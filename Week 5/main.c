#include <stdio.h>

int main(void)
{
    //variables for snail's name and finish time
    char snailName[32];
    int snailTimeSeconds, snailTimeMinutes = 0;

    //display and input for name and time
    printf("Please provide snail's name: ");
    scanf("%31s", snailName);
    printf("Please provide snail's time in seconds: ");
    scanf("%d", &snailTimeSeconds);

    //converting seconds to minutes and seconds
    while(snailTimeSeconds>=60){
        snailTimeSeconds-=60;
        snailTimeMinutes++;
    }

    //results print
    printf("\n");
    printf("%s", snailName);
    printf(" finished in ");
    printf("%d", snailTimeMinutes);
    printf(" minutes and ");
    printf("%d", snailTimeSeconds);
    printf(" seconds.\n\n\n");

    //1 meter race
    //times for 4 parts of 1 meter 'legs'
    int snailTimeSecondsPart1, snailTimeSecondsPart2, snailTimeSecondsPart3, snailTimeSecondsPart4;

    //resetting snail time
    snailTimeMinutes=0;
    snailTimeSeconds=0;

    //display and scanning
    printf("Please provide snail's name: ");
    scanf("%31s", snailName);
    printf("Please provide snail's time for the first 'leg': ");
    scanf("%d", &snailTimeSecondsPart1);
    printf("Please provide snail's time for the second 'leg': ");
    scanf("%d", &snailTimeSecondsPart2);
    printf("Please provide snail's time for the third 'leg': ");
    scanf("%d", &snailTimeSecondsPart3);
    printf("Please provide snail's time for the final 'leg': ");
    scanf("%d", &snailTimeSecondsPart4);

    //adding all 4 times
    snailTimeSeconds=snailTimeSecondsPart1+snailTimeSecondsPart2+snailTimeSecondsPart3+snailTimeSecondsPart4;

    //converting time into minutes and seconds
    while(snailTimeSeconds>=60){
        snailTimeSeconds-=60;
        snailTimeMinutes++;
    }

    //displaying result
    printf("\n");
    printf("%s", snailName);
    printf(" finished in ");
    printf("%d", snailTimeMinutes);
    printf(" minutes and ");
    printf("%d", snailTimeSeconds);
    printf(" seconds.\n");


    //display for snail's qualification result
    printf("%s", snailName);
    //checking if its faster than 4 minutes
    if(snailTimeMinutes<4)
        printf(" did qualify for the International Tournament, with a time of ");
    else if(snailTimeMinutes<12)
        printf(" did qualify for the National Race Meeting, with a time of ");
    else if(snailTimeMinutes<30)
        printf(" did qualify for the Beginner's League, with a time of ");
    else
        printf(" did not qualify for anything, with a time of ");
    printf("%d", snailTimeMinutes);
    printf(" minutes and ");
    printf("%d", snailTimeSeconds);
    printf(" seconds.\n\n\n");


    return 0;
}
