#include<bits/stdc++.h>
#define fs(i,x,y) for(int i=(x),_=(y);i<=_;++i)
#define fn(i,x,y) for(int i=(x),_=(y);i>=_;--i)
using namespace std;

const int N = 1e5 + 7;
int a, b, c;
int w, h;

bool sol(int a, int b, int c) {
    bool ok = (min(2 * b + 2 * a, 2 * a + c) <= w && max(2 * b + 2 * a, 2 * a + c) <= h) || (min(a + 2 * c + b, 2 * b + a) <= w && max(a + 2 * c + b, 2 * b + a) <= h) || (min(a + b + 2 * c, a + b + c) <= w && max(a + b + 2 * c, a + b + c) <= h) || (min(3 * b + a + c, a + c) <= w && max(3 * b + a + c, a + c) <= h);
    return ok;
}

void solve() {
    scanf("%d%d%d", &a, &b, &c);
    scanf("%d%d", &w, &h);
    if(w > h)swap(w, h);
    bool ok = sol(a, b, c) || sol(a, c, b) || sol(b, a, c) || sol(b, c, a) || sol(c, b, a) || sol(c, a, b);
    if(ok)cout << "Yes" << endl;
    else cout << "No" << endl;
}

int main() {
    solve();
}
