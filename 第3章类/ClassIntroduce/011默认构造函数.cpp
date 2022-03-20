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
    Time(){}

};

Time::Time(int TemHour, int TemMinute, int TemSecond) :Hour(TemHour), Minute(TemMinute), Second(TemSecond)//把形式参数赋值给成员属性
{
}
Time::Time(int Hour)
{
	this->Hour = Hour;
}

class A
{
public:
	//含有一个B的成员变量，而B没有不带参数的默认构造函数，
	//所以当A不含有构造函数时，编译器合成的A的默认构造函数里面会去尝试调用B的默认构造函数，但是B没有不带参数的默认构造函数
	
	A():bb(10)//这种情况下合成的默认构造函数是不够用的，我们得手工鞋一个
	{
	}
	B bb;
};
class B
{
public:
	B(int)
	{
	}
}

int main(void)
{
	//Time myTime01 = Time(12, 12, 12);

	Time myTime02;	//调用默认构造函数
	system("pause");
	return 0;

}


/*
*(1)默认构造函数--没有任何参数的构造函数
*	1.如果没有任何构造函数，系统默认给一个默认构造函数，编译器自动定义一个默认构造函数，这个叫“合成的默认构造函数”
*	2.一旦我们写了构造函数，系统就不会自动创建默认构造函数。
*(2)当进行类的组合时候，会包含其他类的对象，必须使用成员初始化列表和初始值，手工写自己的构造函数。
*(3)
*2019年11月17日09:11:05 Sunrise于东北电力大学第二教学楼1121实验室
*
*/
