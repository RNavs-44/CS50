#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(int argc, string argv[])
{
    // check only 1 command line argument
    if (argc != 2)
    {
        printf("Usage: ./substitution key");
        return 1;
    }

    // validate key consists of 26 characters
    if (strlen(key) != 26)
    {
        printf("Key must contain 26 characters");
        return 1;
    }

    // validate the key consists of only alphabets
    string key = argv[1];
    for (int i = 0, n = strlen(key); i < n; i++)
    {
        if (!isalpha(key[i]))
        {
            printf("Key must contain 26 characters");
            return 1;
        }
    }

    // validate key consists of only unique alphabets
    for (int i = 0, n = strlen(key); i < n; i++)
    {
        if (!isalpha(key[i]))
        {
            printf("Key must contain 26 characters");
            return 1;
        }
    }
}
