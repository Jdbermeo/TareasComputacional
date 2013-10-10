def espectro_potencias(fft_x,fft_freq):

     """
     
     Esta funcion calcula el espectro de potencias de cada senal y devuelve los 10 valores mas grandes de amplitud con su respectiva frecuencia.

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
