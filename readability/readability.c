#include <cs50.h>
#include <stdio.h>

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
    }

    int index = 0.0588 * L - 0.296 * S - 15.8;
}
