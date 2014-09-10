#include <iostream>
#include <memory>

using namespace std;
int main()
{
	unique_ptr<double> up1;							// up1 必须初始化才能使用
	unique_ptr<double> up2(new double(1.2));

	shared_ptr<double> sp1;
	shared_ptr<double> sp2(new double(1.2));		// unique_ptr 必须采取直接初始化的形式

	//cout << "up1:" << *up1 << endl;				// up1 必须初始化才能使用
	cout << "up2:" << *up2 << endl;
	
	//cout << "sp1:" << *sp1 << endl;				// sp1 必须初始化才能使用
	cout << "sp2:" << *sp2 << endl;

	double a = 12;
	double b = 22;

	double *ptra = new double(12);
	double *ptrb = new double(22);

	//up1 = new double(a);				// unique_ptr 不能赋值操作
	sp1 = make_shared<double>(1);		// 

	//up2 = up1;						// unique_ptr 不能普通的拷贝
	sp2 = sp1;

	up1.reset(ptra);
	up2.reset(ptrb);

	cout << "up1:" << *up1 << endl;
	cout << "up2:" << *up2 << endl;

	cout << "sp1:" << *sp1 << endl;				
	cout << "sp2:" << *sp2 << endl;

	unique_ptr<double> up3(up1.release());		// 将up1的所有权转让给up3了，并将up1置为空了
	unique_ptr<double> up4(new double(9));
	up3.reset(up4.release());					// 将up4的所有权转让给up3了，并将up3之前指向的内存释放了

}