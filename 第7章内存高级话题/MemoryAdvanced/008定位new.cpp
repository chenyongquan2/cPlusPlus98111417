#include<iostream>
#include<cstdlib>
#include<string>
#include<vector>
#include <memory>
#include <set>
#include <map>
#include <list>
#include <array>

using namespace std;

void *operator new(size_t size)
{
	return  malloc(size);
}



class A
{
public:
	A()
	{
		cout << "调用类A的无参构造函数" << endl;
	}
	A(int m):m_a(m)
	{
		cout << "调用有参数构造函数" << endl;
	}

	~A()
	{
		cout << "调用类A的析构函数" << endl;
	}
	
	//传统new
	void *operator new(size_t size,void*pHead)
	{
		return  pHead;//收到原始地址，返回即可
	}
	
	//定位new重载
	void *operator new(size_t size,void*pHead)
	{
		return  pHead;//收到原始地址，返回即可
	}
	
	//重载的多个版本的new
	void *operator new(size_t size, int v1, int v2)
	{
		cout << "调用了重载的双v的new" << endl;
		void *p = malloc(size);
		return p;
	}

public:
	int m_a;

};

int main(void)
{
	//(1)
	void *myPlaceNew = (void*)new char[sizeof(A)];//内存必须先分配出来
	// A*myA = A::A();// 一般构造函数不能手动调用，通过定位new来手动调用构造函数
	A*myA = new (myPlaceNew)A();//调用无参构造函数，在myPlaceNew构造对象
	//查看汇编：A*myA = new (myPlaceNew)A();
		//call operator new(0811223H)//这里并没有调用malloc
		//call _nmsp2::A::A(081144hH)//调用构造函数
	//A *myA = new A();//调用传统new	
	
	void *myPlaceNew02 = (void*)new char[sizeof(A)];
	A*myA02 = new (myPlaceNew02)A(2);//调用有参数构造函数在myPlaceNew构造对象
	
	delete myA;//ok，也会去调用类对象的析构函数以及释放内存，等价于下面两句(下面的写法更加灵活)
	//怎么析构
	myA->~A();//构造函数不可以手动调用，析构函数可以手动调用
	delete[](void*)myA;
	
	myA02->~A();
	delete[](void*)myA02;

	////
	A* p1 = new (120, 343)A();

	system("pause");
	return 0;
}

/*
*(1)定位new(对比传统new)---placement new  在指定的空间构造对象
*	1.有new，但是没有delete
*	2.功能：在已经分配的原始内存中初始化一个对象。
*		1.已经分配内存，定位new并不分配内存，你需要提起那将这个定位new所需要使用的内存分配出来
*		2.初始化一个对象(初始化一个对象的内存)-->调用对象的构造函数。
*	说白了，就是在一个分配好的内存空间中调用构造函数构造一个对象。
*使用定位new达到调用构造函数的目的
*
*格式：
*new(地址) 类类型（参数）
*
*
*可以重载很多版本的operator new，但是第一个参数是固定的，都是size_t 表示你要new对象的size值。
*
*2019年11月29日21:46:26
* Sunrise于东北电力大学第二教学楼1121实验室

*/
