import pylab
import numpy as np
import matplotlib
from mpl_toolkits.mplot3d import Axes3D

print "La primera parte"
n_x = 200
c = 1.0
dx = 2.0/n_x
beta = 0.01
dt = beta*dx 

n_t = int(0.15/dt) 
x = linspace(0, 2.0, n_x)
u = 3.0*sin(pi*x)
t = linspace(0, 0.15, 200)
plot(x,u)
plot.show()
plot.close()

U = u

for n in range(n_t):  # loop over time
	u_past = u.copy() 
	for i in range(1,n_x-1): #loop over space
        	u[i] = u_past[i]  - beta*((u_past[i+1])**2-(u_past[i-1])**2)*0.5
  		plot(x,u)
	
	U = np.vstack([U, u])
    
plot.show()
plot.close()

fig = plt.figure()
Axes3D = fig.gca(projection='3d')
X, T = numpy.meshgrid(x,t)
Axes3D.plot_wireframe(X,T,U,rstride=20,cstride=10)
plt.show()
plt.close()

print "La segunda parte"




n_x = 200
c = 1.0
dx = 2.0/n_x
beta = 0.05
dt = beta*dx 
n_t = int(0.15/dt) 
x = linspace(0, 2.0, n_x)
u = 3.0*sin(pi*x)
t = linspace(0, 0.15, n_t)
plot(x,u)

U2 = u
for n in range(n_t):  # loop over time
	u_p = u.copy() 
	for i in range(1,n_x-1): #loop over space
		u[i] = u_p[i] - (beta/4)*((u_p[i+1])**2 - (u_p[i-1])**2) + ((beta**2)/8)*((u_p[i+1] + u_p[i])*((u_p[i+1])**2 - (u_p[i])**2)- (u_p[i] + u_p[i-1])*((u_p[i]**2) - (u_p[i-1])**2))
		plot(x,u)
	U2 = np.vstack([U2, u])

plot.show()
plot.close()

fig = plt.figure()
Axes3D = fig.gca(projection='3d')
X, T = numpy.meshgrid(x,t)
Axes3D.plot_wireframe(X,T,U,rstride=20,cstride=10)
plt.show()
plt.close()
