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
#define maxn 200000
using namespace std;

int t, n, k, a[maxn + 5];
char s[maxn + 5];

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

int as[2][maxn + 5], len[2];
void add(int l, int r){
    For(i, 1, r - l + 1) as[0][i] += a[r - i + 1];
    if(r - l + 1 > len[0]) len[0] = r - l + 1;
    For(i, 1, len[0]){
        if(as[0][i] >= 10){
            as[0][i] -= 10;
            as[0][i + 1]++;
            if(i == len[0]){
                len[0]++;
                break;
            }
        }
    }
}

bool chk(){
    if(len[0] != len[1]) return len[0] < len[1];
    Rof(i, len[0], 1)
        if(as[0][i] != as[1][i]) return as[0][i] < as[1][i];
    return 0;
}

int opt[10];
void dfs(int now, int sum){
    if(now > k){
        if(n - sum < 0) return;
        if((n - sum) % k) return;
        int bas = (n - sum) / k, pos = 1;
        For(i, 1, len[0]) as[0][i] = 0;
        len[0] = 0;
        For(i, 1, k){
            if(bas + opt[i] < 0) return;
            add(pos, pos + bas + opt[i] - 1);
            pos += bas + opt[i];
        }
        if(chk()){
            len[1] = len[0];
            For(i, 1, len[1]) as[1][i] = as[0][i];
        }
        return;
    }
    For(i, -1, 1){
        opt[now] = opt[now - 1] + i;
        dfs(now + 1, sum + opt[now]);
    }
}

int main(){
	// freopen("in.txt", "r", stdin);
    // freopen("out.out", "w", stdout);
    read(t);
    while(t--){
        read(n); read(k); k++;
        scanf("%s", s + 1);
        For(i, 1, n) a[i] = s[i] - '0';
        len[1] = inf;
        dfs(2, 0);
        Rof(i, len[1], 1) printf("%d", as[1][i]); puts("");
    }
    return 0;
}
