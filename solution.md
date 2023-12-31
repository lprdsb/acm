# 2023.12.25

### [G2. Light Bulbs (Hard Version)](https://codeforces.com/contest/1914/problem/G2)

若干个区间的极小并，当且仅当这个区间包含了所有区间，当且仅当每个区间的左右点出现了一次， 相当于某个标号恰好出现两次，可以用随机数来异或。

#### 因数个数小trick

$$
d(n)\%2=[n=k^2]
$$

当且仅当该数是完全平方数时，因数个数是奇数个

#### 极小mex

![image-20231225192410689](F:\Documents\acm\picture\image-20231225192410689.png)

# 2023.12.31

数论trick
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


