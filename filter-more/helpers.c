#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int row = 0; row < height; row++)
    {
        for (int column = 0; column < width; column++)
        {
            int average = round((image[row][column].rgbtRed + image[row][column].rgbtBlue + image[row][column].rgbtGreen) / 3.0);
            image[row][column].rgbtRed = average;
            image[row][column].rgbtBlue = average;
            image[row][column].rgbtGreen = average;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];
    for (int row = 0; row < height; row++)
    {
        for (int column = 0; column < width; column++)
        {
            int count = 0;
            float totalRed = totalGreen = totalBlue = 0;
            int[] rowCoords = { row - 1, row, row + 1 };
            int[] colCoords = { column - 1, column, column + 1 }
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    if (rowCoords[i] >= 0 && rowCoords[i] < width && colCoords[i] >= 0 && colCoords[j] < height)
                    {
                        totalR += image[row][column].rgbtRed;
                        totalG += image[row][column].rgbtGreen;
                        totalB += image[row][column].rgbtBlue;
                        count++;
                    }
                }
            }
            temp[row][column].rgbtRed = round(totalRed / (float)count);
            temp[row][column].rgbtGreen = round(totalGreen / (float)count);
            temp[row][column].rgbtBlue = round(totalBlue / (float)count);
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}
