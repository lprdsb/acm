import matplotlib 
import matplotlib.pyplot as plt
from matplotlib.patches import Wedge
import numpy as np
import matplotlib.pyplot as plt
from matplotlib.path import Path   # Path 对象
import matplotlib.patches as patches

fig, (ax1,ax2) = plt.subplots(1, 2, figsize = (10,4))

p1 = np.array([0., 0.])
p2 = np.array([0.2, 1.])
p3 = np.array([1., 0.8])
p4 = np.array([0.8, 0.])
vert1 = [p1,p2,p3]
code1 = [Path.MOVETO, Path.CURVE3, Path.CURVE3]
path1 = Path(vert1, code1)
patch1 = patches.PathPatch(path1, ec='r', fc='None', lw=2)
ax1.add_patch(patch1)
xs1, ys1 = zip(*vert1)
ax1.plot(xs1, ys1, 'x--', lw=2, color='black', ms=10)
ax1.text(-0.05, -0.05, 'P0')
ax1.text(0.15, 1.05, 'P1')
ax1.text(1.05, 0.85, 'P2')
ax1.text(0.85, -0.05, 'P3')
ax1.set_xlim(-0.1, 1.1)
ax1.set_ylim(-0.1, 1.1)
ax1.set_title('123')

vert2 = [p1,p2,p3,p4]
code2 = [Path.MOVETO, Path.CURVE4, Path.CURVE4, Path.CURVE4]
path2 = Path(vert2, code2)
patch2 = patches.PathPatch(path2, ec='b', fc='None', lw=2)
ax2.add_patch(patch2)
xs2, ys2 = zip(*vert2)
ax2.plot(xs2, ys2, 'x--', lw=2, color='black', ms=10)
ax2.text(-0.05, -0.05, 'P0')
ax2.text(0.15, 1.05, 'P1')
ax2.text(1.05, 0.85, 'P2')
ax2.text(0.85, -0.05, 'P3')
ax2.set_xlim(-0.1, 1.1)
ax2.set_ylim(-0.1, 1.1)
ax2.set_title('456')

plt.show()