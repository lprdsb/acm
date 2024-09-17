#pragma GCC optimize("Ofast")
#pragma GCC optimize(3)
#include<cstdio>
#include<vector>
#include<algorithm>
#define fo(x,a,b) for(int x=(a),e_=(b);x<=e_;x++)
#define fd(x,a,b) for(int x=(a),e_=(b);x>=e_;x--)
#define ww printf
#define ll long long

using namespace std;
// const int N=505, maxC=250, B=125;  ////!!!!!!!!!N=105!!!
const int N = 1005, B = 30, maxC = 2 * B;  ////!!!!!!!!!
ll f[N][N][maxC + 2], a[N], b[N];
int n;

int main() {
    freopen("in.txt", "r", stdin);
    //    freopen("1.out","w",stdout);
    scanf("%d", &n);
    fo(i, 1, n) scanf("%lld", &b[i]);
    int tn = unique(b + 1, b + n + 1) - b - 1;
    n = tn; fo(i, 1, tn) a[i] = b[i];

    int key, el, er, em; ll k1, k2, mid;
    fd(l, n, 1) //dec dimen-3rd by B
        fo(r, l, n) {
        if(l == r) {
            fo(c, 0, 2 * B)
                f[l][r][c] = a[l] * (c - B);
            continue;
        }

        key = l;  ///key

#define CALC(Ans)  mid=min(a[em+1], \
	max(a[em]+1, (f[em+1][r][c+1]-f[l][em][c-1])/2)); \
	Ans = max(f[l][em][c-1]+mid,  f[em+1][r][c+1]-mid);

        fo(c, 0, 2 * B) {
            f[l][r][c] = 1e17;
            if(c == 0 || c == 2 * B) continue;

            el = key, er = r - 2, key = r - 1;
            if(el == l) { //1,1.5
                em = l;
                CALC(k1);

                ++em;
                CALC(k2);
                --em;

                if(k1 < k2) { f[l][r][c] = k1, key = l; continue; }
            }

            if(er - el + 1 <= 4) {
                ll tmp = 1e17, mid, val;
                fo(k, el, er + 1) {  //2
                    mid = min(a[k + 1], max(a[k] + 1, (f[k + 1][r][c + 1] - f[l][k][c - 1]) / 2));
                    val = max(f[l][k][c - 1] + mid, f[k + 1][r][c + 1] - mid);
                    if(val < tmp) key = k, tmp = val;
                    // ww("%lld ",max(f[l][k][c-1]+mid,  f[k+1][r][c+1]-mid));
                } //puts("in dp");
                f[l][r][c] = tmp;

            }
            else {
                while(el <= er) { //3,4
                    em = (el + er) / 2;
                    CALC(k1);

                    ++em;
                    CALC(k2);
                    --em;

                    if(k1 < k2) key = em, er = em - 1;
                    else el = em + 1;
                }
                em = key; //5
                CALC(f[l][r][c]);
            }
        }
        // ww("l:%d r:%d :\n",l,r);
        // fo(c,B-10,B-1) ww("%lld ",f[l][r][c]);puts("f");
        // fo(c,B,B+10) ww("%lld ",f[l][r][c]);puts("f");
    }

    printf("%lld", f[1][n][B]);
    return 0;
}