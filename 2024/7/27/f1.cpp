#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
#undef INT_MAX
#define INT_MAX 1000000007

int t;
int n, a, b;
int p[N];
int f[N];

class SegTree {
#define ls (i<<1)
#define rs (i<<1|1)
#define mid (l+r>>1)
    public:
    struct Node {
        int v;
    } d[N << 2];
    void push_up(int i) {
        d[i].v = min(d[ls].v, d[rs].v);
    }
    void build(int i, int l, int r) {
        if(l == r) {
            d[i].v = INT_MAX;
            return;
        }
        build(ls, l, mid);
        build(rs, mid + 1, r);
        push_up(i);
    }
    void modify(int i, int l, int r, int p, int x) {
        if(l == r) {
            d[i].v = x;
            return;
        }
        if(p <= mid) {
            modify(ls, l, mid, p, x);
        }
        else {
            modify(rs, mid + 1, r, p, x);
        }
        push_up(i);
    }
    int query(int i, int l, int r, int ql, int qr) {
        if(ql <= l && qr >= r) {
            return d[i].v;
        }
        if(qr <= mid) {
            return query(ls, l, mid, ql, qr);
        }
        if(ql > mid) {
            return query(rs, mid + 1, r, ql, qr);
        }
        return min(query(ls, l, mid, ql, qr), query(rs, mid + 1, r, ql, qr));
    }
} st;

int main() {
    scanf("%d", &t);
    while(t--) {
        scanf("%d%d%d", &n, &a, &b);
        for(int i = 0;i < n;i++) {
            scanf("%d", &p[i]);
        }
        if(a > b)swap(a, b);
        for(int i = 1;i <= n;i++) {
            f[i] = INT_MAX;
        }
        f[a] = 0;
        st.build(1, 1, n);
        priority_queue<pair<int, int>> pq;
        for(int i = a;i >= 1;i--) {
            int tmp = st.query(1, 1, n, i, i + p[i]);
            f[i] = min(f[i], tmp + 1);
            st.modify(1, 1, n, i, f[i]);
            pq.push({ max(1,i - p[i]), i });
            while(!pq.empty()) {
                if(pq.top().first == i) {
                    st.modify(1, 1, n, pq.top().second, INT_MAX);
                    pq.pop();
                }
                else {
                    break;
                }
            }
        }
        while(!pq.empty())pq.pop();
        for(int i = 1;i <= n;i++) {
            int tmp = st.query(1, 1, n, i - p[i], i);
            f[i] = min(f[i], tmp + 1);
            st.modify(1, 1, n, i, f[i]);
            pq.push({ min(n,n - i - p[i]), i });
            while(!pq.empty()) {
                if(pq.top().first == n - i) {
                    st.modify(1, 1, n, pq.top().second, INT_MAX);
                    pq.pop();   
                }
                else {
                    break;
                }
            }
        }
        while(!pq.empty())pq.pop();
        for(int i = n;i >= b;i--) {
            int tmp = st.query(1, 1, n, i, i + p[i]);
            f[i] = min(f[i], tmp + 1);
            st.modify(1, 1, n, i, f[i]);
            pq.push({ max(1,i - p[i]), i });
            while(!pq.empty()) {
                if(pq.top().first == i) {
                    st.modify(1, 1, n, pq.top().second, INT_MAX);
                    pq.pop();
                }
                else {
                    break;
                }
            }
        }
        for(int i = 1;i <= n;i++) {
            printf("%d %d\n", i, f[i]);
        }
        printf("%d\n", f[b]);
    }
    return 0;
}