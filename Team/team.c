#include <stdio.h>
int main(void)
{
    int petya, vasya, tonya, numberOfProblems;
    int numberOfImplementedProblems = 0;
    scanf("%d\n", &numberOfProblems);
    for(int i=0; i < numberOfProblems; ++i){
        scanf("%d %d %d", &petya, &vasya, &tonya);
        int total;
        if((petya == 0 || petya == 1) && (vasya == 0 || vasya == 1) && (tonya == 0 || tonya == 1)){
            total = petya + vasya + tonya;
            if(total >= 2 && total <= 3){
            numberOfImplementedProblems++;
            }
        }
        else {
            printf("Values must be 1 or 0!\n");
            scanf("%d %d %d", &petya, &vasya, &tonya);
            while(((petya != 0 && petya != 1) || (vasya != 0 && vasya != 1) || (tonya != 0 && tonya != 1))){
                printf("Values must be 1 or 0!\n");
                scanf("%d %d %d", &petya, &vasya, &tonya);
            }
            total = petya + vasya + tonya;
            if(total >= 2 && total <= 3){
            numberOfImplementedProblems++;
            }
        }
        total = 0;    
    }
    printf("%d", numberOfImplementedProblems);
}
