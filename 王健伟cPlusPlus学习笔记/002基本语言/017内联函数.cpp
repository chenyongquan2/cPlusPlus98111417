#include<iostream>
#include<cstdlib>
using namespace std;
#define  PI 3.1415926

inline int myFunction(int testv)	//在函数定义前面加一个inline，就变成内联函数
{
	return 1;
}

constexpr int myFunction02()
{
	return 1;
}


int main(void)
{
	
	int number1 = myFunction(22);
	
	system("pause");
	return 0;
}

/*
* (1)内联函数--在函数定义(不是声明)前面加上inline，导致函数变成内联函数
*	为什么需要内联函数--解决频繁调用小函数的系统开销。（压栈，出栈的系统开始）
*
*	a.inline在影响编译器，在编译阶段对inline这种函数进行处理。
*		--系统尝试将调用函数的动作替换为函数本体，通过这种方式来提升性能。
*
*	b.inline只是开发者对编译器的一个建议，请求。编译器可以做，可以不做，取决于编译器的诊断功能
*		也就是说是否替换的决定权在编译器，我们控制不了。
*
*	c.内联函数的定义就要放在头文件.h中，这样设计需要用到内联函数的实现都可以通过#include把
*		函数的定义包含进来，以便找到函数的本体源代码替换为函数调用内部的调用。
*		不可以在.h文件中放置普通函数的实现，否则编译会出错，请复习头文件防卫。
*
*	优缺点
*	（1）如果编译器替换成功，可以增加效率，但是会带来代码膨胀问题。所以建议函数体尽量小。
*	（2）注意：inline的实现具体优化由编译器优化的，可能把代码优化成一个常量。各种编译器对inline的处理各不相同。
*		要求内联函数尽量小，循环，分支，递归尽量不要出现在inline函数中，否则编译器可能因为代码复杂的原因拒绝让
*		这个函数成为一个内联函数。
*		constexpr函数可以看做一种更严格的内联函数。

*		内联函数类似于一个宏展开。
*		
*/
