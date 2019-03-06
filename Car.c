#include <stdio.h> 
#include <string.h>

typedef struct car {
	char make[30];
	char model[30];
	int year;
	int power;
	int carNumber;
} car;

void swap(car* cars, int i, int j);


int main(void) {

	FILE *carFile;
	car* cars = (car*)malloc(sizeof(car) * 30);
	int numOfString = 0;

	carFile = fopen("Car.txt", "r");

	if (carFile == NULL)
	{
		printf("File was not opened!\n");
		return 1;
	}
	
	int c;
	while (!feof(carFile)) {
		c = fgetc(carFile);
		if (c == '\n')
			numOfString++;
	}
	fseek(carFile, 0, 0);

	for (int i = 0; i < numOfString; i++) {
		fscanf(carFile, "%s%s%d%d%d", cars[i].make, cars[i].model, &cars[i].year, &cars[i].power, &cars[i].carNumber);
	}

	int criteria;

	printf("\n1)Year;\n2)Power;\n3)Name;\nEnter by what criteria to sort: ");
	scanf("%d", &criteria);
	
	int sort;
	printf("How are you want print table:\n1) Desk\n2) Asc\nNum: ");
	scanf("%d", &sort);
	
	printf("|-|%-15s|-|%-15s|-|%-15s|-|%-15s|-|%-15s|-|\n\n", "Mark", "Model", "Year", "Power", "Car num");

	if (criteria == 1) {
		for (int i = 0; i < numOfString; i++) {
			for (int j = 1; j < numOfString; j++) {
				if (cars[j].year < cars[j - 1].year) {
					swap(cars, j - 1, j);
				}
			}
		}
	}
	if (criteria == 2) {
		for (int i = 0; i < numOfString; i++) {
			for (int j = 1; j < numOfString; j++) {
				if (cars[j].power < cars[j - 1].power) {
					swap(cars, j - 1, j);
				}
			}
		}
	}
	
	if (sort == 1) {
		for (int i = 0; i < numOfString; i++) {
			printf("|-|%-15s|-|%-15s|-|%-15d|-|%-15d|-|%-15d|-|\n", cars[i].make, cars[i].model, cars[i].year, cars[i].power, cars[i].carNumber);
		}
	}
	else {
		for (int i = numOfString - 1; i > 0; i--) {
			printf("|-|%-15s|-|%-15s|-|%-15d|-|%-15d|-|%-15d|-|\n", cars[i].make, cars[i].model, cars[i].year, cars[i].power, cars[i].carNumber);
		}
	}

	free(cars);

	fclose(carFile);

	getchar();
	getchar();

	return 0;
}

void swap(car* cars, int i, int j)
{
	car temp;

	strcpy(temp.make, cars[i].make);
	strcpy(temp.model, cars[i].model);
	temp.power = cars[i].year;
	temp.year = cars[i].year;
	temp.carNumber = cars[i].carNumber;

	strcpy(cars[i].make, cars[j].make);
	strcpy(cars[i].model, cars[j].model);
	cars[i].power = cars[j].power;
	cars[i].year = cars[j].year;
	cars[i].carNumber = cars[j].carNumber;

	strcpy(cars[j].make, temp.make);
	strcpy(cars[j].model, temp.model);
	cars[j].power = temp.power;
	cars[j].year = temp.year;
	cars[j].carNumber = temp.carNumber;
}
