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

int n, m;
char s[maxn + 5]; 

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

int a[maxn + 5];
int rk[maxn + 5], sum[maxn + 5], to[maxn + 5], nto[maxn + 5], rk2[maxn + 5], cnt, ncnt;
int height[maxn + 5];
int lhs[maxn + 5][25], rhs[maxn + 5][25];
void get_rk(){
	For(i, 1, m) sum[i] = 0;
	For(i, 1, n) ++sum[to[i] = a[i] + 1];
	For(i, 1, m) sum[i] += sum[i - 1];
	For(i, 1, n) rk[sum[to[i]]--] = i;
	for(int i = 1; i <= n; i <<= 1){
		cnt = 0;
		For(j, n - i + 1, n) rk2[++cnt] = j;
		For(j, 1, n) if(rk[j] > i) rk2[++cnt] = rk[j] - i;
		For(j, 1, m) sum[j] = 0;
		For(j, 1, n) sum[to[j]]++;
		For(j, 1, m) sum[j] += sum[j - 1];
		Rof(j, n, 1) rk[sum[to[rk2[j]]]--] = rk2[j];
		ncnt = 0;
		For(j, 1, n){
			int tem1 = rk[j - 1] + i > n ? 0 : to[rk[j - 1] + i], tem2 = rk[j] + i > n ? 0 : to[rk[j] + i];
			if(j == 1 || to[rk[j - 1]] != to[rk[j]] || tem1 != tem2) ncnt++;
			nto[rk[j]] = ncnt;
		}
		For(j, 1, n) to[j] = nto[j];
		if(ncnt == n) break;
	}
    int now = 0;
    For(i, 1, n){
        if(to[i] == 1) continue;
        if(now) now--;
        while(a[i + now] == a[rk[to[i] - 1] + now]) now++;
        // if(i == 1) cout << now << " " << to[rk[i] - 1] + now << endl;
        // if(i == 1) cout << to[i] << endl;
        height[to[i]] = now;
    }
    Rof(i, n, 1){
        lhs[i][0] = height[i];
        For(o, 1, 20) if(i + (1 << (o - 1)) <= n) lhs[i][o] = min(lhs[i][o - 1], lhs[i + (1 << (o - 1))][o - 1]);
    }
    For(i, 1, n){
        rhs[i][0] = height[i];
        For(o, 1, 20) if(i - (1 << (o - 1)) >= 1) rhs[i][o] = min(rhs[i][o - 1], rhs[i - (1 << (o - 1))][o - 1]);
    }
}
int get_min(int l, int r){
    int lim = 0, tem = r - l + 1;
    while(tem) lim++, tem >>= 1;
    lim--;
    return min(lhs[l][lim], rhs[r][lim]);
}
int lcp(int _x, int _y){
    int tx = to[_x], ty = to[_y];
    if(tx > ty) swap(tx, ty);
    int len = get_min(tx + 1, ty);
    return len;
}

int res[maxn + 5], ss[maxn + 5];
bool cmp(int _x, int _y){
    if(_x == n || _y == n) return _x == n;
    int len = lcp(_x + 1, _y + 1);
    if(len == n - max(_x, _y)) return _x > _y;
    if(ss[_x + len] - ss[_x]) return a[_x + len + 1] < a[_y + len + 1];
    else return a[_x + len + 1] > a[_y + len + 1];
}

int main(){
	// freopen("in.txt", "r", stdin);
    while(scanf("%d", &n) != EOF){
        scanf("%s", s + 1); m = max(n, 200);
        For(i, 1, n) a[i] = s[i] - 'a';
        Rof(i, n, 1){
            a[i] ^= a[i - 1];
            ss[i] = a[i];
            a[i]++;
        }
        For(i, n + 1, n + 10) a[i] = 4;
        For(i, 1, n) ss[i] += ss[i - 1];
        get_rk();
        // For(i, 1, n) cout << a[i] << " "; cout << endl;
        // For(i, 1, n) cout << rk[i] << " "; cout << endl;
        // For(i, 1, n) cout << height[i] << " "; cout << endl;
        // cout << lcp(2, 5) << endl;
        For(i, 1, n) res[i] = i;
        sort(res + 1, res + n + 1, cmp);
        // printf("%d ", n);
        For(i, 1, n) printf("%d ", res[i]);
        puts("");
    }
	return 0;
}


