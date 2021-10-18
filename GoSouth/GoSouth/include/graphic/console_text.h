/*
 * 本文件为对控制台文本输出函数定义。
 * 
 * @author 海中垂钓
 * @time 2021-10-16
 */
#ifndef __GO_SOUTH_GRAPHIC_CONSOLE_TEXT_H__
#define __GO_SOUTH_GRAPHIC_CONSOLE_TEXT_H__

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus


/* 前景色 */

//黑
#define FORE_BLACK  0x00

//蓝
#define FORE_BULE   0x01

//绿
#define FORE_GREEN  0x02

//青
#define FORE_CYAN   0x03

//红
#define FORE_RED    0x04

//紫
#define FORE_PURPLE 0x05

//黄
#define FORE_YELLOW 0x06

//白
#define FORE_WHITE  0x07

//亮黑（灰）
#define FORE_BRIGHT_BLACK  0x08

//亮蓝
#define FORE_BRIGHT_BULE   0x09

//亮绿
#define FORE_BRIGHT_GREEN  0x0A

//亮青
#define FORE_BRIGHT_CYAN   0x0B

//亮红
#define FORE_BRIGHT_RED    0x0C

//亮紫
#define FORE_BRIGHT_PURPLE 0x0D

//亮黄
#define FORE_BRIGHT_YELLOW 0x0E

//亮白
#define FORE_BRIGHT_WHITE  0x0F

/* 背景色 */

//黑
#define BACK_BLACK  0x00

//蓝
#define BACK_BULE   0x10

//绿
#define BACK_GREEN  0x20

//青
#define BACK_CYAN   0x30

//红
#define BACK_RED    0x40

//紫
#define BACK_PURPLE 0x50

//黄
#define BACK_YELLOW 0x60

//白
#define BACK_WHITE  0x70

//亮黑（灰）
#define BACK_BRIGHT_BLACK  0x80

//亮蓝
#define BACK_BRIGHT_BULE   0x90

//亮绿
#define BACK_BRIGHT_GREEN  0xA0

//亮青
#define BACK_BRIGHT_CYAN   0xB0

//亮红
#define BACK_BRIGHT_RED    0xC0

//亮紫
#define BACK_BRIGHT_PURPLE 0xD0

//亮黄
#define BACK_BRIGHT_YELLOW 0xE0

//亮白
#define BACK_BRIGHT_WHITE  0xF0

// 以带颜色方式使用格式化标准输出。颜色在输出后不再维持。字符集为UTF-8，非程序内建的字符串。
extern void console_printf(unsigned short colors, const char* format, ...);

// 以带颜色方式使用字符串输出。颜色在输出后不再维持。字符集为UTF-8，非程序内建的字符串。
extern void console_puts(unsigned short colors, const char* str);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif /* !__GO_SOUTH_GRAPHIC_CONSOLE_TEXT_H__ */
