#include<iostream>
#include<thread>
#include<memory>
#include<mutex>
#include<set>
#include<vector>
#include<exception>
using namespace std;
class P {
public:
    int i = 0;
    P() {
        cout << "我被创建了" << endl;
    }
    P(const P& p) {
        cout << "拷贝创建了" << endl;
    }
};
void abc(const P &p) {
    
}
void dof() {

}
void def(unique_ptr<int> &up) {
    (*up)++;
}
void f(thread t) {
    cout << t.get_id() << endl;
    t.join();
}
void do_work(unsigned id) {

}
int main() {
    cout << this_thread::get_id() << endl;
    //获取可以并行执行的线程数量
    cout << thread::hardware_concurrency() << endl;
    P p;
    thread t(abc, p); //线程里面出入引用要使用ref，否则默认拷贝
    t.join();
    cout << p.i << endl;

    unique_ptr<int> up(new int(20));
    thread t2(def, ref(up));
    t2.join();
    cout << *up << endl;
    thread t3(dof);
    cout << t3.get_id() << endl;
    f(move(t3));
    if (t3.joinable()) t3.join();
    

    //线程量产
    std::vector<std::thread> threads;
    for (unsigned i = 0; i < 20; ++i)
    {
        threads.emplace_back(do_work, i); // 产生线程
        
    }
    for (auto& entry : threads) // 对每个线程调用 join()
        entry.join();


    return 0;
}