#include<stdio.h>

int a[1005][2] = {{8, 0}, {9, 43}, {11, 19}, {12, 47}, {14, 0}, {15, 45}, {19, 0}, {21, 45}};
int b[1005][2] = {{10, 16}, {11, 52}, {13, 31}, {15, 0}, {16, 8}, {17, 55}, {21, 20}, {23, 58}};

int abs(int x){return x < 0 ? -x : x;}

int main(){
    printf("Enter a 24-hour time: ");
    int h, m;
    scanf("%d:%d", &h, &m);
    int res = -1, dif;
    for(int i = 0; i < 8; ++i){
        int tem = abs(a[i][0] * 60 + a[i][1] - h * 60 - m);
        if(res == -1 || tem < dif) res = i, dif = tem;
    }
    printf("Closest departure time is %d:%02d %c.m., arriving at %d:%02d %c.m.", a[res][0] > 12 ? a[res][0] - 12 : a[res][0], a[res][1], a[res][0] >= 12 ? 'p' : 'a',
                                                                                 b[res][0] > 12 ? b[res][0] - 12 : b[res][0], b[res][1], b[res][0] >= 12 ? 'p' : 'a');
    return 0;
}