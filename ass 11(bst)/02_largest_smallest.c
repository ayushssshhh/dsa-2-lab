#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};

struct node* root = NULL;

void create_tree(){
    int n;
    printf("\nenter no. of node to create : ");
    scanf("%d",&n);

    for(int i=0; i<n ; i++){
        struct node *ptr = root, *newnode = (struct node*)malloc(sizeof(struct node));
        printf("enter node value : ");
        scanf("%d",&newnode->data);
        newnode->left = NULL;
        newnode->right = NULL;

        if(root == NULL){
            root = newnode;
        }

        else{
            while(ptr != NULL){
                if(newnode->data > ptr->data){
                    if(ptr->right == NULL){
                        ptr->right = newnode;
                        break;
                    }

                    else
                    ptr = ptr->right;
                }

                else{
                    if(ptr->left == NULL){
                        ptr->left = newnode;
                        break; 
                    }

                    else
                    ptr = ptr->left;
                }
            }
        }
    }
}

void smallest(struct node* ptr){
    if(ptr->left != NULL)
    smallest(ptr->left);

    else
    printf("\nthe node with smallest value : %d",ptr->data);
}

void largest(struct node *ptr){
    if(ptr->right != NULL)
    largest(ptr->right);

    else
    printf("\nthe node with largest vale is : %d",ptr->data);
}

void inorder(struct node* ptr){
    if(ptr != NULL){
        inorder(ptr->left);
        printf(" %d",ptr->data);
        inorder(ptr->right);
    }
}

void preorder(struct node* ptr){
    if(ptr != NULL){
        printf("%d ",ptr->data);
        preorder(ptr->left);
        preorder(ptr->right);
    }
}

void postorder(struct node* ptr){
    if(ptr != NULL){
        postorder(ptr->left);
        postorder(ptr->right);
        printf(" %d",ptr->data);
    }
}

int main(){

    char ch;
    int n;

    do
    {
        printf("\n\n------------BINARY SEARCH TREE OPPERATION-----------------\n\n1 to create tree\n2 to trverse inorder\n3 to traverse preorder\n4 to traverse postorder\n5 print the node with smallest value :\n6 to print node with largest value:\nenter choice : ");
        scanf("%d",&n);

        switch (n)
        {
            case 1 :
                create_tree();
                break;

            case 2 :
                printf("\ntree in inorder :");
                inorder(root);
                break;

            case 3 :
                printf("\ntree in preorder :");
                preorder(root);
                break;

            case 4 :
                printf("\ntree in postorder :");
                postorder(root);
                break;
            
            case 5 :
                smallest(root);
                break;

            case 6 :
                largest(root);
                break;

            default :
                printf("\nenter a valid option : ");
                break;
        }

        printf("\n\nDO YOU WANT TO CONTINUE?!\nenter choice : ");
        scanf(" %c",&ch);

    } while ((ch == 'y') || (ch == 'Y'));
    
    
}

// 1 11 15 30 17 5 8 4 40 9 32 50 3 y 2 y 3 y 4 y 5 y 6