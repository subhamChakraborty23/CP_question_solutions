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



void cpc() {

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif // !ONLINE_JUDGE

}

constexpr int MAXN = (int)1e6;
int dp[MAXN + 2], dp1[MAXN + 2];
int next0[MAXN], next1[MAXN];
ll arr[MAXN];

void solve(string s1,string s2) {
    multiset<char>s1set,s2set;

    for(auto c:s1){
        s1set.insert(c);
    }
    for(auto c:s2){
        s2set.insert(c);
    }
    string common="",uncommon = "";
    for(auto c:s1set){
        if(!s2set.count(c)){
            uncommon += c;
        }else{
            common += c;
        }
    }

    for(auto c:s2set){
        if(!s1set.count(c)){
            uncommon += c;
        }
    }
    
    cout<<uncommon<<" "<<common;


}




int main() {
    clock_t begin = clock();
    FIO
    cpc();
    int t;
    int i = 1;
    cin >> t;
    while (t--) {
        string s1,s2;
        cin>>s1;
        cin>>s2;
        solve(s1,s2);
    }





#ifndef ONLINE_JUDGE
    clock_t end = clock();
    cout << "\n\n Executed In: " << double(end - begin) << " secs" << endl;
#endif // !ONLINE_JUDGE

    return 0;
}