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
	m_tInfo.vDir = { 1.f, 0.f, 0.f };
	m_fSpeed = 5.f;
}

void CPlayer::Update()
{
	Key_Input();
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
	if (GetAsyncKeyState(VK_LEFT))
	{
		m_tInfo.vDir = { -1.f, 0.f, 0.f };
	}
	else if (GetAsyncKeyState(VK_RIGHT))
	{
		m_tInfo.vDir = { 1.f, 0.f, 0.f };
	}
	else if (GetAsyncKeyState(VK_UP))
	{
		m_tInfo.vDir = { 0.f, -1.f, 0.f };
	}
	else if (GetAsyncKeyState(VK_DOWN))
	{
		m_tInfo.vDir = { 0.f, 1.f, 0.f };
	}
	else
		m_tInfo.vDir = { 0.f, 0.f, 0.f };

	m_tInfo.vPos += m_tInfo.vDir * m_fSpeed;
}
