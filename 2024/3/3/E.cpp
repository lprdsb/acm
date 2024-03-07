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
struct Node {
    int x, y, z;
};
vector<Node> as;
vector<int> vec;

void mian() {
    read(n);
    if(n <= 2) puts("0");
    else if(n == 3) puts("1\n1 2 3");
    else if(n == 4) puts("1\n1 3 4");
    else if(n == 5) puts("1\n3 4 5");
    else if(n == 6) puts("2\n1 2 6\n3 4 5");
    else if(n == 7) puts("3\n3 5 7\n5 6 7\n2 3 4");
    else if(n == 8) puts("2\n5 6 7\n1 8 4");
    else if(n == 9) puts("3\n7 8 9\n3 4 5\n1 6 2");
    else if(n == 10) puts("2\n7 8 9\n1 10 6");
    else if(n == 11) puts("3\n9 10 11\n5 6 7\n1 8 4");
    // else if(n == 12) puts("3\n9 10 11\n5 6 7\n12 8 4");
    // else if(n == 13) puts("3\n11 12 13\n7 8 9\n1 10 6");
    else if(n == 23) puts("5\n21 22 23\n17 18 19\n13 14 15\n20 16 1\n2 3 12");
    else {
        int now = n;
        if(now % 4 == 3) {
            as.pb({ 1, 2, now-- });
            vec.pb(now--);
        }
        else if(now % 4 == 2) vec.pb(now--);
        else if(now % 4 == 0) {
            as.pb({ 1, now, now - 1 });
            now -= 2;
            vec.pb(now--);
        }
        while(now > n / 2 || vec.size() % 3) {
            as.pb({ now - 2, now - 1, now });
            vec.pb(now - 3);
            now -= 4;
        }
        // cout << now << endl;
        now = 0;
        while(now < vec.size()) {
            as.pb({ vec[now], vec[now + 1], vec[now + 2] });
            now += 3;
        }
        printf("%d\n", as.size());
        for(auto [x, y, z] : as) printf("%d %d %d\n", x, y, z);
    }
    vec.resize(0);
    as.resize(0);
}

int main() {
    //freopen("in", "r", stdin);
    read(T);
    while(T--) {
        mian();
    }
}
