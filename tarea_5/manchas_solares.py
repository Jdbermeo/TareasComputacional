import modulo_manchas_solares as mf
import numpy as np

def main():
	"""
	Lee datos del registro del promedio de manchas solares por dia cada mes desde 1600s hasta 1995. 
	-Interpola los datos para estimar estimar el numero de manchas en los meses en los que no se tienen datos por medio de interpolacion contante, lineal, y cubica. 
	-Se realiza la transformada de Fourier a las 3, se obtienen los espectros de potencias, y paso seguido se hacen iguales a cero las amplitudes de las frecuencias que esten fuera del rango de 2 y 20 años. 
	-Reconstruir la senal y estimar el periodo del ciclo solar.   
	"""
    #Carga los datos de las manchas solares
    data = np.loadtxt("sparse_sample_monthrg.dat")

    #Interpolacion constante, lineal, y cubica de los datos 
    

    #Encuentra el espectro de potencias de las 3 interpolaciones
    fft_ampl,fft_freq  = mf.espectro_potencias(fft_ampl,fft_freq)	

    #Elimina los xk que correspondan a periodos que no esten entre 2 y 20 años

    #Reconstruye la senales
   
    #Estima el periodo del ciclo solar
	
if __name__ == "__main__":
    main()
	
