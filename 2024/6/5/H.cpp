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

int T, n, num[26];
using Vec = vector<pair<vector<char>, int> >;

vector<char> vv;
Vec v;
void sol(Vec &vec) {
    if(vec.size() <= 1) {
        if(vec.size()) For(i, 1, vec[0].sec)  for(auto c : vec[0].fir) printf("%c", c);
        return;
    }
    if(vec.back().sec == 1) {
        for(auto c : vec.back().fir) printf("%c", c);
        return;
    }
    if(vec.back().sec == 2) {
        for(auto c : vec.back().fir) printf("%c", c);
        For(i, 0, vec.size() - 2) {
            For(j, 1, vec[i].sec) for(auto c : vec[i].fir) printf("%c", c);
        }
        for(auto c : vec.back().fir) printf("%c", c);
        return;
    }
    int sum = 0;
    For(i, 0, vec.size() - 2) sum += vec[i].sec;
    if(vec.back().sec >= 2 * (sum + 1)) {
        For(i, 1, vec.back().sec / (sum + 1) - 1) {
            for(auto c : vec.back().fir) printf("%c", c);
            For(j, 0, vec.size() - 2) {
                for(auto c : vec.back().fir) vec[j].fir.pb(c);
            }
        }
        vec.back().sec %= (sum + 1);
        vec.back().sec += sum + 1;
    }
    for(auto c : vec.back().fir) printf("%c", c);
    v.resize(0);
    vv.resize(0);
    int now = vec.back().sec - 1;
    For(i, 0, vec.size() - 2) {
        sum -= vec[i].sec;
        For(j, 1, vec[i].sec / now) for(auto c : vec[i].fir) vv.pb(c);
        if(vec[i].sec % now) {
            vector<char> vvv = vv;
            for(auto c : vec[i].fir) vvv.pb(c);
            for(auto c : vec.back().fir) vvv.pb(c);
            v.pb({ vvv, vec[i].sec % now });
            now -= vec[i].sec % now;
        }
    }
    for(auto c : vec.back().fir) vv.pb(c);
    if(now) v.pb({ vv, now });
    vec = v;
    sol(vec);
}

void mian() {
    read(n);
    For(i, 1, n) {
        char c; cin >> c;
        num[c - 'a']++;
    }
    Vec vec;
    For(i, 0, 25) if(num[i]) {
        vector<char> v;
        v.pb('a' + i);
        vec.pb({ v, num[i] });
    }
    sol(vec); puts("");
    return;
}

int main() {
    // freopen("in.txt", "r", stdin);
    read(T);
    while(T--) {
        mian();
        For(i, 0, 25) num[i] = 0;
    }
}
