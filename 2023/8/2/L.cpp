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
#define maxn 100000
using namespace std;

int n, k, a[maxn + 5], b[maxn + 5];
LL as = 0;

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

int cnt[maxn + 5];

priority_queue<pair<int, int> > q;
int main(){
	//freopen("in", "r", stdin);
    read(n); read(k);
    For(i, 1, n){
        read(a[i]);
        if(!cnt[a[i]]) k--;
        cnt[a[i]]++;
    }
    For(i, 1, n) read(b[i]);
    For(i, 1, n) q.push({-b[i], a[i]});
    while(k){
        pair<int, int> now = q.top(); q.pop();
        if(cnt[now.sec] != 1){
            as -= now.fir;
            cnt[now.sec]--;
            k--;
        }
    }
    printf("%lld\n", as);
    return 0;
}
