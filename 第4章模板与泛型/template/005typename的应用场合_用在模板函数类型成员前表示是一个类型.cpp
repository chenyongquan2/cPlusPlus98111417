#include<iostream>
#include<cstdlib>
#include<string>
#include<vector>

using namespace std;

//求字符串的长度
template<typename T>
typename T::size_type GetLength(const T&c)
{
	if (c.empty())
	{
		return 0;
	}
	return c.size();
}


int main(void)
{
	string mytest = "jisuanjizuchegnyuanli";
	string::size_type size = GetLength(mytest);//等价于无符号整形

	
	system("pause");
	return 0;
}

/*
*(1)typename的使用场合
*	1.在模板定义里面。typename标明其后的参数是类型参数		template<typename T,int a,int b>
*	template<typename T>		//名字为T的模板参数
*	typename 可以使用class，这里的class不是类定义，表示类型参数
*	2.使用类的类型成员，用typename来表示这是一个类型
*	用法1  ::可以表示类成员作用域
*	用法2  ::还可以表示访问“模板类的"类型"成员”。（T类型的成员变量）
*		s上一节的typedef T* myIterator;//就是模板类的类型成员
*				函数返回值
*		a在类外：
*		typename myVector<T>::myIterator   myVector<T>::myend()
*		typename 的用处就是显式告诉编译器myVector<T>::myIterator是一个类型（用法2，而不是表示静态成员变量，否则编译器就区分不了::后面接的是类型成员还是静态成员）
*
		typename T::size_type GetLength(const T&c)
		中的T::size_type也是类型，类似于unsigned int，所以前面需要加上typename
*
*(2)
*
*(3)
*
*
*/
