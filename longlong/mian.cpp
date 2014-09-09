#include <iostream>
#include <string>

using namespace std;

int global_int;
string global_str;

int main()
{
	cout << "sizeof(unsigned)" << sizeof(unsigned) << endl;
	cout << "sizeof(unsigned long)" << sizeof(unsigned long) << endl;
	cout << "sizeof(unsigned long long)" << sizeof(unsigned long long) << endl;

	cout << "sizeof(char)" << sizeof(char)<< endl;
	cout << "sizeof(wchar_t)" << sizeof(wchar_t) << endl;

	cout << "who goes with F\145rgus?\012" << endl;

	double price = 0.99, discount = price*0.16;

	cout << price << "\t" << discount << endl;

	// list initialization
	long double ld = 3.1415926;
	// int a{ ld },  b = { ld };						
	int c(ld), d = ld;

	//default initialization
	int local_int;
	string local_str;

	cout << global_int << "\t" << global_str << endl;
	//cout << local_int << "\t" << local_str << endl;		// uninitialization error

	return 0;
}