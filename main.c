#include <stdio.h>

#define MAX 5

typedef struct Point_struct {
    int x;
    int y;
} Point;

int populate (char filename [30], Point arr5 [MAX]);
void printAPoint (Point arr5 [MAX]);

int main(int argc, char *argv[]) {
    Point arr5[MAX];
    populate(argv[1], arr5);
    printAPoint(arr5);
}

int populate(char filename[30], Point arr5[MAX]) {
    FILE* inputFile;
    inputFile = fopen(filename, "r");
    
    if(inputFile == NULL) {
        return 0;
    }

    char temp[30];
    int i = 0;
    while (!feof(inputFile)) {
        fgets(temp, 30, inputFile);
        sscanf(temp, "%d %d", &arr5[i].x, &arr5[i].y);
        i++;
    }

    fclose(inputFile);
    return 1;
}

void printAPoint (Point arr5 [MAX]) {
    for(int i = 0; i < MAX; i++) {
        printf("Point %d:\n", i+1);
        printf("X-Coordinate = %d\n", arr5[i].x);
        printf("Y-Coordinate = %d\n\n", arr5[i].y);
    }
}