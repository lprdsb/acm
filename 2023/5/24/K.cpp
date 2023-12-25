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
#define maxn 2000000
#define mod 1000000007
using namespace std;

int t, to_a[maxn + 5], to_b[maxn + 5], to[2 * maxn + 5], n, m, cir_b[maxn + 5];
char a[maxn + 5], b[maxn + 5], s[2 * maxn + 5];

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

bool chk(int x, int y){
    int l = x + 1, r = y;
    if(n >= r - l + 1){
        if(to_b[l] >= r - l + 1){
            if(to_a[r - l + 2] >= n - (r - l + 1)){
                if(to_a[n - (r - l + 1) + 1] >= r - l + 1) return x > y;
                else return a[to_a[n - (r - l + 1) + 1] + 1] < a[n - (r - l + 1) + 1 + to_a[n - (r - l + 1) + 1]];
            }
            else return a[r - l + 2 + to_a[r - l + 2]] < a[to_a[r - l + 2] + 1];
        }
        else return a[to_b[l] + 1] < b[l + to_b[l]];
    }
    else{
        if(cir_b[l] >= r){
            if(to_b[r - n + 1] >= n) return x > y;
            else return b[r - n + 1 + to_b[r - n + 1]] < a[to_b[r - n + 1] + 1];
        }
        else{
            if(to_b[l] >= n){
                // if(cir_b[l] + 1 - n < 0){
                //     For(i, 1, n + m + 1) cout << to[i] << "_";
                // }
                return b[cir_b[l] + 1 - n] < b[cir_b[l] + 1];
            }
            else return a[to_b[l] + 1] < b[l + to_b[l]];
        }
    }
    return 1;
}

int ind[maxn + 5];
void sol(int l, int r){
    if(l == r) return;
    int mid = l + r >> 1;
    sol(l, mid); sol(mid + 1, r);
    vector<int> vec;
    int nowl = l, nowr = mid + 1;
    For(i, l, r){
        if(nowl > mid) vec.pb(ind[nowr++]);
        else if(nowr > r) vec.pb(ind[nowl++]);
        else{
            if(chk(ind[nowl], ind[nowr])) vec.pb(ind[nowl++]);
            else vec.pb(ind[nowr++]);
        }
    }
    For(i, l, r) ind[i] = vec[i - l];
}

void tini(){
    For(i, 1, n) to_a[i] = 0;
    For(i, 1, m) to_b[i] = cir_b[i] = 0;
    For(i, 1, n + m + 1) to[i] = 0;
}

int main(){
	// freopen("in.txt", "r", stdin);
	read(t);
    while(t--){
        scanf("%s %s", a + 1, b + 1); n = strlen(a + 1); m = strlen(b + 1);
        For(i, 1, n) s[i] = a[i];
        s[n + 1] = '%';
        For(i, 1, m) s[n + 1 + i] = b[i];
        int len = n + m + 1, now = 1;
        s[len + 1] = ' ';
        For(i, 2, len){
            to[i] = 0;
            if(now + to[now] - 1 >= i){
                if(i + to[i - now + 1] - 1 <= now + to[now] - 1) to[i] = to[i - now + 1];
                else to[i] = now + to[now] - 1 - i + 1;
            }
            while(s[to[i] + 1] == s[i + to[i]]) to[i]++;
            if(now + to[now] - 1 <= i + to[i] - 1) now = i;
        }
        For(i, 1, n) to_a[i] = to[i]; to_a[n + 1] = 0;
        For(i, 1, m) to_b[i] = to[n + 1 + i]; to_b[m + 1] = 0;
        cir_b[m + 1] = m;
        Rof(i, m, 1){
            if(to_b[i] >= n) cir_b[i] = cir_b[i + n];
            else cir_b[i] = i + to_b[i] - 1;
        }
        For(i, 0, m) ind[i] = i;
        sol(0, m);
        int asi = 0, tem = 1234567, pw = 1;
        For(i, 0, m){
            asi = (asi + 1ll * pw * ind[i]) % mod;
            pw = 1ll * pw * tem % mod;
        }
        printf("%d\n", asi);
        tini();
    } 
    return 0;
}
