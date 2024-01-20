#include <stdio.h>
#include <string.h>
#include <stdlib.h>


struct Node {
    char html_tags[20];
    struct Node* next;
};

struct Stack {
    struct Node* top;
};


struct Stack* createStack() {
    struct Stack* stack;
    stack=(struct Stack*)malloc(sizeof(struct Stack));
    if (stack == NULL) {
        return NULL;
    }
    stack->top = NULL;
    return stack;
}

int empty_stack(struct Stack* stack) {
    return (stack->top == NULL);
}

void push(struct Stack* stack, const char tag[]) {
    struct Node *ptr;
    ptr = (struct Node*)malloc(sizeof(struct Node));
    if (ptr == NULL) {
        ptr -> next = NULL;
    }
    strcpy(ptr->html_tags, tag);
    ptr->next = stack->top;
    stack->top = ptr;
}

char* pop(struct Stack* stack) {
    if (empty_stack(stack)) {
        return NULL;
    }
    struct Node* temp = stack->top;
    char* data = (char*)malloc(strlen(temp->html_tags));
    if (data == NULL) {
        return NULL;
    }
    strcpy(data, temp->html_tags);
    stack->top = temp->next;
    free(temp);
    return data;
}


char* peek(struct Stack* stack) {
    if (empty_stack(stack)) {
        return NULL;
    }
    return stack->top->html_tags;
}

int main() {
    struct Stack* stack=createStack();
    char html_code[500];

    scanf(" %[^\n]s", html_code);

    int i=0;
    while (html_code[i] != '\n' && html_code[i] != '\0') {
        if (html_code[i] == '<'){
            i++;
            if (html_code[i] == '/'){
                i++;
                char tag[20];
                int j=0;
                while (html_code[i] != '>' && html_code[i] != '\0'){
                    tag[j] = html_code[i];
                    i++;
                    j++;
                }
                tag[j] = '\0';

                if (peek(stack) != NULL && strcmp(peek(stack), tag) != 0) {
                    printf("error <%s>\n", peek(stack));
                    pop(stack);
                    break;
                }else {
                    pop(stack);
                }
                i++;
                
            }else{
                int k = 0;
                char tagToPush[20];
                while (html_code[i] != '>' && html_code[i] != '\0'){
                    tagToPush[k] = html_code[i];
                    i++;
                    k++;
                }
                tagToPush[k] = '\0';
                push(stack, tagToPush);
                i++;
            }
        } else{
            i++;
        }
    }

    if (empty_stack(stack)){
        printf("correct\n");
    }

}
