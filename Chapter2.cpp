#include<iostream>
#include<functional>
using namespace std;
int getArgs(int a, int b, int c) {
	cout << a << '\t' << b << '\t' << c << endl;
	return 0;
}
class Person {
public:
	int p, v;
	Person(int _v, int _p) : p(_p), v(_v) {};
};
int main() {
	/*
	* 1. 泛型 Lambda即lambda函数支持auto形参
	* 2. std::bind 和 std::placeholder 函数绑定与参数占位
	* 3. 
	*/
	////1.
	//auto add = [](auto x, auto y) {
	//	return x + y;
	//};
	//auto a = add(1, 2.1);
	//cout << a << endl;
	////2.
	//auto execFunc = bind(getArgs, placeholders::_2, placeholders::_1, 100);
	//execFunc(1, 3);

	return 0;
}