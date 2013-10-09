import numpy as np
from scipy.fftpack import fft, fftfreq,ifft
import matplotlib.pyplot as plt

"""
Modulo con las funciones para procesar los datos de los 24 electrodos
Authors: Miguel Aldana, Juan Diego Bermeo
Creation date: Miercoles Oct  9 2013
"""

def fourierTransform(data):
	"""
	Carga un array de numpy [400,24] y le calcula la transformada de fourier a cada uno de los vectores columna devuelve dos arreglos de [400,24], uno para las amplitudes y otro para las frecuencias, donde el i-esimo vector columna de amplitudes le corresponde el i-esimo vector columna de frecuencias 
	Input: arreglo de numpy [400,24]
	Output: dos arreglos de numpy de [400,24], donde el primero corresponde a frecuencias, y el segundo a amplitudes. 
	"""

	fft_amplitudes = data
	fft_freq = data
	return fft_freq, fft_amplitudes

def inv_fft(fft_freq, fft_amplitudes):
	"""
	Carga dos arreglos de numpy de [400,24], donde el primero corresponde a frecuencias, y el segundo a amplitudes y devuelve un arreglo de [400,24] que corresponde a la transformada inversa de fourier de la señal en frecuencia que entre por input. Es decir pasa la señal del dominio de la frecuencia al domino del tiempo
	Input: dos arreglos de numpy de [400,24], donde el primero corresponde a frecuencias, y el segundo a amplitudes. 
	Output: un arreglo de numpy de [400,24]
	"""
	invfft = fft_freq
	
	return invfft

def chiCuadrado(data,dataReconstruida)
	"""
	Carga dos arrays de numpy [400,24], uno con los datos originales del encefalograma, y otro con el encefalograma construida con las 10 frecuencias con mayor potencia, y calcula el chi cuadrado para el i-esimo vector columna de los dos arreglos, y los imprime en pantalla.
	Input: Dos arreglos de numpy de [400,24]
	Output: Nada 
	"""
	
	chi2 = empty(24)
		
	return

