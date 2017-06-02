#include "stdafx.h"
#include "UCConnector.h"
#include "ConnectCtrl.h"
#include "UCAsio.h"//t
#include<iostream>//t
using boost::asio::ip::address;

bool CUCConnector::Connect(const char * ip, int port)
{
	address laddr;
	laddr.from_string(ip);
	m_endpoint = tcp::endpoint(tcp::v4(), port);
	ReConnect();
	return false;
}

bool CUCConnector::ReConnect()
{
	//SNetGlobal::InitStcIOService(2);
	//tcp::socket * pSock = new tcp::socket(SNetGlobal::GetStcIOService());
	//boost::system::error_code er;
	//std::cout << "Connecting..." << std::endl;
	//pSock->connect(m_endpoint, er);
	//if (er)
	//{
	//	std::cout << "Connect Fail!" <<er<<std::endl;
	//}
	CConnectCtrl::Instance().Init();
	//CConnectCtrl::Instance().PushConnReq();
	return false;
}


