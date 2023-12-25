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
#define maxn 200010
using namespace std;

int n1, n2, cnt = 0;
LL p = 0x04C11DB7, e[40];
bool a[32 * maxn + 5], b[40], c[32 * maxn + 5], d[40];

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

int main(){
    // For(i, 1, 32) cout << ((p >> (32 - i)) & 1) << " "; cout << endl;
    // FILE *file = fopen("in.txt", "r");
	// freopen("in.txt", "r", stdin);
    // freopen("out1.txt", "w", stdout);
    read(n1); read(n2);
    // cout << n1 << " " << n2 << endl;
    For(i, 1, n1){
        LL x; read(x);
        For(j, 0, 7) a[++cnt] = ((x >> (7 - j)) & 1);
        // cout << x << " ";
    }
    // cout << endl;
    cnt += 32;
    For(i, 1, n2){
        LL x; read(x);
        For(j, 0, 7) a[++cnt] = ((x >> (7 - j)) & 1);
        // cout << x << " ";
    }
    // cout << endl;
    For(i, 1, 32) b[i] = c[i] = ((p >> (32 - i)) & 1);
    For(i, 0, cnt){
        if(c[i]) For(j, 1, 32) if(i + j <= cnt + 32) c[i + j] ^= b[j];
        if(a[cnt - i]) For(j, 1, 32) if(c[i + j]) e[j] ^= 1ll << 32, d[j] ^= 1;
        if(cnt - i > 8 * n1 && cnt - i <= 8 * n1 + 32){
            For(j, 1, 32) if(c[i + j]) e[j] ^= 1ll << (cnt - i - 8 * n1 - 1);
        }
    }
    // For(i, 1, 32) cout << d[i] << " "; cout << endl;
    // For(i, 1, cnt) if(a[i]){
    //     For(j, 1, 32) d[j] ^= c[cnt + j - i];
    // }
    For(i, 1, 32) e[i] ^= 1ll << (i - 1);
    LL tem[40] = {};
    For(i, 1, 32){
        LL temi = e[i], fl = 0;
        For(j, 0, 31){
            if((temi >> j) & 1) temi ^= tem[j];
            if((temi >> j) & 1){
                For(p, j + 1, 31) if((temi >> p) & 1) temi ^= tem[p];
                For(p, 0, j - 1) if((tem[p] >> j) & 1) tem[p] ^= temi;
                tem[j] = temi;
                fl = 1;
                break;
            }
        }
        if(!fl && temi){
            puts("-1");
            return 0;
        }
    }
    bool as[40] = {};
    For(i, 0, 31) if((tem[i] >> 32) & 1) as[i] = 1;
    // For(i, 1, 32) if(as[i - 1]) For(j, 1, 32) d[j] ^= c[cnt + j - 8 * n1 - i];
    // For(i, 0, 31) cout << as[i] << " "; cout << endl;
    LL asi = 0;
    For(i, 0, 31) if(as[i]) asi |= 1ll << (31 - i);
    printf("%lld\n", asi);
    return 0;
}
