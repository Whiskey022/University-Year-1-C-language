#include <stdio.h>

char GradeFromPercentage(float percentage);
char GradeFromRawMarks(float marksAwarded, float marksAvailable);
char GradeFromTotalRawMarks(float marksAwarded[], float marksAvailable[], int maxAssignments);
int CheckCase (char a, char b);

int main()
{
    //arrays for marks awarded and marks available
    float marksAwarded[100], marksAvailable[100];
    char finished='n';  //char for user input if the program is finished
    int index;//index for the loop, and the index will be used to identify the amount of assignments
    //loop maximum until 100, or until user says he is finished
    for (index=0; index<100 && finished!='y'; index++){
        printf("Please input an awarded mark: ");
        scanf("%f", &marksAwarded[index]);
        printf("Please input the maximum available mark: ");
        scanf("%f", &marksAvailable[index]);
        printf("Finished? (y/n)");
        scanf(" %c",&finished);
    }
    //prints the grade
    printf("Overall class grade: %c", GradeFromTotalRawMarks(marksAwarded, marksAvailable, index));
    return 0;
}

char GradeFromPercentage(float percentage)
{
    if (percentage>=90)
        return 'A';
    else if (percentage>=70)
        return 'B';
    else if (percentage>=50)
        return 'C';
    else if (percentage>=30)
        return 'D';
    else
        return 'F';

}

char GradeFromRawMarks(float marksAwarded, float marksAvailable)
{
    return GradeFromPercentage((marksAwarded/marksAvailable)*100);
}
char GradeFromTotalRawMarks(float marksAwarded[], float marksAvailable[], int maxAssignments)
{
    //floats for sum of marks awarded and available
    float totalAwarded=0, totalAvailable=0;
    //loop to calculate sums
    for (int i=0; i<maxAssignments; i++){
        totalAwarded+=marksAwarded[i];
        totalAvailable+=marksAvailable[i];
    }
    //sums used in GradeFromRawMarks function to get the grade
    return GradeFromRawMarks(totalAwarded, totalAvailable);
}

int CheckCase (char a, char b)
{
    if(!isupper(a))
        a-=32;
    if(a==b)
        return 1;
    else
        return 0;
}
