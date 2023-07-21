# 现代C++快速入门 | C++11/14/17/20

## Chapter1

### 1. 使用nullptr来代替NULL

### 2. 使用static_cast<type>来替代(type)进行类型转换

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

### 7. 区间for循环

### 8.

