#include<bits/stdc++.h>

#define  ll long long int

using namespace std;

ll helper(ll n, ll e, ll h, ll a, ll b, ll c);
ll minv(ll a, ll b);
ll maxv(ll a, ll b);

void cpc() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // !ONLINE_JUDGE

}

int main() {
	cpc();
	ll  t;
	cin >> t;
	while (t--) {
		ll N, E, H;
		ll A, B, C;
		cin >> N >> E >> H >> A >> B >> C;
		ll cost;
		cost = helper(N, E, H, A, B, C);

		if (cost == 1e15)
			cout << -1 << endl;
		else
			cout << cost << endl;

	}
	return 0;
}
ll helper(ll n, ll e, ll h, ll a, ll b, ll c) {

	if (n <= 0) {
		//when there are no orders
		return 0;
	}
	ll ans = 1e15;
	if ((n <= e) and (n <= h)) {
		//all are chocolate cakes
		ans = minv(ans, n * c);
		//cost of n cakes will be n*c
	}
	if (3 * n <= h) {
		//all orders are milk shake
		ans = minv(ans, n * b);
	}
	if (2 * n <= e) {
		//all orders are omlettes
		ans = minv(ans, n * a);
	}
	if (((h - n) / 2 >= 1) and ((h - n) / 2 >= n - e)) {
		//for milk shake and chocolate cake
		if (b - c < 0) {
			ll temp = minv(n - 1, (h - n) / 2);
			ans = minv(ans, (b - c) * temp + n * c);
		} else {
			ll temp = maxv(1, n - e);
			ans = minv(ans, (b - c) * temp + n * c);
		}
	}
	if (e - n >= 1 and e - n >= n - h) {
		//only omlette and chocolate
		if (a - c < 0) {
			ll temp = minv(n - 1, e - n);
			ans = minv(ans, (a - c) * temp + n * c);

		}
		else {
			ll temp = maxv(1, n - h);
			ans = minv(ans, (a - c) * temp + n * c);
		}
	}
	if ((e / 2 >= 1) and (e / 2 >= (3 * n - h + 2) / 3)) {
		if (a - b < 0) {
			ll temp = minv(n - 1, e / 2);
			ans = minv(ans, (a - b) * temp + n * b);
		} else {
			ll temp = maxv(1, (3 * n - h + 2) / 3);
			ans = minv(ans, (a - b) * temp + n * b);
		}
	}
	//for all type of order
	if ((e >= 3) and (h >= 4) and (n >= 3)) {
		//A+B+C = sum of three orders
		ans = minv(ans, a + b + c + helper(n - 3, e - 3, h - 4, a, b, c));
	}
	return ans;

}

ll minv(ll a, ll b) {
	if (a < b)
		return a;
	return b;
}
ll maxv(ll a, ll b) {
	if (a > b)return a;
	return b;
}