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

class Myclass{
    public:
        int x, y;
        Myclass(int _x, int _y) : x(_x), y(_y){}
        Myclass(Myclass& _tem){
            x = _tem.x;
            y = _tem.y;
        }
        friend ostream& operator << (ostream& os, cst Myclass& tem);
};

ostream& operator << (ostream& os, cst Myclass& tem){
    return os << tem.x << " " << tem.y << endl;
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
	//freopen("in", "r", stdin);
    Myclass tem(1, 2);
    Myclass* tem1 = new Myclass(tem);
    tem1->x = 2;
    cout << *tem1;
	return 0;
}
