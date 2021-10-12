#include<bits/stdc++.h>
using namespace std;
int main() {
	int a = 1, b = 10, c = 1;
	if ((a & b || 0) || (a && c && 0)) {
		a = a + c;
		b = b % 3;
	}
	a = a << 1;
	cout << a + b - c;
}