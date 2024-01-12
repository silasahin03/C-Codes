#include<stdio.h>
#define DIGIT10_SIZE 13
#define DIGIT13_SIZE 17

int main(void)
{
    int number_of_digits;
    char possibleISBN;
    scanf("%d\n", &number_of_digits);
    int sum=0;

    if (number_of_digits==10){
        char digit10[DIGIT10_SIZE] = {0};
        for (int i=0; i<DIGIT10_SIZE; ++i){
            scanf("%c", &possibleISBN);
            digit10[i]=possibleISBN;
            
        }
        int first=digit10[0]-'0';
        int second=digit10[2]-'0';
        int third=digit10[3]-'0';
        int fourth=digit10[4]-'0';
        int fifth=digit10[6]-'0';
        int sixth=digit10[7]-'0';
        int seventh=digit10[8]-'0';
        int eighth=digit10[9]-'0';
        int ninth=digit10[10]-'0';
        int tenth=digit10[12]-'0';
        
        sum = first*10+second*9+third*8+fourth*7+fifth*6+sixth*5+seventh*4+eighth*3+ninth*2+tenth;
        if (sum %11==0){
            printf("The sum is %d. This is ISBN\n", sum);

        }
        else{
            printf("The sum is %d. This is not ISBN\n", sum);
        }
    }


    if (number_of_digits==13){
        char digit10[DIGIT13_SIZE] = {0};
        for (int i=0; i<DIGIT13_SIZE; ++i){
            scanf("%c", &possibleISBN);
            digit10[i]=possibleISBN;
            
        }
        int first=digit10[0]-'0';
        int second=digit10[1]-'0';
        int third=digit10[2]-'0';
        int fourth=digit10[4]-'0';
        int fifth=digit10[6]-'0';
        int sixth=digit10[7]-'0';
        int seventh=digit10[8]-'0';
        int eighth=digit10[10]-'0';
        int ninth=digit10[11]-'0';
        int tenth=digit10[12]-'0';
        int eleventh=digit10[13]-'0';
        int twelveth=digit10[14]-'0';
        int thirteenth=digit10[16]-'0';
        
        sum = first+second*3+third+fourth*3+fifth+sixth*3+seventh+eighth*3+ninth+tenth*3+eleventh+twelveth*3+thirteenth;
        if (sum %10==0){
            printf("The sum is %d. This is ISBN\n", sum);

        }
        else{
            printf("The sum is %d. This is not ISBN\n", sum);
        }
    }
}