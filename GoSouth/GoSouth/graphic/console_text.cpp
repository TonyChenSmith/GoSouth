/*
 * 本文件是对头文件graphic/console_text.h的实现。
 *
 * @author 海中垂钓
 * @time 2021-10-16
 */
#include<windows.h>
#include<stringapiset.h>
#include<cstdlib>
#include<cstdio>
#include<cstdarg>
#include"graphic/console_text.h"

//控制台标准输出句柄。
static HANDLE CONSOLE_STDOUT=NULL;

//控制台标准错误输出句柄。
static HANDLE CONSOLE_STDERR=NULL;

//原本颜色。
static WORD ORIGIN_COLORS=FORE_WHITE|BACK_BLACK;

//获得当前输出颜色组合。
static WORD __mirror_get_text_color(bool is_err)
{
	static CONSOLE_SCREEN_BUFFER_INFO info;
	if (!GetConsoleScreenBufferInfo(is_err?CONSOLE_STDERR:CONSOLE_STDOUT,&info))
	{
		//错误信息。
		return FORE_WHITE|BACK_BLACK;
	}
	return info.wAttributes;
}

//获得当前代码页。
static UINT __mirror_get_code_page(bool is_input)
{
	if (is_input)
	{
		return GetConsoleCP();
	}
	else
	{
		return GetConsoleOutputCP();
	}
}

//检查输出句柄。
static void __mirror_check_out()
{
	if (CONSOLE_STDOUT==NULL)
	{
		CONSOLE_STDOUT=GetStdHandle(STD_OUTPUT_HANDLE);
		if (CONSOLE_STDOUT==INVALID_HANDLE_VALUE)
		{
			//错误操作，这里先置空。
			CONSOLE_STDOUT=NULL;
			return;
		}
	}
}

//检查错误句柄。
static void __mirror_check_err()
{
	if (CONSOLE_STDERR==NULL)
	{
		CONSOLE_STDERR=GetStdHandle(STD_ERROR_HANDLE);
		if (CONSOLE_STDERR==INVALID_HANDLE_VALUE)
		{
			//错误操作，这里先置空。
			CONSOLE_STDERR=NULL;
			return;
		}
	}
}

//使用堆内存的代码页转换。使用了malloc()。
static void __mirror_change_codepage(const char* str,char** aim,UINT str_code,UINT aim_code)
{
	wchar_t* wstr;
	PCHAR result;
	int length;

	//同页不用转。
	if (str_code==aim_code)
	{
		*aim=(char*)str;
		return;
	}
	//源代码页转化为Unicode
	length=MultiByteToWideChar(str_code,0,str,-1,NULL,0);
	if (!length)
	{
		//错误代码。
		*aim=NULL;
		return;
	}
	wstr=new wchar_t[length];
	if (!MultiByteToWideChar(str_code,0,str,-1,wstr,length))
	{
		//错误代码。
		delete[] wstr;
		*aim=NULL;
		return;
	}

	//Unicode转化其他代码页。
	length=WideCharToMultiByte(aim_code,0,wstr,-1,NULL,0,NULL,NULL);
	if (!length)
	{
		//错误代码。
		delete[] wstr;
		*aim=NULL;
		return;
	}

	result=(PCHAR)malloc(length*sizeof(CHAR));
	if (result==NULL)
	{
		//错误代码。
		delete[] wstr;
		*aim=NULL;
		return;
	}

	if (!WideCharToMultiByte(aim_code,0,wstr,-1,result,length,NULL,NULL))
	{
		//错误代码。
		free(result);
		delete[] wstr;
		*aim=NULL;
		return;
	}
	else
	{
		delete[] wstr;
		*aim=result;
		return;
	}
}

//变色格式化标准输出实现。
extern void console_printf(unsigned short colors,const char* format,...)
{
	va_list argv;
	PCHAR str;
	UINT code_page;

	__mirror_check_out();

	//变到新色。
	ORIGIN_COLORS=__mirror_get_text_color(false);
	if (!SetConsoleTextAttribute(CONSOLE_STDOUT,colors))
	{
		//错误信息。
		return;
	}

	code_page=__mirror_get_code_page(false);
	__mirror_change_codepage(format,&str,CP_UTF8,code_page);

	//输出。
	va_start(argv,format);
	vprintf_s(str,argv);
	va_end(argv);

	//变回原色。
	if (!SetConsoleTextAttribute(CONSOLE_STDOUT,ORIGIN_COLORS))
	{
		//错误信息。
		return;
	}

	free(str);
}

//变色字符串输出实现。
extern void console_puts(unsigned short colors,const char* str)
{
	PCHAR output;
	UINT code_page;
	__mirror_check_out();

	//变到新色。
	ORIGIN_COLORS=__mirror_get_text_color(false);
	if (!SetConsoleTextAttribute(CONSOLE_STDOUT,colors))
	{
		//错误信息。
		return;
	}

	code_page=__mirror_get_code_page(false);
	__mirror_change_codepage(str,&output,CP_UTF8,code_page);
	puts(output);

	//变回原色。
	if (!SetConsoleTextAttribute(CONSOLE_STDOUT,ORIGIN_COLORS))
	{
		//错误信息。
		return;
	}
	free(output);
}