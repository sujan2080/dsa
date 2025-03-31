#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* left;
    struct node* right;
};
struct node* root = NULL;

struct node* createnode(int data)
{
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

struct node* insert(struct node* root, int data)
{
    if(root==NULL)
    {
        return createnode(data);
    }
    if(data < root->data)
    {
        root->left = insert(root->left, data);
    }
    else if(data > root->data)
    {
        root->right = insert(root->right, data);
    }
    return root;
}

struct node* search(struct node* root, int key)
{
    if(root == NULL || root->data == key)
    {
       return root;
    }

    if(key < root->data)
    {
       return search(root->left, key);
    }
    else
    {
       return search(root->right, key);
    }

}


void inorder_traversal(struct node* root)
{
    if(root != NULL)
    {
        inorder_traversal(root->left);
        printf("%d  ", root->data);
        inorder_traversal(root->right);
    }
}

void preorder_traversal(struct node* root)
{
   if(root != NULL)
    {
        printf("%d  ", root->data);
        preorder_traversal(root->left);
        preorder_traversal(root->right);
    }
}

void postorder_traversal(struct node* root)
{
    if(root != NULL)
    {
        postorder_traversal(root->left);
        postorder_traversal(root->right);
        printf("%d  ", root->data);
    }
}

int main()
{
    int choice, data;
    struct node* found;

    while(1)
    {
        printf("\nMENU\n");
        printf("1. Insert\n");
        printf("2. Search\n");
        printf("3. Display in-order traversal\n");
        printf("4. Display pre-order traversal\n");
        printf("5. Display post-order traversal\n");
        printf("6. Exit\n");

        printf("Enter the choice:");
        scanf("%d", &choice);
        switch(choice)
        {
        case 1:
            printf("Enter the data to insert:");
            scanf("%d",&data);
            root = insert(root, data);
            break;

        case 2:
            printf("Enter the data to search:");
            scanf("%d", &data);
            found = search(root, data);
            if(found != NULL)
            {
                printf("Element %d found in the BST.\n", data);
            }

            else
            {
               printf("Element %d not found in the BST.\n", data);
            }


            break;

        case 3:
            printf("In-order traversal: ");
            inorder_traversal(root);
            printf("\n");
            break;

        case 4:
            printf("Pre-order traversal: ");
            preorder_traversal(root);
            printf("\n");
            break;

        case 5:
            printf("Post-order traversal: ");
            postorder_traversal(root);
            printf("\n");
            break;

        case 6:
            printf("Exiting program\n");
            exit(0);

        default:
            printf("Wrong choice\n");
            break;
        }
    }
}
