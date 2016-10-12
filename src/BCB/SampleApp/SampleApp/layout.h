#ifndef _LAYOUT_H_
#define _LAYOUT_H_
#include "openGL/SYOpenGLManger.h"
#include "openGL/SYGLUIButton.h"

class Layout
{
private:
	SYOpenGLManger	*g_glMgr;
	SYGLUIButton	*m_btn1;
public:
	Layout()
	{
		g_glMgr = SYOpenGLManger::Instance();
		g_glMgr->setBackgroundColor(255, 255, 255);	


		m_btn1 = new SYGLUIButton(10, 10, L"O2_n.png", L"O2_d.png", L"O2_o.png", L"O2_un.png");
		m_btn1->name = L"v1";	
		g_glMgr->AddSubview(m_btn1);

		//__hook(&SYGLUIButton::OnEventClicked, m_btn1, &Layout::onDidClicked);
	}

	~Layout()
	{
		//__unhook(&SYGLUIButton::OnEventClicked, m_btn1, &Layout::onDidClicked);
	}

	void onDidClicked(SYGLUIButton *sender, int x, int y)
	{
		if (sender == m_btn1)
		{
			OutputDebugStringW(L"m_btn1 had clicked\n");
		}
	}
};

#endif