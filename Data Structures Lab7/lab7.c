#include <stdio.h>
#include <stdlib.h>


struct node {
    int data;
    struct node* left;
    struct node* right;
    struct node* parent;
    int height;
};

struct node* createNode(int value, struct node* parent){
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    newNode-> parent=parent;
    newNode->height=1;
    return newNode;
}

int height(struct node *N)
{
    if (N == NULL)
        return 0;
    return N->height;
}

int getBalance(struct node *N)
{
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}

void updateHeight(struct node* root) {
    if (root != NULL) {
        int val = 1;
        if (root->left != NULL)
            val = root->left->height + 1;
        if (root->right != NULL)
            val = (val > root->right->height + 1) ? val : root->right->height + 1;
        root->height = val;
    }
}

struct node* LLR(struct node* root) {
    struct node* tmpNode = root->left;
    root->left = tmpNode->right;
    if (tmpNode->right != NULL)
        tmpNode->right->parent = root;
    tmpNode->right = root;
    tmpNode->parent = root->parent;
    root->parent = tmpNode;
    if (tmpNode->parent != NULL && root->data < tmpNode->parent->data) {
        tmpNode->parent->left = tmpNode;
    } else {
        if (tmpNode->parent != NULL)
            tmpNode->parent->right = tmpNode;
    }
    root = tmpNode;
    updateHeight(root->left);
    updateHeight(root->right);
    updateHeight(root);
    updateHeight(root->parent);
    return root;
}

struct node* RRR(struct node* root) {
    struct node* tmpNode = root->right;
    root->right = tmpNode->left;
    if (tmpNode->left != NULL)
        tmpNode->left->parent = root;
    tmpNode->left = root;
    tmpNode->parent = root->parent;
    root->parent = tmpNode;
    if (tmpNode->parent != NULL && root->data < tmpNode->parent->data) {
        tmpNode->parent->left = tmpNode;
    } else {
        if (tmpNode->parent != NULL)
            tmpNode->parent->right = tmpNode;
    }
    root = tmpNode;
    updateHeight(root->left);
    updateHeight(root->right);
    updateHeight(root);
    updateHeight(root->parent);
    return root;
}

struct node* LRR(struct node* root) {
    root->left = RRR(root->left);
    return LLR(root);
}

struct node* RLR(struct node* root) {
    root->right = LLR(root->right);
    return RRR(root);
}


struct node* insertNode(struct node* root, struct node* parent, int value) {
    if (root == NULL) {
        return createNode(value, parent);
    } else if (root->data > value) {
        root->left = insertNode(root->left, root, value);
        int first_height = 0;
        int second_height = 0;
        if (root->left != NULL)
            first_height = root->left->height;
        if (root->right != NULL)
            second_height = root->right->height;
        if (abs(first_height - second_height) == 2) {
            if (root->left != NULL && value < root->left->data) {
                root = LLR(root);
            } else {
                root = LRR(root);
            }
        }
    } else if (root->data < value) {
        root->right = insertNode(root->right, root, value);
        int first_height = 0;
        int second_height = 0;
        if (root->left != NULL)
            first_height = root->left->height;
        if (root->right != NULL)
            second_height = root->right->height;
        if (abs(first_height - second_height) == 2) {
            if (root->right != NULL && value < root->right->data) {
                root = RLR(root);
            } else {
                root = RRR(root);
            }
        }
    }
    updateHeight(root);
    return root;
}

void treeSorted(struct node* root) {
    if (root != NULL) {
        treeSorted(root->left);
        printf("%d \n", root->data);
        treeSorted(root->right);
    }
}

void currentLevel(struct node* root, int level){
    if (root == NULL)
        return;
    if (level == 0){
        printf("%d", root->data);
        if (root->parent != NULL) {
            printf(" (%d ", root->parent->data);
            if (root == root->parent->left) {
                printf("L)");
            } else {
                printf("R)");
            }
        }
        printf(" (%d B) ", getBalance(root));
    }
    else {
        currentLevel(root->left, level - 1);
        currentLevel(root->right, level - 1);
    }
}

void printLevels(struct node* root){
    int height = root->height;
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
    int value;
    while (1) {
        scanf("%d", &value);
        if (value == -1){
            break;
        }
        root= insertNode(root, NULL, value);
    }
    treeSorted(root);
    printf("\n");
    printLevels(root);

}
