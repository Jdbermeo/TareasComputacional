#include <stdlib.h>
#include <stdio.h>	
#include <math.h>

#include <string.h>

#define G 4499554
#define dt 5.0/120

int main()
{
	FILE *out;
	int clase,test;
	float x_i=0, y_i=0,Vx_i=0,Vy_i=0;

	out = fopen("a.txt", "r");
	
	do{
		test = fscanf(out, "%i", &(clase));
		if(clase == 1)
		test = fscanf(out, "%f %f %f %f\n", &(x_i), &(y_i),&(Vx_i),&(Vy_i));
			
	printf("%f ",x_i);
	printf("%f ",y_i);
	printf("%f ",Vx_i);
	printf("%f \n",Vy_i);
			
	}while(test!=EOF);	//printf("str1 %f ",dt*120);

	return 0;
}
