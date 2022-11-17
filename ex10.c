#include <stdio.h>

int main(int argc, char *argv[])
{
    if (argc <= 2) {
        printf("ERROR: You need one argument.\n");
        // this is how you abort a program
        return 1;
    }

    int gap = 'a' - 'A';
    printf("gap is %d.\n", gap);

    for (int j = 1; j < argc; j++) {
        for (int i = 0 ; argv[j][i] != '\0'; i++) {
            char letter = argv[j][i];
            char l_letter = letter + gap;
            if (letter + gap < 'a' || letter + gap > 'z') {
                if (l_letter == 'a') {
                    printf("%d: 'A'\n", i);

                } else if (l_letter == 'e') {
                    printf("%d: 'e'\n", i);

                } else if (l_letter == 'i') {
                    printf("%d: 'i'\n", i);

                } else if (l_letter == 'o') {
                    printf("%d: 'o'\n", i);

                } else if (l_letter == 'u') {
                    printf("%d: 'u'\n", i);
                } else if (l_letter == 'y') {
                    if (i < 2) {
                        // it's only sometimes Y
                        printf("%d: 'Y'\n", i);
                    }
                } else {
                    printf("%d: %c is not a vowel\n", i, letter);
                }
                /* switch (l_letter) { */
                /*     case 'a': */
                /*     #<{(| case 'A': |)}># */
                /*         printf("%d: 'A'\n", i); */
                /*         break; */
                /*  */
                /*     case 'e': */
                /*     #<{(| case 'E': |)}># */
                /*         printf("%d: 'E'\n", i); */
                /*         break; */
                /*  */
                /*     case 'i': */
                /*     #<{(| case 'I': |)}># */
                /*         printf("%d: 'I'\n", i); */
                /*         break; */
                /*  */
                /*     case 'o': */
                /*     #<{(| case 'O': |)}># */
                /*         printf("%d: 'O'\n", i); */
                /*         break; */
                /*  */
                /*     case 'u': */
                /*     #<{(| case 'U': |)}># */
                /*         printf("%d: 'U'\n", i); */
                /*         break; */
                /*  */
                /*     case 'y': */
                /*     #<{(| case 'Y': |)}># */
                /*         if (i > 2) { */
                /*             // it's only sometimes Y */
                /*             printf("%d: 'Y'\n", i); */
                /*         } */
                /*         break; */
                /*     default: */
                /*         printf("%d: %c is not a vowel\n", i, letter); */
                /* } */
            }
        }

        printf("\n");
    }
    return 0;
}
