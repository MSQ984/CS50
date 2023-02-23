#include<stdio.h>
#include<cs50.h>
int main(void){
    long long int cardNumber = -1;
    while(cardNumber<10000){
        cardNumber = get_long("Number: ");
    }
    long long int final = cardNumber;
    int counter = 1;
    int odd = 0;
     long long int even =0;
    int temp = 0;
    while(cardNumber != 0){
        if(counter%2 == 0){
            temp = cardNumber%10;
            if(temp*2 == 10){
                even+=1;
            }
            else if(temp*2 == 12){
                even+=3;
            }
            else if(temp*2 == 14){
                even+= 5;
            }
            else if(temp*2 == 16){
                even+= 7;
            }
            else if(temp*2 == 18){
                even+= 9;
            }
            else if(temp*2 == 20){
                even+= 2;
            }
            if(temp*2 <= 9){
                even+=temp*2;
            }
            
        }
        if(counter%2 != 0){
            temp = cardNumber%10;
            odd += temp;
        }
        counter++;
        cardNumber=cardNumber/10;
    }
    int total = odd + even;
    long int visa13, visa16, amex, masterCard;
    visa13 = final/1000000000000;
    visa16 = final/1000000000000000;
    amex = final/10000000000000;
    masterCard = final/100000000000000;
    if(total%10 == 0){
        if(visa13 == 4 || visa16 == 4){
            printf("VISA\n");
        }
        if(amex == 34 || amex == 37){
            printf("AMEX\n");
        }
        if(masterCard == 51 || masterCard == 52 || masterCard == 53 || masterCard == 54 || masterCard == 55){
            printf("MASTERCARD\n");
        }
    }
    if(total%10 > 0){
        printf("INVALID\n");
    }
}