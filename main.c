#include <stdio.h>
#include <stdlib.h>
#include "strawhats.c"



int main()
{
    string name;
    printf("Enter name: ");
    gets(name);
    printf("your name is: ");
    puts(name);

    printf("Enter an integer: ");
    int howl = get_int();
    printf("%d\n",howl);

    printf("Enter a float: ");
    float meh = get_float();
    printf("%f\n",meh);

    printf("Enter a double: ");
    double meow = get_double();
    printf("%lf\n",meow);
}
