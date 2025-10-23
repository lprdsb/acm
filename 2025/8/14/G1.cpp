#include<bits/stdc++.h>
using namespace std;
#define For(i, a, b) for(int i = (a), en = (b); i <= en; ++i)
#define LL long long
#define inf 0x3f3f3f3f3f

#define maxn 100000
#define B 400
#define P 1000000000
int n, m, q;
LL a[maxn + 5];

struct Node { int id, ch[2], cnt, fa; } poi[2 * maxn + 5];
struct Tree {
    int Rt;
    Tree(int rt) {
        Rt = rt;
        a[rt] = inf;
    }
    void upd(int rt) {
        poi[rt].cnt = 1 + poi[poi[rt].ch[0]].cnt + poi[poi[rt].ch[1]].cnt;
    }
    void rot(int rt) {
        int fa = poi[rt].fa, is_ls = poi[fa].ch[0] == rt;
        poi[poi[poi[fa].fa].ch[poi[poi[fa].fa].ch[1] == fa] = rt].fa = poi[fa].fa;
        poi[poi[fa].ch[!is_ls] = poi[rt].ch[is_ls]].fa = fa;
        poi[poi[rt].ch[is_ls] = fa].fa = rt;
        upd(fa); upd(rt);
    }
    void spy(int x) { while(poi[x].fa != Rt) rot(x); }
    int find(int x) {
        // if(x == 4) cout << "asd" << endl;
        int now = Rt;
        while(poi[now].id != x) {
            int to = a[x] > a[poi[now].id];
            // cout << now << endl;
            if(!poi[now].ch[to]) {
                poi[x] = { x, {0, 0}, 1, now };
                poi[now].ch[to] = x;
            }
            now = poi[now].ch[to];
        }
        spy(now);
        return now;
    }
    void ins(int x) {
        find(x);
    }
    int find_rank(int x) { return poi[poi[find(x)].ch[0]].cnt + 1; }
    int find_index(int x) {
        int now = Rt;
        // cout << x << endl;
        while(666) {
            // cout << now << " " <<  << endl;
            if(x > poi[poi[now].ch[0]].cnt) {
                x -= poi[poi[now].ch[0]].cnt;
                if(x > 1) {
                    x--;
                    now = poi[now].ch[1];
                }
                else break;
            }
            else now = poi[now].ch[0];
        }
        // cout << now << endl;
        spy(now);
        // cout << x << endl;
        return now;
    }
    void del(int x) {
        find(x);
        poi[Rt].cnt--;
        if(!poi[x].ch[0]) {
            poi[Rt].ch[0] = poi[x].ch[1];
            poi[poi[x].ch[1]].fa = Rt;
        }
        else {
            int now = poi[x].ch[0], cnt = 0;
            while(poi[now].ch[1]) now = poi[now].ch[1], cnt++;
            For(i, 2, cnt) rot(now);
            poi[now].ch[1] = poi[x].ch[1];
            poi[poi[x].ch[1]].fa = now;
            poi[now].cnt += poi[poi[x].ch[1]].cnt;
        }
    }
};

int main() {
    freopen("in.txt", "r", stdin);
    scanf("%d%d%d", &n, &m, &q); m++;
    For(i, 1, n) scanf("%d", &a[i]);
    LL as = 0;
    if(m <= B) {
        Tree tr(n + 1);
        For(i, 1, n) tr.ins(i);
        while(q--) {
            LL x, y, z; scanf("%lld%lld%lld", &x, &y, &z);
            x = 1 + (x + as) % n;
            y = 1 + (y + as) % P;
            z = 1 + (z + as) % n;
            tr.del(x);
            a[x] = y;
            tr.ins(x);
            tr.find(1);
            cout << poi[1].cnt << endl;
            // cout << tr.find_rank(4) << endl;
            // For(i, 1, n) cout << tr.find_rank(i) << " "; cout << endl;
            // cout << x << " " << y << " " << z << endl;
            as = 0;
            while(z > 0) {
                // cout << z << endl;
                int idx = tr.find_index(z);
                // cout << z << " " << idx << endl;
                as += a[idx];
                z -= m;
            }
            printf("%lld\n", as);
        }
    }
    else {
        Tree tr(n + 1);
        For(i, 1, n) tr.ins(i);
        while(q--) {
            LL x, y, z; scanf("%lld%lld%lld", &x, &y, &z);
            x = 1 + (x + as) % n;
            y = 1 + (y + as) % P;
            z = 1 + (z + as) % n;
            as = 0;
            while(z > 0) {
                as += a[tr.find_index(z)];
                z -= m;
            }
        }
        printf("%lld\n", as);
    }
}