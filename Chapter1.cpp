// ���Կ����Ե�ǿ��
#include<iostream>
#include<vector>
#include<tuple>
#define A 5
#define B 6
using namespace std;
constexpr int add(int a, int b) {
	return 5;
}
tuple<int, double, string> f() {
	return make_tuple(1, 2.3, "����str");
}
int main() {
	/*
	* 1. ʹ��nullptr������NULL
	* 2. ʹ��static_cast<type>�����(type)��������ת��
	* 3. ���ó������ʽconstexpr��constexpr�����Ա������а�ʱ����������Ҳ��Ҫconstexpr
	* 4. if switch ������forһ��ʹ��һ��������ʱ������(C++17)
	* 5. �ṹ���������������ֵ�洢����(C++17)
	* 6. 
	*/
	//constexpr int len = add(A, B);
	//int arr[len];
	// 
	//int c = 1;
	//if (int a = 1, b = 2; a + b + c == 4) {
	//	cout << "if����ʹ������ʱ����" << endl;
	//}
	//switch (int a = 1, b = 2; a + b + c)
	//{
	//case 3:
	//	break;
	//case 4: {
	//	cout << "switch����ʹ������ʱ����" << endl;
	//	break;
	//}
	//default:
	//	break;
	//}
	//auto [a, b, c] = f();
	//decltype(a) bb = 1.2;
	//cout << bb << endl; // bb == 1
	//cout << a << endl;
	//cout << b << endl;
	//cout << c << endl;
	//int a = 1;
	//double b = 1;
	//if (a == b) cout << "a �� b ��ֵ��ͬ" << endl;
	//if (is_same<decltype(a), decltype(b)>::value) cout << "a �� b ������ͬ" << endl; //::valueȡ��boolֵ
	//else cout << "a �� b ���Ͳ���ͬ" << endl;

	return 0;
}