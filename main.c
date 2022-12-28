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
        printf("\t\t-------------------YOU ARE VIEWING THE REVENUE----------------- \n\n");
        return 1;
    }
    else if(x==2)
    {
        printf("\t\t ---------------YOU ARE SEARCHING FOR TICKET BUYER'S INFORMATION------------------ \n\n");
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
        char slct1[500]="\n\n\t\tWhich option do you choose: \n\n\t\t1.Login\n\t\t2.Back\n\t\t\n";

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
                system("cls");
                printf("\n\n\n\n\t\tWhich option do you choose: \n");
                printf("\t\t1: Revenue calculation\n");
                printf("\t\t2: Search information\n");
                printf("\t\t3: See full invoice\n");
                printf("\t\t4: Create accounts for ticket masters.\n");
                printf("\t\t5: Delete passwords.\n");
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



                }
                else if(r==2)
                {
                    char searchName[20];
                    char word[50];
                    char ch;
                    int counter =0;
                    int pos[10];
                    int pointer =0;
                    int loop;
                    char filename[]="invoice.txt";

                    printf("Enter the name you want to search: ");
                    scanf("%s",searchName);

                    FILE* fptr;

                    fptr = fopen("invoice.txt", "r");

                    /*if(fptr!=NULL)
                    {
                        printf("file can not open.");
                    }*/

                    char search[50];
                    strcpy(search,searchName);

                    printf("Name: ");
                    do
                    {
                        ch = fscanf(fptr, "%s", word);
                        if(strcmp(word, search) == 0)
                        {
                            pos[counter] = pointer;
                            counter++;
                            puts(word);
                            break;
                        }
                        pointer++;

                    }
                    while (ch != EOF);

                    int count = 0;

                    if ( fptr != NULL )
                    {
                        char line[256]; /* or other suitable maximum line size */
                        while (fgets(line, sizeof line, fptr) != NULL) /* read a line */
                        {
                            if (count == counter)
                            {
                                //use line or in a function return it
                                //            //in case of a return first close the file with "fclose(file);"
                                printf("%s", line);
                                fclose(fptr);

                            }
                            else
                            {
                                count++;
                            }
                        }
                    }



                    fptr = fopen("invoice.txt", "r");

                    /*if(fptr!=NULL)
                    {
                        printf("file can not open.");
                    }*/

                    char search1[50];
                    strcpy(search1,searchName);

                    do
                    {
                        ch = fscanf(fptr, "%s", word);
                        if(strcmp(word, search1) == 0)
                        {
                            pos[counter] = pointer;
                            counter++;
                            break;
                        }
                        pointer++;

                    }
                    while (ch != EOF);

                    int count1 = 0;

                    if ( fptr != NULL )
                    {
                        char line[256]; /* or other suitable maximum line size */
                        while (fgets(line, sizeof line, fptr) != NULL) /* read a line */
                        {
                            if (count1 == counter)
                            {
                                //use line or in a function return it
                                //            //in case of a return first close the file with "fclose(file);"
                                printf("p");
                                printf("%s", line+1);
                                fclose(fptr);

                            }
                            else
                            {
                                count1++;
                            }
                        }
                    }

                    fclose(fptr);
                    if(counter==0)
                    {
                        printf("Error. The name you are searching for couldn't be found.");
                    }
                }
                else if(r==3)
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
                else if(r==4)
                {
                    for(int i=0; i<3; i++)
                    {
                        printf("\t\tCreate username for user %d: ",i+1);
                        fflush(stdin);
                        gets(tm[i].username);
                        printf("\t\tCreate password for user %d: ",i+1);
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
                    goto menu;


                    //goto menu;
                }
                else if(r==5)
                {
                    fclose(fopen("passwords.txt", "w"));
                }
                //goto menu;

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


        /*for(int i=0; i<3; i++)
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
        //goto menu;*/

        else if(r==2)
        {
            goto menu;
        }


    }

    else if(r==2)                                   //ticket master login
    {
        int r;
        printf("\t\tChoose an option\n\n\t\t\t1.Login\n\t\t\t2.Back\n");
        scanf("%d",&r);
        if(r==1)
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
                int revenue=ticket_price*passenger_num;



                FILE* fptr;

                fptr = fopen("revenue.txt", "a");


                char strRev[10];

                sprintf(strRev, "%d", revenue);
                // Now str contains the integer as characters


                // print our string
                fputs("Date: ",fptr);
                fprintf(fptr, "%s\n",date);
                fputs("The ticketmaster for the bus: ", fptr);
                fprintf(fptr, "%s\n",name);
                fputs("The profit for the day: ", fptr);
                fprintf(fptr, "%s\n",strRev);


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
            system("cls");
            printf("\n\n\t\t\t\t\tInformation saved successfully");
            goto menu;


        }
        else if(r==2)
        {
            system("cls");
            goto menu;

        }

    }

}
