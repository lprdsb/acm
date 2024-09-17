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

#define maxn 3000
int tot = 0, n, q;
struct Item {
    vector<string> key;
    int ok;
} item[maxn + 5];
unordered_map<string, int> ma;
int tot_sql = 0;
unordered_map<string, int> sql[maxn + 5];
int tot_vec = 0;
vector<int> vec[maxn + 5];

vector<string> opt_s;
void opt_spl(string s) {
    opt_s.resize(0);
    opt_s.pb("");
    string tem = "";
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

void uni(vector<string> &sor) {
    unordered_set<string> se;
    for(auto s : sor) se.insert(s);
    sor.resize(0);
    for(auto s : se) sor.pb(s);
}

vector<pair<int*, int> > stk;
vector<string> sol(string &opt) {
    // cout << opt << endl;
    vector<string> sol_res;
    opt_spl(opt);
    if(opt[0] == 'i') {
        tot++;
        vector<string> key;
        int idx = 0;
        for(auto s : opt_s) {
            if(!sql[idx].count(s)) sql[idx][s] = tot_vec++;
            vec[sql[idx][s]].pb(tot);
            key.pb(s);
            idx++;
        }
        // for(auto [k, v] : sql[2]) cout << k << " " << v << endl;
        item[tot] = { key, 1 };
        stk.pb({ &item[tot].ok, 0 });
    }
    else if(opt[0] == 's') {
        vector<int> as;
        auto ss = opt_s;
        if(opt[6] == '_') {
            auto se = sol(ss[2]);
            uni(se);
            for(auto s : se) if(sql[ma[ss[1]]].count(s)) {
                for(auto idx : vec[sql[ma[ss[1]]][s]]) if(item[idx].ok) as.pb(idx);
            }
        }
        else {
            if(sql[ma[ss[1]]].count(ss[2])) {
                for(auto idx : vec[sql[ma[ss[1]]][ss[2]]]) if(item[idx].ok) as.pb(idx);
            }
        }
        sort(as.begin(), as.end());
        as.erase(unique(as.begin(), as.end()), as.end());
        for(auto idx : as) sol_res.pb(item[idx].key[ma[ss[0]]]);
    }
    else if(opt[0] == 'd') {
        int cnt = 0;
        if(opt[6] == '_') {
            auto ss = opt_s;
            // for(auto s : ss) cout << s << " "; cout << endl;
            auto se = sol(ss[1]);
            uni(se);
            // for(auto s : se) cout << s << " "; cout << endl;
            for(auto s : se) if(sql[ma[ss[0]]].count(s)) {
                for(auto idx : vec[sql[ma[ss[0]]][s]]) if(item[idx].ok) {
                    stk.pb({ &item[idx].ok, 1 });
                    item[idx].ok = 0;
                    cnt++;
                }
            }
        }
        else {
            if(sql[ma[opt_s[0]]].count(opt_s[1])) {
                for(auto idx : vec[sql[ma[opt_s[0]]][opt_s[1]]]) if(item[idx].ok) {
                    stk.pb({ &item[idx].ok, 1 });
                    item[idx].ok = 0;
                    cnt++;
                }
            }
        }
        cout << cnt << endl;
    }
    // cout << opt << endl;
    // for(auto s : sol_res) cout << s << " "; cout << endl;
    return sol_res;
}

int main() {
    // freopen("in.txt", "r", stdin);
    read(n); read(q);
    For(i, 1, n) {
        string s; cin >> s;
        ma[s] = tot_sql++;
    }
    while(q--) {
        string opt; cin >> opt;
        if(opt[0] == 'b') {
            stk.resize(0);
        }
        else if(opt[0] == 'c') {
            stk.resize(0);
        }
        else if(opt[0] == 'a') {
            while(stk.size()) {
                pair<int*, int > pa = stk.back(); stk.pop_back();
                *pa.fir = pa.sec;
            }
        }
        else {
            auto res = sol(opt);
            if(opt[0] == 's') {
                cout << res.size() << endl;
                if(res.size()) cout << res[0] << endl << res[(res.size() + 1) / 2 - 1] << endl << res.back() << endl;
                // for(auto s : res) cout << s << endl;
            }
        }
    }
}
