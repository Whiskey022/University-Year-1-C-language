#include <stdio.h>

int main()
{
    //variables
    char snailName[8][32];
    int snailTimeSeconds[8], snailTimeMinutes[8]={0};  //overall time
    int snailTimeSecondsLeg1[8], snailTimeSecondsLeg2[8], snailTimeSecondsLeg3[8], snailTimeSecondsLeg4[8];
    int count=0;            //how many snails there are

    printf("You will be allowed to input information for up to 8 snails.\n");
    printf("If you wish to stop, input '0' for a snail name\n");
    //loop for 8 snails info input
    while (count<8){
        //display and input
        printf("\nPlease provide snail's name: ");
        scanf("%31s", snailName[count]);
        //check if user wants to finish, if yes, breaks the loop
        if (snailName[count][0]=='0')
            break;

        printf("Please provide snail's time for the first 'leg': ");
        scanf("%d", &snailTimeSecondsLeg1[count]);
        printf("Please provide snail's time for the second 'leg': ");
        scanf("%d", &snailTimeSecondsLeg2[count]);
        printf("Please provide snail's time for the third 'leg': ");
        scanf("%d", &snailTimeSecondsLeg3[count]);
        printf("Please provide snail's time for the final 'leg': ");
        scanf("%d", &snailTimeSecondsLeg4[count]);
        count++;
    }

    //continue program only if there are more snails than 0
    if (count>0){

        //loop for finding snail times
        int index=0;        //index for arrays
        while (index<count){
            snailTimeSeconds[index]=snailTimeSecondsLeg1[index]+snailTimeSecondsLeg2[index]
            +snailTimeSecondsLeg3[index]+snailTimeSecondsLeg4[index];
            while(snailTimeSeconds[index]>=60){
                snailTimeSeconds[index]-=60;
                snailTimeMinutes[index]++;
            }
            index++;
        }

        //loop for results
        index=0;
        while(index<count){
            printf("\n");
            printf("%s", snailName[index]);
            printf(" finished in ");
            if(snailTimeMinutes[index]!=0){  //displays minutes if they are not 0
                printf("%d", snailTimeMinutes[index]);
                if(snailTimeMinutes[index]%10==1 && snailTimeMinutes[index]%100!=11) //checks if minutes plural
                    printf(" minute");
                else
                    printf(" minutes");
            }
            if(snailTimeSeconds[index]!=0){   //displays seconds if they are not 0
                if(snailTimeMinutes[index]!=0)  //writes "and" after minutes, if minutes were displayed
                    printf(" and ");
                printf("%d", snailTimeSeconds[index]);
                if(snailTimeSeconds[index]%10==1 && snailTimeSeconds[index]!=11)  //checks if seconds plural
                    printf(" second.");
                else
                    printf(" seconds.");
            }
            else
                printf(".");       //if seconds are equal to 0, write a dot after minutes
            index++;
        }

        //loop to find the quickest for 1st leg
        index=1;
        int fastestIndex=0;     //at first, the first time set to fastest
        while(index<count){
            if(snailTimeSecondsLeg1[index]<snailTimeSecondsLeg1[fastestIndex])
                fastestIndex=index;  //if new fastest time found, its index set to new one
            index++;
        }
        printf("\n\nFor the first leg, the fastest snail was ");
        printf("%s", snailName[fastestIndex]);

        //loop to find the quickest for 2nd leg
        index=1;
        fastestIndex=0;
        while(index<count){
            if(snailTimeSecondsLeg2[index]<snailTimeSecondsLeg2[fastestIndex])
                fastestIndex=index;
            index++;
        }
        printf("\nFor the second leg, the fastest snail was ");
        printf("%s", snailName[fastestIndex]);

        //loop to find the quickest for 3rd leg
        index=1;
        fastestIndex=0;
        while(index<count){
            if(snailTimeSecondsLeg3[index]<snailTimeSecondsLeg3[fastestIndex])
                fastestIndex=index;
            index++;
        }
        printf("\nFor the third leg, the fastest snail was ");
        printf("%s", snailName[fastestIndex]);

        //loop to find the quickest for 4th leg
        index=1;
        fastestIndex=0;
        while(index<count){
            if(snailTimeSecondsLeg4[index]<snailTimeSecondsLeg4[fastestIndex])
                fastestIndex=index;
            index++;
        }
        printf("\nFor the final leg, the fastest snail was ");
        printf("%s", snailName[fastestIndex]);

        //loop to find the overall fastest snail
        index=1;
        fastestIndex=0;
        while(index<count){
            //checks if it is the fastest time (less minutes, or equal minutes but less seconds)
            if(snailTimeMinutes[index]<snailTimeMinutes[fastestIndex] ||
            (snailTimeSeconds[index]<snailTimeSeconds[fastestIndex] && snailTimeMinutes[index]==snailTimeMinutes[fastestIndex]))
                fastestIndex=index;
            index++;
        }
        printf("\nOverall the fastest snail was ");
        printf("%s", snailName[fastestIndex]);

    }

    return 0;
}
