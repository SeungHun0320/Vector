#pragma once

#define WINCX		800
#define WINCY		600

#define	PURE		= 0
#define PI			3.141592f

#define SQUARE(X)        (X) * (X)
#define RADIAN(Degree)   (Degree) * PI/180.f
#define DEGREE(Radian)   (Radian) * 180.f/PI

extern HWND		g_hWnd;

typedef struct tagInfo
{
	D3DXVECTOR3		vDir;
	D3DXVECTOR3		vLook;
	D3DXVECTOR3		vNormal;	// π˝º± ∫§≈Õ(πÊ«‚ ∫§≈Õ)

	D3DXVECTOR3		vPos;

}INFO;


template<typename T>
void Safe_Delete(T& Temp)
{
	if (Temp)
	{
		delete Temp;
		Temp = nullptr;
	}
}