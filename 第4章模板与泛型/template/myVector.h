#pragma once
#ifndef __MYVECTOR__
#define __MYVECTOR__

//定义myvector类
template <typename T>//名字为T的模板参数，用来表示myVector所保存的运算类型
class myVector
{
public:
	//迭代器，
	typedef T* myIterator ;	//如传递过来int类型，这里为int*---这是类型成员
public:
	myVector();//构造函数
	myVector&operator=(const myVector&my_vector);//赋值运算符重载，在类内部使用模板名字不需要提供模板参数
	//myVector<T>&operator=(const myVector<T>&my_vector);//ok
public:
	myIterator mybegin();//迭代器的其实位置
	myIterator myend();//迭代器的最后一个元素的下一个位置

	//void myTestFunctin();
	//当然，类模板的成员函数的定义，也可以写在类模板定义中，即{}中。这种写在类模板定义中的会被显示声明为inline函数。
	void myTestFunctin(){};//具体实现放在类模板的定义之中了。
};

//类模板一旦被实例化之后，那么模板的每个实例都会有自己版本的成员函数。
//类模板的成员函数和这个类模板具有相同的模板参数。这句话的核心意思是：类模板的成员函数室是有模板参数的。（在类外实现可以看见）
/*
所以 如果你要把类模板成员函数的定义(函数体)写在模板定义的外边，那么这个成员函数的模板参数就体现出来了
*.定义在类模板之外的成员函数必须以关键字template开始，后边接类模板参数列表
*	同时类名后面使用<>把模板参数列表里面的所有参数模板名字列出来，多个模板参数之间使用,逗号分开
*/

//构造函数
template <typename T>
myVector<T>::myVector()
{
	
}

//使用typedef自定义了数据类型
template <typename T>
typename myVector<T>::myIterator/*函数返回值*/     myVector<T>::mybegin()
{
	
}

//使用typedef自定义了数据类型
template <typename T>
//typename用法2.访问类型成员myIterator
//typename 的用处就是显式告诉编译器myVector<T>::myIterator是一个类型
typename myVector<T>::myIterator/*函数返回值*/     myVector<T>::myend()
{
	
}

//第一个T要返回一个实例化的类模板类型，第二个T表示是一个实例化的类
template <typename T>
myVector<T>& myVector<T>::operator=(const myVector& my_vector) //myVector<T>这个表示是一个返回后的myVector
{//参数列表里面可加可不加(const myVector<T>& my_vector) 可加<T>
	
}

template<typename  T>
void myVector<T>::myTestFunctin()
{
	cout<<"这是测试函数"	<<endl;
}


#endif
