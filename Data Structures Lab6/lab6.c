#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    int student_id;
    struct node* left;
    struct node* right;
    struct node* prev;
};

struct node* createNode(int student_id , int grade){
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = grade;
    newNode->student_id=student_id;
    newNode->left = newNode->right = newNode-> prev= NULL;
    return newNode;
}


struct node* insertNode(struct node* root, int student_id, int grade, struct node* parent){
    if(root == NULL){
        struct node* newNode = createNode(student_id, grade);
        newNode->prev= parent;
        return newNode;
    }
    if(grade < root->data){
        root->left= insertNode(root->left,student_id, grade,root);
    }
    else if(grade > root->data){
        root->right= insertNode(root->right,student_id, grade,root);
    }
    return root;
}

void treeSorted(struct node* root) {
    if (root != NULL) {
        treeSorted(root->left);
        printf("%d %d\n",root->student_id, root->data);
        treeSorted(root->right);

    }
}

int treeHeight(struct node* node){
    if (node == NULL)
        return 0;
    else {
        int left_height = treeHeight(node->left);
        int right_height = treeHeight(node->right);

        if (left_height > right_height)
            return (left_height + 1);
        else
            return (right_height + 1);
    }
}

void currentLevel(struct node* root, int level){
    if (root == NULL)
        return;
    if (level == 0){
        printf("%d %d", root->student_id, root->data);
        if (root->prev != NULL) {
            printf(" (%d ", root->prev->data);
            if (root == root->prev->left) {
                printf("L) ");
            } else {
                printf("R) ");
            }
        }
    }
    else {
        currentLevel(root->left, level - 1);
        currentLevel(root->right, level - 1);
    }
}

void printLevels(struct node* root){
    int height = treeHeight(root);
    for(int i = 0; i <= height; i++){
        currentLevel(root, i);
        if(i < height){
            printf("\n");
        }
    }
}


int main()
{
    struct node* root= NULL;
    int student_id;
    int grade;
    while (1) {
        scanf("%d", &student_id);

        if (student_id == -1){
            break;
        }
        scanf("%d", &grade);
        root= insertNode(root,student_id, grade, NULL);
    }
    treeSorted(root);
    printf("\n");
    printLevels(root);

}