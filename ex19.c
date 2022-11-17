#include "dbg_bk.h"
#include <stdio.h>

void test_debug(){
    debug("I have Brown Hair.");

    debug("I am %d years old", 37);
}
int main(int argc, char *argv[])
{
    test_debug();
}
