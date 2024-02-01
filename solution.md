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

### Erdos-Ginzburg-Ziv Theorem

![image-20231231191058535](C:\Users\lpr\AppData\Roaming\Typora\typora-user-images\image-20231231191058535.png)

https://zhuanlan.zhihu.com/p/501183534

# 2024.1.7

## 矩阵树

![image-20240107192512990](C:\Users\lpr\AppData\Roaming\Typora\typora-user-images\image-20240107192512990.png)

## BEST定理

![image-20240107192535167](C:\Users\lpr\AppData\Roaming\Typora\typora-user-images\image-20240107192535167.png)

## 连续段dp

[P5999 [CEOI2016] kangaroo](https://www.luogu.com.cn/problem/P5999)

# 2024_1_22

### dp trick

![image-20240122183502074](C:\Users\lpr\AppData\Roaming\Typora\typora-user-images\image-20240122183502074.png)

# 2024_2_1

## 二维链表trick

可以开二位链表连右边和下边

## 括号序列

设$f(n,m,k)$表示有$n$个左括号，$m$个右括号，子序列中合法括号序列最长长度为$2k$的括号序列，转移为
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
