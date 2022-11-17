#include <stdio.h>
#include <assert.h>
#include <stdint.h>

int main(int argc, char *argv[])
{
    int distance = 100;
    float power = 2.345f;
    double super_power = 56789.4532;
    char initial = 'A';
    char first_name[] = "Zed";
    char last_name[] = "Shaw";

    first_name[3] = 'Z';

    /* printf("You are %d miles away.\n", distance); */
    /* printf("You have %f levels of power.\n", power); */
    /* printf("You have %f awesome super powers.\n", super_power); */
    /* printf("I have an initial %c.\n", initial); */
    /* printf("I have a first name %s.\n", first_name); */
    /* printf("I have a last name %s.\n", last_name); */
    /* printf("My whole name is %s %c. %s.\n", */
    /*         first_name, initial, last_name); */
    /*  */
    /* int bugs = 100; */
    /* double bug_rate = 1.2; */
    /*  */
    /* printf("You have %d bugs at the imaginary rate of %f.\n", */
    /*         bugs, bug_rate); */

    /* unsigned long universe_of_defects = 1 * 1024 * 1024 * 1024 * 0xFFFFFFFF; */
    /* unsigned long universe_of_defects = 0xfFFFFFFF + 1; */
    /* unsigned long universe_of_defects = 18446744073709551615; */
    /* unsigned long universe_of_defects = 0xffffffffffffffff + 1;//18446744073709551615 ;//9223372036854775808-1; // 0x8000000000000000 ;//9223372034707292160 ;//0x8000000080000000;//4294967295;//18446744073709551615; */
                                                               // 0x7fffffffffffffff

    /* while (universe_of_defects != 0) { */
        /* printf("sizeof unsigned long %ld\n",sizeof(unsigned long) ); */
        /* printf("sizeof unsigned %ld\n",sizeof(unsigned ) ); */
        /* printf("The entire universe has %lu bugs.\n", universe_of_defects); */
    /*     universe_of_defects++; */
    /* } */
    /* printf("finished \n"); */

    /* long universe_of_defects_l = 0xFFFFFFFFFFFFFFFF; */
    /* signed long universe_of_defects_max_signed_long = 18446744073709551615;//0x8000000080000000; */
    /* signed long universe_of_defects_max_signed_long = 9223372036854775807 + 1;// 18446744073709551615;//0x8000000080000000; */
    signed long universe_of_defects_max_signed_long = 9223372036854775808;// 18446744073709551615;//0x8000000080000000;
    unsigned long universe_of_defects_max_unsigned_long = 9223372036854775808;// 18446744073709551615;//0x8000000080000000;
    /* signed long universe_of_defects_max_signed_long = 0x80000000 + 1; */
    /* signed long universe_of_defects_max_signed_long = 4294967295; // there are */
                                                                  // casting
                                                                  // from signed
                                                                  // to unsigned type;
                                                                  //
    /* signed long universe_of_defects_max_signed_long = 0x7FFFFFFFFFFFFFFF + 1; // there are */
    printf("The entire universe has %ld bugs.\n", universe_of_defects_max_signed_long);
    printf("UN The entire universe has %lu bugs.\n", universe_of_defects_max_unsigned_long);
    /* printf("The entire universe has %ld bugs.\n", universe_of_defects_overflow_max); */
                                                                      
                                                                  
    /* signed long universe_of_defects_overflow_max = -0x80000000 - 1; */
    /* signed long universe_of_defects_overflow_max = -0x7fffffff - 1 - 1; */
    /* assert(0x80000000 == universe_of_defects_overflow_max); */
    /* assert(0x7FFFFFFF+1 == 0x80000000); */
    /* signed long universe_of_defects_7fp1 = 0xFFFFFFFF; */
    /* printf("sizeof signed long %ld\n",sizeof(signed long) ); */
    /* printf("The entire universe has %ld bugs.\n", universe_of_defects_max_signed_long); */
    /* printf("The entire universe has %ld bugs.\n", universe_of_defects_overflow_max); */

    /*  */
    /* double expected_bugs = bugs * bug_rate; */
    /* printf("You are expected to have %f bugs.\n", expected_bugs); */
    /*  */
    /* double part_of_universe = expected_bugs / universe_of_defects; */
    /* printf("That is only a %e portion of the universe.\n", */
    /*         part_of_universe); */
    /*  */
    /* // this makes no sense, just a demo of something weird */
    /* char nul_byte = '\0'; */
    /* int care_percentage = bugs * nul_byte; */
    /* #<{(| int *nul_symbol = NULL; |)}># */
    /* #<{(| int care_percentage = bugs * (*nul_symbol); |)}># */
    /* printf("Which means you should care %d%%.\n", care_percentage); */
    /* printf("Which means you should care %s%%.\n", care_percentage); */
    /* printf("Which means you should care %c%%.\n", care_percentage); */
    /* printf("Which means you should care %e%%.\n", care_percentage); */

    return 0;
}
