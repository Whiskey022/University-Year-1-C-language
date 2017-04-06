#include <stdio.h>

//week 7 functions
char GradeFromPercentage(float percentage);
char GradeFromRawMarks(float marksAwarded, float marksAvailable);
char GradeFromTotalRawMarks(float marksAwarded[], float marksAvailable[], int maxAssignments);
int CheckCase (char a, char b);

//week 8 functions
void DisplayAllRawMarks(float marksAwarded[ ], float marksAvailable[ ], int maxAssignments);
void EditAssignment(float marksAwarded[ ], float marksAvailable[ ], int position);
void AddAssignment(float marksAwarded[ ], float marksAvailable[ ], int *max);
void RemoveAssignment(float marksAwarded[ ], float marksAvailable[ ], int position, int *max);


int main()
{
    char userInput = '?'; // some place to store input from the user
    int max = 0; // the maximum assignment count (i.e. how many assignements we have
    float marksAwarded[100]; // place to store the marks
    float marksAvailable[100]; // place to store the available marks
    // Since we've not got any code to add new assignments yet,
    // here's some test assignments manually assigned.
    /* Testing code: default assignment scores */
    {
        marksAwarded[0] = 10; marksAvailable[0] = 10;
        marksAwarded[1] = 7; marksAvailable[1] = 11;
        marksAwarded[2] = 5; marksAvailable[2] = 11;
        marksAwarded[3] = 3; marksAvailable[3] = 11;
        marksAwarded[4] = 0; marksAvailable[4] = 100;
        max = 5; // update how many items we have
    }
    /* End of testing code */
    while(1) // forever
    {
        // Print the main menu
        printf("\nA) Display Marks\nB) Edit Assignment\nC) Add Assignment\nD) Remove Assignment\n\nQ) Quit\n\n>");
        // Grab the option from the user
        scanf(" %c", &userInput);
        if(CheckCase(userInput, 'A'))
        {
            // Display all the marks we have
            DisplayAllRawMarks(marksAwarded, marksAvailable, max);
        }
        if(CheckCase(userInput, 'B'))
        {
            int position;
            printf("Which assignment to edit?(1-%d)\n>", max);
            scanf("%d", &position);
            EditAssignment(marksAwarded, marksAvailable, position-1);
        }
        if(CheckCase(userInput, 'C'))
        {
            AddAssignment(marksAwarded, marksAvailable, &max);
        }
        if(CheckCase(userInput, 'D'))
        {
            int position;
            printf("Which assignment to remove?(1-%d)\n>", max);
            scanf("%d", &position);
            RemoveAssignment(marksAwarded, marksAvailable, position-1, &max);
        }
        if(CheckCase(userInput, 'Q'))
        {
            // If 'Q' or 'q' entered, break out of the while loop
            break;
        }
        // Keep going around the while loop if the user didn't quit
    }
    return 0;
}


////////////////////////////// week 8 functions

void DisplayAllRawMarks(float marksAwarded[ ], float marksAvailable[ ], int maxAssignments)
{
    //displays all marks
    for (int i=0; i<maxAssignments; i++){
        printf("%f out of %f.\n", marksAwarded[i], marksAvailable[i]);
        printf("Grade %c.\n", GradeFromRawMarks(marksAwarded[i], marksAvailable[i]));
    }
    //displays overall grade
    printf("\nOverall class grade: %c\n", GradeFromTotalRawMarks(marksAwarded, marksAvailable, maxAssignments));
}

void EditAssignment(float marksAwarded[ ], float marksAvailable[ ], int position)
{
    printf("Provide a new mark\n>");
    scanf("%f", &marksAwarded[position]);
    printf("Provide a new maximum available mark\n>");
    scanf("%f", &marksAvailable[position]);
}

void AddAssignment(float marksAwarded[ ], float marksAvailable[ ], int *max)
{
    printf("Provide a mark\n>");
    scanf("%f", &marksAwarded[*max]);
    printf("Provide a maximum available mark\n>");
    scanf("%f", &marksAvailable[*max]);
    //max increased
    *max+=1;
}

void RemoveAssignment(float marksAwarded[ ], float marksAvailable[ ], int position, int *max)
{
    //moves all values back from the position set
    for (int i=position; i<*max; i++){
        marksAwarded[i]=marksAwarded[i+1];
        marksAvailable[i]=marksAvailable[i+1];
    }
    //lowers array size
    *max-=1;
}



///////////////////////// week 7 functions

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


