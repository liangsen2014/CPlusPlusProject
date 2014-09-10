#include <iostream>
#include <memory>

using namespace std;
int main()
{
	unique_ptr<double> up1;							// up1 �����ʼ������ʹ��
	unique_ptr<double> up2(new double(1.2));

	shared_ptr<double> sp1;
	shared_ptr<double> sp2(new double(1.2));		// unique_ptr �����ȡֱ�ӳ�ʼ������ʽ

	//cout << "up1:" << *up1 << endl;				// up1 �����ʼ������ʹ��
	cout << "up2:" << *up2 << endl;
	
	//cout << "sp1:" << *sp1 << endl;				// sp1 �����ʼ������ʹ��
	cout << "sp2:" << *sp2 << endl;

	double a = 12;
	double b = 22;

	double *ptra = new double(12);
	double *ptrb = new double(22);

	//up1 = new double(a);				// unique_ptr ���ܸ�ֵ����
	sp1 = make_shared<double>(1);		// 

	//up2 = up1;						// unique_ptr ������ͨ�Ŀ���
	sp2 = sp1;

	up1.reset(ptra);
	up2.reset(ptrb);

	cout << "up1:" << *up1 << endl;
	cout << "up2:" << *up2 << endl;

	cout << "sp1:" << *sp1 << endl;				
	cout << "sp2:" << *sp2 << endl;

	unique_ptr<double> up3(up1.release());		// ��up1������Ȩת�ø�up3�ˣ�����up1��Ϊ����
	unique_ptr<double> up4(new double(9));
	up3.reset(up4.release());					// ��up4������Ȩת�ø�up3�ˣ�����up3֮ǰָ����ڴ��ͷ���

}