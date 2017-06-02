#include "stdafx.h"
#include "UCAsio.h"

#include<vector>
#include<thread>
static io_service  s_io_service;
static std::vector<std::thread>  s_thread_pool;


io_service & SNetGlobal::GetStcIOService()
{

	return s_io_service;
}

bool SNetGlobal::InitStcIOService(int nCountThr)
{
	//if (!s_io_service)
	//{
		//s_io_service = new io_service;
//	}
	//while (--nCountThr)
	//{
		//auto worker = boost::bind(&boost::asio::io_service::run, &s_io_service);
	s_thread_pool.emplace_back([=] { s_io_service.run(); });
	//}
	return false;
}
