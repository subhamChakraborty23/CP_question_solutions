#include <bits/stdc++.h>
using namespace std;

vector<int>v;

int getMinDiff(vector<char> &v, int k) {
	int n = v.size();
	sort(v.begin(), v.end());

	int diff = v[n - 1] - v[0];

	// Handle corner elements
	int small = arr[0] + 1;
	int big = arr[n - 1] - 1;
	if (small > big)
		swap(small, big);

	// Traverse middle elements
	for (int i = 1; i < n - 1; i ++)
	{
		int subtract = v[i] - 1;

		int add = v[i] + 1;

		// If both subtraction and addition
		// do not change diff
		if (subtract >= small || add <= big)
			continue;

		// Either subtraction causes a smaller
		// number or addition causes a greater
		// number. Update small or big using
		// greedy approach (If big - subtract
		// causes smaller diff, update small
		// Else update big)
		if (big - subtract <= add - small)
			small = subtract;
		else
			big = add;
	}

	return  min(ans, big - small);

}



void solve() {

}

int32_t main() {
	clock_t begin = clock();
	FIO
	cpc();

	w(x) {
		int n, k;
		cin >> n >> k;
		v.resize(n);
		for (int i = 0; i < n; i++) {
			cin >> v[i];
		}
		int ans = getMinDiff(v, k)
		          cout << ans << endl;
	}
#ifndef ONLINE_JUDGE
	clock_t end = clock();
	cout << "\n\n Executed In: " << double(end - begin) << " secs" << endl;
#endif // !ONLINE_JUDGE

	return 0;
}