/*
 *本文对buff部分进行设定，包括名称，效果，描述
 *
 *@yzh159
 * date：2021/10/18
 */
#include<string>
#ifndef _GO_SOUTH_OBJECTS_BUFFMANGER_
#define _GO_SOUTH_OBJECTS_BUFFMENGER_

class BuffManger
{
private:
	unsigned short number=0;

	struct Buff
	{
		//buff名称
		std::string name;
		//buff效果
		std::string effect;
		//buff描述
		std::string introduction;
		//目前只认为buff增加攻击和移动力
		//修改buff攻击力加成
		unsigned short attackBuff=0;
		//修改buff移动力加成
		unsigned short actionBuff=0;
	}buff[10];

	void setName(std::string newName)
	{
		buff[number].name=newName;
	}

	void setEffect(std::string newEffect)
	{
		buff[number].effect=newEffect;
	}

	void setIntroduction(std::string newIntroduction)
	{
		buff[number].introduction=newIntroduction;
	}

	void setAttack(unsigned short newAttack)
	{
		buff[number].attackBuff=newAttack;
	}

	void setAction(unsigned short newAction)
	{
		buff[number].actionBuff=newAction;
	}

public:
	//对buff初始化
	void addBuff(std::string newName,std::string newEffect,std::string newIntroduction,unsigned short newAttack,unsigned short newAction)
	{
		number++;
		setName(newName);
		setEffect(newEffect);
		setIntroduction(newIntroduction);
		setAttack(newAttack);
		setAction(newAction);
	}
	//获得buff名称
	std::string getName()
	{
		return buff[number].name;
	}
	//获得buff效果
	std::string getEffect()
	{
		return buff[number].effect;
	}
	//获得buff描述
	std::string getIntroduction()
	{
		return buff[number].introduction;
	}

	unsigned short getAttackBuff()
	{
		return buff[number].attackBuff;
	}

	unsigned short getActionBuff()
	{
		return buff[number].actionBuff;
	}
};
extern void settings();
#endif // !_GO_SOUTH_OBJECTS_EQUIPMENT_
