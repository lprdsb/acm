#include<bits/stdc++.h>

const int N = 5e5 + 10;
int t;
int n;
char s[N];

int main() {
    scanf("%d", &t);
    while(t--) {
        scanf("%s", s);
        n = strlen(s);
        bool f = true;
        for(int i = 0;i < n;) {
            if(n - i >= 5 && s[i] == 'a' && s[i + 1] == 'v' && s[i + 2] == 'a' && s[i + 3] == 'v' && s[i + 4] == 'a') {
                i += 5;
            }
            else if(n - i >= 3 && s[i] == 'a' && s[i + 1] == 'v' && s[i + 2] == 'a') {
                i += 3;
            }
            else {
                f = false;
                break;
            }
        }
        puts(f ? "Yes" : "No");
    }
    return 0;
}