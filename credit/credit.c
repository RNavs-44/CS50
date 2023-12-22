#include <cs50.h>
#include <stdio.h>

/*
Luhn's Algorithm:
1. Multiply every other digit by 2, starting with the number’s second-to-last digit, and then add those products’ digits together.
2. Add the sum to the sum of the digits that weren’t multiplied by 2.
3. If the total’s last digit is 0 (or, put more formally, if the total modulo 10 is congruent to 0), the number is valid!
*/

bool checksum(long x)
{
    int sum1 = 0, sum2 = 0, total = 0;
}

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
