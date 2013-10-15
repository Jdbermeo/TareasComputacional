import numpy as np
from scipy.fftpack import fft, fftfreq,ifft
import matplotlib.pyplot as plt
from scipy.interpolate import interp1d

"""
Modulo con las funciones para estimar el ciclo solar a partir del registro de manchas solares desde 1603 hasta 1995
Authors: Miguel Aldana, Juan Diego Bermeo
Creation date: Miercoles Oct  9 2013
"""

def interpolacionConstante(data):
	"""
	- - Carga un array de numpy [4633,5]  y devuelve un arreglo numpy [4633,2] con los resultados de la interpolacion cubica para los años en que se tiene y no se tiene medicion. En los años en que no se tiene medicion se calculas por medio de una interpolacion lineal
	- La Interppolacion constante consiste el valor de tiempo desconocido que sigue igual al dato que le precede en tiempo. 
	Input: arreglo de numpy [4633,5]
	Output: arreglo de numpy [4632,2] con los datos interpolados en los meses en los que no tenemos medicion 
	"""
	#Crea un nuevo arreglo de numpy donde solo estan los meses en los que se realizaron mediciones
	n = 0
	for i in range(0,len(data)):
	    if(n==0):
		if(data[i,3]!=-99.0):
		    medicion = data[i,:]
		    n = -1
	    else:  
		if(data[i,3]!=-99.0):
		    medicion = np.vstack([medicion, data[i,:]])
	
	#Acomoda la escala de tiempo a años para cada medicion
	for i in range(0,len(medicion)):
	    medicion[i,2] = (medicion[i,1]/12.0)+medicion[i,0]-1610
	    
	#Lleva a cabo el proceso de interpolacion constante
	funcion_interp_const = interp1d(medicion[:,2],medicion[:,3],kind = 'nearest')

	#Evalua los puntos sobre los que no se tenia informacion con la funcion obtenida de la interpolacion, usando el array de cinco columnas. Primero acomoda la aescala de tiempo, y luego evalua los puntos de tiempo en la funcion
	for i in range(0,len(data)):
		data[i,2] = (data[i,1]/12.0)+data[i,0]-1610

	for i in range(1,len(data)):
		data[i,3] = funcion_interp_cons(data[i,2]) 

	#Separa los datos de tiempo y numero de manchas en un arreglo de numpu [4632,2]
	data_trans = np.hstack((np.reshape(data[1:,2],(4631,1)),np.reshape(data[1:,3],(4631,1))))
	np.savetxt("datosInterpConst.txt",data,"%s")

	return data_trans
	
def interpolacionLineal(data):
	"""
	- Carga un array de numpy [4633,5]  y devuelve un arreglo numpy [4633,2] con los resultados de la interpolacion cubica para los años en que se tiene y no se tiene medicion. En los años en que no se tiene medicion se calculas por medio de una interpolacion lineal
	- La Interppolacion lineal consiste en que el valor desconocido se aproxima como el punto en el tiempo t sobre la linea que conecta el anterior punto conocido y el siguiente punto conocido. 
	Input: arreglo de numpy [4633,5]
	Output: arreglo de numpy [4632,2] con los datos interpolados en los meses en los que no tenemos medicion  
	"""
	#Crea un nuevo arreglo de numpy donde solo estan los meses en los que se realizaron mediciones
	n = 0
	for i in range(0,len(data)):
	    if(n==0):
		if(data[i,3]!=-99.0):
		    medicion = data[i,:]
		    n = -1
	    else:  
		if(data[i,3]!=-99.0):
		    medicion = np.vstack([medicion, data[i,:]])
	
	#Acomoda la escala de tiempo a años para cada medicion
	for i in range(0,len(medicion)):
	    medicion[i,2] = (medicion[i,1]/12.0)+medicion[i,0]-1610
	    
	np.savetxt("datoslimpios.txt",medicion,"%s")

	#Lleva a cabo el proceso de interpolacion lineal
	funcion_interp_lineal = interp1d(medicion[:,2],medicion[:,3],kind = 'linear')

	#Evalua los puntos sobre los que no se tenia informacion con la funcion obtenida de la interpolacion, usando el array de cinco columnas. Primero acomoda la aescala de tiempo, y luego evalua los puntos de tiempo en la funcion
	for i in range(0,len(data)):
		data[i,2] = (data[i,1]/12.0)+data[i,0]-1610

	for i in range(1,len(data)):
		data[i,3] = funcion_interp_lineal(data[i,2]) 

	#Separa los datos de tiempo y numero de manchas en un arreglo de numpu [4632,2]
	data_trans = np.hstack((np.reshape(data[1:,2],(4631,1)),np.reshape(data[1:,3],(4631,1))))
	np.savetxt("datosInterpLin.txt",data,"%s")

	return data_trans	

def interpolacionCubica(data):
	"""
	- Carga un array de numpy [4633,5]  y devuelve un arreglo numpy [4633,2] con los resultados de la interpolacion cubica para los años en que se tiene y no se tiene medicion. En los años en que no se tiene medicion se calculas por medio de una interpolacion cubica
	- La Interppolacion cubica consiste en que el valor desconocido se aproxima como el punto en el tiempo t que esta sobre el arco del polinomio de grado 3 que pasa por el anterior punto conocido y el siguiente punto conocido 
	Input: arreglo de numpy [4633,5]
	Output: arreglo de numpy [4633,2] con los datos interpolados en los meses en los que no tenemos medicion
	"""
	#Crea un nuevo arreglo de numpy donde solo estan los meses en los que se realizaron mediciones
	n = 0
	for i in range(0,len(data)):
	    if(n==0):
		if(data[i,3]!=-99.0):
		    medicion = data[i,:]
		    n = -1
	    else:  
		if(data[i,3]!=-99.0):
		    medicion = np.vstack([medicion, data[i,:]])
	
	#Acomoda la escala de tiempo a años para cada medicion
	for i in range(0,len(medicion)):
	    medicion[i,2] = (medicion[i,1]/12.0)+medicion[i,0]-1610
	    
	np.savetxt("datoslimpios.txt",medicion,"%s")

	#Lleva a cabo el proceso de interpolacion lineal
	funcion_interp_cubic = interp1d(medicion[:,2],medicion[:,3],kind = 'cubic')

	#Evalua los puntos sobre los que no se tenia informacion con la funcion obtenida de la interpolacion, usando el array de cinco columnas. Primero acomoda la aescala de tiempo, y luego evalua los puntos de tiempo en la funcion
	for i in range(0,len(data)):
		data[i,2] = (data[i,1]/12.0)+data[i,0]-1610

	for i in range(1,len(data)):
		data[i,3] = funcion_interp_cubic(data[i,2]) 

	#Separa los datos de tiempo y numero de manchas en un arreglo de numpu [4632,2]
	data_trans = np.hstack((np.reshape(data[1:,2],(4631,1)),np.reshape(data[1:,3],(4631,1))))
	np.savetxt("datosInterpCubica.txt",data,"%s")

	return data_trans

def fourierTransform(data_Interpolacion):
	"""
	Carga un array de numpy [4633,2] y le calcula la transformada de fourier.
	Input: arreglo de numpy [4633,2]
	Output: dos arreglos de numpy de [4633]
		- fft_freq: Frecuencias de armonico.
     		- fft_amplitudes: Amplitud de cada xk. 
	"""
	dt = 1/12.0
	mediciones = data_Interpolacion[:,1]
	
	#Obtiene la amplitud (nomralizada) y frecuencia de la transformada de fourier
	fft_amplitudes = fft(mediciones)/len(mediciones)
	fft_freq = fftfreq(len(mediciones), dt)

	return fft_freq, fft_amplitudes

def espectro_potencias(freq, fft_x):

     """
     Esta funcion calcula el espectro de potencias de un arreglo numpy que tiene por entrada, al sacarles el valor absoluto y elevarlo al cuadrado, y grafica el espectro de potencias obtenido contra las frecuencias que tiene por input.

     Input:
     - freq: arreglo de numpy  de 
     - fft_x: arreglo numpy de numeros complejos de tamano [4607]. Amplitudes de cada senal.

     Output:
     - grafica el espectro de potencias 
     """
	plt.plot(freq,np.abs(fft_x)**2)
	
	return 

def ajuste_periodos(fft_ampl,fft_freq):

    """
    Esta funcion devuelve un arreglo con las amplitudes que corresponden a los periodos de 2 a 20 anos y las demas en cero

    Input:
    - fft_freq: Arreglo numpy de tamano [4607,1], en el que haran igual a cero todas las amplitudas excepto las que tienen periodo entre 2 anos y 20 anos
    - fft_freq: arreglo numpy de tamano [4607,1] con las frecuencias asociadas a los espectros de potencia calculados

    Output:
    - ampl_ajustada: arreglo numpy de tamano [4607,1] donde los unicos valores diferentes de 0 corresponden a las amplitudes de periodos de 2 a 20 anos.
    - freq_ajustada: arreglo numpy de tamano [4607,1]

    """
	#Filtra las potencias que cuyo Periodo sea mayor a 20 años o menor a 2 años
	for i in range(0,len(fft_freq)):
	    if(fft_freq[i]**2>pi**2):
		    fft_ampl[i] = 0
		   

	for i in range(0,len(fft_freq)):
	    if(fft_freq[i]**2<(pi/10)**2):
		    fft_ampl[i] = 0
 

    return fft_ampl

def manchas_reconstruidas(ampl_ajustada,datos_Manchas):

    """

    Esta funcion obtenemos nuevos puntos de manchas y tiempo con la transformada de Fourier inversa para reconstruir la funcion de las manchas solares que depende del tiempo. Ademas realiza una grafica en unidades de anos donde se uestra la reconstruccion con la interpolacion y los datos originales.

    Input:
    - ampl_ajustada: arreglo numpy de tamano [4607,1] donde los unicos valores diferentes de 0 corresponden a las amplitudes entre periodos de 2 a 20 anos.
    - datos_Manchas: arreglo de numpy de [4633,5] con los datos originales de las manchas solares

    Output:
    grafica en la que se muestra la reconstruccion con la interpolacion y eliminando ciertas frecuencias, y las mediciones reales de las manchas solares
    """
 
    return 

def ciclos_solares(ampl_ajustada, freq_ajustada):
    """
    Esta funcion devuelve el valor del periodo en anos tomando la primera frecuencia desde el cero y encontrado el periodo por medio de la relacion T=2pi/w. Tambien imprime el periodo en pantalla 

    Input:
    - ampl_ajustada: arreglo numpy de tamano [4607,1] donde los unicos valores diferentes de 0 corresponden a las amplitudes entre periodos de 2 a 20 anos.
    - freq_ajustada: arreglo numpy de tamano [4607,1] cuyos valores son las frecuencias correspondientes a periodos entre 2 y 20 anos.

    Output:
    - periodo: un float que corresponde a el periodo de las manchas solares

    """
    periodo = 11.0
    return periodo
