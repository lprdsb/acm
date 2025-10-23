#include<bits/stdc++.h>
using namespace std;
#define For(i, a, b) for(int i = (a), en = (b); i <= en; ++i)
#define LL long long

int id[105];

struct Mat {
    int a[15][15];
}a, c;

void mdy(Mat &A, int x, int y) {
    int b[5][5];
    For(i, 1, 4) For(j, 1, 4) b[i][j] = A.a[x + 3 - (j - 1)][y + i - 1];
    For(i, 1, 4) For(j, 1, 4) A.a[x + i - 1][y + j - 1] = b[i][j];
}

int get_s1(Mat &A) {
    int res = 0;
    For(i, 1, 10) For(j, 1, 10) {
        int x = (A.a[i][j] - 1) / 10 + 1, y = (A.a[i][j] - 1) % 10 + 1;
        res += abs(x - i) + abs(y - j);
    }
    return res;
}

int get_s2(Mat &A) {
    int res = 0;
    For(i, 1, 10) For(j, 1, 10) {
        int x = (A.a[i][j] - 1) % 10 + 1, y = (A.a[i][j] - 1) / 10 + 1;
        res = max(abs(x - i), abs(y - j));
    }
    return res;

}

int get_s3(Mat &A) {
    int res = 0;
    For(i, 1, 10) For(j, 1, 10) {
        For(x, 1, 10) For(y, 1, 10) {
            if(x < i || (x == i && y < j)) {
                res += A.a[x][y] > A.a[i][j];
            }
        }
    }
    return res;

}

int get_s4(Mat &A) {
    int res = 0;
    For(i, 1, 10) For(j, 1, 10) {
        // For(p, j, 10) res += A.a[i][j] > A.a[i][p];
        // For(p, j, 10) res += A.a[i][j] > A.a[p][j];
        // res += abs(A.a[i][j] - a)
    }
    return res;

}

int get_s5(Mat &A) {
    int res = 0;
    For(i, 1, 10) For(j, 1, 10) {
        res += abs(A.a[i][j] - A.a[i - 1][j]) == 1;
        res += abs(A.a[i][j] - A.a[i][j - 1]) == 1;
    }
    return res;

}

int get_s6(Mat &A) {
    int res = 0;
    For(i, 1, 10)For(j, 1, 10) {
        int x = (A.a[i][j] - 1) / 10 + 1, y = (A.a[i][j] - 1) % 10 + 1;
        res += ((x != i) || (y != j));
    }
    return res;
}

pair<int, int> pa[105];

int main() {
    // double tmp = 0;
    // For(i, 1, 10) For(j, 1, 10) tmp += abs(i - j);
    // cout << tmp / 100 << endl;
    srand(time(0));
    int T = 100;
    int cnt[2] = { 0, 0 };
    For(_, 1, T) {
        For(i, 1, 10) For(j, 1, 10) {
            a.a[i][j] = (i - 1) * 10 + j;
            pa[(i - 1) * 10 + j] = { i, j };
        }
        // mdy(1, 1);
        For(i, 1, 1000) {
            int x = rand() % 7 + 1, y = rand() % 7 + 1;
            mdy(a, x, y);
        }
        // For(i, 1, 100) id[i] = i;
        random_shuffle(pa + 1, pa + 100 + 1);
        For(i, 1, 100) c.a[pa[i].first][pa[i].second] = i;
        // For(i, 1, 10) {
        //     For(j, 1, 10) printf("%3d ", c.a[i][j]); puts("");
        // }
        // cout << endl;

        cout << "---------------------------------" << endl;
        cout << get_s3(a) << endl;
        cout << get_s3(c) << endl;
        // For(i, 1, 10) {
        //     For(j, 1, 10)cout << a.a[i][j] % 4 << " ";
        //     cout << endl;
        // }
        // For(i, 1, 10) {
        //     int tp = 0;
        //     For(j, 1, 10)tp += a.a[i][j];
        //     cout << tp % 4 << endl;
        // }
        // cout << endl;
        // For(i, 1, 10) {
        //     For(j, 1, 10)cout << c.a[i][j] % 4 << " ";
        //     cout << endl;
        // }
        // For(i, 1, 10) {
        //     int tp = 0;
        //     For(j, 1, 10)tp += a.a[i][j];
        //     cout << tp % 4 << endl;
        // }
        // cout << get_s5(c) << endl;
        // cnt[0] += get_s1(a);
        // cnt[1] += get_s2(c) >= d8;
    }
    // cout << (double)cnt[0] / T << " " << cnt[1] << endl;
}