#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    // check only 1 command line argument
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    // validate key consists of 26 characters
    string key = argv[1];
    if (strlen(key) != 26)
    {
        printf("Key must contain 26 characters\n");
        return 1;
    }

    // validate key consists of only unique alphabets
    for (int i = 0, n = strlen(key); i < n; i++)
    {
        if (!isalpha(key[i]))
        {
            printf("Key must contain 26 characters\n");
            return 1;
        }
        for (int j = i + 1; j < n; j++)
        {
            if (key[i] == key[j])
            {
                printf("Key must contain 26 unique characters\n");
                return 1;
            }
        }
    }

    string plaintext = get_string("plaintext: ");
    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        char c = plaintext[i];
        if (isupper(c))
        {
            plaintext[i] = toupper(key[c-'A']);
        }
        else if (islower(c))
        {
            plaintext[i] = toupper(key[c-'a']);
        }
    }

    printf("ciphertext: %s\n", plaintext);
}
