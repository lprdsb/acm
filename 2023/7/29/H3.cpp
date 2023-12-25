#include <bits/stdc++.h>
using i64 = long long;
constexpr int N = 200233;
int M[80'000'000], MM;

i64 space(const int *ans) {
	i64 res = 0;
	for (int _ = 1; _ <= ans[0]; ++_) {
		int tot = 0, *b = M + ans[_];
		for (int i = 3, s = b[0]; i <= s; i += 2) tot += b[i + 1] - b[i];
		res += i64(tot) * (b[2] - b[1]);
	}
	return res;
}

int * combine_1d(const int *a, const int *b) {
	int i = 2, n = a++[0], j = 2, m = b++[0];
	int * const res = M + MM, sz = 0;
	res[++sz] = std::max(a[0], b[0]);
	res[++sz] = std::min(a[1], b[1]);
	auto push = [res, &sz] (int l, int r) {
		if (sz == 2 || l > res[sz]) res[++sz] = l, res[++sz] = r;
		else res[sz] = std::max(res[sz], r);
	};
	while (i < n || j < m) {
		if (i == n) push(b[j], b[j + 1]), j += 2;
		else if (j == m) push(a[i], a[i + 1]), i += 2;
		else {
			int xl = a[i], xr = a[i + 1], yl = b[j], yr = b[j + 1];
			if (xr <= yl) push(xl, xr), i += 2;
			else if (yr <= xl) push(yl, yr), j += 2;
			else push(std::min(xl, yl), std::max(xr, yr)), i += 2, j += 2;
		}
	}
	res[0] = sz;
	MM += sz + 1;
	return res;
}

bool can_merge(const int *a, const int *b, int bl) {
	if (a[2] != bl || a[0] != b[0]) return false;
	for (int i = 3, n = a[0]; i <= n; ++i) if (a[i] != b[i]) return false;
	return true;
}

int * combine_2d(const int *a, const int *b) {
	static int tmpM[8000], tmpL[8000], tmpR[8000];
	int * const res = tmpM, sz = 0;
	int *l = tmpL, *r = tmpR;
	int i, j, an = a++[0], bn = b++[0];
	for (i = 0; i < an; ++i) l[2 * i] = M[a[i] + 1], l[2 * i + 1] = M[a[i] + 2];
	for (j = 0; j < bn; ++j) r[2 * j] = M[b[j] + 1], r[2 * j + 1] = M[b[j] + 2];
	auto push = [res, &sz] (const int *o, int bl, int br) {
		if (!sz || !can_merge(M + res[sz], o, bl)) {
			memcpy(M + MM, o, (o[0] + 1) * sizeof (int));
			res[++sz] = MM, MM += o[0] + 1;
			M[res[sz] + 1] = bl, M[res[sz] + 2] = br;
		}
		else M[res[sz] + 2] = br;
	};
	auto push_direct = [res, &sz] (const int *o, int bl, int br) {
		if (!sz || !can_merge(M + res[sz], o, bl)) {
			res[++sz] = int(o - M), M[res[sz] + 1] = bl, M[res[sz] + 2] = br;
		}
		else M[res[sz] + 2] = br;
	};
	i = j = 0;
	while (i < an || j < bn) {
		if (i == an) push(M + b[j], r[2 * j], r[2 * j + 1]), ++j;
		else if (j == bn) push(M + a[i], l[2 * i], l[2 * i + 1]), ++i;
		else {
			int xl = l[2 * i], xr = l[2 * i + 1], yl = r[2 * j], yr = r[2 * j + 1];
			if (xr <= yl) push(M + a[i], l[2 * i], l[2 * i + 1]), ++i;
			else if (yr <= xl) push(M + b[j], r[2 * j], r[2 * j + 1]), ++j;
			else {
				if (xl != yl) {
					int ll = std::max(xl, yl);
					if (xl != ll) push(M + a[i], xl, ll), l[2 * i] = ll;
					if (yl != ll) push(M + b[j], yl, ll), r[2 * j] = ll;
				} else {
					int rr = std::min(xr, yr);
					int *mm = combine_1d(M + a[i], M + b[j]);
					if (xr == yr) push_direct(mm, xl, yr), ++i, ++j;
					else if (xr < yr) push_direct(mm, xl, rr), r[2 * j] = rr, ++i;
					else push_direct(mm, yl, rr), l[2 * i] = rr, ++j;
				}
			}
		}
	}
	int * const ret = M + MM;
	memcpy(ret, res, (sz + 1) * sizeof (int));
	ret[0] = sz;
	MM += sz + 1;
	return ret;
}

// returns depth of table
void SparseTable(const int *v, int len) {
	int l1 = int(ceil(log2(len))) + 1;
	int *st = M + MM;
	MM += l1 * len;
	memcpy(st, v, len * sizeof(int));
	for (int j = 1; j < l1; ++j) {
		for (int i = 0, ii = (1 << (j - 1)); i + (1 << j) < len; ++i, ++ii) {
			st[j * len + i] = int(combine_2d(M + st[(j - 1) * len + i], M + st[(j - 1) * len + ii]) - M);
		}
	}
}

int *query(int *st, int len, int l, int r) {
	int lt = r - l + 1, q = int(ceil(log2(lt))) - 1;
	return combine_2d(M + st[q * len + l], M + st[q * len + r - (1 << q) + 1]);
}

int main() {
	freopen("in.txt", "r", stdin);
	int T;
	scanf("%d", &T);
	while (T--) {
		int n, q;
		scanf("%d%d", &n, &q);
		MM = 7 * n;
		// 1 pos 4 x y z w
		for (int i = 0; i < n; ++i) {
			M[7 * i] = 1;
			M[7 * i + 1] = 7 * i + 2;
			M[7 * i + 2] = 4;
			scanf("%d%d%d%d", M + 7 * i + 3, M + 7 * i + 5, M + 7 * i + 4, M + 7 * i + 6);
		}
		constexpr int B = 200;

		static int suf[N], pre[N], block[N];
		int bn = 0;
		for (int st = 0; st < n; st += B) {
			int bl = st, br = std::min(n - 1, st + B - 1);
			for (int i = bl; i <= br; ++i) {
				if (i == bl) suf[i] = 7 * i;
				else suf[i] = int(combine_2d(M + suf[i - 1], M + 7 * i) - M);
			}
			block[bn++] = suf[br];
			for (int i = br; i >= bl; --i) {
				if (i == br) pre[i] = 7 * i;
				else pre[i] = int(combine_2d(M + 7 * i, M + pre[i + 1]) - M);
			}
		}
		int *table = M + MM;
		SparseTable(block, bn);
		for (int i = 1; i <= q; ++i) {
			int s, t;
			scanf("%d%d", &s, &t);
			int bs = --s / B, bt = --t / B;
			int MM_store = MM;
			int *info = M + (MM++); info[0] = 0; // 0
			if (bs == bt) {
				while (s <= t) {
					info = combine_2d(info, M + 7 * s++);
				}
			}
			else if (bs + 1 == bt) {
				info = combine_2d(M + pre[s], M + suf[t]);
			}
			else {
				info = (bs + 1 == bt - 1 ? M + block[bs + 1] : query(table, bn, int(bs + 1), int(bt - 1)));
				info = combine_2d(M + pre[s], combine_2d(info, M + suf[t]));
			}
			i64 ans = space(info);
			printf("%lld\n", ans);
			MM = MM_store;
		}
        // puts("asd");
	}
	return 0;
}
