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
template<typename T0, typename... T>
void printf2(T0 t0, T... t) {
	std::cout << t0 << std::endl;
	if constexpr (sizeof...(t) > 0) printf2(t...);
}
int main() {
	/*
	* 1. ʹ��nullptr������NULL
	* 2. ʹ��static_cast<type>�����(type)��������ת��
	* 3. ���ó������ʽconstexpr��constexpr�����Ա������а�ʱ����������Ҳ��Ҫconstexpr
	* 4. if switch ������forһ��ʹ��һ��������ʱ������(C++17)
	* 5. �ṹ���������������ֵ�洢����(C++17)
	* 6. �����ж�is_same �� decltype
	* 7. ����forѭ��
	* 8. �ɱ����������ģ�庯�����Լ����ģ��չ��
	*/
	//3.
	// constexpr int len = add(A, B);
	//int arr[len];
	//4.
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
	// 5.
	//auto [a, b, c] = f();
	//decltype(a) bb = 1.2;
	//cout << bb << endl; // bb == 1
	//cout << a << endl;
	//cout << b << endl;
	//cout << c << endl;
	// 6.
	//int a = 1;
	//double b = 1;
	////::valueȡ��boolֵ
	////����ֱ��ʹ��is_same_v<T, U>�Ͳ���ʹ��::value��
	//if (a == b) cout << "a �� b ��ֵ��ͬ" << endl;
	//if (is_same<decltype(a), decltype(b)>::value) cout << "a �� b ������ͬ" << endl; 
	//else cout << "a �� b ���Ͳ���ͬ" << endl;
	//8.
	printfT(1, 2, 3, 4);
	return 0;
}