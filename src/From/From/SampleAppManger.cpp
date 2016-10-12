#include "stdafx.h"
#include "SampleAppManger.h"

SampleAppManger* SampleAppManger::m_instance = NULL;

SampleAppManger* SampleAppManger::Instance()
{
	if (m_instance == NULL){
		m_instance = new SampleAppManger(); 
	}
	return m_instance;
}

SampleAppManger::SampleAppManger()
{
	m_hModule					= NULL;
	m_DLLFuncTestAdd			= NULL;
	m_DLLFuncInitOpengl			= NULL;
	m_DLLFuncRenderOpengl		= NULL;
	m_DLLFuncOnOpenglMouseDown  = NULL;
	m_DLLFuncOnOpenglMouseMove  = NULL;
	m_DLLFuncOnOpenglMouseUp	= NULL;

	//-------------------------------------------------------------------------------
	m_hModule = LoadLibrary(L".\\SampleApp.dll");
	//-------------------------------------------------------------------------------
	if ( m_hModule != NULL )
	{
		//-------------------------------------------------------------------------------
		m_DLLFuncTestAdd = (SampleAppManger_TestAdd)GetProcAddress( m_hModule, "TestAdd" );
		if (m_DLLFuncTestAdd == NULL)
		{
			OutputDebugString(L"GetProc fault:TestAdd\n");
			::MessageBox(NULL, L"GetProc fault:TestAdd", L"", MB_OK);
			FreeLibrary(m_hModule);
			return;
		}

		//-------------------------------------------------------------------------------		
		m_DLLFuncInitOpengl = (SampleAppManger_InitOpengl)GetProcAddress( m_hModule, "InitOpengl" );
		if (m_DLLFuncInitOpengl == NULL)
		{
			OutputDebugString(L"GetProc fault:InitOpengl\n");
			::MessageBox(NULL, L"GetProc fault:InitOpengl", L"", MB_OK);
			FreeLibrary(m_hModule);
			return;
		}

		//-------------------------------------------------------------------------------		
		m_DLLFuncRenderOpengl = (SampleAppManger_RenderOpengl)GetProcAddress( m_hModule, "RenderOpengl" );
		if (m_DLLFuncRenderOpengl == NULL)
		{
			OutputDebugString(L"GetProc fault:RenderOpengl\n");
			::MessageBox(NULL, L"GetProc fault:RenderOpengl", L"", MB_OK);
			FreeLibrary(m_hModule);
			return;
		}

		//-------------------------------------------------------------------------------		
		m_DLLFuncOnOpenglMouseDown = (SampleAppManger_OnOpenglMouseDown)GetProcAddress( m_hModule, "OnOpenglMouseDown" );
		if (m_DLLFuncOnOpenglMouseDown == NULL)
		{
			OutputDebugString(L"GetProc fault:OnOpenglMouseDown\n");
			::MessageBox(NULL, L"GetProc fault:OnOpenglMouseDown", L"", MB_OK);
			FreeLibrary(m_hModule);
			return;
		}

		//-------------------------------------------------------------------------------		
		m_DLLFuncOnOpenglMouseMove = (SampleAppManger_OnOpenglMouseMove)GetProcAddress( m_hModule, "OnOpenglMouseMove" );
		if (m_DLLFuncOnOpenglMouseMove == NULL)
		{
			OutputDebugString(L"GetProc fault:OnOpenglMouseMove\n");
			::MessageBox(NULL, L"GetProc fault:OnOpenglMouseMove", L"", MB_OK);
			FreeLibrary(m_hModule);
			return;
		}

		//-------------------------------------------------------------------------------		
		m_DLLFuncOnOpenglMouseUp = (SampleAppManger_OnOpenglMouseUp)GetProcAddress( m_hModule, "OnOpenglMouseUp" );
		if (m_DLLFuncOnOpenglMouseUp == NULL)
		{
			OutputDebugString(L"GetProc fault:OnOpenglMouseUp\n");
			::MessageBox(NULL, L"GetProc fault:OnOpenglMouseUp", L"", MB_OK);
			FreeLibrary(m_hModule);
			return;
		}

		//-------------------------------------------------------------------------------
	}else{
		OutputDebugString(L"SYHttpServerManger fault:Can't find SampleApp.dll\n");
	}
}

SampleAppManger::~SampleAppManger()
{
	FreeLibrary(m_hModule);
	OutputDebugStringW(L"SampleAppManger::~SampleAppManger()\n");
}


int SampleAppManger::TestAdd(int a, int b)
{
	return m_DLLFuncTestAdd(a, b);
}

void SampleAppManger::InitOpengl(HWND hwnd, int w, int h)
{
	m_DLLFuncInitOpengl(hwnd, w, h);
}


void SampleAppManger::RenderOpengl(void)
{
	m_DLLFuncRenderOpengl();
}

void SampleAppManger::OnOpenglMouseDown(int x, int y)
{
	m_DLLFuncOnOpenglMouseDown(x, y);
}

void SampleAppManger::OnOpenglMouseMove(int x, int y)
{
	m_DLLFuncOnOpenglMouseMove(x, y);
}

void SampleAppManger::OnOpenglMouseUp(int x, int y)
{
	m_DLLFuncOnOpenglMouseUp(x, y);
}