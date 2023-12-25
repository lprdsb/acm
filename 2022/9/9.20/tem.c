#include<stdio.h>
#define LL long long

LL l, r, l1, r1, as, a[50], cnt = 0;

int main(){
	//freopen("in", "r", stdin);
	scanf("%lld %lld", &l, &r);
	LL tem = 1;
	while(l){
		l1 += l % 10 * tem;
		tem *= 8;
		l /= 10;
	}
	tem = 1;
	while(r){
		r1 += r % 10 * tem;
		tem *= 8;
		r /= 10;
	}
	as = r1 / 7 - (l1 - 1) / 7;
	while(as){
		a[++cnt] = as % 8;
		as /= 8;
	}
	for(int i = cnt; i >= 1; --i) printf("%d", a[i]);
	puts("");
	return 0;
}


