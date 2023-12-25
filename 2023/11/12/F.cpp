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
#define maxn 
using namespace std;

int n;
map<string, int> ma;

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
    read(n);
    For(i, 1, n){
        int m, fl = 0; read(m);
        For(j, 1, m){
            string s; cin >> s;
            int len = s.length();
            For(p, 0, len - 3){
                if(s[p] == 'b' && s[p + 1] == 'i' && s[p + 2] == 'e'){
                    if(!ma[s]){
                        ma[s] = 1;
                        cout << s << endl;
                        fl = 1;
                    }
                    break;
                }
            }
        }
        if(!fl) puts("Time to play Genshin Impact, Teacher Rice!");
    }
}
