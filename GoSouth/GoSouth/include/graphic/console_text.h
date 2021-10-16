/*
 * ���ļ�Ϊ�Կ���̨�ı�����������塣
 * 
 * @author ���д���
 * @time 2021-10-16
 */
#ifndef __GO_SOUTH_GRAPHIC_CONSOLE_TEXT_H__
#define __GO_SOUTH_GRAPHIC_CONSOLE_TEXT_H__

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus


/* ǰ��ɫ */

//��
#define FOREGROUND_BLACK  0x00

//��
#define FOREGROUND_BULE   0x01

//��
#define FOREGROUND_GREEN  0x02

//��
#define FOREGROUND_CYAN   0x03

//��
#define FOREGROUND_RED    0x04

//��
#define FOREGROUND_PURPLE 0x05

//��
#define FOREGROUND_YELLOW 0x06

//��
#define FOREGROUND_WHITE  0x07

//���ڣ��ң�
#define FOREGROUND_BRIGHT_BLACK  0x08

//����
#define FOREGROUND_BRIGHT_BULE   0x09

//����
#define FOREGROUND_BRIGHT_GREEN  0x0A

//����
#define FOREGROUND_BRIGHT_CYAN   0x0B

//����
#define FOREGROUND_BRIGHT_RED    0x0C

//����
#define FOREGROUND_BRIGHT_PURPLE 0x0D

//����
#define FOREGROUND_BRIGHT_YELLOW 0x0E

//����
#define FOREGROUND_BRIGHT_WHITE  0x0F

/* ����ɫ */

//��
#define BACKGROUND_BLACK  0x00

//��
#define BACKGROUND_BULE   0x10

//��
#define BACKGROUND_GREEN  0x20

//��
#define BACKGROUND_CYAN   0x30

//��
#define BACKGROUND_RED    0x40

//��
#define BACKGROUND_PURPLE 0x50

//��
#define BACKGROUND_YELLOW 0x60

//��
#define BACKGROUND_WHITE  0x70

//���ڣ��ң�
#define BACKGROUND_BRIGHT_BLACK  0x80

//����
#define BACKGROUND_BRIGHT_BULE   0x90

//����
#define BACKGROUND_BRIGHT_GREEN  0xA0

//����
#define BACKGROUND_BRIGHT_CYAN   0xB0

//����
#define BACKGROUND_BRIGHT_RED    0xC0

//����
#define BACKGROUND_BRIGHT_PURPLE 0xD0

//����
#define BACKGROUND_BRIGHT_YELLOW 0xE0

//����
#define BACKGROUND_BRIGHT_WHITE  0xF0

// �Դ���ɫ��ʽʹ�ø�ʽ����׼�������ɫ���������ά�֡�
extern void console_printf(unsigned short colors, const char* format, ...);

// �Դ���ɫ��ʽʹ���ַ����������ɫ���������ά�֡�
extern void console_puts(unsigned short colors, const char* str);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif /* !__GO_SOUTH_GRAPHIC_CONSOLE_TEXT_H__ */
