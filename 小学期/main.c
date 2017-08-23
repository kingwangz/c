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
#include <stdlib.h>

void registered();
void personal();
void administrator();
void userlogin();
void logins();
void administratorlogin();
char * userIDverification(char *);
char * administratorIDverification(char *);
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
    //logins();
    flightadd();
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
    char file[]="a.txt";
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
    IDpassword=administratorIDverification(ID);
    if(strcmp(IDpassword, "h")==0){
        printf("The administrator does not exist, please register.\n");
    }
    else{
        valid=1;
    }
    if(valid==1){
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
        fclose(infile);
    }
        return passwold;
}


char  * administratorIDverification(char * IDA){
    static char passwold[15];
    char ID[20],name[15],gender[15],phone[15],mailbox[15],pass[15];
    FILE *infile;
    char file[]="a.txt";
    char IDF[20];
    char valid[]="h";
    strcpy(IDF, IDA);
    strcat(IDF, file);
    infile=fopen(IDF,"r");
    if (infile==NULL) {
        strcpy(passwold, valid);
    }
    else{
        fscanf(infile,"%s %s %s %s %s %s",ID,name,gender,phone,pass,mailbox);
        strcpy(passwold, pass);
        fclose(infile);
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
    char Flightnumber[20],airline[15],takeoff[15],landing[15],departuretime[15],flighttime[15],firstseatnumber[55],bussinessseatnumber[55],economyseatnumber[55],modela[15],modelb[15],punctualityrate[15],pilots[15],firstfares[15],bussinessfares[15],economyfares[15],seat[55];
    int valid=0,votes;
    char phantom;
    while (valid==0) {
        printf("Flightnumbel\n");
        printf("Requires two letters four digits\n");
        scanf("%s",Flightnumber);
        scanf("%c",&phantom);
        if (isalpha(Flightnumber[0])!=0&&isalpha(Flightnumber[1])!=0){
            valid=1;
        }
        for(int k=2;k<6&&valid==1;k++) {
            if(isdigit(Flightnumber[k])==0){
                valid=0;
            }
        }
        if(valid==1&&phantom==' '){
            valid=0;
        }
    }
    printf("Airline\n");
    scanf("%s",airline);
    while (valid==1) {
        printf("Takeoff\n");
        printf("Requirements for domestic cities contain Airport\n");
        scanf("%s",takeoff);
        scanf("%c",&phantom);
        if (strcmp(takeoff,"Shenzhen")==0||strcmp(takeoff,"Dalian")==0||strcmp(takeoff,"Beijing")==0) {
            valid=0;
        }
        if(strcmp(takeoff,"Shantou")==0||strcmp(takeoff,"Xian")==0||strcmp(takeoff,"Shenyang")==0){
            valid=0;
        }
        if(strcmp(takeoff,"Fuzhou")==0||strcmp(takeoff,"Chengdu")==0||strcmp(takeoff,"Haikou")==0){
            valid=0;
        }
        if(strcmp(takeoff,"Xiamen")==0||strcmp(takeoff,"Tianjin")==0||strcmp(takeoff,"Qingdao")==0){
            valid=0;
        }
        if(strcmp(takeoff,"Hangzhou")==0||strcmp(takeoff,"Ningbo")==0||strcmp(takeoff,"Hangzhou")==0){
            valid=0;
        }
        if(strcmp(takeoff,"Wuhan")==0||strcmp(takeoff,"Wenzhou")==0||strcmp(takeoff,"Nanjing")==0){
            valid=0;
        }
        if(strcmp(takeoff,"Zhanjiang")==0|| strcmp(takeoff,"Harbin")==0||strcmp(takeoff,"Sanya")==0){
            valid=0;
        }
        if(strcmp(takeoff,"Guiyang")==0||strcmp(takeoff,"Beihai")==0||strcmp(takeoff,"Chongqing")==0){
            valid=0;
        }
        if(strcmp(takeoff,"Nantong")==0||strcmp(takeoff,"Jinan")==0||strcmp(takeoff,"Qinhuangdao")==0){
            valid=0;
        }
        if(strcmp(takeoff,"Shijiazhuang")==0||strcmp(takeoff,"Lianyungang")==0||strcmp(takeoff,"Changsha")==0){
            valid=0;
        }
        if(strcmp(takeoff,"Guilin")==0||strcmp(takeoff,"Hefei")==0||strcmp(takeoff,"Huangshan")==0){
            valid=0;
        }
        if(strcmp(takeoff,"Nanchang")==0||strcmp(takeoff,"Zhangjiajie")==0||strcmp(takeoff,"Taiyuan")==0){
            valid=0;
        }
        if(strcmp(takeoff,"Xishuangbanna")==0||strcmp(takeoff,"Hohhot")==0||strcmp(takeoff,"Luoyang")==0){
            valid=0;
        }
        if(strcmp(takeoff,"Zhengzhou")==0||strcmp(takeoff,"Dunhuang")==0||strcmp(takeoff,"Shanghai")==0){
            valid=0;
        }
        if(strcmp(takeoff,"Nanning")==0||strcmp(takeoff,"Kunming")==0|| strcmp(takeoff,"Kunming")==0){
            valid=0;
        }
        if (strcmp(takeoff,"Changchun")==0||strcmp(takeoff,"Zhuhai")==0) {
            valid=0;
        }
        if(valid==0&&phantom==' '){
            valid=1;
        }
    }
    while (valid==0) {
        printf("Landing\n");
        printf("Requirements for domestic cities contain Airport\n");
        scanf("%s",landing);
        scanf("%c",&phantom);
        if (strcmp(landing,"Shenzhen")==0||strcmp(landing,"Dalian")==0||strcmp(landing,"Beijing")==0) {
            valid=1;
        }
        if(strcmp(landing,"Shantou")==0||strcmp(landing,"Xian")==0||strcmp(landing,"Shenyang")==0){
            valid=1;
        }
        if(strcmp(landing,"Fuzhou")==0||strcmp(landing,"Chengdu")==0||strcmp(landing,"Haikou")==0){
            valid=1;
        }
        if(strcmp(landing,"Xiamen")==0||strcmp(landing,"Tianjin")==0||strcmp(landing,"Qingdao")==0){
            valid=1;
        }
        if(strcmp(landing,"Hangzhou")==0||strcmp(landing,"Ningbo")==0||strcmp(landing,"Hangzhou")==0){
            valid=1;
        }
        if(strcmp(landing,"Wuhan")==0||strcmp(landing,"Wenzhou")==0||strcmp(landing,"Nanjing")==0){
            valid=1;
        }
        if(strcmp(landing,"Zhanjiang")==0|| strcmp(landing,"Harbin")==0||strcmp(landing,"Sanya")==0){
            valid=1;
        }
        if(strcmp(landing,"Guiyang")==0||strcmp(landing,"Beihai")==0||strcmp(landing,"Chongqing")==0){
            valid=1;
        }
        if(strcmp(landing,"Nantong")==0||strcmp(landing,"Jinan")==0||strcmp(landing,"Qinhuangdao")==0){
            valid=1;
        }
        if(strcmp(landing,"Shijiazhuang")==0||strcmp(landing,"Lianyungang")==0||strcmp(landing,"Changsha")==0){
            valid=1;
        }
        if(strcmp(landing,"Guilin")==0||strcmp(landing,"Hefei")==0||strcmp(landing,"Huangshan")==0){
            valid=1;
        }
        if(strcmp(landing,"Nanchang")==0||strcmp(landing,"Zhangjiajie")==0||strcmp(landing,"Taiyuan")==0){
            valid=1;
        }
        if(strcmp(landing,"Xishuangbanna")==0||strcmp(landing,"Hohhot")==0||strcmp(landing,"Luoyang")==0){
            valid=1;
        }
        if(strcmp(landing,"Zhengzhou")==0||strcmp(landing,"Dunhuang")==0||strcmp(landing,"Shanghai")==0){
            valid=1;
        }
        if(strcmp(landing,"Nanning")==0||strcmp(landing,"Kunming")==0|| strcmp(landing,"Kunming")==0){
            valid=1;
        }
        if (strcmp(landing,"Changchun")==0||strcmp(landing,"Zhuhai")==0) {
            valid=1;
        }
        if(valid==1&&strcmp(takeoff, landing)==0){
            valid=0;
        }
        if(valid==1&&phantom==' '){
            valid=0;
        }
    }
    while (valid==1) {
        printf("Departuretime\n");
        printf("Match the time format hh:mm\n");
        scanf("%s",departuretime);
        scanf("%c",&phantom);
        if(isdigit(departuretime[0])!=0&&isdigit(departuretime[1])!=0){
            valid=0;
        }
        if(valid==0&&(departuretime[0]>'2'||departuretime[1]>'3')){
            valid=1;
        }
        if(valid==0&&departuretime[2]!=':'){
            valid=1;
        }
        if(valid==0&&(isdigit(departuretime[3])==0||isdigit(departuretime[4])==0)){
            valid=1;
        }
        if(valid==0&&departuretime[3]>'6'){
            valid=1;
        }
        if(valid==0&&departuretime[3]=='6'&&departuretime[4]!='0'){
            valid=1;
        }
        if(valid==0&&phantom==' '){
            valid=1;
        }
    }
    while (valid==0) {
        printf("Flighttime\n");
        printf("Match the time format hh:mm\n");
        scanf("%s",flighttime);
        scanf("%c",&phantom);
        if(isdigit(flighttime[0])!=0&&isdigit(flighttime[1])!=0){
            valid=1;
        }
        if(valid==1&&flighttime[2]!=':'){
            valid=0;
        }
        if(valid==1&&(isdigit(flighttime[3])==0||isdigit(flighttime[4])==0)){
            valid=0;
        }
        if(valid==1&&flighttime[3]>'6'){
            valid=0;
        }
        if(valid==1&&flighttime[3]=='6'&&flighttime[4]!='0'){
            valid=0;
        }
        if(valid==1&&phantom==' '){
            valid=0;
        }
    }
    while (valid==1) {
        printf("Model\n");
        printf("Choose models: large, medium and small\n");
        scanf("%s",modela);
        scanf("%c",&phantom);
        if(strcmp(modela,"large")==0||strcmp(modela,"medium")==0||strcmp(modela,"small")==0){
            valid=0;
        }
        if(valid==0&&phantom==' '){
            valid=1;
        }
    }
    while (valid==0) {
        printf("Model\n");
        if(strcmp(modela,"large")==0){
            printf("Choose models: BY747,BY767,BY777\n");
            scanf("%s",modelb);
            scanf("%c",&phantom);
            if(strcmp(modelb,"BY747")==0||strcmp(modelb,"BY767")==0|| strcmp(modelb,"BY777")==0){
                valid=1;
            }
            if(valid==1&&phantom==' '){
                valid=0;
            }
        }
        else if(strcmp(modela,"medium")==0){
            printf("Choose models: BY737,BY738,TU5\n");
            scanf("%s",modelb);
            scanf("%c",&phantom);
            if(strcmp(modelb,"BY737")==0||strcmp(modelb,"BY738")==0|| strcmp(modelb,"TU5")==0){
                valid=1;
            }
            if(valid==1&&phantom==' '){
                valid=0;
            }
        }
        else{
            printf("Choose models: YN7,AN4\n");
            scanf("%s",modelb);
            scanf("%c",&phantom);
            if(strcmp(modelb,"YN7")==0||strcmp(modelb,"AN4")==0){
                valid=1;
            }
            if(valid==1&&phantom==' '){
                valid=0;
            }
        }
    }
    while (valid==1) {
        printf("Punctualityrate\n");
        printf("According to the percentage format: xx.x%% \n");
        scanf("%s",punctualityrate);
        scanf("%c",&phantom);
        if(isdigit(punctualityrate[0])!=0&&isdigit(punctualityrate[1])!=0){
            valid=0;
        }
        if(valid==0&&punctualityrate[2]!='.'){
            valid=1;
        }
        if(valid==0&&isdigit(punctualityrate[3])==0){
            valid=1;
        }
        if(valid==0&&punctualityrate[4]!='%'){
            valid=1;
        }
        if(valid==0&&phantom==' '){
            valid=1;
        }
    }
    while (valid==0) {
        printf("FirstClass pilots\n");
        printf("According  format: xxx.xx \n");
        scanf("%s",firstfares);
        scanf("%c",&phantom);
        if(isdigit(firstfares[0])!=0&&isdigit(firstfares[1])!=0){
            valid=1;
        }
        if(isdigit(firstfares[2])==0&&firstfares[2]!='.'&&valid==1){
            valid=0;
        }
        if(valid==1&&firstfares[2]=='.'){
            if(isdigit(firstfares[3])==0||isdigit(firstfares[4])==0){
                valid=0;
            }
        }
        if(valid==1&&isdigit(firstfares[2])!=0){
            if(flighttime[3]!='.'||isdigit(firstfares[4])==0||isdigit(firstfares[5])==0){
                valid=0;
            }
        }
        if(valid==1&&phantom==' '){
            valid=0;
        }
    }
    while (valid==1) {
        printf("BussinessseatClass pilots\n");
        printf("According  format: xxx.xx \n");
        scanf("%s",bussinessfares);
        scanf("%c",&phantom);
        if(isdigit(bussinessfares[0])!=0&&isdigit(bussinessfares[1])!=0){
            valid=0;
        }
        if(isdigit(bussinessfares[2])==0&&bussinessfares[2]!='.'&&valid==1){
            valid=1;
        }
        if(valid==0&&bussinessfares[2]=='.'){
            if(isdigit(bussinessfares[3])==0||isdigit(bussinessfares[4])==0){
                valid=1;
            }
        }
        if(valid==0&&isdigit(bussinessfares[2])!=0){
            if(bussinessfares[3]!='.'||isdigit(bussinessfares[4])==0||isdigit(bussinessfares[5])==0){
                valid=1;
            }
        }
        if(valid==0&&phantom==' '){
            valid=1;
        }
    }  while (valid==0) {
        printf("EconomyClass pilots\n");
        printf("According  format: xxx.xx \n");
        scanf("%s",economyfares);
        scanf("%c",&phantom);
        if(isdigit(economyfares[0])!=0&&isdigit(economyfares[1])!=0){
            valid=1;
        }
        if(isdigit(economyfares[2])==0&&economyfares[2]!='.'&&valid==1){
            valid=0;
        }
        if(valid==1&&economyfares[2]=='.'){
            if(isdigit(economyfares[3])==0||isdigit(economyfares[4])==0){
                valid=0;
            }
        }
        if(valid==1&&isdigit(economyfares[2])!=0){
            if(economyfares[3]!='.'||isdigit(economyfares[4])==0||isdigit(economyfares[5])==0){
                valid=0;
            }
        }
        if(valid==1&&phantom==' '){
            valid=0;
        }
    }
    if(strcmp(modela,"large")==0){
        votes=360;
        for(int i=0;i<55;i++){
            firstseatnumber[i]='F';
        }
        for(int i=0;i<55;i++){
            bussinessseatnumber[i]='C';
        }
        for(int i=0;i<55;i++){
            economyseatnumber[i]='Y';
        }
        for(int i=0;i<55;i=i+6){
            seat[i]='a';
            seat[i+1]='b';
            seat[i+2]='c';
            seat[i+3]='d';
            seat[i+4]='e';
            seat[i+5]='f';
        }
        
    }
    if(strcmp(modela,"medium")==0){
        votes=200;
        for(int i=0;i<55;i++){
            firstseatnumber[i]='F';
        }
        for(int i=0;i<55;i++){
            bussinessseatnumber[i]='C';
        }
        for(int i=0;i<55;i++){
            economyseatnumber[i]='Y';
        }
        for(int i=0;i<55;i=i+6){
            seat[i]='a';
            seat[i+1]='b';
            seat[i+2]='c';
            seat[i+3]='d';
            seat[i+4]='e';
            seat[i+5]='f';
        }
    }
    if(strcmp(modela,"small")==0){
        votes=100;
        for(int i=0;i<55;i++){
            firstseatnumber[i]='F';
        }
        for(int i=0;i<55;i++){
            bussinessseatnumber[i]='C';
        }
        for(int i=0;i<55;i++){
            economyseatnumber[i]='Y';
        }
        for(int i=0;i<55;i=i+6){
            seat[i]='a';
            seat[i+1]='b';
            seat[i+2]='c';
            seat[i+3]='d';
            seat[i+4]='e';
            seat[i+5]='f';
        }
    }
    printf("Pilots\n");
    scanf("%s",pilots);
   
}
