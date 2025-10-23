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

#define maxn 2000000
cst int p = 24;
#define maxp (1 << p)
int n, q, a[maxn + 5], l1[maxp + 5], r1[maxp + 5], v1[maxp + 5];

LL pp[maxn + 5];

int tag[maxn + 5];
void ins(int x) {
    int id = x / p, to = (id + 1) * p - 1;
    if(x % p) {
        pp[id] ^= (1 << (to - x + 1)) - 1;
        tag[id + 1] ^= 1;
    }
    else tag[id] ^= 1;
}
void out(int x) {
    Rof(o, p - 1, 0) printf("%d", (x >> o) & 1);
    printf(" ");
}
int que(int x) {
    int id = x / p, to = (id + 1) * p - 1;
    if(x % p) {
        int h = (to - x + 1);
        LL L = (pp[id] & ((1 << h) - 1)) << (p - h), R = pp[id + 1] >> h;
        if(tag[id]) L ^= ((1 << h) - 1) << (p - h);
        if(tag[id + 1] ^ tag[id]) R ^= (1 << (p - h)) - 1;
        // out(pp[id + 1]);// out(R);
        return L | R;
    }
    else {
        if(tag[id]) return pp[id] ^ ((1 << p) - 1);
        return pp[id];
    }
}




int rev[maxp + 5];

int main() {
    // freopen("in.txt", "r", stdin);
    r1[0] = 0;
    For(i, 1, (1 << p) - 1) {
        r1[i] = (i & 1) * r1[i >> 1] + (i & 1);
    }
    For(i, 0, (1 << p) - 1) {
        rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (p - 1));
        l1[i] = r1[rev[i]];
    }

    For(i, 1, (1 << p) - 1) {
        v1[i] = v1[i >> 1];
        if(((i >> (p - 1)) & 1) && l1[i] != p) v1[i] -= (l1[i] + 1) * l1[i] / 2;
        if(!(i & 1)) v1[i] += (r1[i >> 1] + 1) * (r1[i >> 1]) / 2;
    }
    read(n); read(q);
    For(i, 1, n) {
        char c; cin >> c;
        a[i] = c - '0';
    }

    For(i, 1, n) {
        int id = i / p, to = (id + 1) * p - 1;
        pp[id] |= a[i] << (to - i);
    }


    // For(i, 0, n / p) out(pp[i]);
    // cout << endl;
    // out(que(2));
    // cout << endl;

    while(q--) {
        int op; read(op);
        if(op == 1) {
            int l, r; read(l); read(r);
            ins(l); ins(r + 1);
        }
        else {
            // For(i, 0, n / p) out(pp[i]);
            // cout << endl;
            // out(que(2)); puts("");
            int l, A, B; read(l); read(A); read(B);
            LL res = 0, n1 = 0;
            int oa = 0, ob = 0, ida = A / p, idb = B / p;
            For(i, 0, ida - 1) oa ^= tag[i];
            For(i, 0, idb - 1) ob ^= tag[i];
            for(int i = 0; i <= l; i += p) {
                int t = min(i + p - 1, l - 1);

                int aa = que(A + i);
                if(oa) aa ^= (1 << p) - 1;
                int bb = que(B + i);
                if(ob) bb ^= (1 << p) - 1;
                int sta = aa ^ bb;
                sta ^= (1 << p) - 1;
                sta = (sta >> (p - (t - i + 1))) << (p - (t - i + 1));

                // out(aa); out(bb); out(sta); puts("");

                int tl1 = min(t - i + 1, l1[sta]), tr1 = min(t - i + 1, r1[sta]);
                if(tl1 == t - i + 1) n1 += tl1;
                else {
                    res += 1ll * (n1 + tl1 + 1) * (n1 + tl1) / 2 + v1[sta];
                    n1 = tr1;
                }

                oa ^= tag[ida++];
                ob ^= tag[idb++];
            }
            res += 1ll * (n1 + 1) * n1 / 2;
            printf("%lld\n", res);
        }
    }
}
