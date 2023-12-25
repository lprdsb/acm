#include <cstdio>

using namespace std;
typedef long long ll;

const int mod = 998244353, pmd = 998244352;
int qpow(int x, int y)
{
	int ans = 1;
	while(y)
	{
		if(y & 1)
			ans = (ll)ans * x % mod;
		x = (ll)x * x % mod;
		y >>= 1;
	}
	return ans;
}
int k[514], p[514];

int main()
{
	freopen("in.txt", "r", stdin);
	int t, i, j, m, l, s, r, q, ans, tmp;
	ll n;
	scanf("%d", &t);
	while(t--)
	{
		ans = 0;
		scanf("%lld", &n);
		n--;
		for(i = 0; i <= 62; i++)
		{
			if((1ll << i) > n)
				continue;
			l = 2;
			k[1] = 2;
			p[1] = 0;
			k[2] = mod - 1;
			p[2] = pmd - 1;
			for(j = 1; j <= i; j++)
			{
				if(((n - (1ll << i)) >> (j - 1)) & 1)
					for(m = 1; m <= l; m++)
						k[m] = (ll)k[m] * qpow(2, p[m]) % mod;
				s = 0;
				for(m = 1; m <= l; m++)
				{
					q = qpow(2, 2 * p[m] + 1);
					r = qpow(mod + 1 - q, pmd - 1);
					s = (s + (ll)k[m] * r) % mod;
					k[m] = (ll)(mod - q) * r % mod * k[m] % mod;
					p[m] = 2ll * p[m] % pmd;
				}
				++l;
				k[l] = s;
				p[l] = pmd - 1;
			}
			s = ((n >> i) - 1) % pmd;
			tmp = 0;
			for(m = 1; m <= l; m++)
				tmp = (tmp + (ll)k[m] * qpow(2, (ll)p[m] * s % pmd)) % mod;
			tmp = (ll)tmp * qpow(2, pmd - i) % mod;
			ans = (ans + tmp) % mod;
		}
		printf("%d\n", ans);
	}
	return 0;
}