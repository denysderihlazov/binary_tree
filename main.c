#include <stdio.h>
#include <stdlib.h>

#define HELP_INFO \
" ---binary Tree--- \n"\
"   Usage instructions:\n\n" \
"\nAttention: \n\n" \
"The <data> of structure must be an integer!\n"

struct tree {
    int data;
    struct tree *left;
    struct tree *right;
};

void printHeloInfo()
{
    printf(HELP_INFO);
    exit(0);
}


int strCompare(char *str1, char *str2)
{
    int i = 0;
    while(*(str1+i) != '\0' && *(str2+i) != '\0') {
        if((int)*(str1+i) == (int)*(str2+i) && (int)*(str1+i+1) == (int)*(str2+i+1)) {
            i++;
        } else {
            return 0;
        }
    }
 
    return 1;
}

int parseCharToInt(char *str)
{
    int answer = 0;
    char *args = str;
    int isNegative = 0;

    if((int)*str == (int)'-') {
        isNegative = 1;
        args++;
    }

    if((int)*args < (int)'0' || (int)*args > (int)'9') {
        printf("The argument isn't a digit!\n");
        printHeloInfo();
    }

    while((int)*args != (int)'\0') {
        if(answer == 0) {
            answer = (int)*args - (int)'0';
        } else {
            answer = answer*10 + (int)*args - (int)'0';
        }
        args++;
    }

    if(isNegative) {
        answer *= -1;
    }

    return answer;
}

void addNode(struct tree **Tree) {
    // add Tree->data
    // add Tree->left
    // add Tree->right
    if(Tree == NULL) {
        printf("Unable to allocate memory!\n");
        exit(1);
    }

    struct tree *newNode = malloc(sizeof(struct tree));
    newNode->data = 0;
    newNode->left = NULL;
    newNode->right = NULL;


}

int main(int argc, char *argv[])
{
    if(argc < 2) {
        printHeloInfo();
    }

    struct tree *Tree = malloc(sizeof(struct tree));
    Tree->data = 0;
    Tree->left = NULL;
    Tree->right = NULL;

    if(strCompare(argv[1], "-h") || strCompare(argv[1], "--help")) {
        printHeloInfo();
    }

    if(argc == 2) {
        // parseCharToInt(argv[1]);
        // addNode();
    }

    while(Tree != NULL) {
        struct tree *temp = Tree;
    }

    return 1;
}

// init and add elements to Tree
// count Tree sum
// find element in a Tree

// in a future draw tree in a console