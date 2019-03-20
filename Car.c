#include <stdio.h> 
#include <string.h>
#include <stdlib.h>
#include <string.h>

typedef struct car {
	char make[30];
	char model[30];
	int year;
	int power;
	int carNumber;
} car;

void swap(car* cars, int i, int j);
int tableOutputSettings(car* cars, int numOfString);

int main(void) {

	FILE *carFile = fopen("Car.txt", "r");
	FILE *orderedData = fopen("OrderedDate.txt", "w");
	car* cars = (car*)malloc(sizeof(car) * 30);
	int numOfString = 0;

	if (carFile == NULL || orderedData == NULL)
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
	
	int sort = tableOutputSettings(cars, numOfString);
	
	fprintf(orderedData,"|-|%-15s|-|%-15s|-|%-15s|-|%-15s|-|%-15s|-|\n\n", "Mark", "Model", "Year", "Power", "Car num");
	if (sort == 1) {
		for (int i = 0; i < numOfString; i++) {
			fprintf(orderedData,"|-|%-15s|-|%-15s|-|%-15d|-|%-15d|-|%-15d|-|\n", cars[i].make, cars[i].model, cars[i].year, cars[i].power, cars[i].carNumber);
		}
	}
	else {
		for (int i = numOfString - 1; i >= 0; i--) {
			fprintf(orderedData,"|-|%-15s|-|%-15s|-|%-15d|-|%-15d|-|%-15d|-|\n", cars[i].make, cars[i].model, cars[i].year, cars[i].power, cars[i].carNumber);
		}
	}

	free(cars);

	fclose(orderedData);
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
	temp.power = cars[i].power;
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

int tableOutputSettings(car *cars, int numOfString) {

	int criteria;

	printf("\n1)Year;\n2)Power;\n3)Name;\nEnter by what criteria to sort: ");
	scanf("%d", &criteria);
	
	int sort;
	printf("How are you want print table:\n1) Desk\n2) Asc\nNum: ");
	scanf("%d", &sort);

	if (criteria == 1) {
		for (int i = 0; i < numOfString; i++) {
			for (int j = 1; j < numOfString; j++) {
				if (cars[j].year < cars[j - 1].year) {
					swap(cars, j - 1, j);
				}
			}
		}
	}
	else if (criteria == 2) {
		for (int i = 1; i < numOfString; i++) {
			for (int j = 1; j < numOfString; j++) {
				if (cars[j].power < cars[j - 1].power) {
					swap(cars, j - 1, j);
				}
			}
		}
	}

	else if (criteria == 3) {
		for (int i = 1; i < numOfString; i++) {
			for (int j = 1; j < numOfString; j++) {
				if (strcmp(cars[j - 1].make, cars[j].make) > 0) {
					swap(cars, j - 1, j);
				}
			}
		}
	}

	return sort;
}
