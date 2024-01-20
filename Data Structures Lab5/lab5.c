#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
    char data[20];
    int priority;
    struct node* next;
} Node;

Node *newNode(const char val[20], int pri){
    Node* temp = (Node*)malloc(sizeof(Node));
    strcpy(temp-> data, val);
    temp -> priority = pri;
    temp -> next =NULL;
    return temp;
}

void push(Node** head, const char val[20], int pri){

    Node* temp = newNode(val, pri);
    if(*head== NULL || pri <(*head) -> priority || (pri == (*head)->priority && strcmp(val, (*head)->data) < 0)){
        temp -> next = *head;
        *head = temp;
    }
    else{
        Node* start = *head;
        while(start-> next != NULL && (pri > start-> next->priority || (pri == start->next->priority && strcmp(val, start->next->data) > 0))){
            start=start->next;
        }
        temp ->next = start-> next;
        start->next = temp;


    }
}

void display(Node** head){
    Node* temp= *head;
    if(head== NULL){
        return;
    }
    else{
        while (temp != NULL){
            printf("%s\n", temp->data);
            temp=temp->next;
        }
    }
}



int main(){
    char names[20];
    Node* pq = NULL;


    while(strcmp(names,"-1") != 0){
        scanf(" %[^\n]s", names);
        if(strcmp(names,"-1")!=0){
            if(strcmp(names, "Annem")==0 || strcmp(names, "Babam")==0 || strcmp(names,"Kardesim")==0) {
                push(&pq,names,1);
            }
            else if(strcmp(names, "Amcam")==0 || strcmp(names, "Dayim")==0 || strcmp(names, "Halam")==0 || strcmp(names, "Teyzem")==0){
                push(&pq,names,2);
            }
            else if(strcmp(names, "Isyeri")==0 || strcmp(names, "Okul")==0){
                push(&pq,names,3);
            }
            else if(strcmp(names, "Arkadasim1")==0 || strcmp(names, "Arkadasim2")==0||strcmp(names, "Arkadasim3")==0 || strcmp(names, "Arkadasim4")==0||strcmp(names, "Arkadasim5")==0){
                push(&pq,names, 4);
            }
            else if(strcmp(names, "Banka")==0 || strcmp(names, "Kargo")==0){
                push(&pq,names, 5);
            }
            else if (strcmp(names, "Reklam")==0){
                push(&pq,names,6);
            }
            else{
                push(&pq,names, 4);
            }
        }

    }

    display(&pq);

}