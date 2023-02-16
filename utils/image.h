#pragma once
#include "../matirx/matrix.h"

typedef struct {
    Matrix* image_data;
    int label;
} Image;

Image** csv_to_images(char* file_string, int image_num);
void image_print(Image* image);
void image_free(Image* image);
void images_free(Image** images, int n);