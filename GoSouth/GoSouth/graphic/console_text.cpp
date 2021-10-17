/*
 * ���ļ��Ƕ�ͷ�ļ�graphic/console_text.h��ʵ�֡�
 * 
 * @author ���д���
 * @time 2021-10-16
 */
#include<windows.h>
#include<cstdio>
#include<cstdarg>
#include"graphic/console_text.h"

//����̨��׼��������
static HANDLE CONSOLE_STDOUT = NULL;

//����̨��׼������������
static HANDLE CONSOLE_STDERR = NULL;

//ԭ����ɫ��
static WORD ORIGIN_COLORS = FOREGROUND_WHITE | BACKGROUND_BLACK;

//��õ�ǰ�����ɫ��ϡ�
static WORD __mirror_get_text_color(bool is_err)
{
	static CONSOLE_SCREEN_BUFFER_INFO info;
	if (!GetConsoleScreenBufferInfo(is_err?CONSOLE_STDERR:CONSOLE_STDOUT, &info))
	{
		//������Ϣ��
		return FOREGROUND_WHITE | BACKGROUND_BLACK;
	}
	return info.wAttributes;
}

//�����������
static void __mirror_check_out()
{
	if (CONSOLE_STDOUT == NULL)
	{
		CONSOLE_STDOUT = GetStdHandle(STD_OUTPUT_HANDLE);
		if (CONSOLE_STDOUT == INVALID_HANDLE_VALUE)
		{
			//����������������ÿա�
			CONSOLE_STDOUT = NULL;
			return;
		}
	}
}

//����������
static void __mirror_check_err()
{
	if (CONSOLE_STDERR == NULL)
	{
		CONSOLE_STDERR = GetStdHandle(STD_ERROR_HANDLE);
		if (CONSOLE_STDERR == INVALID_HANDLE_VALUE)
		{
			//����������������ÿա�
			CONSOLE_STDERR = NULL;
			return;
		}
	}
}

//��ɫ��ʽ����׼���ʵ�֡�
extern void console_printf(unsigned short colors, const char* format, ...)
{
	va_list argv;

	__mirror_check_out();

	//�䵽��ɫ��
	ORIGIN_COLORS = __mirror_get_text_color(false);
	if (!SetConsoleTextAttribute(CONSOLE_STDOUT, colors))
	{
		//������Ϣ��
		return;
	}

	//�����
	va_start(argv, format);
	vprintf_s(format, argv);
	va_end(argv);

	//���ԭɫ��
	if (!SetConsoleTextAttribute(CONSOLE_STDOUT, ORIGIN_COLORS))
	{
		//������Ϣ��
		return;
	}
}

//��ɫ�ַ������ʵ�֡�
extern void console_puts(unsigned short colors, const char* str)
{
	__mirror_check_out();

	//�䵽��ɫ��
	ORIGIN_COLORS = __mirror_get_text_color(false);
	if (!SetConsoleTextAttribute(CONSOLE_STDOUT, colors))
	{
		//������Ϣ��
		return;
	}

	puts(str);

	//���ԭɫ��
	if (!SetConsoleTextAttribute(CONSOLE_STDOUT, ORIGIN_COLORS))
	{
		//������Ϣ��
		return;
	}
}