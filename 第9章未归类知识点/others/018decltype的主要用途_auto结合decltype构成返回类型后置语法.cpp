#include<iostream>
#include<cstdlib>
#include <vector>

using namespace std;


//函数返回类型的后置语法
auto func(int a,int b)->int
{
	return 0;
}

auto add(int i,int k)->decltype(i+k)
{
	return i + k;
}

int&myfunction01(int&i)
{
	return i;
}
double myfunction01(double&i)
{
	return i;
}

//函数模板
template<typename T>
//decltype(myfunction01(tv))  myFunTemplate(T&tv) //error，因为返回类型写在前面，但是此时tv还没有(这货在函数形参里面的)
auto myFunTemplate(T&tv)->decltype(myfunction01(tv))//返回类型后置，要先有tv，才能用tv，这里必须用返回类型后置这种用法
//注意：上面这一行的auto并没有自动类型推导的含义，这里它只是返回类型后置语法的组成部分。
//auto myFunTemplate(T&tv) //ok，并且auto有自动类型推导的含义

{
	return myfunction01(tv);
}

int main(void)
{
	//2.3decltype的主要用途_decltype(auto)用法
	int i = 12;
	double d = 23.34;
	cout << myFunTemplate(i) << endl;//12
	cout << myFunTemplate(d) << endl;//23.34

	
	system("pause");
	return 0;
}
/*
* (2)2.3decltype的主要用途_auto结合decltype构成返回类型后置语法
*auto这里没有自动类型推断的意思，只是返回类型后置语法的组成部分
* 
*/
