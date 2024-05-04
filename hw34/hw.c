    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>

    int main()
    {
        int n;
        scanf(" N = %d \n", &n);

        //memory allocation for the array
        int* A = malloc(n* sizeof(int));

        //store the values in the array
        for (int i=0; i < n; i++)
            scanf(" %d", &A[i]);

        //create a string to place the cmd into
        char S[30];

        printf("cmd: ");
        scanf("%s", S);

        //make the comparisons
        char ss[5];     //string show
        ss[0]= 's';
        ss[1]= 'h';
        ss[2]= 'o';
        ss[3]= 'w';
        ss[4]= 0;
        char sq[5];     //string quit
        sq[0]= 'q';
        sq[1]= 'u';
        sq[2]= 'i';
        sq[3]= 't';
        sq[4]= 0;
        char sw[5];     //string swap
        sw[0] = 's';
        sw[1] = 'w';
        sw[2] = 'a';
        sw[3] = 'p';
        sw[4] = 0;
        
        while ( 0 != strcmp(S, sq))
        {
            if (0 == strcmp(S, ss))
            {
                //print the array
                for (int i=0; i < n; i++)
                {
                    printf("[%d] ", i);
                    for (int j=0; j < A[i]; j++)
                    {
                        printf("*");
                    }
                    printf("\n");
                }
            }
            else if (0 == strcmp(S, sw))
            {
                //check which values to swap
                int i, j;
                scanf(" %d %d", &i, &j);
                //create a new temp array to be able to swap
                int temp = A[i];
                A[i] = A[j];
                A[j] = temp;
            }
            printf("cmd: ");
            scanf("%s", S);
        }


        free(A);
        return 0;
    }