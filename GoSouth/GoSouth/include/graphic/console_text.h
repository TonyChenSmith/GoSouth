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
#define FOREGROUND_BLACK  0x00

//蓝
#define FOREGROUND_BULE   0x01

//绿
#define FOREGROUND_GREEN  0x02

//青
#define FOREGROUND_CYAN   0x03

//红
#define FOREGROUND_RED    0x04

//紫
#define FOREGROUND_PURPLE 0x05

//黄
#define FOREGROUND_YELLOW 0x06

//白
#define FOREGROUND_WHITE  0x07

//亮黑（灰）
#define FOREGROUND_BRIGHT_BLACK  0x08

//亮蓝
#define FOREGROUND_BRIGHT_BULE   0x09

//亮绿
#define FOREGROUND_BRIGHT_GREEN  0x0A

//亮青
#define FOREGROUND_BRIGHT_CYAN   0x0B

//亮红
#define FOREGROUND_BRIGHT_RED    0x0C

//亮紫
#define FOREGROUND_BRIGHT_PURPLE 0x0D

//亮黄
#define FOREGROUND_BRIGHT_YELLOW 0x0E

//亮白
#define FOREGROUND_BRIGHT_WHITE  0x0F

/* 背景色 */

//黑
#define BACKGROUND_BLACK  0x00

//蓝
#define BACKGROUND_BULE   0x10

//绿
#define BACKGROUND_GREEN  0x20

//青
#define BACKGROUND_CYAN   0x30

//红
#define BACKGROUND_RED    0x40

//紫
#define BACKGROUND_PURPLE 0x50

//黄
#define BACKGROUND_YELLOW 0x60

//白
#define BACKGROUND_WHITE  0x70

//亮黑（灰）
#define BACKGROUND_BRIGHT_BLACK  0x80

//亮蓝
#define BACKGROUND_BRIGHT_BULE   0x90

//亮绿
#define BACKGROUND_BRIGHT_GREEN  0xA0

//亮青
#define BACKGROUND_BRIGHT_CYAN   0xB0

//亮红
#define BACKGROUND_BRIGHT_RED    0xC0

//亮紫
#define BACKGROUND_BRIGHT_PURPLE 0xD0

//亮黄
#define BACKGROUND_BRIGHT_YELLOW 0xE0

//亮白
#define BACKGROUND_BRIGHT_WHITE  0xF0

// 以带颜色方式使用格式化标准输出。颜色在输出后不再维持。
extern void console_printf(unsigned short colors, const char* format, ...);

// 以带颜色方式使用字符串输出。颜色在输出后不再维持。
extern void console_puts(unsigned short colors, const char* str);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif /* !__GO_SOUTH_GRAPHIC_CONSOLE_TEXT_H__ */
