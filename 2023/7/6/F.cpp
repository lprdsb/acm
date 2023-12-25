#include<bits/stdc++.h>
#define For(i, a, b) for(int i = (a), en = (b); i <= en; ++i)
#define Rof(i, a, b) for(int i = (a), en = (b); i >= en; --i)
#define Tra(u, i) for(int i = hd[u]; ~i; i = e[i].net)
#define cst const
#define LL long long
#define DD double
#define LD long double
#define pb push_back
#define mp make_pair
#define fir first
#define sec second
#define inf 0x3f3f3f3f
#define Inf 0x3f3f3f3f3f3f3f3f
#define eps 1e-12
#define maxn 200000
using namespace std;

int t, n, q, a[2 * maxn + 5];

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

vector<pair<LL, int> > se;
vector<pair<LL, int> > asi; 

vector<pair<int, int> > vec;
vector<pair<int, int> > veci;

int tot = 0;

int main(){
	// freopen("in.txt", "r", stdin);
    read(t);
    For(o, 1, t){
        read(n); read(q);
        For(i, 1, n){
            read(a[i]); a[n + i] = a[i];
        }
        vec.resize(0);
        int mx = 0;
        Rof(i, 2 * n, 1){
            veci.resize(0);
            veci.pb({a[i], i});
            int now = a[i];
            for(auto j : vec){
                if((now | j.fir) != now) veci.pb({now | j.fir, j.sec});
                now |= j.fir;
            }
            vec = veci;
            if(i <= n){
                // mx = max(mx, (int)vec.size());
                for(auto j : vec){
                    se.pb({1ll * n * (j.sec - i - (j.sec > n + 1)) + i, j.fir});
                }
            }
        }
        sort(se.begin(), se.end());
        tot += se.size();
        // if(t == 1000){
        //     cout << mx << endl;
        //     return 0;
        // }
        int now = -1;
        for(auto i : se){
            if(i.sec > now) asi.pb(i);
            now = max(now, i.sec);
            // cout << i.fir << " " << i.sec << endl;
        }
        while(q--){
            int v; read(v);
            int l = 0, r = asi.size() - 1;
            while(l < r){
                int mid = l + r >> 1;
                if(asi[mid].sec > v) r = mid;
                else l = mid + 1;
            }
            if(asi[l].sec > v) printf("%lld\n", asi[l].fir);
            else puts("-1");
        }
        se.resize(0);
        asi.resize(0);
    }
    return 0;
}
