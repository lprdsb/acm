#include<bits/stdc++.h>
#define fs(i,x,y) for(int i=(x),_=(y);i<=_;++i)
#define fn(i,x,y) for(int i=(x),_=(y);i>=_;--i)
typedef long long ll;
using namespace std;

const int N = 2e5 + 7;
int n, q;
char s[N];
set<int>sl, sr;

void solve() {
    scanf("%d%d", &n, &q);
    scanf("%s", s + 1);
    fs(i, 1, n) {
        if(s[i] == 'L') {
            sl.insert(i);
        }
        else sr.insert(n + 1 - i);
    }
    sl.insert(0), sr.insert(0);
    while(q--) {
        int x;scanf("%d", &x);
        if(s[x] == 'L') {
            sl.erase(sl.find(x));
            sr.insert(n + 1 - x);
            s[x] = 'R';
        }
        else {
            sr.erase(sr.find(n + 1 - x));
            sl.insert(x);
            s[x] = 'L';
        }
        printf("%d\n", max(*sl.rbegin() - (int)sl.size() + 1, *sr.rbegin() - (int)sr.size() + 1));
    }
}

signed main() {
    int T = 1;
    while(T--) {
        solve();
    }
}