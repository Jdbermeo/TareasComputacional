/*

Este programa carga uno o varios archivo(s) de texto donde se encuentra(n) determinadas las condiciones iniciales
del problema de las galaxias y las usa como parametros.
Todos los parametros son del tipo float.
Genera 5 archivos de texto cada uno con las posiciones finales y velocidades de cada particula. Al programa no le importa cuantas galaxias esta manejando, simplemente resuelve las ecuaciones necesarias para determinar Las posiciones y las velocidades.

*/

#include <stdlib.h>
#include <stdio.h>
#include <gsl/gsl_math.h>
#include <gsl/gsl_eigen.h>
#include <gsl/gsl_blas.h>
#include <gsl/gsl_linalg.h> 
#include <string.h>
#include <math.h>

/*
	Una de las dos ecuaciones diferenciales de primer orden para rsolver la ecuacion diferencial de la interaccion gravitacional. Esta formula se usa en el metodo Runge-Kutta para solucionar la ecuacion diferencial de forma numerica.
	Input:
	- x: variable sobre la que se deriva, es decir el tiempo
	- y1: Posicion en veolcidad
	- y2: Posicion en 
	- R: Distancia a la galaxia.
	Output:
	-El resultado de evaluar el cambio o y prima definido por la ecuacion diferencial de primer orden.
*/
double y1prima(double x,double y1,double y2,double R)
{
	return 	y2;
}

/*
	Una de las dos ecuaciones diferenciales de primer orden para rsolver la ecuacion diferencial de la interaccion gravitacional. Esta formula se usa en el metodo Runge-Kutta para solucionar la ecuacion diferencial de forma numerica.
	Input:
	- x: variable sobre la que se deriva, es decir el tiempo
	- y1: Posicion en veolcidad
	- y2: Posicion en 
	- R: Distancia a la galaxia.
	Output:
	-El resultado de evaluar el cambio o y prima definido por la ecuacion diferencial de primer orden.
*/
double y2prima(double x,double y1,double y2,double R)
{
	
	return 	y1;
}

 
/*
	El programa recibe como parámetro el nombre del archivo donde se encuentran las posiciones y velocidades iniciales de las estrelals y de los centros de las galaxias. Con estos datos se calcula el cambio en posicion de las estrellas debido a la fuerza de atraccion del centro de cada galaxia. 
	-Primero se evalua el cambio en posicion de los centros de masa de las galaxias por su interaccion gravitacional con el metodo Runge-Kutta de cuarto orden. 
	-Despues se evalua el cambio en posicion de las estrellas teniendo en cuenta el cambio de posicion para los mismos cambios en tiempo de los centros de las galaxias.
	-Se escribe en un 5 archivos de texto de las posiciones de los cuerpos en intervalos de billon de años hasa llegar a 5 billones de años. 

*/

int main(int argc, char **argv){

	/* Se definen las variables y las constantes*/
	
	FILE *input; //Para abrir el archivo de las condicones iniciales
	double G;
	double numG =0; //Para guardar el número de galaxias.
	int i,j; // Para los loops. 


	/* Se verifican cuantos archivos de texto entran como parametro*/
	
	printf("Este programa se esta ejecutando con %d argumento(s):\n",argc-1);
	for(i=1;i<argc;i++){
    	printf("%s\n", argv[i]);
  	}
	printf("El programa se dispone a calcular la dinamica de %d galaxia(s)\n EXIT!\n", argc-1);
	
	input=fopen(argv[1],"r");
    	if(!input){
      	printf("surgió un problema abriendo el archivo\n");
      	exit(1);
   	 }
	
	/* Primero se aplica el método Runge Kutta de cuarto orden a los centros de cada galaxia y se obtiene una matriz con sus posiciones en el tiempo para despues usarse en el calculo del cambio en posicion de las estrellas*/
	double **R;

	/*Se aplica ahora el metdo Runge-Kutta de cuarto orden a las estrellas para ver sus diferentes coordenadas espaciales en el tiempo*/
	RungeKutta(1.0,2.0,3.0,4.0,R[1][1],5) ;

	fclose(input);

	input=fopen(argv[2],"r");
    	if(!input){
      	printf("surgió un problema abriendo el archivo\n");
      	exit(1);
   	 }

}

int RungeKutta(double x_i, double vx_i, double y_i,double vy_i, double **R,int numG)
{
	/*
		Este método se encarga de tomar las condiciones iniciales de una de las estrellas, y aplicar el metodo Runge-Kutta de cuarto orden para resolver la ecuacion diferencial del movimiento con una fuerza central. 
		-El metodo se encarga de escribir en 5 archivos la posicion del cuerpo cuyas condicones iniciales recibe cuando pasan 1 billon de años hasta llegar a 5 billones de años. 
		-Calcula el cambio en posicion para el numero de galaxias presentes en el archivo de condiciones iniciales.
		-Llama las funciones y1prima y2prima que se usan en el metodo Runge-Kutta
		
	Input:
		-x_i: Posicion inicial en el eje x
		-y_i: Posicion inicial en el eje y
		-vx_i: Velocidad inicial en el eje x
		-vy_i: Velocidad inicial en el eje y
		- R[][], Matriz donde cada columna representa una galaxia y cada fila el cambio de posicion de cada galaxia, con el mismo cambio en el tiempo que se va usar en el Runge-Kutta para las estrellas

	Output:
		Una línea en 5 archivos diferentes. Cada archivo representa el cambio en un billon de años, y la linea sera la posicion de la estrella en ese tiempo. 
	*/

	y1prima(1,1,1,1);
	
	y1prima(1,1,1,1);

	return 0;
}



