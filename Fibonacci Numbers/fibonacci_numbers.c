#include <stdio.h>
int main(void)
{
    int nth_number;
    printf("Fibonacci numbers\n");
    printf("Please enter a number:\n");
    scanf("%d", &nth_number);
    if (nth_number==0){
        printf("Error");
    }
    else{
        int i, j, t1=0, t2=1, fibo;
        for (i=1; i<=nth_number; ++i){
            for (j=1; j<=i; ++j){
                printf("*");
            }
            printf("%d\n", t1);
            fibo= t1+t2;
            t1=t2;
            t2=fibo;
        }
        printf("%d. element is %d\n", nth_number, t2-t1);
        
    }
}