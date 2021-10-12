#include <bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define fo1(i,a,n) for(int i=a;i<n;i++)
#define fo2(i,a,n) for(int i=a;i<=n;i++)
#define Fo(i,k,n) for(i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)
#define ll long long
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

ll lcm(ll a, ll b) {
    ll a0 = a;
    ll b0 = b;
    return a0 * b0 / __gcd(a0, b0);
}
//sieve of eratosthenes using bitset
//bitset<50005> isprime;
vector<bool> isprime(500005, true);
vector<int>primes;
void gen_primes(int max_limit) {
    for (int i = 2; i * i <= max_limit; i++) {
        if (isprime[i]) {
            //ith index is prime
            for (int j = i * i; j <= max_limit; j += i) {
                isprime[j] = false;
            }
        }
    }
    for (int i = 0; i <= max_limit; i++) {
        if (isprime[i]) {
            primes.pb(i);
        }
    }
}
bool isPrime(ll n) {
    if (n == 1)return false;
    if (n == 2)return true;
    for (int i = 2; i * i < n; i++) {
        if (n % i == 0) {
            return false;
        }

    }
    return true;
}


void cpc() {

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif // !ONLINE_JUDGE

}

const int N = 105;

int a[N][N];

vector<int>f;
void factors(ll n) {
    f.clear();
    for (int i = 1; i * i < n; i++) {
        if (n % i == 0 && n != i)
            f.pb(i);
    }
    for (int i = sqrt(n); i >= 1; i--) {
        if (n % i == 0 && n != i)
            f.pb(n / i);
    }
}
void solve() {
    int n;
    cin >> n;
    if (n == 1) {
        cout << "0" << endl;
        return;
    }
    if (n == 2) {
        cout << "1" << endl;
        return;
    }
    if (n == 3) {
        cout << "2" << endl;
        return;
    }
    if (n % 2 == 0) {
        cout << "2" << endl;
        return;
    }
    cout << "3" << endl;
    return;

}

int32_t main() {
    clock_t begin = clock();
    FIO
    cpc();

    w(x) {
        solve();
    }
#ifndef ONLINE_JUDGE
    clock_t end = clock();
    cout << "\n\n Executed In: " << double(end - begin) << " secs" << endl;
#endif // !ONLINE_JUDGE

    return 0;
}