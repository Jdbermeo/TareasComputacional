from pylab import *
import random
import matplotlib.pyplot as plt

"""
	Recibe los parametros aleatorios del Metropolis-Hastings, y calcula la forma de la solucion de la ecuacuon diferencial por medio del metodo Runge-Kutta.
	Input:
		-alfa: Parametro aleatorio de la ecuacion dieferencial que se busca estimar
		-beta: Parametro aleatorio de la ecuacion dieferencial que se busca estimar
		-km1: Parametro aleatorio de la ecuacion dieferencial que se busca estimar
		-km2: Parametro aleatorio de la ecuacion dieferencial que se busca estimar
		-S: Parametro aleatorio de la ecuacion dieferencial que se busca estimar
		-numPuntos: numero de iteraciones en el metodo Runge Kutta. Debe ser multiplo de 28 para los intervalos en tiempo de 0.5 esten incluidos y asi poderlos comparar con los datos observados

	Output:
		- x: Array de tamano [numpPuntos+1] y da el tiempo en el que avanza la funcion
		- y:Array de tamano [numpPuntos+1] y da los valores que toma P en el tiempo. 
"""
def RungeKutta(alfa,beta,km1,km2,S,numPuntos):
	
	#Con esto se define el numero 	
	h=28.0/numPuntos
	n_points=int((28.0+h)/h)
	x=empty(n_points)
	y=empty(n_points)
	def func_prime(x,y):
		return alfa*(S-y)/(km1+S-y)-(beta*y)/(km2+y)

	y[0]=12
	x[0]=2

	for i in range(1,n_points):

		k1 = func_prime(x[i-1],y[i-1])
	
		#primer paso
		x1 = x[i-1] + (h/2.0)
		y1 = y[i-1] + (h/2.0) * k1
		k2 = func_prime(x1, y1)
	
		#segundo paso
		x2 = x[i-1] + (h/2.0)
		y2 = y[i-1] + (h/2.0) * k2
		k3 = func_prime(x2, y2)

		#tercer paso
		x3 = x[i-1] + h
		y3 = y[i-1] + h * k3
		k4 = func_prime(x3, y3)
	
		#cuarto paso
		average_k = (1.0/6.0)*(k1 + 2.0*k2 + 2.0*k3 + k4)
	
		x[i] = x[i-1] + h
		y[i] = y[i-1] + h * average_k	

	return x,y

"""
	Calcula el chi cuadrado de la observacion con el resultado del metodo Runge-Kutta en los tiempos en los que se tiene observacion
	
	Input:
		-numPuntos: numero de puntos con los que se realizo el Runge-Kutta, para asi cuando vaya a comparar en que momento esta sobre el tiempo correcto tenga un margen pequeno de comparacion
"""

def likelihood(x_obs,y_obs,x_model,y_model,numPuntos):
	chi_squared = 0.0
	a = 0
	for i in range(len(x_model)):
		for j in range(len(x_obs)):
			if(abs(x_obs[j]-x_model[i]) < 28.0/(numPuntos*10)):				
				chi_squared = chi_squared + ((y_obs[j]-y_model[i])**2)
				a = a+1
				#print a #Para verificar que si esta haciendo el numero de iteraciones correcto
	return exp(-chi_squared*0.5)

"""

"""

def graficar(x_obs,y_obs,alfa,beta,km1,km2,S):

#Scatter Plots
	scatter(alfa,beta)
	savefig('alfa y beta .png')
	plt.show()
	plt.close()

	scatter(alfa,km1)
	savefig('alfa y km1.png')
	plt.show()
	plt.close()	

	scatter(alfa,km2)
	savefig('alfa y km2.png')
	plt.show()
	plt.close()

	scatter(alfa,S)
	savefig('alfa y S.png')
	plt.show()
	plt.close()

	scatter(beta,km1)
	savefig('beta y km1.png')
	plt.show()
	plt.close()

	scatter(beta,km2)
	savefig('beta y km2.png')
	plt.show()
	plt.close()		

	scatter(beta,S)
	savefig('beta y S.png')
	plt.show()
	plt.close()	

	scatter(km1,km2)
	savefig('alfa y km1.png')
	plt.show()
	plt.close()	

	scatter(km1,S)
	savefig('km1 y S.png')
	plt.show()
	plt.close()

	scatter(km2,S)
	savefig('km2 y S.png')
	plt.show()
	plt.close()		

	#Histogramas

	count, bins, ignored =plt.hist(alfa, 20, normed=True)
	savefig('histograma alfa.png')
	plt.show()
	plt.close()

	count, bins, ignored =plt.hist(beta, 20, normed=True)
	savefig('histograma beta.png')
	plt.show()
	plt.close()

	count, bins, ignored =plt.hist(km1, 20, normed=True)
	savefig('histograma km1.png')
	plt.show()
	plt.close()

	count, bins, ignored =plt.hist(km2, 20, normed=True)
	savefig('histograma km2.png')
	plt.show()
	plt.close()

	count, bins, ignored =plt.hist(S, 20, normed=True)
	savefig('histograma S.png')
	plt.show()
	plt.close()

	#Graficar lo que podria ser el mejor estimado

	average_a = average(alfa)
	average_b = average(beta)
	average_km1 = average(km1)
	average_km2 = average(km2)
	average_S = average(S)

	t, best_P = RungeKutta(average_a, average_b, average_km1,average_km2,average_S,2800)
	scatter(x_obs,y_obs)
	plot(t, best_P)
	savefig('Calculo con los valores promedio.png')
	plt.show()
	plt.close()

	#Grafica de contorno de los parametros contra los otros respecto a chi cuadrado	


