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

deque<int> dq;

pair<int, int> que(int d) {
    cout << "? " << d << endl;
    int x, y; read(x); read(y);
    return { x, y };
}

void sol(int n) {
    if(n == 1) {
        pair<int, int> tem = que(0);
        dq.push_front(tem.fir);
        return;
    }
    if(n == 2) {
        pair<int, int> tem = que(0), tem1 = que(0);
        dq.push_front(tem.fir); dq.push_front(tem1.fir);
        return;
    }
    pair<int, int> tem = que(n - 2);
    if(tem.sec == 0) {
        pair<int, int> tem1 = que(0);
        sol(n - 2);
        dq.push_front(tem.fir);
        dq.push_front(tem1.fir);
    }
    else {
        sol(n - 1);
        if(tem.sec != dq.front()) dq.push_front(tem.fir);
        else dq.push_back(tem.fir);
    }
}

int T, n;

void mian() {
    read(n);
    dq.resize(0);
    sol(n);
    cout << "! ";
    for(auto i : dq) printf("%d ", i);
    cout << endl;
}

int main() {
    //freopen("in", "r", stdin);
    read(T);
    while(T--) {
        mian();
    }
}
