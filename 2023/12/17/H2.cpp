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

#define maxn 1000000
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
set<int> se[maxn + 5];
vector<int> vec[2];
int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out1.txt", "w", stdout);
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
        Node* l = nod[0].r, * r = &nod[0];
        For(i, 1, o) r = r->r, now = (now << 1) | a[r->pos];
        while (r) {
            val[l->pos] = now;
            se[now].insert(l->pos);
            now ^= (a[l->pos] << (o - 1));
            l = l->r;
            r = r->r;
            if (!r) break;
            now = (now << 1) | a[r->pos];
        }
        For(i, (1 << (o - 1)), min(n, (1 << o) - 1)) {
            fl = i;
            if (se[i].size()) {
                printf("%d %d\n", *se[i].begin() - que(*se[i].begin()), se[i].size());
                vec[0].resize(0); vec[1].resize(0);
                Node* ll = &nod[*se[i].begin()];
                For(j, 1, o - 1) {
                    ll = ll->l;
                    if (!ll->pos) break;
                    vec[0].pb(ll->pos);
                }
                ll = &nod[*se[i].begin()];
                For(j, 1, o) {
                    se[val[ll->pos]].erase(ll->pos);
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
                For(j, 0, vec[0].size() - 1) {
                    now |= (a[vec[0][j]] << j);
                    se[val[vec[0][j]]].erase(vec[0][j]);
                    if ((int)vec[1].size() - 1 >= o - (j + 1) - 1) {
                        // cout << vec[0][j] << " asd " << vec[1][o - (j + 1) - 1] << endl;
                        val[vec[0][j]] = (now << (o - (j + 1))) | vec[1][o - (j + 1) - 1];
                        se[val[vec[0][j]]].insert(vec[0][j]);
                    }
                }
            }
            else puts("-1 0");
            // Node* tem = nod[0].r;
            // while (tem) {
            //     cout << tem->pos << " ";
            //     tem = tem->r;
            // } cout << endl;
            // tem = nod[0].r;
            // while (tem) {
            //     cout << a[tem->pos];
            //     tem = tem->r;
            // } cout << endl;
            // tem = nod[0].r;
            // while (tem) {
            //     cout << val[tem->pos] << " ";
            //     tem = tem->r;
            // } cout << endl;
        }
        For(i, (1 << (o - 1)), min(n, (1 << o) - 1)) se[i].clear();
    }
    For(i, fl + 1, n) puts("-1 0");
    return 0;
}
