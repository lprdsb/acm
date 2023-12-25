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
#define maxn 4000
using namespace std;

int t, n, a[maxn + 5], b[maxn + 5], cnt, mx[maxn + 5];
pair<int, int> opt[maxn + 5];

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

int find(int x){
    int l = 1, r = cnt;
    while(l < r){
        int mid = l + r >> 1;
        if(b[mid] >= x) r = mid;
        else l = mid + 1;
    }
    return l;
}

int main(){
	freopen("in.txt", "r", stdin);
    read(t);
    while(t--){
        read(n);
        cnt = 0;
        For(i, 1, n){
            read(opt[i].fir); read(opt[i].sec);
            b[++cnt] = opt[i].fir;
            b[++cnt] = opt[i].sec + 1;
        }
        sort(b + 1, b + cnt + 1);
        cnt = unique(b + 1, b + cnt + 1) - b - 1;
        For(i, 1, cnt) a[i] = 0;
        For(i, 1, n){
            opt[i].fir = find(opt[i].fir);
            opt[i].sec = find(opt[i].sec + 1) - 1;
            a[opt[i].fir]++;
            a[opt[i].sec + 1]--;
        }
        int as = n;
        For(i, 1, cnt) a[i] += a[i - 1], as = min(as, n - a[i]);
        For(o, 0, n){
            if(o) For(i, opt[o].fir, opt[o].sec) a[i]--;
            // if(o == 5){
            //     cout << opt[o].fir << " " << opt[o].sec << endl;
            //     For(i, 1, cnt) cout << b[i] << " " << a[i] << endl; cout << endl;
            // }
            mx[cnt + 1] = 0;
            Rof(i, cnt, 1) mx[i] = max(mx[i + 1], a[i]);
            int now = 0;
            For(i, 1, cnt){
                now = max(now, a[i]);
                // if(o == 5 && b[i] == 5) cout << now << " " << mx[i] << endl;
                if(!a[i]) as = min(as, n - (o != 0) - now - mx[i]);
            }
            if(o) For(i, opt[o].fir, opt[o].sec) a[i]++;
        }
        printf("%d\n", as);
    }
    return 0;
}
