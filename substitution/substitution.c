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

    // validate the key consists of only alphabets
    string key = argv[1];
    for (int i = 0, n = strlen(key); i < n; i++)
    {
        if (!isalpha(key[i]))
        {
            
        }
    }
}
