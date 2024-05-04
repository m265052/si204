    //WILL PITKIN       m265052
    //hw35              01MAY24     (submit time)
    //********************************************
    //          FINAL HW!!!!!!!!!!!!!!!!!!!!
    //********************************************

    //do a previous hw that takes in a list and prints
    //out strings that begin with any letter
    //do this in c instead of c++


    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>

    struct Node
    {
        char s[128];
        struct Node* next;
    };

    struct Node* add2front(char* st , struct Node* L);
    void listprint(struct Node* L, char c);
    void deleteList(struct Node* L);

    int main()
    {
        printf("Enter words followed by END:\n");
        struct Node* L = NULL;
        char st[128];

        int cmp;       //comparison
        do{
            scanf(" %s", st);
            //make comparison from string to the word end
            cmp = strcmp(st, "END");
            L = add2front(st, L);

        }while(cmp != 0);


        printf("What letter?\n");
        char c;
        scanf(" %c", &c);

        listprint(L, c);

        deleteList(L);
        return 0;
    }


    struct Node* add2front(char* st , struct Node* L)
    {
        struct Node* T = malloc(sizeof(struct Node));
        strcpy(T->s, st);
        T->next = L;
        return T;
    }

    void listprint(struct Node* L, char c)
    {
        if ( L != NULL )
        {
            if (L->s[0] == c)
            printf("%s\n", L->s);
            //to reverse the print, this line below can just be placed above
            //the if statement
            listprint(L->next, c);
        }
    }
    void deleteList(struct Node* L)
    {
        if( L != NULL )
        {
            deleteList(L->next);
            free(L);
        }
    }