#include <stdio.h>
#include <string.h>

struct AccessRecord{
int customerID;
char domain[255];
char timestamp[20];
};

void TaskOne();
void PrintRecord ( struct AccessRecord R );
void AddRecord (struct AccessRecord A[], int *amount);
void ReadRecordsFromFile(struct AccessRecord A[], int *amount, char directory[]);
void SaveRecords(struct AccessRecord A[], int amount);
void PrintRecordsOfID(struct AccessRecord A[], int amount, int id);

int main()
{
    //uncomment function to test first task
    //TaskOne();

    struct AccessRecord A[100];
    int recordsAmount=0;

    while (1){
        printf("\nA) Add new record\nB) Display all the records\nC) Load records from a file\n");
        printf("D) Save records to the file\nE) Load saved records file\nF) Display certain user ID records\n\nQ) Quit program\n");

        //user inputs his choice
        char choice=' ';
        scanf(" %c", &choice);

        printf("\n");
        if (choice=='a' || choice=='A')
            AddRecord(A, &recordsAmount);
        else if (choice=='b' || choice=='B')
            //prints all records
            for (int i=0; i<recordsAmount; i++)
                PrintRecord(A[i]);
        else if (choice=='c' || choice=='C')
            //loads records from example file
            ReadRecordsFromFile(A, &recordsAmount,"E:\\Programming\\C\\UNI\\Week 10\\example_data.ipb");
        else if (choice=='d' || choice=='D')
            SaveRecords(A, recordsAmount);
        else if (choice=='E' || choice=='E')
            //loads records from user's saved records file
            ReadRecordsFromFile(A, &recordsAmount,"E:\\Programming\\C\\UNI\\Week 10\\saved_data.ipb");
        else if (choice=='F' || choice=='f'){
            printf("Provide user ID: ");
            int id;
            scanf("%d", &id);
            PrintRecordsOfID(A, recordsAmount, id);
        }
        else if  (choice=='q' || choice=='Q')
            break;
    }
    return 0;
}

// for task one - struct only has one value, not a struct array
void TaskOne()
{
    struct AccessRecord A;

    printf("\nWhat's the customer's ID: ");
    scanf("%i", &A.customerID);
    printf("What's the domain: ");
    scanf(" %s", &A.domain);
    printf("What's the date(e.g 2016-12-11 12:34:56): ");
    scanf(" %20[^\n]s", &A.timestamp);
    PrintRecord(A);
}

void PrintRecord ( struct AccessRecord R )
{
    printf ("%s: User %i visited %s\n",
        R.timestamp , R.customerID , R.domain ) ;
}

//adds a record to the records array
void AddRecord (struct AccessRecord A[], int *amount)
{
    printf("What's the customer's ID: ");
    scanf("%i", &A[*amount].customerID);
    printf("What's the domain: ");
    scanf(" %s", &A[*amount].domain);
    printf("What's the date(e.g 2016-12-11 12:34:56): ");
    scanf(" %20[^\n]s", &A[*amount].timestamp);
    *amount+=1;
}

//reads records from a specified file
void ReadRecordsFromFile(struct AccessRecord A[], int *amount, char directory[])
{
    FILE *reader;
    //opens a file from specified location
    reader = fopen(directory, "r");

    //reset amount value to zero

    for (int i=*amount; i<100; i++)
    {
        //scanning values to temporary variables
        int integer;
        fscanf(reader, "%d", &integer);
        char string1[255];
        fscanf(reader, "| %254[^|]s", string1);
        char string2[20];
        fscanf(reader, "| %19[^\n]s", string2);

        //if end of file, break scanning
        if (feof(reader)){
            break;
        }

        //temporary values copied to struct array
        A[i].customerID=integer;
        strcpy(A[i].domain, string1);
        strcpy(A[i].timestamp, string2);

        *amount+=1;
    }
    fclose(reader);
}

//saves all records currently saved in the struct array
void SaveRecords(struct AccessRecord A[], int amount)
{
    FILE *writer;
    writer = fopen("E:\\Programming\\C\\UNI\\Week 10\\saved_data.ipb", "w");

    for (int i=0; i<amount; i++)
    {
        fprintf(writer, "%d|%s|%s\n", A[i].customerID, A[i].domain, A[i].timestamp);
    }
    fclose(writer);
}

//prints records only of a certain customer
void PrintRecordsOfID(struct AccessRecord A[], int amount, int id)
{
    //if customer ID equals to the given specified ID, prints the record
    for (int i=0; i<amount; i++)
        if (A[i].customerID==id)
            PrintRecord(A[i]);
}
