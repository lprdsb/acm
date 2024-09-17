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

#define maxn 5000
#define maxm 3000000
int tot = 0, n, q;
struct Item {
    vector<int> key;
    int ok;
} item[maxn + 5];
int tot_sql = 0, tot_hsh = 0;
unordered_map<string, int> ma;
unordered_map<string, int> hsh;
string ihsh[maxm + 5];
unordered_map<int, int> sql[maxn + 5];
int tot_vec = 0;
vector<int> vec[maxm + 5];

vector<string> opt_s;
void opt_spl(string s) {
    opt_s.resize(0);
    opt_s.pb("");
    int fl = 0;
    s.pop_back();
    int cnt = 0;
    for(auto c : s) {
        if(c == '(') cnt++;
        if(c == ')') cnt--;
        if(cnt >= 1) {
            if(cnt == 1 && c == ',') opt_s.pb("");
            else if(cnt != 1 || c != '(') opt_s.back() += c;
        }
    }
}

#define UNI(v) {sort(v.begin(), v.end()); v.erase(unique(v.begin(), v.end()), v.end());}

vector<pair<int*, int> > stk;
vector<int> sol(string &opt) {
    vector<int> sol_res;
    opt_spl(opt);
    auto ss = opt_s;
    if(opt[0] == 'i') {
        int idx = 0;
        for(auto s : ss) {
            if(!hsh.count(s)) {
                hsh[s] = tot_hsh;
                ihsh[tot_hsh] = s;
                tot_hsh++;
                assert(tot_hsh <= maxm);
            }
            int h = hsh[s];
            if(!sql[idx].count(h)) {
                sql[idx][h] = tot_vec++;
                assert(tot_vec <= maxm);
            }
            vec[sql[idx][h]].pb(tot);
            item[tot].key.pb(h);
            idx++;
        }
        // for(auto [k, v] : sql[2]) cout << k << " " << v << endl;
        stk.pb({ &item[tot].ok, 0 });
        item[tot].ok = 1;
        tot++;
        assert(tot <= maxn);
    }
    else if(opt[0] == 's') {
        vector<int> as;
        assert(ma.count(ss[1]));
        int to = ma[ss[1]];
        if(opt[6] == '_') {
            auto se = sol(ss[2]); UNI(se);
            for(auto h : se) if(sql[to].count(h)) for(auto idx : vec[sql[to][h]]) if(item[idx].ok) as.pb(idx);
        }
        else if(hsh.count(ss[2])) {
            int h = hsh[ss[2]];
            if(sql[to].count(h)) for(auto idx : vec[sql[to][h]]) if(item[idx].ok) as.pb(idx);
        }
        UNI(as);
        assert(ma.count(ss[0]));
        to = ma[ss[0]];
        for(auto idx : as) sol_res.pb(item[idx].key[to]);
    }
    else if(opt[0] == 'd') {
        vector<int> as;
        assert(ma.count(ss[0]));
        int to = ma[ss[0]];
        if(opt[6] == '_') {
            auto se = sol(ss[1]); UNI(se);
            for(auto h : se) if(sql[to].count(h)) for(auto idx : vec[sql[to][h]]) if(item[idx].ok) as.pb(idx);
        }
        else if(hsh.count(ss[1])) {
            int h = hsh[ss[1]];
            if(sql[to].count(h)) for(auto idx : vec[sql[to][h]]) if(item[idx].ok) as.pb(idx);
        }
        for(auto idx : as) {
            stk.pb({ &item[idx].ok, 1 });
            item[idx].ok = 0;
        }
        cout << as.size() << endl;
    }
    return sol_res;
}

int main() {
    // freopen("in.txt", "r", stdin);
    read(n); read(q);
    For(i, 1, n) {
        string s; cin >> s;
        assert(!ma.count(s));
        ma[s] = tot_sql++;
    }
    while(q--) {
        string opt; cin >> opt;
        if(opt[0] == 'b' || opt[0] == 'c') stk.resize(0);
        else if(opt[0] == 'a') {
            while(stk.size()) {
                pair<int*, int > pa = stk.back(); stk.pop_back();
                assert(*pa.fir != pa.sec);
                *pa.fir = pa.sec;
            }
        }
        else {
            auto res = sol(opt);
            if(opt[0] == 's') {
                cout << res.size() << endl;
                if(res.size()) cout << ihsh[res[0]] << endl << ihsh[res[(res.size() + 1) / 2 - 1]] << endl << ihsh[res.back()] << endl;
                // for(auto s : res) cout << s << endl;
            }
        }
    }
}
