#include<bits/stdc++.h>
#define de fprintf(stderr,"%d \n",__LINE__)
#pragma optimize(2)
#pragma optimize(3)
#pragma optimize("Ofast")
#pragma optimize("inline")
#define int long long
#define fr(i,a,b) for(int i(a),end##i(b);i<=end##i;i++)
#define fd(i,a,b) for(int i(a),end##i(b);i>=end##i;i--)
#define pii pair<int,int>
#define fi first
#define se second
#define mk make_pair
#define pb push_back
using namespace std;
const int mod = 998244353;
const int maxn = 33;
int upd(const int &x) {
    if(x >= mod)return x - mod;
    else if(x < 0)return x + mod;
    return x;
}
void add(int &x, const int &y) {
    x = upd(x + y);
}
int ksm(int x, int k) {
    int ans = 1;
    while(k) {
        if(k & 1)ans = ans * x % mod;
        x = x * x % mod;
        k >>= 1;
    }
    return ans;
}
int jc[10000], inv[10000];
void init(int n) {
    jc[0] = 1;
    fr(i, 1, n)jc[i] = jc[i - 1] * i % mod;
    inv[n] = ksm(jc[n], mod - 2);
    fd(i, n - 1, 0)inv[i] = inv[i + 1] * (i + 1) % mod;
}
int n, m, m0, w;
vector<pii> g[maxn];
int a[62];
int have = 0;
void insert(int x) {
    //printf("ins %lld\n",x);
    fd(i, 60, 0)if(x >> i & 1) {
        if(!a[i]) {
            a[i] = x;
            break;
        }
        else x ^= a[i];
    }
}
int sum;
int S[maxn];
bool pd[maxn];
void dfs(int x, int fa) {
    sum++;
    pd[x] = 1;
#define u g[x][i].fi
#define v g[x][i].se
    fr(i, 0, g[x].size() - 1)if(u != fa) {
        if(!pd[u]) {
            S[u] = S[x] ^ v;
            dfs(u, x);
        }
        else {
            insert(v ^ S[x] ^ S[u]);
        }
    }
#undef u
#undef v
}
int solve1(int n) {
    static int f[1000][62], p[62];
    int cnt = 0;
    fr(i, 0, 60)if(a[i])cnt++;
    f[0][cnt] = 1;
    p[0] = 1;
    fr(i, 1, w)p[i] = upd(p[i - 1] << 1);
    fr(i, 1, n - have)fr(j, 0, w) {
        f[i][j] = ((j ? f[i - 1][j - 1] * (p[w] - p[j - 1]) : 0) + f[i - 1][j] * p[j]) % mod;
    }
    //printf("%lld %lld %lld %lld\n",have,cnt,w,f[n-have][w]);
    return f[n - have][w];
}
vector<int> st;
//map<vector<int>,int> F[2];
int now;
const int base = 131, P = 3803783;
vector<int> F[2][8400];
int N[2];
int H(const vector<int> &A) {
    int s = 0;
    fr(i, 0, A.size() - 1)s = (s * base + A[i]) % P;
    return s;
}
//double all;
int solve2(int n, int m) {
    static int f[2][P];
    static vector<int> B;
    fr(i, 0, P - 1)f[0][i] = f[1][i] = -1;
    f[0][H(st)] = 1;
    F[0][++N[0]] = st;
    //fr(i,0,st.size()-1)printf("%lld ",st[i]);cout<<'\n';
    //cerr<<m;
    fr(r, 1, m) {
        fr(t, 1, N[r & 1]) {
            int id = H(F[r & 1][t]);
            f[r & 1][id] = -1;
        }
        N[r & 1] = 0;
        fr(t, 1, N[r & 1 ^ 1]) {
            //cerr<<t<<'\n';
#define A F[r&1^1][t] 
            int from = H(A);
            //	fprintf(stderr,"%lld[",r);fr(i,0,A.size()-1)fprintf(stderr,"%lld ",A[i]);fprintf(stderr,"]=%lld\n",f[r&1^1][from]*inv[r-1]%mod);
            fr(i, 0, A.size() - 1)fr(j, 0, i - 1) {
                int x = A[i] + A[j];
                int pos = 0;
                fr(k, 0, A.size() - 1)if(k != i && k != j) {
                    if(x && A[k] >= x) {
                        pos = (pos * base + x) % P;
                        x = 0;
                    }
                    pos = (pos * base + A[k]) % P;
                }
                if(x)pos = (pos * base + x) % P;
                if(f[r & 1][pos] == -1) {
                    f[r & 1][pos] = 0;
                    vector<int> B;
                    int x = A[i] + A[j];
                    fr(k, 0, A.size() - 1)if(k != i && k != j) {
                        if(x && A[k] >= x) {
                            B.pb(x);
                            x = 0;
                        }
                        B.pb(A[k]);
                    }
                    if(x)B.pb(x);
                    F[r & 1][++N[r & 1]] = B;
                }
                f[r & 1][pos] = (f[r & 1][pos] + f[r & 1 ^ 1][from] * A[i] % mod * A[j] % mod) % mod;
            }
            int s = 0;
            fr(i, 0, A.size() - 1) {
                add(s, (A[i] * (A[i] - 1) / 2));
            }
            add(s, -now);
            if(s) {
                if(f[r & 1][from] == -1) {
                    f[r & 1][from] = 0;
                    F[r & 1][++N[r & 1]] = A;
                }
                f[r & 1][from] = (f[r & 1][from] + f[r & 1 ^ 1][from] * s) % mod;
            }
#undef A
        }
        now++;
    }
    //printf("so %lld\n",f[m&1][H(vector<int>({n}))]*inv[m]%mod);
    return f[m & 1][H(vector<int>({ n }))] * inv[m] % mod * ksm((1ll << w) % mod, (int)st.size() - 1) % mod;
}

signed main() {
    freopen("in.txt", "r", stdin);
    // freopen("pig.out", "w", stdout);
    cin >> n >> m >> m0 >> w;
    if(m < n - 1) {
        cout << 0;
        return 0;
    }
    init(m - m0);
    fr(i, 1, m0) {
        int x, y, z;scanf("%lld%lld%lld", &x, &y, &z);
        g[x].pb(mk(y, z));
        g[y].pb(mk(x, z));
    }
    have = m0;
    fr(i, 1, n)if(!pd[i]) {
        sum = 0;
        dfs(i, 0);
        st.pb(sum);
        have -= sum - 1;
    }
    sort(st.begin(), st.end());
    now = m0;
    //double T1=clock();
    cout << upd(1ll * solve1(m - n + 1) * solve2(n, m - m0) % mod);
    //printf("%lf\n",(clock()-T1)/CLOCKS_PER_SEC);
    return 0;
}