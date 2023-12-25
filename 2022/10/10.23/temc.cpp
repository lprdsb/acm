#include<iostream>
using namespace std;

int n, now_y = 1900, now_m = 1, now_d = 1, now_w = 1, ans[80];
int mon[20] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int check(){
	if(now_m != 2) return 0;
	if(now_y % 4 != 0) return 0;
	if(now_y % 400 == 0) return 1;
	if(now_y % 100 == 0) return 0;
	return 1;
}

int main(){
	cin >> n;
	while(666){
		now_d++; now_w++;
		if(now_w == 8) now_w = 1;
		if(now_d > mon[now_m] + check()) now_d = 1, now_m++;
		if(now_m == 13) now_y++, now_m = 1;
		if(now_y == 1900 + n) break;
		if(now_d == 13) ans[now_w]++;
	}
	for(int i = 1; i <= 7; ++i) cout << ans[i] << " ";
	return 0;
}


