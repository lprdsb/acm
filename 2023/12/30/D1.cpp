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

int n = 7;

int num[2][10];
bool chk(int x, int y) {
    For(i, 0, 9) num[0][i] = num[1][i] = 0;
    while(x) {
        num[0][x % 10]++;
        x /= 10;
    }
    while(y) {
        num[1][y % 10]++;
        y /= 10;
    }
    For(i, 0, 9) if(num[0][i] != num[1][i]) return 0;
    return 1;
}

int num1[10005];
vector<int> vec[10005];
int main() {
    //freopen("in", "r", stdin);
    vector<int> as;
    For(i, 1000, 10000) if(i * i >= 1000000 && i * i < 10000000) as.pb(i * i);
    For(i, 0, as.size() - 1) For(j, 0, i) {
        if(chk(as[i], as[j])) num1[i]++, vec[i].pb(as[j]);
    }
    For(i, 0, as.size() - 1) if(num1[i] >= 7) {
        cout << as[i] << " " << num1[i] << endl;
        for(auto j : vec[i]) cout << j << " ";
        cout << endl;
    }
}
