#pragma once

#include "stdafx.h"

//#include "UCConnection.h"

using boost::asio::ip::tcp;

class CUCODEConnection;

struct SConnData
{
	tcp::socket * sock;
	CUCODEConnection * connection;
};