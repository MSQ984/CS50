#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cs50.h>
#include <ctype.h>
int valid(int argc, string key[]){
    if(argc == 1){
        printf("Usage: ./substitution key\n");
        return 1;
    }
    else if(strlen(key[1]) != 26 ){
        printf("Please enter all 26 alphabets\n");
        return 1;
    }
    for(int i = 0, n =strlen(key[1]); i<n ; i++){
        if((int)key[1][i]<65 || (int)key[1][i]>90){
            if((int)key[1][i]<97 || (int)key[1][i]>122){
            return 1;
            }
        }
    }
    for(int i = 0, n =strlen(key[1]); i<n ; i++){
        for(int j = i+1; j<n ; j++){
            if(key[1][i] == key[1][j]){
                printf("Key must not contain repeated characters\n");
                return 1;
            }
        }
    }
    return 0;
}
int crypto(key[]){
    
}
int main(int argc, string key[]){
    int ans = valid(argc, key);
    if(ans != 0){
        return ans;
    }
    string plaintext=get_string("plaintext: ");
    printf("ciphertext: ");
    for(int i = 0, n = strlen(plaintext); i<n ; i++){
        if((int)plaintext[i] >= 65 && (int)plaintext[i] <= 90){
            int curr = (int)plaintext[i] - 65;
            char temp = toupper(key[1][curr]);
            printf("%c", temp);
        } 
        else if((int)plaintext[i] >= 97 && (int)plaintext[i] <= 122){
            int curr = (int)plaintext[i] - 97;
            char temp = tolower(key[1][curr]);
            printf("%c", temp);
        }
        else if((int)plaintext[i] == 32){
            printf(" ");
        }
        else{
            printf("%c", plaintext[i]);
        }
    }
    printf("\n");
}