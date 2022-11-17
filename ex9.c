#include <stdio.h>

int main(int argc, char *argv[])
{
    int i;
    char *cities[4] = { "California", "Oregon", "Washington", "Texas" };
    for (i = 0; i < argc; i++) {
        printf("arg %d: %s\n", i, argv[i]);
    }
    for (i = 0; i < 4; i++) {
        printf("state %d: %s\n", i, cities[i]);
    }

    i = 25;
    while (--i){
        if (i % 2 != 0 && i > 10) { 
            printf("**%d** ",i);
        } else if (i / 2 == 0){
            printf("%d ",i * 100);
        } else {
            printf("%d ",i);
        }
    }
    return 0;
}
