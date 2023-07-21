#include<tuple>
#include<iostream>
using namespace std;
int main() {
	tuple<int, int, double> t = { 1, 1, 1.0 };
	get<1>(t);
	return 0;
}
