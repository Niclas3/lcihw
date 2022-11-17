#include <stdio.h>

int main(int argc, char *argv[])
{
    int i = 0;

    if (argc == 2) {
        printf("You only have one argument. You suck.\n");
    } else if (argc > 1 && argc < 4) {
        printf("Here's your arguments:\n");

        for (i = 1; i < argc; i++) {
            printf("%s ", argv[i]);
        }
        printf("\n");
    } else if (argc > 10 || (argc < 14 && argc != 100) ) {
        printf("You have too many arguments. You suck.\n");
        for (i = 1; i < argc; i++){
            for (int j = 0; *((*(argv+i))+j) != '\0'; j++) {
                printf("%c ",*((*(argv+i))+j));
            }
            printf("\n");
        }
    }
    return 0;
}
