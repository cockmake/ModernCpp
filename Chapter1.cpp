// ���Կ����Ե�ǿ��
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
	return make_tuple(1, 2.3, "����str");
}
class Person {
public:
	int p;
	Person(int _p){
		p = _p;
	}
};
void printf2() {} //һ��Ҫ����һ��û�в�����ͬ������
template<typename T0, typename... T>
void printf2(T0 t0, T... t) {
	//һ���������пɱ������ģ�����������ں���
	cout << t0.p << endl;
	if (sizeof...(t) > 0) {
		//(args...)�������Ϊû�в���
		//��ִ���ڼ��ת��printf2(T0 t0, T... t)����ִ��
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
	// virtual int getNum() = 0;  //���麯������ʹ�ü̳и��������ǿ��ʵ�ָú����������޷��õ�ʵ����
	//�麯����������ʵ�ֶ�̬��
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
	* 1. ʹ��nullptr������NULL
	* 2. ʹ��static_cast<type>�����(type)��������ת��
	* 3. ���ó������ʽconstexpr��constexpr�����Ա������а�ʱ����������Ҳ��Ҫconstexpr
	* 4. if switch ������forһ��ʹ��һ��������ʱ������(C++17)
	* 5. �ṹ���������������ֵ�洢����(C++17)
	* 6. �����ж�is_same �� decltype
	* 7. ����forѭ��
	* 8. �ɱ����������ģ�庯�����Լ����ģ��չ��
	* 9. ί�й��캯��������ͬһ������һ�����캯��������һ�����캯�����Ӷ��ﵽ�򻯴����Ŀ��
	* 10.��̬����������Ϊ�˻ع�һ�£������麯���Լ���̬�Ĵ���������
	* 11.ǿ����ö��
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
	//// if (names::BB_001 == types::TYPE_DOWN)  //���벻ͨ������ͬ��ö�ٿռ䲻�ܽ��бȽ�
	// if (names::BB_001 == names::CC_002)
	//	cout << "��ͬ" << endl;
	//cout << b << endl
	//	<< c << endl
	//	<< d << endl;
	////stdout:
	////��ͬ
	////100
	////100
	////101
	return 0;
}