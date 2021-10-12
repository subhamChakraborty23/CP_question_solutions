#include <bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define fo1(i,a,n) for(int i=a;i<n;i++)
#define fo2(i,a,n) for(int i=a;i<=n;i++)
#define Fo(i,k,n) for(i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)
#define ll long long int
#define si(x)   scanf("%d",&x)
#define sl(x)   scanf("%I64d",&x)
#define ss(s)   scanf("%s",s)s
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define tr(it, a) for(auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
#define minHp priority_queue<int>
#define maxHp priority_queue<int,vi,greater<int>>
#define setbits(x) __builtin_popcountll(x)
#define zerobits(x) __biultin_ctzll(x)
#define inf 1e18
#define ps(x,y) fixed<<setprecision(y)<<x
#define mk(arr,n,type) type *arr = new type[n]
#define w(x) int x=1;cin>>x; while(x--)
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define showarr(arr , a , size ) for (int i = a; i <=size ; i++) {cout << arr[i] << " ";}

typedef pair<int, int>      pii;
typedef pair<int, int>      pll;
typedef vector<int>         vi;
typedef vector<ll>         vl;
typedef vector<pii>         vpii;
typedef vector<pll>         vpll;
typedef vector<vi>          vvi;
typedef vector<vl>          vvl;
const int mod = 1000000007;
mt19937  rng(chrono::steady_clock::now().time_since_epoch().count());

// ll lcm(ll a, ll b) {
//     ll a0 = a;
//     ll b0 = b;
//     return a0 * b0 / __gcd(a0, b0);
// }

void cpc() {

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif // !ONLINE_JUDGE

}
// int calculateMex(unordered_set<int> Set)
// {
//     int Mex = 0;

//     while (Set.find(Mex) != Set.end())
//         Mex++;

//     return (Mex);
// }


void solve() {
    ll n, m, k;
    cin >> n >> m >> k;
    double arr[n + 1][m + 1];
    for (ll i = 0; i <= n; i++) {
        for (ll j = 0; j <= m; j++) {
            if (i == 0 or j == 0)
                arr[i][j] = 0;
            else
                cin >> arr[i][j];
        }
    }
    for (ll i = 0; i <= n; i++) {
        double prev = 0;
        for (ll j = 0; j <= m; j++) {
            arr[i][j] += prev;
            prev = arr[i][j];
        }
    }
    for (ll i = 0; i <= m; i++) {
        double prev = 0;
        for (ll j = 0; j <= n; j++) {
            arr[j][i] += prev;
            prev = arr[j][i];
        }
    }
    ll minM = min(m, n);
    ll ans = 0;
    for (ll u = 1; u <= minM; u++) {
        for (ll i = u; i <= n; i++) {
            for (ll j = u; j <= m; j++) {
                if ((arr[i][j] + arr[i - u][j - u] - arr[i][j - u] - arr[i - u][j]) / (u * u) >= k) {
                    ans++;
                }
            }
        }
    }
    cout << ans << endl;
}




int32_t main() {
    clock_t begin = clock();
    FIO
    cpc();
    int t;
    cin >> t;
    while (t--) {
        solve();
    }





#ifndef ONLINE_JUDGE
    clock_t end = clock();
    cout << "\n\n Executed In: " << double(end - begin) << " secs" << endl;
#endif // !ONLINE_JUDGE

    return 0;
}