#include <stdio.h>
#include <cs50.h>
int main(void)
{
    string name = get_string("Whats is your name \n");
    printf("hello, world %s\n", name);
}