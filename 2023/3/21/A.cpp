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

int n, m;

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

int ball[55][405], mx[55][405], mn[55][405];
vector<pair<int, int> > as;
void chkmn(int &x, int y){if(x > y) x = y;}
void chkmx(int &x, int y){if(x < y) x = y;}
void move(int x, int y){
    ball[y][++ball[y][0]] = ball[x][ball[x][0]--];
    mn[y][ball[y][0]] = min(mn[y][ball[y][0] - 1], ball[y][ball[y][0]]);
    mx[y][ball[y][0]] = max(mx[y][ball[y][0] - 1], ball[y][ball[y][0]]);
    as.pb({x, y});
}
int ok[2][405];
vector<pair<int, int> > pa;
void opt(int x, int y){
    memset(ok, 0, sizeof ok);
    pa.clear();
    For(i, 1, m) pa.pb({ball[x][i], i});
    For(i, 1, m) pa.pb({ball[y][i], m + i});
    sort(pa.begin(), pa.end());
    For(i, 1, m){
        if(pa[i - 1].sec <= m) ok[0][pa[i - 1].sec] = 1;
        if(pa[m + i - 1].sec > m) ok[1][pa[m + i - 1].sec - m] = 1;
    }
    int tem = 0;
    For(i, 1, m) tem += !ok[0][i];
    For(i, 1, tem) move(y, n + 1);
    Rof(i, m, 1){
        if(ok[0][i]) move(x, n + 1);
        else move(x, y);
    }
    For(i, 1, m - tem) move(n + 1, x);
    For(i, 1, tem) move(y, x);
    For(i, 1, m - tem) move(y, n + 1);
    For(i, 1, tem) move(x, y);
    For(i, 1, m){
        if(ok[1][i]) move(n + 1, y);
        else move(n + 1, x);
    }
}

int to[55], _to[55];
void sol(int l, int r){
    if(l == r) return;
    int mid = l + r >> 1;
    sol(l, mid); sol(mid + 1, r);
    int l1 = l, l2 = mid + 1;
    // cout << "asd" << endl;
    For(i, l, r){
        if(l1 > mid) _to[i] = to[l2++];
        else if(l2 > r) _to[i] = to[l1++];
        else{
            if(mx[to[l1]][m] >= mx[to[l2]][m]) opt(to[l2], to[l1]), _to[i] = to[l2++];
            else opt(to[l1], to[l2]), _to[i] = to[l1++];
        }
    }
    For(i, l, r) to[i] = _to[i];
}

int main(){
	// freopen("in.txt", "r", stdin);
    read(n); read(m);
    For(i, 1, n) to[i] = i, mn[i][0] = inf, ball[i][0] = m;
    For(i, 1, n) For(j, 1, m){
        read(ball[i][j]);
        mn[i][j] = min(mn[i][j - 1], ball[i][j]);
        mx[i][j] = max(mx[i][j - 1], ball[i][j]);
    }
    // opt(1, 2);
    sol(1, n);
    printf("%d\n", as.size());
    for(auto i : as) printf("%d %d\n", i.fir, i.sec);
    return 0;
}
