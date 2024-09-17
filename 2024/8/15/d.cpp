#include<bits/stdc++.h>

const int N = 1e5 + 10;

int t;
int n, m;
double k;
double kpw[N];
int p[N];
bool f[N];

class SegTree {
#define ls (i<<1)
#define rs (i<<1|1)
#define mid (l+r>>1)
    struct Data {
        int x;
        int p;
        int y;
        int s;
    } d[N << 2];

    public:

    void push_down(int i) {
        d[ls].x -= d[i].y;
        d[ls].y += d[i].y;
        d[rs].x -= d[i].y;
        d[rs].y += d[i].y;
        d[i].y = 0;
    }
    void push_up(int i) {
        if()
    }
    void build(int i, int l, int r) {
        if(l == r) {
            d[i].x = n - l;
            d[i].y = 0;
            d[i].p = p[l];
            d[i].s = l;
            return;
        }
        build(ls, l, mid);
        build(rs, mid + 1, r);
    }
    void modify(int i, int l, int r) {
        
    }
}

int main() {
    scanf("%d", &t);
    while(t--) {
        scanf("%d%d%lf", &n, &m, &k);

    }
    return 0;
}