#include<iostream>
#include<thread>
using namespace std;
int main() {
	thread t([](int a) {
		cout << a << endl;
		cout << "A: ���ѽ" << endl;
		}, 1);
	cout << t.get_id() << endl;
	t.join();
	return 0;
}