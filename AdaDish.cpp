#include <bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define fo1(i,a,n) for(i=a;i<n;i++)
#define fo2(i,a,n) for(i=a;i<=n;i++)
#define Fo(i,k,n) for(i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)
#define ll long long
#define si(x)	scanf("%d",&x)
#define sl(x)	scanf("%I64d",&x)
#define ss(s)	scanf("%s",s)s
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
#define w(x) int x;cin>>x; while(x--)
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);

typedef pair<int, int>	pii;
typedef pair<ll, ll>	pll;
typedef vector<int>		vi;
typedef vector<ll>		vl;
typedef vector<pii>		vpii;
typedef vector<pll>		vpll;
typedef vector<vi>		vvi;
typedef vector<vl>		vvl;
const int mod = 1000000007;
mt19937  rng(chrono::steady_clock::now().time_since_epoch().count());

ll lcm(int a,int b){
    ll a0 = a;
    ll b0 = b;
    return a0*b0/__gcd(a0,b0);
}
void cpc(){
    
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif // !ONLINE_JUDGE

}

int32_t main(){
    FIO
    cpc();

    int x;
    cin>>x;
    while(x--){
        int n;
        cin>>n;
        vector<int>dishes(n);
        for(int i=0;i<n;i++){
            cin>>dishes[i];
        }
        int b1=0,b2=0;
        sort(dishes.rbegin(),dishes.rend());
        int i=0;
        int ans=0;
        while(i<n){
            if(b1==b2){
                b1+=dishes[i];
            }
            else if(b2<b1){
                b2+=dishes[i];
            }
            else if(b1<b2){
                b1+=dishes[i];
            }
            ans=max(b1,b2);
            i++;

        }
        cout<<ans<<"\n";

    }
    return 0;
}