// & - provides address of something stored in memory
// * - instructs compiler to go to a location in memory

#include <cs50.h>
#include <stdio.h>

int main(void)
{
    char *s = "HI!";
    printf("%c\n", *s);
    printf("%c\n", *(s + 1));
    printf("%c\n", *(s + 2));
}
