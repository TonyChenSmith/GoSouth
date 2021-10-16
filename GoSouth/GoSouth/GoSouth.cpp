/*
 * 主程序入口。
 * 
 * @time 2021-10-16
 */
#include<cstdio>
#include"graphic/console_text.h"

int main()
{
    unsigned short index,subindex;
    for (index = 0; index < 16; index++)
    {
        console_printf(index | BACKGROUND_GREEN, "A\nA\nA\n");
    }
    return 0;
}
