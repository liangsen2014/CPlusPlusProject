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
#if TEST1	// ���������
	int *x(new int(1024));
	//process(x);					// ���󣺲��ܽ�int*ת����һ��shared_ptr<int>
	cout << "*x = " << *x << endl;
	process(shared_ptr<int>(x));	// ��x���ݸ�����ָ��ṹ���һ������ָ�룬������������ʱ����ָ��ὫX�ڴ��ͷţ�֮����ʹ��X�����ִ���
	cout << "*x = " << *x << endl;	// δ���壺X��һ������ָ�룬X���ڴ�ռ䱻֮ǰ����ʱ����ָ����ͷ���
#endif

#if TEST2	// ��ȷ������
	shared_ptr<int> p(new int(42));	// ���ü���Ϊ1
	process(p);						// ����p������ptr��������������ü��������ü���Ϊ2
	int i = *p;						// ��ȷ:���ü���Ϊ1
	
#endif
}