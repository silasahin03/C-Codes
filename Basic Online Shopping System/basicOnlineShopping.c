#include<stdio.h>
#define LIST_SIZE 10


int main(void)
{
    int whichone;
    int how_many;
    float enter_money;
    float add_money;
    float price;
    float total=0.00;
    float list[LIST_SIZE]={5.00, 7.00, 9.00, 50.00, 25.00, 2.50, 4.20, 1.10, 1.90, 2.30};
    char names[LIST_SIZE][10]={"Apple","Orange", "Tomate","Meat","Chicken","Milk","Yoghurt","Egg","Lemonate","Coke"};
    printf("****************Online Shopping*****************\n");
    printf("1- Apple	5$\n");
    printf("2- Orange	7$\n");
    printf("3- Tomate	9$\n");
    printf("4- Meat   	50$\n");
    printf("5- Chicken	25$\n");
    printf("6- Milk   	2.5$\n");
    printf("7- Yoghurt	4.2$\n");
    printf("8- Egg   	1.1$\n");
    printf("9- Lemonate	1.9$\n");
    printf("10-Coke  	2.3$\n");
    printf("************************************************\n");
    printf("Please enter your choice and quantity(Enter '0' for exit, '-1' for total price): ");
    scanf("%d", &whichone);
    
    while(whichone!=-1 && whichone!=0){
        scanf("%d", &how_many);
        price=list[whichone-1]*how_many; 
        if(whichone==6 || whichone==9 || whichone==10){
            printf("%.2f lt %s: %.2f$\n",(float)how_many, names[whichone-1], (float)price);
        }
        else if(whichone==8){
            printf("%.2f  %s: %.2f$\n",(float)how_many, names[whichone-1], (float)price);
        }
        else{
            printf("%.2f kg %s: %.2f$\n",(float)how_many, names[whichone-1], (float)price);
        }
        total+=price;
        printf("Please enter your choice and quantity(Enter '0' for exit, '-1' for total price): ");
        scanf("%d", &whichone);
    }
    
   
    while(whichone==0){
            char yes_no;
            printf("Are you sure (y/n) : ");
            scanf(" %c",&yes_no);
            
            if(yes_no=='y'){
                printf("Have a good day...\n");
                break;
            }
            if(yes_no=='n'){
                printf("Please enter your choice and quantity(Enter '0' for exit, '-1' for total price): ");
                scanf("%d", &whichone);
                while(whichone!=-1 && whichone!=0){
                    scanf("%d", &how_many);
                    price=list[whichone-1]*how_many; 
                    if(whichone==6 || whichone==9 || whichone==10){
                        printf("%.2f lt %s: %.2f$\n",(float)how_many, names[whichone-1], (float)price);
                    }
                    else if(whichone==8){
                        printf("%.2f  %s: %.2f$\n",(float)how_many, names[whichone-1], (float)price);
                    }
                    else{
                        printf("%.2f kg %s: %.2f$\n",(float)how_many, names[whichone-1], (float)price);
                    }
                    total+=price;
                    printf("Please enter your choice and quantity(Enter '0' for exit, '-1' for total price): ");
                    scanf("%d", &whichone);
                    continue;
                }
            }
    }
    
    if(whichone==-1){
        printf("-1\n");
        printf("Your total price is %.2f$. ",total);
        printf("How much money you enter: ");
        scanf("%f",&enter_money);
        printf("%.2f$\n", enter_money);
        if (enter_money>=total){
            printf("Total price has been paid. Your remaining money %.2f$.\n",enter_money-total);
            printf("Have a good day...\n");
    
        }
        else{
            printf("Your money is not enough. You must add %.2f$ for total price. How much money you enter: ",total-enter_money);
            scanf("%f",&add_money);
            if(total-enter_money>add_money){
                while(total-enter_money>add_money){
                    enter_money+=add_money;
                    printf("Your money is not enough. You must add %.2f$ for total price. How much money you enter: ",total-enter_money);
                    scanf("%f",&add_money);
                }
            }
            printf("Total price has been paid. Your remaining money %.2f$. \n",add_money-(total-enter_money));
            printf("Have a good day...\n");
        }
    }
}
