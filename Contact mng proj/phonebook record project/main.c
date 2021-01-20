//
//  main.c
//  phonebook record project
//
//  Created by Sathienpong Polachan on 22/11/2561 BE.
//  Copyright © 2561 Sathienpong Polachan. All rights reserved.
//

#include <stdio.h> //for standard input output and it is included in every c program
#include <stdlib.h> //for NULL
#include <curses.h> //for colours and EOF
#include <string.h> //for variable type
#include <unistd.h>

#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define YELLOW  "\x1b[33m"
#define BLUE    "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN    "\x1b[36m"
#define RESET   "\x1b[0m"


struct person
{
    char name[35];
    char address[50];
    char mble_no[20];
    char sex[8];
    char mail[50];
    char citizen_id[20];
    
};
struct person p;
int i,found;
char name[35];
FILE *confile, *fp;

void add_contact();
void show_list();
void delete_contact();
void modify_contact();
void search_contact();
void quit();
void passlogin();
void menu();

int main()
{
    system("clear");
    passlogin();
    menu();
}
// ************************************************ LOGIN **********************************************
void passlogin()
{
    char pass[10],password[10]="1"; // change password here
    
    printf(GREEN"\n\t\t\t !!!SECURITY SYSTEM!!!\n\n"RESET);
    printf(GREEN"\t\t\tPlese Enter password: ");
    scanf("%s"RESET,pass);
    
    if (strcmp(pass,password)==0)
    {
        printf(GREEN"\n\t\t\t    PASSWORD CORRECT \n\n\t\tWELCOME TO CONTACT MANAGEMENT SYSTEM :D:D \n"RESET);
        
        sleep(2);
        menu();
    }
    else
    {
        fflush(stdin); // clear buffer
        system("clear");
        printf(RED"\n\t\t\t !!!WRONG PASSWORD!!!\a\a\a\a\n\n================================================================================"RESET);
        passlogin();
    }
}

// ************************************************* MENU ******************************************************

void menu()
{
    char method;
    system("clear");
    printf("\t\t\tWELCOME TO CONTACT MANAGEMENT\n\n");
    printf("\t\t\t\t  ||MENU||\n\t================================================================\n");
    printf("\t(a).Add Contact   \t(l).Contact list   \t(d).Delete Contact  \n\t(m).Modify Contact \t(s).Search Contact \t(q).quit\n\t================================================================");
    printf("\n\tEnter your method number: ");
    scanf("%s",&method);
    switch(method)
    {
        case 'a':
            add_contact();
            break;
        case 'A':
            add_contact();
            break;
        case 'l':
            show_list();
            break;
        case 'L':
            show_list();
            break;
        case 'd':
            delete_contact();
            break;
        case 'D':
            delete_contact();
            break;
        case 'm':
            modify_contact();
            break;
        case 'M':
            modify_contact();
            break;
        case 's':
            search_contact();
            break;
        case 'S':
            search_contact();
            break;
        case 'q':
            quit();
            break;
        case 'Q':
            quit();
            break;
        default:
            printf(RED"Please enter method above !!!\a\a\a\n\n"RESET);
            sleep(1);
            menu();
    }
}

// ********************************************* ADD CONTACT *************************************************

void add_contact()
{
    system("clear");
//    struct person new_person;
    
    
    confile=fopen("contact.txt","a+");
    if (confile == NULL)
    {
        printf("File dose not exist\a\a");
        return;
    }
    printf("================================\nPlease complete this information form\n================================\n\n");
    printf("Please enter name: ");
    getchar();
    fgets(p.name,35,stdin);
    //fprintf(confile,"Name = %s",new_person.name);
    
    printf("Please enter address: ");
    fgets(p.address,50,stdin);
    //fprintf(confile,"Address = %s",new_person.address);
    
    printf("Please enter mobile number: ");
    fgets(p.mble_no,20,stdin);
    //fprintf(confile,"Mobile number = %d",*new_person.mble_no);
    
    printf("Please enter gender: ");
    fgets(p.sex,8,stdin);
    //fprintf(confile,"Gender = %s",new_person.sex);
    
    printf("Please enter E-mail: ");
    fgets(p.mail,100,stdin);
    //fprintf(confile,"E-mail = %s",new_person.mail);
    
    printf("Please enter citizen ID: ");
    fgets(p.citizen_id,20,stdin);
    //fprintf(confile,"Citizen Identify Number = %d",*new_person.citizen_id);
    
    fseek(stdin,0,SEEK_END);
    fseek(confile,0,SEEK_END);
    
    fprintf(confile,"================================================\nName = %s\nAddress = %s\nMobile No. = %s\nGender = %s\nMail = %s\nCitizen ID =  %s\n",p.name,p.address,p.mble_no,p.sex,p.mail,p.citizen_id);
    
    fclose(confile);
    printf("contact saved.\n\n");
    sleep(1);
    getchar();
    fseek(stdin,0,SEEK_END);
    system("clear");
    printf("Name       = %s\n",p.name);
    printf("Address    = %s\n",p.address);
    printf("Mobile No. = %s\n",p.mble_no);
    printf("Gender     = %s\n",p.sex);
    printf("E-mail     = %s\n",p.mail);
    printf("Citizen ID = %s\n",p.citizen_id);
    
    printf("\n\nEnter any key");
    getchar();
    fseek(stdin,0,SEEK_END);
    menu();
}

// ************************************************* SHOW LIST *********************************************

void show_list()
{
    system("clear");
    confile = fopen("contact.txt","r");
    if (confile == NULL)
    {
        system("clear");
        printf("\nfile opening error in listing\n\n");
        exit(1);
    }
    while(fread(&p,sizeof(p),1,confile)==1)
    {
        printf("\n\t\t================================\n\t\t\tLIST OF CONTACTS\n\t\t================================\n");

            printf("\n%s\n%s\n%s\n%s\n%s\n%s\n",p.name,p.address,p.mble_no,p.sex,p.mail,p.citizen_id);
        getchar();
    }
    fclose(confile);
    
    system("clear");
    printf("\nPress any key to continue\n");
    getchar();
    fflush(stdin);
    menu();
}

// **************************************************** QUIT ****************************************************

void quit()
{
    char ans;
    system("clear");
    printf("\tAre you sure you want to exit? \n\t[y] or [n]: ");
    scanf("%s",&ans);
    switch(ans)
    {
        case 'y':
            exit(1);
        case 'Y':
            exit(1);
        case 'n':
            menu();
        case 'N':
            menu();
        default:
            printf(RED"\tInvalid input\n\n"RESET);
            sleep(1);
            quit();
    }
    fflush(stdin);
}



// ************************************************** MODIFY CONTACT ****************************************

void modify_contact()
{
    int f=0;
    char method;
    system("clear");
    printf("\t\t\t===================================\n\t\t\t MODIFY CONTACT \n\t\t\t================================\n\n\n");
    printf("please enter name: ");
    getchar();
    fgets(name,35,stdin);
    
    confile = fopen("contact.txt","r");
    
    if (strcmp(p.name,(name))==0)
    {
        printf("Name is %s",p.name);
        printf("================================\nPlease complete this information form\n================================\n\n");
        printf("Please enter name: ");
        getchar();
        fgets(p.name,35,stdin);
        //fprintf(confile,"Name = %s",new_person.name);
        
        printf("Please enter address: ");
        fgets(p.address,50,stdin);
        //fprintf(confile,"Address = %s",new_person.address);
        
        printf("Please enter mobile number: ");
        fgets(p.mble_no,20,stdin);
        //fprintf(confile,"Mobile number = %d",*new_person.mble_no);
        
        printf("Please enter gender: ");
        fgets(p.sex,8,stdin);
        //fprintf(confile,"Gender = %s",new_person.sex);
        
        printf("Please enter E-mail: ");
        fgets(p.mail,100,stdin);
        //fprintf(confile,"E-mail = %s",new_person.mail);
        
        printf("Please enter citizen ID: ");
        fgets(p.citizen_id,20,stdin);
        //fprintf(confile,"Citizen Identify Number = %d",*new_person.citizen_id);
        fflush(stdin);
        fseek(confile,ftell(confile)-sizeof(p),0);
        fprintf(confile,"%s,%s,%s,%s,%s,%s\n",p.name,p.address,p.mble_no,p.sex,p.mail,p.citizen_id);
        fclose(confile);
        printf(GREEN"Contact saved!\a\n\n"RESET);
        fseek(stdin,0,SEEK_END);
        sleep(1);
        menu();
        f=1;
    }
    if (f==0)
    {
        printf(RED"Contact not found !!!!\a\a\n\n"RESET);
    LOOP:
        printf("Want to add contact or back to menu or quit the program ?\n\n [A] for add \n [M] for menu\n [Q] for quit\n Enter your method : ");
        scanf("%s",&method);
        
        
        switch(method)
        {
            case 'A':
                add_contact();
                break;
            case 'a':
                add_contact();
                break;
            case 'M':
                menu();
                break;
            case 'm':
                menu();
                break;
            case 'Q':
                quit();
                break;
            case 'q':
                quit();
                break;
            default:
                printf("Please enter method above!!!\n\n\a\a\a");
                goto LOOP;
        }
    }
}

// *************************************************** SEARCH CONTACT ******************************************

void search_contact()
{
    char method;
    system("clear");
    
    printf("\n\t\t================================\n\t\t\tSEARCH CONTACT\n\t\t================================\n\n");
    printf("Please enter name: ");
    getchar();
    fgets(name,35,stdin);
    
    confile = fopen("contact.txt","r");
    
    if (strcmp(p.name,(name))==0)
    {
        system("clear");
        printf("\n\nContact found!\n\n");
        printf("\nName = %s\nAdress = %s\nMobile No. = %s\nGender = %s\nE-mail = %s\nCitizen ID = %s\n",p.name,p.address,p.mble_no,p.sex,p.mail,p.citizen_id);
        printf("Enter any key to continue");
        getchar();
        menu();
    }
    else
    {
        printf(RED"contact not found !!!\n\n\a\a"RESET);
    LOOP:
        printf("Want to add contact or back to menu or quit the program ?\n\n [A] for add \n [M] for menu\n [Q] for quit\n Enter your method : ");
        scanf("%s",&method);
        
    
        switch(method)
        {
            case 'A':
                add_contact();
                break;
            case 'a':
                add_contact();
                break;
            case 'M':
                menu();
                break;
            case 'm':
                menu();
                break;
            case 'Q':
                quit();
                break;
            case 'q':
                quit();
                break;
            default:
                printf("Please enter method above!!!\n\n\a\a\a");
                goto LOOP;
        }
    }
}

// ************************************************** DELETE CONTACT *****************************************

void delete_contact()
{
    char method;
    system("clear");
    fflush(stdin);
    printf("\n\t\t================================\n\t\t\tDELETE CONTACT\n\t\t================================\n\n");
    printf("Enter name: ");
    getchar();
    fgets(name,35,stdin);
    
    confile = fopen("contact.txt","r");
    if(confile==NULL)
    {
        
        printf("CONTACT'S DATA NOT ADDED YET.");
        sleep(2);
        menu();
    }
    if (strcmp(p.name,(name))==0)
    {
        fp = fopen("temp.txt","w");
    
        while(fread(&p,sizeof(p),1,confile)!=0)
            if (strcmp(name,p.name)!=0)
            {
                fwrite(&p,sizeof(p),1,fp);
            }
        fclose(confile);
        fclose(fp);
    
        remove("contact.txt");
        rename("temp.txt","contact.txt");
        
        printf(GREEN"RECORD DELETED SUCCESSFULLY.\n\n"RESET);
        printf("enter any key to continue");
        getchar();
        fseek(stdin,0,SEEK_END);
        menu();
    }
    if (strcmp(p.name,(name))!=0)
    {
        printf(RED"Contact not found!!!\n\n\a\a\a"RESET);
    LOOP:
        printf("Want to add contact or back to menu or quit the program ?\n\n [A] for add \n [M] for menu\n [Q] for quit\n Enter your method : ");
        scanf("%s",&method);
        switch(method)
        {
            case 'A':
                add_contact();
                break;
            case 'a':
                add_contact();
                break;
            case 'M':
                menu();
                break;
            case 'm':
                menu();
                break;
            case 'Q':
                quit();
                break;
            case 'q':
                quit();
                break;
            default:
                printf("Please enter method above!!!\n\n\a\a\a");
                goto LOOP;
        }
        fseek(stdin,0,SEEK_END);
    }
}
