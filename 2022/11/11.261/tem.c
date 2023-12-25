#include<stdio.h>

int mon[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
struct Date{
	int y, m, d;
};

struct Date Date_init(int y, int m, int d){
	struct Date ans;
	ans.y = y;
	ans.m = m;
	ans.d = d;
	return ans;
}

int check(int y, int m){
	if(m != 2) return 0;
	if(y % 4) return 0;
	if(y % 400 == 0) return 1;
	if(y % 100 == 0) return 0;
	return 1;
}

struct Date solve(struct Date now, int days){
	while(days){
		int mon_day = mon[now.m] + check(now.y, now.m);
		if(days >= mon_day){
			days -= mon_day;
			now.m++;
		}
		else{
			now.d += days;
			if(now.d > mon_day) now.d -= mon_day, now.m++;
			days = 0;
		}
		if(now.m == 13) now.m = 1, now.y++;
	}
	return now;
}

int main(){
	//freopen("in", "r", stdin);
	int y, m, d;
	scanf("%d %d %d", &y, &m, &d);
	struct Date now = Date_init(y, m, d), to;
	int days;
	scanf("%d", &days);
	to = solve(now, days);
	printf("%d %d %d\n", to.y, to.m, to.d);
	return 0;
}


