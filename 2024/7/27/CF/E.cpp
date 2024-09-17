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
    if(x == -1) exit(0);
}

#define maxn 10000
int T, n, m;
vector<int> ch[maxn + 5];

int f[maxn + 5], fl = 1, tot = 0;
vector<int> vec[2];
void dfs(int u) {
    vec[f[u]].pb(u);
    for(auto v : ch[u]) {
        if(f[v] != -1) {
            if(f[v] == f[u]) {
                fl = 0;
                return;
            }
        }
        else {
            f[v] = !f[u];
            dfs(v);
            if(!fl) return;
        }
    }
}

void mian(int _) {
    read(n);
    assert(n != -1);
    read(m);
    For(i, 1, m) {
        int u, v; read(u); read(v);
        ch[u].pb(v); ch[v].pb(u);
    }
    fl = 1;
    f[1] = 0;
    vec[0].resize(0); vec[1].resize(0);
    dfs(1);
    // For(i, 1, tp) cout << st[i] << " "; cout << endl;
    if(!fl) {
        cout << "Alice" << endl;
        For(i, 1, n) {
            cout << "1 2" << endl;
            int a, b; read(a); read(b);
        }
    }
    else {
        cout << "Bob" << endl;
        // if(T == 1000) {
        //     For(i, 1, n) {
        //         int a, b; read(a); read(b);
        //         cout << i << " " << a << endl;
        //     }
        //     return;
        // }
        int a, b; read(a); read(b);
        int cc[2][2] = { {0, 0}, {0, 0} };
        cc[0][0] = a;
        cout << vec[0].back() << " " << a << endl; vec[0].pop_back();
        if(n == 1) return;

        int aa, bb; read(aa); read(bb);
        if(aa == cc[0][0]) swap(aa, bb);
        cc[1][0] = aa;
        cout << vec[1].back() << " " << aa << endl; vec[1].pop_back();
        if(n == 2) return;

        int to = -1;
        if(!vec[0].size()) {
            to = 1;
            cc[1][1] = 6 - a - aa;
        }
        if(!vec[1].size()) {
            to = 0;
            cc[0][1] = 6 - a - aa;
        }
        For(i, 3, n) {
            // if(_ == 6 && i == 4) exit(0);
            int aaa, bbb; read(aaa); read(bbb);
            assert(aaa <= 3 && bbb <= 3);
            // if(_ == 6 && i == 3) assert(to == -1);
            // if(_ == 6 && i == 4) exit(0);
            if(to != -1) {
                assert(vec[to].size());
                if(aaa != cc[to][0] && aaa != cc[to][1]) swap(aaa, bbb);
                cout << vec[to].back() << " " << aaa << endl; vec[to].pop_back();
            }
            else {
                if(aaa == 6 - a - aa) swap(aaa, bbb);
                if(aaa == cc[0][0] && vec[0].size()) {
                    assert(vec[0].size());
                    cout << vec[0].back() << " " << aaa << endl, vec[0].pop_back();
                    if(!vec[0].size()) {
                        to = 1;
                        cc[1][1] = 6 - a - aa;
                    }
                }
                else {
                    assert(vec[1].size());
                    cout << vec[1].back() << " " << aaa << endl; vec[1].pop_back();
                    if(!vec[1].size()) {
                        to = 0;
                        cc[0][1] = 6 - a - aa;
                    }
                }
            }
            // if(_ == 6 && i == 3) exit(0);
        }
    }
}

int main() {
    //freopen("in", "r", stdin);
    memset(f, -1, sizeof f);
    read(T);
    For(_, 1, T) {
        mian(_);
        For(i, 1, n) {
            ch[i].resize(0);
            f[i] = -1;
        }
        // if(T == 1000 && _ == 6) return 0;
    }
}
