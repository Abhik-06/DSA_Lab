#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct node{
    char word[50];
    char meaning[50];
    struct node* left;
    struct node* right;
};

int Choice(int choice);
struct node* CreatePair(struct node* root,char newword[50],char newmeaning[50]);
void LookupMeaning(struct node* root,char tempword[50]);
void LookupWord(struct node* root, char tempmeaning[50]);
void DisplayElements(struct node* root);
struct node* DeletePair(struct node* root,char word[50]);
struct node* findInorderPredecessor(struct node* root);


int main(){
    struct node* root = NULL;
    int choice = 1;

    while(choice==1){
        printf("Enter your choice\n");
        printf("1 for entering a word-meaning pair\n");
        printf("2 for looking up a word\n");
        printf("3 for looking up a meaning\n");
        printf("4 for displaying all the word-meaning pairs lexicographically\n");
        printf("5 for deleting a node\n");
        printf("Choice : ");
        scanf("%d",&choice);
        while(getchar()!='\n');

        if(choice==1){
            char tempword[50];
            char tempmeaning[50];

            printf("\nEnter the word : ");
            fgets(tempword,50,stdin);
            printf("\nEnter the meaning : ");
            fgets(tempmeaning,50,stdin);

            root = CreatePair(root,tempword,tempmeaning);
            printf("\nDone 1\n");
        }
        else if(choice==2){
            char word[50];

            printf("\nEnter the word,whose meaning you wish to lookup : ");
            fgets(word,50,stdin);

            LookupWord(root,word);
            printf("\nDone !\n");
        }
        else if(choice==3){
            char meaning[50];

            printf("\nEnter the word,whose meaning you wish to lookup : ");
            fgets(meaning,50,stdin);

            LookupMeaning(root,meaning);
            printf("\nDone !\n");
        }
        else if(choice==4){
            DisplayElements(root);
        }
        else if(choice==5){
            char temp[50];
            printf("\nEnter the word,of the pair, which you wish to delete : ");
            fgets(temp,50,stdin);

            root = DeletePair(root,temp);
            printf("\nDone !\n");
        }
        else{
            printf("\nInvalid Choice !\n");
        }

        choice = Choice(choice);
    }

    printf("\nThank you for using my program :)\n");
    return 0;
}

int Choice(int choice){
    printf("\nWould you like to rerun the program ?\n");
    printf("1 for yes, 0 for no\n");
    printf("Choice : ");

    scanf("%d",&choice);
    while(getchar()!='\n');
    return choice;
}

struct node* CreatePair(struct node* root,char newword[50],char newmeaning[50]){
    if(root==NULL){
        root = (struct node*)malloc(sizeof(struct node));
        strcpy(root->word,newword);
        strcpy(root->meaning,newmeaning);

        root->left = NULL;
        root->right = NULL;

        return root;
    }

    int cmp = strcmp(newword,root->word);

    if(cmp < 0){
        root->left = CreatePair(root->left,newword,newmeaning);
    }
    else if(cmp > 0){
        root->right = CreatePair(root->right,newword,newmeaning);
    }
    else{
        int choice;
        printf("\nThe word already exists !");
        printf("\nShould I rewrite the meaning ?");
        printf("\n1 for yes,0 for no");
        printf("\nChoice : ");
        scanf("%d",&choice);

        if(choice==1){
            strcpy(root->meaning,newmeaning);
        }

        printf("\nDone !\n");
        return NULL;
    }

    return root;
}

void LookupMeaning(struct node* root,char word[50]){
    if(root==NULL){
        return;
    }

    LookupMeaning(root->left,word);

    if(strcmp(word,root->word)==0){
        printf("%s : %s",root->word,root->meaning);
    }

    LookupMeaning(root->right,word);
}

void LookupWord(struct node* root, char meaning[50]){
    if(root == NULL){
        return;
    }
       
    LookupWord(root->left, meaning);
       
    if(strcmp(meaning, root->meaning) == 0){
        printf("\n%s : %s", root->word, meaning);
        printf("\nDone !\n");
    }
       
    LookupWord(root->right, meaning);
}

void DisplayElements(struct node* root){
    if(root==NULL){
        return;
    }

    DisplayElements(root->left);
    printf("%s : %s\n",root->word,root->meaning);
    DisplayElements(root->right);
}

struct node* DeletePair(struct node* root,char word[50]){
    if(root==NULL){
        printf("\nWord not found !\n");
        return NULL;
    }

    int cmp = strcmp(word,root->word);

    if(cmp < 0){
        root->left = DeletePair(root->left,word);
    }
    else if(cmp > 0){
        root->right = DeletePair(root->right,word);
    }
    else{
        // If NO child
        if(root->left==NULL && root->right==NULL){
            free(root);
            printf("\nDone !\n");
            return NULL;
        }
        
        //If 1 child
        else if(root->left==NULL){
            struct node* temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right==NULL){
            struct node* temp = root->left;
            free(root);
            return temp;
        }
        //Has 2 child, finding the inorder predecc i.e, the smallest child in the right subtree
        struct node* temp = findInorderPredecessor(root->left);

        strcpy(root->word,temp->word);
        strcpy(root->meaning,temp->meaning);
        
        root->left = DeletePair(root->left,temp->word);
        return root;
    }

    return root;
}

struct node* findInorderPredecessor(struct node* root){
    struct node* temp = root;
    while(temp!=NULL && temp->right!=NULL){
        temp = temp->right;
    }

    return temp;
}