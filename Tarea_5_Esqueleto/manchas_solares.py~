import modulo_manchas_solares as mfs
import numpy as np

def main():
	"""
	Lee datos del registro del promedio de manchas solares por dia cada mes desde 1600s hasta 1995. 
	-Interpola los datos para estimar estimar el numero de manchas en los meses en los que no se tienen datos por medio de interpolacion contante, lineal, y cubica. 
	-Se realiza la transformada de Fourier a las 3, se obtienen los espectros de potencias, y paso seguido se hacen iguales a cero las amplitudes de las frecuencias que esten fuera del rango de 2 y 20 anos. 
	-Reconstruir la senal y estimar el periodo del ciclo solar.   
	"""
	#Carga los datos de las manchas solares
	data = np.loadtxt("sparse_sample_monthrg.dat")

	#Interpolacion constante, lineal, y cubica de los datos 
	interpConst = mfs.interpolacionConstante(data)
	interpLin = mfs.interpolacionLineal(data)   
	interpCub = mfs.interpolacionCubica(data)
	    
	#Encuentra la transformada de fourier para cada interpolacion
	freqConst, xkConst = mfs.fourierTransform(interpConst)
	freqLin, xkLin = mfs.fourierTransform(interpLin)
	freqCub, xkCub = mfs.fourierTransform(interpCub)

	#Encuentra el espectro de potencias de las 3 interpolaciones
	PxkConst = mfs.espectro_potencias(xkConst)	
	PxkLin = mfs.espectro_potencias(xkLin)
	PxkCub = mfs.espectro_potencias(xkCub)

	#Elimina los xk que correspondan a periodos que no esten entre 2 y 20 anos
	xkConst_ajustada = mfs.ajuste_periodos(xkConst,freqConst)  
	xkLin_ajustada = mfs.ajuste_periodos(xkLin,freqLin)	
	xkCub_ajustada = mfs.ajuste_periodos(xkCub,freqCub)
	
	#Reconstruye la senales y grafica la senal suavizada y los datos reales para cada interpolacion
	mfs.manchas_reconstruidas(xkConst_ajustada,data)
	mfs.manchas_reconstruidas(xkLin_ajustada,data)
	mfs.manchas_reconstruidas(xkCub_ajustada,data)

	#Estima el periodo del ciclo solar
	Periodo_IntpConst = mfs.ciclos_solares(xkConst_ajustada, freqConst)
	Periodo_IntpLin = mfs.ciclos_solares(xkLin_ajustada, freqLin)
	Periodo_IntpCub = mfs.ciclos_solares(xkCub_ajustada, freqCub)

if __name__ == "__main__":
    main()
	
