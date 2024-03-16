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
int sss;
int n, a[maxn + 5], ma[12][12], deg[12];
char s[2 * maxn + 5];
int ch[12 * maxn + 5][12], to[12 * maxn + 5], sum[12 * maxn + 5], tot = 1;
int f[1 << 12][12 * maxn + 5], pre[1 << 12][12 * maxn + 5];
short preo[1 << 12][12 * maxn + 5];
// pair<int, int> pre[1 << 12][12 * maxn + 5];
int ttt;

int main() {
    // cout << ((&ttt - &sss) >> 17) << endl;
    // freopen("in.txt", "r", stdin);
    read(n);
    For(i, 1, n) {
        read(a[i]); scanf("%s", s + 1);
        int len = strlen(s + 1);
        For(o1, 0, 11) {
            deg[o1] = 0;
            For(o2, 0, 11) ma[o1][o2] = 0;
        }
        For(j, 1, len - 1) if(s[j] != s[j + 1]) ma[s[j] - 'a'][s[j + 1] - 'a'] = ma[s[j + 1] - 'a'][s[j] - 'a'] = 1;
        int cnt = 0;
        For(o1, 0, 11) {
            For(o2, 0, 11) if(o1 != o2) deg[o1] += ma[o1][o2];
            cnt += deg[o1] != 0;
        }
        int fl = 0;
        For(o1, 0, 11) if(deg[o1] >= 3) {
            fl = 1;
            break;
        }
        if(fl) continue;
        vector<int> st;
        int now = -1;
        For(o, 0, 11) if(deg[o] == 1) now = o;
        while(now != -1) {
            int tem = now;
            now = -1;
            For(o, 0, 11) if(o != tem && ma[tem][o] && (!st.size() || (st.size() && o != st.back()))) now = o;
            st.pb(tem);
        }
        if(st.size() == cnt) {
            now = 1;
            for(auto o : st) {
                if(!ch[now][o]) {
                    ch[now][o] = ++tot;
                }
                now = ch[now][o];
            }
            sum[now] += a[i];
            if(st.size() != 1) {
                reverse(st.begin(), st.end());
                now = 1;
                for(auto o : st) {
                    if(!ch[now][o]) ch[now][o] = ++tot;
                    now = ch[now][o];
                }
                sum[now] += a[i];
            }
        }
    }
    queue<int> q;
    For(o, 0, 11) {
        if(ch[1][o]) {
            q.push(ch[1][o]);
            to[ch[1][o]] = 1;
        }
        else ch[1][o] = 1;
    }
    while(q.size()) {
        int u = q.front(); q.pop();
        For(o, 0, 11) {
            if(ch[u][o]) {
                sum[ch[u][o]] += sum[ch[to[u]][o]];
                to[ch[u][o]] = ch[to[u]][o];
                q.push(ch[u][o]);
            }
            else ch[u][o] = ch[to[u]][o];
        }
    }
    memset(f, -inf, sizeof f); f[0][1] = 0;
    int res = -1;
    int all = (1 << 12) - 1;
    For(mask, 0, (1 << 12) - 2) For(o, 0, 11) if(!((mask >> o) & 1)) For(i, 1, tot) {
        int tem = mask | (1 << o), tt = ch[i][o];
        if(f[tem][tt] < f[mask][i] + sum[tt]) {
            f[tem][tt] = f[mask][i] + sum[tt];
            pre[tem][tt] = i;
            preo[tem][tt] = o;
            if(tem == all) {
                if(res == -1 || f[all][res] < f[all][tt]) res = tt;
            }
        }
    }
    // cout << pre[all][res] << endl;
    int mask = all;
    while(mask) {
        printf("%c", 'a' + preo[mask][res]);
        // for(auto o : st) cout << o << " "; cout << endl;
        int tem = res;
        res = pre[mask][res];
        mask ^= 1 << preo[mask][tem];
    }
    return 0;
}

