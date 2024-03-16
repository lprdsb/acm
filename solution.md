# 2023.12.25

## [G2. Light Bulbs (Hard Version)](https://codeforces.com/contest/1914/problem/G2)

若干个区间的极小并，当且仅当这个区间包含了所有区间，当且仅当每个区间的左右点出现了一次， 相当于某个标号恰好出现两次，可以用随机数来异或。

## 因数个数小trick

$$
d(n)\%2=[n=k^2]
$$

当且仅当该数是完全平方数时，因数个数是奇数个

## 极小mex

![极小mex](F:\Documents\acm\picture\极小mex.png)

称$[l,r]$是极小区间，当且仅当不存在$[L,R]\subsetneq[l,r],\mbox{mex}(l,r)=\mbox{mex}(L,R)$。则有结论：极小区间只有$O(n)$个。

证明：考虑极小区间$[l,r]$，则$a_l\neq a_r$，设$a_l>a_r$，由于删掉端点$\mbox{mex}$会变化，所以$\mbox{mex}(l,r)>a_l$，对于$r_1>r$，若$a_{r_1}\leq a_r$，则$[l,r_1]$，$r_1$可以删去，其不为极小区间。若$a_{r_1}\ge a_r$，由于$\mbox{mex}(l,r_1)>a_{r_1}$，说明$a_{r_1}$已经出现过，仍然可以删去，其不为极小区间，故对于一个$l$来说，对应的$r$只有一个。

# 2023.12.31

## 数论trick

$$
F_n(x)=\prod_{i=0}^n(1-p^ix)
$$

可以考虑

$$
F_n(px)=\prod_{i=0}^{n}(1-p^{i+1}x)=\prod_{i=1}^{n+1}(1-p^ix)=F_n(x)\frac{1-p^{n+1}x}{1-x}
$$

即

$$
(1-x)F_n(px)=(1-p^{n+1}x)F_n(x)
$$

考虑$[x^k]$

$$
p^k[x^k]F_n-p^{k-1}[x^{k-1}]F_n=[x^k]F_n-p^{n+1}[x^{k-1}]F_n\\
(p^k-1)[x^k]F_n=(p^{k-1}-p^{n+1})[x^{k-1}]F_n\\
[x^k]F_n=\frac{p^{k-1}-p^{n+1}}{p^k-1}[x^{k-1}]F_n
$$

## [q-binomial](https://www.cnblogs.com/zkyJuruo/p/15515243.html)

$$
[n]_q = \sum\limits_{i=0}^{n-1} q^i = \lim_{x \rightarrow q} \frac{1-x^n}{1-x}, [ n ] !_q = \prod_{i=1}^n [i]_q, {n \brack m}_q = \frac {[n]!_q} {[m]!_q [n - m]!_q}\\
{n \brack m}_q = {n-1 \brack m-1}_q + q^m {n-1 \brack m}_q\\
\prod_{i=0}^{n-1} (1+q^iy) = \sum\limits_{i=0}^n q^{\binom{i}{2}} {n \brack i}_q y^i\\
{n + m \brack k}_q = \sum\limits_{i=0}^k q^{(n-i)(k-i)} {n \brack i}_q {m \brack k-i}_q\\
{n + m + 1 \brack n + 1}_q = \sum\limits_{i=0}^m q^i {n + i \brack n}_q\\
\frac{1}{\prod_{i=0}^n (1-q^ix)} = \sum\limits_{i \ge 0} x^i {i+n \brack n}_q
$$

### Erdos-Ginzburg-Ziv Theorem

![image-20231231191058535](C:\Users\lpr\AppData\Roaming\Typora\typora-user-images\image-20231231191058535.png)

https://zhuanlan.zhihu.com/p/501183534

$n$为任意正整数，则在任意$2n-1$个整数中，必定存在$n$个整数，它们的和是$n$的倍数。

# 2024.1.7

## 矩阵树

![image-20240107192512990](C:\Users\lpr\AppData\Roaming\Typora\typora-user-images\image-20240107192512990.png)

# 无向图

给定一个无向图，有重边无自环，$A$为其邻接矩阵，$D$为其度数矩阵。

其基尔霍夫矩阵为$D-A$。

$\det(K')$即为该无向图生成树数量，其中$K'$为任意一个$n-1$阶余子式。

# 有向图

给定一个无向图，有重边无自环，$A$为其邻接矩阵，$D_{in}$为其入度矩阵，$D_{out}$为其出度矩阵。

若为外向树$K=D_{in}-A$，若为内向树$K=D_{out}-A$。

以$r$为根的树的个数为$\det(K')$，$K'$为$(r,r)$的余子式。

## BEST定理

![image-20240107192535167](C:\Users\lpr\AppData\Roaming\Typora\typora-user-images\image-20240107192535167.png)

对于一个有向欧拉图，$i$点出度为$out_i$，其本质不同的欧拉回路个数为：

$$
T\prod_i(out_i-1)!
$$

$T$为图的内向生成树个数。

证明：

考虑一条欧拉回路，每个点最后一次出去的边，一定构成一颗内向树，考虑给每个点剩下的边使用的的先后排序。

对于欧拉路径，可以在两个起点之间连边，然后算欧拉回路。

## 连续段dp

[P5999 [CEOI2016] kangaroo](https://www.luogu.com.cn/problem/P5999)

# 2024_1_22

### dp trick

![image-20240122183502074](C:\Users\lpr\AppData\Roaming\Typora\typora-user-images\image-20240122183502074.png)

将一棵树分为$k$个联通块，计算$\prod_{i=1}^kS_i$的总和，可以考虑这样的$dp$，在$k$个连通块中，每个连通块选择一个点的方案数。

$dp[i][j][0/1]$表示$i$点为根的子树，分成$j$个连通块，$i$这个点的连通块中有没有放标记点。

# 2024_2_1

## 二维链表trick

可以开二位链表连右边和下边

## 括号序列

1.设$f(n,m,k)$表示有$n$个左括号，$m$个右括号，子序列中合法括号序列最长长度为$2k$的括号序列，转移为

$$
f(n,m,k)=
\left\{
\matrix{
{n+m}\choose n && k\ge min(n,m)\\
f(n-1,m,k-1)+f(n,m-1,k) && k<min(n,m)
}
\right.
$$

通过归纳可以得到

$$
f(n,m,k)=
\left\{
\matrix{
{n+m}\choose n && k\ge min(n,m)\\
{n+m}\choose k && k<min(n,m)
}
\right.
$$

2.对于一个括号序列来说，要想构造一个最长的合法子括号序列，没有用上的右括号的数量就是前缀和的min。可以考虑像算卡特兰数那样将跨过某条斜线之后的路径全部取反。

# 2024_2_18

$$
\max_{a\in A,b\in B}\{a\&b\}=\max_{x\in a\in A, x\in b \in B}\{x\}
$$

# 2024_3_16

## or_trick

$$
\max_{0\leq i \le a,0\le j\le b}i|j=(a | b)|(2^{\log(a\&b) + 1}-1)
$$
