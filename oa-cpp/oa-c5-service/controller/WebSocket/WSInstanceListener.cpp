#include "stdafx.h"

#include "WSInstanceListener.h"
#include "WSListener.h"
#include <memory>

std::atomic<v_int32> WSInstanceListener::SOCKETS(0);

void WSInstanceListener::onAfterCreate(const WebSocket& socket, const std::shared_ptr<const ParameterMap>& params)
{
	// ��ȡ�ͻ���ID
	std::string id = params->at("id")->c_str();
	// �жϿͻ��˶����Ƿ����
	std::lock_guard<std::mutex> guard(instance_mutex);
	if (conn_pool.find(id) != conn_pool.end()) {
		// �رվܾ�����
		socket.sendClose(9999, u8"reason id has been used");
		OATPP_LOGD(TAG, "New Incoming Connection. Connection has been refuse.");
		return;
	}

	// ��ӵ����ӳ���
	conn_pool.insert(std::make_pair(id, &socket));
	OATPP_LOGD(TAG, "client(%s): open connection", id.c_str());

	// ������������
	SOCKETS++;
	OATPP_LOGD(TAG, "New Incoming Connection. Connection count=%d", SOCKETS.load());

	// �����Ϣ���������
	socket.setListener(std::make_shared<WSListener>(id, &conn_pool));
}

void WSInstanceListener::onBeforeDestroy(const WebSocket& socket)
{
	auto peer = std::static_pointer_cast<WSListener>(socket.getListener());
	if (peer)
	{
		// ��ȡ�ͻ���ID
		std::string id = peer->getId();

		// ����ͻ����Ƴ�
		OATPP_LOGD(TAG, "client(%s): close connection", id.c_str());

		// �����Ӷ����map���Ƴ�
		std::lock_guard<std::mutex> guard(instance_mutex);
		conn_pool.erase(id);
		socket.setListener(nullptr);

		// ������������
		SOCKETS--;
		OATPP_LOGD(TAG, "Connection closed. Connection count=%d", SOCKETS.load());
	}
}
