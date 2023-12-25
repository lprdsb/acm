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

int t, n, q;

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

template<int P>
struct Mint{
    int x;
    Mint(){x = 0;}
    Mint(int _x) : x{norm(_x % P)}{}
    int norm(int _x){
        if(_x < 0) _x += P;
        if(_x >= P) _x -= P;
        return _x;
    }
    Mint inv(){return fp(*this, P - 2);}
    Mint operator - (){return {P - x};}
    Mint& operator += (Mint _x) &{
        x = norm(x + _x.x);
        return *this;
    }
    Mint& operator -= (Mint _x) &{
        x = norm(x - _x.x);
        return *this;
    }
    Mint& operator *= (Mint _x) &{
        x = 1ll * x * _x.x % P;
        return *this;
    }
    Mint& operator /= (Mint _x) &{return *this *= _x.inv();}
    friend Mint operator + (Mint _x, Mint _y){return _x += _y;}
    friend Mint operator - (Mint _x, Mint _y){return _x -= _y;}
    friend Mint operator * (Mint _x, Mint _y){return _x *= _y;}
    friend Mint operator / (Mint _x, Mint _y){return _x /= _y;}
    friend bool operator == (Mint _x, Mint _y){return _x.x == _y.x;}
};
using Z = Mint<998244353>;

Z pw[maxn + 5];

struct Data{
    int l, r;
};
struct Segment:vector<Data>{
    Z val;
    Segment(){val = 0;}
    Segment(int l, int r){val = l * pw[1] + r * pw[2];}
    void upd_val(){
        int tot = 0;
        val = 0;
        for(auto i : *this){
            val += i.l * pw[++tot];
            val += i.r * pw[++tot];
        }
    }
};
Segment operator + (cst Segment &_a, cst Segment &_b){
    if(!_a.size()) return _b;
    if(!_b.size()) return _a;
    Segment res = {};
    Data now = {114514};
    int l = 0, r = 0;
    while(l < _a.size() || r < _b.size()){
        Data tem;
        if(l == _a.size()) tem = _b[r++];
        else if(r == _b.size()) tem = _a[l++];
        else if(_a[l].l < _b[r].l) tem = _a[l++];
        else tem = _b[r++];
        if(now.l == 114514) now = tem;
        else{
            if(tem.l > now.r) res.pb(now), now = tem;
            else if(tem.r > now.r) now.r = tem.r;
        }
    }
    if(now.l != 114514) res.pb(now);
    res.upd_val();
    return res;
}
struct Matrix{
    int l, r;
    Segment row;
};
struct Graph:vector<Matrix>{
    LL get_s(){
        LL res = 0;
        for(auto i : *this){
            LL tem = 0;
            for(auto j : i.row) tem += j.r - j.l;
            res += tem * (i.r - i.l);
        }
        return res;
    }
    void print(){
        for(auto i : *this){
            for(auto j : i.row) cout << i.l << " " << j.l << " " << i.r << " " << j.r << endl;
        }
    }
} gra[maxn + 5];
Graph operator + (cst Graph &_a, cst Graph &_b){
    if(!_a.size()) return _b;
    if(!_b.size()) return _a;
    Graph res = {};
    Matrix now = {114514};
    int l = 0, r = 0;
    while(l < _a.size() || r < _b.size()){
        Matrix tem;
        if(l == _a.size()) tem = _b[r++];
        else if(r == _b.size()) tem = _a[l++];
        else if(_a[l].l < _b[r].l) tem = _a[l++];
        else tem = _b[r++];
        if(now.l == 114514) now = tem;
        else{
            if(tem.l > now.r) res.pb(now), now = tem;
            else if(tem.r <= now.r){
                if(now.l != tem.l) res.pb({now.l, tem.l, now.row});
                res.pb({tem.l, tem.r, now.row + tem.row});
                now.l = tem.r;
            }
            else if(tem.r > now.r){
                if(now.l != tem.l) res.pb({now.l, tem.l, now.row});
                res.pb({tem.l, now.r, now.row + tem.row});
                tem.l = now.r;
                now = tem;
            }
        }
    }
    res.pb(now);
    Graph resi = {};
    for(auto i : res){
        if(i.l == i.r) continue;
        if(!resi.size() || i.l != resi[resi.size() - 1].r) resi.pb(i);
        else if(resi[resi.size() - 1].row.val == i.row.val) resi[resi.size() - 1].r = i.r;
        else resi.pb(i);
    }
    return resi;
}

int B = 100, up;
Graph pre[maxn + 5], suf[maxn + 5], lhs[maxn + 5][25], rhs[maxn + 5][25];

Graph sol(int l, int r){
    if(l > r) return {};
    int len = 0;
    while((1 << (len + 1)) <= r - l + 1) len++;
    return lhs[r][len] + rhs[l][len];
}

int main(){
	freopen("in.txt", "r", stdin);
    pw[0] = 1;
    pw[1] = 1331;
    For(i, 2, maxn) pw[i] = pw[1] * pw[i - 1];
    read(t);
    while(t--){
        read(n); read(q); up = n / B;
        For(i, 0, up) lhs[i][0] = rhs[i][0] = {};
        // For(i, 0, n - 1) gra[i].resize(0);
        For(i, 0, n - 1){
            int x1, y1, x2, y2; read(x1); read(y1); read(x2); read(y2);
            Segment tem; tem.pb({y1, y2});
            Matrix tem1 = {x1, x2, tem};
            gra[i].resize(0);
            gra[i].pb(tem1);
            lhs[i / B][0] = lhs[i / B][0] + gra[i];
            // cout << i << endl;
        }
        For(i, 0, up) rhs[i][0] = lhs[i][0];
        // (gra[0] + gra[1]).print();
        // int mx = 0;
        // For(i, 0, up){
        //     int sum = 0;
        //     for(auto j : lhs[i][0]) sum += j.row.size();
        //     mx = max(mx, sum);
        // }
        // cout << mx << endl;
        For(i, 0, n - 1){
            if(i % B) pre[i] = pre[i - 1] + gra[i];
            else pre[i] = gra[i];
        }
        Rof(i, n - 1, 0){
            if(i % B != B - 1 && i != n - 1) suf[i] = suf[i + 1] + gra[i];
            else suf[i] = gra[i];
        }
        For(i, 0, up){
            int len = 1;
            For(j, 1, 20){
                if(i < len) break;
                lhs[i][j] = lhs[i][j - 1] + lhs[i - len][j - 1];
                len <<= 1;
                // cout << lhs[i][j].size() << endl;
            }
            // if(i == 100){
            //     lhs[i][5].print();
            // }
        }
        Rof(i, up, 0){
            int len = 1;
            For(j, 1, 20){
                if(i + len >= up) break;
                rhs[i][j] = rhs[i][j - 1] + rhs[i + len][j - 1];
                len <<= 1;
            }
        }
        cout << "asd" << endl;
        while(q--){
            int l, r; read(l); read(r); l--; r--;
            Graph asi = {};
            if(l / B != r / B) asi = sol(l / B + 1, r / B - 1) + suf[l] + pre[r];
            else For(i, l, r) asi = asi + gra[i];
            // printf("%lld\n", asi.get_s());
        }
        // puts("asd");
    }
    return 0;
}
