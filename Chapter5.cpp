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
        cout << "�ұ�������" << endl;
    }
    P(const P& p) {
        cout << "����������" << endl;
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
    ////��ȡ���Բ���ִ�е��߳�����
    //cout << thread::hardware_concurrency() << endl;
    //P p;
    //thread t(abc, p); //�߳������������Ҫʹ��ref������Ĭ�Ͽ���
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

    ////�߳�����
//std::vector<std::thread> threads;
//for (unsigned i = 0; i < 20; ++i)
//{
//    threads.emplace_back(do_work, i); // �����߳�
//    
//}
//for (auto& entry : threads) // ��ÿ���̵߳��� join()
//    entry.join();
//lock(m1, m2)��������������ͬʱ�Ӷ���������һ��û���Ͼͽ����������ͷ��Ѿ��ӵ���
//lock_guard�������������ͷţ���Ҫ����Ϊlock�Ѿ���������
//lock_guard(m1, adopt_lock)
//lock_guard(m2, adopt_lock)

    //��������ִ������ʹ��scoped_lock(m1, m2)ֱ���滻 C++17����
    //unique_lock��ԭ��mutex����Ҫ�����RAII������Ȩ��ת��
    //unique_lock�ĳ�����Ϊ ������������ݽ��д�����ռ�¼�̫�õ�����
    //mutex the_mutex;
    //unique_lock<mutex> my_lock(the_mutex);  //�Զ��������mutex�Ѿ����� Ҫʹ��adopt_lock;
    //T data_to_process = get_next_data_chunk();
    //my_lock.unlock();  // 1 ��Ҫ����ס�Ļ�����Խ��process()�����ĵ���
    //result_type result = process(data_to_process);
    //my_lock.lock(); // 2 Ϊ��д�����ݣ��Ի������ٴ�����
    //write_result(data_to_process, result);


    //call_once��once_flag���Ա�֤���̶߳Ա����ĳ�ʼ������ ��ʵcall_flag�ı���Ҳ��һ��mutex
    //�������ܶ��߳̿ɶ��ܻ�ʹ��foo����
    //std::shared_ptr<some_resource> resource_ptr;
    //std::once_flag resource_flag;  // 1
    //void init_resource() {
    //    resource_ptr.reset(new some_resource);
    //}
    //void foo(){
    //    std::call_once(resource_flag, init_resource);  // ���������Ľ���һ�γ�ʼ��
    //    resource_ptr->do_something();
    //}

    //shared_mutex������� ����д������
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
//scope_lock��lock | lock_guard��RAII���� ������������в��ܼ���������
//shared_lock ������/��д����
// #include<shared_mutex>
// unique_lock��Ҫ�Ǻ�condition_variable������ϵ�
// һ���̲߳�������һ�����Ѿ������Ļ����������򽫵���������

    // �첽��Ӧ
    //#include<condition_variable>
    //condition_variable con_var;
    //con_var.wait(mutex, pred) pred���Ѻ���м��
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
        { //���ԭ�򣺴�����ֻ���д������������
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
    

    //��ȡ�첽����ķ���ֵ
    
    
    return 0;
}