#include "stdafx.h"
#include "ConnectCtrl.h"
#include "UCNetConfig.h"
#include "ConnDataMgr.h"
#include "UCAsio.h"
#include "UCConnection.h"
#include <string>
#include <iostream>

CConnectCtrl::CConnectCtrl()
	: m_pThread(NULL)
	, m_pProcReqArray(NULL)
	, m_pSocketArray(NULL)
	, m_pAllReqArray(NULL)
{
	m_wSocketCount = 0;
	m_bTerminate = false;
}

CConnectCtrl::~CConnectCtrl()
{
}

CConnectCtrl & CConnectCtrl::Instance()
{
	static CConnectCtrl l_CConCtrl;
	return l_CConCtrl;
}

bool CConnectCtrl::Init()
{
	int const nMaxRequest = MAX_CONNECTION * 2;

	m_pProcReqArray = new SConnReq*[MAX_CONNECTION];
	std::memset(m_pProcReqArray, 0, sizeof(SConnReq) * MAX_CONNECTION);

	for (size_t i = 0; i < MAX_CONNECTION; ++i)
	{
		//m_pSocketArray[i] = new tcp::socket(*SNetGlobal::GetStcIOService());
	}
	m_pAllReqArray = new SConnReq[nMaxRequest];
	for (size_t i = 0; i < nMaxRequest; ++i)
	{
		m_FreeQueue.push(&m_pAllReqArray[i]);
	}

	m_pThread = new std::thread(ThreadFunc, (void*)this);

	return true;
}

bool CConnectCtrl::PushConnReq(tcp::endpoint endpoint, INetSession * pSession)
{
	SConnReq * pSConnReq = m_FreeQueue.front();
	pSConnReq->endpoint = endpoint;
	pSConnReq->pSession = pSession;
	m_ReqQueue.push(pSConnReq);
	return false;
}

void CConnectCtrl::OnExecute()
{
	_ProcRequest();
	//_ProcEvent();
}

void CConnectCtrl::_ProcRequest()
{
	while (m_wSocketCount < (UINT16)MAX_CONNECTION)
	{
		if (m_ReqQueue.empty())
		{
			break;
		}
		SConnReq * pSConReq = m_ReqQueue.front();

		tcp::socket * pSock = new tcp::socket(SNetGlobal::GetStcIOService());
		//pSock->async_connect(pSConReq->endpoint, [](boost::system::error_code & er) {});
		boost::system::error_code er;
		std::cout << "Connecting..." << std::endl;
		pSock->connect(pSConReq->endpoint, er);
		if (er)
		{
			std::cout << "Connect Fail!"<<std::endl;
			m_bTerminate = true;
		}
		m_pProcReqArray[m_wSocketCount] = pSConReq;
		m_pSocketArray[m_wSocketCount] = pSock;
		++m_wSocketCount;
	}
}

void CConnectCtrl::_ProcEvent()
{
	UINT16 l_wStart = 0;
	UINT16 l_wIndex = 0;
	if (m_wSocketCount == 0)
	{
		return;
	}
	do
	{
		l_wIndex = l_wStart;
		l_wStart++;
		SConnReq * pConnReq = m_pProcReqArray[l_wIndex];

		if (pConnReq == NULL)
		{
			continue;
		}
		SConnData * pConnData = new SConnData;
		CUCODEConnection * pConnection = pConnData->connection;
		pConnData->sock = m_pSocketArray[l_wIndex];
		pConnection->SetSession(pConnReq->pSession);

		m_pProcReqArray[l_wIndex] = NULL;
	} while (l_wStart<m_wSocketCount);
}

unsigned CConnectCtrl::ThreadFunc(LPVOID pParam)
{
	CConnectCtrl * pCtrl = (CConnectCtrl*)pParam;
	while (!pCtrl->m_bTerminate) {
		pCtrl->OnExecute();
		Sleep(1);
	}
	return 0;
}
