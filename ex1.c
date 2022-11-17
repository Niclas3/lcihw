#include <stdio.h>

int* test_static(){
    static int z =10;
    return &z;
}
int* test_auto(){
    auto int z =10;
    return &z;
}

int main(int argc, char *arv[]){
    int *zp = test_static();
    int *zp_auto = test_auto();
    printf("%p\n", zp);
    printf("%d\n", *zp);

    printf("%p\n", zp_auto);
    printf("%d\n", *zp_auto);
    /* int distance = 100; */
    /* char* weekday = "Sunday"; */
    /* char* month = "July"; */
    /* int day = 3; */
    /* int hour = 10; */
    /* int min = 2; */
    /* int count; */

    /* do{ */
    /*     printf("that is do things"); */
    /* } while(0<1); */
    
   /*  typedef unsigned char zm_type; */
   /*  zm_type a = 'a'; */
   /*  union U_stu{ */
   /*      char *name; */
   /*      int age; */
   /*  } stu_u; */
   /*  union U_stu zm; */
   /*  */
   /*  switch(a){ */
   /*      case 0: */
   /*          printf("some thing"); */
   /*          break; */
   /*      default: */
   /*          putc(1, stdin); */
   /*  } */
   /*  */
   /*  typedef struct STUU { */
   /*      int age; */
   /*      int number; */
   /*  } AYU; */
   /*  */
   /*  AYU *student1; */
   /*  */
   /* int register ab= 10;  */
   /*  struct STU{ */
   /*      char name; */
   /*      int age; */
   /*  } student; */
   /*  struct STU *s; */
   /*   */
   /*  */
   /*  printf("do some things"); */
   /*  */
   /*  for(int i=0; i<5; i++){ */
   /*      count = printf("Y more complex than Hello world. \n"); */
   /*      printf("count: %d \n",count); */
   /*  } */
   /*       */
   /*  fprintf(stderr, "%s, %s %d, %.2d: %.2d\n", */
   /*          weekday, month, day, hour, min); */
    return 0;
}
