#pragma once

#include "stdafx.h"
#include "ConnDataMgr.h"

class INetSession;
class CUCODEConnection
{
public:
	CUCODEConnection();
	inline void SetConnData(SConnData * pConnData) { m_pConnData = pConnData; }
	inline void SetSession(INetSession * pSession) { m_pSession = pSession; }
	void OnRecv(const char * pBuf, DWORD dwfLen, const boost::system::error_code & ec);
	void Send(const char * pBuf, DWORD dwLen);
private:
	SConnData   * m_pConnData;
	INetSession * m_pSession;
};
