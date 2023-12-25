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
#define maxn 3000
using namespace std;

int n, m;
int mx[maxn + 5], mn[maxn + 5];

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

int tot = 0;

int main(){
	//freopen("in", "r", stdin);
    memset(mn, inf, sizeof mn);
    read(n); read(m);
    For(i, 1, n){
        For(j, 1, m){
            char c; cin >> c;
            mx[i] = max(mx[i], c - 'a');
            mn[i] = min(mn[i], c - 'a');
        }
    }
    For(i, 1, n){
        int fl = 1;
        For(j, 1, n) if(j != i){
            if(mx[j] <= mn[i]){
                fl = 0;
                break;
            }
        }
        printf("%d", fl);
    }
    return 0;
}
