#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <algorithm>

using namespace std;

void writePPMImage(int* data, int width, int height, const char *filename, int maxIterations)
{
    FILE *fp = fopen(filename, "wb");

    // write ppm header
    fprintf(fp, "P6\n");
    fprintf(fp, "%d %d\n", width, height);
    fprintf(fp, "255\n");

    for (int i = 0; i < width*height; ++i) {
        float mapped = pow( std::min(static_cast<float>(maxIterations), static_cast<float>(data[i])) / 256.f, .5f);
        unsigned char result = static_cast<unsigned char>(255.f * mapped);
        for (int j = 0; j < 3; ++j)
            fputc(result, fp);
    }
    fclose(fp);
    printf("Wrote image file %s\n", filename);
}

int main() {
    //size of image generated
    int width = 1450;
    int height = 1000;

    //probability of elements
    int a[] = {1, 2, 3, 4, 5, 6};
    // There is an extreme situation
    // int a[] = {
    //     1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,    //#'1' = 40
    //     1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,    //#'1' = 40
    //     1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,    //#'1' = 40
    //     2,3,4,5,6,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,                          //#'1' = 15
    // };

    int count = sizeof(a)/sizeof(int);
    
    int* sumArr = new int[width];
    int* output = new int[width*height];

    //height*30 is the number of samples, there is 1000*30= 30000
    for (int i=0; i<height*30; i++) {
        int temp = a[random()%count];
        //how many times added
        for (int j=0; j<100; j++) {
            temp = temp + a[random()%count];
        }
        sumArr[temp] = sumArr[temp]+1;
    }
    
    for (int i=0; i<width; i++) {
        // sumArr[i]/2 to scale image
        for (int j=height-1; j>=height-sumArr[i]; j--) {
            //Widening images
            for (int k=0; k<10; k++) {
                output[j*width+i*10+k]=256;
            }
        }
    }

    writePPMImage(output, width, height, "output-image.ppm", 256);

    delete[] sumArr;
    delete[] output;
    return 0;
}


