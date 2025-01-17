/*
 * (1)一些概念
 *	1.c++标准库 standard library c++编译器自带，可以在代码中包含头文件直接使用。
 *	引入的目的就是解决一些反复使用的功能，我们直接使用即可。
 *	2.c++标准模板库，STL=standard template library。包含在c++标准库中，是c++标准库的核心。
 *		STL深刻影响着c++标准库
 *	3.泛型编程 generic programming 使用模板template为主要的编程手段来编写代码。
 *		我们可以认为标准模板库就是使用泛型编程的编码方式为我们提供的一套库。
 *	
 * (2)推荐书籍
 *		权威书籍 c++标准库第二版 侯捷  概览即可，作为工具书,因为我们只需要使用其中的一部分的内容
 *				STL源码剖析	侯捷  不建议自己详细剖析，stl源码太难衡量。
 * (3)算法和数据结构谈
 *	疑问：要不要把算法和数据结构的知识学习，然后再学习STL?
 *
 *		数据结构浅谈：数据结构是研究数据怎么存储的问题。树，栈，队列，链表，散列表。
 *			每一种数据结构都有一定的特点，有的存储快，有的查询快，我们需要使用代码实现这些数据结构
 *
 *		数据结构学习方法：对数据结构有简单认识，不需要知道太多。
 *				但是对栈，队列，链表这3个需要大概了解。
 *				栈：后进先出
 *				队列：先进先出
 *				链表：顺序存储的一种结构，
 *			其他数据结构，树，图，散列表等有一定概念就可以。
 *	答案：除非将来做和算法和数据结构相关工作，有必要精细研究每一种数据结构知识，否则没有必要花太多时间研究这些东西。
 *		我们直接使用既可以。当需要的时候直接学习。比如树中的红黑树，平衡等需要耗费大量时间，我们不需要去研究。
 *
 *	推荐书籍：《算法导论》，工作中不需要就不要啃这种书
 *
 *		
 * (4)STL标准模板库 发展史和各个版本
 *	1998年，STL被融入到C++标准中来
 *		很多厂商去实现很多stl版本：
 *			1.HP（惠普） stl，是所有实现坂本的始祖
 *			2.SGI stl：参考惠普stl实现的，linux下的GUN（gcc,g++）用的就是这个版本
 *			3.P.J.Plauger STL:也是惠普STL实现的	VC++
 *
 * 
 * (5)标准库的使用说明
 *	所有里面用的东西，都在std里面。所以源码文件开头使用using namespace std;
 *	标准库中和stl的相关头文件有几十到上百个，使用的时候需要包含相关的头文件。
 *	
 * (6)STL的组成部分
 *		1.容器：vector list map
 *		2.迭代器：用于遍历或者访问容器中的元素
 *		3.算法，，诗选一些功能，查找search ,排序sort，
 *		4.分配器--一般不使用，进行内存分配，一般不需要明确指定，使用默认分配即可。
 *		5.其他：如适配器，仿函数(函数对象等)
 * ()()()()()()()
 */