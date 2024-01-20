#include<stdio.h>
#include<math.h>
#define DIGITS_OF_GIVEN_NUMBERS

int main(void)
{
    char n;
    unsigned int p;
    int k;
    scanf("%d", &n);
    scanf("%d", &p);
    k = interesting_number(n,p);
    printf("%d",k);
}

int interesting_number(int n, unsigned int p)
{
   char digits_of_given_numbers[]={0};
   int i=0;
   int new_number;
   new_number=n;
   if (new_number != 0){
    digits_of_given_numbers[i]= new_number %10;
    new_number= new_number/10;
    i++;
   }
   int sum=0;
   int power=i+p;
    for (int j=0; j<=i, p<=power ; j++){
        sum+= pow(digits_of_given_numbers[j],power);
        power-=power;
    }
    int k=0;
   if (sum%n==0){
    k=sum/n;
   }
   else{
    k=-1;
   }
   
   return k;
}
