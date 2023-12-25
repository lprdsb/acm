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

int n, m, q, a[maxn + 5], b[maxn + 5];

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

set<int> se;
int st[maxn + 5], top = 0;

int main(){
	// freopen("in.txt", "r", stdin);
    read(n); read(m); read(q);
    int cnt = 0;
    For(i, 1, n){
        char c; cin >> c;
        a[i] = c - '0';
        cnt += a[i];
    }
    For(i, 1, n) se.insert(i);
    For(i, 1, m){
        int l, r; read(l); read(r);
        auto it = se.lower_bound(l);
        vector<int> vec;
        while(it != se.end() && *it <= r){
            st[++top] = *it;
            vec.pb(*it);
            it++;
        }
        for(auto j : vec) se.erase(j);
    }
    int as = cnt, now = cnt;
    For(i, 1, min(cnt, top)){
        as -= b[st[i]] != a[st[i]];
        b[st[i]] = 1;
        as += b[st[i]] != a[st[i]];
    }
    while(q--){
        int x; read(x);
        as -= b[x] != a[x];
        a[x] ^= 1;
        as += b[x] != a[x];
        if(a[x]){
            now++;
            if(now <= top){
                as -= b[st[now]] != a[st[now]];
                b[st[now]] = 1;
                as += b[st[now]] != a[st[now]];
            }
        }
        else{
            if(now <= top){
                as -= b[st[now]] != a[st[now]];
                b[st[now]] = 0;
                as += b[st[now]] != a[st[now]];
            }
            now--;
        }
        printf("%d\n", (as - max(0, now - top)) / 2);
    }
    return 0;
}
