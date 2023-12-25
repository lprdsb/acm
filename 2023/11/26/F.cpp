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
#define maxn 1000000
using namespace std;

int T, n, m;

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

int L[maxn + 5], R[maxn + 5], as[maxn + 5];
vector<pair<int, int> > vec[maxn + 5];

int main(){
	// freopen("in.txt", "r", stdin);
    read(T);
    while(T--){
        read(n); read(m);
        For(i, 1, n) L[i] = 1, R[i] = n;
        For(i, 1, m){
            int x, y; read(x); read(y);
            int l = 1, r = n;
            while(l < r){
                int mid = l + r >> 1;
                if(y <= mid){
                    L[mid] = max(L[mid], x);
                    r = mid;
                }
                else{
                    R[mid] = min(R[mid], x - 1);
                    l = mid + 1;
                }
            }
        }
        set<pair<int, int> > se;
        // For(i, 1, n) cout << L[i] << " " << R[i] << endl;
        For(i, 1, n) vec[L[i]].pb({R[i], i});
        int fl = 1;
        For(i, 1, n){
            for(auto [j, k] : vec[i]) se.insert({j, k});
            if(se.begin()->fir >= i){
                as[se.begin()->sec] = i;
                se.erase(se.begin());
            }
            else{
                fl = 0;
                break;
            }
        }
        if(!fl) puts("-1");
        else{
            For(i, 1, n) printf("%d ", as[i]);
            puts("");
        }
        For(i, 1, n) vec[i].resize(0);
    }
}
