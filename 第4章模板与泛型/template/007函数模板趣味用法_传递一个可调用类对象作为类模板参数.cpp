#include<iostream>
#include<cstdlib>
#include<string>
#include<vector>

using namespace std;

int myFunction(int a, int b)
{
	return  a + b;
}


//把函数指针作为另外一个函数的参数传递？？
//
//定义一个函数指针类型
typedef int(*FunType)(int, int);

template <typename T,typename F>//F为类类型Tc
void testFunction(const T&i,const T&j,F myfunc)//当F为类类型，会调用拷贝构造函数
//template <typename T,typename F=tc>//默认类型为tc
//void testFunction(const T&i,const T&j,F myfunc=F())//当F为类类型，产生默认的临时对象F()，即tc()
//解读为=>void testFunction(const int&i,const int&j,Tc myfunc=Tc())

{
	cout << myfunc(i, j) << endl;//当myfunc为类对象，会去调用类对象的operator()运算符。
}

class tc
{
public:
	tc()
	{
		cout << "无参构造函数执行" << endl;
	}
	tc(const tc&t)
	{
		cout << "拷贝构造函数执行" << endl;
	}
	//重载()函数调用运算符
	int operator()(int a,int b)
	{
		return a + b;
	}
public:
	
};



int main(void)
{
	testFunction(1, 2,myFunction);//自动推断 T为int，F为函数指针类型


	tc object01;
	testFunction(3, 4, object01);
	/*
	 * 1.首先调用拷贝构造函数执行，把一个object01拷贝给形参,判断为类 类型
	 * 2.然后调用重载的函数调用()运算符
	 */
	cout << "_______________________________" << endl;
	testFunction(5, 6, tc());//使用一个临时对象，少调用一个拷贝构造函数，只调用了无参构造函数

	
	system("pause");
	return 0;
}

/*
 *传递一个可调用类对象作为类模板参数
 *
*(1)可调用对象概念--具体见“未归类知识点1”
*	1.如果类重载了函数调用运算符（也就是括号运算符），则我们可以像使用函数一样使用该类的对象，
*		我们把这样的类对象称为函数对象（function object）或者仿函数(仿造的函数)
*	2.C++语言中有几种可调用对象：函数、函数指针、lamba表达式、
*		bind创建的对象以及重载了函数运算符的类。
*
*(2)
*
*(3)
*
*
*/
