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

int main(){
    struct node* root;
    int choice = 1;

    while(choice==1){
        printf("Enter your choice");
        printf("1 for entering a word-meaning pair");
        printf("2 for looking up a word");
        printf("3 for looking up a meaning");
        printf("4 for displaying all the word-meaning pairs lexicographically");
        printf("Choice : ");
        scanf("%d",&choice);

        if(choice==1){
            char tempword[50];
            char tempmeaning[50];

            printf("\nEnter the word : ");
            fgets(tempword,50,stdin);
            printf("\nEnter the meaning : ");
            fgets(tempmeaning,50,stdin);

            CreatePair(&root,tempword,tempmeaning);
            printf("\nDone 1\n");
        }
        if(choice==2){
            char word[50];

            printf("Enter the word,whose meaning you wish to lookup : ");
            fgets(word,50,stdin);

            LookupWord(&root,word);
            printf("\nDone !\n");
        }
        if(choice==3){
            char meaning[50];

            printf("Enter the word,whose meaning you wish to lookup : ");
            fgets(meaning,50,stdin);

            LookupMeaning(&root,meaning);
            printf("\nDone !\n");
        }
        else{
            printf("\nInvalid Choice !\n");
        }

        choice = Choice();
    }

    printf("\nThank you for using my program :)\n");
    return 0;
}

void CreatePair(struct node* root,char newword[50],char newmeaning[50]){
    if(root==NULL){
        strcopy(root->word,newword);
        strcopy(root->meaning,newmeaning);

        printf("\nDone !\n");
        return;
    }

    int cmp = strcmp(newword,root->word);

    if(cmp < 0){
        root->left = CreateNode(root->left,newword,newmeaning);
    }
    if(cmp > 0){
        root->right = CreateNode(root->right,newword,newmeaning);
    }
    else{
        int choice;
        printf("\nThe word already exists !");
        printf("Should I rewrite the meaning ?");
        printf("1 for yes,0 for no");
        printf("Choice : ");
        scanf("%d",&choice);

        if(choice==1){
            strcopy(root->meaning,newmeaning);
        }

        printf("\nDone !\n");
        return;
    }
}

void LookupMeaning(struct node* root,char word){
    int cmp = strcmp(word,root->word);
    if(cmp < 1){
        LookupMeaning(root->left,word);
    }
    if(cmp > 1){
        LookupMeaning(root->right,word);
    }
    else{
        printf("\n%c : %c",word,root->meaning);
        printf("\nDone !\n");
        return;
    }
}

void LookupWord(struct node* root,char meaning){
    int cmp = strcmp(meaning,root->meaning);
    if(cmp < 1){
        LookupWord(root->left,meaning);
    }
    if(cmp > 1){
        LookupWord(root->right,meaning);
    }
    else{
        printf("\n%c : %c",root->word,meaning);
        printf("\nDone !\n");
        return;
    }
}

void DisplayElements(struct node* root){
    if(root==NULL){
        return;
    }

    DisplayElements(root->left);
    printf("%c : %c\n",root->word,root->meaning);
    DisplayElements(root->right);
}

DeletePair(struct node* root,char word){
    int cmp = strcmp(root->word,word);

    if(cmp < 0){
        DeletePair(root->left,word);
    }
    if(cmp > 0){
        DeletePair(root->right,word);
    }
    else{
        // If NO child
        if(root->left==NULL && root->right==NULL){
            free(root);
            printf("\nDone !\n");
            return;
        }
        
        //If 1 child
        else if(root->left==NULL){
            struct node* temp = root->right;
            free(root);
            return;
        }
        else if(root->right==NULL){
            struct node* temp = root->left;
            free(root);
            return;
        }
    }
}