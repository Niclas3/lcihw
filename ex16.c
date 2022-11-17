#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

struct Person {
    char *name;
    int age;
    int height;
    int weight;
};

struct Person *Person_create(char *name, int age, int height, int weight) {
    struct Person *who = malloc(sizeof(struct Person));
    assert(who != NULL);

    who->name = strdup(name);
    printf("name address %p\n", who->name);
    assert(who->name != NULL);
    who->age = age;
    who->height = height;
    who->weight = weight;

    return who;
}
// why C program always return pointer of struct instant of struct it self.
// If you return struct then you can not free() right memory address when you 
// alloc from malloc().
struct Person Person_create_ret_struct(char *name, int age, int height, int weight) {
    struct Person *who = malloc(sizeof(struct Person));
    assert(who != NULL);
    printf("pointer inner creater %p\n", who);

    who->name = strdup(name);
    assert(who->name != NULL);
    who->age = age;
    who->height = height;
    who->weight = weight;

    return *who;
}

struct Person Person_create_at_stack(char *_name, int _age, int _height, int _weight){
    struct Person sb = {
       .name = _name,
       .age = _age,
       .height = _height,
       .weight = _weight
    };
    return sb;
}

void Person_destroy(struct Person *who)
{
    assert(who != NULL);

    /* free(who->name); */
    free(who);
}

void Person_print(struct Person *who)
{
    printf("Name: %s\n", who->name);
    printf("\tAge: %d\n", who->age);
    printf("\tHeight: %d\n", who->height);
    printf("\tWeight: %d\n", who->weight);
}

void Person_print_at_stack(struct Person sb){
    printf("Name: %s\n", sb.name);
    printf("\tAge: %d\n", sb.age);
    printf("\tHeight: %d\n", sb.height);
    printf("\tWeight: %d\n", sb.weight);
}

int main(int argc, char *argv[])
{
    /* struct Person *zm = Person_create("zhoumin", 29, 175, 125); */
    /* printf("Outter pointer address :%p\n", &zm); */
    /* printf("Outter person address :%p\n", zm); */
    /* Person_print(zm); */
    /*  */
    /* Person_destroy(zm); */

    struct Person xyy = Person_create_at_stack("xingyayun", 32, 165, 45);
    Person_print_at_stack(xyy);
 
    // make two people structures
    /* struct Person *joe = Person_create("Joe Alex", 32, 64, 140); */
    /*  */
    /* struct Person *frank = Person_create("Frank Blank", 20, 72, 180); */
    /*  */
    /* // print them out and where they are in memory */
    /* printf("Joe is at memory location %p:\n", joe); */
    /* Person_print(joe); */
    /*  */
    /* printf("Frank is at memory location %p:\n", frank); */
    /* Person_print(frank); */
    /*  */
    /* // make everyone age 20 years and print them again */
    /* joe->age += 20; */
    /* joe->height -= 2; */
    /* joe->weight += 40; */
    /* Person_print(joe); */
    /*  */
    /* frank->age += 20; */
    /* frank->weight += 20; */
    /* Person_print(frank); */
    /*  */
    /* // destroy them both so we clean up */
    /* Person_destroy(joe); */
    /* Person_destroy(frank); */

    return 0;
}
