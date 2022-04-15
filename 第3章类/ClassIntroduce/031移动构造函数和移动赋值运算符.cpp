#include<iostream>
#include<cstdlib>
#include<string>
#include<vector>

using namespace std;

class B
{
public:
	B():m_bm(100)
	{
		cout << "类B的构造函数执行" << endl;
	}
	//拷贝构造函数
	B(const B&temb)
	{
		this->m_bm = temb.m_bm;
		cout << "类B的拷贝构造函数执行" << endl;
	}
	//析构函数
	virtual ~B()
	{
		cout << "类B的析构函数执行" << endl;
	}
	//移动构造函数
public:
	int m_bm;
};


class A
{
public:
	A():b(new B())
	{
		cout << "类A的默认构造函数执行" << endl;
	}
	//拷贝构造函数
	A(const A&temA):b(new B(*(temA.b)))//调用类B的拷贝构造函数
	{
		//this->b = new B(*temA.b);
		cout << "类A的拷贝构造函数执行" << endl;
	}

	//移动构造函数    
	//noexcept通知标准库，移动构造函数不抛出任何异常（编译器可能为异常做一些额外工作，加上这个关键字不抛出异常，编译器就不用做这些额外工作了提高效率）
	//注意：最好移动构造函数以及移动赋值运算符声明和实现都得带上这个noexcept。
	
	A (A&&temA)noexcept:b(temA.b)//直接让临时对象指向内存，这样两个指针指向同一块内存
	{
		//要打断原来对象指针指向的内存，不要让两个指针指向同一块内存
		temA.b = nullptr;
		
		//这里应该让对象a的B*b指针打断，并直接移动到新的对象
		cout << "类A的移动构造函数执行" << endl;
	}
	//拷贝赋值运算符
	A& operator=(const A&src)
	{
		if (this==&src)
		{
			return*this;
			
		}
		delete b;//把自己的内存删除掉
		b = new B(*(src.b));//重新分配一段内存，调用拷贝构造函数
		cout << "类A的拷贝赋值运算符执行" << endl;
		return *this;
	}
	
	//移动赋值运算符
	A &operator=(A&&src)noexcept
	{
		if (this==&src)
		{
			
			return *this;
		}
		delete b;//把自己的内存删除掉
		b = src.b;//把对方的内存地址直接拿过来
		src.b = NULL;
		std::cout << "类A的移动赋值运算符执行了" << endl;
		return *this;
	}
	
private:
	B* b;
	
};


class testMove
{
public:
	int number01;
	string str;//string内部带移动构造函数
};

static  A getA()
{
	A a;
	return  a;
	//情况1:调用拷贝构造函数生成一个临时对象tmp返回之，
	//情况2:这里如果A有移动构造函数，那么就会优先调用移动构造函数把a对象的数据给移动给tmp临时对象
}

int main(void)
{
	B *b1 = new B();//调用构造函数
	b1->m_bm = 100;
	B*b2 = new B(*b1);//调用B的拷贝构造函数

	delete b1;//调用析构函数
	delete b2;

	cout << "---------------------------" << endl;
	A a1 = getA();
	/*
	 *  
	//增加移动构造函数前:
	(类B的构造函数执行
	类A的默认构造函数执行)1次构造函数+
	(类B的拷贝构造函数执行
	类A的拷贝构造函数执行)1次拷贝构造函数【PS:来返回tmp临时对象】+
	2次析构A对象的析构
	
	

	//增加移动构造函数后：
	(类B的构造函数执行
	类A的默认构造函数执行)1次构造函数+
	(类A的移动构造函数) 1次拷贝构造函数 【执行 将getA()里栈上的a对象给移动构造给了临时对象tmp,而tmp对象空间是直接分配在a1预留空间上。】
	2次析构A对象的析构
	 */

	cout << "---------------" << endl;
	A a2(a1);//执行拷贝构造函数

	//如何将a1内容移动给a2？-->使用std::move()转换为一个右值，就会调用移动构造函数
	A a3(std::move(a1));//调用移动构造函数--因为传递过来的是一个右值
	//A &&a4(std::move(a1));//这里没有产生新对象，根本不会调用移动构造函数，相当于a1有了一个新的别名叫a4，后续不要使用a1(虽然没毛病)

	cout << "******************" << endl;
	A&&a5 = getA();//返回临时对象被引用a5接管(移动构造函数) 与上面的 A a3(std::move(a1));执行结果一样 一次构造 一次移动构造 一次析构 
	/*
	 * 
	类B的构造函数执行
	类A的默认构造函数执行
	类A的移动构造函数执行
	 */

	//移动拷贝赋值运算符
	A a6;//调用构造函数
	a6 = std::move(a1);//left value-->right value=调用移动赋值运算符(若有)

	//证明系统会在满足要求生成默认移动构造函数
	testMove tm;
	tm.number01 = 01;
	tm.str = "jisuanji";

	testMove tm2 = std::move(tm);	//系统帮我们合成了移动构造函数，里面调用了string的移动构造函数,把tm里的str移动tm2的str里 (不是move函数实现的)
	cout << "00000000000000000" << endl;
	cout << tm.number01 << endl;	//1
	cout << tm.str << endl;	//无
	
	system("pause");
	return 0;
}

/*
*(1)对象移动概念
*	进行兑现的拷贝系统新更能消耗太大。所以c++中引入“对象移动”的概念。将一个不用的对象的内存移动给其他对象。
*	这样可以节约系统性能。
*
*(2)移动构造函数和移动赋值运算符概念（c++11新引入的）
*程序执行的效率问题。
*移动构造函数：c++引入，进一步提高程序运行效率。
*	1.如果拷贝数据，A移动到B，那么A对象我们就不能再使用了。
*	2.并不是把内存中的数据从一个地址复制到另一个地址。只是内存数据的所有者变更。数据在内存中没变，但是所有者A已经变换。
*
*若有其他参数，则得为默认参数
*拷贝构造函数：Time::Time(const Time&temTime,int a=10){} const左值引用
*移动构造函数：Time::Time(const Time&&temTime,int a=10){}	//右值引用&&---右值可以认为是个临时，不能改变的量
*目的：把一个对象A一些有用的数据移动给另一个对象B，以后不能使用对象A
*移动构造函数和移动赋值运算符应该完成的功能：
*	1.完成必要的内存移动，斩断原对象和内存之间的关系。
*	2.确保移动后原对象处于一种“即便被销毁也没什么问题”的一种状态。却保不再使用A。
*	
*(3)移动赋值运算符--使用&&
*(4)合成的移动操作
*		1.如果不写拷贝构造函数构造函数，某些条件下可以自己合成移动构造函数，移动赋值运算符
*		2.有自己的拷贝构造函数，自己的拷贝赋值运算符(编译器认为你既然要写构造函数的需求，就认为拷贝的逻辑可能比较复杂(有设计到新申请对象等复杂操作)
		因为编译器合成不了这么复杂的,编译器宁愿不给你生成)，
		或者自己的析构，那么编译器就不会合成移动构造函数和移动赋值运算符。(有这种拷贝对象或者释放对象的倾向的话)
*			所以一些类是没有合成移动构造函数和移动赋值运算符。
*			说明移动构造函数和移动赋值运算符是非常讲究的，不是那么容易实现的。
*	
*		3。如果没有移动拷贝构造函数和移动赋值运算符，系统会调用拷贝构造函数和赋值运算符会顶替，
		//虽然参数不一样(因为拷贝构造函数参数是const A&temA,可以接收左值，也可接受右值)，
		eg:
			A a6;//调用构造函数
			a6 = std::move(a1);//若有移动赋值运算符，优先使用移动赋值运算符，若无，则使用拷贝赋值运算符来代替
*				
*		4.只有一个类没有定义任何版本的拷贝构造函数成员(没有拷贝构造函数 也没有拷贝赋值运算符)，且每个非静态成员都可以移动时，编译器才会为该类合成移动构造函数和移动赋值运算符。
*			什么叫成员可移动？
*				1.内置类型 int string 本身可以移动
*				2.如果是个类类型成员，这个类要有对应的移动操作相关函数，就可以移动
*			那么编译器就会合成移动构造函数和移动赋值运算符。
*		
*		
*
*(5)总结
*	1.尽量给类增加移动构造函数和移动赋值运算符
*	2.不抛出异常的移动构造函数和移动赋值函数尽量加上 noexcept
*	3.一个对象移动数据后不会自动销毁，该指向null就要指向，让被移动对象处于一种能够被析构的状态
*	4.没有移动构造函数和移动赋值运算符，会使用相应的拷贝构造函数执行。
*	
*
*
*/
