#include "pch.h"
#include "CPlayer.h"

CPlayer::CPlayer()
{
}

CPlayer::~CPlayer()
{
	Release();
}

void CPlayer::Initialize()
{
	m_tInfo.vPos = { 400.f, 300.f, 0.f };
	m_tInfo.vLook = { 1.f, 0.f, 0.f };
	m_fSpeed = 5.f;
}

void CPlayer::Update()
{
	m_tInfo.vDir = Get_Mouse() - m_tInfo.vPos;

	//float fLength = sqrtf(SQUARE(m_tInfo.vDir.x) + SQUARE(m_tInfo.vDir.y));

	//m_tInfo.vDir.x /= fLength;
	//m_tInfo.vDir.y /= fLength;
	//m_tInfo.vDir.z = 0.f;

	//float fLength2 = sqrtf(SQUARE(m_tInfo.vLook.x) + SQUARE(m_tInfo.vLook.y));

	//m_tInfo.vLook.x /= fLength2;
	//m_tInfo.vLook.y /= fLength2;
	//m_tInfo.vLook.z = 0.f;

	D3DXVec3Normalize(&m_tInfo.vDir, &m_tInfo.vDir);
	D3DXVec3Normalize(&m_tInfo.vLook, &m_tInfo.vLook);

	//float fDot = (m_tInfo.vDir.x * m_tInfo.vLook.x) + (m_tInfo.vDir.y * m_tInfo.vLook.y) + (m_tInfo.vDir.z * m_tInfo.vLook.z);

	float fDot = D3DXVec3Dot(&m_tInfo.vDir, &m_tInfo.vLook);

	float fRadian = acosf(fDot);

	if (m_tInfo.vPos.y < Get_Mouse().y)
		fRadian = 2.f * D3DX_PI - fRadian;

	m_tInfo.vPos.x += m_fSpeed * cosf(fRadian);
	m_tInfo.vPos.y -= m_fSpeed * sinf(fRadian);
}

void CPlayer::Render(HDC hDC)
{
	Rectangle(hDC, 
		int(m_tInfo.vPos.x - 50.f), 
		int(m_tInfo.vPos.y - 50.f), 
		int(m_tInfo.vPos.x + 50.f),
		int(m_tInfo.vPos.y + 50.f));
}

void CPlayer::Release()
{
}

void CPlayer::Key_Input()
{
}
