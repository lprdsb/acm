#include<iostream>
using namespace std;
int n;
int ask(int l, int r, int op) {
    if(op)swap(l, r), l = n - l, r = n - r;
    cout << "? " << l + 1 << " " << r << endl;
    int res;cin >> res;
    return res;
}
void ATRI() {
    cin >> n;
    int f1 = ask(0, n >> 2, 0) != ask(n >> 2, n >> 1, 0);
    int f2 = ask(0, n >> 1, f1);
    int res = f2 ? 0 : (n >> 1) - 1;
    if(f2) { for(int k = n >> 2;k;k >>= 1)if(!ask(0, res + k, f1))res += k; }
    else { for(int k = n >> 2;k;k >>= 1)if(ask(0, res + k, f1 ^ 1))res += k; }
    cout << "! " << res + 1 << endl;
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;cin >> t;while(t--)ATRI();
    return 0;
}