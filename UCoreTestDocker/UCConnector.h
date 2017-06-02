#pragma once

#include "stdafx.h"
//#include "ConnectCtrl.h"

using boost::asio::ip::tcp;
using boost::asio::ip::address;

class INetSession;
class CUCConnector
{
public:
	bool Connect(const char * ip, int port);
	bool ReConnect();
	void SetSession(INetSession * pSession) { m_pSession = pSession; }
private:
	INetSession * m_pSession;
	tcp::endpoint m_endpoint;
};