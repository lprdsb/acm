import numpy as np
import matplotlib.pyplot as plt
import matplotlib.cm as cm

# 生成数据
N = 1000
x = np.random.rand(N)
y = np.random.rand(N)
colors = np.arange(N)

# 绘制圆形散点图
fig, ax = plt.subplots()
size = 100*(np.random.rand(N)+1)
ax.scatter(x, y, s=size, c=colors, cmap='jet', alpha=1)
ax.axis('off')
plt.show()
