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
	- Carga un array de numpy [4633,5] pero tiene solo en cuenta desde la linea 25 ya que hay muy pocas mediciones por ano de 1612 hacia atras. De igual forma son solo dos anos por lo que se desprecia una pequena cantidad de datos relativamente. 
	- La Interppolacion constante consiste el valor de tiempo desconocido que sigue igual al dato que le precede en tiempo. 
	Input: arreglo de numpy [4633,5]
	Output: arreglo de numpy de [4607] 
	"""
	
	interp_const = data
	return interp_const
	
def interpolacionLineal(data):
	"""
	- Carga un array de numpy [4633,5] pero tiene solo en cuenta desde la linea 25 ya que hay muy pocas mediciones por ano de 1612 hacia atras. De igual forma son solo dos anos por lo que se desprecia una pequena cantidad de datos relativamente. 
	- La Interppolacion lineal consiste en que el valor desconocido se aproxima como el punto en el tiempo t sobre la linea que conecta el anterior punto conocido y el siguiente punto conocido. 
	Input: arreglo de numpy [4633,5]
	Output: arreglo de numpy de [4607] 
	"""
	interp_lineal = data
	return interp_lineal

def interpolacionCubica(data):
	"""
	- Carga un array de numpy [4633,5] pero tiene solo en cuenta desde la linea 25 ya que hay muy pocas mediciones por ano de 1612 hacia atras. De igual forma son solo dos anos por lo que se desprecia una pequena cantidad de datos relativamente. 
	- La Interppolacion cubica consiste en que el valor desconocido se aproxima como el punto en el tiempo t que esta sobre el arco del polinomio de grado 3 que pasa por el anterior punto conocido y el siguiente punto conocido 
	Input: arreglo de numpy [4633,5]
	Output: arreglo de numpy de [4607] 
	"""
	interp_cubica = data
	return interp_cubica

def fourierTransform(data_Interpolacion):
	"""
	Carga un array de numpy [4607] y le calcula la transformada de fourier.
	Input: arreglo de numpy [4607]
	Output: dos arreglos de numpy de [4607]
		- fft_freq: Frecuencias de armonico.
     		- fft_amplitudes: Amplitud de cada xk. 
	"""

	fft_amplitudes = data_Interpolacion
	fft_freq = data_Interpolacion
	return fft_freq, fft_amplitudes

def espectro_potencias(fft_x):

     """
     Esta funcion calcula el espectro de potencias de un arreglo numpy que tiene por entrada, al sacarles el valor absoluto y elevarlo al cuadrado.
     Adicionalmente grafica el espectro de cada interpolacion en una grafica diferente para poder comparar los espectros de potencia de estas.

     Input:
     - fft_x: arreglo numpy de numeros complejos de tamano [4607]. Amplitudes de cada senal.

     Output:
     - espectro_x: arreglo tamano[4607] con las potencias que aporta cada frecuencia.
     """

     espectro_x = fft_x;

     return espectro_x

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

    ampl_ajustada = fft_ampl
    freq = fft_freq

    return ampl_ajustada

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
