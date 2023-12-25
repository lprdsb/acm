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

int n, a[maxn + 5][4], b[4], rest[maxn + 5], mx[2][maxn + 5], sa[maxn + 5], as[maxn + 5][4], ok[maxn + 5][4];
LL tot = 0;

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

int popcnt[20];
LL sum[4 * maxn + 5][3];
bool chk(int sta, int pos, int o, int x){
    int tem = x * popcnt[sta];
    LL res = rest[pos] - ok[pos][o];
    if(tem <= tot) res += tem * sum[tem][0] - sum[tem][1];
    if(tem) res += sum[min(tot, 1ll * tem - 1)][2];
    For(o1, 0, 3){
        if((sta >> o1) & 1) tem -= a[pos][o1];
        else res += b[o1];
    }
    res -= min(tem, rest[pos]);
    For(o1, 0, 3) res -= b[o1];
    return res >= 0;
}

int main(){
	// freopen("in.txt", "r", stdin);
    For(i, 1, 15) popcnt[i] = popcnt[i >> 1] + (i & 1);
    read(n);
    For(i, 1, n) For(o, 0, 3) read(a[i][o]), sa[i] += a[i][o], tot += a[i][o];
    For(o, 0, 3) read(b[o]), tot += b[o];
    For(i, 2, n){
        mx[0][i] = mx[0][i - 1];
        For(o, 0, 3) mx[0][i] = max(mx[0][i], a[i - 1][o]);
    }
    Rof(i, n - 1, 1){
        mx[1][i] = mx[1][i + 1];
        For(o, 0, 3) mx[1][i] = max(mx[1][i], a[i + 1][o]);
    }
    tot /= n;
    For(i, 1, n){
        rest[i] = tot - sa[i];
        For(o, 0, 3){
            ok[i][o] = min(rest[i], b[o]);
            as[i][o] = inf;
        }
    }
    // cout << chk(0, 4) << endl;
    For(sta, 0, 15){
        For(i, 1, n){
            int tem = rest[i];
            For(o, 0, 3) if((sta >> o) & 1) tem += a[i][o];
            sum[tem][0]++;
            sum[tem][1] += tem - rest[i];
            sum[tem][2] += rest[i];
        }
        Rof(i, tot - 1, 0) For(o, 0, 1) sum[i][o] += sum[i + 1][o];
        For(i, 1, tot) sum[i][2] += sum[i - 1][2];
        For(i, 1, n) For(o, 0, 3){
            int l = max(mx[0][i], mx[1][i]), r = a[i][o] + ok[i][o];
            // if(n == 4 && sta == 0 && i == 1) cout << sta << " " << o << " " << i << " " << l << " " << r << endl;
            if(r < l) continue;
            b[o] -= ok[i][o];
            while(l < r){
                int mid = l + r >> 1;
                if(chk(sta, i, o, mid)) r = mid;
                else l = mid + 1;
            }
            as[i][o] = min(as[i][o], a[i][o] + ok[i][o] - l);
            b[o] += ok[i][o];
        }
        For(i, 0, tot) For(o, 0, 2) sum[i][o] = 0;
    }
    For(i, 1, n){
        int res = 0;
        For(o, 0, 3) if(as[i][o] != inf) res = max(res, as[i][o]);
        printf("%d ", res);
    }
    return 0;
}
