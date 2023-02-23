#include "helpers.h"
#include <math.h>
#include <stdio.h>
// Convert image to grayscale

void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i = 0 ; i < height ; i++){
        for(int j= 0 ; j < width ; j++){
            float avg = image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed;
            int average = round(avg/3);
            image[i][j].rgbtBlue = image[i][j].rgbtRed = image[i][j].rgbtGreen = average;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE tempImage[height][width];
    for(int k = 0 ; k < height ; k++){
        for(int l = 0; l < width ; l++){
            tempImage[k][l].rgbtBlue = 0;
            tempImage[k][l].rgbtGreen = 0;
            tempImage[k][l].rgbtRed = 0;

        }
    }
    for(int i = 0 ; i < width/2 ; i++){
        for(int j = 0 ; j < height ; j++){
            tempImage[j][i] = image[j][i];
            image[j][i] = image[j][width-i-1];
            image[j][width-i-1] = tempImage[j][i];
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE duplicateImage[height][width];
    for(int i = 0 ; i < height ; i++){
        for( int j = 0 ; j < width ; j++){
            duplicateImage[i][j] = image[i][j];
        }
    }
    for(int i = 0 ; i < height ; i++){
        for(int j = 0 ; j < width ; j++){
            switch(j){
                case 0:
                    if(i == height-1){
                        duplicateImage[i][j].rgbtBlue = round((float)(image[i][j].rgbtBlue + image[i][j+1].rgbtBlue + image[i-1][j].rgbtBlue + image[i-1][j+1].rgbtBlue)/4);
                        duplicateImage[i][j].rgbtRed = round((float)(image[i][j].rgbtRed + image[i][j+1].rgbtRed + image[i-1][j].rgbtRed + image[i-1][j+1].rgbtRed)/4);
                        duplicateImage[i][j].rgbtGreen = round((float)(image[i][j].rgbtGreen + image[i][j+1].rgbtGreen + image[i-1][j].rgbtGreen + image[i-1][j+1].rgbtGreen)/4);
                    }
                    else{
                        duplicateImage[i][j].rgbtBlue = round((float)(image[i][j].rgbtBlue + image[i][j+1].rgbtBlue + image[i+1][j].rgbtBlue + image[i+1][j+1].rgbtBlue + image[i-1][j].rgbtBlue + image[i-1][j+1].rgbtBlue)/6);
                        duplicateImage[i][j].rgbtRed = round((float)(image[i][j].rgbtRed + image[i][j+1].rgbtRed + image[i+1][j].rgbtRed + image[i+1][j+1].rgbtRed + image[i-1][j].rgbtRed + image[i-1][j+1].rgbtRed)/6);
                        duplicateImage[i][j].rgbtGreen = round((float)(image[i][j].rgbtGreen + image[i][j+1].rgbtGreen + image[i+1][j].rgbtGreen + image[i+1][j+1].rgbtGreen + image[i-1][j].rgbtGreen + image[i-1][j+1].rgbtGreen)/6);
                    }
                    break;
            }
            switch(i){
                case 0:
                    if(j == 0){
                        duplicateImage[i][j].rgbtBlue = round((float)(image[i][j].rgbtBlue + image[i][j+1].rgbtBlue + image[i+1][j].rgbtBlue + image[i+1][j+1].rgbtBlue)/4);
                        duplicateImage[i][j].rgbtRed = round((float)(image[i][j].rgbtRed + image[i][j+1].rgbtRed + image[i+1][j].rgbtRed + image[i+1][j+1].rgbtRed)/4);
                        duplicateImage[i][j].rgbtGreen = round((float)(image[i][j].rgbtGreen + image[i][j+1].rgbtGreen + image[i+1][j].rgbtGreen + image[i+1][j+1].rgbtGreen)/4);
                    }
                    else if(j == width-1){
                        duplicateImage[i][j].rgbtBlue = round((float)(image[i][j].rgbtBlue + image[i][j-1].rgbtBlue + image[i+1][j].rgbtBlue + image[i+1][j-1].rgbtBlue)/4);
                        duplicateImage[i][j].rgbtRed = round((float)(image[i][j].rgbtRed + image[i][j-1].rgbtRed + image[i+1][j].rgbtRed + image[i+1][j-1].rgbtRed)/4);
                        duplicateImage[i][j].rgbtGreen = round((float)(image[i][j].rgbtGreen + image[i][j-1].rgbtGreen + image[i+1][j].rgbtGreen + image[i+1][j-1].rgbtGreen)/4);
                    }
                    else{
                        duplicateImage[i][j].rgbtBlue = round((float)(image[i][j].rgbtBlue + image[i][j+1].rgbtBlue + image[i][j-1].rgbtBlue + image[i+1][j].rgbtBlue + image[i+1][j-1].rgbtBlue + image[i+1][j+1].rgbtBlue)/6);
                        duplicateImage[i][j].rgbtRed = round((float)(image[i][j].rgbtRed + image[i][j+1].rgbtRed + image[i][j-1].rgbtRed + image[i+1][j].rgbtRed + image[i+1][j-1].rgbtRed + image[i+1][j+1].rgbtRed)/6);
                        duplicateImage[i][j].rgbtGreen = round((float)(image[i][j].rgbtGreen + image[i][j+1].rgbtGreen + image[i][j-1].rgbtGreen + image[i+1][j].rgbtGreen + image[i+1][j-1].rgbtGreen + image[i+1][j+1].rgbtGreen)/6);
                    }
                    break;
            }
            if(i == height-1 && j!=0 && j!=width-1){
                duplicateImage[i][j].rgbtBlue = round((float)(image[i][j].rgbtBlue + image[i][j+1].rgbtBlue + image[i][j-1].rgbtBlue + image[i-1][j].rgbtBlue + image[i-1][j-1].rgbtBlue + image[i-1][j+1].rgbtBlue)/6);
                duplicateImage[i][j].rgbtRed = round((float)(image[i][j].rgbtRed + image[i][j+1].rgbtRed + image[i][j-1].rgbtRed + image[i-1][j].rgbtRed + image[i-1][j-1].rgbtRed + image[i-1][j+1].rgbtRed)/6);
                duplicateImage[i][j].rgbtGreen = round((float)(image[i][j].rgbtGreen + image[i][j+1].rgbtGreen + image[i][j-1].rgbtGreen + image[i-1][j].rgbtGreen + image[i-1][j-1].rgbtGreen + image[i-1][j+1].rgbtGreen)/6);
            }
            if(j == width-1 && i!=0 && i!=height-1){
                duplicateImage[i][j].rgbtBlue = round((float)(image[i][j].rgbtBlue + image[i][j-1].rgbtBlue + image[i+1][j].rgbtBlue + image[i+1][j-1].rgbtBlue + image[i-1][j].rgbtBlue + image[i-1][j-1].rgbtBlue)/6);
                duplicateImage[i][j].rgbtRed = round((float)(image[i][j].rgbtRed + image[i][j-1].rgbtRed + image[i+1][j].rgbtRed + image[i+1][j-1].rgbtRed + image[i-1][j].rgbtRed + image[i-1][j-1].rgbtRed )/6);
                duplicateImage[i][j].rgbtGreen = round((float)(image[i][j].rgbtGreen + image[i][j-1].rgbtGreen + image[i+1][j].rgbtGreen + image[i+1][j-1].rgbtGreen + image[i-1][j].rgbtGreen + image[i-1][j-1].rgbtGreen)/6);
            }
            if(i == height-1 && j == width-1){
                duplicateImage[i][j].rgbtBlue = round((float)(image[i][j].rgbtBlue + image[i][j-1].rgbtBlue + image[i-1][j].rgbtBlue + image[i-1][j-1].rgbtBlue )/4);
                duplicateImage[i][j].rgbtRed = round((float)(image[i][j].rgbtRed + image[i][j-1].rgbtRed + image[i-1][j].rgbtRed + image[i-1][j-1].rgbtRed )/4);
                duplicateImage[i][j].rgbtGreen = round((float)(image[i][j].rgbtGreen + image[i][j-1].rgbtGreen + image[i-1][j].rgbtGreen + image[i-1][j-1].rgbtGreen )/4);
            }
            if(i!=0 && i!= height-1 && j!=0 && j!=width-1){
                duplicateImage[i][j].rgbtBlue = round((float)(image[i][j].rgbtBlue + image[i][j+1].rgbtBlue + image[i][j-1].rgbtBlue + image[i+1][j].rgbtBlue + image[i+1][j-1].rgbtBlue + image[i+1][j+1].rgbtBlue + image[i-1][j].rgbtBlue + image[i-1][j-1].rgbtBlue + image[i-1][j+1].rgbtBlue)/9);
                duplicateImage[i][j].rgbtRed = round((float)(image[i][j].rgbtRed + image[i][j+1].rgbtRed + image[i][j-1].rgbtRed + image[i+1][j].rgbtRed + image[i+1][j-1].rgbtRed + image[i+1][j+1].rgbtRed + image[i-1][j].rgbtRed + image[i-1][j-1].rgbtRed + image[i-1][j+1].rgbtRed)/9);
                duplicateImage[i][j].rgbtGreen = round((float)(image[i][j].rgbtGreen + image[i][j+1].rgbtGreen + image[i][j-1].rgbtGreen + image[i+1][j].rgbtGreen + image[i+1][j-1].rgbtGreen + image[i+1][j+1].rgbtGreen+ image[i-1][j].rgbtGreen + image[i-1][j-1].rgbtGreen + image[i-1][j+1].rgbtGreen)/9);
            }
        }
    }
    for(int i = 0 ; i < height ; i++){
        for( int j = 0 ; j < width ; j++){
            image[i][j] = duplicateImage[i][j];
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            temp[i][j] = image[i][j];
        }
    }

    int Gx[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};

    int Gy[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};

    for(int i = 0 ; i < height ; i++){
        for(int j = 0 ; j < width ; j++){
            float Gx_red = 0,
            Gx_green = 0,
            Gx_blue = 0,
            Gy_red = 0,
            Gy_green = 0,
            Gy_blue = 0;

            for(int k = -1 ; k < 2 ; k++){
                for(int l = -1 ; l < 2 ; l++){
                    if(i + k < 0 || i+k >=height){
                        continue;
                    }
                    if(j+l < 0 || j+l >=width){
                        continue;
                    }
                    Gx_red = Gx_red + temp[i+k][j+l].rgbtRed * Gx[k+1][l+1];
                    Gy_red = Gy_red + temp[i+k][j+l].rgbtRed * Gy[k+1][l+1];
                    Gx_blue = Gx_blue + temp[i+k][j+l].rgbtBlue * Gx[k+1][l+1];
                    Gy_blue = Gy_blue + temp[i+k][j+l].rgbtBlue * Gy[k+1][l+1];
                    Gx_green = Gx_green + temp[i+k][j+l].rgbtGreen * Gx[k+1][l+1];
                    Gy_green = Gy_green + temp[i+k][j+l].rgbtGreen * Gy[k+1][l+1];
                }
            }

            int red = round(sqrt(Gx_red*Gx_red+Gy_red*Gy_red));
            int green = round(sqrt(Gx_green*Gx_green+Gy_green*Gy_green));
            int blue = round(sqrt(Gx_blue*Gx_blue+Gy_blue*Gy_blue));

            if(red>255){
                red = 255;
            }
            if(green>255){
                green = 255;
            }
            if(blue>255){
                blue = 255;
            }

            image[i][j].rgbtRed = red;
            image[i][j].rgbtGreen = green;
            image[i][j].rgbtBlue = blue;
        }
    }
    return;
}