#include <stdio.h>
#define SIZE 100

int main(void) 
{
    int row;
    int column;
    scanf("%d",&row);
    scanf("%d",&column);
    char myarray[row][column];
    char value;
    for (int i=0; i<row; i++){
        for (int j=0; j<column; j++){
            scanf(" %c",&value);
            myarray[i][j]=value;
        }
    }

    for (int i=0; i<row; i++){
        for (int j=0; j<column; j++){
            printf("%c", myarray[i][j]);
        }
        printf("\n");
    }

    printf("\n");

    int current_row;
    int current_column;
    scanf("%d",&current_row);
    scanf("%d",&current_column);

    char commands[SIZE];
    int total=0;
    char operator='+';
    scanf("%s", commands);
    for (int i=0; commands[i] != ' '; i++) {
        switch (commands[i]){
            case 'd':
                current_row+=1;
                break;
            case 'u':
                current_row-=1;
                break;
            case 'r':
                current_column+=1;
                break;
            case 'l':
                current_column-=1;
                break;
            case 'q':
                printf("command:%c\n",commands[i]);
                printf("Game is over. Your score is %d!\n", total);
                return 0;
        }

        char next_value;
        next_value=myarray[current_row][current_column];
        if (next_value>='0' && next_value<='9'){
            int number;
            number=next_value-'0';
            printf("command:%c\n",commands[i]);
            printf("%d %c %d = ",total, operator, number);
            switch (operator){
                case '+':
                    total+=number;
                    break;
                case '-':
                    total-=number;
                    break;
                case '*':
                    total*=number;
                    break;
            }
            printf("%d\n",total);
        } 
        else if (next_value=='+' || next_value=='-' || next_value=='*'){
            operator=next_value;
            printf("command:%c\n",commands[i]);
            printf("Operator changed to %c\n", operator);
        } 
        else if (next_value=='['){
            int number=0;
            current_column++;
            while(myarray[current_row][current_column] != ']'){
                number=number*10 + myarray[current_row][current_column]-'0';
                current_column++;
            }
            printf("command:%c\n", commands[i]);
            printf("%d %c %d = ", total,operator,number);
            switch (operator){
                case '+':
                    total+=number;
                    break;
                case '-':
                    total-=number;
                    break;
                case '*':
                    total*=number;
                    break;
            }
            printf("%d\n",total);
        }
        else if(next_value == ']'){
            int number=0;
            current_column--;
            while(myarray[current_row][current_column] != '[') {
                number=number*10 + myarray[current_row][current_column]-'0';
                current_column--;
            }
            printf("command:%c\n",commands[i]);
            printf("%d %c %d = ",total, operator, number);
            switch(operator){
                case '+':
                    total+=number;
                    break;
                case '-':
                    total-=number;
                    break;
                case '*':
                    total*=number;
                    break;
            }
            printf("%d\n",total);
        }
    }
}