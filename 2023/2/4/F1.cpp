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

struct Node{
    int len;
    vector<int> vec;
    Node(){}
    Node(int l, int r){
        len = r - l + 1;
        Rof(i, r, l) vec.pb(a[i]);
    }
    void init(){
        vec.clear();
        vec.pb(0);
        len = 1;
    }
    void out(){
        Rof(i, len - 1, 0) printf("%0d", vec[i]);
        puts("");
    }
} as, asi;
Node operator + (Node x, Node y){
    Node as;
    if(x.len < y.len) swap(x, y);
    as = x;
    For(i, 0, y.len - 1) as.vec[i] += y.vec[i];
    For(i, 0, as.len - 2){
        if(as.vec[i] >= 10){
            as.vec[i] -= 10;
            as.vec[i + 1]++;
        }
    }
    if(as.vec[as.len - 1] >= 10){
        as.vec[as.len - 1] -= 10;
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
void dfs(int now, int sum, int pos, int len){
    /*if(len == 3){
        cout << now << " ";
        asi.out();
    }*/
    if(now > k){
        if(sum) return;
        if(asi < as) as = asi;
        return;
    }
    Node tem = asi;
    For(i, -1, 1){
        opt[now] = opt[now - 1] + i;
        if(opt[now] >= 3 || opt[now] <= -3) continue;
        asi = asi + Node(pos, pos + len + opt[now] - 1);
        dfs(now + 1, sum - opt[now], pos + len + opt[now], len);
        asi = tem;
    }
}

int main(){
	freopen("in.txt", "r", stdin);
    freopen("out1.out", "w", stdout);
    read(t);
    asi.init();
    while(t--){
        read(n); read(k); k++;
        For(i, 1, n){
            char c; cin >> c;
            a[i] = c - '0';
        }
        as.len = inf;
        dfs(1, n % k, 1, n / k);
        if(n % k) dfs(1, n % k - k, 1, n / k + 1);
        as.out();
        // (Node(200, 300) + Node(200, 350)).out();
    }
    return 0;
}