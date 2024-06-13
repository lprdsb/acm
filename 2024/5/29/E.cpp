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

#define maxn 10000
int T, n, m, vis[maxn + 5];

int que(int x, int y) {
    if(x > y) swap(x, y);
    cout << "? " << x << " " << y << endl;
    char s[20]; cin >> s;
    assert(s[0] != '-');
    return s[0] == 'Y';
}

void mian() {
    read(n);
    For(i, 1, n) vis[i] = 0;
    int pre = 1, now = 2;
    while(now <= n && que(now, pre)) pre = now++;
    if(now > n) {
        cout << "!";
        For(i, 1, n) cout << " 0"; cout << endl;
        return;
    }
    vis[now] = 1;
    int p1 = pre, p2 = now, fl = 0;
    For(i, now + 1, n) {
        if(fl) {
            int q1 = que(i, i - 1), q2 = que(i, p2);
            if(!q1 && !q2) {
                For(j, max(p1, p2) + 1, i - 1) vis[j] = 1;
                p1 = i;
                p2 = i - 1;
                fl = 0;
            }
            else if(!q1) {
                p1 = i - 1; p2 = i; vis[i] = 1;
                fl = 0;
            }
            else if(!q2) {
                p1 = i;
                fl = 0;
            }
        }
        else {
            int q1 = que(i, p1), q2 = que(i, p2);
            if(q1 && q2) fl = 1;
            else if(!q1) {
                vis[i] = 1;
                p2 = i;
            }
            else p1 = i;
        }
    }
    cout << "!";
    For(i, 1, n) cout << " " << vis[i]; cout << endl;
}

int main() {
    //freopen("in", "r", stdin);
    read(T);
    while(T--) {
        mian();
    }
}
