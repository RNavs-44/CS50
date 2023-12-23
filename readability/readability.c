#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string text = get_string("Text: ");
    int letters = 0, sentences = 0, words = 1;
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        char c = text[i];
        if (isalpha(c))
        {
            letters++;
        }
        else if (isspace(c))
        {
            words++;
        }
        else if (c == '!' || c == '.' || c == '?')
        {
            sentences++;
        }
    }
    float L = (float) letters * (100 / (float) words);
    float S = (float) sentences * (100 / (float) words);
    int index = roundf(0.0588 * L - 0.296 * S - 15.8);
    if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}
