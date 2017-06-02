#include "UCConnection.h"
//#include "../Share/Net/INetSession.h"

CUCODEConnection::CUCODEConnection()
	: m_pSession(NULL)
	, m_pConnData(NULL)
{
}

void CUCODEConnection::OnRecv(const char * pBuf, DWORD dwfLen, const boost::system::error_code & ec)
{
	
}

void CUCODEConnection::Send(const char * pBuf, DWORD dwLen)
{
	m_pConnData->sock->send(boost::asio::buffer(pBuf, dwLen));
}

//void CUCODEConnection::Send(const char * pBuf, DWORD dwLen)
//{
//	//m_pConnData->sock->async_send(boost::asio::buffer(pBuf, wLen), [](const boost::system::error_code & ec) {});
//}
