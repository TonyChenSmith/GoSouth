/*
 * 主程序入口。
 * 
 * @time 2021-10-16
 */
#include<cstdio>
#include<cstdlib>
#include"graphic/console_text.h"

int main()
{
    unsigned short index,subindex;
    char str[]={0xE6,0xB5,0x8B,0xE8,0xAF,0x95,0x25,0x2E,0x32,0x6C,0x66,0};
    console_printf(FORE_GREEN | BACK_BLACK, str,1.238);
    console_printf(FORE_GREEN | BACK_BLACK, "测试");
    return 0;
}
