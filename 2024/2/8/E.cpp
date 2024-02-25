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
int T, n, m;
char s1[maxn + 5], s2[maxn + 5];
vector<int> vec[26];

void mian() {
    read(n); read(m);
    scanf("%s%s", s1 + 1, s2 + 1);
    int k = n - m;
    Rof(i, n, 1) vec[s1[i] - 'a'].pb(i);
    For(i, 1, m) {
        if(!vec[s2[i] - 'a'].size()) {
            puts("NO");
            return;
        }
        int pos = vec[s2[i] - 'a'].back();
        For(o, 0, s2[i] - 'a' - 1) while(vec[o].size() && vec[o].back() <= pos) {
            if(!k) {
                puts("NO");
                return;
            }
            vec[o].pop_back();
            k--;
        }
        vec[s2[i] - 'a'].pop_back();
    }
    puts("YES");
}

int main() {
    // freopen("in.txt", "r", stdin);
    read(T);
    while(T--) {
        mian();
        For(o, 0, 25) vec[o].resize(0);
    }
}
