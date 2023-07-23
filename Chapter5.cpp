#include<iostream>
#include<thread>
#include<memory>
#include<mutex>
#include<set>
#include<vector>
#include<stack>
#include<exception>
#include <shared_mutex>
#include<condition_variable>
#include<future>
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
    //cout << this_thread::get_id() << endl;
    ////获取可以并行执行的线程数量
    //cout << thread::hardware_concurrency() << endl;
    //P p;
    //thread t(abc, p); //线程里面出入引用要使用ref，否则默认拷贝
    //t.join();
    //cout << p.i << endl;

    //unique_ptr<int> up(new int(20));
    //thread t2(def, ref(up));
    //t2.join();
    //cout << *up << endl;
    //thread t3(dof);
    //cout << t3.get_id() << endl;
    //f(move(t3));
    //if (t3.joinable()) t3.join();
    //

    ////线程量产
//std::vector<std::thread> threads;
//for (unsigned i = 0; i < 20; ++i)
//{
//    threads.emplace_back(do_work, i); // 产生线程
//    
//}
//for (auto& entry : threads) // 对每个线程调用 join()
//    entry.join();
//lock(m1, m2)用来加锁，可以同时加多个锁，如果一个没加上就进入阻塞并释放已经加的锁
//lock_guard用来监视锁的释放，主要是因为lock已经上锁过了
//lock_guard(m1, adopt_lock)
//lock_guard(m2, adopt_lock)

    //上面的两种搭配可以使用scoped_lock(m1, m2)直接替换 C++17引入
    //unique_lock和原生mutex的主要区别的RAII和所有权可转移
    //unique_lock的出现是为 解决读出的数据进行处理所占事件太久的问题
    //mutex the_mutex;
    //unique_lock<mutex> my_lock(the_mutex);  //自动上锁如果mutex已经上锁 要使用adopt_lock;
    //T data_to_process = get_next_data_chunk();
    //my_lock.unlock();  // 1 不要让锁住的互斥量越过process()函数的调用
    //result_type result = process(data_to_process);
    //my_lock.lock(); // 2 为了写入数据，对互斥量再次上锁
    //write_result(data_to_process, result);


    //call_once和once_flag可以保证多线程对变量的初始化问题 其实call_flag的本质也是一个mutex
    //这里假设很多线程可都能会使用foo函数
    //std::shared_ptr<some_resource> resource_ptr;
    //std::once_flag resource_flag;  // 1
    //void init_resource() {
    //    resource_ptr.reset(new some_resource);
    //}
    //void foo(){
    //    std::call_once(resource_flag, init_resource);  // 可以完整的进行一次初始化
    //    resource_ptr->do_something();
    //}

    //shared_mutex解决的是 读者写者问题
    //class dns_entry;
    //class dns_cache
    //{
    //    std::map<std::string, dns_entry> entries;
    //    mutable std::shared_mutex entry_mutex;
    //public:
    //    dns_entry find_entry(std::string const& domain) const
    //    {
    //        std::shared_lock<std::shared_mutex> lk(entry_mutex);  // 1
    //        std::map<std::string, dns_entry>::const_iterator const it =
    //            entries.find(domain);
    //        return (it == entries.end()) ? dns_entry() : it->second;
    //    }
    //    void update_or_add_entry(std::string const& domain,
    //        dns_entry const& dns_details)
    //    {
    //        std::lock_guard<std::shared_mutex> lk(entry_mutex);  // 2
    //        entries[domain] = dns_details;
    //    }
    //};
//scope_lock（lock | lock_guard（RAII）） 解决多条件持有才能继续的问题
//shared_lock 解决多读/单写问题
// #include<shared_mutex>
// unique_lock主要是和condition_variable进行配合的
// 一个线程不能锁定一个它已经锁定的互斥量，否则将导致死锁。

    // 异步响应
    //#include<condition_variable>
    //condition_variable con_var;
    //con_var.wait(mutex, pred) pred唤醒后进行检查
    /*
        std::mutex mut;
        std::queue<data_chunk> data_queue;  // 1
        std::condition_variable data_cond;
        void data_preparation_thread()
        {
          while(more_data_to_prepare())
          {
            data_chunk const data=prepare_data();
            std::lock_guard<std::mutex> lk(mut);
            data_queue.push(data);  // 2
            data_cond.notify_one();  // 3
          }
        }
        void data_processing_thread()
        { //设计原则：处理函数只进行处理，否则就阻塞
          while(true)
          {
            std::unique_lock<std::mutex> lk(mut);  // 4
            data_cond.wait(
                 lk,[]{return !data_queue.empty();});  // 5
            data_chunk data=data_queue.front();
            data_queue.pop();
            lk.unlock();  // 6
            process(data);
            if(is_last_chunk(data))
              break;
          }
        }
    */
    

    //获取异步任务的返回值
    
    
    return 0;
}