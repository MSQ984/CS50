#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int temp;
    int counter = 0;
    // TODO: Prompt for start size
    int startPop;
    do{
        startPop = get_int("Start size: ");
    }
    while (startPop < 9);
    // TODO: Prompt for end size
    int endPop;
    do{
        endPop = get_int("End size: ");
    }
    while(endPop < startPop);
    // TODO: Calculate number of years until we reach threshold
    while (endPop > startPop){
        temp = startPop;
        startPop += startPop/3;
        startPop -= temp/4;
        counter++;
    }
    // TODO: Print number of years
    printf("Years: %i\n",counter);
}