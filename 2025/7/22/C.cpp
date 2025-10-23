#include<bits/stdc++.h>
#define For(i, a, b) for(int i = (a), en = (b); i <= en; ++i)
#define Rof(i, a, b) for(int i = (a), en = (b); i >= en; --i)
#define LL long long
#define pb push_back
using namespace std;

#define maxn 200000
int n, q, a[maxn + 5];

#define ls (rt << 1)
#define rs ((rt << 1) | 1)
#define md ((l + r) >> 1)
int val[4 * maxn + 5];
void ins(int rt, int l, int r, int x, int v) {
    if(l == r) {
        // cout << rt << " " << v << endl;
        return void(val[rt] = v);
    }
    if(x <= md) ins(ls, l, md, x, v);
    else ins(rs, md + 1, r, x, v);
    val[rt] = val[ls] | val[rs];
    // cout << rt << " " << l << " " << r << " " << rs << endl;
}
int que(int rt, int l, int r, int ql, int qr) {
    // cout << rt << " " << l << " " << r << " " << val[rt] << endl;
    if(ql <= l && qr >= r) return val[rt];
    int res = 0;
    if(ql <= md) res |= que(ls, l, md, ql, qr);
    if(qr > md) res |= que(rs, md + 1, r, ql, qr);
    return res;
}


int count(int x) {
    return __builtin_popcount(x);
}

int chk(int l, int r) {
    if(r < l) return 0;
    if(!((r - l + 1) & 1)) return 0;
    // cout << que(1, 1, n, l, r) << endl;
    return count(que(1, 1, n, l, r)) & 1;
}

set<int> se[26];
struct Node {
    int res, bas;
    map<int, int> ma;
    void init(int x) {
        ma[0] += maxn;
        res = x * 2;
    }
    int get_id(int x) {
        return (x - bas) / 2;
    }
    int get_res() {
        auto it = --ma.end();
        return it->first;
    }
    void mdy(int x, int v) {
        int to = get_id(x), pre = -1, las = -1;
        auto it = se[a[x]].find(x);
        if(it != se[a[x]].begin()) {
            it--;
            pre = *it;
            int l = (get_id(pre)) * 2 + 1, r = (to - 1) * 2;
            // cout << l << " " << r << endl;
            if(chk(l, r)) {
                ma[r - l + 1]--;
                if(ma[r - l + 1] == 0) ma.erase(r - l + 1);
            }
            it++;
        }
        if(it != se[a[x]].end()) {
            it++;
            las = *it;
            int l = to * 2 + 1, r = (get_id(las) - 1) * 2;
            if(chk(l, r)) {
                ma[r - l + 1]--;
                if(ma[r - l + 1] == 0) ma.erase(r - l + 1);
            }
            it--;
        }
        // cout << pre << " " << las << endl;
        if(pre != -1 && las != -1) {
            int l = get_id(pre) * 2 + 1, r = (get_id(las) - 1) * 2;
            if(chk(l, r)) ma[r - l + 1]++;
        }
        // for(auto [p, v] : ma) cout << p << " " << v << endl;
    }
} node[2];

int get_res() {
    int res = 0;
    For(o, 0, 1) res = max(res, node[o].get_res());
    // cout << que(1, 1, n, 2, 6) << endl;
    For(i, 1, min(n, 5)) For(j, max(i, n - 4), n) if(chk(i, j)) {
        res = max(res, j - i + 1);
        // cout << res << " " << i << " " << j << endl;
    }
    return res;
}


int main() {
    // memset(val, 1, sizeof val);
    For(i, 0, 4 * maxn) val[i] = 1;
    freopen("in.txt", "r", stdin);
    scanf("%d%d", &n, &q);

    node[0].init(n / 2); node[0].bas = 0;
    node[1].init((n - 1) / 2); node[1].bas = 1;
    For(i, 1, n) se[0].insert(i);
    // node[0].mdy(2, 1);
    // cout << get_res() << endl;
    For(i, 1, n) {
        char c; cin >> c;
        a[i] = c - 'a';
        For(o, 0, 1) node[o].mdy(i, a[i]);
        ins(i, 1, n, i, 1 << a[i]);
        se[0].erase(i);
        se[a[i]].insert(i);
    }
    // cout << que(1, 1, n, 2, 6) << endl;
    // ins(1, 1, n, 2, 2);
    // cout << val[9] << endl;
    // cout << chk(, 5) << endl;
    // cout << que(1, 1, n, 2, 6) << endl;
    printf("%d\n", get_res());
    // while(q--) {
    //     int p; char c; scanf("%d", &p); cin >> c;
    //     For(o, 0, 1) node[o].mdy(p, c - 'a');
    //     ins(1, 1, n, p, c - 'a');
    //     printf("%d\n", get_res());
    //     se[a[p]].erase(p);
    //     a[p] = c - 'a';
    //     se[a[p]].insert(p);
    // }
    return 0;
}