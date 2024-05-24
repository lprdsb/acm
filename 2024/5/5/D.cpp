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

int T, n;
int cnt = 0;
map<int, int> ma;
void ins(int x, int y) {
    if(ma[x] < 0) cnt--;
    ma[x] += y;
    if(ma[x] < 0) cnt++;
}
vector<int> vec;
void print() {
    sort(vec.begin(), vec.end());
    Rof(i, vec.size() - 1, 1) printf("%d ", vec[i] - vec[i - 1] >> 1);
    if(vec[0]) printf("%d ", vec[0]);
    For(i, 1, vec.size() - 1) printf("%d ", vec[i] - vec[i - 1] >> 1);
    puts("");
}

void mian() {
    read(n);
    For(i, 1, n * (n + 1) / 2 - 1) {
        int x; read(x);
        ma[x]++;
    }
    if(n % 2 == 0) ma[0]++;
    for(auto [k, v] : ma) if(v & 1) vec.pb(k);
    For(i, 0, vec.size() - 1) For(j, 0, vec.size() - 1) {
        int v1 = vec[i], v2 = vec[j];
        if(i != j && v1 && v2) ins(abs(v1 - v2) >> 1, -1);
        ins(v1 + v2 >> 1, -1);
    }
    if(vec.size() == (n + 2) / 2 + 1) {
        For(i, 0, vec.size() - 1) {
            vector<int> vv;
            For(j, 0, vec.size() - 1) {
                int v1 = vec[i], v2 = vec[j];
                if(i != j) {
                    if(v1 && v2) {
                        vv.pb(abs(v1 - v2) >> 1);
                        vv.pb(abs(v1 - v2) >> 1);
                    }
                    vv.pb(v1 + v2 >> 1);
                }
                vv.pb(v1 + v2 >> 1);
            }
            for(auto v : vv) ins(v, 1);
            if(cnt == 1 && ma[vec[i]] == -1) {
                For(j, i, vec.size() - 2) vec[j] = vec[j + 1]; vec.pop_back();
                print();
                return;
            }
            for(auto v : vv) ins(v, -1);
        }
    }
    else {
        int mx = 0;
        for(auto [k, v] : ma) if(v) mx = max(mx, k);
        vec.pb(vec.back() - 2 * (vec.back() - mx));
        print();
        return;
    }
}

int main() {
    // freopen("in.txt", "r", stdin);
    read(T);
    while(T--) {
        mian();
        ma.clear();
        vec.resize(0);
        cnt = 0;
    }
}
