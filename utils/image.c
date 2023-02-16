#include "image.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXCHAR 10000

Image** csv_to_images(char* file_string, int image_num) {
	FILE *fp;
	Image** images = malloc(image_num * sizeof(Image*));
	char row[MAXCHAR];
	fp = fopen(file_string, "r");

	// Read the first line 
	fgets(row, MAXCHAR, fp);
	int i = 0;
	while (feof(fp) != 1 && i < image_num) {
		images[i] = malloc(sizeof(Image));

		int j = 0;
		fgets(row, MAXCHAR, fp);
		char* token = strtok(row, ",");
		images[i]->image_data = matrix_create(28, 28);
		while (token != NULL) {
			if (j == 0) {
				images[i]->label = atoi(token);
			} else {
				images[i]->image_data->entries[(j-1) / 28][(j-1) % 28] = atoi(token) / 256.0;
			}
			token = strtok(NULL, ",");
			j++;
		}
		i++;
	}
	fclose(fp);
	return images;
}

void image_print(Image* image) {
	matrix_print(image->image_data);
	printf("Image Label: %d\n", image->label);
}

void image_free(Image* image) {
	matrix_free(image->image_data);
	free(image);
	image = NULL;
}

void images_free(Image** images, int n) {
	for (int i = 0; i < n; i++) {
		image_free(images[i]);
	}
	free(images);
	images = NULL;
}