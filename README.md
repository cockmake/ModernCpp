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

# 现代C++快速入门 | C++11/14/17/20

## Chapter1

### 1. 使用nullptr来代替NULL

### 2. 使用`static_cast<type>(src_data)`来替代`(type)src_data`进行类型转换

### 3. 善用常量表达式constexpr，constexpr函数对变量进行绑定时变量的申明也需要constexpr

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

### 4. if switch 可以像for一样使用一个或多个临时变量了(C++17)

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

### 5. 结构化绑定来解决多类型值存储问题(C++17) tuple | make_tuple

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



### 6. 类型判断is_same 和 decltype

```C++
int a = 1;
double b = 1;
//::value取出bool值
//或者直接使用is_same_v<T, U>就不用使用::value了
if (a == b) cout << "a 与 b 数值相同" << endl;
if (is_same<decltype(a), decltype(b)>::value) cout << "a 与 b 类型相同" << endl; 
else cout << "a 与 b 类型不相同" << endl;
```

### 7. 区间（范围）for循环

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



### 10. 多态（这里存粹是为了回顾一下（纯）虚函数以及多态的触发条件）

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

### 3. 右值引用（重要！）

>   右值引用是 C++11 引入的与 Lambda 表达式齐名的重要特性之一。它的引入解决了 C++ 中大量的历史遗留问题， 消除了诸如 `std::vector`、`std::string` 之类的额外开销， 也才使得函数对象容器 `std::function` 成为了可能。
>
>   **左值、右值的纯右值、将亡值、右值**
>
>   要弄明白右值引用到底是怎么一回事，必须要对左值和右值做一个明确的理解。
>
>   **左值(lvalue, left value)**，顾名思义就是赋值符号左边的值。准确来说， 左值是表达式（不一定是赋值表达式）后依然存在的持久对象。
>
>   **右值(rvalue, right value)**，右边的值，是指表达式结束后就不再存在的临时对象。
>
>   而 C++11 中为了引入强大的右值引用，将右值的概念进行了进一步的划分，分为：纯右值、将亡值。
>
>   **纯右值(prvalue, pure rvalue)**，纯粹的右值，要么是纯粹的字面量，例如 `10`, `true`； 要么是求值结果相当于字面量或匿名临时对象，例如 `1+2`。非引用返回的临时变量、运算表达式产生的临时变量、 原始字面量、Lambda 表达式都属于纯右值。
>
>   **将亡值(xvalue, expiring value)**，是 C++11 为了引入右值引用而提出的概念（因此在传统 C++中， 纯右值和右值是同一个概念），也就是即将被销毁、却能够被移动的值。

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

### 4. 四种类型转换

>   1.   `static_cast`
>
>        这是最常用的一种类型转换方法。它可以用于基础数据类型之间的转换，如 `int` 到 `float`，或者指针类型之间的转换。
>
>   2. `dynamic_cast`
>
>       `dynamic_cast` 主要用于对象的上行和下行转换，即基类和派生类之间的转换。如果转换失败，`dynamic_cast` 会返回 `nullptr`。
>
>   3. `const_cast`
>
>       `const_cast` 主要用于去除 `const` 属性。
>
>   4. `reinterpret_cast`（个人猜测，可用于对数据的保护）
>
>       `reinterpret_cast` 用于任何类型的指针或整数类型之间的转换。这是一个非常强大的转换，但也非常危险，应谨慎使用。reinterpret_cast是为了映射到一个完全不同类型的意思，这个关键词在我们需要把类型映射回原有类型时用到它。我们映射到的类型仅仅是为了故弄玄虚和其他目的，这是所有映射中最危险的。

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

-   拷贝构造时会输出：

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

-   移动构造时会输出：

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
