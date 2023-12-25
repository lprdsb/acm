#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
using ll = long long;
int n,m,sz[N],nsz[N],num[N],kk,dis[90][N],vis[N],tt[N];set<int> st[N];vector<int> v[N];
ll s1[N],s2[N],ans;bool fl[N];
void proc(int s,int pos)
{
vector<int> tt = {s,pos};
while (pos > kk)
{
for (auto &i : v[pos])
if (tt[tt.size() - 2] != i) {tt.push_back(i);pos = i;break;}
}
for (auto &i : tt) vis[i] = 1;
pos = tt[0];int b = tt.back(),len = tt.size() - 1;
int sum = len + dis[pos][b];
for (int i = 1;i < len;i++)
s1[i] = s1[i - 1] + sz[tt[i]],s2[i] = s2[i - 1] + sz[tt[i]] * 1ll * i;
ll ss = 0;
for (int i = 1;i < len;i++)
{
int ed = min(i + sum / 2,len - 1);
ll ss1 = (s2[ed] - s2[i]) - i * (s1[ed] - s1[i]),ss2 = -(s2[len - 1] - s2[ed]) + (sum + i) * (s1[len - 1] - s1[ed]);
ss += (ss1 + ss2) * sz[tt[i]];
}
ans += ss * 2;
for (int i = 1;i < len;i++) fl[tt[i]] = 1;
for (int i = 1;i <= n;i++)
{
if (fl[i]) continue;
int d1 = dis[pos][i],d2 = dis[b][i],pp = min((d2 + len - d1) / 2,len - 1);
ll ss1 = s2[pp] + d1 * s1[pp],ss2 = (s2[pp] - s2[len - 1]) + (d2 + len) * (s1[len - 1] - s1[pp]);
ans += (ss1 + ss2) * sz[i];
}
for (int i = 1;i < len;i++) fl[tt[i]] = 0;
}
void spfa(int s)
{
for (int i = 1;i <= n;i++) dis[s][i] = INT_MAX >> 1;
queue<int> q;q.push(s);dis[s][s] = 0;
while (!q.empty())
{
int nd = q.front();q.pop();
for (auto &i : v[nd])
if (dis[s][i] > dis[s][nd] + 1) dis[s][i] = dis[s][nd] + 1,q.push(i);
}
}
int main ()
{
	freopen("in.txt", "r", stdin);
ios::sync_with_stdio(false);
cin >> n >> m;
for (int i = 1;i <= m;i++)
{
int t1,t2;cin >> t1 >> t2;st[t1].insert(t2);st[t2].insert(t1);
}
queue<int> q;for (int i = 1;i <= n;i++) {sz[i]  =1;if (st[i].size() == 1) q.push(i);}
while (!q.empty())
{
int nd = q.front();q.pop();
for (auto &i : st[nd])
{
st[i].erase(nd);ans += sz[nd] * 2ll * (n - sz[nd]);
sz[i] += sz[nd];if (st[i].size() == 1) q.push(i);
}
st[nd].clear();
}
int cnt = 0;for (int i = 1;i <= n;i++) if (st[i].size() > 2) num[i] = ++cnt;
kk = cnt;for (int i = 1;i <= n;i++) if (st[i].size() == 2) num[i] = ++cnt;
for (int i = 1;i <= n;i++)
{
for (auto &j : st[i]) v[num[i]].push_back(num[j]);
st[i].clear();
}
for (int i = 1;i <= n;i++) nsz[num[i]] = sz[i];
n = cnt;
for (int i = 1;i <= n;i++) sz[i] = nsz[i];
if (!kk) kk = 2;
for (int i = 1;i <= kk;i++)
{
spfa(i);for (int j = 1;j <= n;j++) ans += dis[i][j] * 1ll * sz[i] * sz[j];
}
for (int i = 1;i <= kk;i++)
for (auto &j : v[i]) if (j > kk && !vis[j]) proc(i,j);
cout << ans / 2 << endl;
return 0;
}