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

int P[2] = {998244353, 1000000007}, bas = 1331;
struct Hint{
    int val[2];
};
Hint operator + (cst Hint &_x, cst Hint &_y){
    Hint res = {{0, 0}};
    For(o, 0, 0) res.val[o] = (1ll * _x.val[o] + _y.val[o]) % P[o];
    return res;
}
Hint operator - (cst Hint &_x, cst Hint &_y){
    Hint res = {{0, 0}};
    For(o, 0, 0) res.val[o] = (1ll * _x.val[o] - _y.val[o] + P[o]) % P[o];
    return res;
}
Hint operator * (cst Hint &_x, cst Hint &_y){
    Hint res = {{0, 0}};
    For(o, 0, 0) res.val[o] = 1ll * _x.val[o] * _y.val[o] % P[o];
    return res;
}
bool operator == (cst Hint &_x, cst Hint &_y){
    For(o, 0, 0) if(_x.val[o] != _y.val[o]) return 0;
    return 1;
}
Hint pw[maxn + 5];
void init(){
    pw[0] = {1, 1};
    For(i, 1, maxn) For(o, 0, 0) pw[i].val[o] = 1ll * pw[i - 1].val[o] * bas % P[o];
}
int a[maxn + 5];
Hint sum[maxn + 5];
void build(){
    For(i, 1, n){
        For(o, 0, 0) sum[i].val[o] = (1ll * bas * sum[i - 1].val[o] % P[o] + a[i]) % P[o];
    }
}
Hint get_val(int l, int r){return sum[r] - pw[r - l + 1] * sum[l - 1];}

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

int res[maxn + 5], ss[maxn + 5];

bool cmp(int _x, int _y){
    int l = 1, r = n - max(_x, _y);
    if(r == 0) return _x == n;
    while(l < r){
        int mid = l + r >> 1;
        if(!(get_val(_x + 1, _x + mid) == get_val(_y + 1, _y + mid))) r = mid;
        else l = mid + 1;
    }
    if(get_val(_x + 1, _x + l) == get_val(_y + 1, _y + l)) return _x > _y;
    if(ss[_x + l - 1] - ss[_x]) return a[_x + l] < a[_y + l];
    else return a[_x + l] > a[_y + l];
}

int main(){
	freopen("in.txt", "r", stdin);
    init();
    while(scanf("%d", &n) != EOF){
        // scanf("%s", s + 1);
        For(i, 1, n){
            // a[i] = s[i] - 'a';
            a[i] = (i >> 1) & 1;
        }
        Rof(i, n, 1){
            a[i] ^= a[i - 1];
            ss[i] = a[i];
            a[i]++;
        }
        // For(i, 1, n) cout << a[i] << " "; cout << endl;
        For(i, 1, n) ss[i] += ss[i - 1];
        build();
        // cout << cmp(5, 4) << endl;
        For(i, 1, n) res[i] = i;
        sort(res + 1, res + n + 1, cmp);
        // For(i, 1, n) printf("%d ", res[i]); puts("");
    }
	return 0;
}


