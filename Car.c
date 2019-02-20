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

			}
		}
	}

	if (fclose(CarFile) == EOF) printf("\n Error \n");


	return 0;
}