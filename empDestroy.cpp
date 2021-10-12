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






int32_t main() {
    clock_t begin = clock();
    FIO
    cpc();
    ll t, q, d;
    cin >> t >> q >> d;
    while (t--) {
        ll lx = (-1LL) * 1e18, ly = lx, rx = 1e18, ry = rx;
        lx--;
        rx++;
        ly--;
        ry++;
        ll curr = 1;
        string cc;
        ll z = -1;
        while (true)
        {
            if (curr == 1)
            {
                if (rx >= (lx + 2) and ry >= (ly + 2))
                {
                    ll midx = lx + (rx - lx) / 2, midy = ly + (ry - ly) / 2;
                    cout << curr << " " << midx << " " << midy << endl;
                    cin >> cc;
                    if (cc.compare("O") == 0 or cc.compare("FAILED") == 0)
                        break;
                    if (cc[0] == 'X') {
                        lx = midx - 1;
                        rx = midx + 1;
                    }
                    else if (cc[0] == 'P') {
                        if (d == 0) {
                            rx = midx - 1;
                        } else {
                            rx = midx;
                            lx--;
                        }
                    } else {
                        if (d == 0) {
                            lx = midx + 1;
                        } else {
                            lx = midx;
                            rx++;
                        }
                    }
                    if (cc[1] == 'Y') {
                        ly = midy - 1;
                        ry = midy + 1;
                    } else if (cc[1] == 'P') {
                        if (d == 0) {
                            ry = midy - 1;
                        } else {
                            ry = midy;
                            ly--;
                        }
                    } else {
                        if (d == 0) {
                            ly = midy + 1;

                        } else {
                            ly = midy;
                            ry++;
                        }
                    }
                    if (d == 0) {

                    } else {
                        if ((rx <= (lx + 3)) and (ry <= (ly + 3)) {
                        curr = 2;
                    }
                }
            }
            else {
                curr = 2;
                cout << curr << " " << lx << " " << ly << " " << rx << " " << ry << endl;
                cin >> cc;
                break;
            }
        }
        else
        {
            if ((rx == (lx + 3)) and (rx == (ly + 3))) {
                    cout << curr << " " << lx << " " << ly << " " << lx + 2 << " " << ry << endl;
                    cin >> cc;
                    if (cc.compare("O") == 0) {
                        break;

                    } else if (cc.compare("IN") == 0) {
                        rx = lx + 2;
                    } else {
                        lx = lx + 2;
                        rx++;
                    }
                }
                if ((rx == (lx + 2)) and (ry == (ly + 3))) {
                    cout << curr << " " << lx << " " << ly << " " << rx << " " << ly + 2 << endl;
                    cin >> cc;
                    if (cc.compare("O") == 0) {

                    } else if (cc.compare("IN") == 0) {
                        cout << curr << " " << lx << " " << ly << " " << rx << " " << ly + 2 << endl;
                        cin >> cc;
                    } else {
                        cout << curr << " " << lx << " " << ly + 2 << " " << rx << " " << ly + 4 << endl;
                        cin >> cc;
                    }
                    break;
                } if ((rx == (lx + 3)) and (ry == (ly + 2))) {
                    cout << curr << " " << lx << " " << ly << " " << lx + 2 << " " << ry << endl;
                    cin >> cc;
                    if (cc.compare("O") == 0) {

                    } else if (cc.compare("IN") == 0) {
                        cout << curr << " " << lx << " " << ly << " " << lx + 2 << " " << ry << endl;
                        cin >> cc;
                    } else {
                        cout << curr << " " << lx + 2 << " " << ly << " " << lx + 4 << " " << ry << endl;
                        cin >> cc;
                    }
                    break;
                }

                else {
                    cout << curr << " " << lx << " " << ly << " " << rx << " " << ry << endl;
                    cin >> cc;
                    break;
                }
                cout.flush();
            }
            cout.flush();
        }
    }





#ifndef ONLINE_JUDGE
    clock_t end = clock();
    cout << "\n\n Executed In: " << double(end - begin) << " secs" << endl;
#endif // !ONLINE_JUDGE

    return 0;
}