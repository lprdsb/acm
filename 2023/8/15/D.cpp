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

int t, n, k, a[maxn + 5], lhs[maxn + 5], rhs[maxn + 5];

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

int main(){
	freopen("in.txt", "r", stdin);
    read(t);
    while(t--){
        read(n); read(k);
        For(i, 1, n){
            char c; cin >> c;
            a[i] = c -'0';
        }
        int now = 0;
        For(i, 1, n){
            if(a[i]) now++;
            else now = 0;
            lhs[i] = max(lhs[i - 1], now);
        }
        now = 0;
        rhs[n + 1] = 0;
        Rof(i, n, 1){
            if(a[i]) now++;
            else now = 0;
            rhs[i] = max(rhs[i + 1], now);
        }
        int l = 0, cnt = 0;
        int mx0 = -1, mx1 = 0;
        For(i, 1, n){
            cnt += a[i];
            while(cnt > k) cnt -= a[++l];
            if(i - l > mx0) mx0 = i - l, mx1 = max(lhs[l], rhs[i + 1]);
            else if(i - l == mx0) mx1 = max(mx1, max(lhs[l], rhs[i + 1]));
        }

        now = 0;
        For(i, 1, n){
            if(!a[i]) now++;
            else now = 0;
            lhs[i] = max(lhs[i - 1], now);
        }
        now = 0;
        rhs[n + 1] = 0;
        Rof(i, n, 1){
            if(!a[i]) now++;
            else now = 0;
            rhs[i] = max(rhs[i + 1], now);
        }
        l = 0, cnt = 0;
        int mx00 = -1, mx11 = 0;
        For(i, 1, n){
            cnt += !a[i];
            while(cnt > k) cnt -= !a[++l];
            if(i - l > mx00) mx00 = i - l, mx11 = max(lhs[l], rhs[i + 1]);
            else if(i - l == mx00) mx11 = max(mx11, max(lhs[l], rhs[i + 1]));
        }

        printf("%d ", max(mx0 + mx1, mx00 + mx11));
        For(i, 2, n) printf("%lld ", 1ll * i * mx0 + mx1); puts("");
    }
    return 0;
}
