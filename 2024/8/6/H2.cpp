#include <bits/stdc++.h>
using namespace std;
#define fo(i,j,k) for(int i=(j),end_i=(k);i<=end_i;i++)
#define ff(i,j,k) for(int i=(j),end_i=(k);i< end_i;i++)
#define fd(i,j,k) for(int i=(j),end_i=(k);i>=end_i;i--)
#define all(x) (x).begin(),(x).end()
#define cle(x) memset(x,0,sizeof(x))
#define lowbit(x) ((x)&-(x))
#define VI vector<int>
#define ll long long
#define ull unsigned ll
#define lll __int128
#define db double
#define lb long db
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define endl "\n"
template<class T>inline void read(T &x) {
    x = 0; char ch = getchar(); bool f = 0;
    for(;ch < '0' || ch>'9';ch = getchar()) f |= (ch == '-');
    for(;ch >= '0' && ch <= '9';ch = getchar()) x = x * 10 + (ch ^ 48);
    if(f) x = -x;
}
template<class T, class... V>
inline void read(T &a, V&... b) { read(a); read(b...); }
#ifndef ONLINE_JUDGE
#define debug(x) cerr<<#x<<"="<<x<<endl
#define debugv(x) cerr<<#x<<" : "; ff(i,0,(x).size()) cerr<<(x)[i]<<(i==(x).size()-1?'\n':' ')
#else
#define debug(x)
#define debugv(x)
#endif
mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count());

#define LOG_LEVEL 0

const int N = 1005;
const int M = 5005;

int n;
string key[N];
map<string, int> mp_key;

map<string, int> mp_str;
int cnt;
vector<string> str_vec;
int get_id(string s) {
    if(mp_str.count(s)) return mp_str[s];
    str_vec.push_back(s);
    return mp_str[s] = cnt++;
}

#define L_TYPE int
struct Line {
    int create_time, delete_time;
    vector<L_TYPE> cons;
    Line(int create_time = 0, vector<L_TYPE> cons = {}) : create_time(create_time), cons(cons) {
        delete_time = -1;
    }
    Line(int create_time, vector<string> cons) : create_time(create_time) {
        delete_time = -1;
        for(auto x : cons) {
            this->cons.push_back(get_id(x));
        }
    }
    void set_delete_time(int delete_time) {
        this->delete_time = delete_time;
    }
    bool valid(int t) {
        return create_time != -1 && create_time <= t && delete_time == -1;
    }
};

bool vis[N * 100];

struct State {
    Line a[M];
    int tot, las_time;
    State() {
        tot = 0;
        las_time = 0;
    }
    void insert(int t, vector<string> s) {
        if(LOG_LEVEL) {
            cout << "LOG :: insert(";
            for(int i = 0; i < n; i++) {
                cout << s[i] << (i == n - 1 ? ")\n" : ",");
            }
        }
        a[++tot] = Line(t, s);
    }
    int del(int t, string _key, vector<L_TYPE> s) {
        if(LOG_LEVEL) {
            cout << "LOG :: delete(" << key << ",{";
            for(auto x : s) {
                cout << x << ",";
            }
            cout << "})\n";
        }
        int del_cnt = 0;

        for(auto x : s)
            vis[x] = 1;

        int key = mp_key[_key];
        for(int i = 1; i <= tot; i++) {
            if(a[i].valid(t) && vis[a[i].cons[key]]) {
                a[i].set_delete_time(t);
                del_cnt++;
            }
        }

        for(auto x : s)
            vis[x] = 0;
        return del_cnt;
    }
    void commit(int t) {
        if(LOG_LEVEL) {
            cout << "LOG :: commit(" << t << ")\n";
        }
    }
    void abort() {
        if(LOG_LEVEL) {
            cout << "LOG :: abort()\n";
        }
        for(int i = 1; i <= tot; i++) {
            if(las_time <= a[i].create_time)
                a[i].create_time = -1;
            if(las_time <= a[i].delete_time)
                a[i].delete_time = -1;
        }
    }
    void set_las_time(int t) {
        if(LOG_LEVEL) {
            cout << "LOG :: begin(" << t << ")\n";
        }
        las_time = t;
    }
    vector<L_TYPE> select(int t, string _key1, string _key2, vector<L_TYPE> s) {
        if(LOG_LEVEL) {
            cout << "LOG :: select(" << _key1 << "," << _key2 << ",{";
            for(auto x : s) {
                cout << x << ",";
            }
            cout << "})\n";
        }
        int key1 = mp_key[_key1], key2 = mp_key[_key2];

        for(auto x : s)
            vis[x] = 1;

        vector<L_TYPE> ans;
        for(int i = 1; i <= tot; i++) {
            if(a[i].valid(t) && vis[a[i].cons[key2]]) {
                ans.push_back(a[i].cons[key1]);
            }
        }

        for(auto x : s)
            vis[x] = 0;
        return ans;
    }
};

State S;

#define ABORT 1
#define BEGIN 2
#define COMMIT 3
#define SELECT 4
#define SELECT_IN 5
#define INSERT 6
#define DELETE 7
#define DELETE_IN 8

map<string, int> mp_type;
void init() {
    mp_type["abort"] = 1;
    mp_type["begin"] = 2;
    mp_type["commit"] = 3;
    mp_type["select"] = 4;
    mp_type["select_in"] = 5;
    mp_type["insert"] = 6;
    mp_type["delete"] = 7;
    mp_type["delete_in"] = 8;
}

int now_time;
vector<L_TYPE> work(string &s) {
    auto x = s.find('(');
    if(x == string::npos) return { get_id(s) };
    int type = mp_type[s.substr(0, x)];
    auto get_next = [&]() {
        return s.find(',', x + 1);
        };
    vector<string> val;
    switch(type) {
        case ABORT:
            S.abort();
            break;
        case BEGIN:
            S.set_las_time(now_time);
            break;
        case COMMIT:
            S.commit(now_time);
            break;
            // SELECT
        case SELECT:
        case SELECT_IN:
            for(int i = 0; i < 2; i++) {
                int y = get_next();
                val.push_back(s.substr(x + 1, y - x - 1));
                x = y;
            }
            val.push_back(s.substr(x + 1, s.size() - x - 2));
            return S.select(now_time, val[0], val[1], work(val[2]));
            break;
        case INSERT:
            for(int i = 0; i < n - 1; i++) {
                int y = get_next();
                val.push_back(s.substr(x + 1, y - x - 1));
                x = y;
            }
            val.push_back(s.substr(x + 1, s.size() - x - 2));
            S.insert(now_time, val);
            break;
        case DELETE:
        case DELETE_IN:
            int y = get_next();
            val.push_back(s.substr(x + 1, y - x - 1));
            x = y;
            val.push_back(s.substr(x + 1, s.size() - x - 2));
            cout << S.del(now_time, val[0], work(val[1])) << endl;
            break;
    }
    return {};
}

int main() {
    freopen("in.txt", "r", stdin);
    init();
    ios::sync_with_stdio(0); cin.tie(0);
    int q;
    cin >> n >> q;
    for(int i = 0; i < n; i++) {
        cin >> key[i];
        mp_key[key[i]] = i;
    }
    for(int i = 1; i <= q; i++) {
        now_time = i;
        string s;
        cin >> s;
        bool flag = (s[0] == 's');
        auto ans = work(s);
        if(flag) {
            cout << ans.size() << endl;
            if(ans.size()) {
                cout << str_vec[ans[0]] << endl << str_vec[ans[(ans.size() - 1) / 2]] << endl << str_vec[ans.back()] << endl;
            }
        }
    }
    return 0;
}