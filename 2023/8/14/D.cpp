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
#define maxn 5000
using namespace std;

int t, n, a[maxn + 5], sum[maxn + 5];
LL as = 0;
vector<pair<int, int> > vec[maxn + 5];

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
    while(t--){
        read(n);
        For(i, 1, n) read(a[i]), vec[i].resize(0);
        a[n + 1] = 0;
        For(i, 1, n){
            int l = i, r = i, cnt = 0;
            while(r <= n && !cnt){
                r++;
                cnt += a[r] <= a[i];
            }
            Rof(j, i, 1){
                cnt += a[j] <= a[i];
                if(cnt <= i - j + 1) l = r;
                while(r <= n && cnt <= i - j + 1){
                    r++;
                    cnt += a[r] <= a[i];
                }
                // if(i == 3) cout << j << " " << i << " " << l << " " << r << endl;
                vec[j].pb({l, r});
            }
        }
        as = 0;
        For(i, 1, n){
            For(j, 1, n) sum[j] = 0;
            for(auto j : vec[i]) sum[j.fir]++, sum[j.sec]--;
            For(j, i, n){
                sum[j] += sum[j - 1];
                if(!sum[j]){
                    as++;
                    // cout << i << " " << j << endl;
                }
            }
        }
        printf("%lld\n", as);
    }
    return 0;
}
