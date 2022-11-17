#include <stdio.h>

int main(int argc, char *argv[])
{
    int i = 0,j = 0;

    // go through each string in argv
    // why am I skipping argv[0]?
    /* for (i = 0; j = i*10, i < argc ; i++) { */
    /*     printf("j:??%d \n", j); */
    /*     printf("arg %d: %s\n", i, argv[i]); */
    /* } */
    argv[3] = "insert_By_code";
    for (i = 0,j = i+10 ;  
               i < argc ; i++) {
        printf("j:??%d \n", j);
        printf("arg %d: %s\n", i, argv[i]);
    }

    // Let's make our own array of strings
    char *states[] = {
        "California", "Oregon",
        "Washington", "Texas", NULL
    };

    int num_states = 5;
    for (i = 0; i < num_states; i++) {
        printf("state %d: %s\n", i, states[i]);
    }

    return 0;
}
