#include <stdio.h> 
struct car {
	char make;
	char model;
	int year;
};
int main(void) {
	FILE *CarFile;
	struct car information[30];
	int NumOfString = 0;

	CarFile = fopen("Car.txt", "r");

	while (!feof(CarFile)) {
		if (fgetc(CarFile) == '\n')
			NumOfString++;
	}
	NumOfString++;
	if (fclose(CarFile) == EOF) printf("\n Error \n");

	CarFile = fopen("Car.txt", "r");

	for (int i = 0; i < NumOfString; i++) {
		fscanf(CarFile,"%s%s%d", information->make, information->model, information->year)
	}

	for (int i = 0; i < NumOfString; i++) {
		struct car temp;
		for (int j = 1; j < NumOfString; j++) {
			if (information[j].year < information[j - 1].year) {
				temp.make = information[j].make;
				temp.model = information[j].model;
				temp.year = information[j].model;

				information[j].make = information[j - 1].make;
				information[j].model = information[j - 1].model;
				information[j].year = information[j - 1].year;

				information[j - 1].make = temp.make;
				information[j - 1].model = temp.model;
				information[j - 1].year = temp.year;
			}
		}
	}

	if (fclose(CarFile) == EOF) printf("\n Error \n");


	return 0;
}