#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
#define int long long
using namespace std;
const int maxn = 2005;
const int mod = 998244353;
int is_p[maxn], p[maxn], hsp[maxn],cnt;
vector<int> v[maxn];
long long n,m,c;
int q[2005];
int a[maxn],ans;
long long edans;

int f[(1<<13)+5][305];
int ksm(int a, int b){
	int mul = 1;
	while(b){
		if (b&1){
			mul = mul*a%mod;
		}
		a = a*a%mod;
		b >>= 1;
	}
	return mul;
}
void init(){
	for (int i = 2; i <= 2000; i++){ // 埃筛 
		if (!is_p[i]){
			p[++cnt] = i;
			hsp[i] = cnt;
		}
		for (int j = 2; j*i <= 2000; j++){
			is_p[i*j] = 1;
		}
	}
	for (int i = 2; i <= 2000; i++){
		for (int j = 1; j <= cnt; j++){
			if (i%p[j] == 0){
				if (j <= 13) q[i] |= (1<<j-1); //查看每个数的前13个质数的包含情况 
				v[i].push_back(j); //所有数的质因子 
			} 
		}
	}
}


vector<int> hvp;

int tt[(1<<13)+5];//不含当前状态的数一共有多少 
signed main(){
	freopen("in.txt", "r", stdin);
	//freopen("a.in","r",stdin);
	//freopen("card.out","w",stdout);
	cin >> n;
	init();
	for (int i = 1; i <= n; i++){
		long long val;
		cin >> val;
		a[val]++;
	}

	cin >> m;
	for (int i = 0; i < (1<<13); i++){//枚举不含哪些质数 
		for (int j = 2; j <= 2000; j++){
			if ( (q[j]&i) ) continue; //说明含了，continue 
			f[i][v[j][v[j].size()-1]] += a[j]; //个数加上这个数有多少 
			f[i][v[j][v[j].size()-1]] %= mod;
			tt[i] += a[j];
		}
		tt[i] += a[1];
	}
	
	
	for (int i = 1; i <= m; i++){
		
		edans = 0;
		hvp.clear();
		
		int less = 0;//询问序列与前十三个质数的交集 
		cin >> c;
		for (int j = 1; j <= c; j++){
			long long t;
			cin >> t;
			hvp.push_back(t);
			if (hsp[t] <= 13){
				less |= (1<<hsp[t]-1);
			}
		}
		sort(hvp.begin(),hvp.end());
		
		for (int j = 0; j < (1<<13); j++){
			if ( (j|less) != less) continue;
			int ct = tt[j];//一共有这么多数 
			ans = 1;
			for (int k = 0; k < c; k++){
				if (hvp[k] <= 41) continue;
				(ans *= (ksm(2,f[j][hsp[hvp[k]]])-1)) %= mod;//必须选 
				ct -= f[j][hsp[hvp[k]]];
			}
			(ans *= ksm(2,ct)) %= mod;//剩下的选不选都行 
			
			int cnt1 = 0;
			for (int k = 0; k <= 13; k++) cnt1 += (j>>k&1);//看看容斥是加还是减 
			if (cnt1&1) (edans -= ans)%=mod;
			else (edans+=ans)%=mod;
		}
		cout << (edans%mod+mod)%mod << endl;
	}
	
	return 0;
}