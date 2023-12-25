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

#define maxn 3000000
int n, a[maxn + 5];
struct Node {
    Node* l, * r;
    int pos;
} nod[maxn + 5];

template <class T>
void read(T& x) {
    char ch;
    bool ok;
    for (ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if (ch == '-') ok = 1;
    for (x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
    if (ok) x = -x;
}

int tr[maxn + 5];
void ins(int x) {
    while (x <= n) tr[x]++, x += x & -x;
}
int que(int x) {
    int res = 0;
    while (x) res += tr[x], x -= x & -x;
    return res;
}

int val[maxn + 5];

int bas[maxn + 5], ok[maxn + 5];
vector<int> ind[maxn + 5];
set<int> se[maxn + 5], se1[maxn + 5];
void ins1(int x, int y) {
    auto it = se1[x].find(y);
    if (it != se1[x].end()) se1[x].erase(it);
    else se[x].insert(y);
    ok[y] = 1;
}
void del1(int x, int y) {
    if (!ok[y]) return;
    auto it = se[x].find(y);
    if (it != se[x].end()) se[x].erase(it);
    else se1[x].insert(y);
    ok[y] = 0;
}
int get_sz(int x) {
    return (int)ind[x].size() - bas[x] + (int)se[x].size() - (int)se1[x].size();
}
int que1(int x) {
    if (!get_sz(x)) return -1;
    while (se1[x].size() && bas[x] < ind[x].size() && ind[x][bas[x]] == *se1[x].begin()) {
        bas[x]++;
        se1[x].erase(se1[x].begin());
    }
    int res = -1;
    if (bas[x] < ind[x].size() && (res == -1 || res > ind[x][bas[x]])) res = ind[x][bas[x]];
    if (se[x].size() && (res == -1 || res > *se[x].begin())) res = *se[x].begin();
    return res;
}

vector<int> vec[2];
int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    read(n);
    For(i, 1, n) {
        char c; cin >> c;
        a[i] = c - '0';
    }
    nod[0].r = &nod[1];
    For(i, 1, n) {
        nod[i] = { &nod[i - 1],  &nod[i + 1], i };
    }
    nod[n].r = 0;
    int fl = 0;
    For(o, 1, 20) {
        if (n - que(n) < o) break;
        int now = 0;
        For(i, 1, n) ok[i] = 0;
        Node* l = nod[0].r, * r = &nod[0];
        For(i, 1, o) {
            r = r->r;
            now = (now << 1) | a[r->pos];
        }
        while (r) {
            val[l->pos] = now;
            if (now & (1 << (o - 1))) {
                ind[now].pb(l->pos);
                ok[l->pos] = 1;
            }
            now ^= (a[l->pos] << (o - 1));
            l = l->r;
            r = r->r;
            if (!r) break;
            now = (now << 1) | a[r->pos];
        }
        For(i, (1 << (o - 1)), min(n, (1 << o) - 1)) {
            fl = i;
            int tt = que1(i);
            if (tt != -1) {
                printf("%d %d\n", tt - que(tt), get_sz(i));
                vec[0].resize(0); vec[1].resize(0);
                Node* ll = &nod[tt];
                For(j, 1, o - 1) {
                    ll = ll->l;
                    if (!ll->pos) break;
                    vec[0].pb(ll->pos);
                }
                ll = &nod[tt];
                // if (i == 105049) {
                //     if (o == 17) {
                //         Node* tem = nod[0].r;
                //         while (tem) {
                //             if (tem->pos >= 999800) cout << tem->pos << " ";
                //             tem = tem->r;
                //         } cout << endl;
                //     }
                // }
                For(j, 1, o) {
                    // if (i == 105049) cout << val[tt] << endl;
                    if (val[ll->pos] & (1 << (o - 1))) {
                        del1(val[ll->pos], ll->pos);
                    }
                    ins(ll->pos);
                    ll->l->r = ll->r;
                    if (ll->r) ll->r->l = ll->l;
                    ll = ll->r;
                }
                if (ll) {
                    int now = a[ll->pos];
                    For(j, 1, o - 1) {
                        vec[1].pb(now);
                        ll = ll->r;
                        if (!ll) break;
                        now = (now << 1) | a[ll->pos];
                    }
                }
                int now = 0;
                For(j, 0, (int)vec[0].size() - 1) {
                    now |= (a[vec[0][j]] << j);
                    if (val[vec[0][j]] & (1 << (o - 1))) {
                        del1(val[vec[0][j]], vec[0][j]);
                    }
                    if ((int)vec[1].size() - 1 >= o - (j + 1) - 1) {
                        val[vec[0][j]] = (now << (o - (j + 1))) | vec[1][o - (j + 1) - 1];
                        if (val[vec[0][j]] & (1 << (o - 1))) {
                            ins1(val[vec[0][j]], vec[0][j]);
                        }
                    }
                }
            }
            else puts("-1 0");
        }
    }
    For(i, fl + 1, n) puts("-1 0");
    // cout << (DD)clock() / 1000 << endl;
    return 0;
}
