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

struct invoice
{
    char name[20];
    char email[40];
    char phone[20];
};

typedef struct invoice inv;

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

int mngrOptions(void)
{
    int x;
    printf("\t\t");
    scanf("%d",&x);
    printf("\e[1;1H\e[2J");
    printf("\n\n\n\n\n\n\t");
    if(x==1)
    {
        printf("\t\t-------------------YOU ARE VIEWING THE REVENUE----------------- \n\n"); //not working
        return 1;
    }
    else if(x==2)
    {
        printf("\t\t ---------------YOU ARE SEARCHING FOR TICKET INVOICE------------------ \n\n"); //notworking
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
        printf("\t\t\t---------------YOU ARE LOGGING IN AS THE MANAGER------------------ \n\n\t\t\t\t****PLEASE ENTER THE FOLLOWING INFORMATION***\n\n"); //notworking
        return 1;
    }
    else if(x==2)
    {
        printf("\t---------------YOU ARE CREATING USERNAMES AND PASSWORDS FOR TICKETMASTERS------------------\n\n\t\t\t\t\t****PLEASE ENTER THE FOLLOWING INFORMATION***\n\n"); //not working
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
    menu:
    for(i=0; i<=52; i++)
    {
        printf("%c",slct[i]);
        Sleep(40);
    }

    //printf("\n\n\t\tSELECT YOUR ROLE :\n\n\t\t1.Manager\n\t\t2.Ticketmaster\n\t\t");

    int r=rolechk(role);

    if(r==1)                                                                //MANAGER
    {
        char slct1[500]="\n\n\t\tWhich option do you choose: \n\n\t\t1.Login\n\t\t2.Create accounts for ticketmaster.\n\t\t3.Back\n\t\t\n";

        for(int i=0; i<=strlen(slct1); i++)
        {
            printf("%c",slct1[i]);
            Sleep(40);
        }

        int r=logincheck(option);

        if(r==1)                                            //MANAGER LOGIN
        {
            mngr:
            printf("\t\tEnter your username: ");
            fflush(stdin);
            gets(m.username);
            printf("\t\tEnter your password: ");
            fflush(stdin);
            gets(m.password);

            char str[]="admin";
            if(strcmp(m.username,str)==0 && strcmp(m.password,str)==0)
            {
                printf("Which option do you choose: \n");
                printf("1: Revenue calculation\n");
                printf("2: Invoice print\n");
                int r = mngrOptions();

                if(r==1)
                {
                    FILE *fp;
                    fp=fopen("revenue.txt","r");
                    char c;
                    while((c=getc(fp))!=EOF)
                    {
                        putchar(c);
                    }
                    fclose(fp);

                    //goto menu; //goes to main menu

                }
                else if(r==2)
                {
                    FILE *fp;
                    fp=fopen("invoice.txt","r");
                    char c;
                    while((c=getc(fp))!=EOF)
                    {
                        putchar(c);
                    }
                    fclose(fp);
                }

               //goto menu; //goes to main menu

            }
            else
            {
                printf("\e[1;1H\e[2J");
            printf("\t\n\n\n\n\n\n\n\n\n");
            printf("\t\tPlease enter the correct information and try again\n\n");
            Beep(800,1000);
            goto mngr; // beeps and goes to manager input if password is incorrect
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
            system("cls");
             printf("\n\n\tOperation completed sucsessfully");
              //goto menu;



        }
        else if(r==3)
        {
            goto menu;
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
            printf("\t\tPlease enter the correct information and try again\n\n");
            Beep(800,1000);
            goto tmpass; //beeps and goes to tm login page again
        }
        else
        {
            char date[30];
            char name[20];
            int passenger_num;
            int ticket_price;
            inv passengers[40];

            printf("\e[1;1H\e[2J");
            printf("\t\n\n\n\n\n\n\n\n\n\t\t\t\t");
            printf("Enter date: ");
            fflush(stdin);
            gets(date);
            printf("\t\t\t\t");
            printf("Enter name: ");
            fflush(stdin);
            gets(name);
            printf("\t\t\t\t");
            printf("Enter number of passengers today(cannot be over 40): ");
            scanf("%d",&passenger_num);
            printf("\t\t\t\t");
            printf("Enter the price for ticket today: ");
            scanf("%d",&ticket_price);

            FILE* fptr;

            fptr = fopen("revenue.txt", "a");
            //WARNING BUG HERE ***********************************************
            //*****************************************************************
            //*****************************************************************
            int revenue = ticket_price*passenger_num;

            char snumrev[2000];

            // convert 123 to string [buf]
            itoa(revenue, snumrev, 20);

            // print our string
            fputs("Date: ",fptr);
            fprintf(fptr, "%s\n",date);
            fputs("The ticketmaster for the bus: ", fptr);
            fprintf(fptr, "%s\n",name);
            fputs("The profit for the day: ", fptr);
            fprintf(fptr, "%s\n",snumrev);


            fclose(fptr);



            for(int i=0; i<passenger_num; i++)          //taking the input for invoice
            {
                printf("\e[1;1H\e[2J");
                printf("\t\n\n\n\n\n\n\n\n\n\t\t\t\t");
                printf("Enter name: ");
                fflush(stdin);
                gets(passengers[i].name);
                printf("\t\t\t\t");
                printf("Enter email: ");
                fflush(stdin);
                gets(passengers[i].email);
                printf("\t\t\t\t");
                printf("Enter phone number: ");
                fflush(stdin);
                gets(passengers[i].phone);

                FILE* fptr;

                fptr = fopen("invoice.txt", "a");

                fputs("Name: ",fptr);
                fprintf(fptr, "%s\n",passengers[i].name);
                fputs("Email: ",fptr);
                fprintf(fptr, "%s\n",passengers[i].email);
                fputs("Phone: ",fptr);
                fprintf(fptr, "%s\n",passengers[i].phone);


                fclose(fptr);

            }


        }



    }

}
