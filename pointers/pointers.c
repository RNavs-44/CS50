// & - provides address of something stored in memory
// * - instructs compiler to go to a location in memory

#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n = 50;
    int *p = &n;
    printf("%p\n", p); // prints location in memory
    printf("%i\n", *p); // prints 50

    string s = "HI!";
    printf("%p\n", s);
    char *q = &s[2];
    printf("%p\n", &s[0]);
    printf("%p\n", &s[1]);
    printf("%p\n", &s[2]);
    printf("%p\n", &s[3]);
    printf("%c\n", *q);
}
