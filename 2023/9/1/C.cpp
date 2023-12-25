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
#define maxn 10000
using namespace std;

int t, n;
struct Node{
    int ty, v, k;
    bool vis[256];
} opt[maxn + 5];

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
        For(i, 1, n){
            int v = 0, k = 0;
            char s[10]; scanf("%s", s + 1);
            read(v);
            if(s[1] == 'a'){
                opt[i] = {1, v, k, {}};
            }
            if(s[2] == 'e'){
                read(k);
                opt[i] = {2, v, k, {}};
            }
            if(s[2] == 'n'){
                read(k);
                opt[i] = {3, v, k, {}};
            }
            if(s[2] == 'l'){
                read(k);
                opt[i] = {4, v, k, {}};
            }
            if(s[2] == 'g'){
                read(k);
                opt[i] = {5, v, k, {}};
            }
        }
        int pos = 1, now = 0, fl = 1;
        while(pos != n + 1){
            if(opt[pos].vis[now]){
                fl = 0;
                break;
            }
            opt[pos].vis[now] = 1;
            if(opt[pos].ty == 1){
                now = (now + opt[pos].v) % 256;
                pos++;
            }
            else if(opt[pos].ty == 2){
                if(now == opt[pos].v) pos = opt[pos].k;
                else pos++;
            }
            else if(opt[pos].ty == 3){
                if(now != opt[pos].v) pos = opt[pos].k;
                else pos++;
            }
            else if(opt[pos].ty == 4){
                if(now < opt[pos].v) pos = opt[pos].k;
                else pos++;
            }
            else if(opt[pos].ty == 5){
                if(now > opt[pos].v) pos = opt[pos].k;
                else pos++;
            }
        }
        puts(fl ? "Yes" : "No");
    }
    return 0;
}
