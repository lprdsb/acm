令$a_{i,j}^k$表示在第$i$行第$j$列填入了数字$k$，则

1.每个格子填一个数字：

$$
\land_{i=1}^{3}\land_{j=1}^{3}\land_{k=1}^{3}(a_{i,j}^k\rightarrow (\land_{m=1,m\not=k}^{3}\lnot P_{i,j}^m))
$$
