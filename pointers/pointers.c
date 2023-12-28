// & - provides address of something stored in memory
// * - instructs compiler to go to a location in memory

#include <stdio.h>

int main(void)
{
    int n = 50;
    int *p = &n;
    printf("%p\n", p); // prints location in memory
    printf("%i\n", *p); // prints 50
}
