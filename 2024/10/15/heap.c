#include<stdio.h>
#define For(i, a, b) for(int i = (a), en = (b); i <= en; ++i)
#define Rof(i, a, b) for(int i = (a), en = (b); i >= en; --i)

#define maxn 200000

int a[maxn + 5], n;
int b[maxn + 5];

void swap(int x, int y) {
    int tmp = a[x];
    a[x] = a[y];
    a[y] = tmp;

    tmp = b[x];
    b[x] = b[y];
    b[y] = tmp;
}

int tp = 0;

void up(int idx) {
    while(idx != 1) {
        int fa = idx >> 1;
        if(a[idx] < a[fa]) swap(idx, fa);
        else break;
        idx = fa;
    }
}
int down(int idx) {
    int ls = idx << 1, rs = idx << 1 | 1;
    if(ls > tp) {
        if(rs > tp) return idx;
        swap(idx, rs);
        return down(rs);
    }
    else {
        if(rs > tp) {
            swap(idx, ls);
            return down(ls);
        }
        else {
            if(a[ls] < a[rs]) {
                swap(idx, rs);
                return down(rs);
            }
            else {
                swap(idx, ls);
                return down(ls);
            }
        }
    }
}

void del() {
    // printf("%d\n", a[1]);
    int idx = down(1);
    if(idx != tp) {
        swap(idx, tp);
        up(idx);
    }
    tp--;
    // printf("%d\n", a[1]);
}
void ins(int x, int y) {
    a[++tp] = x;
    b[tp] = y;
    up(tp);
}

int n, m, t, ma[105][105], T;

#define LL long long
LL f[105][105];

int dir[4][2] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };

int chk(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

int main() {
    freopen("in.txt", "r", stdin);
    scanf("%d%d%d", &n, &m, &t);
    For(i, 0, n - 1) For(j, 0, m - 1) {
        char c; scanf("\n%c", &c);
        if(c == '#') ma[i][j] = 1;
        if(c == '*') T = i * m + j;
        f[i][j] = 1000000;
    }
    ins(0, 0);
    f[0][0] = 0;
    while(tp) {
        int p = b[0]; del();
        int x = p / m, y = p % m;
        For(o, 0, 3) {
            int tx = x + dir[o][0], ty = y + dir[o][1];
            if(!chk(tx, ty)) continue;
            if(f[tx][ty] < f[x][y] + t * ma[tx][ty]) {
                f[tx][ty] = f[x][y] + t * ma[tx][ty];
                printf("%d %d\n", tx, ty);
                ins(f[tx][ty], tx * m + ty);
            }
        }
    }
    printf("%lld\n", f[T / m][T % m]);
}