#include<bits/stdc++.h>

const int N = 1e3 + 10;

int n, m;
char c[N][N];
int f[N][N][4];
int d[N][N][4];
int e[N][N];
int h[N][N];
int q;
int x, y, dir;
int ox, oy, od;

int type;

int get_dir(char* s) {
    switch(*s) {
        case 'a':
            return 0;
        case 'b':
            return 1;
        case 'l':
            return 2;
        case 'r':
            return 3;
        default:
            return -1;
    }
}

int get_ori(int xx, int yy, int dd) {
    if(xx < 0 || xx >= n || yy < 0 || yy >= m) {
        type = 1;
        return 1;
    }
    if(d[xx][yy][dd]) {
        type = 0;
        ox = x;
        oy = y;
        od = dir;
        return 0;
    }
    d[xx][yy][dd] = 1;
    int z = 0;
    switch(dd) {
        case 0:
            switch(c[xx][yy]) {
                case '-':
                    z = get_ori(xx - 1, yy, 1);
                    break;
                case '\\':
                    z = get_ori(xx, yy + 1, 2);
                    break;
                case '/':
                    z = get_ori(xx, yy - 1, 3);
                    break;
                case '|':
                    z = get_ori(xx + 1, yy, 0);
                    break;
                default:
                    break;
            }
            break;
        case 1:
            switch(c[xx][yy]) {
                case '-':
                    z = get_ori(xx + 1, yy, 0);
                    break;
                case '\\':
                    z = get_ori(xx, yy - 1, 3);
                    break;
                case '/':
                    z = get_ori(xx, yy + 1, 2);
                    break;
                case '|':
                    z = get_ori(xx - 1, yy, 1);
                    break;
                default:
                    break;
            }
            break;
        case 2:
            switch(c[xx][yy]) {
                case '-':
                    z = get_ori(xx, yy + 1, 2);
                    break;
                case '\\':
                    z = get_ori(xx + 1, yy, 0);
                    break;
                case '/':
                    z = get_ori(xx - 1, yy, 1);
                    break;
                case '|':
                    z = get_ori(xx, yy - 1, 3);
                    break;
                default:
                    break;
            }
            break;
        case 3:
            switch(c[xx][yy]) {
                case '-':
                    z = get_ori(xx, yy - 1, 3);
                    break;
                case '\\':
                    z = get_ori(xx - 1, yy, 1);
                    break;
                case '/':
                    z = get_ori(xx + 1, yy, 0);
                    break;
                case '|':
                    z = get_ori(xx, yy + 1, 2);
                    break;
                default:
                    break;
            }
            break;
        default:
            break;
    }
    if(z) {
        ox = xx;
        oy = yy;
        od = dd;
    }
    return 0;
}

int get_ans(int x, int y, int dir, int cnt) {
    if(cnt > 0 && x == ox && y == oy && dir == od) {
        return f[x][y][dir] = cnt;
    }
    if(cnt > 0 && ((c[x][y] == '-' && dir != 2 && dir != 3) || (c[x][y] == '|' && dir != 0 && dir != 1) || c[x][y] == '\\' || c[x][y] == '/')) {
        e[x][y]++;
    }
    switch(dir) {
        case 0:
            if(x == 0) {
                break;
            }
            switch(c[x - 1][y]) {
                case '-':
                    f[x][y][dir] = get_ans(x - 1, y, 1, cnt + (e[x - 1][y] == 0));
                    break;
                case '\\':
                    f[x][y][dir] = get_ans(x - 1, y, 2, cnt + (e[x - 1][y] == 0));
                    break;
                case '/':
                    f[x][y][dir] = get_ans(x - 1, y, 3, cnt + (e[x - 1][y] == 0));
                    break;
                case '|':
                    f[x][y][dir] = get_ans(x - 1, y, 0, cnt);
                    break;
                default:
                    break;
            }
            break;
        case 1:
            if(x == n - 1) {
                break;
            }
            switch(c[x + 1][y]) {
                case '-':
                    f[x][y][dir] = get_ans(x + 1, y, 0, cnt + (e[x + 1][y] == 0));
                    break;
                case '\\':
                    f[x][y][dir] = get_ans(x + 1, y, 3, cnt + (e[x + 1][y] == 0));
                    break;
                case '/':
                    f[x][y][dir] = get_ans(x + 1, y, 2, cnt + (e[x + 1][y] == 0));
                    break;
                case '|':
                    f[x][y][dir] = get_ans(x + 1, y, 1, cnt);
                    break;
                default:
                    break;
            }
            break;
        case 2:
            if(y == 0) {
                break;
            }
            switch(c[x][y - 1]) {
                case '-':
                    f[x][y][dir] = get_ans(x, y - 1, 2, cnt);
                    break;
                case '\\':
                    f[x][y][dir] = get_ans(x, y - 1, 0, cnt + (e[x][y - 1] == 0));
                    break;
                case '/':
                    f[x][y][dir] = get_ans(x, y - 1, 1, cnt + (e[x][y - 1] == 0));
                    break;
                case '|':
                    f[x][y][dir] = get_ans(x, y - 1, 3, cnt + (e[x][y - 1] == 0));
                    break;
                default:
                    break;
            }
            break;
        case 3:
            if(y == m - 1) {
                break;
            }
            switch(c[x][y + 1]) {
                case '-':
                    f[x][y][dir] = get_ans(x, y + 1, 3, cnt);
                    break;
                case '\\':
                    f[x][y][dir] = get_ans(x, y + 1, 1, cnt + (e[x][y + 1] == 0));
                    break;
                case '/':
                    f[x][y][dir] = get_ans(x, y + 1, 0, cnt + (e[x][y + 1] == 0));
                    break;
                case '|':
                    f[x][y][dir] = get_ans(x, y + 1, 2, cnt + (e[x][y + 1] == 0));
                    break;
                default:
                    break;
            }
            break;
        default:
            break;
    }
    if(cnt > 0 && ((c[x][y] == '-' && dir != 2 && dir != 3) || (c[x][y] == '|' && dir != 0 && dir != 1) || c[x][y] == '\\' || c[x][y] == '/')) {
        e[x][y]--;
    }
    return f[x][y][dir];
}

std::vector<int*> vv;

int get_ans2(int x, int y, int dir) {
    switch(dir) {
        case 0:
            if(x == 0) {
                break;
            }
            switch(c[x - 1][y]) {
                case '-':
                    f[x][y][dir] = get_ans2(x - 1, y, 1);
                    f[x][y][dir] += (e[x - 1][y] == 1);
                    break;
                case '\\':
                    f[x][y][dir] = get_ans2(x - 1, y, 2);
                    f[x][y][dir] += (e[x - 1][y] == 1);
                    break;
                case '/':
                    f[x][y][dir] = get_ans2(x - 1, y, 3);
                    f[x][y][dir] += (e[x - 1][y] == 1);
                    break;
                case '|':
                    f[x][y][dir] = get_ans2(x - 1, y, 0);
                    break;
                default:
                    break;
            }
            break;
        case 1:
            if(x == n - 1) {
                break;
            }
            switch(c[x + 1][y]) {
                case '-':
                    f[x][y][dir] = get_ans2(x + 1, y, 0);
                    f[x][y][dir] += (e[x + 1][y] == 1);
                    break;
                case '\\':
                    f[x][y][dir] = get_ans2(x + 1, y, 3);
                    f[x][y][dir] += (e[x + 1][y] == 1);
                    break;
                case '/':
                    f[x][y][dir] = get_ans2(x + 1, y, 2);
                    f[x][y][dir] += (e[x + 1][y] == 1);
                    break;
                case '|':
                    f[x][y][dir] = get_ans2(x + 1, y, 1);
                    break;
                default:
                    break;
            }
            break;
        case 2:
            if(y == 0) {
                break;
            }
            switch(c[x][y - 1]) {
                case '-':
                    f[x][y][dir] = get_ans2(x, y - 1, 2);
                    break;
                case '\\':
                    f[x][y][dir] = get_ans2(x, y - 1, 0);
                    f[x][y][dir] += (e[x][y - 1] == 1);
                    break;
                case '/':
                    f[x][y][dir] = get_ans2(x, y - 1, 1);
                    f[x][y][dir] += (e[x][y - 1] == 1);
                    break;
                case '|':
                    f[x][y][dir] = get_ans2(x, y - 1, 3);
                    f[x][y][dir] += (e[x][y - 1] == 1);
                    break;
                default:
                    break;
            }
            break;
        case 3:
            if(y == m - 1) {
                break;
            }
            switch(c[x][y + 1]) {
                case '-':
                    f[x][y][dir] = get_ans2(x, y + 1, 3);
                    break;
                case '\\':
                    f[x][y][dir] = get_ans2(x, y + 1, 1);
                    f[x][y][dir] += (e[x][y + 1] == 1);
                    break;
                case '/':
                    f[x][y][dir] = get_ans2(x, y + 1, 0);
                    f[x][y][dir] += (e[x][y + 1] == 1);
                    break;
                case '|':
                    f[x][y][dir] = get_ans2(x, y + 1, 2);
                    f[x][y][dir] += (e[x][y + 1] == 1);
                    break;
                default:
                    break;
            }
            break;
        default:
            break;
    }
    d[x][y][dir] = 1;
    if((c[x][y] == '-' && dir != 2 && dir != 3) || (c[x][y] == '|' && dir != 0 && dir != 1) || c[x][y] == '\\' || c[x][y] == '/') {
        e[x][y]++;
        vv.push_back(&e[x][y]);
    }
    return f[x][y][dir];
}

char tmp[N];

int main() {
    scanf("%d%d", &n, &m);
    for(int i = 0;i < n;i++) {
        scanf("\n%s", tmp);
        for(int j = 0;j < m;j++) {
            c[i][j] = tmp[j];
        }
    }
    scanf("%d", &q);
    while(q--) {
        scanf("%d%d%s", &x, &y, tmp);
        x--;
        y--;
        dir = get_dir(tmp);
        if(f[x][y][dir] == 0) {
            get_ori(x, y, dir);
            // printf("!%d %d %d\n", ox, oy, od);
            if(type) {
                get_ans2(ox, oy, od);
                while(!vv.empty()) {
                    (*vv.back())--;

                    vv.pop_back();
                }
            }
            else {
                get_ans(ox, oy, od, 0);
            }
        }
        printf("%d\n", f[x][y][dir]);
    }
    return 0;
}