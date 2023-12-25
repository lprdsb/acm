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
#define maxn 10000
using namespace std;

int t, n, a[maxn + 5];
vector<pair<int, int> > as;

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

void opt(int x, int y){
    if(x == y) return;
    if(x > y) swap(x, y);
    as.pb({x, y});
}

vector<int> b, a0, a1;
void sol(){
    Rof(i, b.size() - 1, 1) For(j, 0, i - 1) opt(b[i], b[j]);
}

int main(){
	//freopen("in", "r", stdin);
    read(t);
    while(t--){
        read(n);
        For(i, 1, n){
            char c; cin >> c;
            a[i] = c - '0';
            if(a[i]) a1.pb(i);
            else a0.pb(i);
        }
        For(i, 0, a0.size() - 2) opt(a0[a0.size() - 1], a0[i]);
        For(i, 1, a1.size() - 1) opt(a1[0], a1[i]);
        For(i, 1, n) if(i != a1[0] && i != a0[a0.size() - 1]) b.pb(i);
        sol();
        For(i, 1, a1[0]) opt(i, a1[0]);
        Rof(i, a0.size(), a1[0]) opt(i, a1[0]);
        For(i, a0.size() + 1, a0[a0.size() - 1]) opt(i, a0[a0.size() - 1]);
        Rof(i, n, a0[a0.size() - 1]) opt(i, a0[a0.size() - 1]);
        printf("%d\n", as.size());
        for(auto i : as) printf("%d %d\n", i.fir, i.sec);
        as.resize(0);
        b.resize(0);
        a0.resize(0);
        a1.resize(0);
    }
    return 0;
}
