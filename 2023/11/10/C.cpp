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

int n, a[maxn + 5][10];

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

char s[100];
int cnt[15][105], len[maxn + 5];

int main(){
	//freopen("in", "r", stdin);
    read(n);
    For(i, 1, n){
        scanf("%s", s + 1);
        len[i] = strlen(s + 1);
        For(j, 1, len[i]){
            a[i][j] = a[i][j - 1] + s[j] - '0';
        }
        cnt[len[i]][a[i][len[i]]]++;
    }
    LL res = 0;
    For(i, 1, n){
        For(j, 1, len[i] - 1) if(!((len[i] + j) & 1)){
            int tem = (len[i] + j) >> 1;
            if(a[i][tem] > a[i][len[i]] - a[i][tem]) res += cnt[j][2 * a[i][tem] - a[i][len[i]]];
            if(a[i][len[i]] - a[i][len[i] - tem] > a[i][len[i] - tem]) res += cnt[j][a[i][len[i]] - 2 * a[i][len[i] - tem]];
        }
    }
    // cout << res << endl;
    For(i, 1, 10) For(j, 1, 100) res += 1ll * cnt[i][j] * cnt[i][j];
    printf("%lld\n", res);
    return 0;
}
