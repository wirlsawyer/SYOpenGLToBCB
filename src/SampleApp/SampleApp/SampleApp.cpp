// SampleApp.cpp : Defines the entry point for the DLL application.
//

#include "stdafx.h"
#include "Layout.h"

#include "openGL\SYOpenGLManger.h"  // by Sawyer
SYOpenGLManger *g_glMgr  = NULL; // by Sawyer
Layout         *g_layout = NULL;


#ifdef BCB
typedef unsigned char  	BYTE;
typedef wchar_t 		WCHAR;
#else
#endif


#ifdef _MANAGED
#pragma managed(push, off)
#endif

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
					 )
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:	
		break;

	case DLL_THREAD_ATTACH:
		break;
	case DLL_THREAD_DETACH:
		break;
	case DLL_PROCESS_DETACH:
		delete g_glMgr;
		delete g_layout;
		break;
	}
    return TRUE;
}

#ifdef _MANAGED
#pragma managed(pop)
#endif

//======================================================================================================================
int WINAPI TestAdd(int a, int b)
{
	return a+b;	
}

//======================================================================================================================
void WINAPI InitOpengl(HWND hwnd, int w, int h)
{
	//opengl
	g_glMgr = SYOpenGLManger::Instance(hwnd, w, h);
	//yourself layout
	g_layout = new Layout();
}

//======================================================================================================================
void WINAPI RenderOpengl(void)
{
	g_glMgr->Render();
}

//======================================================================================================================
void WINAPI OnOpenglMouseDown(int x, int y)
{
	g_glMgr->OnMouseDown(x, y);
}

//======================================================================================================================
void WINAPI OnOpenglMouseMove(int x, int y)
{
	g_glMgr->OnMouseMove(x, y);
}

//======================================================================================================================
void WINAPI OnOpenglMouseUp(int x, int y)
{
	g_glMgr->OnMouseUp(x, y);
}

