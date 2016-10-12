#ifndef _SAMPLEAPPMANGER_H_
#define _SAMPLEAPPMANGER_H_

#ifdef BCB
#include <windows.h>
typedef unsigned char  	BYTE;
typedef wchar_t 		WCHAR;
#else
#endif



typedef int (WINAPI* SampleAppManger_TestAdd)(int a, int b);
typedef int (WINAPI* SampleAppManger_InitOpengl)(HWND hwnd, int w, int h);
typedef int (WINAPI* SampleAppManger_RenderOpengl)(void);
typedef int (WINAPI* SampleAppManger_OnOpenglMouseDown)(int x, int y);
typedef int (WINAPI* SampleAppManger_OnOpenglMouseMove)(int x, int y);
typedef int (WINAPI* SampleAppManger_OnOpenglMouseUp)(int x, int y);


class SampleAppManger
{

public:	
	//creat
	static SampleAppManger* Instance(void);
	~SampleAppManger(void);
	//method
	int TestAdd(int a, int b);
	void InitOpengl(HWND hwnd, int w, int h);
	void RenderOpengl(void);

	void OnOpenglMouseDown(int x, int y);
	void OnOpenglMouseMove(int x, int y);
	void OnOpenglMouseUp(int x, int y);
private:
	//method
	SampleAppManger(void);	


private:
	//var
	//creat
	static SampleAppManger*				m_instance;		
	//dll
	HMODULE  							m_hModule;

	SampleAppManger_TestAdd				m_DLLFuncTestAdd;
	SampleAppManger_InitOpengl			m_DLLFuncInitOpengl;
	SampleAppManger_RenderOpengl		m_DLLFuncRenderOpengl;
	SampleAppManger_OnOpenglMouseDown	m_DLLFuncOnOpenglMouseDown;
	SampleAppManger_OnOpenglMouseMove	m_DLLFuncOnOpenglMouseMove;
	SampleAppManger_OnOpenglMouseUp		m_DLLFuncOnOpenglMouseUp;
};

#endif