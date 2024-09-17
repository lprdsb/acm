#include <bits/stdc++.h>
using namespace std;

using ll = long long;

constexpr int N = 100100;

string back = "rzxazuhcziyrzxaziyiusazuhcjusazuhcziyrzchsaxsrchsyiyrchcziyrzchsaxsrchshjyrzxazujyrchcziyrzxaziyiusazujyrchcziyrbyaziyiusazuhchsaxsrchsyaziyiusaxhsyiyrzxhsyazuhchsyaziyiusazuhchsaxsrchsyaziyiusazizchsyiyrzchsaxsrchsyiyrchcziyrzchsaxsrchbrzxazuhbrzchsyiyrzchsaxsrchsyiyrchcziyrzchsaxsrchshjyrzxacziyrzxaziyiusazuhchsacziyrzxazizchsyiyrzchsaxsrchsyiyrchcziyrzchsaxsrchshjyrzxazujyrchcziyrzxaziyiusazujyrchbrzxazuhbrzchsyiyrzchsaxsrchsyiyrchcziyrzchsaxsrchshjyrzxazujyrchcziyrzxaziyiusazujyrchcziyizuhchsyizujyrzxazujyrchcziyrzxaziyiusazujyrchcziyrbyazuhchsyaziyiusazuhchsaxsrchsyaziyizuhchsyizujyrzxazujyrchcziyrzxaziyiusazujyrchcziyrbyazuhchsyaziyiusazuhchsaxsrchsysrchshjyrzxazujyrchcziyrzxaziyiusazizchsyiyrzchsaxsrchsyiyrcjusazuhchshjyrzxazujyrchcziyrzxaziyiusazujyrchcziyrbyazuhchsyaziyiusazuhchsaxsrchsyaziyizuhchsyizujyrzxazujyrchcziyrzxaziyiusazujyrchcziyrbyazuhchsyaziyiusazuhchsaxsrchsyaziyiusaxhsyiyrzxhsyazuhchsyaziyiusazuhchsaxsrchsyaziyiusazizchsyiyrzchsaxsrchsyiyrchcziyrzchsaxhsyiyrzxhsyazuhchsyaziyiusazuhchsaxsrchsyaziyiusazizchsyiyrzchsaxsrchsyiyrchcziyrzcziyrbyazuhchsyaziyiusazuhchsaxsrchshjyrzxaziyiusazuhchsaxsyiyrzxacziyrzxaziyiusazuhchsacziyrzxazizchsyiyrzchsaxsrchsyiyrchcziyrzchsaxsrchshjyrzxazujyrchcziyrzxaziyiusazujyrchbrzxazuhbrzchsyiyrzchsaxsrchsyiyrchcziyrzchsaxsrchshjyrzxazujyrchcziyrzxaziyiusazujyrchcziyizuhchsyizujyrzxazujyrchcziyrzxaziyiusazujyrchcziyrbyazuhchsyaziyiusazuhchsaxsrchsyaziyizuhchsyizujyrzxazujyrchcziyrzxaziyiusazujyrchcziyrbyazuhchsyaziyiusazuhchsaxsrchsysrchshjyrzxazujyrchcziyrzxaziyiusazizchsyiyrzchsaxsrchsyiyrcjusazuhchshjyrzxazujyrchcziyrzxaziyiusazujyrchcziyrbyazuhchsyaziyiusazuhchsaxsrchsyaziyizuhchsyizujyrzxazujyrchcziyrzxaziyiusazujyrchcziyrbyazuhchsyaziyiusazuhchsaxsrchsyaziyiusaxhsyiyrzxhsyazuhchsyaziyiusazuhchsaxsrchsyaziyiusazizchsyiyrzchsaxsrchsyiyrchcziyrzchsaxhsyiyrzxhsyazuhchsyaziyiusazuhchsaxsrchsyaziyiusazizchsyiyrzchsaxsrchsyiyrchcziyrzcziyrbyazuhchsyaziyiusazuhchsaxsrchshjyrzxaziyiusazuhchsaxsyazuhchsyaziyiusazuhchsaxsrchsyaziyiusazizchsyiyrzchsaxsrchsyiyrchcziyrzchsaxsrchbrzxazuhbrzchsyiyrzchsaxsrchsyiyrchcziyrzchsaxsrchshjyrzxazujyrchcziyrzxaziyiusazujyrchcziyizuhchsyaziyiusazuhchsaxsrchsyaziyiusazizchsyiyrzchsaxsrchsyiyrchcziyrzchsaxsrchshchsyiyrchcziyrzxaziyizuhchsyizujyrzxazujyrchcziyrzxaziyiusazujyrchcziyrbyazuhchsyaziyiusazuhchsaxsrchsyaziyiusaxhsyiyrzxhsyazuhchsyaziyiusazuhchsaxsrchsyaziyiusazizchsyiyrzchsaxsrchsyiyrchcziyrzchsaxhsyiyrzxhsyazuhchsyaziyiusazuhchsaxsrchsyaziyiusazizchsyiyrzchsaxsrchsyiyrchcziyrzcziyrbyazuhchsyaziyiusazuhchsaxsrchshjyrzxazujyrchcziyrzxaziysrchsyiyrbyazuhchsyaziyiusazuhchsaxsrchsyaziyiusazizchsyiyrzchsaxsrchsyiyrchcziyrzchsaxhsyiyrzxhsyazuhchsyaziyiusazuhchsaxsrchsyaziyiusazizchsyiyrzchsaxsrchsyiyrchcziyrzchsaxsrchbrzxazuhbrzchsyiyrzchsaxsrchsyiyrchcziyrzchsaxsrchshjyrzxazujyrchcziyrzxaziyiusazujyrchbrzxazuhbrzchsyiyrzchsaxsrchsyiyrchcziyrzchsaxsrchshjyrzxazujyrchcziyrzxaziyiusazujusazizchsyiyrzchsaxsrchsyiyrchcziyrbyazuhchsyaziyiusazuhchsacziyrzxazizchsyiyrzchsaxsrchsyiyrchcziyrzchsaxsrchshjyrzxazujyrchcziyrzxaziyiusazizchsyiyrzchsaxsrchsyaziyizuhchsyizujyrzxazujyrchcziyrzxaziyiusazujyrchcziyrbyazuhchsyaziyiusazuhchsaxsrchsyaziyiusaxhsyiyrzxhsyazuhchsyaziyiusazuhchsaxsrchsyaziyiusazizchsyiyrzchsaxsrchsyiyrchcziyrzchsaxhsyiyrzxhsyazuhchsyaziyiusazuhchsaxsrchsyaziyiusazizchsyiyrzchsaxsrchsyiyrchcziyrzcziyrbyazuhchsyaziyiusazuhchsaxsrchshjyrzxazujyrchcziyrzxaziysrchsyiyrbyazuhchsyaziyiusazuhchsaxsrchsyaziyiusazizchsyiyrzchsaxsrchsyiyrchcziyrzchsaxhsyiyrzxhsyazuhchsyaziyiusazuhchsaxsrchsyaziyiusazizchsyiyrzchsaxsrchsyiyrchcziyrzchsaxsrchbrzxazuhbrzchsyiyrzchsaxsrchsyiyrchcziyrzchsaxsrchshjyrzxazujyrchcziyrzxaziyiusazujyrchbrzxazuhbrzchsyiyrzchsaxsrchsyiyrchcziyrzchsaxsrchshjyrzxazujyrchcziyrzxaziyiusazujusazizchsyiyrzchsaxsrchsyiyrchcziyrbyazuhchsyaziyiusazuhchsacziyrzxazizchsyiyrzchsaxsrchsyiyrchcziyrzchsaxsrchshjyrzxazujyrchcziyrzchsaxhsyiyrzxhsyazuhchsyaziyiusazuhchsaxsrchsyaziyiusazizchsyiyrzchsaxsrchsyiyrchcziyrzchsaxsrchbrzxazuhbrzchsyiyrzchsaxsrchsyiyrchcziyrzchsaxsrchshjyrzxazujyrchcziyrzxaziyiusazujyrchbrzxazuhbrzchsyiyrzchsaxsrchsyiyrchcziyrzchsaxsrchshjyrzxazujyrchcziyrzxaziyiusazujusazizchsyiyrzchsaxsrchsyiyrchcziyrbyazuhchsyaziyiusazuhchsacziyrzxazizchsyiyrzchsaxsrchsyiyrchcziyrzchsaxsrchshjyrzxaziyiusazuhchsaxsyiyrzxacziyrzxaziyiusazuhchsacziyrzxazizchsyiyrzchsaxsrchsyiyrchcziyrzchsaxsrchshjyrzxazujyrchcziyrzxaziyiusazujyrchbrzxazuhbrzchsyiyrzchsaxsrchsyiyrchcziyrzchsaxsrchshjyrzxazujyrchcziyrzxaziyiusazujyrchcziyizuhchsyizujyrzxazujyrchcziyrzxaziyiusazujyrchcziyrbyazuhchsyaziyiusazuhchsaxsrchsyaziyizuhchsyizujyrzxazujyrchcziyrzxaziyiusazujyrchcziyrbyazuhchsyaziyiusazuhchsaxsrchsysrchshjyrzxazujyrchcziyrzxaziyiusazizchsyiyrzchsaxsrchsyiyrcjusazuhchshjyrzxazujyrchcziyrzxaziyiusazujyrchcziyrbyazuhchsyaziyiusazuhchsaxsrchsyaziyizuhchsyizujyrzxazujyrchcziyrzxaziyiusazujyrchcziyrbyazuhchsyaziyiusazuhchsaxsrchsyaziyiusaxhsyiyrzxhsyazuhchsyaziyiusazuhchsaxsrchsyaziyiusazizchsyiyrzchsaxsrchsyiyrchcziyrzchsaxhsyiyrzxhsyazuhchsyaziyiusazuhchsaxsrchsyaziyiusazizchsyiyrzchsaxsrchsyiyrchcziyrzcziyrbyazuhchsyaziyiusazuhchsaxsrchshjyrzxaziyiusazuhchsaxsyiyrzxacziyrzxaziyiusazuhchsacziyrzxazizchsyiyrzchsaxsrchsyiyrchcziyrzchsaxsrchshjyrzxazujyrchcziyrzxaziyiusazujyrchbrzxazuhbrzchsyiyrzchsaxsrchsyiyrchcziyrzchsaxsrchshjyrzxazujyrchcziyrzxaziyiusazujyrchcziyizuhchsyizujyrzxazujyrchcziyrzxaziyiusazujyrchcziyrbyazuhchsyaziyiusazuhchsaxsrchsyaziyizuhchsyizujyrzxazujyrchcziyrzxaziyiusazujyrchcziyrbyazuhchsyaziyiusazuhchsaxsrchsysrchshjyrzxazujyrchcziyrzxaziyiusazizchsyiyrzchsaxsrchsyiyrcjusazuhchshjyrzxazujyrchcziyrzxaziyiusazujyrchcziyrbyazuhchsyaziyiusazuhchsaxsrchsyaziyizuhchsyizujyrzxazujyrchcziyrzxaziyiusazujyrchcziyrbyazuhchsyaziyiusazuhchsaxsrchsyaziyiusaxhsyiyrzxhsyazuhchsyaziyiusazuhchsaxsrchsyaziyiusazizchsyiyrzchsaxsrchsyiyrchcziyrzchsaxhsyiyrzxhsyazuhchsyaziyiusazuhchsaxsrchsyaziyiusazizchsyiyrzchsaxsrchsyiyrchcziyrzcziyrbyazuhchsyaziyiusazujyrchbrzxazuhbrzchsyiyrzchsaxsrchsyiyrchcziyrzchsaxsrchshjyrzxazujyrchcziyrzxaziyiusazujyrchcziyizuhchsyizujyrzxazujyrchcziyrzxaziyiusazujyrchcziyrbyazuhchsyaziyiusazuhchsaxsrchsyaziyizuhchsyizujyrzxazujyrchcziyrzxaziyiusazujyrchcziyrbyazuhchsyaziyiusazuhchsaxsrchsysrchshjyrzxaziyiusazuhchsaxsyiyrzxacziyrzxaziyiusazuhchsacziyrzxazizchsyiyrzchsaxsrchsyiyrchcziyrzchsaxsrchshjyrzxazujyrchcziyrzxaziyiusazujyrchbrzxazuhbrzchsyiyrzchsaxsrchsyiyrchcziyrzchsaxsrchshjyrzxazujyrchcziyrzxaziyiusazujyrchcziyizuhchsyizujyrzxazujyrchcziyrzxaziyiusazujyrchcziyrbyazuhchsyaziyiusazuhchsaxsrchsyaziyizuhchsyizujyrzxazujyrchcziyrzxaziyiusazujyrchcziyrbyazuhchsyaziyiusazuhchsaxsrchsysrchshjyrzxazujyrchcziyrzxaziyiusazizchsyiyrzchsaxsrchsyiyrcjusazuhchshjyrzxazujyrchcziyrzxaziyiusazujyrchcziyrbyazuhchsyaziyiusazuhchsaxsrchsyaziyizuhchsyizujyrzxazujyrchcziyrzxaziyiusazujyrchcziyrbyazuhchsyaziyiusazuhchsaxsrchsyaziyiusaxhsyiyrzxhsyazuhchsyaziyiusazuhchsaxsrchsyaziyiusazizchsyiyrzchsaxsrchsyiyrchcziyrzchsaxhsyiyrzxhsyazuhchsyaziyiusazuhchsaxsrchsyaziyiusazizchsyiyrzchsaxsrchsyiyrchcziyrzcziyrbyazuhchsyaziyiusazuhchsaxsrchshjyrzxaziyiusazuhchsaxsyiyrzxacziyrzxaziyiusazuhchsacziyrzxazizchsyiyrzchsaxsrchsyiyrchcziyrzchsaxsrchshjyrzxazujyrchcziyrzxaziyiusazujyrchbrzxazuhbrzchsyiyrzchsaxsrchsyiyrchcziyrzchsaxsrchshjyrzxazujyrchcziyrzxaziyiusazujyrchcziyizuhchsyizujyrzxazujyrchcziyrzxaziyiusazujyrchcziyrbyazuhchsyaziyiusazuhchsaxsrchsyaziyizuhchsyizujyrzxazujyrchcziyrzxaziyiusazujyrchcziyrbyazuhchsyaziyiusazuhchsaxsrchsysrchshjyrzxazujyrchcziyrzxaziyiusazizchsyiyrzchsaxsrchsyiyrcjusazuhchshjyrzxazujyrchcziyrzxaziyiusazujyrchcziyrbyazuhchsyaziyiusazuhchsaxsrchsyaziyizuhchsyizujyrzxazujyrchcziyrzxaziyiusazujyrchcziyrbyazuhchsyaziyiusazuhchsaxsrchsyaziyiusaxhsyiyrzxhsyazuhchsyaziyiusazuhchsaxsrchsyaziyiusazizchsyiyrzchsaxsrchsyiyrchcziyrzchsaxhsyiyrzxhsyazuhchsyaziyiusazuhchsaxsrchsyaziyiusazizchsyiyrzchsaxsrchsyiyrchcziyrzcziyrbyazuhchsyaziyiusazuhchsacziyrzxazizchsyiyrzchsaxsrchsyiyrchcziyrzchsaxsrchshjyrzxazujyrchcziyrzxaziyiusazujyrchbrzxazuhbrzchsyiyrzchsaxsrchsyiyrchcziyrzchsaxsrchshjyrzxazujyrchcziyrzxaziyiusazujyrchcziyizuhchsyizujyrzxazujyrchcziyrzxaziyiusazujyrchcziyrbyazuhchsyaziyiusazuhchsaxsrchsyaziyizuhchsyizujyrzxazujyrchcziyrzxaziyiusazujyrchcziyrbyazuhchsyaziyiusazuhchsaxsrchshjyrzxazujyrchcziyrzchsaxhsyiyrzxhsyazuhchsyaziyiusazuhchsaxsrchsyaziyiusazizchsyiyrzchsaxsrchsyiyrchcziyrzchsaxsrchbrzxazuhbrzchsyiyrzchsaxsrchsyiyrchcziyrzchsaxsrchshjyrzxazujyrchcziyrzxaziyiusazujyrchbrzxazuhbrzchsyiyrzchsaxsrchsyiyrchcziyrzchsaxsrchshjyrzxazujyrchcziyrzxaziyiusazujusazizchsyiyrzchsaxsrchsyiyrchcziyrbyazuhchsyaziyiusazuhchsacziyrzxazizchsyiyrzchsaxsrchsyiyrchcziyrzchsaxsrchshjyrzxazujyrchcziyrzxaziyiusazujyrchbrzxazuhbrzchsyiyrzchsaxsrchsyiyrchcziyrzchsaxsrchshjyrzxazujyrchcziyrzxaziyiusazujyrchcziyizuhchsyizujyrzxazujyrchcziyrzxaziyiusazujyrchcziyrbyazuhchsyaziyiusazuhchsaxsrchsyaziyizuhchsyizujyrzxazujyrchcziyrzxaziyiusazujyrchcziyrbyazuhchsyaziyiusazuhchsaxsrchsysrchshjyrzxazujyrchcziyrzxaziyiusazizchsyiyrzchsaxsrchsyiyrcjusazuhchshjyrzxazujyrchcziyrzxaziyiusazujyrchcziyrbyazuhchsyaziyiusazujyrchbrzxazuhbrzchsyiyrzchsaxsrchsyiyrchcziyrzchsaxsrchshjyrzxazujyrchcziyrzxaziyiusazujyrchcziyizuhchsyizujyrzxazujyrchcziyrzxaziyiusazujyrchcziyrbyazuhchsyaziyiusazuhchsaxsrchsyaziyizuhchsyizujyrzxazujyrchcziyrzxaziyiusazujyrchcziyrbyazuhchsyaziyiusazuhchsaxsrchsysrchshjyrzxazujyrchcziyrzxaziyiusazizchsyiyrzchsaxsrchsyiyrcjusazuhchshjyrzxazujyrchcziyrzxaziyiusazujyrchcziyrbyazuhchsaxsrchsyiyrchczxazuhcjusazuhchsaxsrchsyiyrcjusazuhchshjyrzxazujyrchcziyrzxaziyiusazujyrchcziyrbyazuhchsyaziyiusazuhchsaxsrchsyaziyizuhchsyizujyrzxazujyrchcziyrzxaziyiusazujyrchcziyrbyazuhchsyaziyiusazuhchsaxsrchsyaziyiusaxhsyiyrzxhsyazuhchsyaziyiusazuhchsaxsrchsyaziyiusazizchsyiyrzchsaxsrchsyiyrchcziyrzchsaxhsyiyrzxhsyazuhchsyaziyiusazuhchsaxsrchsyaziyiusazizchsyiyrzchsaxsrchsyiyrchcziyrzcziyrbyazuhchsyaziyiusazuhchsaxsrchshjyrzxazujyrchcziyrzxaziysrchsyiyrbyazuhchsyaziyiusazuhchsaxsrchsyaziyiusazizchsyiyrzchsaxsrchsyiyrchcziyrzchsaxhsyiyrzxhsyazuhchsyaziyiusazuhchsaxsrchsyaziyiusazizchsyiyrzchsaxsrchsyiyrchcziyrzchsaxsrchbrzxazuhbrzchsyiyrzchsaxsrchsyiyrchcziyrzchsaxsrchshjyrzxazujyrchcziyrzxaziyiusazujyrchbrzxazuhbrzchsyiyrzchsaxsrchsyiyrchcziyrzchsaxsrchshjyrzxazujyrchcziyrzxaziyiusazujusazizchsyiyrzchsaxsrchsyiyrchcziyrbyazuhchsaxsrchsyiyrchczxazuhcjusazuhchsaxsrchsyiyrcjusazuhchshjyrzxazujyrchcziyrzxaziyiusazujyrchcziyrbyazuhchsyaziyiusazuhchsaxsrchsyaziyizuhchsyizujyrzxazujyrchcziyrzxaziyiusazujyrchcziyrbyazuhchsyaziyiusazuhchsaxsrchsyaziyiusaxhsyiyrzxhsyazuhchsyaziyiusazuhchsaxsrchsyaziyiusazizchsyiyrzchsaxsrchsyiyrchcziyrzchsaxhsyiyrzxhsyazuhchsyaziyiusazuhchsaxsrchsyaziyiusazizchsyiyrzchsaxsrchsyiyrchcziyrzcziyrbyazuhchsyaziyiusazuhchsaxsrchshjyrzxazujyrchcziyrzxaziysrchsyiyrbyazuhchsyaziyiusazuhchsaxsrchsyaziyiusazizchsyiyrzchsaxsrchsyiyrchcziyrzchsaxhsyiyrzxhsyazuhchsyaziyiusazuhchsaxsrchsyaziyiusazizchsyiyrzchsaxsrchsyiyrchcziyrzchsaxsrchbrzxazuhbrzchsyiyrzchsaxsrchsyiyrchcziyrzchsaxsrchshjyrzxazujyrchcziyrzxaziyiusazujyrchbrzxazuhbrzchsyiyrzchsaxsrchsyiyrchcziyrzchsaxsrchshjyrzxazujyrchcziyrzxaziyiusazujusazizchsyiyrzchsaxsrchsyaziyizuhchsyizujyrzxazujyrchcziyrzxaziyiusazujyrchcziyrbyazuhchsyaziyiusazuhchsaxsrchsyaziyiusaxhsyiyrzxhsyazuhchsyaziyiusazuhchsaxsrchsyaziyiusazizchsyiyrzchsaxsrchsyiyrchcziyrzchsaxhsyiyrzxhsyazuhchsyaziyiusazuhchsaxsrchsyaziyiusazizchsyiyrzchsaxsrchsyiyrchcziyrzcziyrbyazuhchsaxsrchsyiyrchczxazuhcjusazuhchsaxsrchsyiyrcjusazuhchshjyrzxazujyrchcziyrzxaziyiusazujyrchcziyrbyazuhchsyaziyiusazuhchsaxsrchsyaziyizuhchsyizujyrzxazujyrchcziyrzxaziyiusazujyrchcziyrbyazuhchsyaziyiusazuhchsaxsrchsyaziyiusaxhsyiyrzxhsyazuhchsyaziyiusazuhchsaxsrchsyaziyiusazizchsyiyrzchsaxsrchsyiyrchcziyrzchsaxhsyiyrzxhsyazuhchsyaziyiusazuhchsaxsrchsyaziyiusazizchsyiyrzchsaxsrchsyiyrchcziyrzcziyrbyazuhchsyaziyiusazuhchsaxsrchshjyrzxazujyrchcziyrzxaziysrchsyiyrbyazuhchsyaziyiusazuhchsaxsrchsyaziyiusazizchsyiyrzchsaxsrchsyiyrchcziyrzchsaxhsyiyrzxhsyazuhchsyaziyiusazuhchsaxsrchsyaziyiusazizchsyiyrzchsaxsrchsyiyrchcziyrzchsaxsrchbrzxazuhbrzchsyiyrzchsaxsrchsyiyrchcziyrzchsaxsrchshjyrzxazujyrchcziyrzxaziyiusazujyrchbrzxazuhbrzchsyiyrzchsaxsrchsyiyrchcziyrzchsaxsrchshjyrzxazujyrchcziyrzxaziyiusazujusazizchsyiyrzchsaxsrchsyiyrchcziyrbyazuhchsaxsrchsyiyrchczxazuhcjusazuhchsaxsrchsyiyrcjusazuhchshjyrzxazujyrchcziyrzxaziyiusazujyrchcziyrbyazuhchsyaziyiusazuhchsaxsrchsyaziyizuhchsyizujyrzxazujyrchcziyrzxaziyiusazujyrchcziyrbyazuhchsyaziyiusazuhchsaxsrchsyaziyiusaxhsyiyrzxhsyazuhchsyaziyiusazuhchsaxsrchsyaziyiusazizchsyiyrzchsaxsrchsyiyrchcziyrzchsaxhsyiyrzxhsyazuhchsyaziyiusazuhchsaxsrchsyaziyiusazizchsyiyrzchsaxsrchsyiyrchcziyrzcziyrbyazuhchsyaziyiusazuhchsaxsrchshjyrzxazujyrchcziyrzxaziysrchsyiyrbyazuhchsyaziyiusazuhchsaxsrchsyaziyiusazizchsyiyrzchsaxsrchsyiyrchcziyrzchsaxhsyiyrzxhsyazuhchsyaziyiusazuhchsaxsrchsyaziyiusazizchsyiyrzchsaxsrchsyiyrchcziyrzchsaxsrchbrzxazuhbrzchsyiyrzchsaxsrchsyiyrchcziyrzchsaxsrchshjyrzxazujyrchcziyrzxaziyiusazujyrchbrzxazuhbrzchsyiyrzchsaxsrchsyiyrchcziyrzchsaxsrchshjyrzxazujyrchcziyrzxaziyiusazujusazizchsyiyrzchsaxsrchsyiyrcjusazuhchshjyrzxazujyrchcziyrzxaziyiusazujyrchcziyrbyazuhchsyaziyiusazuhchsaxsrchsyaziyizuhchsyizujyrzxazujyrchcziyrzxaziyiusazujyrchcziyrbyazuhchsyaziyiusazuhchsaxsrchsyaziyiusaxhsyiyrzxhsyazuhchsyaziyiusazuhchsaxsrchsyaziyiusazizchsyiyrzchsaxsrchsyiyrchcziyrzchsaxhsyiyrzxhjyrzxazujyrchcziyrzxaziyiusazujyrchcziyrbyazuhchsyaziyiusazuhchsaxsrchsyaziyiusaxhsyiyrzxhsyazuhchsyaziyiusazuhchsaxsrchsyaziyiusazizchsyiyrzchsaxsrchsyiyrchcziyrzchsaxsrchbrzxazuhbyazuhchsyaziyiusazuhchsaxsrchsyaziyiusazizchsyiyrzchsaxsrchsyiyrchcziyrzchsaxsrchbrzxazujyrchcziyrzxaziyiusazujyrchcziyrbyazuhchsyaziyiusazuhchsaxsrchsyaziyiusazixazuhchsaxsrchsyiyrchbrzxazuhbrzchsyiyrzchsaxsrchsyiyrchcziyrzchsaxsrchshjyrzxazujyrchcziyrzxaziyiusazujyrchcziyizuhchsyizujyrzxazujyrchcziyrzxaziyiusazujyrchcziyrbyazuhchsyaziyiusazuhchsaxsrchsyaziyizuhchsyizujyrzxazujyrchcziyrzxaziyiusazujyrchcziyrbyazuhchsyaziyiusazuhchsaxsrchsysrchshjyrzxazujyrchcziyrzxaziyiusazizchsyiyrzchsaxsrchsyiyrcjusazuhchshjyrzxazujyrchcziyrzxaziyiusazujyrchcziyrbyazuhchsyaziyiusazuhchsaxsrchsyaziyizuhchsyizujyrzxazujyrchcziyrzxaziyiusazujyrchcziyrbyazuhchsyaziyiusazuhchsaxsrchsyaziyiusaxhsyiyrzxhsyazuhchsyaziyiusazuhchsaxsrchsyaziyiusazizchsyiyrzchsaxsrchsyiyrchcziyrzchsaxhsyiyrzxhsyazuhchsyaziyiusazuhchsaxsrchsyaziyiusazizchsyiyrzchsaxsrchsyiyrchcziyrzcziyrbyazuhchsyaziyiusazuhchsaxsrchshjyrzxazujyrchcziyrzxaziysrchsyiyrbyazuhchsyaziyiusazuhchsaxsrchsyaziyiusazizchsyiyrzchsaxsrchsyiyrchcziyrbyazuhchsyaziyiusazujyrchbrzxazuhbrzchsyiyrzchsaxsrchsyiyrchcziyrzchsaxsrchshjyrzxazujyrchcziyrzxaziyiusazujyrchcziyizuhchsyizujyrzxazujyrchcziyrzxaziyiusazujyrchcziyrbyazuhchsyaziyiusazuhchsaxsrchsyaziyizuhchsyizujyrzxazujyrchcziyrzxaziyiusazujyrchcziyrbyazuhchsyaziyiusazuhchsaxsrchsysrchshjyrzxazujyrchcziyrzxaziyiusazizchsyiyrzchsaxsrchsyiyrcjusazuhchshjyrzxazujyrchcziyrzxaziyiusazujyrchcziyrbyazuhchsyaziyiusazuhchsaxsrchsyaziyizuhchsyizujyrzxazujyrchcziyrzxaziyiusazujyrchcziyrbyazuhchsyaziyiusazuhchsaxsrchsyaziyiusaxhsyiyrzxhsyazuhchsyaziyiusazuhchsaxsrchsyaziyiusazizchsyiyrzchsaxsrchsyiyrchcziyrzchsaxhsyiyrzxhsyazuhchsyaziyiusazuhchsaxsrchsyaziyiusazizchsyiyrzchsaxsrchsyiyrchcziyrzcziyrbyazuhchsyaziyiusazuhchsaxsrchshjyrzxazujyrchcziyrzxaziysrchsyiyrbyazuhchsyaziyiusazuhchsaxsrchsyaziyiusazizchsyiyrzchsaxsrchsyaziyizuhchsyizujyrzxazujyrchcziyrzxaziyiusazujyrchcziyrbyazuhchsyaziyiusazuhchsaxsrchsyaziyiusaxhsyiyrzxhsyazuhchsyaziyiusazuhchsaxsrchsyaziyiusazizchsyiyrzchsaxsrchsyiyrchcziyrzchsaxhsyiyrzxhsyazuhchsyaziyiusazuhchsaxsrchsyaziyiusazizchsyiyrzchsaxsrchsyiyrchcziyrzcziyrbyazuhchsyaziyiusazuhchsaxsrchshjyrzxazujyrchcziyrzxaziysrchsyiyrbyazuhchsyaziyiusazuhchsaxsrchsyaziyiusazizchsyiyrchcziyrzxaziyiuhchsyiysrchsyiyrchcziyrzxaziysrchsyiyrbyazuhchsyaziyiusazuhchsaxsrchsyaziyiusazizchsyiyrzchsaxsrchsyiyrchcziyrzchsaxhsyiyrzxhsyazuhchsyaziyiusazuhchsaxsrchsyaziyiusazizchsyiyrzchsaxsrchsyiyrchcziyrzchsaxsrchbrzxazuhbrzchsyiyrzchsaxsrchsyiyrchcziyrzchsaxsrchshjyrzxazujyrchcziyrzxaziyiusazujyrchbrzxazuhbrzchsyiyrzchsaxsrchsyiyrchcziyrzchsaxsrchshjyrzxazujyrchcziyrzxaziyiusazujusazizchsyiyrzchsaxsrchsyiyrchcziyrbyazuhchsyaziyiusazuhchsacziyrzxazizchsyiyrzchsaxsrchsyiyrchcziyrzchsaxsrchshjyrzxazujyrchcziyrzxaziyiusazujyrchbrzxazuhbrzchsyiyrzchsaxsrchsyiyrchcziyrzchsaxsrchshjyrzxazujyrchcziyrzxaziyiusazujyrchcziyizuhchsyizujyrzxazujyrchcziyrzxaziyiusazujyrchcziyrbyazuhchsyaziyiusazuhchsaxsrchsyaziyizuhchsyizujyrzxazujyrchcziyrzxaziyiusazujyrchcziyrbyazuhchsyaziyiusazuhchsaxsrchsysrchshjyrzxazujyrchcziyrzxaziyiusazizchsyiyrchcziyrzxaziyiuhchsyiysrchsyiyrchcziyrzxaziysrchsyiyrbyazuhchsyaziyiusazuhchsaxsrchsyaziyiusazizchsyiyrzchsaxsrchsyiyrchcziyrzchsaxhsyiyrzxhsyazuhchsyaziyiusazuhchsaxsrchsyaziyiusazizchsyiyrzchsaxsrchsyiyrchcziyrzchsaxsrchbrzxazuhbrzchsyiyrzchsaxsrchsyiyrchcziyrzchsaxsrchshjyrzxazujyrchcziyrzxaziyiusazujyrchbrzxazuhbrzchsyiyrzchsaxsrchsyiyrchcziyrzchsaxsrchshjyrzxazujyrchcziyrzxaziyiusazujusazizchsyiyrzchsaxsrchsyiyrchcziyrbyazuhchsyaziyiusazuhchsacziyrzxazizchsyiyrzchsaxsrchsyiyrchcziyrzchsaxsrchshjyrzxazujyrchcziyrzxaziyiusazujyrchbrzxazuhbrzchsyiyrzchsaxsrchsyiyrchcziyrzchsaxsrchshjyrzxazujyrchcziyrzxaziyiusazujyrchcziyizuhchsyizujyrzxazujyrchcziyrzxaziyiusazujyrchcziyrbyazuhchsyaziyiusazuhchsaxsrchsyaziyizuhchsyizujyrzxazujyrchcziyrzxaziyiusazujyrchcziyrbyazuhchsyaziyiusazuhchsaxsrchsysrchshjyrzxazujyrchcziyrzchsaxhsyiyrzxhsyazuhchsyaziyiusazuhchsaxsrchsyaziyiusazizchsyiyrzchsaxsrchsyiyrchcziyrzchsaxsrchbrzxazuhbrzchsyiyrzchsaxsrchsyiyrchcziyrzchsaxsrchshjyrzxazujyrchcziyrzxaziyiusazujyrchbrzxazuhbrzchsyiyrzchsaxsrchsyiyrchcziyrzchsaxsrchshjyrzxazujyrchcziyrzxaziyiusazujusazizchsyiyrchcziyrzxaziyiuhchsyiysrchsyiyrchcziyrzxaziysrchsyiyrbyazuhchsyaziyiusazuhchsaxsrchsyaziyiusazizchsyiyrzchsaxsrchsyiyrchcziyrzchsaxhsyiyrzxhsyazuhchsyaziyiusazuhchsaxsrchsyaziyiusazizchsyiyrzchsaxsrchsyiyrchcziyrzchsaxsrchbrzxazuhbrzchsyiyrzchsaxsrchsyiyrchcziyrzchsaxsrchshjyrzxazujyrchcziyrzxaziyiusazujyrchbrzxazuhbrzchsyiyrzchsaxsrchsyiyrchcziyrzchsaxsrchshjyrzxazujyrchcziyrzxaziyiusazujusazizchsyiyrzchsaxsrchsyiyrchcziyrbyazuhchsyaziyiusazuhchsacziyrzxazizchsyiyrzchsaxsrchsyiyrchcziyrzchsaxsrchshjyrzxazujyrchcziyrzxaziyiusazujyrchbrzxazuhbrzchsyiyrzchsaxsrchsyiyrchcziyrzchsaxsrchshjyrzxazujyrchcziyrzxaziyiusazujyrchcziyizuhchsyizujyrzxazujyrchcziyrzxaziyiusazujyrchcziyrbyazuhchsyaziyiusazuhchsaxsrchsyaziyizuhchsyizujyrzxazujyrchcziyrzxaziyiusazujyrchcziyrbyazuhchsyaziyiusazuhchsaxsrchsysrchshjyrzxazujyrchcziyrzxaziyiusazizchsyiyrchcziyrzxaziyiuhchsyiysrchsyiyrchcziyrzxaziysrchsyiyrbyazuhchsyaziyiusazuhchsaxsrchsyaziyiusazizchsyiyrzchsaxsrchsyiyrchcziyrzchsaxhsyiyrzxhsyazuhchsyaziyiusazuhchsaxsrchsyaziyiusazizchsyiyrzchsaxsrchsyiyrchcziyrzchsaxsrchbrzxazuhbrzchsyiyrzchsaxsrchsyiyrchcziyrzchsaxsrchshjyrzxazujyrchcziyrzxaziyiusazujyrchbrzxazuhbrzchsyiyrzchsaxsrchsyiyrchcziyrzchsaxsrchshjyrzxazujyrchcziyrzxaziyiusazujusazizchsyiyrzchsaxsrchsyiyrchcziyrbyazuhchsyaziyiusazuhchsacziyrzxazizchsyiyrzchsaxsrchsyiyrchcziyrzchsaxsrchshjyrzxazujyrchcziyrzxaziyiusazujyrchbrzxazuhbrzchsyiyrzchsaxsrchsyiyrchcziyrzchsaxsrchshjyrzxazujyrchcziyrzxaziyiusazujyrchcziyizuhchsyizujyrzxazujyrchcziyrzxaziyiusazujyrchcziyrbyazuhchsyaziyiusazuhchsaxsrchsyaziyizuhchsyizujyrzxazujyrchcziyrzxaziyiusazujyrchcziyrbyazuhchsyaziyiusazuhchsaxsrchsysrchshjyrzxazujyrchcziyrzxaziysrchsyiyrbyazuhchsyaziyiusazuhchsaxsrchsyaziyiusazizchsyiyrzchsaxsrchsyiyrchcziyrzchsaxhsyiyrzxhsyazuhchsyaziyiusazuhchsaxsrchsyaziyiusazizchsyiyrzchsaxsrchsyiyrchcziyrzchsaxsrchbrzxazuhbrzchsyiyrzchsaxsrchsyiyrchcziyrzchsaxsrchshjyrzxazujyrchcziyrzxaziyiusazujyrchbrzxazuhbrzchsyiyrzchsaxsrchsyiyrchcziyrzchsaxsrchshjyrzxazujyrchcziyrzxaziyiusazizchsyiyrzchsaxsrchsyaziyizuhchsyizujyrzxazujyrchcziyrzxaziyiusazujyrchcziyrbyazuhchsyaziyiusazuhchsaxsrchsyaziyiusaxhsyiyrzxhsyazuhchsyaziyiusazuhchsaxsrchsyaziyiusazizchsyiyrzchsaxsrchsyiyrchcziyrzchsaxhsyiyrzxhsyazuhchsyaziyiusazuhchsaxsrchsyaziyiusazizchsyiyrzchsaxsrchsyiyrchcziyrzcziyrbyazuhchsyaziyiusazuhchsaxsrchshjyrzxazujyrchcziyrzxaziysrchsyiyrbyazuhchsyaziyiusazuhchsaxsrchsyaziyiusazizchsyiyrzchsaxsrchsyiyrchcziyrzchsaxhsyiyrzxhsyazuhchsyaziyiusazuhchsaxsrchsyaziyiusazizchsyiyrzchsaxsrchsyiyrchcziyrzchsaxsrchbrzxazuhbrzchsyiyrzchsaxsrchsyiyrchcziyrzchsaxsrchshjyrzxazujyrchcziyrzxaziyiusazujyrchbrzxazuhbrzchsyiyrzchsaxsrchsyiyrchcziyrzchsaxsrchshjyrzxazujyrchcziyrzxaziyiusazujusazizchsyiyrzchsaxsrchsyiyrchcziyrbyazuhchsyaziyiusazuhchsacziyrzxazizchsyiyrzchsaxsrchsyiyrchcziyrzchsaxsrchshjyrzxazujyrchcziyrzchsaxhsyiyrzxhsyazuhchsyaziyiusazuhchsaxsrchsyaziyiusazizchsyiyrzchsaxsrchsyiyrchcziyrzchsaxsrchbrzxazuhbrzchsyiyrzchsaxsrchsyiyrchcziyrzchsaxsrchshjyrzxazujyrchcziyrzxaziyiusazujyrchbrzxazuhbrzchsyiyrzchsaxsrchsyiyrchcziyrzchsaxsrchshjyrzxazujyrchcziyrzxaziyiusazujusazizchsyiyrzchsaxsrchsyiyrchcziyrbyazuhchsyaziyiusazuhchsacziyrzxazizchsyiyrzchsaxsrchsyiyrchcziyrzchsaxsrchshjyrzxaziyiusazuhchsaxsyiyrzxacziyrzxaziyiusazuhchsacziyrzxazizchsyiyrzchsaxsrchsyiyrchcziyrzchsaxsrchshjyrzxazujyrchcziyrzxaziyiusazujyrchbrzxazuhbrzchsyiyrzchsaxsrchsyiyrchcziyrzchsaxsrchshjyrzxazujyrchcziyrzxaziyiusazujyrchcziyizuhchsyizujyrzxazujyrchcziyrzxaziyiusazujyrchcziyrbyazuhchsyaziyiusazuhchsaxsrchsyaziyizuhchsyizujyrzxazujyrchcziyrzxaziyiusazujyrchcziyrbyazuhchsyaziyiusazuhchsaxsrchsysrchshjyrzxazujyrchcziyrzxaziyiusazizchsyiyrzchsaxsrchsyiyrcjusazuhchshjyrzxazujyrchcziyrzxaziyiusazujyrchcziyrbyazuhchsyaziyiusazuhchsaxsrchsyaziyizuhchsyizujyrzxazujyrchcziyrzxaziyiusazujyrchcziyrbyazuhchsyaziyiusazuhchsaxsrchsyaziyiusaxhsyiyrzxhsyazuhchsyaziyiusazuhchsaxsrchsyaziyiusazizchsyiyrzchsaxsrchsyiyrchcziyrzchsaxhsyiyrzxhsyazuhchsyaziyiusazuhchsaxsrchsyaziyiusazizchsyiyrzchsaxsrchsyiyrchcziyrzcziyrbyazuhchsyaziyiusazuhchsaxsrchshjyrzxaziyiusazuhchsaxsyiyrzxacziyrzxaziyiusazuhchsacziyrzxazizchsyiyrzchsaxsrchsyiyrchcziyrzchsaxsrchshjyrzxazujyrchcziyrzxaziyiusazujyrchbrzxazuhbrzchsyiyrzchsaxsrchsyiyrchcziyrzchsaxsrchshjyrzxazujyrchcziyrzxaziyiusazujyrchcziyizuhchsyizujyrzxazujyrchcziyrzxaziyiusazujyrchcziyrbyazuhchsyaziyiusazuhchsaxsrchsyaziyizuhchsyizujyrzxazujyrchcziyrzxaziyiusazujyrchcziyrbyazuhchsyaziyiusazuhchsaxsrchsysrchshjyrzxazujyrchcziyrzxaziyiusazizchsyiyrzchsaxsrchsyiyrcjusazuhchshjyrzxazujyrchcziyrzxaziyiusazujyrchcziyrbyazuhchsyaziyiusazuhchsaxsrchsyaziyizuhchsyizujyrzxazujyrchcziyrzxaziyiusazujyrchcziyrbyazuhchsyaziyiusazuhchsaxsrchsyaziyiusaxhsyiyrzxhsyazuhchsyaziyiusazuhchsaxsrchsyaziyiusazizchsyiyrzchsaxsrchsyiyrchcziyrzchsaxhsyiyrzxhsyazuhchsyaziyiusazuhchsaxsrchsyaziyiusazizchsyiyrzchsaxsrchsyiyrchcziyrzcziyrbyazuhchsyaziyiusazujyrchbrzxazuhbrzchsyiyrzchsaxsrchsyiyrchcziyrzchsaxsrchshjyrzxazujyrchcziyrzxaziyiusazujyrchcziyizuhchsyizujyrzxazujyrchcziyrzxaziyiusazujyrchcziyrbyazuhchsyaziyiusazuhchsaxsrchsyaziyizuhchsyizujyrzxazujyrchcziyrzxaziyiusazujyrchcziyrbyazuhchsyaziyiusazuhchsaxsrchsysrchshjyrzxaziyiusazuhchsaxsyiyrzxacziyrzxaziyiusazuhchsacziyrzxazizchsyiyrzchsaxsrchsyiyrchcziyrzchsaxsrchshjyrzxazujyrchcziyrzxaziyiusazujyrchbrzxazuhbrzchsyiyrzchsaxsrchsyiyrchcziyrzchsaxsrchshjyrzxazujyrchcziyrzxaziyiusazujyrchcziyizuhchsyizujyrzxazujyrchcziyrzxaziyiusazujyrchcziyrbyazuhchsyaziyiusazuhchsaxsrchsyaziyizuhchsyizujyrzxazujyrchcziyrzxaziyiusazujyrchcziyrbyazuhchsyaziyiusazuhchsaxsrchsysrchshjyrzxazujyrchcziyrzxaziyiusazizchsyiyrzchsaxsrchsyiyrcjusazuhchshjyrzxazujyrchcziyrzxaziyiusazujyrchcziyrbyazuhchsyaziyiusazuhchsaxsrchsyaziyizuhchsyizujyrzxazujyrchcziyrzxaziyiusazujyrchcziyrbyazuhchsyaziyiusazuhchsaxsrchsyaziyiusaxhsyiyrzxhsyazuhchsyaziyiusazuhchsaxsrchsyaziyiusazizchsyiyrzchsaxsrchsyiyrchcziyrzchsaxhsyiyrzxhsyazuhchsyaziyiusazuhchsaxsrchsyaziyiusazizchsyiyrzchsaxsrchsyiyrchcziyrzcziyrbyazuhchsyaziyiusazuhchsaxsrchshjyrzxaziyiusazuhchsaxsyiyrzxacziyrzxaziyiusazuhchsacziyrzxazizchsyiyrzchsaxsrchsyiyrchcziyrzchsaxsrchshjyrzxazujyrchcziyrzxaziyiusazujyrchbrzxazuhbrzchsyiyrzchsaxsrchsyiyrchcziyrzchsaxsrchshjyrzxazujyrchcziyrzxaziyiusazujyrchcziyizuhchsyizujyrzxazujyrchcziyrzxaziyiusazujyrchcziyrbyazuhchsyaziyiusazuhchsaxsrchsyaziyizuhchsyizujyrzxazujyrchcziyrzxaziyiusazujyrchcziyrbyazuhchsyaziyiusazuhchsaxsrchsysrchshjyrzxazujyrchcziyrzxaziyiusazizchsyiyrzchsaxsrchsyiyrcjusazuhchshjyrzxazujyrchcziyrzxaziyiusazujyrchcziyrbyazuhchsyaziyiusazuhchsaxsrchsyaziyizuhchsyizujyrzxazujyrchcziyrzxaziyiusazujyrchcziyrbyazuhchsyaziyiusazuhchsaxsrchsyaziyiusaxhsyiyrzxhsyazuhchsyaziyiusazuhchsaxsrchsyaziyiusazizchsyiyrzchsaxsrchsyiyrchcziyrzchsaxhsyiyrzxhsyazuhchsyaziyiusazuhchsaxsrchsyaziyiusazizchsyiyrzchsaxsrchsyiyrchcziyrzcziyrbyazuhchsyaziyiusazuhchsacziyrzxazizchsyiyrzchsaxsrchsyiyrchcziyrzchsaxsrchshjyrzxazujyrchcziyrzxaziyiusazujyrchbrzxazuhbrzchsyiyrzchsaxsrchsyiyrchcziyrzchsaxsrchshjyrzxazujyrchcziyrzxaziyiusazujyrchcziyizuhchsyizujyrzxazujyrchcziyrzxaziyiusazujyrchcziyrbyazuhchsyaziyiusazuhchsaxsrchsyaziyizuhchsyizchsyiyrzchsaxsrchsyiyrchcziyrzchsaxsrchshjyrzxazujyrchcziyrzxaziyiusazujyrchcziyizuhchsyizujyrzxazujyrchcziyrzxaziyiusazujyrchcziyrbyazuhchsyaziyiusazuhchsaxsrchsyaziyiusaxhsyiyrzchsaxsrchsyiyrchcziyrzchsaxsrchshjyrzxazujyrchcziyrzxaziyiusazujyrchcziyrbiyrzxaziyiusazuhchsaxhsyiyrzxhsyazuhchsyaziyiusazuhchsaxsrchsyaziyiusazizchsyiyrzchsaxsrchsyiyrchcziyrzchsaxsrchbrzxazuhbrzchsyiyrzchsaxsrchsyiyrchcziyrzchsaxsrchshjyrzxazujyrchcziyrzxaziyiusazujyrchbrzxazuhbrzchsyiyrzchsaxsrchsyiyrchcziyrzchsaxsrchshjyrzxazujyrchcziyrzxaziyiusazujusazizchsyiyrzchsaxsrchsyiyrchcziyrbyazuhchsyaziyiusazuhchsacziyrzxazizchsyiyrzchsaxsrchsyiyrchcziyrzchsaxsrchshjyrzxazujyrchcziyrzxaziyiusazujyrchbrzxazuhbrzchsyiyrzchsaxsrchsyiyrchcziyrzchsaxsrchshjyrzxazujyrchcziyrzxaziyiusazujyrchcziyizuhchsyizujyrzxazujyrchcziyrzxaziyiusazujyrchcziyrbyazuhchsyaziyiusazuhchsaxsrchsyaziyizuhchsyizujyrzxazujyrchcziyrzxaziyiusazujyrchcziyrbyazuhchsyaziyiusazuhchsaxsrchsysrchshjyrzxazujyrchcziyrzxaziyiusazizchsyiyrzchsaxsrchsyiyrcjusazuhchshjyrzxazujyrchcziyrzxaziyiusazujyrchcziyrbyazuhchsyaziyiusazuhchsaxsrchshjyrzxazujyrchcziyrzchsaxhsyiyrzxhsyazuhchsyaziyiusazuhchsaxsrchsyaziyiusazizchsyiyrzchsaxsrchsyiyrchcziyrzchsaxsrchbrzxazuhbrzchsyiyrzchsaxsrchsyiyrchcziyrzchsaxsrchshjyrzxazujyrchcziyrzxaziyiusazujyrchbrzxazuhbrzchsyiyrzchsaxsrchsyiyrchcziyrzchsaxsrchshjyrzxazujyrchcziyrzxaziyiusazujusazizchsyiyrzchsaxsrchsyiyrchcziyrbyazuhchsyaziyiusazuhchsacziyrzxazizchsyiyrzchsaxsrchsyiyrchcziyrzchsaxsrchshjyrzxazujyrchcziyrzxaziyiusazujyrchbrzxazuhbrzchsyiyrzchsaxsrchsyiyrchcziyrzchsaxsrchshjyrzxazujyrchcziyrzxaziyiusazujyrchcziyizuhchsyizujyrzxazujyrchcziyrzxaziyiusazujyrchcziyrbyazuhchsyaziyiusazuhchsaxsrchsyaziyizuhchsyizujyrzxazujyrchcziyrzxaziyiusazujyrchcziyrbyazuhchsyaziyiusazuhchsaxsrchsysrchshjyrzxazujyrchcziyrzxaziyiusazizchsyiyrzchsaxsrchsyiyrcjusazuhchshjyrzxazujyrchcziyrzxaziyiusazujyrchcziyrbyazuhchsyaziyiusazujyrchbrzxazuhbrzchsyiyrzchsaxsrchsyiyrchcziyrzchsaxsrchshjyrzxazujyrchcziyrzxaziyiusazujyrchcziyizuhchsyizujyrzxazujyrchcziyrzxaziyiusazujyrchcziyrbyazuhchsyaziyiusazuhchsaxsrchsyaziyizuhchsyizujyrzxazujyrchcziyrzxaziyiusazujyrchcziyrbyazuhchsyaziyiusazuhchsaxsrchsysrchshjyrzxazujyrchcziyrzxaziyiusazizchsyiyrzchsaxsrchsyiyrcjusazuhchshjyrzxazujyrchcziyrzxaziyiusazujyrchcziyrbyazuhchsaxsrchsyiyrchczxazuhcjusazuhchsaxsrchsyiyrcjusazuhchshjyrzxazujyrchcziyrzxaziyiusazujyrchcziyrbyazuhchsyaziyiusazuhchsaxsrchsyaziyizuhchsyizujyrzxazujyrchcziyrzxaziyiusazujyrchcziyrbyazuhchsyaziyiusazuhchsaxsrchsyaziyiusaxhsyiyrzxhsyazuhchsyaziyiusazuhchsaxsrchsyaziyiusazizchsyiyrzchsaxsrchsyiyrchcziyrzchsaxhsyiyrzxhsyazuhchsyaziyiusazuhchsaxsrchsyaziyiusazizchsyiyrzchsaxsrchsyiyrchcziyrzcziyrbyazuhchsyaziyiusazuhchsaxsrchshjyrzxazujyrchcziyrzxaziysrchsyiyrbyazuhchsyaziyiusazuhchsaxsrchsyaziyiusazizchsyiyrzchsaxsrchsyiyrchcziyrzchsaxhsyiyrzxhsyazuhchsyaziyiusazuhchsaxsrchsyaziyiusazizchsyiyrzchsaxsrchsyiyrchcziyrzchsaxsrchbrzxazuhbrzchsyiyrzchsaxsrchsyiyrchcziyrzchsaxsrchshjyrzxazujyrchcziyrzxaziyiusazujyrchbrzxazuhbrzchsyiyrzchsaxsrchsyiyrchcziyrzchsaxsrchshjyrzxazujyrchcziyrzxaziyiusazujusazizchsyiyrzchsaxsrchsyiyrchcziyrbyazuhchsaxsrchsyiyrchczxazuhcjusazuhchsaxsrchsyiyrcjusazuhchshjyrzxazujyrchcziyrzxaziyiusazujyrchcziyrbyazuhchsyaziyiusazuhchsaxsrchsyaziyizuhchsyizujyrzxazujyrchcziyrzxaziyiusazujyrchcziyrbyazuhchsyaziyiusazuhchsaxsrchsyaziyiusaxhsyiyrzxhsyazuhchsyaziyiusazuhchsaxsrchsyaziyiusazizchsyiyrzchsaxsrchsyiyrchcziyrzchsaxhsyiyrzxhsyazuhchsyaziyiusazuhchsaxsrchsyaziyiusazizchsyiyrzchsaxsrchsyiyrchcziyrzcziyrbyazuhchsyaziyiusazuhchsaxsrchshjyrzxazujyrchcziyrzxaziysrchsyiyrbyazuhchsyaziyiusazuhchsaxsrchsyaziyiusazizchsyiyrzchsaxsrchsyiyrchcziyrzchsaxhsyiyrzxhsyazuhchsyaziyiusazuhchsaxsrchsyaziyiusazizchsyiyrzchsaxsrchsyiyrchcziyrzchsaxsrchbrzxazuhbrzchsyiyrzchsaxsrchsyiyrchcziyrzchsaxsrchshjyrzxazujyrchcziyrzxaziyiusazujyrchbrzxazuhbrzchsyiyrzchsaxsrchsyiyrchcziyrzchsaxsrchshjyrzxazujyrchcziyrzxaziyiusazujusazizchsyiyrzchsaxsrchsyaziyizuhchsyizujyrzxazujyrchcziyrzxaziyiusazujyrchcziyrbyazuhchsyaziyiusazuhchsaxsrchsyaziyiusaxhsyiyrzxhsyazuhchsyaziyiusazuhchsaxsrchsyaziyiusazizchsyiyrzchsaxsrchsyiyrchcziyrzchsaxhsyiyrzxhsyazuhchsyaziyiusazuhchsaxsrchsyaziyiusazizchsyiyrzchsaxsrchsyiyrchcziyrzcziyrbyazuhchsaxsrchsyiyrchczxazuhcjusazuhchsaxsrchsyiyrcjusazuhchshjyrzxazujyrchcziyrzxaziyiusazujyrchcziyrbyazuhchsyaziyiusazuhchsaxsrchsyaziyizuhchsyizujyrzxazujyrchcziyrzxaziyiusazujyrchcziyrbyazuhchsyaziyiusazuhchsaxsrchsyaziyiusaxhsyiyrzxhsyazuhchsyaziyiusazuhchsaxsrchsyaziyiusazizchsyiyrzchsaxsrchsyiyrchcziyrzchsaxhsyiyrzxhsyazuhchsyaziyiusazuhchsaxsrchsyaziyiusazizchsyiyrzchsaxsrchsyiyrchcziyrzcziyrbyazuhchsyaziyiusazuhchsaxsrchshjyrzxazujyrchcziyrzxaziysrchsyiyrbyazuhchsyaziyiusazuhchsaxsrchsyaziyiusazizchsyiyrzchsaxsrchsyiyrchcziyrzchsaxhsyiyrzxhsyazuhchsyaziyiusazuhchsaxsrchsyaziyiusazizchsyiyrzchsaxsrchsyiyrchcziyrzchsaxsrchbrzxazuhbrzchsyiyrzchsaxsrchsyiyrchcziyrzchsaxsrchshjyrzxazujyrchcziyrzxaziyiusazujyrchbrzxazuhbrzchsyiyrzchsaxsrchsyiyrchcziyrzchsaxsrchshjyrzxazujyrchcziyrzxaziyiusazujusazizchsyiyrzchsaxsrchsyiyrchcziyrbyazuhchsaxsrchsyiyrchczxazuhcjusazuhchsaxsrchsyiyrcjusazuhchshjyrzxazujyrchcziyrzxaziyiusazujyrchcziyrbyazuhchsyaziyiusazuhchsaxsrchsyaziyizuhchsyizujyrzxazujyrchcziyrzxaziyiusazujyrchcziyrbyazuhchsyaziyiusazuhchsaxsrchsyaziyiusaxhsyiyrzxhsyazuhchsyaziyiusazuhchsaxsrchsyaziyiusazizchsyiyrzchsaxsrchsyiyrchcziyrzchsaxhsyiyrzxhsyazuhchsyaziyiusazuhchsaxsrchsyaziyiusazizchsyiyrzchsaxsrchsyiyrchcziyrzcziyrbyazuhchsyaziyiusazuhchsaxsrchshjyrzxazujyrchcziyrzxaziysrchsyiyrbyazuhchsyaziyiusazuhchsaxsrchsyaziyiusazizchsyiyrzchsaxsrchsyiyrchcziyrzchsaxhsyiyrzxhsyazuhchsyaziyiusazuhchsaxsrchsyaziyiusazizchsyiyrzchsaxsrchsyiyrchcziyrzchsaxsrchbrzxazuhbrzchsyiyrzchsaxsrchsyiyrchcziyrzchsaxsrchshjyrzxazujyrchcziyrzxaziyiusazujyrchbrzxazuhbrzchsyiyrzchsaxsrchsyiyrchcziyrzchsaxsrchshjyrzxazujyrchcziyrzxaziyiusazujusazizchsyiyrzchsaxsrchsyiyrcjusazuhchshjyrzxazujyrchcziyrzxaziyiusazujyrchcziyrbyazuhchsyaziyiusazuhchsaxsrchsyaziyizuhchsyizujyrzxazujyrchcziyrzxaziyiusazujyrchcziyrbyazuhchsyaziyiusazuhchsaxsrchsyaziyiusaxhsyiyrzxhsyazuhchsyaziyiusazuhchsaxsrchsyaziyiusazizchsyiyrzchsaxsrchsyiyrchcziyrzchsaxhsyiyrzxhsyazuhchsyaziyiusazuhchsaxsrchsyaziyiusazizchsyiyrzchsaxsrchsyiyrchcziyrbyazuhchsyaziyiusazujyrchbrzxazuhbrzchsyiyrzchsaxsrchsyiyrchcziyrzchsaxsrchshjyrzxazujyrchcziyrzxaziyiusazujyrchcziyizuhchsyizujyrzxazujyrchcziyrzxaziyiusazujyrchcziyrbyazuhchsyaziyiusazuhchsaxsrchsyaziyizuhchsyizujyrzxazujyrchcziyrzxaziyiusazujyrchcziyrbyazuhchsyaziyiusazuhchsaxsrchsysrchshjyrzxazujyrchcziyrzxaziyiusazizchsyiyrzchsaxsrchsyiyrcjusazuhchshjyrzxazujyrchcziyrzxaziyiusazujyrchcziyrbyazuhchsyaziyiusazuhchsaxsrchsyaziyizuhchsyizujyrzxazujyrchcziyrzxaziyiusazujyrchcziyrbyazuhchsyaziyiusazuhchsaxsrchsyaziyiusaxhsyiyrzxhsyazuhchsyaziyiusazuhchsaxsrchsyaziyiusazizchsyiyrzchsaxsrchsyiyrchcziyrzchsaxhsyiyrzxhsyazuhchsyaziyiusazuhchsaxsrchsyaziyiusazizchsyiyrzchsaxsrchsyiyrchcziyrzcziyrbyazuhchsyaziyiusazuhchsaxsrchshjyrzxazujyrchcziyrzxaziysrchsyiyrbyazuhchsyaziyiusazuhchsaxsrchsyaziyiusazizchsyiyrzchsaxsrchsyaziyizuhchsyizujyrzxazujyrchcziyrzxaziyiusazujyrchcziyrbyazuhchsyaziyiusazuhchsaxsrchsyaziyiusaxhsyiyrzxhsyazuhchsyaziyiusazuhchsaxsrchsyaziyiusazizchsyiyrzchsaxsrchsyiyrchcziyrzchsaxhsyiyrzxhsyazuhchsyaziyiusazuhchsaxsrchsyaziyiusazizchsyiyrzchsaxsrchsyiyrchcziyrzcziyrbyazuhchsyaziyiusazuhchsaxsrchshjyrzxazujyrchcziyrzxaziysrchsyiyrbyazuhchsyaziyiusazuhchsaxsrchsyaziyiusazizchsyiyrchcziyrzxaziyiuhchsyiysrchsyiyrchcziyrzxaziysrchsyiyrbyazuhchsyaziyiusazuhchsaxsrchsyaziyiusazizchsyiyrzchsaxsrchsyiyrchcziyrzchsaxhsyiyrzxhsyazuhchsyaziyiusazuhchsaxsrchsyaziyiusazizchsyiyrzchsaxsrchsyiyrchcziyrzchsaxsrchbrzxazuhbrzchsyiyrzchsaxsrchsyiyrchcziyrzchsaxsrchshjyrzxazujyrchcziyrzxaziyiusazujyrchbrzxazuhbrzchsyiyrzchsaxsrchsyiyrchcziyrzchsaxsrchshjyrzxazujyrchcziyrzxaziyiusazujusazizchsyiyrzchsaxsrchsyiyrchcziyrbyazuhchsyaziyiusazuhchsacziyrzxazizchsyiyrzchsaxsrchsyiyrchcziyrzchsaxsrchshjyrzxazujyrchcziyrzxaziyiusazujyrchbrzxazuhbrzchsyiyrzchsaxsrchsyiyrchcziyrzchsaxsrchshjyrzxazujyrchcziyrzxaziyiusazujyrchcziyizuhchsyizujyrzxazujyrchcziyrzxaziyiusazujyrchcziyrbyazuhchsyaziyiusazuhchsaxsrchsyaziyizuhchsyizujyrzxazujyrchcziyrzxaziyiusazujyrchcziyrbyazuhchsyaziyiusazuhchsaxsrchsysrchshjyrzxazujyrchcziyrzxaziyiusazizchsyiyrchcziyrzxaziyiuhchsyiysrchsyiyrchcziyrzxaziysrchsyiyrbyazuhchsyaziyiusazuhchsaxsrchsyaziyiusazizchsyiyrzchsaxsrchsyiyrchcziyrzchsaxhsyiyrzxhsyazuhchsyaziyiusazuhchsaxsrchsyaziyiusazizchsyiyrzchsaxsrchsyiyrl";

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n, k;
    cin >> n >> k;
    vector<ll> a(N + 1), f(k + 1, 1e9), g(k + 1);
    vector<int> bb;
    string alp = "qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM0123456789";
    map<char, int> mp;
    for(int i = 0; i < alp.size(); i++) {
        mp[alp[i]] = i;
    }
    for(auto i : back) {
        int val = mp[i];
        bb.push_back(val / 9);
        bb.push_back(val / 3 % 3);
        bb.push_back(val % 3);
    }
    for(int i = 2; i <= N; i++) {
        a[i] = a[i - 1] + i / 2;
        if(a[i] > k) break;
    }
    f[0] = 0;
    for(int i = 2; a[i] <= k; i++) {
        for(int j = a[i]; j <= k; j++) {
            if(f[j - a[i]] + i < f[j]) {
                f[j] = f[j - a[i]] + i;
                g[j] = i;
            }
        }
    }
    if(f[k] > n) {
        cout << "No\n";
        return 0;
    }
    string s;
    for(int i = k, fl = 0; i; ) {
        s += string(g[i], fl + '0');
        i -= a[g[i]];
        fl ^= 1;
    }
    int p = s.back() == '0' ? 1 : 0;
    for(int i = 0; s.size() < n; i++) {
        s.push_back(((bb[i] + p) % 3) + '0');
    }
    cout << "Yes\n";
    for(int i = 0; i < s.size(); i++) {
        cout << s[i] << ' ';
    }
    return 0;
}
/*
2842 0

*/