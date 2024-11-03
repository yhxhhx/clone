#ifndef _WSLISTENER_H_
#define _WSLISTENER_H_
#include "oatpp-websocket/WebSocket.hpp"
#include "oatpp-websocket/ConnectionHandler.hpp"
#include <map>

/**
 * WebSocket������,���������WebSocket�¼�
 */
class WSListener : public oatpp::websocket::WebSocket::Listener
{
private:
	static constexpr const char* TAG = "Server_WSListener";
	// ��Ϣ������
	oatpp::data::stream::BufferOutputStream m_messageBuffer;
	// �û�ID
	std::string id;
	// �����������û��б�
	std::map<std::string, const WebSocket*>* conn_pool;
public:
	// ��ȡID
	const std::string& getId();
	// �����ʼ��
	WSListener(std::string id, std::map<std::string, const WebSocket*>* conn_pool);
	// ��ping֡�ϵ���
	void onPing(const WebSocket& socket, const oatpp::String& message) override;
	// ��pong֡�ϵ���
	void onPong(const WebSocket& socket, const oatpp::String& message) override;
	// ��close֡�ϵ���
	void onClose(const WebSocket& socket, v_uint16 code, const oatpp::String& message) override;
	// ��ÿ����Ϣ֡�ϵ��á����һ����Ϣ���ٴε��ã�size����0��ָ����Ϣ����
	void readMessage(const WebSocket& socket, v_uint8 opcode, p_char8 data, oatpp::v_io_size size) override;
	//���û�����֪ͨ
	void SendNotification(const std::string& userId);
};

#endif // !_WSLISTENER_H_