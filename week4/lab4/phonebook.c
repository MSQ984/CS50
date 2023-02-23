#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void){
    FILE *contacts = fopen("contacts.csv", "a");
    if(contacts == NULL){
        return 1;
    }
    char *name = get_string("Name: ");
    char *number = get_string("Number: ");
    fprintf(contacts, "%s,%s\n", name, number);
    fclose(contacts);
}