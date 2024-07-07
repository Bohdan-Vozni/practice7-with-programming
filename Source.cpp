#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int main() {
	char coordinates[20];
	printf("Input circle coordinates (x1 y1 r1 x2 y2 r2): ");
	fgets(coordinates, sizeof(coordinates), stdin);



	char* next_token;
	char* token = strtok_s(coordinates, " ", &next_token);
	int count = 0;
	float tokstring[7];
	while (token != NULL) {
		tokstring[count] = atof(token);
		//printf("\ntoken %s", token);
		token = strtok_s(NULL, " ", &next_token);
		count++;

		if (count > 6) {
			printf("Erorr");
			return 13;
		}
	}
	float distance = sqrt(pow(tokstring[3] - tokstring[0], 2) + pow(tokstring[4] - tokstring[1], 2));
	//printf("\ndistance: %f", distance);

	if (distance == 0 && tokstring[2] == tokstring[5]) {
		printf("\nThe number of crossing points -1");
	}
	else if (distance == tokstring[2] + tokstring[5]) {
		printf("\nThe number of crossing points 1");
	}
	else if (distance > tokstring[2] + tokstring[5]) {
		printf("\nThe number of crossing points 0");
	}
	else {
		printf("\nThe number of crossing points 2");
	}

/*
	for (int i = 0; i < count; i++) {
		printf("\nArray: %.2f", tokstring[i]);
	}*/

	return 0;
}
