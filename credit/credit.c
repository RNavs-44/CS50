#include <cs50.h>
#include <stdio.h>

/*
Luhn's Algorithm:
1. Multiply every other digit by 2, starting with the number’s second-to-last digit, and then add those products’ digits together.
2. Add the sum to the sum of the digits that weren’t multiplied by 2.
3. If the total’s last digit is 0 (or, put more formally, if the total modulo 10 is congruent to 0), the number is valid!
*/

bool checksum(long n)
{
    int sum1 = 0, sum2 = 0, mod;
    do
    {
        sum1 += n % 10;
        n /= 10;

        mod = n % 10;
        n /= 10;
        mod *= 2;
        sum2 += (mod % 10) + (mod / 10);
    }
    while (n > 0);
    if ((sum1 + sum2) % 10 != 0)
    {
        return false;
    }
    return true;
}

int main(void)
{
    long n = get_long("Number: ");

    // check length
    int len = 0;
    long temp = n;
    while (temp > 0)
    {
        temp = temp / 10;
        len++;
    }
    if (len != 13 && len != 15 && len != 16)
    {
        printf("INVALID\n");
        return 0;
    }

    // check sum
    if (!checksum(n))
    {
        printf("INVALID\n");
        return 0;
    }

    do
    {
        n /= 10;
    }
    while (n > 99);
    if ((n / 10 == 5) && (0 < n % 10 && 6 > n % 10) && (len == 16))
    {
        printf("MASTERCARD\n");
    }
    else if ((n / 10 == 3) && (n % 10 == 4 || n % 10 == 7) && (len == 15))
    {
        printf("AMEX\n");
    }
    else if (n / 10 == 4 && (len == 13 || len == 16))
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}
