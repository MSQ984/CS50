#include <stdio.h>
#include <cs50.h>
int main(void){
    int height = 0;
    do
    {
        height = get_int("Height: ");
    }
    while(height <1 || height > 8);
    for(int i = 1 ; i<height+1 ; i++){
        for(int j = 0; j<(height-i) ; j++){
            printf(" ");
        }
        for( int k = 0 ; k < i ; k++){
            printf("#");
        }
        printf("  ");
        for( int l = 0 ; l < i ; l++){
            printf("#");
        }
        printf("\n");
    }
}