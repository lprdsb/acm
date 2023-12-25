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

vector<int> vec{5, 2, 3, 4, 5};

struct Cmp{
    // int d;
    // Cmp(int _d){d = _d;}
    bool operator () (cst int x, cst int y){
        // if(abs(x - y) <= 2) return 0;
        return x > y;
    }
};
set<int, Cmp> se;

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

int main(){
	//freopen("in", "r", stdin);
    // sort(vec.begin(), vec.end(), Cmp(2));
    // for(auto i : vec) cout << i << " "; cout << endl;
    se.insert(4); se.insert(5);
    for(auto i : se) cout << i << " "; cout << endl;
}
