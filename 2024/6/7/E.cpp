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

#define maxn 200000
int T, n, d;
pair<int, int> poi[maxn + 5];
map<int, vector<int> > ma[2];

void mian() {
    read(n); read(d);
    For(i, 1, n) {
        read(poi[i].fir), read(poi[i].sec);
        ma[0][poi[i].fir + poi[i].sec].pb(i);
        ma[1][poi[i].fir - poi[i].sec].pb(i);
    }
    For(o, 0, 1) for(auto &[k, v] : ma[o]) sort(v.begin(), v.end(), [](cst int &x, cst int &y) {return poi[x].fir < poi[y].fir;});
    for(auto &[k, v] : ma[0]) {
        if(ma[0].count(k - d)) {
            int now = 0, l = 0, r = 0;
            vector<int> &vv = ma[0][k - d];
            for(auto id : vv) {
                while(now < vv.size() && poi[vv[now]].fir < poi[id].fir + d / 2) now++;
                if(now < vv.size() && poi[vv[now]].fir == poi[id].fir + d / 2) {
                    while(l < v.size() && poi[v[l]].fir < poi[vv[now]].fir) l++;
                    while(r < v.size() && poi[v[r]].sec >= poi[id].sec) r++;
                    if(l < r) {
                        printf("%d %d %d\n", v[l], id, vv[now]);
                        return;
                    }
                }
            }
        }
        if(ma[0].count(k + d)) {
            int now = 0, l = 0, r = 0;
            vector<int> &vv = ma[0][k + d];
            for(auto id : vv) {
                while(now < vv.size() && poi[vv[now]].fir < poi[id].fir + d / 2) now++;
                if(now < vv.size() && poi[vv[now]].fir == poi[id].fir + d / 2) {
                    while(l < v.size() && poi[v[l]].sec > poi[vv[now]].sec) l++;
                    while(r < v.size() && poi[v[r]].fir <= poi[id].fir) r++;
                    if(l < r) {
                        printf("%d %d %d\n", v[l], id, vv[now]);
                        return;
                    }
                }
            }
        }
    }

    for(auto &[k, v] : ma[1]) {
        // if(k == 4) cout << v.size() << endl;
        if(ma[1].count(k + d)) {
            int now = 0, l = 0, r = 0;
            vector<int> &vv = ma[1][k + d];
            for(auto id : vv) {
                while(now < vv.size() && poi[vv[now]].fir < poi[id].fir + d / 2) now++;
                if(now < vv.size() && poi[vv[now]].fir == poi[id].fir + d / 2) {
                    while(l < v.size() && poi[v[l]].sec < poi[vv[now]].sec) l++;
                    while(r < v.size() && poi[v[r]].fir <= poi[id].fir) r++;
                    if(l < r) {
                        printf("%d %d %d\n", v[l], id, vv[now]);
                        return;
                    }
                }
            }
        }
        if(ma[1].count(k - d)) {
            int now = 0, l = 0, r = 0;
            vector<int> &vv = ma[1][k - d];
            for(auto id : vv) {
                while(now < vv.size() && poi[vv[now]].fir < poi[id].fir + d / 2) now++;
                if(now < vv.size() && poi[vv[now]].fir == poi[id].fir + d / 2) {
                    while(l < v.size() && poi[v[l]].fir < poi[vv[now]].fir) l++;
                    while(r < v.size() && poi[v[r]].sec <= poi[id].sec) r++;
                    if(l < r) {
                        printf("%d %d %d\n", v[l], id, vv[now]);
                        return;
                    }
                }
            }
        }
    }
    puts("0 0 0");
}

int main() {
    // freopen("in.txt", "r", stdin);
    read(T);
    while(T--) {
        mian();
        ma[0].clear();
        ma[1].clear();
    }
}
