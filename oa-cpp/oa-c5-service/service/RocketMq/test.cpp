
#include <iostream>
#include <mutex>
#include <thread>
#include "Macros.h"
#include "../../domain/dto/System/inform/SystemInformDTO.h"
#include "NacosClient.h"
#include "RocketClient.h"
#include "RocketListener.h"
#include "../../controller/WebSocket/WSController.h"

#include "gtest/gtest.h"


class RocketTest : public testing::Test {
protected:
	void SetUp() override
	{
		//��ȡ����
		NacosClient nacosClient(TEST_NS_ADDR, TEST_NS_NAMESPACE);
#ifdef LINUX
		YAML::Node node = nacosClient.getConfig("third-services.yaml");
#else
		YAML::Node node = nacosClient.getConfig("./conf/third-services.yaml");
#endif
		string namesrv = YamlHelper().getString(&node, "rocket-mq.name-server");

		// �����ͻ���
		this->client = new RocketClient(namesrv);
	}
	void TearDown() override
	{
		if (client)
		{
			client->unsubscribe();
			delete client;
			client = nullptr;
		}
	}
	// MQ�ͻ��˶���
	RocketClient* client = nullptr;
};


// ����ͬ��������Ϣ
TEST_F(RocketTest, SendSync) {
	// ������Ϣ����
	auto dto = SystemInformDTO::createShared();
	dto->id = "1";
	dto->title = "test";
	dto->description = "123";
	dto->addDescription = "456";
	dto->status = "yes";
	dto->time = "19999";
	// ������Ϣ
	RC_PUBLISH_OBJ_MSG_SYNC(res, client, "send", dto);
	std::cout << "sync send result: " << res << endl;
}