#include <stdlib.h>
#include <stdio.h>	
#include <math.h>
#include <gsl/gsl_math.h>
#include <string.h>
#include <gsl/gsl_eigen.h>
#include <gsl/gsl_vector.h>
#include <gsl/gsl_matrix.h>
#include <gsl/gsl_blas.h>


/*Definir como van a interactuar y cambiar las posiciones de los centros de masas de las dos galaxias. Con eso definido lo hecho para los otros puntos va a funcionar. Adicionalmente puede ayudar a mejorar el proceso para calcular el cambio en la poscion de los otros puntos. 
*/

double y1prima(double t,double x, double y, double vx,double vy,double rx,double ry)
{
	return 	-4.4973*(10**15)*(x-rx);
}

double y2prima(double t,double y1,double y2)
{
	
	return 	-4896189*y1;
}

int main(int argc, char **argv)
{
	int numG = 0;
	int clase;
	double x_i,y_i,Vx_i,Vy_i;
	
	//Abrir el archivo con las condiciones inicales de cada partícula
	FILE *in;
	in = fopen(argv[1],"r");
	
	//Se lee la posición de cada archivo  test = fscanf(in, "%i %f %f %f %f\n", &(clase), &(x_i), &(y_i),&(Vx_i),&(Vy_i));
	do{
		test = fscanf(in, "%i \n", &(clase));
		if(i==-1)
		{
			numG++;
		}	

	}while(test!=EOF);

	if(numG==1)
	{
		do{
			test = fscanf(in, "%i %f %f %f %f\n", &(clase), &(x_i), &(y_i),&(Vx_i),&(Vy_i));
			if(i==-1)
			{
				numG++;
				test = EOF;
			}	

		}while(test!=EOF);

	}

	if(numG>1)
	{

	}

	else
	{
		printf("El archivo de condiciones iniciales no contiene el centro de la galaxia");
	}
	return 0;
}


int RungeKutta(double x_i, double vx_i, double y_i,double vy_i, double R[][],int numG)
{
	//Leer condiciones inciales del archivo
	int i,j;
	int numPuntos = 120;
	double deltat= 5/numPuntos;
	double t[numPuntos],v[numPuntos],r[numPuntos],x[numPuntos],y[numpuntos];

	//Para imprimir el resultado en un archivo	
	FILE *out;

	//Definir las condiciones iniciales
		t[0] = 0;
		r[0] = ((y_i**2)+(x_i**2))**(0.5);
		v[0] = ((vy_i**2)+(vx_i**2))**(0.5);

	//Hacer Runge-Kutta cuarto orden
	for(i=1;i<numPuntos;i++)
	{
		double k11=0,k12=0,k13=0,k14=0,k21=0,k22=0,k23=0,k24=0,
		for(j=0;j<numG;j++)
		{
			k11 = k11 + y1prima(t[i-1],r[i-1],v[i-1],R[i][j]);
			k21 = k21 + y2prima(t[i-1],r[i-1],v[i-1],R[i][j]);
		}	

		//Primer paso
		double t1 = t[i-1] + (deltat/2.0);
		double y11 = r[i-1] + (deltat/2.0)*k11;
		double y21 = v[i-1] + (deltat/2.0)*k21;
		
		for(j=0;j<numG;j++)
		{
			k12 = k12 + y1prima(t1,y11,y21,R[i][j]);
			k22 = k22 + y2prima(t1,y11,y21,R[i][j]);
		}

		//Segundo paso
		double t2 = t[i-1] + (deltat/2.0);
		double y12 = r[i-1] + (deltat/2.0)*k12;
		double y22 = v[i-1] + (deltat/2.0)*k22;		
		
		for(j=0;j<numG;j++)
		{		
			k13 = k13 + y1prima(t2,y12,y22,R[i][j]));
			k23 = k23 + y2prima(t2,y12,y22,R[i][j]));	
		}

		//Tercer paso
		double t3 = t[i-1] + (deltat);
		double y13 = r[i-1] + (deltat)*k13;
		double y23 = v[i-1] + (deltat)*k23;		
		
		for(j=0;j<numG;j++)
		{
			k14 = y1prima(t3,y13,y23,R[i][j]);
		 	k24 = y2prima(t3,y13,y23,R[i][j]);
		}	

		//Cuarto Paso, Promedio
		double promK1 = (1.0/6.0)*(k11 + 2.0*k12 + 2.0*k13 + k14);
		double promK2 = (1.0/6.0)*(k21 + 2.0*k22 + 2.0*k23 + k24);

		t[i] = t[i-1] + (deltat);
		r[i] = r[i-1] + (deltat)*promK1;
		v[i] = v[i-1] + (deltat)*promK2;	

		//Encontrar las nuevas posiciones en X y Y con el nuevo radio y velocidad encontradas
	}
	//Escribir los datos en un archivo de texto para graficarlos posteriormente
	out = fopen("solucionEcuacion.txt","w");	
	for(i=0;i<numPuntos;i++)
	{
		fprintf(out,"%f %f \n",x[i],y1[i]);
	}

	return 0;			
}

