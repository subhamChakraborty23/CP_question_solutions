#include <bits/stdc++.h>
using namespace std;


typedef long long int ll

#define pb push_back
#define mp make_pair

const int mod = 1000000007;
mt19937  rng(chrono::steady_clock::now().time_since_epoch().count());


void cpc() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // !ONLINE_JUDGE

}

int32_t main() {

	cpc();

	ll x;
	cin >> x;
	while (x--) {
		ll n, m, k;
		cin >> n >> m >> k;
		vector<ll>g(n + 1);
		for (ll i = 0; i < n; i++)
			cin >> g[i + 1];
		vector<vector<pair<ll, ll>>>arr(n + 1), dp(n + 1);
		for (ll i = 0; i < m; i++) {
			ll u, v, d;
			cin >> u >> v >> d;
			arr[u].pb(mp(i, d));
			arr[v].pb(mp(i, d));

		}
		dp[0].pb(mp(0, 0));
		for (ll i = 1; i <= n; i++) {
			vector<pair<ll, ll>>temp;
			temp.insert(temp.end(), dp[i - 1].begin(), dp[i - 1].end());
			ll curr = 0, mask = 0;
			set<ll>open;
			for (ll j = i; j >= i; j--) {
				curr += g[j];
				mask ^= 1LL << j;
				for (auto xyz : arr[j]) {
					if (open.count(xyz.first))
						curr += xyz.second;
					else
						open.insert(xyz.first);
				}
				if (j > 1) {
					for (auto xyzj : dp[j - 2]) {
						temp.pb(mp(xyzj.first + curr, mask ^ xyzj.second));
					}
				}
				else {
					temp.pb(mp(curr, mask));
				}

			}
			sort(temp.begin(), temp.end());
			reverse(temp.begin(), temp.end());
			set<ll>sel;
			ll filled = 0;
			for (ll j = 0; j < temp.size() && filled < k; j++) {
				if (sel.count(temp[j].second))
					continue;
				dp[i].pb(temp[j]);
				filled++;
				sel.insert(temp[j].second);
			}

		}
		for (ll i = 0; i < k; i++)
			cout << dp[n][i].first << " ";
		cout << endl;
	}
	return 0;
}
