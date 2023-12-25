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
#define maxn 1000000
using namespace std;

int q, top = 0;
vector<pair<int*, int> > st[maxn + 5];

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

int a[maxn + 5], b[maxn + 5], as[maxn + 5];

int main(){
	// freopen("in.txt", "r", stdin);
    int now = 0;
    For(i, 1, maxn) a[i] = inf;
    read(q);
    For(_, 1, q){
        // cout << &as[2] << endl;
        int x;
        char c; cin >> c;
        if(c == '+'){
            read(x);
            top++;
            st[top].resize(0);

            st[top].pb({&now, now});
            now++;
            // if(_ == 6) cout << as[2] << endl;
            st[top].pb({&as[now], as[now]});
            as[now] = as[now - 1];

            if(a[b[now]] == now){
                st[top].pb({&a[b[now]], a[b[now]]});
                a[b[now]] = inf;
            }
            st[top].pb({&b[now], b[now]});
            b[now] = x;

            if(a[x] > now){
                st[top].pb({&a[x], a[x]});
                a[x] = now;
                st[top].pb({&as[now], as[now]});
                as[now]++;
            }
        }
        else if(c == '-'){
            read(x);
            top++;
            st[top].resize(0);
            st[top].pb({&now, now});
            now -= x;
        }
        else if(c == '!'){
            reverse(st[top].begin(), st[top].end());
            for(auto i : st[top]) *i.fir = i.sec;
            top--;
        }
        else{
            printf("%d\n", as[now]);
            fflush(stdout);
        }
    }
    return 0;
}
