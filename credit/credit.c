#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long n = get_long ("Number: ");

    // check length
    int len;
    long temp = n;
    while (temp > 0)
    {
        temp = temp / 10;
        len ++;
    }
    if (len != 13 || len != 15 || len != 16)
    {
        printf("INVALID");
        return 0;
    }

    // check sum
    if (checksum(n))
    {
        printf("VALID");
    }
}
