#pragma once

#include "stdafx.h"

using boost::asio::ip::tcp;

class INetSession;

struct SConnReq
{
	INetSession * pSession;
	tcp::endpoint endpoint;
};