#include <stdio.h>
#include <math.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

int main(){

    FILE *fptr;
    fptr = fopen("Random.txt", "w");
    srand(time(NULL));
    int random;
    for(int i=1; i<=100000; i++){
        random = rand()%100000 + 1;
        fprintf(fptr, "%d ", random);
    }
    fclose(fptr);

    return 0;

}
