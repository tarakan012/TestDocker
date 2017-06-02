#pragma once

#include"stdafx.h"

using boost::asio::io_service;


struct SNetGlobal
{
	static io_service & GetStcIOService();
	static bool InitStcIOService(int nCountThr = 2);
};



