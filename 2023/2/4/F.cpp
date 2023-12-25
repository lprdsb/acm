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

struct Node{
    int len;
    vector<LL> vec;
    LL sol(int l, int r){
        LL asi = 0;
        For(i, l, r) asi = 10 * asi + a[i];
        return asi;
    }
    Node(){}
    Node(int l, int r){
        Rof(i, r, l){
            int to = i - 15;
            if(to < l) to = l;
            vec.pb(sol(to, i));
            i -= 15;
        }
        len = vec.size();
    }
    void init(){
        vec.clear();
        vec.pb(0);
        len = 1;
    }
    void out(){
        Rof(i, len - 1, 0){
            printf(i == len - 1 ? "%lld" : "%016lld", vec[i]);
        }
        puts("");
    }
} as, asi;
Node operator + (Node x, Node y){
    Node as;
    if(x.len < y.len) swap(x, y);
    as = x;
    For(i, 0, y.len - 1) as.vec[i] += y.vec[i];
    For(i, 0, as.len - 2){
        if(as.vec[i] >= 10000000000000000){
            as.vec[i] -= 10000000000000000;
            as.vec[i + 1]++;
        }
    }
    if(as.vec[as.len - 1] >= 10000000000000000){
        as.vec[as.len - 1] -= 10000000000000000;
        as.vec.pb(1);
        as.len++;
    }
    return as;
}
bool operator < (cst Node &x, cst Node &y){
    if(x.len != y.len) return x.len < y.len;
    Rof(i, x.len - 1, 0){
        if(x.vec[i] != y.vec[i]) return x.vec[i] < y.vec[i];
    }
    return 0;
}

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

int opt[maxn + 5];
void dfs(int now, int pos, int len){
    // if(abs(opt[now - 1]) >= 3) return;
    // asi.out();
    if(now > k){
        if(pos != n + 1) return;
        if(asi < as) as = asi;
        return;
    }
    Node tem = asi;
    For(i, -1, 1){
        if(now == 1 && i) continue;
        opt[now] = opt[now - 1] + i;
        if(opt[now] >= 3 || opt[now] <= -3) continue;
        asi = asi + Node(pos, pos + len + opt[now] - 1);
        dfs(now + 1, pos + len + opt[now], len);
        asi = tem;
    }
}

int main(){
	freopen("in.txt", "r", stdin);
    freopen("out2.out", "w", stdout);
    read(t);
    asi.init();
    while(t--){
        read(n); read(k); k++;
        scanf("%s", s + 1);
        For(i, 1, n) a[i] = s[i] - '0';
        as.len = inf;
        dfs(1, 1, n / k - 1);
        dfs(1, 1, n / k);
        dfs(1, 1, n / k + 1);
        dfs(1, 1, n / k + 2);
        // if(n % k) dfs(1, n % k - k, 1, n / k + 1);
        as.out();
    }
    return 0;
}
