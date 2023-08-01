#include <stdio.h>

int main(void){
    int i, j;
    
    printf("This is a test file of Cworkspcae.\n");
    printf("Plz input any numbers : ");
    scanf("%d", &i);
    printf("Plz input any numbers : ");
    scanf("%d", &j);

    int sum = i + j;

    printf("You input %d and %d.\n", i, j);
    printf("And their sum is %d.\n", sum);

    return 0;
}