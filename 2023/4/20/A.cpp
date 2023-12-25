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
#define maxn 50000
using namespace std;

int n, m, bas = 800;
LL as[maxn + 5], sum[maxn + 5];
struct Poi{int x, y, h;} poi[maxn + 5];
bool operator < (cst Poi &x, cst Poi y){
    return x.y < y.y;
}
struct Que{int a, b, c, id; DD k;};
bool operator < (cst Que &x, cst Que &y){
    if(x.a) return x.k < y.k;
    else return (DD)x.c / x.b < (DD)y.c / y.b;
}
vector<Que> vec[2];

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

DD k;
bool cmp(cst Poi &x, cst Poi &y){
    return x.x + x.y * k < y.x + y.y * k;
}

int id[maxn + 5], to[maxn + 5];
priority_queue<pair<DD, int> > q;
void q_push(int x, int y){
    if(poi[x].y == poi[y].y) return;
    DD tem = (DD)(poi[x].x - poi[y].x) / (poi[y].y - poi[x].y);
    if(tem < -1e9) return;
    q.push({-tem, x});
}
void sol(int l, int r){
    k = -1e9;
    sort(poi + l, poi + r + 1, cmp);
    sum[l - 1] = 0;
    For(i, l, r){
        to[i] = id[i] = i;
        sum[i] = sum[i - 1] + poi[i].h;
    }
    For(i, l, r - 1) q_push(i, i + 1);
    int now = 0;
    DD las = -1e9;
    while(q.size()){
        pair<DD, int> pa = q.top(); q.pop();
        if(las + pa.fir > -eps) continue;
        las = -pa.fir;
        while(now < vec[1].size() && vec[1][now].k < -pa.fir){
            int ll = l, rr = r;
            while(ll < rr){
                int mid = ll + rr >> 1;
                if(poi[id[mid]].x + poi[id[mid]].y * vec[1][now].k - (DD)vec[1][now].c / vec[1][now].a > -eps) rr = mid;
                else ll = mid + 1;
            }
            if(poi[id[ll]].x + poi[id[ll]].y * vec[1][now].k - (DD)vec[1][now].c / vec[1][now].a > -eps) ll--;
            as[vec[1][now].id] += sum[ll];
            now++;
        }
        // cout << pa.fir << endl;
        if(to[pa.sec] != r){
            sum[to[pa.sec]] += poi[id[to[pa.sec] + 1]].h - poi[pa.sec].h;
            swap(id[to[pa.sec]], id[to[pa.sec] + 1]);
            to[id[to[pa.sec]]]--;
            to[pa.sec]++;
            if(to[pa.sec] != l + 1) q_push(id[to[pa.sec] - 2], id[to[pa.sec] - 1]);
            if(to[pa.sec] != r) q_push(pa.sec, id[to[pa.sec] + 1]);
        }
    }
    // cout << "asd" << endl;
    while(now < vec[1].size()){
        int ll = l, rr = r;
        while(ll < rr){
            int mid = ll + rr >> 1;
            if(poi[id[mid]].x + poi[id[mid]].y * vec[1][now].k - (DD)vec[1][now].c / vec[1][now].a > -eps) rr = mid;
            else ll = mid + 1;
        }
        if(poi[id[ll]].x + poi[id[ll]].y * vec[1][now].k - (DD)vec[1][now].c / vec[1][now].a > -eps) ll--;
        as[vec[1][now].id] += sum[ll];
        now++;
    }
}

int main(){
	// freopen("in.txt", "r", stdin);
	read(n); read(m);
    For(i, 1, n){
        read(poi[i].x), read(poi[i].y), read(poi[i].h);
        sum[0] += poi[i].h;
    }
    sort(poi + 1, poi + n + 1);
    For(i, 1, m){
        int a, b, c; read(a); read(b); read(c);
        if(!a){
            if(!b){
                if(c > 0) as[i] = sum[0];
            }
            else vec[0].pb({a, b, c, i, 0});
        }
        else vec[1].pb({a, b, c, i, (DD)b / a});
    }
    sort(vec[0].begin(), vec[0].end());
    sort(vec[1].begin(), vec[1].end());
    int now = 0;
    sum[0] = 0;
    for(auto i : vec[0]){
        while(now < vec[0].size() && (DD)i.c / i.b - poi[now].y > eps){
            sum[0] += poi[now].h;
            now++;
        }
        as[i.id] = sum[0];
    }
    for(int o = 1; o <= n; o += bas) sol(o, min(o + bas - 1, n));
    For(i, 1, m) printf("%lld\n", as[i]);
    return 0;
}