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
	execFunc(1, 3);
    //stdout:
    //3 1 100
	return 0;
}
```

### 3.
