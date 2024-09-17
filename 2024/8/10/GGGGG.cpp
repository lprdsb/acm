#include<bits/stdc++.h>
#define fs(i,x,y) for(int i=(x),_=(y);i<=_;++i)
#define fn(i,x,y) for(int i=(x),_=(y);i>=_;--i)
#define pi pair<int,int>
#define se second
#define fi first
#define mpi(x,y)  make_pair(x,y)
typedef long long ll;
typedef double db;
using namespace std;

const int N = 30;
const db pai = 3.14159265358979323846;
char ss[N];
db ang;
db len;
int a[10];
int sol(int typ) {
    db x = len * 2 / sqrt(3) * sin(pai / 3 - ang * pai / 180);
    db y = len * 2 / sqrt(3) * sin(ang * pai / 180);
    // cout << x << ' ' << y << endl;
    int tot = (int)(x / 2) + 1 + (int)(y / 2) + 1;
    // cout << "//" << tot * 2 << endl;
    if(x + y < tot * 2 - 2) {
        // cout << "///typ1" << endl;
        if(typ == 1) {
            a[1] = 1;a[2] = 3;a[3] = 0;a[4] = 2;
        }
        else if(typ == 2) {
            a[1] = 2;a[2] = 1;a[3] = 0;a[4] = 3;
        }
        else {
            a[1] = 3;a[2] = 2;a[3] = 0;a[4] = 1;
        }
        if(x + y < tot * 2 - 3)return a[1];
        else {
            int xx = x + 1, yy = y + 1;
            if((xx % 2 == 0) && (yy % 2 == 1))return a[2];
            else if((xx % 2 == 1) && (yy % 2 == 1))return a[3];
            else return a[4];
        }
    }
    else {
        // cout << "///typ2" << endl;
        if(typ == 1) {
            a[1] = 2;a[2] = 0;a[3] = 3;a[4] = 1;
        }
        else if(typ == 2) {
            a[1] = 3;a[2] = 0;a[3] = 1;a[4] = 2;
        }
        else {
            a[1] = 1;a[2] = 0;a[3] = 2;a[4] = 3;
        }
        if(x + y > tot * 2 - 1)return a[4];
        else {
            int xx = x + 1, yy = y + 1;
            if((xx % 2 == 0) && (yy % 2 == 1))return a[1];
            else if((xx % 2 == 0) && (yy % 2 == 0))return a[2];
            else return a[3];
        }
    }
}

void solve() {
    int ans[3];
    fs(i, 1, 2) {
        scanf("%s", ss + 1);scanf("%lf%lf", &ang, &len);
        if(ss[1] == 'C') {
            ans[i] = sol(1);
        }
        else if(ss[1] == 'D') {
            ans[i] = sol(2);
        }
        else {
            ans[i] = sol(3);
        }
    }
    if(ans[1] == ans[2]) {
        printf("YES\n");
    }
    else  printf("NO\n");
}

signed main() {
    int T = 1;
    while(T--) {
        solve();
    }
}