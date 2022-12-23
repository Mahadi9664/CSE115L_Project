#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<windows.h>

struct manager
{
    char username[20];
    char password[20];
};
struct ticketmaster
{
    char username[20];
    char password[20];
};

int rolechk(int x)
{
    printf("\t\t");
    scanf("%d",&x);
    printf("\e[1;1H\e[2J");
    printf("\n\n\n\n\n\n\t");
    if(x==1)
    {
        printf("\t\t-------------------YOU ARE HERE AS THE MANAGER------------------ \n\n\t\t\t\t****PLEASE ENTER THE FOLLOWING INFORMATION***\n\n");
        return 1;
    }
    else if(x==2)
    {
        printf("\t\t ---------------YOU ARE LOGGING IN AS A TICKET MASTER------------------ \n\n\t\t\t\t****PLEASE ENTER THE FOLLOWING INFORMATION***\n\n");
        return 2;

    }

}

void welcome()
{
    int i;
    char x=219;

    char c[50]="WELCOME TO BUS MANAGEMENT SYSTEM";
    printf("\n\n\n\n\n\n\t\t\t\t\t");
    for(i=0; i<=50; i++)
    {
        printf("%c",c[i]);
        Sleep(50);
    }

}

int logincheck(int x)
{
    printf("\t\t");
    scanf("%d",&x);
    printf("\e[1;1H\e[2J");
    printf("\n\n\n\n\n\n\t");
    if(x==1)
    {
        printf("\t\t\t---------------YOU ARE LOGGING IN AS THE MANAGER------------------ \n\n\t\t\t\t****PLEASE ENTER THE FOLLOWING INFORMATION***\n\n");
        return 1;
    }
    else if(x==2)
    {
        printf("\t---------------YOU ARE CREATING USERNAMES AND PASSWORDS FOR TICKETMASTERS------------------\n\n\t\t\t\t\t****PLEASE ENTER THE FOLLOWING INFORMATION***\n\n");
        return 2;

    }
}

void loadingBar()
{
    int i=1;
    char x=219;
    printf("\n\n\n\n\n\n");
    printf("\t\t\t\t\t\t");
    printf("Please wait...........\n\t\t\t\t\t\t");
    for(i=0; i<=20; i++)
    {
        printf("%c",x);
        Sleep(70);
    }
    system("cls");
}

int main()
{
    system("color 0b");
    struct manager m;
    struct ticketmaster tm[5];
    int role;
    int option;
    loadingBar();
    welcome();
    //asking user to enter role and taking input


    char content[1000];

    char slct[]="\n\n\t\tSELECT YOUR ROLE :\n\n\t\t1.Manager\n\t\t2.Ticketmaster\n\t\t\n";
    int i;
    for(i=0; i<=52; i++)
    {
        printf("%c",slct[i]);
        Sleep(40);
    }

    //printf("\n\n\t\tSELECT YOUR ROLE :\n\n\t\t1.Manager\n\t\t2.Ticketmaster\n\t\t");

    int r=rolechk(role);

    if(r==1)                                                                //MANAGER
    {
        char slct1[500]="\n\n\t\tWhich option do you choose: \n\n\t\t1.Login\n\t\t2.Create accounts for ticketmaster.\n\t\t\n";

        for(int i=0; i<=strlen(slct1); i++)
        {
            printf("%c",slct1[i]);
            Sleep(40);
        }

        int r=logincheck(option);

        if(r==1)                                            //MANAGER LOGIN
        {
            printf("\t\tEnter your username: ");
            fflush(stdin);
            gets(m.username);
            printf("\t\tEnter your password: ");
            fflush(stdin);
            gets(m.password);

            char str[]="admin";
            if(strcmp(m.username,str)==0 && strcmp(m.password,str)==0)
            {



                ///OKITAR CODE

                printf("\e[1;1H\e[2J");
                printf("Welcome.");             //the codes will go here
            }
        }

        else if(r==2)                                           //Create accounts
        {
            for(int i=0; i<3; i++)
            {
                printf("\tCreate username for user %d: ",i+1);
                fflush(stdin);
                gets(tm[i].username);
                printf("\tCreate password for user %d: ",i+1);
                fflush(stdin);
                gets(tm[i].password);

                FILE* fptr;

                fptr = fopen("passwords.txt", "a");

                fprintf(fptr, "%s",tm[i].username);
                fprintf(fptr, "%s\n",tm[i].password);


                fclose(fptr);
            }
        }

    }
    else if(r==2)                                   //ticket master login
    {
        struct manager n;
        char word[50];
        char ch;
        int count =0;
        int pos[10];
        int pointer =0;
        int loop;
        char filename[]="passwords.txt";

        tmpass:
        printf("\t\tEnter your username: ");
        fflush(stdin);
        gets(n.username);
        printf("\t\tEnter your password: ");
        fflush(stdin);
        gets(n.password);

        FILE* fptr;

        fptr = fopen("passwords.txt", "r");

        /*if(fptr!=NULL)
        {
            printf("file can not open.");
        }*/

        char search[50];
        strcpy(search,strcat(n.username,n.password));

        do
        {
            ch = fscanf(fptr, "%s", word);
            if(strcmp(word, search) == 0)
            {
                pos[count] = pointer;
                count++;
            }
            pointer++;
            //printf("%s",word);
        }
        while (ch != EOF);

        if(count == 0)
        {
            printf("\e[1;1H\e[2J");
            printf("\t\n\n\n\n\n\n\n\n\n");
            goto tmpass;
        }
        else
        {
            printf("WELCOME!!!");

                                                                    //ekhane okitar code jabe




        }

        fclose(fptr);
    }

}
