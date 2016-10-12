#ifndef _SYOPENGRESOURCE_H_
#define _SYOPENGRESOURCE_H_

#ifdef BCB
typedef unsigned char  	BYTE;
typedef wchar_t 		WCHAR;
#else
#endif

#include <objbase.h>

#include <GL\glut.h>//�ϥ�DevC++���ܭn�אּ�ФJ #include <GL\openglut.h> 
#pragma comment (lib,"opengl32.lib")      //�o�椣�b�쥻DevC++���d���̡A�OVC++�~�ݭn�� 

#include <gdiplus.h>
#pragma comment (lib, "gdiplus.lib")
using namespace Gdiplus;

#include <string>
#include <vector>


class SYTexture2D
{
public:
	GLuint      texture;
	GLint       width;
	GLint       height;
	GLint		texWidth;
	GLint		texHeight;
	std::wstring filePath;
};

class SYOpenGLResource
{

public:	
	//creat
	static SYOpenGLResource* Instance(void);
	static SYOpenGLResource* Instance(WCHAR *pwszPath);
	~SYOpenGLResource(void);
	
	//method
	SYTexture2D *IsExistTextureWithFilePath(const WCHAR *pwszFilePath);
	SYTexture2D *LoadTexture(const WCHAR *pwszFilePath);

private:
	//method
	SYOpenGLResource(void);	
	SYOpenGLResource(WCHAR *pwszPath);	

	bool IsPowerOfTwo(int x);
	int NextPowerOfTwo(int minimum);
private:
	//var
	//creat
	static SYOpenGLResource*	m_instance;
	//////////////////////////////////////////////////////////////////////////
	std::wstring strRootPath;
	std::vector<SYTexture2D *> *m_pvecTexture;
};

#endif