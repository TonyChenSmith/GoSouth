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

//控制台标准错误输出句柄。
static HANDLE CONSOLE_STDERR = NULL;

//原本颜色。
static WORD ORIGIN_COLORS = FOREGROUND_WHITE | BACKGROUND_BLACK;

//获得当前输出颜色组合。
static WORD __mirror_get_text_color(bool is_err)
{
	static CONSOLE_SCREEN_BUFFER_INFO info;
	if (!GetConsoleScreenBufferInfo(is_err?CONSOLE_STDERR:CONSOLE_STDOUT, &info))
	{
		//错误信息。
		return FOREGROUND_WHITE | BACKGROUND_BLACK;
	}
	return info.wAttributes;
}

//检查输出句柄。
static void __mirror_check_out()
{
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
}

//检查错误句柄。
static void __mirror_check_err()
{
	if (CONSOLE_STDERR == NULL)
	{
		CONSOLE_STDERR = GetStdHandle(STD_ERROR_HANDLE);
		if (CONSOLE_STDERR == INVALID_HANDLE_VALUE)
		{
			//错误操作，这里先置空。
			CONSOLE_STDERR = NULL;
			return;
		}
	}
}

//变色格式化标准输出实现。
extern void console_printf(unsigned short colors, const char* format, ...)
{
	va_list argv;

	__mirror_check_out();

	//变到新色。
	ORIGIN_COLORS = __mirror_get_text_color(false);
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
	if (!SetConsoleTextAttribute(CONSOLE_STDOUT, ORIGIN_COLORS))
	{
		//错误信息。
		return;
	}
}

//变色字符串输出实现。
extern void console_puts(unsigned short colors, const char* str)
{
	__mirror_check_out();

	//变到新色。
	ORIGIN_COLORS = __mirror_get_text_color(false);
	if (!SetConsoleTextAttribute(CONSOLE_STDOUT, colors))
	{
		//错误信息。
		return;
	}

	puts(str);

	//变回原色。
	if (!SetConsoleTextAttribute(CONSOLE_STDOUT, ORIGIN_COLORS))
	{
		//错误信息。
		return;
	}
}