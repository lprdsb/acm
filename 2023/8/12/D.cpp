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
#define maxn 200000
using namespace std;

int t, n, q;

struct Node{
    int l, r, a, b;
} a[maxn + 5];
bool operator < (Node _x, Node _y){
    return _x.b < _y.b;
}

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

int main(){
	// freopen("in.txt", "r", stdin);
    read(t);
    For(_, 1, t){
        read(n);
        For(i, 1, n) read(a[i].l), read(a[i].r), read(a[i].a), read(a[i].b);
        // if(_ == 5 && t != 5){
        //     cout << "asd" << endl;
        //     For(i, 1, n) cout << a[i].l << " " << a[i].r << " " << a[i].a << " " << a[i].b << endl;
        // }
        sort(a + 1, a + n + 1);
        set<pair<int, int> > se;
        int nowl = -1, nowr;
        Rof(i, n, 1){
            if(nowl == -1 || a[i].b < nowl){
                if(nowl != -1) se.insert({nowl, nowr});
                nowr = a[i].b;
            }
            if(nowl == -1 || a[i].l < nowl) nowl = a[i].l;
        }
        if(nowl != -1) se.insert({nowl, nowr});
        // cout << nowl << " " << nowr << endl;
        read(q);
        For(__, 1, q){
            int x; read(x);
            auto it = se.lower_bound({x + 1, 0});
            if(it != se.begin()) it--;
            if(it->fir <= x) x = max(x, it->sec);
            printf("%d ", x);
        }
        puts("");
    }
}
