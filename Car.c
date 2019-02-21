#include <stdio.h> 
#include <string.h>

typedef struct car {
	char make[25];
	char model[25];
	int year;
} car;


void swap(car* cars, int i, int j)
{
	car temp;

	strcpy(temp.make, cars[i].make);
	strcpy(temp.model, cars[i].model);
	temp.year = cars[i].year;

	strcpy(cars[i].make, cars[j].make);
	strcpy(cars[i].model, cars[j].model);
	cars[i].year = cars[j].year;

	strcpy(cars[j].make, temp.make);
	strcpy(cars[j].model, temp.model);
	cars[j].year = temp.year;
}

int main(void) {
	FILE *CarFile;
	car* cars = (car*)malloc(sizeof(car) * 30);
	int NumOfString = 0;

	CarFile = fopen("Car.txt", "r");

	if (CarFile == NULL)
	{
		printf("File was not opened!\n");
		return 1;
	}
	int c;
	while (!feof(CarFile)) {
		c = fgetc(CarFile);
		if (c == '\n')
			NumOfString++;
	}
	fseek(CarFile, 0, 0);

	for (int i = 0; i < NumOfString; i++) {
		fscanf(CarFile, "%s%s%d", cars[i].make, cars[i].model, &cars[i].year);
	}

	for (int i = 0; i < NumOfString; i++) {
		for (int j = 1; j < NumOfString; j++) {
			if (cars[j].year < cars[j - 1].year) {
				swap(cars, j - 1, j);
			}
		}
	}

	int sort;
	printf("How are you wont print table:\n1) Desk\n2)Asc");
	scanf("%d", &sort);
	printf("%10s |-| %10s |-| %10s", "Mark", "Model", "Year");
	if (sort == 1) {
		for (int i = 0; i < NumOfString; i++) {
			printf("%10s |-| %10s |-| %10s", cars[i].make, cars[i].model, cars[i].year);
		}
	}
	else {
		for (int i = NumOfString; i > 0; i--) {
			printf("%10s |-| %10s |-| %10s", cars[i].make, cars[i].model, cars[i].year);
		}
	}

	free(cars);

	fclose(CarFile);
	getchar();
	getchar();

	return 0;
}