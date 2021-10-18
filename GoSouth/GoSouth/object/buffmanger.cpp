/*本代码对buff进行初始化及处理（未完）
 *缺少buff描述文件
 *
 * @yzh159
 * date：2021/10/18
 */

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include"graphic/console_text.h"
#include"object/buffmanger.h"


extern void settings()
{
	std::string x,y,z;
	x="The best sword in the hometown";
	y="攻击＋1";
	z="带着全村的希望出发";
	BuffManger p;
	p.addBuff(x,y,z,1,0);
	console_printf(FORE_WHITE,"%s",p.getIntroduction().c_str());
}
