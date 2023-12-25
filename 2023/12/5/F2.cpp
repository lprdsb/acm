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

int T, n, m;

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

#define maxn 100000
int a[maxn + 5], in[maxn + 5], as[maxn + 5];
vector<int> b[maxn + 5];

int main(){
	//freopen("in", "r", stdin);
    read(T);
    while(T--){
        read(n); read(m);
        For(i, 1, n) as[i] = i;
        For(i, 1, n){
            int p; read(p);
            b[i].resize(p + 1);
            For(j, 1, p) read(b[i][j]);
        }
        int fl = 0;
        For(i, 2, n){
            For(j, 1, b[i - 1].size() - 1) a[b[i - 1][j]] = 1;
            int fl1 = 1;
            For(j, 1, b[i].size() - 1) if(a[b[i][j]]){
                fl1 = 0;
                break;
            }
            For(j, 1, b[i - 1].size() - 1) a[b[i - 1][j]] = 0;
            if(fl1){
                fl = 1;
                swap(as[i - 1], as[i]);
                break;
            }
        }
        if(!fl) puts("No");
        else{
            puts("Yes");
            For(i, 1, n) printf("%d ", as[i]);
            puts("");
        }
    }
}
