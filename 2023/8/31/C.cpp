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

int t, n;
char s[maxn + 5];

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

vector<int> ok[2];

int main(){
	// freopen("in.txt", "r", stdin);
    read(t);
    while(t--){
        scanf("%s", s + 1); n = strlen(s + 1);
        int now = 0, fl = 1;
        For(i, 1, n){
            if(s[i] == '+') now++;
            if(s[i] == '-'){
                now--;
                For(o, 0, 1){
                    int ffl = 0;
                    while(ok[o].size() && ok[o][ok[o].size() - 1] > now){
                        ffl = 1;
                        ok[o].pop_back();
                    }
                    if(ffl && o && (!ok[1].size() || ok[1][ok[1].size() - 1] != now)) ok[1].pb(now);
                }
            }
            if(s[i] == '0'){
                if(now <= 1){
                    // cout << "asd" << endl;
                    fl = 0;
                    break;
                }
                if(ok[1].size() && ok[1][ok[1].size() - 1] >= now){
                    fl = 0;
                    break;
                }
                if(!ok[0].size() || ok[0][ok[0].size() - 1] != now) ok[0].pb(now);
            }
            if(s[i] == '1'){
                if(ok[0].size() && ok[0][0] <= now){
                    fl = 0;
                    break;
                }
                if(!ok[1].size() || ok[1][ok[1].size() - 1] != now) ok[1].pb(now);
            }
        }
        puts(fl ? "YES" : "NO");
        For(o, 0, 1) ok[o].resize(0);
    }
    return 0;
}
