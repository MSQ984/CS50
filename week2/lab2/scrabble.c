#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // TODO: Print the winner
    if(score1 == score2){
        printf("Tie!\n");
    }
    if(score1 > score2){
        printf("Player 1 wins!\n");
    }
    if(score1 < score2){
        printf("Player 2 wins!\n");
    }
}

int compute_score(string word)
{
    int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
    int sum = 0;
    for(int i = 0, n =strlen(word); i < n ; i++){
        if((int)word[i] <= 90 && (int)word[i] >= 65){
            sum+=(POINTS[(int)word[i]-65]);
        }
        
        else if((int)word[i] <= 122 && (int)word[i] >= 97){
            sum+=(POINTS[(int)word[i]-97]);
        }
        else{
            sum+=0;
        }
    }
    return sum;
}