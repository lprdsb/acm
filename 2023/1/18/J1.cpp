#include<bits/stdc++.h>
#define eps 1e-20
using namespace std;

int n;
long double ans = 0;

int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i){
        long double x; scanf("%llf", &x);
        if(i == 1) ans = x;
        else{
            long double tem = ans;
            tem = max(tem, ans + x);
            tem = max(tem, ans * x);
            if(fabs(x) > eps) tem = max(tem, ans / x);
            ans = tem;
        }
    }
    printf("%.3lf", (double)ans);
    return 0;
}