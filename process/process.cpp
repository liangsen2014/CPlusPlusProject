#include <iostream>
#include <memory>

#define TEST1 0
#define TEST2 1
using namespace std;

void process(shared_ptr<int> ptr)
{
	cout << "shared_ptr<int> ptr = " << *ptr << endl;

}

int main()
{
#if TEST1	// 错误的例子
	int *x(new int(1024));
	//process(x);					// 错误：不能将int*转换成一个shared_ptr<int>
	cout << "*x = " << *x << endl;
	process(shared_ptr<int>(x));	// 将x传递给智能指针会构造成一个智能指针，这样函数返回时智能指针会将X内存释放，之后再使用X便会出现错误
	cout << "*x = " << *x << endl;	// 未定义：X是一个空悬指针，X的内存空间被之前的临时智能指针给释放了
#endif

#if TEST2	// 正确的例子
	shared_ptr<int> p(new int(42));	// 引用计数为1
	process(p);						// 拷贝p给参数ptr，会递增它的引用计数，引用计数为2
	int i = *p;						// 正确:引用计数为1
	
#endif
}