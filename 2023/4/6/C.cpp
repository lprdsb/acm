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
#define maxn 100000
using namespace std;

int s, tt;
struct Node{int ch[2], cnt[2], fa, lpr;};
class Lct_Tree{
    Node poi[maxn + 5];
};
Lct_Tree tem;
int t;

int main(){
	// freopen("in.txt", "r", stdin);
    cout << ((&t - &s) >> 19) << endl;
    return 0;
}
