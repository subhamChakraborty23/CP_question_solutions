#include<bits/stdc++.h>

using namespace std;


void cpc() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // !ONLINE_JUDGE

}

int main() {
	cpc();
	int t;
	cin >> t;
	while (t--) {
		long int c;
		cin >> c;
		long int x = c;
		int ones = 0;//no. of ones in c binary
		int size = 0;//size of c in binary
		while (x > 0) {
			if (x % 2 == 1) {
				ones++;
			}
			x = x / 2;
			size++;
		}
		//The product A*B will be max when both A and B are max ,iterate over
		//ever bit of c and for each bit in c if it is 0 then put 1 in both A and B
		//if it is 1then we can put 1 in A and 0 in B or vice versa, if we put 1 at MSB
		//of A then we have to put remaining 1s in B so that B will also be max
		int A[size], B[size];
		int s = size;
		x = c;
		int idx = 0;
		while (x > 0) {
			if (x % 2 == 0) {
				A[idx] = 1; B[idx] = 1;
			} else {
				if (ones == 1) {
					A[idx] = 1; B[idx] = 0;
				} else {
					A[idx] = 0; B[idx] = 1;
				}
				ones--;
			}
			idx++;
			x = x / 2;
		}
		long int a = 0, b = 0;
		long int p = 1;
		for (int i = 0; i < s; i++) {
			a = a + p * A[i];
			b = b + p * B[i];
			p = p * 2;
		}
		cout << a * 1ll * b << endl;
	}
	return 0;
}