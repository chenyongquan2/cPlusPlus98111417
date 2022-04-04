#include<iostream>
#include<cstdlib>

using namespace std;


void printInformation(int&tem)//类型是左值引用的形参
{
	cout << "形参类型为左值引用的函数" << endl;
}
void printInformation(int&&tem)//类型是左值引用的形参
{
	cout << "形参类型为右值引用的函数" << endl;
}

template<typename T>
void testTransmit(T&&t)//万能引用
{
	printInformation(t);//如果t是右值，T=int t=int&&类型，t本身是左值	如果t是左值，T=int&,t=int&类型，t本身是左值
	printInformation(std::forward<T>(t));
	printInformation(std::move(t));//move将左值转换为右值
	
}

void f12()
{
	int i = 10;
	//std::forward<T>要转成啥样，取决于T的类型
	int&& ir1 = std::forward<int>(i);//forward这里成功把i转换成右值
	int& ir2 = std::forward<int &>(i);
}

int main(void)
{
	testTransmit(1);//传递右值
	/*
	 *  形参类型为左值引用的函数
		形参类型为右值引用的函数
		形参类型为右值引用的函数
	 */

	int i = 123;
	testTransmit(i);//传递左值
	/*

	形参类型为左值引用的函数
	形参类型为左值引用的函数
	形参类型为右值引用的函数
	 */
	system("pause");
	return 0;
}
/*
 * (1)std::forward()小例子
 * (2)
 * (3)
 * (4)
 * (5)
 * (6)(7)
 */
