/*

Este programa toma cuatro numeros como prametros.
Todos son del tipo float.
Genera un archivo de texto con las condiciones iniciales necesaria para modelar una galaxia simplificada.

*/
	
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#define PI 3.14159265
	
/* Se definen las variables y las constantes*/
	
	FILE *input;
	double G;
	double KPARSEC;
	double MASA_SOLAR;
	double x_centro,y_centro,vx_centro,vy_centro;
	int i,j,columnas,filas,memoria_i;
	double *x,*y,*v_x,*v_y;
	int *ID;
	int num_estrellas=121;
	double theta=0.0;
	int *orbitas;
	double masa;
	double AUX;
	double a_x,a_y,vx,vy,vel;
double Convertir(){

	double a= pow(10,30);
	double b=pow(10,16);
	double d=pow(10,30);
	double l=pow(10,-11);
	masa=1/(1.9891*d);
	MASA_SOLAR=a*1.9891;
	KPARSEC=3.086*b;
	G=((pow(10,-9)))*6.67384*l ;
	
}



	/*Método que asigna a una particula su velocidad y posicion inicial.
	Parametros: 
	int orbita: Determina la orbita a la que esta la particula en cuention. Con este parametro se determinan tambien la velocidad y7 ep 		radio.
	int angulo: Determina la posicion en la orbita de la particula.
	return: Velocidad y posicion de la particula medida con respecto a la masa central de la galaxia.
	*/
	
double asignarCondiciones(int orbita, double thetaa){

	double a=pow(10,12);
	double t=pow(10,16);
	vel=pow(((G*MASA_SOLAR*a)/(3.086*t*orbita*10)),0.5);
	a_x=(orbita*10*cos(thetaa))+x_centro;
	a_y=(orbita*10*sin(thetaa))+y_centro;
	vx=vx_centro-vel*sin(thetaa);
	vy=vy_centro+vel*cos(thetaa);
return 0.0;
	
}
	
int main(int argc, char **argv){

	Convertir();
	x_centro=atof(argv[1]);
	y_centro=atof(argv[2]);
	vx_centro=atof(argv[3]);
	vy_centro=atof(argv[4]);
	
	x = malloc( num_estrellas* sizeof(double));
	y = malloc(num_estrellas * sizeof(double));
 	v_x = malloc(num_estrellas * sizeof(double));	
 	v_y = malloc(num_estrellas * sizeof(double));
	ID=malloc(num_estrellas * sizeof(int));
	orbitas=malloc(6 * sizeof(int));
	
	orbitas[0]=12;
	orbitas[1]=18;
	orbitas[2]=24;
	orbitas[3]=30;
	orbitas[4]=36;

	x[0]=x_centro;
	y[0]=y_centro;
	v_x[0]=vx_centro;
	v_y[0]=vy_centro;
	
	for(i=0;i<num_estrellas;i++){
		ID[i]=i-1;
	}


	/* Verificamos que el numero de parametros es el correcto */
	
	printf("Este programa se esta ejecutando con %d argumento(s):\n",argc-1);
	for(i=1;i<argc;i++){
    	printf("%s\n", argv[i]);
  	}
  	if(argc-1!=4){
   	printf("Se necesitan 4 parametros para determinar las condiciones iniciales\n EXIT!\n");
    	exit(1);
    	}
printf("Check_point 1 \n");

	/* Aqui irá un loop que utilizara la funcion asignarCondiciones(int orbita, double angulo) para dar a cada particula 
	su posicion y velocidad inicial*/
	

	for (i=1;i<=12;i++){

			asignarCondiciones(1, theta);
			x[i]=a_x;
			y[i]=a_y;
			v_x[i]=vx;
			v_y[i]=vy;
			theta=theta+(2*PI/12);	
	}


	for (i=13;i<=12+18;i++){

			asignarCondiciones(2, theta);
			x[i]=a_x;
			y[i]=a_y;
			v_x[i]=vx;
			v_y[i]=vy;
			theta=theta+(2*PI/18);	
			
	}
	
	for (i=31;i<=54;i++){

			asignarCondiciones(3, theta);
			x[i]=a_x;
			y[i]=a_y;
			v_x[i]=vx;
			v_y[i]=vy;
			theta=theta+(2*PI/24);	
	}
	
	for (i=55;i<=84;i++){

			asignarCondiciones(4, theta);
			x[i]=a_x;
			y[i]=a_y;
			v_x[i]=vx;
			v_y[i]=vy;
			theta=theta+(2*PI/30);	
	}
	
	for (i=85;i<num_estrellas;i++){

			asignarCondiciones(5, theta);
			x[i]=a_x;
			y[i]=a_y;
			v_x[i]=vx;
			v_y[i]=vy;
			theta=theta+(2*PI/36);	
	}
	
	



printf("Check_point 2 \n");
	
	/* Finalmente creamos un archivo y escribimos en él las condiciones de cada particula en una tabla*/

	input=fopen("Condiciones_iniciales.dat","w");
	for (i=0;i<num_estrellas;i++){
	
		fprintf(input,"%i %f %f %f %f \n", ID[i],x[i],y[i],v_x[i],v_y[i]);
		
	}	
	 fclose(input);
	
}


	


