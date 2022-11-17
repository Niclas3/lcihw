#include <stdio.h>
int main(int argc, char* argv[]){
    char *age = "\010";
    int height = 72;

    printf("I am %d years old. \n", age);
    printf("I am %d inches tall. \n", height);

    /* printf("what is bell character\?\?<bell>\a"); */
    /* printf("what is <backspace>b<backspace>\n"); */
    /* printf("what is <backspace>b\b<backspace>\n"); */
    /* printf("Ignore remaining characters in this string.....\n"); */
    /* printf("Ignore remaining characters \c in this string.....\n"); */
    /* printf("escape character \eeeee"); */
    /* printf("escape character eeee"); */
    /* printf("formfeed\fpage break\n"); */
    
    // \r will ignore left all string and return right strings
    // \r source\rsomething\n
    /* printf("first line"); */
    /* printf("lilz\rcba"); */
    /* printf("z\rabcdefghi"); */
    /* printf("abcdefghi\n123\rz"); */
    /* printf("abcdefghi1234567"); */
    /* printf("<tab>\t<tab2>\n"); */
    /* printf("<vertical tab>\v<vertical tab>\n"); */
    /* printf("<vertical tab>\n\t\t<vertical tab>"); */
    /* printf("\\"); */
    /* char s1[] = "\xFF"; */
    /* printf("what is \001"); */
    /* printf("what is %a",(double) *s1); */

    return 0;
}
