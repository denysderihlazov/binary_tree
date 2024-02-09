#include <stdio.h>
#include <stdlib.h>

#define HELP_INFO \
" ---binary Tree--- \n"\
"   Usage instructions:\n\n" \
" - To add elements to the tree, run the program with integers as arguments.\n"\
"   The first argument after the program name will be taken as the base key,\n"\
"   and subsequent keys will be generated and added based on it.\n"\
"   Example: ./main 10 will add keys around the base key 10.\n\n" \
" - To search for an element, provide the key as the second argument.\n"\
"   The program will search for this key in the tree and report if it was found.\n"\
"   Example: ./main 10 15 will add keys around 10 and search for 15.\n"


struct tree {
    int key;
    struct tree *left;
    struct tree *right;
};

void printHeloInfo()
{
    printf(HELP_INFO);
    exit(0);
}

int strCompare(char *str1, char *str2) {
    int i = 0;
    while(*(str1+i) == *(str2+i)) {
        if(*(str1+i) == '\0') return 1;
        i++;
    }
    return 0;
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

void addNode(int key, struct tree **Root) {
    if(Root == NULL) {
        printf("Unable to allocate memory!\n");
        exit(1);
    }

    struct tree *newNode = malloc(sizeof(struct tree));
    if (newNode == NULL) {
        printf("Unable to allocate memory for new node!\n");
        exit(2);
    }

    newNode->key = key;
    newNode->left = NULL;
    newNode->right = NULL;

    if(*Root == NULL) { // The tree is empty
        *Root = newNode;
    } else {
        struct tree *currentNode = *Root;
        struct tree *parent = NULL;

        while(1) {
            parent = currentNode;

            if(key == currentNode->key) {
                printf("Tree key already exists!\n");
                free(newNode);
                return;
            } else if(key < currentNode->key) {
                currentNode = currentNode->left;
                if(currentNode == NULL) {
                    parent->left = newNode;
                    return;
                }
            } else {
                currentNode = currentNode->right;
                if(currentNode == NULL) {
                    parent->right = newNode;
                    return;
                }
            }
        }
    }
}

int searchThroughBinTree(int searchable, struct tree **Root) {
    if(Root == NULL || *Root == NULL) {
        printf("The tree is empty!\n");
        return -1;
    }

    struct tree *currentNode = *Root;

    while (currentNode != NULL) {
        if(currentNode->key == searchable) {
            printf("Found\n");
            return 1;
        } else if (searchable < currentNode->key) {
            currentNode = currentNode->left;
        } else if (searchable > currentNode->key) {
            currentNode = currentNode->right;
        }
    }

    printf("The element isn't in the tree\n");
    return 0;
}

void freeTree(struct tree *node) {
    if (node == NULL) return;
    freeTree(node->left);
    freeTree(node->right);
    free(node);
}

int main(int argc, char *argv[])
{
    if(argc < 2) {
        printHeloInfo();
    }

    struct tree *Tree = NULL;

    if(strCompare(argv[1], "-h") || strCompare(argv[1], "--help")) {
        printHeloInfo();
    }

    if(argc == 3) {
        int key = parseCharToInt(argv[1]);
        addNode(key, &Tree);
        addNode(key+1, &Tree);
        addNode(key+2, &Tree);
        addNode(key+3, &Tree);
        addNode(key+5, &Tree);
        addNode(key+7, &Tree);
        addNode(key+4, &Tree);
        addNode(key+9, &Tree);

        int searchKey = parseCharToInt(argv[2]);
        printf("Searching for: %d\n", searchKey);
        int found = searchThroughBinTree(searchKey, &Tree);
        if(found == 1) {
            printf("Element found.\n");
        } else {
            printf("Element not found.\n");
        }
    }

    freeTree(Tree);

    return 1;
}