#include<bits/stdc++.h>

using namespace std;

int a[10] = { 0b11101,0b00100,0b10111,0b10110,0b01110,0b11010,0b11011,0b10100,0b11111,0b11110 };
int d[32];
bool f[32];
int a2[10] = { 0b1110111,0b0010010,0b1011101,0b1011011,0b0111010,0b1101011,0b1101111,0b1010010,0b1111111,0b1111011 };
int d2[128];
bool f2[128];

int main() {
    for(int x = 0;x < 32;x++) {
        d[x] = d[x >> 1] + (x & 1);
    }
    for(int y = 0;y < 128;y++) {
        d2[y] = d2[y >> 1] + (y & 1);
    }
    for(int i = 0;i < (1 << 10);i++) {
        int ans = 5;
        int ans2 = 7;
        for(int x = 0;x < 32;x++) {
            bool ok = true;
            for(int j = 0;j < 10;j++) {
                if(i & (1 << j)) {
                    if(f[a[j] & x]) {
                        ok = false;
                    }
                    f[a[j] & x] = true;
                }
            }
            for(int j = 0;j < 10;j++) {
                if(i & (1 << j)) {
                    f[a[j] & x] = false;
                }
            }
            if(ok) {
                ans = min(ans, d[x]);
            }
        }
        for(int x = 0;x < 32;x++) {
            bool ok = true;
            for(int j = 0;j < 10;j++) {
                if(i & (1 << j)) {
                    if(f[a[j] & x]) {
                        ok = false;
                    }
                    f[a[j] & x] = true;
                }
            }
            for(int j = 0;j < 10;j++) {
                if(i & (1 << j)) {
                    f[a[j] & x] = false;
                }
            }
            if(ok) {
                ans = min(ans, d[x]);
            }
        }
        if(ans != ans2) {
            printf("%b\n", i);
        }
    }
    return 0;
}