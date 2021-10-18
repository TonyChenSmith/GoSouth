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
    for (index = 0; index < 16; index++)
    {
        console_printf(index | BACKGROUND_GREEN, "A\nA\nA\n");
    }
    console_puts(0x51, "Test.\n");
    return 0;
}
