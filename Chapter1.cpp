// 语言可用性的强化
#include<iostream>
#include<vector>
#include<tuple>
#include<map>
#define A 5
#define B 6
using namespace std;
constexpr int add(int a, int b) {
	return 5;
}
tuple<int, double, string> f() {
	return make_tuple(1, 2.3, "我是str");
}
class Person {
public:
	int p;
	Person(int _p){
		p = _p;
	}
};
void printf2() {} //一般要搭配一个没有参数的同名函数
template<typename T0, typename... T>
void printf2(T0 t0, T... t) {
	//一般来讲含有可变参数的模板往往是类内函数
	cout << t0.p << endl;
	if (sizeof...(t) > 0) {
		//(args...)可以理解为没有参数
		//在执行期间会转到printf2(T0 t0, T... t)进行执行
		printf2(t...);
	}
}
template <auto _Type, typename T> 
T foo(const T& value) {
	if (_Type == 1) return value;
	else return value * 2;
}

class Base {
public:
	int value, value2;
	Base() : value(1), value2(value + 1) {};
	Base(int v) : Base() {
		value += v;
		value2 += v;
	}
};
class ABase {
public:
	int num = 0;
	// virtual int getNum() = 0;  //纯虚函数可以使得继承该类的子类强制实现该函数，否则无法得到实例化
	//虚函数是用来是实现多态的
	virtual void setNum(int _num) {
		num = _num;
	}
	virtual int getNum() {
		return num;
	}
};
class BBase: public ABase {
public:
	void setNum(int _num) {
		num = _num * 5;
	}
};
class CBase : public ABase {
public:
	void setNum(int _num) {
		num = _num * 10;
	}
};
int setAndGet(ABase* abase, int v) {
	abase->setNum(v);
	return abase->getNum();
}
enum class names : unsigned int {
	AA_000,
	BB_001 = 100,
	CC_002 = 100,
	DD_003
};
enum class types: unsigned int {
	TYPE_DOWN = 100

};
int main1() {
	/*
	* 1. 使用nullptr来代替NULL
	* 2. 使用static_cast<type>来替代(type)进行类型转换
	* 3. 善用常量表达式constexpr，constexpr函数对变量进行绑定时变量的申明也需要constexpr
	* 4. if switch 可以像for一样使用一个或多个临时变量了(C++17)
	* 5. 结构化绑定来解决多类型值存储问题(C++17)
	* 6. 类型判断is_same 和 decltype
	* 7. 区间for循环
	* 8. 可变参数数量的模板函数，以及变参模板展开
	* 9. 委托构造函数可以在同一个类中一个构造函数调用另一个构造函数，从而达到简化代码的目的
	* 10.多态（这里存粹是为了回顾一下（纯）虚函数以及多态的触发条件）
	* 11.强类型枚举
	*/
	//3.
	// constexpr int len = add(A, B);
	//int arr[len];
	//4.
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
	////::value取出bool值
	////或者直接使用is_same_v<T, U>就不用使用::value了
	//if (a == b) cout << "a 与 b 数值相同" << endl;
	//if (is_same<decltype(a), decltype(b)>::value) cout << "a 与 b 类型相同" << endl; 
	//else cout << "a 与 b 类型不相同" << endl;
	//9.
	//Person p1(1), p2(2), p3(3);
	//printf2(p1, p2, p3);
	//cout << foo<1, float>(3) << endl;
	//Base base(4);
	//cout << base.value << '\t' << endl
	//	<< base.value2 << endl;
	////stdout:
	////5
	////6
	//Subclass sc(3);
	//cout << sc.value << endl;
	// 10.
	//ABase* bbase = new BBase();
	//ABase *cbase = new CBase();
	//cout << setAndGet(bbase, 10) << endl;
	//cout << setAndGet(cbase, 10) << endl;
	////stdout:
	////50
	////100
	//11.
	//unsigned int b = static_cast<unsigned int>(names::BB_001);
	//unsigned int c = static_cast<unsigned int>(names::CC_002);
	//unsigned int d = static_cast<unsigned int>(names::DD_003);
	//// if (names::BB_001 == types::TYPE_DOWN)  //编译不通过，不同的枚举空间不能进行比较
	// if (names::BB_001 == names::CC_002)
	//	cout << "相同" << endl;
	//cout << b << endl
	//	<< c << endl
	//	<< d << endl;
	////stdout:
	////相同
	////100
	////100
	////101
	return 0;
}