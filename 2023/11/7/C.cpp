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
#define maxn 100000
using namespace std;

#define i128 __int128_t

int T, m;
vector<pair<i128, i128> > vec[maxn + 5];
i128 sc[maxn + 5];

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

int st[1000], top = 0;
void print(i128 x){
    while(x) st[++top] = x % 10, x /= 10;
    if(!top) printf("0");
    while(top) printf("%d", st[top--]);
    puts("");
}

map<i128, pair<i128, i128> > ma;
int main(){
	// freopen("in.txt", "r", stdin);
    read(T);
    For(_, 1, T){
        read(m);
        i128 sl = 0, sr = 0, lpr = 0;
        // if(_ == 1894) cout << (LL)m << endl;
        For(i, 1, m){
            int n;
            LL l, r; read(n); read(l); read(r);
            // if(_ == 1894) cout << (LL)n << " " << (LL)l << " " << (LL)r << endl;
            sc[i] = 0;
            sl += l; sr += r;
            vec[i].resize(n);
            For(j, 0, n - 1){
                LL x; read(x);
                // if(_ == 1894) cout << x << " ";
                vec[i][j].fir = x;
            }
            // if(_ == 1894) cout << endl;
            For(j, 0, n - 1){
                LL x; read(x);
                // if(_ == 1894) cout << x << " ";
                vec[i][j].sec = x;
                sc[i] += x;
            }
            // if(_ == 1894) cout << endl;
            lpr += r;
            for(auto [a, c] : vec[i]){
                if(sc[i] - c <= l){
                    ma[a].fir += l - (sc[i] - c);
                    ma[a].sec += l;
                }
                else if(sc[i] - c <= r) ma[a].sec += sc[i] - c;
                else ma[a].sec += r;
                ma[a].sec -= r;
            }
        }
        // if(T == 10000) continue;
        // print(sc[1]);
        if(sr - sl + 1 >= 2 * maxn) puts("0");
        else{
            i128 res = -1;
            for(i128 i = sl; i <= sr; ++i){
                i128 now = min(i, ma[i].fir) + max((i128)0, i - ma[i].sec - lpr);
                // if(i == 10) cout << (int)now << endl;
                if(res == -1 || now < res) res = now;
                // if(res == 0) cout << (LL)i << endl; 
            }
            print(res);
        }
        ma.clear();
    }
}
