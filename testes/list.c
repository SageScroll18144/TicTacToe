#include <stdio.h>
#include <stdlib.h>

int main(){

    int *list = (int *) malloc(sizeof(int));
    int tam = 1;
    list[0] = 89;
    printf("%d\n", list[0]);

    list = (int *) realloc(list, (tam-1) * sizeof(int));
    //printf("%d\n", list[0]);
    free(list);
    return 0;
}