#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    string text = get_string("Text: ");
    int letters = 0, sentences = 0, words = 1;
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        char c = text[i];
        if (isaplha(c)
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
    float L = letters * (100 / words);
    float S = sentences * (100 / words);
    int index = roundf(0.0588 * L - 0.296 * S - 15.8);
    if (index > 16)
    {
        printf("Grade 16+");
    }
    else
    {
        printf("Grade %i", index);
    }
}
