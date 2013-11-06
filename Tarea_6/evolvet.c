#include <stdlib.h>
#include <stdio.h>	
#include <math.h>
#include <string.h>


#define G 4499554
#define dt 5.0/10000
#define Fv 1.0226895
#define it 10001

/*Definir como van a interactuar y cambiar las posiciones de los centros de masas de las dos galaxias. Con eso definido lo hecho para los otros puntos va a funcionar. Adicionalmente puede ayudar a mejorar el proceso para calcular el cambio en la poscion de los otros puntos. 

*/

<<<<<<< HEAD
double y1prima(float V_ant)
{
	return 	V_ant;
}

double y2prima(float x1, float x2,float rx1,float rx2)
=======
double y1prima(double t,double x, double y, double vx,double vy,double rx,double ry)
{
	return 	-4.4973*(10**15)*(x-rx);
}

double y2prima(double t,double y1,double y2)
>>>>>>> 900585269b26f564ca17ec6651527c1566ababbd
{
	
	return 	-G*(x1-rx1)/(pow(pow((x1-rx1),2)+pow((x2-rx2),2),(1.5)));
}

int main(int argc, char **argv)
{
	int numG = 0,numE = 0;
	int test,i = 0,j = 0,k,clase;
	float a1,a2,a3,a4;
	float *x_iG,*y_iG,*Vx_iG,*Vy_iG; //Para guardar las condiciones iniciales de los centros de las galaxias
	float *x_iE,*y_iE,*Vx_iE,*Vy_iE; //Para guardar las condiciones iniciales de las estrellas
	float *posG_x,*posG_y,*VG_x,*VG_y;
	float *posE_x,*posE_y,*VE_x,*VE_y;
	
	//Abrir el archivo con las condiciones inicales de cada partícula
	FILE *in;
	FILE *out;
	in = fopen(argv[1],"r");
	
	//Se lee la posición de cada archivo  test = fscanf(in, "%i %f %f %f %f\n", &(clase), &(x_i), &(y_i),&(Vx_i),&(Vy_i));
	do{
		test = fscanf(in, "%i %f %f %f %f\n", &(clase),&(a1),&(a2),&(a3),&(a4));
		if(clase != -1)
		{
			numE++;
		}
		else
		{
			numG++;
		}
		j++;
	}while(test!=EOF);

	if(numG>=j)
	{	
		numG =numG-1;
		printf("%i %i %i\n",numG, numE,j-1);
	}
	if(numE>=j)
	{	
		numE = numE-1;
		printf("%i %i %i\n",numG, numE,j-1);
	}
	else
	{ 
		numE = numE-1;
		printf("%i %i %i\n",numG, numE,j-1);
	}

	//Arreglo donde se van a guardar las posiciones de los puntos. Se guardan solo 2 puntos para ahorrar memoria, y se imprimirá en los respectivos archivos cuando llegue a los tiempos definidos.

	posG_x = malloc(2 * numG * sizeof(float));
	posG_y = malloc(2 * numG * sizeof(float));
	posE_x = malloc(2 * numE * sizeof(float));
	posE_y = malloc(2 * numE * sizeof(float));

	VG_x = malloc(2 * numG * sizeof(float));
	VG_y = malloc(2 * numG * sizeof(float));
	VE_x = malloc(2 * numE * sizeof(float));
	VE_y = malloc(2 * numE * sizeof(float));

//Arreglos para guardar las condiciones iniciales 
	
	x_iG = malloc((numG)*sizeof(float));
	y_iG = malloc((numG)*sizeof(float));
	Vx_iG = malloc((numG)*sizeof(float));
	Vy_iG = malloc((numG)*sizeof(float));

	x_iE = malloc((numE)*sizeof(float));
	y_iE = malloc((numE)*sizeof(float));
	Vx_iE = malloc((numE)*sizeof(float));
	Vy_iE = malloc((numE)*sizeof(float));

//Guarda las posiciones inciales de las galaxias del problema
	do{
			test = fscanf(in, "%i ", &(clase));
			if(clase == -1)
			{
				test = fscanf(in, "%f %f %f %f\n", &(x_iG[i]), &(y_iG[i]),&(Vx_iG[i]),&(Vy_iG[i]));
				i++;
			}	
			
			if(clase != -1)
			{
				test = fscanf(in, "%f %f %f %f\n", &(x_iE[j]), &(y_iE[j]),&(Vx_iE[j]),&(Vy_iE[j]));
				j++;				
			}
	}while(test!=EOF);

	//Calcula el cambio en la posición del centro de las galaxias de acuerdo al numero de galaxias que hayan.
	if(numG==1)
	{
		for(i=1;i<=(numG+numE);i++)
		{
			//Dado que la velocidad se mantiene constante, solo se multiplica el cambio de tiempo por el cambio en tiempo.
			posG_x[i] = posG_x[i-1]+ i*dt*Vx_iG[0]*Fv;
			posG_y[i] = posG_y[i-1]+ i*dt*Vy_iG[0]*Fv;	
		}
	}

	if(numG>1)
	{
	
		//Guarda las posiciones iniciales
		for(i=0;i<numG;i++)
		{
			posG_x[i*2] = x_iG[i];
			posG_y[i*2] = y_iG[i];
			VG_x[i*2] = Vx_iG[i]*Fv;
			VG_y[i*2] = Vy_iG[i]*Fv;
		}
		
		for(i=0;i<numE;i++)
		{
			posE_x[i*2] = x_iE[i];
			posE_y[i*2] = y_iE[i];
			VE_x[i*2] = Vx_iE[i]*Fv;
			VE_y[i*2] = Vy_iE[i]*Fv;
		}		

	//Hacer Runge-Kutta cuarto orden
	for(i=1;i<it;i++)
	{
		float kx11[numG+numE],kx12[numG+numE], kx13[numG+numE], kx14[numG+numE], kx21[numG+numE],kx22[numG+numE],kx23[numG+numE],kx24[numG+numE];
		memset( kx11, 0,  numG+numE * sizeof(float));
		memset( kx12, 0,  numG+numE * sizeof(float));
		memset( kx13, 0,  numG+numE * sizeof(float));
		memset( kx14, 0,  numG+numE * sizeof(float));
		memset( kx21, 0,  numG+numE * sizeof(float));
		memset( kx22, 0,  numG+numE * sizeof(float));
		memset( kx23, 0,  numG+numE * sizeof(float));
		memset( kx24, 0,  numG+numE * sizeof(float));

		float ky11[numG+numE],ky12[numG+numE], ky13[numG+numE], ky14[numG+numE], ky21[numG+numE],ky22[numG+numE],ky23[numG+numE],ky24[numG+numE];
		memset( ky11, 0,  numG+numE *sizeof(float));
		memset( ky12, 0,  numG+numE *sizeof(float));
		memset( ky13, 0,  numG+numE *sizeof(float));
		memset( ky14, 0,  numG+numE *sizeof(float));
		memset( ky21, 0,  numG+numE *sizeof(float));
		memset( ky22, 0,  numG+numE *sizeof(float));
		memset( ky23, 0,  numG+numE *sizeof(float));
		memset( ky24, 0,  numG+numE *sizeof(float));

		float promKx1[numG+numE],promKx2[numG+numE],promKy1[numG+numE],promKy2[numG+numE];

		float x11[numG+numE],x12[numG+numE],x13[numG+numE],x14[numG+numE],x21[numG+numE],x22[numG+numE],x23[numG+numE],x24[numG+numE];
		float y11[numG+numE],y12[numG+numE],y13[numG+numE],y14[numG+numE],y21[numG+numE],y22[numG+numE],y23[numG+numE],y24[numG+numE];
	
		//Primer paso
		for(j=0;j<numG;j++)
		{
			//Centros de galaxias
			for(k=0;k<numG;k++)
			{	
				
				//Cambio en posicion por la velocidad del centro de la galaxia
				if(k==j)
				{				
					kx11[j] += y1prima(VG_x[j*2]); //Para x
					ky11[j] += y1prima(VG_y[(j*2)]); //Para y
				}				
				//Aceleracion por los centros de otras galaxias
				if(k!=j)
				{
					kx21[j] += y2prima(posG_x[(j*2)],posG_y[(j*2)],posG_x[(k*2)],posG_y[(k*2)]); //Para x
					ky21[j] += y2prima(posG_y[(j*2)],posG_x[(j*2)],posG_y[(k*2)],posG_x[(k*2)]); //Para y
				}

		}

		for(j=0;j<numG;j++)
		{		
			x11[j] = posG_x[(j*2)]+ (dt/2.0)*kx11[j];
			x21[j] = VG_x[(j*2)] + (dt/2.0)*kx21[j];
			y11[j] = posG_y[(j*2)] + (dt/2.0)*ky11[j];
			y21[j] = VG_y[(j*2)] + (dt/2.0)*ky21[j];		
		}
		
		//Para las estrellas
		for(j=numG;j<(numG+numE);j++)
		{
			for(k=0;k<numG;k++)
			{
				kx11[j]+= y1prima(VE_x[(j-numG)*2]);
				kx21[j]+= y2prima(posE_x[(j-numG)*2],posE_y[(j-numG)*2],posG_x[(k*2)],posG_y[(k*2)]);
			
				ky11[j]+= y1prima(VE_x[(j-numG)*2]);
				ky21[j]+= y2prima(posE_y[(j-numG)*2],posE_x[(j-numG)*2],posG_y[(k*2)],posG_x[(k*2)]);
			}		
		}	

		for(j=numG;j<(numG+numE);j++)
		{		
			x11[j] = posE_x[(j*2)]+ (dt/2.0)*kx11[j];
			x21[j] = VE_x[(j*2)] + (dt/2.0)*kx21[j];
			y11[j] = posE_y[(j*2)] + (dt/2.0)*ky11[j];
			y21[j] = VE_y[(j*2)] + (dt/2.0)*ky21[j];
		}	
	
		//Segundo paso
		for(j=0;j<numG;j++)
		{
			for(k=0;k<numG;k++)
			{		
				//Cambio en posicion por la velocidad de la galaxia
				if(k==j)
				{				
					kx12[j] += y1prima(x21[j]); //Para x
					ky12[j] += y1prima(y21[j]); //Para y
				}				
				//Aceleracion por los centros de otras galaxias
				if(k!=j)
				{
					kx22[j] +=  y2prima(x11[j],y11[j],x11[k],y11[k]); //Para x
					ky22[j] +=  y2prima(y11[j],x11[j],y11[k],x11[k]); //Para y
				}
			}
		}

		for(j=0;j<numG;j++)
		{		
			x12[j] = posG_x[(j*2)]+ (dt/2.0)*kx12[j];
			x22[j] = VG_x[(j*2)] + (dt/2.0)*kx22[j];
			y12[j] = posG_y[(j*2)] + (dt/2.0)*ky12[j];
			y22[j] = VG_y[(j*2)] + (dt/2.0)*ky22[j];		
		}	
		
		//Para las estrellas
		for(j=numG;j<(numG+numE);j++)
		{
			for(k=0;k<numG;k++)
			{
				kx12[j]+= y1prima(x21[j]);
				kx22[j]+= y2prima(x11[j],y11[j],x11[k],y11[k]);
			
				ky12[j]+= y1prima(y21[j]);
				ky22[j]+= y2prima(y11[j],x11[j],y11[k],x11[k]);
			}		
		}	

		for(j=numG;j<(numG+numE);j++)
		{		
			x12[j] = posE_x[(j*2)]+ (dt/2.0)*kx12[j];
			x22[j] = VE_x[(j*2)] + (dt/2.0)*kx22[j];
			y12[j] = posE_y[(j*2)] + (dt/2.0)*ky12[j];
			y22[j] = VE_y[(j*2)] + (dt/2.0)*ky22[j];
		}			
		
		//Tercer paso
		for(j=0;j<numG;j++)
		{
			for(k=0;k<numG;k++)
			{		
				//Cambio en posicion por la velocidad de la galaxia
				if(k==j)
				{				
					kx13[j] += y1prima(x22[j]); //Para x
					ky13[j] += y1prima(y22[j]); //Para y
				}				
				//Aceleracion por los centros de otras galaxias
				if(k!=j)
				{
					kx23[j] +=  y2prima(x12[j],y12[j],x12[k],y12[k]); //Para x
					ky23[j] +=  y2prima(y12[j],x12[j],y12[k],x12[k]); //Para y
				}
			}
		}

		for(j=0;j<numG;j++)
		{		
			x13[j] = posG_x[(j*2)]+ (dt)*kx13[j];
			x23[j] = VG_x[(j*2)] + (dt)*kx23[j];
			y13[j] = posG_y[(j*2)] + (dt)*ky13[j];
			y23[j] = VG_y[(j*2)] + (dt)*ky23[j];		
		}	
		
		//Para las estrellas
		for(j=numG;j<(numG+numE);j++)
		{
			for(k=0;k<numG;k++)
			{
				kx13[j]+= y1prima(x22[j]);
				kx23[j]+= y2prima(x12[j],y12[j],x12[k],y12[k]);
			
				ky13[j]+= y1prima(y22[j]);
				ky23[j]+= y2prima(y12[j],x12[j],y12[k],x12[k]);
			}		
		}	

		for(j=numG;j<(numG+numE);j++)
		{		
			x13[j] = posE_x[(j*2)]+ (dt)*kx13[j];
			x23[j] = VE_x[(j*2)] + (dt)*kx23[j];
			y13[j] = posE_y[(j*2)] + (dt)*ky13[j];
			y23[j] = VE_y[(j*2)] + (dt)*ky23[j];
		}			
		
		
		//Cuarto Paso, k4
		//Centros de las galaxias
		for(j=0;j<numG;j++)
		{
			for(k=0;k<numG;k++)
			{		
				//Cambio en posicion por la velocidad de la galaxia
				if(k==j)
				{				
					kx14[j] += y1prima(x23[j]); //Para x
					ky14[j] += y1prima(y23[j]); //Para y
				}				
				//Aceleracion por los centros de otras galaxias
				if(k!=j)
				{
					kx24[j] +=  y2prima(x13[j],y13[j],x13[k],y13[k]); //Para x
					ky24[j] +=  y2prima(y13[j],x13[j],y13[k],x13[k]); //Para y
				}
			}
		}

		//Estrellas		
		for(j=numG;j<(numG+numE);j++)
		{
			for(k=0;k<numG;k++)
			{
				kx14[j]+= y1prima(x23[j]);
				kx24[j]+= y2prima(x13[j],y13[j],x13[k],y13[k]);
			
				ky14[j]+= y1prima(y23[j]);
				ky24[j]+= y2prima(y13[j],x13[j],y13[k],x13[k]);
			}		
		}	

		//Promedio 
		for(j=0;j<(numG);j++)
		{		
			promKx1[j] = (1.0/6.0)*(kx11[j] + 2.0*kx12[j] + 2.0*kx13[j] + kx14[j]);
			promKx2[j] = (1.0/6.0)*(kx21[j] + 2.0*kx22[j] + 2.0*kx23[j] + kx24[j]);

			promKy1[j] = (1.0/6.0)*(ky11[j] + 2.0*ky12[j] + 2.0*ky13[j] + ky14[j]);
			promKy2[j] = (1.0/6.0)*(ky21[j] + 2.0*ky22[j] + 2.0*ky23[j] + ky24[j]);

			posG_x[(j*2)] = posG_x[(j*2)] + i*dt * promKx1[j]; 
			VG_x[(j*2)] = VG_x[(j*2)] + i*dt * promKx2[j]; 
			posG_y[(j*2)] = posG_y[(j*2)] + i*dt * promKy1[j];
			VG_y[(j*2)] = VG_y[(j*2)] + i*dt * promKy2[j];
		}

		for(j=numG;j<(numG+numE);j++)
		{		
			promKx1[j] = (1.0/6.0)*(kx11[j] + 2.0*kx12[j] + 2.0*kx13[j] + kx14[j]);
			promKx2[j] = (1.0/6.0)*(kx21[j] + 2.0*kx22[j] + 2.0*kx23[j] + kx24[j]);

			promKy1[j] = (1.0/6.0)*(ky11[j] + 2.0*ky12[j] + 2.0*ky13[j] + ky14[j]);
			promKy2[j] = (1.0/6.0)*(ky21[j] + 2.0*ky22[j] + 2.0*ky23[j] + ky24[j]);

			posE_x[(j*2)-numG] = posE_x[(j*2)-numG] + i*dt * promKx1[j]; 
			VE_x[(j*2)-numG] = VE_x[(j*2)-numG] + i*dt * promKx2[j]; 
			posE_y[(j*2)-numG] = posE_y[(j*2)-numG] + i*dt * promKy1[j];
			VE_y[(j*2)-numG] = VE_y[(j*2)-numG] + i*dt * promKy2[j];
		}
		
		//Escribir los datos en un archivo de texto para graficarlos posteriormente
		if(i*dt==1)
		{	
			char str1[50];
			char str2[50] = "1 billon de años ";
			sprintf(str1,"%i galaxia(s).txt",numG);
			strcat(str2,str1);
			out = fopen(str2,"a");	
			for(j=0;j<numG;j++)
			{
				fprintf(out,"-1 %f %f \n",posG_x[(j*2)],posG_y[(j*2)]);
			}
			
			for(j=numG;j<(numG+numE);j++)
			{
				fprintf(out,"0 %f %f \n",posE_x[(j*2)],posE_y[(j*2)]);
			}
		}	
		if(i*dt==2)
		{	
			char str1[50];
			char str2[50] = "2 billon de años ";
			sprintf(str1,"%i galaxia(s).txt",numG);
			strcat(str2,str1);
			out = fopen(str2,"a");		
			for(j=0;j<numG;j++)
			{
				fprintf(out,"-1 %f %f \n",posG_x[(j*2)],posG_y[(j*2)]);
			}
			
			for(j=numG;j<(numG+numE);j++)
			{
				fprintf(out,"0 %f %f \n",posE_x[(j*2)],posE_y[(j*2)]);
			}
		}
		if(i*dt==3)
		{	
			char str1[50];
			char str2[50] = "3 billon de años ";
			sprintf(str1,"%i galaxia(s).txt",numG);
			strcat(str2,str1);
			out = fopen(str2,"a");		
			for(j=0;j<numG;j++)
			{
				fprintf(out,"-1 %f %f \n",posG_x[(j*2)],posG_y[(j*2)]);
			}
			
			for(j=numG;j<(numG+numE);j++)
			{
				fprintf(out,"0 %f %f \n",posE_x[(j*2)],posE_y[(j*2)]);
			}
		}
		if(i*dt==4)
		{	
			char str1[50];
			char str2[50] = "4 billon de años ";
			sprintf(str1,"%i galaxia(s).txt",numG);
			strcat(str2,str1);
			out = fopen(str2,"a");	
			for(j=0;j<numG;j++)
			{
				fprintf(out,"-1 %f %f \n",posG_x[(j*2)],posG_y[(j*2)]);
			}
			
			for(j=numG;j<(numG+numE);j++)
			{
				fprintf(out,"0 %f %f \n",posE_x[(j*2)],posE_y[(j*2)]);
			}
		}
		if(i*dt==5)
		{	
			char str1[50];
			char str2[50] = "5 billon de años ";
			sprintf(str1,"%i galaxia(s).txt",numG);
			strcat(str2,str1);
			out = fopen(str2,"a");	
			for(j=0;j<numG;j++)
			{
				fprintf(out,"-1 %f %f \n",posG_x[(j*2)],posG_y[(j*2)]);
			}
			
			for(j=numG;j<(numG+numE);j++)
			{
				fprintf(out,"0 %f %f \n",posE_x[(j*2)],posE_y[(j*2)]);
			}
		}		
	}

	}
	}
	else
	{
		printf("El archivo de condiciones iniciales no contiene el centro de la galaxia");
	}

	return 0;
}
