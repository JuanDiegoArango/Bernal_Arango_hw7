import numpy as np
import matplotlib.pyplot as plt
import matplotlib
import sys
from matplotlib.backends.backend_pdf import PdfPages

name = sys.argv[1]
name_clean=name.strip('.dat')

strings=name_clean.split('_')

time=float(strings[1].strip('.dat'))
data= np.loadtxt(name)

figVel = plt.figure()
plt.xlabel('x [m]')
plt.ylabel('V [m/s]')
plt.title('Velocidad t='+str(time)+' s')
plt.plot(data[:,0],data[:,1])
plt.grid()

figP = plt.figure()
plt.xlabel('x [m]')
plt.ylabel('P [Pa]')
plt.title('Presion t='+str(time)+' s')
plt.plot(data[:,0],data[:,2])
plt.grid()

figRho= plt.figure()
plt.xlabel('x [m]')
plt.ylabel('Rho [kg/m^3]')
plt.title('Densidad t='+str(time)+' s')
plt.plot(data[:,0],data[:,3])
plt.grid()

final = PdfPages(name_clean+'.pdf')
final.savefig(figVel)
final.savefig(figP)
final.savefig(figRho)
final.close()
