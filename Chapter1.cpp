// ���Կ����Ե�ǿ��
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
	* 1. ʹ��nullptr������NULL
	* 2. ʹ��static_cast<type>�����(type)��������ת��
	* 3. ���ó������ʽconstexpr��constexpr�����Ա������а�ʱ����������Ҳ��Ҫconstexpr
	* 4. if switch ������forһ��ʹ��һ��������ʱ������(C++17)
	* 5. �ṹ���������������ֵ�洢����(C++17)
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

	return 0;
}