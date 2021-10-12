#include <bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define fo1(i,a,n) for(int i=a;i<n;i++)
#define fo2(i,a,n) for(int i=a;i<=n;i++)
#define Fo(i,k,n) for(i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)
#define int long long
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
typedef vector<int>         vl;
typedef vector<pii>         vpii;
typedef vector<pll>         vpll;
typedef vector<vi>          vvi;
typedef vector<vl>          vvl;
const int mod = 1000000007;
mt19937  rng(chrono::steady_clock::now().time_since_epoch().count());

int lcm(int a, int b) {
    int a0 = a;
    int b0 = b;
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
int divisorOfFact(int n) {
    int result = 1;
    for (int i = 0; primes[i] <= n; i++) {
        int k = primes[i];
        int count = 0;
        while ((n / k) != 0) {
            count = (count + (n / k)) % mod;
            k = k * primes[i];
        }
        result = ((result % mod) * (count + 1) % mod) % mod;
    }
    return result;
}
void segmentedSieve(int a, int b) {
    vector<bool> segsieve(b - a + 1, true);
    if (a == 1)a++;
    for (int i = 0; primes[i]*primes[i] <= b; i++) {
        int p = primes[i];
        int j = (a / p) * p;
        if (j < a)j += p;
        for (; j <= b; j += p) {
            if (j != p) {
                segsieve[j - a] = false;
            }
        }
    }
    for (int i = a; i <= b; i++) {
        if (i <= 1)continue;
        if (segsieve[i - a] == true) {
            cout << i << endl;
        }
    }
}
void cpc() {

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif // !ONLINE_JUDGE

}
void solve() {
    int n;
    cin >> n;
    set<int>s;
    bool found = 0;
    fo1(i, 0, n) {
        int x;
        cin >> x;
        if (s.count(x))found = 1;
        s.insert(x);
    }
    if (found)cout << "YES\n";
    else cout << "NO\n";
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