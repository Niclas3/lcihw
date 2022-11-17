#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    char name[4] = { 'a' };
    int numbers[4] = { 0 };
    /* char name[4] = { 'a', 'a', 'a', 'a' }; */

    // first, print them out raw
    /* printf("numbers: %d %d %d %d\n", */
    /*         numbers[0], numbers[1], numbers[2], numbers[3]); */
    /*  */
    /* printf("name each: %c %c %c %c\n", */
    /*         name[0], name[1], name[2], name[3]); */
    /*  */
    /* printf("name each by int: %d %d %d %d\n", */
    /*         name[0], name[1], name[2], name[3]); */
    /*  */
    /* printf("name: %s\n", name); */

    //set up the numbers
    numbers[0] = 1;
    numbers[1] = 2;
    numbers[2] = 3;
    numbers[3] = 4;

    //set up the name
    name[0] = 'Z';
    name[1] = 'e';
    name[2] = 'd';
    name[3] = 'a';
    /* name[7] = '4'; */
    /* name[8] = '5'; */
    /* name[9] = '6'; */
    /* name[10] = '7'; */
    /* name[11] = '8'; */
    /* name[12] = '*'; */
    /* name[13] = 'A'; */

    // then print them out initialized 
    /* printf("numbers: %d %d %d %d\n", */
    /*         numbers[0], numbers[1], numbers[2], numbers[3]); */
    /*  */
    /* printf("name each: %c %c %c %c\n", */
    /*        name[0], name[1], name[2], name[3]); */

    // print the name like a string
    /* printf("name: %s\n", name); */
    /*  */
    /* for (int rev_i = strlen(name); rev_i >= 0; rev_i--) { */
    /*     printf("%c ", name[rev_i]); */
    /* } */
    /* printf("\n"); */

    char name_4[] = "abc";
    int *p_store = name_4;

    printf("name_4: %s\n", name_4);
    printf("p_store: %d 'name_4': %s\n", *p_store, name_4);

    // another way to use name
    /* char *another = "Zed"; */
    /*  */
    /* printf("another: %s\n", another); */
    /* printf("another each: %c %c %c %c\n", */
    /*         another[0], another[1], another[2], another[3]); */

    return 0;
}
