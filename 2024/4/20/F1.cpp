//#pragma GCC optimize("O3")
//#pragma comment(linker, "/STACK:1024000000,1024000000")
#include<bits/stdc++.h>
using namespace std;
function<void(void)> ____ = []() {ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);};
int a, b, n, fa, fb;
vector<pair<pair<int, int>, pair<int, int>>> ret;
ostream& operator << (ostream &os, const pair<pair<int, int>, pair<int, int>> pr) {
    os << pr.first.first * fa << ' ' << pr.first.second * fb << ' ' << pr.second.first * fa << ' ' << pr.second.second * fb;
    return os;
}
void dfs(int ca, int cb, int vert) {
    int dx = a - ca, dy = b - cb;
    if(dx < n and dy < n) {
        if(vert) ret.emplace_back(make_pair(make_pair(ca + dx, cb + n - 1), make_pair(ca - (n - 1 - dx), cb)));
        else ret.emplace_back(make_pair(make_pair(ca, cb - (n - 1 - dy)), make_pair(ca + n - 1, cb + dy)));
        return;
    }
    else if(dx < n) {
        ret.emplace_back(make_pair(make_pair(ca, cb), make_pair(ca + n - 1, cb + n - 1)));
        dfs(a, cb + n, 1);
    }
    else if(dy < n) {
        ret.emplace_back(make_pair(make_pair(ca + n - 1, cb + n - 1), make_pair(ca, cb)));
        dfs(ca + n, b, 0);
    }
    else {
        ret.emplace_back(make_pair(make_pair(ca, cb), make_pair(ca + n - 1, cb + n - 1)));
        if(dx < dy) dfs(ca + n - 1, cb + n, 1);
        else dfs(ca + n, cb + n - 1, 0);
    }
}
void solve() {
    cin >> a >> b >> n;
    a = a * (fa = a < 0 ? -1 : 1);
    b = b * (fb = b < 0 ? -1 : 1);
    ret.clear();
    dfs(0, 0, 1);
    cout << ret.size() << endl;
    for(auto p : ret) cout << p << endl;
}
int main() {
    ____();
    int T; for(cin >> T; T; T--) solve();
    return 0;
}
