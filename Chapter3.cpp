#include<tuple>
#include<iostream>
#include<array>
#include<memory>
#include<vector>
using namespace std;
int main3() {
	/*
	* 1.shared_ptr
	* 2.unique_ptr
	* 3.weak_ptr
	*/
	//1.
	/*constexpr int len = 4;
	shared_ptr sptr = make_shared<array<int, len>>(array<int, len>{1, 2, 3, 4});
	{
		array<int, len>* p = sptr.get();
		cout << sptr.use_count() << endl;
		shared_ptr sptr2 = sptr;
		(*sptr2)[0] = 100;
		cout << sptr.use_count() << endl;
		sptr2.reset();
		cout << sptr.use_count() << endl;
		cout << sptr2.use_count() << endl;
	}
	cout << sptr.use_count() << endl;
	cout << (*sptr)[0] << endl;*/
	//2.
	//unique_ptr uptr = make_unique<vector<int>>();
	//uptr->emplace_back(1);
	//cout << uptr << endl;
	//// unique_ptr uptr2 = uptr; ��������
	//unique_ptr uptr2 = move(uptr);
	//cout << uptr << endl;  //��Դ�ѽ�תmoveת��
	//cout << uptr2 << endl;
	//3.
	//weak_ptr wptr = make_shared<int>();
	//{
	//	shared_ptr uptr = make_shared<int>(10);
	//	wptr = uptr;
	//	cout << wptr.use_count() << endl; // 1
	//	cout << wptr.expired() << endl; //0��ά�������ݻ�û�б��ͷ�
	//	if (!wptr.expired()) {
	//		 shared_ptr t = wptr.lock();
	//		//(*wptr.lock()) = 20;
	//		 (*t) = 20;
	//		 cout << uptr.use_count() << endl; // 2
	//		 t = nullptr; //�����ڲ�ʵ�� nullptr �� reset �Ǿ��Եȼ۵�
	//		 cout << uptr.use_count() << endl;// 1
	//	}
	//	cout << (*uptr) << endl; //20��lock��ȡweak_ptr����Ӧ��shared_ptr
	//}
	//cout << wptr.use_count() << endl; // 0
	//cout << wptr.expired() << endl; // 1��ά�������ݱ��ͷ���
	//shared_ptr<int> sp1(new int(10));
	//// һ�����͵Ĵ����÷� 
	//shared_ptr<int> sp4(sp1.get());
	//cout << sp4.use_count() << endl;
	//// ��Ϊ�����ᵼ���µ����ü���Ϊ1������ͷŵĻᵼ��ԭ�е�sp1���󣬲��һ��ͷ�����
	return 0;
}
