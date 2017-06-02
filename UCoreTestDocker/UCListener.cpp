#include "stdafx.h"
#include "UCListener.h"
#include "UCAsio.h"

void UCORE::CUCListener::Start(const char * ip, int port)
{
	SNetGlobal::InitStcIOService();

	tcp::socket * pSocket = new tcp::socket(SNetGlobal::GetStcIOService());
	tcp::acceptor * pAcceptor = new tcp::acceptor(SNetGlobal::GetStcIOService());
	address addr;
	addr.from_string(ip);
	tcp::endpoint endpoint(tcp::v4(), port);
	pAcceptor->open(endpoint.protocol());
	pAcceptor->set_option(tcp::acceptor::reuse_address(true));
	pAcceptor->bind(endpoint);
	pAcceptor->listen();
	pAcceptor->accept(*pSocket); //boost::bind(&CUCListener::OnAccept, this, pSocket, boost::asio::placeholders::error));
}

void UCORE::CUCListener::OnAccept(tcp::socket * pSocket, const boost::system::error_code & ec)
{

	SConnData * pConnData = new SConnData;
	pConnData->connection = new CUCODEConnection;

	pConnData->sock = pSocket;
	tcp::socket * pSock = pConnData->sock;
	CUCODEConnection * pConnection = pConnData->connection;
	INetSession * pSession = new INetSession;
	pSession->mType = ST_ServerCS_OnlyGS;
	INetSessionMgr::GetInstance()->AddSession(pSession);
	pConnection->SetSession(pSession);
	char * lbuf = new char[1024];
	//pSock->async_receive(boost::asio::buffer(lbuf, 4), boost::bind(&CUCODEConnection::OnRecv, this, lbuf, 4, boost::asio::placeholders::error));
}