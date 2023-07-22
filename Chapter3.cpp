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
	//// unique_ptr uptr2 = uptr; 不被允许
	//unique_ptr uptr2 = move(uptr);
	//cout << uptr << endl;  //资源已近转move转手
	//cout << uptr2 << endl;
	//3.
	//weak_ptr wptr = make_shared<int>();
	//{
	//	shared_ptr uptr = make_shared<int>(10);
	//	wptr = uptr;
	//	cout << wptr.use_count() << endl; // 1
	//	cout << wptr.expired() << endl; //0，维护的数据还没有被释放
	//	if (!wptr.expired()) {
	//		 shared_ptr t = wptr.lock();
	//		//(*wptr.lock()) = 20;
	//		 (*t) = 20;
	//		 cout << uptr.use_count() << endl; // 2
	//		 t = nullptr; //鉴于内部实现 nullptr 和 reset 是绝对等价的
	//		 cout << uptr.use_count() << endl;// 1
	//	}
	//	cout << (*uptr) << endl; //20，lock获取weak_ptr所对应的shared_ptr
	//}
	//cout << wptr.use_count() << endl; // 0
	//cout << wptr.expired() << endl; // 1，维护的数据被释放了
	//shared_ptr<int> sp1(new int(10));
	//// 一个典型的错误用法 
	//shared_ptr<int> sp4(sp1.get());
	//cout << sp4.use_count() << endl;
	//// 因为这样会导致新的引用计数为1，如果释放的会导致原有的sp1错误，并且会释放两次
	return 0;
}
