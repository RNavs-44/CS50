#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // TODO: Prompt for start size
    int start;
    do {
        start = get_int("Enter starting population size: ");
    }
    while (start < 9);

    // TODO: Prompt for end size
    int end;
    do {
        end = get_int("Enter ending population size: ");
    }
    while (end < start);

    // TODO: Calculate number of years until we reach threshold
    int years;
    while (start < end) {
        int gain = start / 3;
        int lose = start / 4;

    }
    // TODO: Print number of years
}
