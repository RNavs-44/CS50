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
        for (int col = 0, cur = width - 1; col < width; col++, cur--)
        {
            temp[row][cur] = image[row][col];
        }
    }
    for (int row = 0; row < height; row++)
    {
        for (int column = 0; column < width; column++)
        {
            image[row][column] = temp[row][column];
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];
    for (int row = 0; row < height; row++)
    {
        for (int column = 0; column < width; column++)
        {
            int count = 0;
            float totalRed = 0, totalGreen = 0, totalBlue = 0;
            int rowCoords[] = { row - 1, row, row + 1 };
            int columnCoords[] = { column - 1, column, column + 1 };
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    if (rowCoords[i] >= 0 && rowCoords[i] < height && columnCoords[j] >= 0 && columnCoords[j] < width)
                    {
                        totalRed += image[rowCoords[i]][columnCoords[j]].rgbtRed;
                        totalGreen += image[rowCoords[i]][columnCoords[j]].rgbtGreen;
                        totalBlue += image[rowCoords[i]][columnCoords[j]].rgbtBlue;
                        count++;
                    }
                }
            }
            temp[row][column].rgbtRed = round(totalRed / count);
            temp[row][column].rgbtGreen = round(totalGreen / count);
            temp[row][column].rgbtBlue = round(totalBlue / count);
        }
    }
    for (int row = 0; row < height; row++)
    {
        for (int column = 0; column < width; column++)
        {
            image[row][column] = temp[row][column];
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    int Gx[3][3] = {
        {-1, 0, 1},
        {-2, 0, 2},
        {-1, 0, 1}
    };
    int Gy[3][3] = {
        {-1, -2, -1},
        {0, 0, 0},
        {1, 2, 1}
    };
    RGBTRIPLE temp[height][width];
    for (int row = 0; row < height; row++)
    {
        for (int column = 0; column < width; column++)
        {
            int count = 0;
            float GxRed = 0, GxGreen = 0, GxBlue = 0, GyRed = 0, GyGreen = 0, GyBlue = 0;
            int rowCoords[] = { row - 1, row, row + 1 };
            int columnCoords[] = { column - 1, column, column + 1 };
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    if (rowCoords[i] >= 0 && rowCoords[i] < height && columnCoords[j] >= 0 && columnCoords[j] < width)
                    {
                        GxRed += image[rowCoords[i]][columnCoords[j]].rgbtRed * Gx[i][j];
                        GxGreen += image[rowCoords[i]][columnCoords[j]].rgbtGreen * Gx[i][j];
                        GxBlue += image[rowCoords[i]][columnCoords[j]].rgbtBlue * Gx[i][j];
                        GyRed += image[rowCoords[i]][columnCoords[j]].rgbtRed * Gy[i][j];
                        GyGreen += image[rowCoords[i]][columnCoords[j]].rgbtGreen * Gy[i][j];
                        GyBlue += image[rowCoords[i]][columnCoords[j]].rgbtBlue * Gy[i][j];
                        count++;
                    }
                }
            }
            int finalRed = sqrt(GxRed * GxRed + GyRed * GyRed);
            int finalGreen = sqrt(GxGreen * GxGreen + GyGreen * GyGreen);
            int finalBlue = sqrt(GxBlue * GxBlue + GyBlue * GyBlue);
        }
    }
    for (int row = 0; row < height; row++)
    {
        for (int column = 0; column < width; column++)
        {
            image[row][column] = temp[row][column];
        }
    }
    return;
}
