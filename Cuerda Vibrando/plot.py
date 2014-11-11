

import numpy as np
import matplotlib.pyplot  as plt
from matplotlib import cm, colors
from mpl_toolkits.mplot3d import Axes3D
import sys

a=sys.argv[1]
b=a.strip('.dat')
data = np.loadtxt(""+a+"")
fig = plt.figure(figsize=(100,40))
ax = Axes3D(fig)
x=np.linspace(0,100,101)
t=np.linspace(0,120,121)
matriz=np.zeros((101,121))
for i in range(0,101):
    matriz[i]=data[:,i]
X,T=np.meshgrid(x,t)
p = ax.plot_surface(X, T, matriz.T, rstride=1, cstride=1, cmap=cm.jet)
ax.view_init(elev=1, azim=15)
plt.xlabel('x')
plt.ylabel('time')

plt.savefig(""+b+".pdf")




