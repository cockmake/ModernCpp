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
		cout << "a����Դ��ַ" << endl;
		cout << "����p��ַ��" << &a.p << endl;
		cout << "vector��ַ��" << &a.arr.back() << endl;
		p = a.p;
		arr = a.arr;
		cout << "�����˿�������" << endl;
		cout << "����p��ַ��" << &p << endl;
		cout << "vector��ַ��"<< &arr.back() << endl;
	}
	A (A&& a) noexcept {
		cout << "a����Դ��ַ" << endl;
		cout << "����p��ַ��" << &a.p << endl;
		cout << "vector��ַ��" << &a.arr.back() << endl;
		p = move(a.p);
		arr = move(a.arr);
		cout << "�������ƶ�����" << endl;
		cout << "����p��ַ��" << &p << endl;
		cout << "vector��ַ��" << &arr.back() << endl;
		//cout << "vector��ַ��" << &a.arr.back() << endl; //�Ƿ���a.arr����Դ���ƶ�������˳�ʼ״̬
	}
	~A() {
		cout << "A��ɾ����" << endl;
	}
};
A getA() {
	A a;
	a.p = 1;
	a.arr = vector<int>({ 1, 2, 3 });
	return a;
}
void reference(std::string& str) {
	std::cout << "��ֵ" << std::endl;
}
void reference(std::string&& str) {
	std::cout << "��ֵ" << std::endl;
}
string ccc;
const char* p;
void fff() {
	string b = "123";
	p = b.c_str();
	ccc = move(b);  //�����b��Դ�Ѿ���������
	cout << p << endl; //�����b��Դ�Ѿ��ص��˳�ʼ��״̬
	//����ִ�������ʵb���������٣�������Դ�Ѿ��ƶ�����b��
}
int main2() {
	fff();
	cout << p << endl; //��������b��Դ�Ѿ�������������������
	cout << ccc << endl; //��������ccc�Ĵ�ӡ����123 �������b��Դ
	/*
	* 1. ���� Lambda��lambda����֧��auto�β�
	* 2. std::bind �� std::placeholder �����������ռλ
	* 3. ��ֵ���ã���Ҫ����
	* 4. ��������ת��
	* 5. �ƶ����캯������Դ�ƶ��������п������٣� move��������ֵ
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
	//cout << "ȷ��һ�£�" << endl;
	//cout << "����p��ַ��" << &a.p << endl;
	//cout << "vector��ַ��" << &a.arr.back() << endl;
	////string������operator+���ص���һ��Ҫ���������ٵĶ����޷���ֵ���������ã������������������������ڵķ�����
	////����1��
	//std::string lv1 = "string,"; // lv1 ��һ����ֵ
	//const string& lv2 = lv1 + lv1; // �Ϸ�, ������ֵ�����ܹ��ӳ���ʱ��������������
	////ll += "Test"; // �Ƿ�, ���������޷����޸�
	////cout << lv2 << endl; // string,string
	////����2��
	////string&& rv2 = lv1 + lv2; // �Ϸ�, ��ֵ�����ӳ���ʱ������������
	////rv2 += "Test"; // �Ϸ�, �ǳ��������ܹ��޸���ʱ����
	////cout << rv2 << endl; // string,string,string,Test
	////reference(rv2); // �����ֵ
	//std::string lv1 = "string,"; // lv1 ��һ����ֵ
	//const string& lv2 = lv1 + lv1; // �Ϸ�, ������ֵ�����ܹ��ӳ���ʱ��������������
	//string& ll = const_cast<string&>(lv2);
	//cout << lv2 << endl;
	//ll += "Test"; // �Ϸ�, �����˳�������ת��
	//cout << lv2 << endl;
	//class Base { virtual void dummy() {} };
	//class Derived : public Base { int a = 1; };
	//Base* base = new Base;
	//Derived* son = new Derived;
	//Derived* derived = dynamic_cast<Derived*>(base);  // �⽫ʧ�ܣ����� nullptr
	//Base* fa = dynamic_cast<Base*>(son);  // �ɹ�����������ת�����ӵ�����
	//cout << derived << endl;
	//cout << fa << endl;
	//if (derived == nullptr)  cout << "����ת��ʧ��" << endl;
	//if (fa != nullptr)  cout << "����ת���ɹ�" << endl;
	//int a = 10;
	//int* p = &a;
	//char* c = reinterpret_cast<char*>(p);  // �� int* ת��Ϊ char*

	return 0;
}