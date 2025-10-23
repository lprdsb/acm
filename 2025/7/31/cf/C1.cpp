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

#define maxn 1000
int T, as[maxn + 5], B = 0;
vector<int> p[maxn], val;

char s[maxn + 5] = " )()()()()()())))))((()())))";
int n = strlen(s + 1);

int chk(vector<char> &vec) {
    int now = 0;
    For(i, 0, vec.size() - 1) {
        now += (vec[i] == '(') ? 1 : -1;
        if(now < 0) return 0;
    }
    return now == 0;
}

int que(vector<int> &vec) {
    cout << "? " << vec.size() << " ";
    // for(auto v : vec) cout << v << " "; cout << endl;
    int res = 0;
    For(i, 1, min(100, (int)vec.size())) cout << s[vec[i - 1]]; cout << endl;
    For(l, 0, vec.size() - 1) {
        vector<char> cc;
        For(r, l, vec.size() - 1) {
            cc.push_back(s[vec[r]]);
            res += chk(cc);
        }
    }
    cout << res << endl;
    // read(res);
    return res;
}

void mian() {
    // read(n);
    int l = 1, r = n;
    while(l < r) {
        int md = l + r >> 1;
        vector<int> vec;
        For(i, md, n) vec.push_back(i);
        if(!que(vec)) r = md;
        else l = md + 1;
    }

    vector<int> vec;
    for(int i = 1; i <= n; i += B) {
        vec.resize(0);
        vec.resize(maxn, l);
        int lim = min(n - i + 1, B);
        For(j, 1, lim) for(auto pp : p[j]) vec[pp] = i + j - 1;
        int res = que(vec);
        Rof(j, val.size() - 1, 0) {
            if(res >= val[j]) {
                res -= val[j];
                as[i + j] = 0;
                // cout << val[j] << endl;
            }
            else as[i + j] = 1;
        }
    }
    cout << "! ";
    For(i, 1, n) cout << (as[i] ? ')' : '(');
    cout << endl;
}

int main() {
    //freopen("in", "r", stdin);
    int now = 0, sum = 0;
    For(i, 1, maxn) {
        int tmp = i * (i + 1) / 2;
        if(tmp > sum) {
            if(now + 2 * i + 1 > maxn) break;
            val.push_back(tmp);
            B++;
            For(j, 1, i) {
                p[B].push_back(now + 2 * j - 1);
                p[0].push_back(now + 2 * j);
            }
            now += 2 * i + 1;
            p[0].push_back(now);
            sum += tmp;
        }
    }
    cout << B << endl;
    T = 1;
    // read(T);
    while(T--) {
        mian();
    }
}
