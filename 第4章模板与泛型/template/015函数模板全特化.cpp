#include<iostream>
#include<cstdlib>
#include<string>
#include<vector>

using namespace std;


template<typename T,typename U>
void TestFunction(T &t,U&u)
{
	cout << "--这是函数泛化版本--" << endl;
}

//全特化版本 t=int，u=doubel
template<>//全特化，所以为空
void TestFunction(int &t, double&u)
{
	cout << "--这是int double类型的特化版本--" << endl;
}

//函数重载写法
void TestFunction(int &t, double&u)
{
	cout << "这是testFunction的重载函数" << endl;
}

int main(void)
{
	//函数模板全特化
	const char*p = "jisuanjiz";
	int i = 1200;
	TestFunction(p, i);//t=const char* &
	

	double d = 23.344;
	TestFunction(i, d);//调用int double 的特化版本
	//如果有重载函数，优先调用重载函数，而不去调用特例话的函数

	system("pause");
	return 0;
}

/*
*(1)函数模板全特化
*全特化函数实际山等价于实例化一个函数模板，并不是等价于一个函数重载
*
*特化函数遇上重载函数优先调用哪一个？？？优先函数重载，再而看是否满足特化版本，最后看泛化版本
*

**如果你要传递一个字符串给函数模板
*函数的模板中有数组类型的模板参数，指针类型模板参数。
*编译器会认为 数组类型模板参数更加合适。所以编译器会为你选择数组类型的模板参数的 特化版本。
* Sunrise于东北电力大学第二教学楼1121实验室2019年11月25日15:58:46
*
*(2)
*
*(3)
*
*
*/
