// 语言可用性的强化
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
	return make_tuple(1, 2.3, "我是str");
}
int main() {
	/*
	* 1. 使用nullptr来代替NULL
	* 2. 使用static_cast<type>来替代(type)进行类型转换
	* 3. 善用常量表达式constexpr，constexpr函数对变量进行绑定时变量的申明也需要constexpr
	* 4. if switch 可以像for一样使用一个或多个临时变量了(C++17)
	* 5. 结构化绑定来解决多类型值存储问题(C++17)
	* 6. 
	*/
	//constexpr int len = add(A, B);
	//int arr[len];
	// 
	//int c = 1;
	//if (int a = 1, b = 2; a + b + c == 4) {
	//	cout << "if里面使用了临时变量" << endl;
	//}
	//switch (int a = 1, b = 2; a + b + c)
	//{
	//case 3:
	//	break;
	//case 4: {
	//	cout << "switch里面使用了临时变量" << endl;
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
	//if (a == b) cout << "a 与 b 数值相同" << endl;
	//if (is_same<decltype(a), decltype(b)>::value) cout << "a 与 b 类型相同" << endl; //::value取出bool值
	//else cout << "a 与 b 类型不相同" << endl;

	return 0;
}