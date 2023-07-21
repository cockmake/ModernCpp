// 语言可用性的强化
#include<iostream>
#include<vector>
#define A 5
#define B 6
using namespace std;
constexpr int add(int a, int b) {
	return 5;
}
int main() {
	/*
	* 1. 使用nullptr来代替NULL
	* 2. 使用static_cast<type>来替代(type)进行类型转换
	* 3. 善用常量表达式constexpr，constexpr函数对变量进行绑定时变量的申明也需要constexpr
	* 4. if switch 可以像for一样使用一个或多个临时变量了(C++17)
	* 5. 结构化绑定来解决多类型值存储问题(C++17)
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

	return 0;
}