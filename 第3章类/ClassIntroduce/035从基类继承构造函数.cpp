#include<iostream>
#include<cstdlib>
#include<string>
#include<vector>

using namespace std;
class A
{
public:
	A(int i) {};
};
class B
{
public:
	B(int i) {};
};
class C:public A,public B
{
public:
	//using A::A;继承A的构造函数=>C(int i):A(i){}
	//using B::B;继承B的构造函数=>C(int i):B(i){}
	//上面冲突
	C(int c) :A(c), B(c) {}//如果一个类从它的基类中继承了相同的构造函数，这个类必须为该构造函数定义自己的版本。
};


int main(void)
{
	playObject();
	system("pause");
	return 0;
}

/*
*(1)从多个父类继承构造函数
*	如果一个类从它的基类中继承了相同的构造函数，这个类必须为该构造函数定义自己的版本。
*
*/
