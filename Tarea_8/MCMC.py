from pylab import *
import random
import matplotlib.pyplot as plt
import moduloT8 as mt

#Definir el numero iteraciones para el Runge Kutta y para el Metropolis-Hastings, y el sigma para los saltos aleatorios
numPunRK = 2800
n_iterations = 100000
sigma = 0.1

data = loadtxt("datos.dat")
y_obs = data[:,1]
x_obs = data[:,0]

alfa_walk = empty((0)) #this is an empty list to keep all the steps
beta_walk = empty((0))
km1_walk = empty((0))
km2_walk = empty((0))
S_walk = empty((0))

alfa_walk = append(alfa_walk, random.random())
beta_walk = append(beta_walk, random.random())
km1_walk = append(km1_walk, random.random())
km2_walk = append(km2_walk, random.random())
S_walk = append(S_walk, random.random())

Ls = empty((0))
np.savetxt("Proabiblidades o L's",Ls)
#Metdo Metropolis-Hastings

for i in range(n_iterations):
	
	alfa_prime = np.random.normal(alfa_walk[i], sigma) 
	beta_prime = np.random.normal(beta_walk[i], sigma)
	km1_prime = np.random.normal(km1_walk[i], sigma) 
	km2_prime = np.random.normal(km2_walk[i], sigma)
	S_prime = np.random.normal(S_walk[i], sigma) 


	x_init,y_init = mt.RungeKutta(alfa_walk[i],beta_walk[i],km1_walk[i],km2_walk[i],S_walk[i],numPunRK)
	x_prime,y_prime = mt.RungeKutta(alfa_prime,beta_prime,km1_prime,km2_prime,S_prime,numPunRK)
	
	#Se hace esto para preveer el caso en que sea en que sea igual a cero
	L_ant = mt.likelihood(x_obs,y_obs,x_init, y_init,numPunRK)
	Ls  = append(Ls,L_ant)
	
	if(L_ant == 0): #Porque a veces cuando es muy baja la iguala a cero

			alfa_walk  = append(alfa_walk,alfa_prime)
			beta_walk  = append(beta_walk,beta_prime)
			km1_walk = append(km1_walk,km1_prime)
			km2_walk = append(km2_walk,km2_prime)
			S_walk = append(S_walk,S_prime)

	else: #Si no es igual a cero si se puede dividir la L inicial

		alpha = mt.likelihood(x_obs,y_obs,x_prime, y_prime,numPunRK)/L_ant
		
		if(alpha>=1.0):

			alfa_walk  = append(alfa_walk,alfa_prime)
			beta_walk  = append(beta_walk,beta_prime)
			km1_walk = append(km1_walk,km1_prime)
			km2_walk = append(km2_walk,km2_prime)
			S_walk = append(S_walk,S_prime)
		
		else:
			beta = random.random()
	
			if(beta<=alpha):
			
				alfa_walk  = append(alfa_walk,alfa_prime)
				beta_walk  = append(beta_walk,beta_prime)
				km1_walk = append(km1_walk,km1_prime)
				km2_walk = append(km2_walk,km2_prime)
				S_walk = append(S_walk,S_prime)
		        else:

				alfa_walk  = append(alfa_walk,alfa_walk[i])
				beta_walk  = append(beta_walk,beta_walk[i])
				km1_walk = append(km1_walk,km1_walk[i])
				km2_walk = append(km2_walk,km2_walk[i])
				S_walk = append(S_walk,S_walk[i])



print alfa_walk[n_iterations]
print beta_walk[n_iterations]
print km1_walk[n_iterations]
print km2_walk[n_iterations]
print S_walk[n_iterations]

np.savetxt("Proabiblidades o L's",Ls)

mt.graficar(x_obs,y_obs,alfa_walk,beta_walk,km1_walk,km2_walk,S_walk)

