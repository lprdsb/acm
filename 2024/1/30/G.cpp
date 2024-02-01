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

#define maxn 100
int n, st[maxn + 5][maxn + 5], top[maxn + 5], bot[maxn + 5], ok[maxn + 5];

int main() {
    //freopen("in", "r", stdin);
    read(n);
    LL sum = 0;
    int cnt = 0;
    For(i, 1, n) {
        read(top[i]);
        cnt += top[i];
        bot[i] = 1;
        Rof(j, top[i], 1) read(st[i][j]), sum += st[i][j];
    }
    LL res = 0;
    priority_queue<pair<int, int> > q[2];
    priority_queue<int> qq;
    For(i, 1, n) {
        if(top[i] == 1) qq.push(st[i][1]);
        else {
            ok[i] = 1;
            q[0].push({ st[i][top[i]], i });
            q[1].push({ st[i][1], i });
        }
    }
    For(i, 1, (cnt + 1) >> 1) {
        if(qq.size()) {
            res += qq.top();
            qq.pop();
        }
        else {
            while(st[q[0].top().sec][top[q[0].top().sec]] != q[0].top().fir || !ok[q[0].top().sec]) q[0].pop();
            pair<int, int> pa = q[0].top(); q[0].pop();
            res += st[pa.sec][top[pa.sec]--];
            if(bot[pa.sec] == top[pa.sec]) {
                ok[pa.sec] = 0;
                qq.push(st[pa.sec][bot[pa.sec]]);
            }
            else q[0].push({ st[pa.sec][top[pa.sec]], pa.sec });
        }

        if(qq.size()) qq.pop();
        else {
            if(!q[1].size()) break;
            while(st[q[1].top().sec][bot[q[1].top().sec]] != q[1].top().fir || !ok[q[1].top().sec]) q[1].pop();
            pair<int, int> pa = q[1].top(); q[1].pop();
            if(bot[pa.sec] == top[pa.sec]) {
                ok[pa.sec] = 0;
                qq.push(st[pa.sec][bot[pa.sec]]);
            }
            else q[1].push({ st[pa.sec][bot[pa.sec]], pa.sec });
        }
    }
    printf("%lld %lld\n", res, sum - res);
}
