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
#define maxn 70000
#define mod 998244353
using namespace std;

int n, k, bas = 32;
struct Matrix{
    LL a[32];
    Matrix(){memset(a, 0, sizeof a);}
    friend Matrix operator * (Matrix _a, Matrix _b){
        Matrix asi;
        For(i, 0, k - 1) For(j, 0, k - 1) if((_a.a[i] >> j) & 1) asi.a[i] ^= _b.a[j];
        return asi;
    }
    friend Matrix operator - (Matrix _a, Matrix _b){
        For(i, 0, k - 1) _a.a[i] ^= _b.a[i];
        return _a;
    }
    friend bool operator < (Matrix _a, Matrix _b){
        For(i, 0, k - 1) if(_a.a[i] != _b.a[i]) return _a.a[i] < _b.a[i];
        return 0;
    }
    friend bool operator == (Matrix _a, Matrix _b){
        For(i, 0, k - 1) if(_a.a[i] != _b.a[i]) return 0;
        return 1;
    }
    int get_rk(){
        LL tem[32] = {};
        int asi = 0;
        For(i, 0, k - 1){
            LL temi = a[i];
            For(j, 0, k - 1){
                if((temi >> j) & 1) temi ^= tem[j];
                if((temi >> j) & 1){
                    tem[j] = temi;
                    asi++;
                    break;  
                }
            }
        }
        return asi;
    }
    void print(){
        For(i, 0, k - 1){
            For(j, 0, k - 1) cout << ((a[i] >> j) & 1) << " ";
            cout << endl;
        }
        cout << endl;
    }
} tra[100], uni;

template <class T>
void read(T &x){
	char ch;
	bool ok;
	for(ok = 0, ch = getchar(); !isdigit(ch); ch = getchar()) if(ch == '-') ok = 1;
	for(x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	if(ok) x = -x;
}

int fp(int x, int y){
    int asi = 1;
    while(y){
        if(y & 1) asi = 1ll * asi * x % mod;
        y >>= 1;
        x = 1ll * x * x % mod;
    }
    return asi;
}

vector<LL> vec;
vector<int> f;

map<Matrix, int> ma;

Matrix fp(Matrix x, LL y){
    Matrix asi = uni;
    while(y){
        if(y & 1) asi = asi * x;
        x = x * x;
        y >>= 1;
    }
    return asi;
}

int main(){
	// freopen("in.txt", "r", stdin);
    read(n); read(k);
    For(i, 0, k - 1) uni.a[i] |= 1 << i;
    For(i, 1, k - 1){
        tra[bas + i] = uni;
        For(j, i, k - 1) tra[bas + i].a[j] |= 1 << j - i;

        tra[bas - i] = uni;
        For(j, i, k - 1) tra[bas - i].a[j - i] |= 1 << j;
    }
    Matrix A = uni;
    For(i, 1, n){
        int x; read(x);
        A = tra[bas + x] * A;
    }

    Matrix B = uni;
    ma[B] = 0;
    For(i, 1, maxn - 1){
        B = B * A;
        ma[B] = i;
        // B.print();
        // if(i == maxn - 1) B.print();
    }
    B = B * A;
    Matrix C = B;
    LL now = maxn, r;
    while(666){
        if(ma.count(C)){
            // C.print();
            r = now - ma[C];
            break;
        }
        now += maxn;
        C = C * B;
    }
    // cout << r << endl;
    for(LL i = 1; i * i <= r; ++i) if(r % i == 0){
        vec.pb(i);
        if(r / i != i) vec.pb(r / i);
    }
    sort(vec.begin(), vec.end());
    for(auto i : vec) f.pb(fp(2, k - (fp(A, i) - uni).get_rk()));
    // cout << f[3] << endl;
    For(i, 0, vec.size() - 1) For(j, 0, i - 1) if(vec[i] % vec[j] == 0) f[i] = (1ll * f[i] - f[j] + mod) % mod;
    int asi = 0;
    For(i, 0, vec.size() - 1) asi = (asi + 1ll * vec[i] * f[i] % mod) % mod;
    printf("%d\n", 1ll * asi * fp(2, mod - 1 - k) % mod);
    return 0;
}
