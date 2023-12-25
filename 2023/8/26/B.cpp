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
using namespace std;

int t, n, k, a[100005];

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

int main(){
	//freopen("in", "r", stdin);
    read(t);
    while(t--){
        read(n); read(k);
        For(i, 1, n){
            char c; cin >> c;
            a[i] = c - 'a';
        }
        if(k & 1){
            vector<int> b[2];
            For(i, 1, n) b[i & 1].pb(a[i]);
            sort(b[0].begin(), b[0].end());
            sort(b[1].begin(), b[1].end());
            int o = 1, tt[2] = {0, 0};
            For(i, 1, n){
                printf("%c", 'a' + b[o][tt[o]++]);
                o ^= 1;
            }
            puts("");
        }
        else{
            sort(a + 1, a + n + 1);
            For(i, 1, n) printf("%c", 'a' + a[i]);
            puts("");
        }
    }
}
