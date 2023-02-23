#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <stdio.h>
#include <math.h>

int main(void){
    string abc = get_string("TEXT: ");
    int letters = 0, words = 0, sentences = 0;
    for(int i = 0,n = strlen(abc); i<n ; i++){
        if( ((int)abc[i]>=65 && (int)abc[i]<=90) || ((int)abc[i]>=97 && (int)abc[i]<=122) ){
            letters++;
        }
        else if(abc[i] == ' '){
            if(i != 0){
                words++;
            }
        }
        else if((int)abc[i] == 46 || (int)abc[i] == 33 || (int)abc[i] == 63){
            sentences++;
            if(i == n-1){
                words++;
            }
        }
    }
    float lavgt = ((float)letters/(float)words)*10000;
    float savgt = ((float)sentences/(float)words)*10000;
    float lavg = floor(lavgt);
    float savg = floor(savgt);
    lavg = lavg/100;
    savg = savg/100;
    
    int index = round((0.0588*lavg) - (0.296*savg) - 15.8);
    if(index<1){
        printf("Before Grade 1\n");
    }
    else if(index>16){
        printf("Grade 16+\n");
    }
    else{
        printf("Grade %i\n", index);
    }
}