#pragma once
#ifndef _ROCKETLISTENER_H_
#define _ROCKETLISTENER_H_

#include <iostream>
#include <mutex>
#include <thread>
#include "Macros.h"
#include "../../domain/dto/System/inform/SystemInformDTO.h"
#include "NacosClient.h"
#include "RocketClient.h"
#include "../../controller/WebSocket/WSListener.h"


class RocketListener : public RocketClient::RConsumerListener {
private:
	// ���ڷ�����Ϣ��WebSocket�ͻ��˵ļ�����
	WSListener* wsListener;
	// ����ͬ���Ļ�����
	std::mutex mutex;
public:
	void receiveMessage(std::string payload) override {
		std::lock_guard<std::mutex> guard(mutex);
		// ����JSON��Ϣ��DTO��
		RC_RECEIVER_MSG_CONVERT(dto, SystemInformDTO, payload);
		string id = dto->id.getValue("");
		string title = dto->title.getValue("");
		string description = dto->description.getValue("");
		string addDescription = dto->addDescription.getValue("");
		string status = dto->status.getValue("");
		string time = dto->time.getValue("");
		string msg = title + "," + description + "," + addDescription + "," + status + "," + time;
		wsListener->SendMessage(id, msg);
	}
};


#endif // !_ROCKETLISTENER_H_