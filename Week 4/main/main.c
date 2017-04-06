#include <stdio.h>

int main(void)
{
    //different numbers set to two integers
    int firstInteger = 55, secondInteger = 22;

    //first display
    printf("The ratio between ");
    printf("%d", firstInteger);
    printf(" and ");
    printf("%d", secondInteger);
    printf(" is: ");
    printf("%f", (float)firstInteger/secondInteger);
    printf("\nAnd the modulus of the same numbers is: ");
    printf("%d", firstInteger%secondInteger);
    printf("\n\n");

    //display and scanning user's input integers
    printf("Input a number: \n");
    scanf("%d", &firstInteger);
    printf("Input a second number: \n");
    scanf("%d", &secondInteger);

    //division of user's integers
    int result = firstInteger/secondInteger;
    printf("Division of these two integers: ");
    printf("%d", result);

    //modulus of user's integers
    result = firstInteger%secondInteger;
    printf("\nModulus of these two integers: ");
    printf("%d", result);
    printf("\n\n");


    //floats for float division task
    float firstFloat, secondFloat;

    //display and scanning for float inputs
    printf("Input a float: ");
    scanf("%f", &firstFloat);
    printf("\nInput second float: ");
    scanf("%f", &secondFloat);

    //division display
    printf("Division result of these floats is: ");
    printf("%f", firstFloat/secondFloat);
    printf("\n\n");


    //char array for user's name
    char name[20];

    //string scan
    printf("What is your name?\n");
    scanf("%s", name);
    printf("Hello ");
    printf("%s", name);

    return 0;
}
