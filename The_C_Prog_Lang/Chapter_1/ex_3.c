// modify the temperature conversion program to print a heading above the table
#include <stdio.h>

#define LOWER_LIMIT_TEMPERATURE  0
#define UPPER_LIMIT_TEMPERATURE  300
#define STEP_SIZE  20

int main(void)
{
	int fahr = LOWER_LIMIT_TEMPERATURE;
	float celsius;
	
	while(fahr <= UPPER_LIMIT_TEMPERATURE)
	{
		celsius = (5.0/9.0)*(fahr-32.0);
		printf("%3d \t %.4f \n", fahr, celsius);
		fahr += STEP_SIZE;
	}
	return 0;
}
