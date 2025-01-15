#include "pch.h"
#include "CMonster.h"

CMonster::CMonster() : m_pPlayer(nullptr)
{
}

CMonster::~CMonster()
{
	Release();
}

void CMonster::Initialize()
{
	m_tInfo.vPos = { 100.f, 100.f, 0.f };
	m_fSpeed = 3.f;
	
	m_tInfo.vLook = { 1.f, 0.f, 0.f };
}

void CMonster::Update()
{
	m_tInfo.vDir = m_pPlayer->Get_Info().vPos - m_tInfo.vPos;

	float fLength = sqrtf(SQUARE(m_tInfo.vDir.x) + SQUARE(m_tInfo.vDir.y));

	m_tInfo.vDir.x /= fLength;
	m_tInfo.vDir.y /= fLength;
	m_tInfo.vDir.z = 0.f;

	float fInEnemy = (m_tInfo.vDir.x * m_tInfo.vLook.x) + (m_tInfo.vDir.y * m_tInfo.vLook.y) + (m_tInfo.vDir.z * m_tInfo.vLook.z);
	float fRadian = acosf(fInEnemy);

	if (m_tInfo.vDir.y > 0)
		fRadian = 2.f * D3DX_PI - fRadian;

	float fDegree = D3DXToDegree(fRadian);

	m_tInfo.vPos.x += m_fSpeed * cosf(D3DXToRadian(fDegree));
	m_tInfo.vPos.y -= m_fSpeed * sinf(D3DXToRadian(fDegree));
}

void CMonster::Render(HDC hDC)
{
	Ellipse(hDC,
		int(m_tInfo.vPos.x - 50.f),
		int(m_tInfo.vPos.y - 50.f),
		int(m_tInfo.vPos.x + 50.f),
		int(m_tInfo.vPos.y + 50.f));
}

void CMonster::Release()
{
}


// 내적을 이용하려면 두 방향 벡터가 있어야 함
