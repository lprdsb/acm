#include<bits/stdc++.h>
using namespace std;
#define For(i, a, b) for(int i = (a), en = (b); i <= en; ++i)

int n;
char s[100005];

int main() {
    // freopen("in.txt", "r", stdin);
    scanf("%d\n", &n);
    printf("%d nya\n", n);
    For(i, 1, n) {
        fgets(s, 100000, stdin);
        int len = strlen(s);
        // cout << len << endl;
        s[len - 1] = 0;
        printf("%s nya\n", s);
    }
}