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
using namespace std;

template <class T>
void read(T& x) {
    char ch;
    bool ok;
    for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
    for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
    if(ok) x = -x;
}

#define maxn 200000
int T, n, a[maxn + 5], ok[maxn + 5], pre[maxn + 5], b[maxn + 5];

vector<int> vec[maxn + 5];

int chk(int x) {
    priority_queue<int> q;
    for(auto i : vec[n + 1]) q.push(i);
    For(i, 1, x) q.pop();
    Rof(i, n, 1) {
        for(auto j : vec[i]) q.push(j);
        if(q.size() && q.top() == i) return 0;
        if(!ok[i]) {
            if(q.size()) {
                pre[i] = q.top();
                q.pop();
            }
            else if(i > a[1]) return 1;
        }
    }
    return 2;
}

void mian() {
    read(n);
    For(i, 1, n) read(a[i]);
    if(a[1] == n + 1) {
        puts("No");
        return;
    }
    ok[a[1]] = 1;
    For(i, 2, n) if(a[i] < a[i - 1]) {
        puts("No");
        return;
    }
    For(i, 2, n) {
        if(a[i] == a[i - 1]) vec[a[i]].pb(i - 1);
        else ok[a[i]] = 1, pre[a[i]] = i - 1;
    }
    int l = 0, r = vec[n + 1].size();
    while(l < r) {
        int md = l + r >> 1;
        if(chk(md)) r = md;
        else l = md + 1;
    }
    // cout << chk(0) << endl;
    if(chk(l) != 2) puts("No");
    else {
        // For(i, 1, n) cout << pre[i] << " "; cout << endl;
        puts("Yes");
        For(i, 1, n) printf("%d ", b[i] = (pre[i] ? b[pre[i]] : i));
        puts("");
    }
}

int main() {
    // freopen("in.txt", "r", stdin);
    read(T);
    while(T--) {
        mian();
        For(i, 1, n + 1) {
            vec[i].resize(0);
            ok[i] = pre[i] = 0;
        }
    }
}
