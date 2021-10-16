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

//��ɫ��׼���ʵ�֡�
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
			//����������������ÿա�
			CONSOLE_STDOUT = NULL;
			return;
		}
	}

	//�䵽��ɫ��
	if (!GetConsoleScreenBufferInfo(CONSOLE_STDOUT, &info))
	{
		//������Ϣ��
		return;
	}
	origin_colors = info.wAttributes;
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
	if (!SetConsoleTextAttribute(CONSOLE_STDOUT, origin_colors))
	{
		//������Ϣ��
		return;
	}
}

extern void console_puts(unsigned short colors, const char* str)
{

}