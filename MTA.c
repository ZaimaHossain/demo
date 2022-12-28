#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void printWelcomeMessage();
int checkUserID(int id);
int validateUser(int id, int PIN);



struct User
{
    int userID;
    char name[30];
    int PIN;
    float balance;
};

struct User users[1000];
int noOfUser;

void printWelcomeMessage()
{
    printf("\t * * * * * * * * * * * * * * * *");
    printf("\n\n\t *   WELCOME to our Mini ATM   *");
    printf("\n\n\t * * * * * * * * * * * * * * * *\n\n");
}


int checkUserID(int id)
{
    int i;
    for(i=0; i<noOfUser; i++)
    {
        if(users[i].userID == id)
            return i;
    }
    return -1;
}

int validateUser(int id, int PIN)
{
    int i=checkUserID(id);
    if(i==-1)
        return 0;
    if(users[i].PIN == PIN)
        return 1;

    return 0;
}

void optionsMenu()
{
    int opt;
    printf("Please choose one of the options below\n\n");
    printf("1. Balance inquiry\n");
    printf("2. Cash deposit\n");
    printf("3. Cash withdrawal\n");
    printf("4. PIN change\n");
    printf("0. Exit");
}

float checkBalance()
{

}
int main()
{
    FILE* ptr;

    ptr = fopen("UserInfo.txt", "r");


    int i=0;
    while(fscanf(ptr, "%d %s %d %f", &users[i].userID, &users[i].name, &users[i].PIN, &users[i].balance) == 4)
    {
        i++;
    }
    noOfUser = i;

    printWelcomeMessage();


    int userId, pin;

    while(1)
    {
        printf("Please enter your user id: ");
        scanf("%d", &userId);
        int idx = checkUserID(userId);

        if(idx>=0)
        {

            while(1)
            {
                printf("\nEnter your 4 digit PIN: ");
                scanf("%d", &pin);
                if(validateUser(userId, pin))
                {
                    printf("\nWelcome %s to Brac bank\n", users[idx].name);

                    //Do transaction here



                    break;
                }
                else
                {
                    printf("\nInvalid PIN\n");
                }
            }

            break;
        }
        else
        {
            printf("\nNo user found\n");
        }
    }


    fclose(ptr);
    return 0;
}
