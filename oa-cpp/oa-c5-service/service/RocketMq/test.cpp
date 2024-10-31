
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
		//获取配置
		NacosClient nacosClient(TEST_NS_ADDR, TEST_NS_NAMESPACE);
#ifdef LINUX
		YAML::Node node = nacosClient.getConfig("third-services.yaml");
#else
		YAML::Node node = nacosClient.getConfig("./conf/third-services.yaml");
#endif
		string namesrv = YamlHelper().getString(&node, "rocket-mq.name-server");

		// 创建客户端
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
	// MQ客户端对象
	RocketClient* client = nullptr;
};


// 测试同步发送消息
TEST_F(RocketTest, SendSync) {
	// 定义消息对象
	auto dto = SystemInformDTO::createShared();
	dto->id = "1";
	dto->title = "test";
	dto->description = "123";
	dto->addDescription = "456";
	dto->status = "yes";
	dto->time = "19999";
	// 发送消息
	RC_PUBLISH_OBJ_MSG_SYNC(res, client, "send", dto);
	std::cout << "sync send result: " << res << endl;
}