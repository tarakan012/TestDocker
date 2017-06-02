#pragma once

#include "stdafx.h"
#include <thread>
#include <queue>

//#include "..\Share\Net\INetSession.h"
#include "NetRequest.h"

using boost::asio::ip::tcp;

class INetSession;
class CConnectCtrl
{
public:
	CConnectCtrl();
	~CConnectCtrl();

	static CConnectCtrl & Instance();

	bool Init();
	bool PushConnReq(tcp::endpoint endpoint, INetSession * pSession);
	void OnExecute();
	void _ProcRequest();
	void _ProcEvent();
	static unsigned ThreadFunc(LPVOID pParam);
private:
	tcp::socket                     **	m_pSocketArray;
	SConnReq                        **  m_pProcReqArray;
	std::thread                     *   m_pThread;
	std::queue<SConnReq*>               m_ReqQueue;
	SConnReq                        *   m_pAllReqArray;
	std::queue<SConnReq*>               m_FreeQueue;
	UINT16                              m_wSocketCount;
	BOOL                                m_bTerminate;
};