- [现代C++快速入门 | C++11/14/17/20](#现代c快速入门--c11141720)
  - [Chapter1](#chapter1)
    - [1. 使用nullptr来代替NULL](#1-使用nullptr来代替null)
    - [2. 使用`static_cast<type>(src_data)`来替代`(type)src_data`进行类型转换](#2-使用static_casttypesrc_data来替代typesrc_data进行类型转换)
    - [3. 善用常量表达式constexpr，constexpr函数对变量进行绑定时变量的申明也需要constexpr](#3-善用常量表达式constexprconstexpr函数对变量进行绑定时变量的申明也需要constexpr)
    - [4. if switch 可以像for一样使用一个或多个临时变量了(C++17)](#4-if-switch-可以像for一样使用一个或多个临时变量了c17)
    - [5. 结构化绑定来解决多类型值存储问题(C++17) tuple | make\_tuple](#5-结构化绑定来解决多类型值存储问题c17-tuple--make_tuple)
    - [6. 类型判断is\_same 和 decltype](#6-类型判断is_same-和-decltype)
    - [7. 区间（范围）for循环](#7-区间范围for循环)
    - [8.可变参数数量的模板函数，以及变参模板展开](#8可变参数数量的模板函数以及变参模板展开)
    - [9.委托构造函数可以在同一个类中一个构造函数调用另一个构造函数，从而达到简化代码的目的](#9委托构造函数可以在同一个类中一个构造函数调用另一个构造函数从而达到简化代码的目的)
    - [10. 多态（这里存粹是为了回顾一下（纯）虚函数以及多态的触发条件）](#10-多态这里存粹是为了回顾一下纯虚函数以及多态的触发条件)
    - [11.强枚举类](#11强枚举类)
  - [Chapter2](#chapter2)
    - [1.泛型 Lambda即lambda函数支持auto形参](#1泛型-lambda即lambda函数支持auto形参)
    - [2.std::bind 和 std::placeholder 函数绑定与参数占位](#2stdbind-和-stdplaceholder-函数绑定与参数占位)
    - [3. 右值引用（重要！）](#3-右值引用重要)
    - [4. 四种类型转换](#4-四种类型转换)
    - [5.移动构造函数（资源移动，不进行拷贝销毁） move可以来构造右值](#5移动构造函数资源移动不进行拷贝销毁-move可以来构造右值)
    - [6.再次体验一些右值资源的"迁移"，个人感觉"转手"形容更为贴切](#6再次体验一些右值资源的迁移个人感觉转手形容更为贴切)
  - [Chapter3](#chapter3)
    - [1. 常用容器`vector`，`array`，`（unordered_）map`，`（unordered_）set`， `queue`，`priority_queue`，`deque`，`stack`，`tuple`，`bit_set`](#1-常用容器vectorarrayunordered_mapunordered_set-queuepriority_queuedequestacktuplebit_set)
    - [2.智能指针 `shared_ptr`，`unique_ptr`，`weak_ptr`](#2智能指针-shared_ptrunique_ptrweak_ptr)
      - [1.shared\_ptr](#1shared_ptr)
      - [2. unique\_ptr](#2-unique_ptr)
      - [3.weak\_ptr （主要用来解决交叉引用的问题）](#3weak_ptr-主要用来解决交叉引用的问题)
      - [4.shared\_ptr的交叉引用问题，以及weak\_ptr的解决方案](#4shared_ptr的交叉引用问题以及weak_ptr的解决方案)
      - [5.智能指针使用过程中的一些注意点](#5智能指针使用过程中的一些注意点)
  - [Chapter4 （文件操作）](#chapter4-文件操作)
    - [1.获取路径的绝对路径和相对路径 os::absolute和os::relative](#1获取路径的绝对路径和相对路径-osabsolute和osrelative)
    - [2.查看和切换当前目录，创建一层或多层目录 os::current\_path() 和 os::create\_directories()](#2查看和切换当前目录创建一层或多层目录-oscurrent_path-和-oscreate_directories)
    - [3.文件以及文件夹的删除和拷贝 remove()和copy()](#3文件以及文件夹的删除和拷贝-remove和copy)
    - [4.遍历路径与递归遍历 os::recursive\_directory\_entry 和 directory\_entry](#4遍历路径与递归遍历-osrecursive_directory_entry-和-directory_entry)
    - [5.重命名与移动 os::rename](#5重命名与移动-osrename)
  - [Chapter5 并行与并发](#chapter5-并发与并行)

# 现代C++快速入门 | C++11/14/17/20

## Chapter1

### 1\. 使用nullptr来代替NULL

### 2\. 使用`static_cast<type>(src_data)`来替代`(type)src_data`进行类型转换

### 3\. 善用常量表达式constexpr，constexpr函数对变量进行绑定时变量的申明也需要constexpr

```C++
#define A 5
#define B 6
constexpr int add(int a, int b) {
    return 5;
}
int main(){
    constexpr int len = add(A, B);
    int arr[len];
    return 0;
}
```

### 4\. if switch 可以像for一样使用一个或多个临时变量了(C++17)

```c++
int c = 1;
if (int a = 1, b = 2; a + b + c == 4) {
    cout << "if里面使用了临时变量" << endl;
}

switch (int a = 1, b = 2; a + b + c)
{
case 3:
    break;
case 4: {
    cout << "switch里面使用了临时变量" << endl;
    break;
}
default:
    break;
}
```

### 5\. 结构化绑定来解决多类型值存储问题(C++17) tuple | make_tuple

```C++
#include<tuple>
tuple<int, double, string> f() {
    return make_tuple(1, 2.3, "我是str");
}
auto [a, b, c] = f();
decltype(a) bb = 1.2;  //decltype 可以作为变量声明
cout << bb << endl; // bb == 1
cout << a << endl;
cout << b << endl;
cout << c << endl;
```

### 6\. 类型判断is_same 和 decltype

```C++
int a = 1;
double b = 1;
//::value取出bool值
//或者直接使用is_same_v<T, U>就不用使用::value了
if (a == b) cout << "a 与 b 数值相同" << endl;
if (is_same<decltype(a), decltype(b)>::value) cout << "a 与 b 类型相同" << endl; 
else cout << "a 与 b 类型不相同" << endl;
```

### 7\. 区间（范围）for循环

### 8.可变参数数量的模板函数，以及变参模板展开

```C++
class Person {
public:
    int p;
    Person(int _p) {p = _p;}
};
void printf2() {} //要搭配一个没有参数的同名函数
template<typename T0, typename... T>
void printf2(T0 t0, T... t) {
    //一般来讲含有可变参数的模板往往是类内函数
    cout << t0.p << endl;
    if (sizeof...(t) > 0) {
        //注意sizeof...(args)和(args...)的用法
        //(args...)可以理解为没有参数
        //在执行期间会转到printf2(T0 t0, T... t)进行执行
        printf2(t...);
    }
}
int main(){
    Person p1(1), p2(2), p3(3);
    printf2(p1, p2, p3);
    return 0;
}
```

### 9.委托构造函数可以在同一个类中一个构造函数调用另一个构造函数，从而达到简化代码的目的

```C++
class Base {
public:
    int value, value2;
    Base() : value(1), value2(value + 1) {};
    Base(int v) : Base() {
        value += v;
        value2 += v;
    }
};
int main(){
    Base base(4);
    cout << base.value << '\t' << endl
        << base.value2 << endl;
    //stdout:
    //5
    //6
    return 0;
}
```

### 10\. 多态（这里存粹是为了回顾一下（纯）虚函数以及多态的触发条件）

```C++
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
int main(){
    ABase* bbase = new BBase();
    ABase *cbase = new CBase();
    cout << setAndGet(bbase, 10) << endl;
    cout << setAndGet(cbase, 10) << endl;
    //stdout:
    //50
    //100
    return 0;
}
```

### 11.强枚举类

```C++
#include<iostream>
using namespace std;
enum class names : unsigned int {
    AA_000,
    BB_001 = 100,
    CC_002 = 100,
    DD_003
};
enum class types: unsigned int {
    TYPE_DOWN = 100

};
int main(){
    unsigned int b = static_cast<unsigned int>(names::BB_001);
    unsigned int c = static_cast<unsigned int>(names::CC_002);
    unsigned int d = static_cast<unsigned int>(names::DD_003);
    // if (names::BB_001 == types::TYPE_DOWN)  //编译不通过，不同的枚举空间不能进行比较
     if (names::BB_001 == names::CC_002)
        cout << "相同" << endl;
    cout << b << endl
        << c << endl
        << d << endl;
    //stdout:
    //相同
    //100
    //100
    //101
    return 0;
}
```

## Chapter2

### 1.泛型 Lambda即lambda函数支持auto形参

```C++
auto add = [](auto x, auto y) {
    return x + y;
};
auto a = add(1, 2.1);
cout << a << endl;
//stdout:
//3.1(float)
```

### 2.std::bind 和 std::placeholder 函数绑定与参数占位

```c++
#include<functional>
using namespace std;
int getArgs(int a, int b, int c) {
    cout << a << '\t' << b << '\t' << c << endl;
    return 0;
}
int main(){
    auto execFunc = bind(getArgs, placeholders::_2, placeholders::_1, 100);  
    //最好可以做到前面是占位后面是数值，就像是默认形参一样
    execFunc(1, 3);
    //stdout:
    //3 1 100
    return 0;
}
```

### 3\. 右值引用（重要！）

> 右值引用是 C++11 引入的与 Lambda 表达式齐名的重要特性之一。它的引入解决了 C++ 中大量的历史遗留问题， 消除了诸如 `std::vector`、`std::string` 之类的额外开销， 也才使得函数对象容器 `std::function` 成为了可能。
>
> **左值、右值的纯右值、将亡值、右值**
>
> 要弄明白右值引用到底是怎么一回事，必须要对左值和右值做一个明确的理解。
>
> **左值(lvalue, left value)**，顾名思义就是赋值符号左边的值。准确来说， 左值是表达式（不一定是赋值表达式）后依然存在的持久对象。
>
> **右值(rvalue, right value)**，右边的值，是指表达式结束后就不再存在的临时对象。
>
> 而 C++11 中为了引入强大的右值引用，将右值的概念进行了进一步的划分，分为：纯右值、将亡值。
>
> **纯右值(prvalue, pure rvalue)**，纯粹的右值，要么是纯粹的字面量，例如 `10`, `true`； 要么是求值结果相当于字面量或匿名临时对象，例如 `1+2`。非引用返回的临时变量、运算表达式产生的临时变量、 原始字面量、Lambda 表达式都属于纯右值。
>
> **将亡值(xvalue, expiring value)**，是 C++11 为了引入右值引用而提出的概念（因此在传统 C++中， 纯右值和右值是同一个概念），也就是即将被销毁、却能够被移动的值。

```C++
//string的重载operator+返回的是一个要即将被销毁的对象无法赋值给常规引用，下面是两种延续其声明周期的方法：
//方法1：
std::string lv1 = "string,"; // lv1 是一个左值
const string& lv2 = lv1 + lv1; // 合法, 常量左值引用能够延长临时变量的生命周期
//ll += "Test"; // 非法, 常量引用无法被修改
cout << lv2 << endl; // string,string
//方法2：
string&& rv2 = lv1 + lv2; // 合法, 右值引用延长临时对象生命周期
rv2 += "Test"; // 合法, 非常量引用能够修改临时变量
cout << rv2 << endl; // string,string,string,Test
reference(rv2); // 输出左值
```

### 4\. 四种类型转换

> 1.  `static_cast`
>
>     这是最常用的一种类型转换方法。它可以用于基础数据类型之间的转换，如 `int` 到 `float`，或者指针类型之间的转换。
>
> 2.  `dynamic_cast`
>
>     `dynamic_cast` 主要用于对象的上行和下行转换，即基类和派生类之间的转换。如果转换失败，`dynamic_cast` 会返回 `nullptr`。
>
> 3.  `const_cast`
>
>     `const_cast` 主要用于去除 `const` 属性。
>
> 4.  `reinterpret_cast`（个人猜测，可用于对数据的保护）
>
>     `reinterpret_cast` 用于任何类型的指针或整数类型之间的转换。这是一个非常强大的转换，但也非常危险，应谨慎使用。reinterpret_cast是为了映射到一个完全不同类型的意思，这个关键词在我们需要把类型映射回原有类型时用到它。我们映射到的类型仅仅是为了故弄玄虚和其他目的，这是所有映射中最危险的。

```C++
//static_cast举例：
int a = 10;
float b = static_cast<float>(a);  // 将 int 转换为 float
//dynamic_cast举例：
class Base { virtual void dummy() {} };
class Derived : public Base { int a = 1; };
Base* base = new Base;
Derived* son = new Derived;
Derived* derived = dynamic_cast<Derived*>(base);  // 这将失败，返回 nullptr
Base* fa = dynamic_cast<Base*>(son);  // 成功，可以像上转换（子到父）
cout << derived << endl;
cout << fa << endl;
if (derived == nullptr)  cout << "向下转换失败" << endl;
if (fa != nullptr)  cout << "向上转换成功" << endl;
//stdout:
//0000000000000000
//00000275DE5C4F20
//向下转换失败
//向上转换成功

//const_cast举例：
std::string lv1 = "string,"; // lv1 是一个左值
const string& lv2 = lv1 + lv1; // 合法, 常量左值引用能够延长临时变量的生命周期
string& ll = const_cast<string&>(lv2);
cout << lv2 << endl;
ll += "Test"; // 合法, 经过了常量类型转换
cout << lv2 << endl;
//reinterpret_cast举例，转换后指向的还是原来的数据，只是表达方式变了
int a = 10;
int *ip = &a;
// <写上要转换的目标类型>(要转换的变量)
char *cp = reinterpret_cast<char*>(ip);
// 转换为数字类型
int addr = reinterpret_cast<int>(ip);
cout << addr << endl;
// 函数指针转换
typedef void(FUNC_ONE)(void);
typedef void(FUNC_TWO)(int);
FUNC_ONE *fun_ptr1 = nullptr;
FUNC_TWO *fun_ptr2 = reinterpret_cast<FUNC_TWO*>(fun_ptr1);
```

### 5.移动构造函数（资源移动，不进行拷贝销毁） move可以来构造右值

```C++
class A {
public:
    int p;
    vector<int> arr;
    A() {};
    A (const A& a){
        cout << "a的资源地址" << endl;
        cout << "常量p地址：" << &a.p << endl;
        cout << "vector地址：" << &a.arr.back() << endl;
        p = a.p;
        arr = a.arr;
        cout << "发生了拷贝构造" << endl;
        cout << "常量p地址：" << &p << endl;
        cout << "vector地址："<< &arr.back() << endl;
    }
    A (A&& a) noexcept {
        cout << "a的资源地址" << endl;
        cout << "常量p地址：" << &a.p << endl;
        cout << "vector地址：" << &a.arr.back() << endl;
        p = move(a.p);
        arr = move(a.arr);  //move过的资源回恢复成初始态，但是起始地址回发生变化
        cout << "发生了移动构造" << endl;
        cout << "常量p地址：" << &p << endl;
        cout << "vector地址：" << &arr.back() << endl;
        //cout << "vector地址：" << &a.arr.back() << endl; //非法，a.arr的资源被移动后进入了初始状态
    }
    ~A() {
        cout << "A被删除了" << endl;
    }
};
A getA() {
    A a;
    a.p = 1;
    a.arr = vector<int>({ 1, 2, 3 });
    return a;
}
int main(){
    A a = getA();
    cout << "确认一下：" << endl;
    cout << "常量p地址：" << &a.p << endl;
    cout << "vector地址：" << &a.arr.back() << endl;
    return 0;
}
```

- 拷贝构造时会输出：

    ```tex
    a的资源地址
    常量p地址：000000DCAF2FF818
    vector地址：00000267B1734348
    发生了拷贝构造
    常量p地址：000000DCAF2FFAA8
    vector地址：00000267B17340C8
    A被删除了
    确认一下：
    常量p地址：000000DCAF2FFAA8
    vector地址：00000267B17340C8
    A被删除了
    ```

- 移动构造时会输出：

    ```tex
    a的资源地址
    常量p地址：0000006F81FFF7C8
    vector地址：000001AFDAF24488
    发生了移动构造
    常量p地址：0000006F81FFFA58
    vector地址：000001AFDAF24488
    A被删除了
    确认一下：
    常量p地址：0000006F81FFFA58
    vector地址：000001AFDAF24488
    A被删除了
    ```

***由此也可以看出移动构造对内置基本变量类型没有作用，比较使用占用内存较多的资源***

```C++
class AAA{
public:
    int a;
    AAA() : a(0) {};
    AAA(int _a) {
        a = _a;
    }
};
class T {
public:
    int p = 0;
    vector<AAA> arr;
    T() {
        arr.push_back(AAA(1));
        cout << "T构造函数" << endl;
        cout << "T.p：" << &p << endl;
        cout << "T.arr[0]：" << &arr[0] << endl;
        cout << "T.arr：" << &arr << endl;
    }
    T(const T& t) {
        cout << "T拷贝构造函数" << endl;
        p = t.p;
        arr = t.arr;
    }
    //T(T&& t) noexcept : arr(move(t.arr))  {
    //    cout << "T移动构造函数" << endl;
    //    p = move(t.p);
    //}
    ~T() {
        cout << "T我被销毁了" << endl;
    }
};

T getT(bool flag) {
    T tt, tt2;
    tt.p = 1;
    tt2.p = 2;
    if (flag)  return tt;
    else return tt2;
}
int main() {
    bool flag = true;
    T&& tt = getT(flag);  //返回的是一个右值，如果T类型的移动构造没有实现的话带有&&也是无效的
    cout << "T.p：" << &tt.p << endl;
    cout << "T.arr[0]：" << &tt.arr[0] << endl;
    cout << "T.arr：" << &tt.arr << endl;
    cout << tt.arr[0].a << endl;
    return 0;
}
```

```tex
输出结果：

T构造函数
T.p：00000015160FF9F8
T.arr[0]：0000018777AD9110  X
T.arr：00000015160FFA00  √ 指针的指针（个人理解）
//T构造函数
//T.p：00000015160FFA38
//T.arr[0]：0000018777AD8B50
//T.arr：00000015160FFA40
T拷贝构造函数
T我被销毁了
//T我被销毁了
T.p：00000015160FFBD8
T.arr[0]：0000018777AD9350  X
T.arr：00000015160FFBE0  √指针的指针
1
T我被销毁了
```



### 6.再次体验一些右值资源的"迁移"，个人感觉"转手"形容更为贴切

```C++
string ccc;
const char* p;
void fff() {
    string b = "123";
    p = b.c_str();
    cout << p << end; //这里打印的是"123"资源还没被重置
    ccc = move(b);  //这里的b资源已经被"搬走"了 其实是ccc的内部指针指向了该资源 原来的
    cout << p << endl; //这里的b资源已经回到了初始化状态 所以为""空
    //函数执行完毕其实b发生了销毁，但是资源已经移动到了b上
}
int main() {
    fff();
    cout << p << endl; //这里由于b资源已经被销毁了所以是乱码
    cout << ccc << endl; //所以这里ccc的打印还是123 即最初的b资源
    return 0;
}
```

## Chapter3

### 1. 常用容器`vector`，`array`，`（unordered_）map`，`（unordered_）set`， `queue`，`priority_queue`，`deque`，`stack`，`tuple`，`bit_set`

> 作为一名业余的算法爱好者，以上容器肯定是不离手的，这里稍微介绍一下array产生的原因，以及与vector的区别
> `std::array`
> 看到这个容器的时候肯定会出现这样的问题：
>
> 1.  为什么要引入  `std::array`  而不是直接使用  `std::vector`？
> 2.  已经有了传统数组，为什么要用  `std::array`?
>     与  `std::vector`  不同，`std::array`  对象的大小是固定的，如果容器大小是固定的，那么可以优先考虑使用  `std::array`  容器。 另外由于  `std::vector`  是自动扩容的，当存入大量的数据后，并且对容器进行了删除操作， 容器并不会自动归还被删除元素相应的内存，这时候就需要手动运行  `shrink_to_fit()`  释放这部分内存。

```C++
// 遇到固定长度的数组时，优先使用array而不是T arr[len]
std::vector<int> v;
std::cout << "size:" << v.size() << std::endl;         // 输出 0
std::cout << "capacity:" << v.capacity() << std::endl; // 输出 0
// 如下可看出 std::vector 的存储是自动管理的，按需自动扩张
// 但是如果空间不足，需要重新分配更多内存，而重分配内存通常是性能上有开销的操作
v.push_back(1);
v.push_back(2);
v.push_back(3);
std::cout << "size:" << v.size() << std::endl;         // 输出 3
std::cout << "capacity:" << v.capacity() << std::endl; // 输出 4
// 这里的自动扩张逻辑与 Golang 的 slice 很像
v.push_back(4);
v.push_back(5);
std::cout << "size:" << v.size() << std::endl;         // 输出 5
std::cout << "capacity:" << v.capacity() << std::endl; // 输出 8
// 如下可看出容器虽然清空了元素，但是被清空元素的内存并没有归还
v.clear();                                             
std::cout << "size:" << v.size() << std::endl;         // 输出 0
std::cout << "capacity:" << v.capacity() << std::endl; // 输出 8
// 额外内存可通过 shrink_to_fit() 调用返回给系统
v.shrink_to_fit();
std::cout << "size:" << v.size() << std::endl;         // 输出 0
std::cout << "capacity:" << v.capacity() << std::endl; // 输出 0
```

### 2.智能指针 `shared_ptr`，`unique_ptr`，`weak_ptr`

#### 1.shared_ptr

> std::shared_ptr 是一种智能指针，它能够记录多少个 shared_ptr 共同指向一个对象，从而消除显示的调用 delete，当引用计数变为零的时候就会将对象自动删除。
> `shared_ptr sptr = make_share<T>(data);`

```C++
#include<memory>
#include<iostream>
using namespace std;
int main(){
	constexpr int len = 4;
	shared_ptr sptr = make_shared<array<int, len>>(array<int, len>{1, 2, 3, 4});
	{
		//块语句
		array<int, len>* p = sptr.get(); //生成的普通指针不会修改引用计数
		cout << sptr.use_count() << endl; //1
		shared_ptr sptr2 = sptr;
		(*sptr2)[0] = 100;
		cout << sptr.use_count() << endl; // 2
		cout << sptr2.use_count() << endl; //2
		sptr2.reset();
		cout << sptr.use_count() << endl; //1
		cout << sptr2.use_count() << endl; //0
	}
	cout << sptr.use_count() << endl; //1
	cout << (*sptr)[0] << endl; //100
	return 0;
}
```

#### 2. unique_ptr

> `std::unique_ptr` 是一种独占的智能指针，它禁止其他智能指针与其共享同一个对象，从而保证代码的安全
> 既然是独占，换句话说就是不可复制。但是，我们可以利用 `std::move` 将其转移给其他的 `unique_ptr`

```C++
#include<memory>
unique_ptr uptr = make_unique<vector<int>>();
uptr->emplace_back(1);
cout << uptr << endl;
// unique_ptr uptr2 = uptr; 不被允许
unique_ptr uptr2 = move(uptr);
cout << uptr << endl;  //资源已近转move转手
cout << uptr2 << endl;
//stdout:
//000001F0D66DFB30
//0000000000000000
//000001F0D66DFB30
```

#### 3.weak_ptr （主要用来解决交叉引用的问题）

> weak_ptr 设计的目的是为配合 shared_ptr 而引入的一种智能指针来协助 shared_ptr 工作, 它只可以从一个 shared_ptr 或另一个 weak_ptr 对象构造, 它的构造和析构不会引起引用记数的增加或减少。 同时weak_ptr 没有重载*和->但可以使用 lock 获得一个可用的 shared_ptr 对象。

1. 弱指针的使用：
    weak_ptr wpGirl_1; // 定义空的弱指针
    weak_ptr wpGirl_2(spGirl); // 使用共享指针构造
    wpGirl_1 = spGirl; // 允许共享指针赋值给弱指针

2. 弱指针也可以获得引用计数：
    wpGirl_1.use_count()

3. 弱指针不支持 * 和 -> 对指针的访问；

4. 在必要的使用可以转换成共享指针 lock()。

```C++
#include<memory>
shared_ptr<Girl> sp_girl;
sp_girl = wpGirl_1.lock(); //别忘记引用计数+1了

// 使用完之后，再将共享指针置nullptr即可
sp_girl = nullptr; //reset
```

```C++
#include<memory>
weak_ptr wptr = make_shared<int>();
{
	shared_ptr uptr = make_shared<int>(10);
	wptr = uptr;
	cout << wptr.use_count() << endl; // 1
	cout << wptr.expired() << endl; //0，维护的数据还没有被释放
	if (!wptr.expired()) {
		 shared_ptr t = wptr.lock();
		//(*wptr.lock()) = 20;
		 (*t) = 20;
		 cout << uptr.use_count() << endl; // 2
		 t = nullptr; //鉴于内部实现 nullptr 和 reset 是绝对等价的
		 cout << uptr.use_count() << endl;// 1
	}
	cout << (*uptr) << endl; //20，lock获取weak_ptr所对应的shared_ptr
}
cout << wptr.use_count() << endl; // 0
cout << wptr.expired() << endl; // 1，维护的数据被释放了
```

#### 4.shared_ptr的交叉引用问题，以及weak_ptr的解决方案

> 案例来自于：
> 原文链接：https://blog.csdn.net/cpp_learner/article/details/118912592

```tex
Boy类中有Girl的智能指针；
Girl类中有Boy的智能指针；
当他们交叉互相持有对方的管理对象时…
```

```C++
#include <iostream>
#include <string>
#include <memory>

using namespace std;

class Girl;

class Boy {
public:
	Boy() {
		cout << "Boy 构造函数" << endl;
	}

	~Boy() {
		cout << "~Boy 析构函数" << endl;
	}

	void setGirlFriend(shared_ptr<Girl> _girlFriend) {
		this->girlFriend = _girlFriend;
	}

private:
	shared_ptr<Girl> girlFriend;
};

class Girl {
public:
	Girl() {
		cout << "Girl 构造函数" << endl;
	}

	~Girl() {
		cout << "~Girl 析构函数" << endl;
	}

	void setBoyFriend(shared_ptr<Boy> _boyFriend) {
		this->boyFriend = _boyFriend;
	}

private:
	shared_ptr<Boy> boyFriend;
};


void useTrap() {
	shared_ptr<Boy> spBoy(new Boy());
	shared_ptr<Girl> spGirl(new Girl());

	// 陷阱用法
	spBoy->setGirlFriend(spGirl);
	spGirl->setBoyFriend(spBoy);
	// 此时boy和girl的引用计数都是2
}


int main(void) {
	useTrap();

	system("pause");
	return 0;
}
```

**这时Boy和Girl对象均没有得到释放**
![运行截图](https://img-blog.csdnimg.cn/12cc6f26f5974fd4ba3f73eea9d5a0f8.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L2NwcF9sZWFybmVy,size_16,color_FFFFFF,t_70#pic_center)
![解释1](https://img-blog.csdnimg.cn/f00ef1a424b2427cb7817c146bf28abb.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L2NwcF9sZWFybmVy,size_16,color_FFFFFF,t_70#pic_center)
![解释2](https://img-blog.csdnimg.cn/cd962cb9e0ae4610bebb40da2133e8a9.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L2NwcF9sZWFybmVy,size_16,color_FFFFFF,t_70#pic_center)

> 所以在使用shared_ptr智能指针时，要注意避免对象交叉使用智能指针的情况！ 否则会导致内存泄露！
> 当然，这也是有办法解决的，那就是使用weak_ptr弱指针。

```tex
针对上面的情况，还讲一下另一种情况。如果是单方获得管理对方的共享指针，那么这样着是可以正常释放掉的！
例如：
```

```C++
void useTrap() {
	shared_ptr<Boy> spBoy(new Boy());
	shared_ptr<Girl> spGirl(new Girl());

	// 单方获得管理
	//spBoy->setGirlFriend(spGirl);
	spGirl->setBoyFriend(spBoy);	
}
```

![运行结果](https://img-blog.csdnimg.cn/e5439af7a98d461493bc3356f494fd2e.jpg?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L2NwcF9sZWFybmVy,size_16,color_FFFFFF,t_70#pic_center)

**记住weak_ptr确实"指向"了那块资源（表述为记录了那块资源的状态更为贴切）但是并不会导致引用计数的增加，再利用weak_ptr的特性所以可以完美的解决这个问题**

```C++
#include <iostream>
#include <string>
#include <memory>

using namespace std;

class Girl;

class Boy {
public:
	Boy() {
		cout << "Boy 构造函数" << endl;
	}
	~Boy() {
		cout << "~Boy 析构函数" << endl;
	}
	void setGirlFriend(shared_ptr<Girl> _girlFriend) {
		this->girlFriend = _girlFriend;
		// 在必要的使用可以转换成共享指针
		shared_ptr<Girl> sp_girl;
		sp_girl = this->girlFriend.lock();

		cout << sp_girl.use_count() << endl;
		// 使用完之后，再将共享指针置NULL即可
		sp_girl = NULL;
	}
private:
	weak_ptr<Girl> girlFriend;
};
class Girl {
public:
	Girl() {
		cout << "Girl 构造函数" << endl;
	}

	~Girl() {
		cout << "~Girl 析构函数" << endl;
	}

	void setBoyFriend(shared_ptr<Boy> _boyFriend) {
		this->boyFriend = _boyFriend;
	}
private:
	shared_ptr<Boy> boyFriend;
};
void useTrap() {
	shared_ptr<Boy> spBoy(new Boy());
	shared_ptr<Girl> spGirl(new Girl());
	spBoy->setGirlFriend(spGirl);
	spGirl->setBoyFriend(spBoy);
}
int main(void) {
	useTrap();
	system("pause");
	return 0;
}
```

#### 5.智能指针使用过程中的一些注意点

1. `尽量不要同时使用原生指针和多个智能指针管理数据;`

```C++
int *x = new int(10);
unique_ptr< int > up1(x);
unique_ptr< int > up2(x);
// 警告! 以上代码使up1 up2指向同一个内存,非常危险
或以下形式：
up1.reset(x);
up2.reset(x);
```

2. `智能指针get 函数返回的指针;
    如果我们主动释放掉get 函数获得的指针，那么智能 指针内部的指针就变成野指针了，析构时造成重复释放，带来严重后果!`
3. `禁止用任何类型智能指针get 函数返回的指针去初始化另外一个智能指针！`

```C++
shared_ptr<int> sp1(new int(10));
// 一个典型的错误用法 
shared_ptr<int> sp4(sp1.get());
cout << sp4.use_count() << endl;
// 因为这样会导致新的引用计数为1，如果释放的会导致原有的sp1错误，并且会释放两次
```

4. `为了安全起见不要使用原生指针来初始化智能指针，就像第一条一样，不要混用`
    **常用的初始化方法有两种：**
    `shared_ptr<T> sptr(new X)及 shared_ptr sptr = make_shared<T>(data)`

## Chapter4 （文件操作）

### 1.获取路径的绝对路径和相对路径 os::absolute和os::relative

```C++
#include<iostream>
#include<filesystem>
using namespace std;
namespace os = filesystem;
os::path abs_path = os::absolute(os::current_path());
cout << "当前工作目录的绝对目录：" << abs_path << endl;
cout << "当前工作目录的相对目录：" << os::relative(abs_path) << endl;
```

### 2.查看和切换当前目录，创建一层或多层目录 os::current_path() 和 os::create_directories()

```C++
#include<iostream>
#include<filesystem>
using namespace std;
namespace os = filesystem;
os::path target_path = "D:\\abc\\def";
if (!os::exists(target_path)) {
    //os::create_directory(target_path); //create_directory可以在已有的基础上创建一层目录
    os::create_directories(target_path); //create_directories则可以递归创建多层目录
}
os::current_path(target_path); //current_path传入参数时会切换当前工作目录
os::path cur_path = os::current_path();  //不参入参数的时候则会返回当前所在的目录
cout << cur_path.string() << endl; 
```

### 3.文件以及文件夹的删除和拷贝 remove()和copy()

```C++
#include<iostream>
#include<filesystem>
using namespace std;
namespace os = filesystem;
os::path target_path = "D:\\abc\\def";
//删除某个文件
os::remove(target_path / "a/a.txt");
//删除整个文件夹
if(target_path != os::current_path()) os::remove_all(target_path); 
//删除时要保证删除的target_path不是当前目录

//拷贝文件和目录
if (os::exists("D:\\def")) {
    os::copy(target_path, "D:\\def", 
        os::copy_options::recursive | os::copy_options::overwrite_existing);
}
//copy_options::skip_existing 选项告诉 copy 函数跳过已存在内容。
//copy_options::recursive 选项告诉 copy 函数递归复制目录及其所有内容 如果不加就只有目录结构没有内容。
//copy_options::overwrite_existing 选项告诉 copy 函数如果目标文件已经存在，就覆盖它。
```

### 4.遍历路径与递归遍历 os::recursive_directory_entry 和 directory_entry

>   C++20中支持stirng::ends_with和starts_with

```C++
//遍历当前文件夹下的所有文件和文件夹，不递归遍历。
os::path target_path = "D:\\abc\\def";
os::directory_iterator dir_iters(target_path);
for (const os::directory_entry& it : dir_iters) {
    cout << "路径为：" << it.path() << endl
        << "类型为：" << (it.is_directory() ? "文件夹" : "文件") << endl
        << "文件名为：" << it.path().filename() << endl
        << "扩展名为：" << it.path().extension() << endl
        << "不带扩展的文件名为：" << it.path().stem() << endl;
    if (!it.is_directory() && it.path().string().ends_with(".xlsx")) {
        //C++20中支持stirng::ends_with和starts_with
        cout << "\t是xlsx类型的文件" << endl
            << "文件大小为：" << it.file_size() << endl; // 以B为单位
    }
    cout << string(20, '*') << endl;
};
//递归遍历整个文件夹下的所有子文件夹和文件
os::recursive_directory_iterator recursive_iters(target_path);
for (const os::directory_entry& blk : recursive_iters) {
    cout << "目录为：" << blk.path() << endl
        << "类型为：" << (blk.is_directory() ? "目录" : "文件") << endl
        << "占用空间：" << blk.file_size() << endl
        << "最近一次的修改时间：" << os::last_write_time(blk) << endl
        << string(20, '*') << endl;
}
```

### 5.重命名与移动 os::rename

```C++
//重命名 无论是重命名还是删除都不能对当前的工作目录或工作父目录进行操作
//b不存在a目录才能移动成功
os::current_path("D:/");
os::path a = "D:/abc", b = "D:/def";
b += "/" + a.filename().string();
try {
    if (a != os::current_path()) os::rename(a, b);
}
catch (exception& E) {
    cout << E.what() << endl;
}
```

## Chapter5 并发与并行

>   有需要的请去看 [C++ Concurrency In Action - 《C++并发编程(第二版)（C++ Concurrency In Action - 2nd edition）》 - 书栈网 · BookStack](https://www.bookstack.cn/read/xiaoweiChen-CPP-Concurrency-In-Action-2ed-2019/README.md) 这里不再进行整理
