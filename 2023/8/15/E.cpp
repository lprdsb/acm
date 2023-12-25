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

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

int q, tot = 0;
struct Tree{
    int val;
    int fa[20];
} tr[maxn + 5];
int st[maxn + 5], top = 0;

int main(){
    // cout << ((&T - &S) >> 19) << endl;
	// freopen("in.txt", "r", stdin);
    tot = 1;
    st[++top] = 1;
    tr[1].rt = get_new();
    read(q);
    while(q--){
        int x;
        char c; cin >> c;
        if(c == '+'){
            read(x);
            tot++;
            tr[tot].rt = ins(tr[st[top]].rt, 1, maxn, x);
            tr[tot].fa[0] = st[top];
            For(i, 1, 19) tr[tot].fa[i] = tr[tr[tot].fa[i - 1]].fa[i - 1];
            st[++top] = tot;
        }
        else if(c == '-'){
            read(x);
            int now = st[top];
            For(i, 0, 19) if((x >> i) & 1) now = tr[now].fa[i];
            st[++top] = now;
        }
        else if(c == '!') top--;
        else{
            printf("%d\n", tr[st[top]].rt->val);
            fflush(stdout);
        }
    }
    return 0;
}
