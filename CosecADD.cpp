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
// vector<vector<ll>>&a, vector<vector<ll>>&b
bool isValid(vector<vector<ll>>&a, vector<vector<ll>>&b, ll r , ll c) {
    ll i, j;
    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            if (a[i][j] != b[i][j]) {
                return false;
            }
        }
    }
    return true;
}


void solve() {
    ll r, c, x;
    cin >> r >> c >> x;

    vector<vector<ll>>a(r, vector<ll>(c, 0));
    vector<vector<ll>>b(r, vector<ll>(c, 0));
    // ll a[1001][1001] = {0};
    // ll b[1001][1001] = {0};

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> b[i][j];
        }
    }
    ll i, j, diff, k;
    if (r < x and c < x) {
        if (isValid(a, b, r, c))
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    } else if (r < x) {
        for (i = 0; i < r; i++) {
            for (j = 0; j <= (c - x + 1); j++) {
                if (a[i][j] == b[i][j])
                    continue;
                else {
                    diff = b[i][j] - a[i][j];
                    a[i][j] += diff;
                    k = 1;
                    while (k < x) {
                        a[i][j + k] += diff;
                        k++;
                    }
                }
            }
        }
        if (isValid(a, b, r, c))
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    } else if (c < x) {
        for (i = 0; i < c; i++) {
            for (j = 0; j < (r - x + 1); j++) {
                if (a[j][i] == b[j][i])
                    continue;
                else {
                    diff = b[j][i] - a[j][i];
                    a[j][i] += diff;
                    k = 1;
                    while (k < x) {
                        a[j + k][i] += diff;
                        k++;
                    }
                }
            }
        }
        if (isValid(a, b, r, c))
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    } else if (r >= x and c >= x) {
        for (i = 0; i < r; i++) {
            for (j = 0; j < (c - x + 1); j++) {
                if (a[i][j] == b[i][j])
                    continue;
                else {
                    diff = b[i][j] - a[i][j];
                    a[i][j] += diff;
                    k = 1;
                    while (k < x) {
                        a[i][j + k] += diff;
                        k++;
                    }
                }
            }
        }
        for (i = 0; i < c; i++) {
            for (j = 0; j < (r - x + 1); j++) {
                if (a[j][i] == b[j][i])
                    continue;
                else {
                    diff = b[j][i] - a[j][i];
                    a[j][i] += diff;
                    k = 1;
                    while (k < x) {
                        a[j + k][i] += diff;
                        k++;
                    }
                }
            }
        }
        if (isValid(a, b, r, c))
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }


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