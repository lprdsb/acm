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

#define ULL unsigned LL
#define maxn 300000
struct BIT : vector<ULL> {
    int len;
    void set_len(int _len) {
        len = _len;
        this->resize(len / 64 + 1);
    }
    void init() { this->resize(0); }
    friend BIT operator ^ (BIT _x, cst BIT &_y) {
        For(i, 0, _x.size() - 1) _x[i] ^= _y[i];
        return _x;
    }
    int popcount() {
        int res = 0;
        for(auto i : *(this)) res += __builtin_popcountll(i);
        return res;
    }
    vector<int> find() {
        int now = 0;
        vector<int> pos;
        for(auto i : *(this)) {
            while(i) pos.pb(now + __builtin_ctzll(i)), i -= i & -i;
            now += 64;
        }
        return pos;
    }
} mask[maxn + 5], sta;

int T, n, m, sum[maxn + 5];

void mian() {
    read(n); read(m);
    For(i, 1, m) mask[i].init(), mask[i].set_len(n);
    For(i, 0, n - 1) For(j, 1, m) {
        char c; cin >> c;
        if(c == '1') mask[j][i / 64] |= 1ull << (i % 64);
    }
    int mxi, mxj, mx = -1;
    For(i, 1, m) {
        For(j, 1, m) if(j != i) {
            sta = mask[j] ^ mask[i];
            int cnt = sta.popcount();
            if(!cnt) {
                For(p, 0, n - 1) sum[p]++;
            }
            else if(cnt == 2) {
                vector<int> pos = sta.find();
                sum[pos[0]]++; sum[pos[1]]++;
            }
        }
        int mmx = 0;
        For(i, 1, n - 1) if(sum[i] > sum[mmx]) mmx = i;
        if(sum[mmx] > mx) {
            mx = sum[mmx];
            mxi = mmx;
            mxj = i;
        }
        For(i, 0, n - 1) sum[i] = 0;
    }
    printf("%d\n", mx + 1);
    For(i, 0, n - 1) {
        if(i == mxi) {
            if((mask[mxj][i / 64] >> (i % 64)) & 1) cout << "0";
            else cout << "1";
        }
        else {
            if((mask[mxj][i / 64] >> (i % 64)) & 1) cout << "1";
            else cout << "0";
        }
    }
    cout << endl;
}

int main() {
    // freopen("in.txt", "r", stdin);
    read(T);
    while(T--) {
        mian();
    }
}
