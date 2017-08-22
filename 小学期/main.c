//
//  main.c
//  小学期
//
//  Created by kingwang on 2017/8/17.
//  Copyright © 2017年 kingwang. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void registered();
void personal();
void administrator();
void userlogin();
void logins();
void administratorlogin();
char * userIDverification(char *);
char * administratorIDverification();
void userinterface();
void administratorinterface();
void flightinquiries();
void recommendation();
void userinformation();
void tickets();
void filter();
void record();
void modification();
void singleticket();
void multiplayerticketsn();
void ordermanagement();
void flightmanagement();
void flightadd();

int main()
{
    //registered();
    logins();
    return 0;
}


void registered(){
    char phantom;
    char code[10],a[2];
    while(1)
    {
        printf("(a)Individual user registration\n");
        printf("(b)Administrator registration\n");
        printf("(c)	Exit\n");
        scanf("%s",a);
        scanf("%c",&phantom);
        if(a[0]=='a')
        {personal();
        }
        else if(a[0]=='b')
        {   printf("Enter the administrator invitation code\n");
            scanf("%s",code);
            scanf("%c",&phantom);
            if(strcmp(code,"kingwang")==0){
                   administrator();
            }
            else{
                printf("Invitation code error\n");
            }
        }
        else if(a[0]=='c')
        {exit(1);}
    }
}




void personal(){
    char ID[20],name[15],gender[15],phone[15],password[15],mailbox[15],IDF[15];
    int valid=0;
    char phantom;
    char file[]=".txt";
    FILE *infile;
    while(valid==0){
        printf("User ID\n");
        printf("Length 6-10 characters\n");
        scanf("%s",ID);
        scanf("%c",&phantom);
        if(strlen(ID)>5&&strlen(ID)<11){
            valid=1;
        }
        for(int k=0;k<11&&valid==1;k++) {
            if(ispunct(ID[k])!=0){
                valid=0;
            }
        }
        strcpy(IDF, ID);
        strcat(IDF, file);
        infile=fopen(IDF,"r");
        if (valid==1&&infile!=NULL) {
            printf("ID already exists, please re-enter\n");
            valid=0;
        }
        if(valid==1&&phantom==' '){
            valid=0;
        }
    }
    printf("Name\n");
    scanf("%s",name);
    while (valid==1) {
        printf("Gender\n");
        printf("Please choose a man or a lady\n");
        scanf("%s",gender);
        scanf("%c",&phantom);
        if (strcmp(gender,"man")==0||strcmp(gender,"lady")==0) {
            valid=0;
        }
        if(valid==0&&phantom==' '){
            valid=1;
        }
    }
    while(valid==0){
        printf("Phone\n");
        printf("The telephone number should be 11 digits\n");
        scanf("%s",phone);
        scanf("%c",&phantom);
        valid=1;
        if(strlen(phone)!=11){
            valid=0;
        }
        for(int k=0;k<11&&valid==1;k++) {
            if(isdigit(phone[k])==0){
                valid=0;
            }
        }
        if(valid==1&&phantom==' '){
            valid=0;
        }
    }
    printf("Password\n");
    scanf("%s",password);
    while(valid==1){
        printf("Mailbox\n");
        printf("The correct format is ***@***.***\n");
        scanf("%s",mailbox);
        scanf("%c",&phantom);
        valid=0;
        if(strlen(mailbox)!=11){
            valid=1;
        }
        for(int k=0;k<3&&valid==0;k++) {
            if(isalpha(mailbox[k])==0){
                valid=1;
            }
        }
        if(valid==0 && mailbox[3]!='@'){
            valid=1;
        }
        for(int k=4;k<7&&valid==0;k++) {
            if(isalpha(mailbox[k])==0){
                valid=1;
            }
        }
        if(mailbox[7]!='.'&&valid==0){
            valid=1;
        }
        for(int k=8;k<11&&valid==0;k++) {
            if(isalpha(mailbox[k])==0){
                valid=1;
            }
        }
        if(valid==0&&phantom==' '){
            valid=1;
        }
    }
    strcpy(IDF, ID);
    strcat(IDF, file);
    infile=fopen(IDF,"a+" );
    if(infile==NULL){
        printf("system error\n");
        exit(1);
    }
    fprintf(infile,"%s %s %s %s %s %s",ID,name,gender,phone,password,mailbox);
    fclose(infile);
}




void administrator(){
    char IDA[20],name[15],gender[15],phone[15],password[15],mailbox[15],airline[15],IDF[15];
    int valid=0;
    char phantom;
    char file[]=".txt";
    FILE *infile;
    while(valid==0){
        printf("Administrator ID\n");
        printf("Length 6-10 characters\n");
        scanf("%s",IDA);
        scanf("%c",&phantom);
        if(strlen(IDA)>5&&strlen(IDA)<11){
            valid=1;
        }
        for(int k=0; k<11 && valid==1 ;k++) {
            if(ispunct(IDA[k])!=0){
                valid=0;
            }
        }
        strcpy(IDF, IDA);
        strcat(IDF, file);
        infile=fopen(IDF,"r");
        if (valid==1&&infile!=NULL) {
            printf("ID already exists, please re-enter\n");
            valid=0;
        }
        if(valid==1&&phantom==' '){
            valid=0;
        }
    }
    printf("Name\n");
    scanf("%s",name);
    while (valid==1) {
        printf("Gender\n");
        printf("Please choose a man or a lady\n");
        scanf("%s",gender);
        scanf("%c",&phantom);
        if (strcmp(gender,"man")==0||strcmp(gender,"lady")==0) {
            valid=0;
        }
        if(valid==0&&phantom==' '){
            valid=1;
        }
    }
    while(valid==0){
        printf("Phone\n");
        printf("The telephone number should be 11 digits\n");
        scanf("%s",phone);
        scanf("%c",&phantom);
        valid=1;
        if(strlen(phone)!=11){
            valid=0;
        }
        for(int k=0;k<11&&valid==1;k++) {
            if(isdigit(phone[k])==0){
                valid=0;
            }
        }
        if(valid==1&&phantom==' '){
            valid=0;
        }
    }
    printf("Password\n");
    scanf("%s",password);
    while(valid==1){
        printf("Mailbox\n");
        printf("The correct format is ***@***.***\n");
        scanf("%s",mailbox);
        scanf("%c",&phantom);
        valid=0;
        if(strlen(mailbox)!=11){
            valid=1;
        }
        for(int k=0;k<3&&valid==0;k++) {
            if(isalpha(mailbox[k])==0){
                valid=1;
            }
        }
        if(valid==0 && mailbox[3]!='@'){
            valid=1;
        }
        for(int k=4;k<7&&valid==0;k++) {
            if(isalpha(mailbox[k])==0){
                valid=1;
            }
        }
        if(mailbox[7]!='.'&&valid==0){
            valid=1;
        }
        for(int k=8;k<11&&valid==0;k++) {
            if(isalpha(mailbox[k])==0){
                valid=1;
            }
        }
        if(valid==0&&phantom==' '){
            valid=1;
        }
    }
    printf("Airline\n");
    scanf("%s",airline);
    strcpy(IDF, IDA);
    strcat(IDF, file);
    infile=fopen(IDF,"a+" );
    if(infile==NULL){
        printf("system error\n");
        exit(1);
    }
    fprintf(infile,"%s %s %s %s %s %s %s",IDA,name,gender,phone,password,mailbox,airline);
    fclose(infile);
}




void logins(){
    char phantom;
    char a[2];
    while(1)
    {
        printf("(a)Individual user login\n");
        printf("(b)Administrator login\n");
        printf("(c)	Exit\n");
        scanf("%s",a);
        scanf("%c",&phantom);
        if(a[0]=='a')
        {userlogin();
        }
        else if(a[0]=='b')
        {administratorlogin();
        }
        else if(a[0]=='c')
        {exit(1);}
    }
    
}



void userlogin(){
    char ID[15],password[15];
    int valid=0;
    char * IDpassword;
    printf("Please enter the user ID\n");
    scanf("%s",ID);
    IDpassword=userIDverification(ID);
    if(strcmp(IDpassword, "h")==0){
        printf("The user does not exist, please register.\n");
    }
    else{
        valid=1;
    }
    if(valid==1){
        printf("Please enter the user password\n");
        scanf("%s",password);
        if(strcmp(IDpassword,password)==0){
            printf("Welcome back!\n");
            userinterface();
        }
        else{
            printf("Password is wrong, please try again.\n");
        }
    }
}



void administratorlogin(){
    char ID[15],password[15];
    int valid=0;
    char * IDpassword;
    printf("Please enter the administrator ID\n");
    scanf("%s",ID);
    IDpassword=administratorIDverification();
    if(strcmp(IDpassword, "hoole")==0){
        printf("The administrator does not exist, please register.\n");
        valid=1;
    }
    if(valid==0){
        printf("Please enter the administrator password\n");
        scanf("%s",password);
        if(strcmp(IDpassword,password)==0){
            printf("Welcome back!\n");
            administratorinterface();
        }
        else{
            printf("Password is wrong, please try again.\n");
        }
    }
}




char * userIDverification(char * IDU){
    static char passwold[15];
    char ID[20],name[15],gender[15],phone[15],mailbox[15],pass[15];
    FILE *infile;
    char file[]=".txt";
    char IDF[20];
    char valid[]="h";
    strcpy(IDF, IDU);
    strcat(IDF, file);
    infile=fopen(IDF,"r");
    if (infile==NULL) {
        strcpy(passwold, valid);
    }
    else{
        fscanf(infile,"%s %s %s %s %s %s",ID,name,gender,phone,pass,mailbox);
        strcpy(passwold, pass);
    }
        return passwold;
}


char  * administratorIDverification(){
    static char passwold[15];
    char valid[]="hoole";
    int a=0;
    if(a==0){
        strcpy(passwold, valid);
        return passwold;
    }
    return passwold;
}


void userinterface(){
    char phantom;
    char a[2];
    while(1)
    {
        printf("(a)Flight inquiries\n");
        printf("(b)Popular city recommendation\n");
        printf("(c)Personal information\n");
        printf("(d)Tickets\n");
        printf("(e)Exit\n");
        scanf("%s",a);
        scanf("%c",&phantom);
        if(a[0]=='a')
        {flightinquiries();
        }
        else if(a[0]=='b')
        {recommendation();
        }
        else if(a[0]=='c')
        {userinformation();
        }
        else if(a[0]=='d')
        {tickets();
        }
        else if(a[0]=='e')
        {exit(1);}
    }
    

}


void administratorinterface(){
    char phantom;
    char a[2];
    while(1)
    {
        printf("(a)Order management\n");
        printf("(b)Flight Management\n");
        printf("(c)Personal information\n");
        printf("(d)Exit\n");
        scanf("%s",a);
        scanf("%c",&phantom);
        if(a[0]=='a')
        {ordermanagement();
        }
        else if(a[0]=='b')
        {flightmanagement();
        }
        else if(a[0]=='c')
        {modification();
        }
        else if(a[0]=='d')
        {exit(1);}
    }
    

}



void flightinquiries(){
    char phantom;
    char a[2];
    while(1)
    {
        printf("(a)Model\n");
        printf("(b)Take off the city\n");
        printf("(c)Period\n");
        printf("(d)Flight number\n");
        printf("(e)Exit\n");
        scanf("%s",a);
        scanf("%c",&phantom);
        if(a[0]=='a')
        {filter();
        }
        else if(a[0]=='b')
        {filter();
        }
        else if(a[0]=='c')
        {filter();
        }
        else if(a[0]=='d')
        {filter();
        }
        else if(a[0]=='e')
        {exit(1);}
    }

}


void recommendation(){
    char phantom;
    char a[2];
    while(1)
    {
        printf("(a)Flight price\n");
        printf("(b)Hot city\n");
        printf("(c)Exit\n");
        scanf("%s",a);
        scanf("%c",&phantom);
        if(a[0]=='a')
        {filter();
        }
        else if(a[0]=='b')
        {filter();
        }
        else if(a[0]=='c')
        {exit(1);}
    }

}


void userinformation(){
    char phantom;
    char a[2];
    while(1)
    {
        printf("(a)Ticket record\n");
        printf("(b)Information modification\n");
        printf("(c)Exit\n");
        scanf("%s",a);
        scanf("%c",&phantom);
        if(a[0]=='a')
        {record();
        }
        else if(a[0]=='b')
        {modification();
        }
        else if(a[0]=='c')
        {exit(1);}
    }
}


void tickets(){
    char phantom;
    char a[2];
    while(1)
    {
        printf("(a)Single ticket\n");
        printf("(b)Multiplayer ticketsn\n");
        printf("(c)Exit\n");
        scanf("%s",a);
        scanf("%c",&phantom);
        if(a[0]=='a')
        {singleticket();
        }
        else if(a[0]=='b')
        {multiplayerticketsn();
        }
        else if(a[0]=='c')
        {exit(1);}
    }
}

void ordermanagement(){
    char phantom;
    char a[2];
    while(1)
    {
        printf("(a)Check order\n");
        printf("(b)Statistics\n");
        printf("(c)Exit\n");
        scanf("%s",a);
        scanf("%c",&phantom);
        if(a[0]=='a')
        {singleticket();
        }
        else if(a[0]=='b')
        {multiplayerticketsn();
        }
        else if(a[0]=='c')
        {exit(1);}
    }

}


void flightmanagement(){
    char phantom;
    char a[2];
    while(1)
    {
        printf("(a)Flight inquiries\n");
        printf("(b)Flight add\n");
        printf("(c)Exit\n");
        scanf("%s",a);
        scanf("%c",&phantom);
        if(a[0]=='a')
        {filter();
        }
        else if(a[0]=='b')
        {flightadd();
        }
        else if(a[0]=='c')
        {exit(1);}
    }

}



void filter(){
    
}


void record(){
    
}


void modification(){
    
}


void singleticket(){
    
}


void multiplayerticketsn(){
    
}


void flightadd(){
    
}
