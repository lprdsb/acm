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

    int n, m, q, a[maxn + 5], tot = 0;
    struct Node{
        int ls, rs, cnt;
    } poi[200 * maxn + 5];
    class Tree{
        public:
            int hd[maxn + 5];
            int build(int rt1, int rt2, int l, int r, int x){
                poi[rt2] = poi[rt1];
                poi[rt2].cnt++;
                if(l == r) return rt2;
                int mid = l + r >> 1;
                if(x <= mid) poi[rt2].ls = build(poi[rt1].ls, ++tot, l, mid, x);
                else poi[rt2].rs = build(poi[rt1].rs, ++tot, mid + 1, r, x);
                return rt2;
            }
            void ins(int tim, int x, int p){
                hd[tim] = build(hd[tim - 1], ++tot, 0, (1 << p) - 1, x);
            }
            int qque(int rt, int ql, int qr, int l, int r){
                if(!rt || (ql <= l && qr >= r)) return poi[rt].cnt;
                int mid = l + r >> 1, asi = 0;
                if(ql <= mid) asi += qque(poi[rt].ls, ql, qr, l, mid);
                if(qr > mid) asi += qque(poi[rt].rs, ql, qr, mid + 1, r);
                return asi;
            }
            int que(int tim1, int tim2, int l, int r, int p){
                if(l <= r) return qque(hd[tim2], l, r, 0, (1 << p) - 1) - qque(hd[tim1 - 1], l, r, 0, (1 << p) - 1);
                else{
                    swap(l, r);
                    l++; r--;
                    int asi = poi[hd[tim2]].cnt - poi[hd[tim1 - 1]].cnt;
                    if(l <= r) asi -= que(tim1, tim2, l, r, p);
                    return asi;
                }
            }
    } tr[19];

    template <class T>
    void read(T &x){
        char ch;
        bool ok;
        for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
        for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
        if(ok) x = -x;
    }

    int main(){
        // freopen("in.txt", "r", stdin);
        read(n); read(m);
        For(i, 1, n){
            int x; read(x);
            a[x] ^= 1;
        }
        For(o, 1, 18){
            int sta = (1 << o) - 1;
            For(i, 1, m){
                if(a[i]) tr[o].ins(i, i & sta, o);
                else tr[o].hd[i] = tr[o].hd[i - 1];
            }
        }
        read(q);
        while(q--){
            int l, r, fl = 0; read(l); read(r);
            For(o, 1, 18){
                int sta = (1 << o) - 1;
                if(tr[o].que(l, r, (l + (1 << (o - 1))) & sta, (l + sta) & sta, o) & 1){
                    fl = 1;
                    break;
                }
            }
            printf(fl ? "A" : "B");
        }
        return 0;
    }
