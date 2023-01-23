#include <stdio.h>
#include <stdlib.h>

int main(){

    int *list[10];

    for(int i=0;i<10;i++) list[i] = NULL;
    
    for(int i=0;i<10;i++) free(list[i]);
    return 0;
}