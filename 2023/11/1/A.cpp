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
#define maxn 500000
using namespace std;

int T, n, m, a[maxn + 5];

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

vector<int> pos[maxn + 5];

struct Data{
    int l, mex;
};
vector<Data> dat[maxn + 5];

int las[maxn + 5], tr[maxn + 5];
void ins(int x, int y){
    x = maxn - x + 1;
    while(x <= maxn) tr[x] += y, x += x & -x;
}
int que(int x){
    x = maxn - x + 1;
    int res = 0;
    while(x) res += tr[x], x -= x & -x;
    return res;
}


int main(){
	//freopen("in", "r", stdin);
    read(T);
    while(T--){
        read(n); read(m);
        For(i, 1, n){
            read(a[i]);
            pos[a[i]].pb(i);
        }
        For(i, 1, n + 1){
            int pre = 0;
            for(auto j : pos[i]){
                dat[j - 1].pb({pre + 1, i});
                pre = j;
            }
            dat[n].pb({pre + 1, i});
        }
        int res = -inf;
        For(i, 1, n){
            if(las[a[i]]) ins(las[a[i]], -1);
            las[a[i]] = i;
            ins(i, 1);
            for(auto [l, mex] : dat[i]) res = max(res, que(l) - mex);
        }
        printf("%d\n", res);
        For(i, 1, n){
            dat[i].resize(0);
            if(las[a[i]]) ins(las[a[i]], -1);
            las[a[i]] = 0;
            pos[a[i]].resize(0);
        }
    }
}
