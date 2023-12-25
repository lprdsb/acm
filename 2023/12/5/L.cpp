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

int T, n;
LL k;

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

multiset<pair<int, int> > se[2];
int load(LL lim){
    if(!se[0].size() && !se[1].size()) return 0;
    while(se[0].size() || se[1].size()){
        if(lim != 1 && (!se[0].size() || (se[1].size() && se[1].begin()->fir <= se[0].begin()->fir))){
            pair<int, int> pa = *se[1].begin(); se[1].erase(se[1].begin());
            if(lim > 2 * pa.sec) lim -= 2 * pa.sec;
            else{
                pa.sec -= lim / 2;
                if(pa.sec) se[1].insert(pa);
                if(lim % 2 == 0) break;
                else lim = 1;
            }
        }
        else{
            if(!se[0].size()) break;
            pair<int, int> pa = *se[0].begin(); se[0].erase(se[0].begin());
            if(lim > pa.sec) lim -= pa.sec;
            else{
                pa.sec -= lim;
                if(pa.sec) se[0].insert(pa);
                break;
            }
        }
    }
    return 1;
}

int main(){
	// freopen("in.txt", "r", stdin);
    read(T);
    while(T--){
        read(n); read(k);
        For(i, 1, n){
            int c, w, f; read(c); read(w); read(f);
            se[w - 1].insert({-f, c});
        }
        LL res = 0;
        while(se[0].size() || se[1].size()){
            if(!se[0].size() || (se[1].size() && se[1].begin()->fir <= se[0].begin()->fir)){
                pair<int, int> pa = *se[1].begin(); se[1].erase(se[1].begin());
                res += 1ll * pa.sec * 2 / k * -pa.fir;
                pa.sec %= k / 2;
                if(pa.sec){
                    res += -pa.fir;
                    load(k - pa.sec * 2);
                }
            }
            else{
                pair<int, int> pa = *se[0].begin(); se[0].erase(se[0].begin());
                res += 1ll * pa.sec / k * -pa.fir;
                pa.sec %= k;
                if(pa.sec){
                    res += -pa.fir;
                    load(k - pa.sec);
                }
            }
        }
        printf("%lld\n", res);
    }
}