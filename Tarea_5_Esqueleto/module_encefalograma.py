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

def inv_fft(ffft_amplitudes):
	"""
	Carga dos arreglos de numpy de [400,24], donde el primero corresponde a frecuencias, y el segundo a amplitudes y devuelve un arreglo de [400,24] que corresponde a la transformada inversa de fourier de la senal en frecuencia que entre por input. Es decir pasa la senal del dominio de la frecuencia al domino del tiempo
	Input: dos arreglos de numpy de [400,24], donde el primero corresponde a frecuencias, y el segundo a amplitudes. 
	Output: un arreglo de numpy de [400,24]
	"""
	invfft = fft_amplitudes
	
	return invfft

def espectro_potencias(fft_x,fft_freq):

     """
     
     Esta funcion calcula el espectro de potencias de cada senal y devuelve los 10 valores mas grandes de amplitud con su respectiva frecuencia. Las otras frecuencias las hace iguales a cero

     Input:
     - fft_freq: arreglo numpy de tamano [400,24]. Frecuencias de cada senal.
     - fft_x: arreglo numpy de numeros complejos de tamano [400,24]. Amplitudes de cada senal.

     Output:
     - max_espectro_x: arreglo numpy con los 10 valores de fft_x normalizados mas grandes de tamano [400,24].
     - max_espectro_freq: arreglo numpy con los 10 valores correspondientes a valor de max_espectro_x de tamano[400,24].

     24 corresponde a las senales.
     400 corresponde a las frecuencias.

     """

     max_espectro_x = fft_x;
     max_espectro_freq = fft_freq;

     return max_espectro_x, max_espectro_freq

def chiCuadrado(data,dataReconstruida):
	"""
	Carga dos arrays de numpy [400,24], uno con los datos originales del encefalograma, y otro con el encefalograma construida con las 10 frecuencias con mayor potencia, y calcula el chi cuadrado para el i-esimo vector columna de los dos arreglos, y los imprime en pantalla.
	Input: Dos arreglos de numpy de [400,24]
	Output: Nada 
	"""
	
	chi2 = empty(24)
		
	return

