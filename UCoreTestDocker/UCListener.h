#pragma once

#include "stdafx.h"
#include "ConnDataMgr.h" 
#include "boost/bind/bind.hpp"
#include "UCConnection.h"
#include "../Share/Net/INetSession.h"
#include "../Share/Net/INetSessionMgr.h"

namespace UCORE
{
	class CUCListener
	{
	public:
		void Start(const char * ip, int port);
		void OnAccept(tcp::socket * pSocket, const boost::system::error_code & ec);
	};
	using boost::asio::ip::tcp;
	using boost::asio::ip::address;

}