

import numpy as np
import matplotlib.pyplot  as plt
from mpl_toolkits.mplot3d import Axes3D
import sys

a=sys.argv[1]
b=a.strip('.dat')
data = np.loadtxt(""+a+"")
fig = plt.figure(figsize=(30.0, 20.0))
ax = Axes3D(fig)
x=np.linspace(0,100,101)
matriz=np.zeros((121,101))
for i in range(0,101):
    p=data[:,i]
    for j in range (0,121):
        matriz[j][i]=p[j]

for i in range(0,121):
    y=matriz[i]
    t=i*np.ones(101)
    ax.plot(t, x, y)
ax.view_init(elev=20, azim=8)

plt.savefig(""+b+".pdf")




