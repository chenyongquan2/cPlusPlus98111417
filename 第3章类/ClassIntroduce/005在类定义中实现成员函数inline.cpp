#include<iostream>
#include<cstdlib>
#include<string>
#include<vector>
using namespace std;

class Time
{
private:
	int Hour;
	int Minute;
	int Second;
public:
	explicit Time(int Hour, int Minute, int Second);
	Time(int Hour);
public:
	void AddHour(int TemHour)//问题：如果这个类实现的函数在.h中，若被多次include函数体，是否会像普通的成员函数那般说会被重复定义？
	//不会，因为这种函数被当做inline内联函数处理,不会报重复定义的错。
	{
		/*(1)在类定义中实现成员函数inline(宏展开，减少入栈出栈的开销)，类内的成员函数实现其实也叫类的成员函数定义。
*	AddInline()函数在类的定义中实现的成员函数，会被当做inline内联函数来处理。
*	能不能内联成功，取决于具体的编译器。*/
		
		Hour = Hour + TemHour;
	}

};

Time::Time(int TemHour, int TemMinute, int TemSecond) :Hour(TemHour), Minute(TemMinute), Second(TemSecond)//把形式参数赋值给成员属性
{
}
Time::Time(int Hour)
{
	this->Hour = Hour;
}


int main(void)
{
	Time myTime01 = Time(12, 12, 12);

	system("pause");
	return 0;

}

/*
*(1)在类定义中实现成员函数inline，类内的成员函数实现其实也叫类的成员函数定义。
*	AddInline()函数在类的定义中实现的成员函数，会被当做inline内联函数来处理。
*	能不能内联成功，取决于具体的编译器。
*
*(2)
*(3)
*
*/
