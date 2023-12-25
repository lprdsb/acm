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

int n;
char s[maxn + 5];
int tot = 2;
int ch[2 * maxn + 5][26];
int sz[2 * maxn + 5];
vector<int> vec[maxn + 5];

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

int main(){
	//freopen("in", "r", stdin);
    read(n);
    For(i, 1, n){
        scanf("%s", s + 1);
        int len = strlen(s + 1);
        vec[i].resize(len + 1);
        For(j, 1, len) vec[i][j] = s[j] - 'a';
        int now = 1;
        sz[now]++;
        For(j, 1, len){
            if(!ch[now][vec[i][j]]) ch[now][vec[i][j]] = ++tot;
            now = ch[now][vec[i][j]];
            sz[now]++;
        }

        now = 2;
        sz[now]++;
        Rof(j, len, 1){
            if(!ch[now][vec[i][j]]) ch[now][vec[i][j]] = ++tot;
            now = ch[now][vec[i][j]];
            sz[now]++;
        }
    }
    LL res = 0;
    For(i, 1, n){
        int now = 2;
        For(j, 1, vec[i].size() - 1){
            int ok = sz[now] - sz[ch[now][vec[i][j]]];
            res += 1ll * ok * (vec[i].size() - 1 - j + 1);
            now = ch[now][vec[i][j]];
        }

        now = 1;
        Rof(j, vec[i].size() - 1, 1){
            int ok = sz[now] - sz[ch[now][vec[i][j]]];
            res += 1ll * ok * (vec[i].size() - 1 - (vec[i].size() - 1 - j + 1) + 1);
            now = ch[now][vec[i][j]];
        }
    }
    printf("%lld\n", res);
    return 0;
}
