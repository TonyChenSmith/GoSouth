/*
 * 本文件是对头文件graphic/console_text.h的实现。
 * 
 * @author 海中垂钓
 * @time 2021-10-16
 */
#include<windows.h>
#include<cstdio>
#include<cstdarg>
#include"graphic/console_text.h"

//控制台标准输出句柄。
static HANDLE CONSOLE_STDOUT = NULL;

//变色标准输出实现。
extern void console_printf(unsigned short colors, const char* format, ...)
{
	CONSOLE_SCREEN_BUFFER_INFO info;
	WORD origin_colors;
	va_list argv;

	if (CONSOLE_STDOUT == NULL)
	{
		CONSOLE_STDOUT = GetStdHandle(STD_OUTPUT_HANDLE);
		if (CONSOLE_STDOUT == INVALID_HANDLE_VALUE)
		{
			//错误操作，这里先置空。
			CONSOLE_STDOUT = NULL;
			return;
		}
	}

	//变到新色。
	if (!GetConsoleScreenBufferInfo(CONSOLE_STDOUT, &info))
	{
		//错误信息。
		return;
	}
	origin_colors = info.wAttributes;
	if (!SetConsoleTextAttribute(CONSOLE_STDOUT, colors))
	{
		//错误信息。
		return;
	}

	//输出。
	va_start(argv, format);
	vprintf_s(format, argv);
	va_end(argv);

	//变回原色。
	if (!SetConsoleTextAttribute(CONSOLE_STDOUT, origin_colors))
	{
		//错误信息。
		return;
	}
}

extern void console_puts(unsigned short colors, const char* str)
{

}