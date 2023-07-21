#include<iostream>
#include<functional>
#include<cstdio>
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
class A {
public:
	int p;
	vector<int> arr;
	A() {};
	A (const A& a){
		cout << "a的资源地址" << endl;
		cout << "常量p地址：" << &a.p << endl;
		cout << "vector地址：" << &a.arr.back() << endl;
		p = a.p;
		arr = a.arr;
		cout << "发生了拷贝构造" << endl;
		cout << "常量p地址：" << &p << endl;
		cout << "vector地址："<< &arr.back() << endl;
	}
	A (A&& a) noexcept {
		cout << "a的资源地址" << endl;
		cout << "常量p地址：" << &a.p << endl;
		cout << "vector地址：" << &a.arr.back() << endl;
		p = move(a.p);
		arr = move(a.arr);
		cout << "发生了移动构造" << endl;
		cout << "常量p地址：" << &p << endl;
		cout << "vector地址：" << &arr.back() << endl;
		//cout << "vector地址：" << &a.arr.back() << endl; //非法，a.arr的资源被移动后进入了初始状态
	}
	~A() {
		cout << "A被删除了" << endl;
	}
};
A getA() {
	A a;
	a.p = 1;
	a.arr = vector<int>({ 1, 2, 3 });
	return a;
}
void reference(std::string& str) {
	std::cout << "左值" << std::endl;
}
void reference(std::string&& str) {
	std::cout << "右值" << std::endl;
}
string ccc;
const char* p;
void fff() {
	string b = "123";
	p = b.c_str();
	ccc = move(b);  //这里的b资源已经被搬走了
	cout << p << endl; //这里的b资源已经回到了初始化状态
	//函数执行完毕其实b发生了销毁，但是资源已经移动到了b上
}
int main2() {
	fff();
	cout << p << endl; //这里由于b资源已经被销毁了所以是乱码
	cout << ccc << endl; //所以这里ccc的打印还是123 即最初的b资源
	/*
	* 1. 泛型 Lambda即lambda函数支持auto形参
	* 2. std::bind 和 std::placeholder 函数绑定与参数占位
	* 3. 右值引用（重要！）
	* 4. 四种类型转换
	* 5. 移动构造函数（资源移动，不进行拷贝销毁） move来构造右值
	* 6. 
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
	//A a = getA();
	//cout << "确认一下：" << endl;
	//cout << "常量p地址：" << &a.p << endl;
	//cout << "vector地址：" << &a.arr.back() << endl;
	////string的重载operator+返回的是一个要即将被销毁的对象无法赋值给常规引用，下面是两种延续其声明周期的方法：
	////方法1：
	//std::string lv1 = "string,"; // lv1 是一个左值
	//const string& lv2 = lv1 + lv1; // 合法, 常量左值引用能够延长临时变量的生命周期
	////ll += "Test"; // 非法, 常量引用无法被修改
	////cout << lv2 << endl; // string,string
	////方法2：
	////string&& rv2 = lv1 + lv2; // 合法, 右值引用延长临时对象生命周期
	////rv2 += "Test"; // 合法, 非常量引用能够修改临时变量
	////cout << rv2 << endl; // string,string,string,Test
	////reference(rv2); // 输出左值
	//std::string lv1 = "string,"; // lv1 是一个左值
	//const string& lv2 = lv1 + lv1; // 合法, 常量左值引用能够延长临时变量的生命周期
	//string& ll = const_cast<string&>(lv2);
	//cout << lv2 << endl;
	//ll += "Test"; // 合法, 经过了常量类型转换
	//cout << lv2 << endl;
	//class Base { virtual void dummy() {} };
	//class Derived : public Base { int a = 1; };
	//Base* base = new Base;
	//Derived* son = new Derived;
	//Derived* derived = dynamic_cast<Derived*>(base);  // 这将失败，返回 nullptr
	//Base* fa = dynamic_cast<Base*>(son);  // 成功，可以像上转换（子到父）
	//cout << derived << endl;
	//cout << fa << endl;
	//if (derived == nullptr)  cout << "向下转换失败" << endl;
	//if (fa != nullptr)  cout << "向上转换成功" << endl;
	//int a = 10;
	//int* p = &a;
	//char* c = reinterpret_cast<char*>(p);  // 将 int* 转换为 char*

	return 0;
}