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
#include <math.h>
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
void filters(char *,char*,int,int);
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
    //flightadd();
    flightinquiries();
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
    while (valid==0) {
        printf("Airline\n");
        printf("Currently supports the top ten airlines nationwide\n");
        scanf("%s",airline);
        scanf("%c",&phantom);
        if (strcmp(airline,"CA")==0||strcmp(airline,"MU")==0||strcmp(airline,"CZ")==0) {
            valid=1;
        }
        if (strcmp(airline,"HU")==0||strcmp(airline,"ZH")==0||strcmp(airline,"FM")==0) {
            valid=1;
        }
        if (strcmp(airline,"MF")==0||strcmp(airline,"3U")==0||strcmp(airline,"SC")==0) {
            valid=1;
        }
        if (strcmp(airline,"9C")==0) {
            valid=1;
        }
        if(valid==1&&phantom==' '){
            valid=0;
        }
    }
    
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
    char model[20],takeoff[15],landing[15];
    char phantom;
    char a[2];
    while(1)
    {   int valid=0;
        printf("(a)Model\n");
        printf("(b)Take off the city and landing city\n");
        printf("(c)Period\n");
        printf("(d)Flight number\n");
        printf("(e)Exit\n");
        scanf("%s",a);
        scanf("%c",&phantom);
        if(a[0]=='a')
        {   while (valid==0) {
            printf("Please enter the required model \n");
            scanf("%s",model);
            scanf("%c",&phantom);
            if(strcmp(model,"BY747")==0||strcmp(model,"BY767")==0|| strcmp(model,"BY777")==0){
                valid=1;
            }
            if(strcmp(model,"BY737")==0||strcmp(model,"BY738")==0|| strcmp(model,"TU5")==0){
                valid=1;
            }
            if(strcmp(model,"YN7")==0||strcmp(model,"AN4")==0){
                valid=1;
            }
            if(valid==1&&phantom==' '){
                valid=0;
            }
        }
            printf("(a)Filter by takeoff time\n");
            printf("(b)Filter by economy fares\n");
            printf("(c)Exit\n");
            scanf("%s",a);
            scanf("%c",&phantom);
            if(a[0]=='a')
            {filters(model,"",1, 1);
            }
            else if(a[0]=='b')
            {filters(model,"", 1, 2);
            }
            else if(a[0]=='c')
            {exit(1);}
        }
        
        else if(a[0]=='b')
        {   while (valid==0) {
            printf("Takeoff\n");
            printf("Requirements for domestic cities contain Airport\n");
            scanf("%s",takeoff);
            scanf("%c",&phantom);
            if (strcmp(takeoff,"Shenzhen")==0||strcmp(takeoff,"Dalian")==0||strcmp(takeoff,"Beijing")==0) {
                valid=1;
            }
            if(strcmp(takeoff,"Shantou")==0||strcmp(takeoff,"Xian")==0||strcmp(takeoff,"Shenyang")==0){
                valid=1;
            }
            if(strcmp(takeoff,"Fuzhou")==0||strcmp(takeoff,"Chengdu")==0||strcmp(takeoff,"Haikou")==0){
                valid=1;
            }
            if(strcmp(takeoff,"Xiamen")==0||strcmp(takeoff,"Tianjin")==0||strcmp(takeoff,"Qingdao")==0){
                valid=1;
            }
            if(strcmp(takeoff,"Hangzhou")==0||strcmp(takeoff,"Ningbo")==0||strcmp(takeoff,"Hangzhou")==0){
                valid=1;
            }
            if(strcmp(takeoff,"Wuhan")==0||strcmp(takeoff,"Wenzhou")==0||strcmp(takeoff,"Nanjing")==0){
                valid=1;
            }
            if(strcmp(takeoff,"Zhanjiang")==0|| strcmp(takeoff,"Harbin")==0||strcmp(takeoff,"Sanya")==0){
                valid=1;
            }
            if(strcmp(takeoff,"Guiyang")==0||strcmp(takeoff,"Beihai")==0||strcmp(takeoff,"Chongqing")==0){
                valid=1;
            }
            if(strcmp(takeoff,"Nantong")==0||strcmp(takeoff,"Jinan")==0||strcmp(takeoff,"Qinhuangdao")==0){
                valid=1;
            }
            if(strcmp(takeoff,"Shijiazhuang")==0||strcmp(takeoff,"Lianyungang")==0||strcmp(takeoff,"Changsha")==0){
                valid=1;
            }
            if(strcmp(takeoff,"Guilin")==0||strcmp(takeoff,"Hefei")==0||strcmp(takeoff,"Huangshan")==0){
                valid=1;
            }
            if(strcmp(takeoff,"Nanchang")==0||strcmp(takeoff,"Zhangjiajie")==0||strcmp(takeoff,"Taiyuan")==0){
                valid=1;
            }
            if(strcmp(takeoff,"Xishuangbanna")==0||strcmp(takeoff,"Hohhot")==0||strcmp(takeoff,"Luoyang")==0){
                valid=1;
            }
            if(strcmp(takeoff,"Zhengzhou")==0||strcmp(takeoff,"Dunhuang")==0||strcmp(takeoff,"Shanghai")==0){
                valid=1;
            }
            if(strcmp(takeoff,"Nanning")==0||strcmp(takeoff,"Kunming")==0|| strcmp(takeoff,"Kunming")==0){
                valid=1;
            }
            if (strcmp(takeoff,"Changchun")==0||strcmp(takeoff,"Zhuhai")==0) {
                valid=1;
            }
            if(valid==1&&phantom==' '){
                valid=0;
            }
        }
            while (valid==1) {
                printf("Landing\n");
                printf("Requirements for domestic cities contain Airport\n");
                scanf("%s",landing);
                scanf("%c",&phantom);
                if (strcmp(landing,"Shenzhen")==0||strcmp(landing,"Dalian")==0||strcmp(landing,"Beijing")==0) {
                    valid=0;
                }
                if(strcmp(landing,"Shantou")==0||strcmp(landing,"Xian")==0||strcmp(landing,"Shenyang")==0){
                    valid=0;
                }
                if(strcmp(landing,"Fuzhou")==0||strcmp(landing,"Chengdu")==0||strcmp(landing,"Haikou")==0){
                    valid=0;
                }
                if(strcmp(landing,"Xiamen")==0||strcmp(landing,"Tianjin")==0||strcmp(landing,"Qingdao")==0){
                    valid=0;
                }
                if(strcmp(landing,"Hangzhou")==0||strcmp(landing,"Ningbo")==0||strcmp(landing,"Hangzhou")==0){
                    valid=0;
                }
                if(strcmp(landing,"Wuhan")==0||strcmp(landing,"Wenzhou")==0||strcmp(landing,"Nanjing")==0){
                    valid=0;
                }
                if(strcmp(landing,"Zhanjiang")==0|| strcmp(landing,"Harbin")==0||strcmp(landing,"Sanya")==0){
                    valid=0;
                }
                if(strcmp(landing,"Guiyang")==0||strcmp(landing,"Beihai")==0||strcmp(landing,"Chongqing")==0){
                    valid=0;
                }
                if(strcmp(landing,"Nantong")==0||strcmp(landing,"Jinan")==0||strcmp(landing,"Qinhuangdao")==0){
                    valid=0;
                }
                if(strcmp(landing,"Shijiazhuang")==0||strcmp(landing,"Lianyungang")==0||strcmp(landing,"Changsha")==0){
                    valid=0;
                }
                if(strcmp(landing,"Guilin")==0||strcmp(landing,"Hefei")==0||strcmp(landing,"Huangshan")==0){
                    valid=0;
                }
                if(strcmp(landing,"Nanchang")==0||strcmp(landing,"Zhangjiajie")==0||strcmp(landing,"Taiyuan")==0){
                    valid=0;
                }
                if(strcmp(landing,"Xishuangbanna")==0||strcmp(landing,"Hohhot")==0||strcmp(landing,"Luoyang")==0){
                    valid=0;
                }
                if(strcmp(landing,"Zhengzhou")==0||strcmp(landing,"Dunhuang")==0||strcmp(landing,"Shanghai")==0){
                    valid=0;
                }
                if(strcmp(landing,"Nanning")==0||strcmp(landing,"Kunming")==0|| strcmp(landing,"Kunming")==0){
                    valid=0;
                }
                if (strcmp(landing,"Changchun")==0||strcmp(landing,"Zhuhai")==0) {
                    valid=0;
                }
                if(valid==0&&strcmp(takeoff, landing)==0){
                    valid=1;
                }
                if(valid==0&&phantom==' '){
                    valid=1;
                }
            }
            printf("(a)Filter by takeoff time\n");
            printf("(b)Filter by economy fares\n");
            printf("(c)Exit\n");
            scanf("%s",a);
            scanf("%c",&phantom);
            if(a[0]=='a')
            {filters(takeoff,landing,3, 1);
            }
            else if(a[0]=='b')
            {filters(takeoff,landing, 3, 2);
            }
            else if(a[0]=='c')
            {exit(1);}
            
        }
        else if(a[0]=='c')
        {
        }
        else if(a[0]=='d')
        {
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
        {
        }
        else if(a[0]=='b')
        {
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
        {
        }
        else if(a[0]=='b')
        {flightadd();
        }
        else if(a[0]=='c')
        {exit(1);}
    }
    
}



void filters(char * COM,char * COMA,int x,int y){
    char Flightnumber[20],airline[15],takeoff[15],landing[15],departuretime[15],flighttime[15],modela[15],modelb[15],punctualityrate[15],pilotsa[15],pilotsb[15],firstfares[15],bussinessfares[15],economyfares[55],votes[15];
    char Flightnumbera[500][20],airlinea[500][15],takeoffa[500][15],landinga[500][15],departuretimea[500][15],flighttimea[500][15],modelaa[500][15],modelba[500][15],punctualityratea[500][15],pilotsaa[500][15],pilotsba[500][15],firstfaresa[500][15],bussinessfaresa[500][15],economyfaresa[500][55],votesa[500][15];
    char Comparison[55],Comparisonb[55],Comparisonc[55],Comparisond[55],tempa[55],tempb[55],tempc[55],tempd[55],tempe[55],tempf[55],tempg[55],temph[55],tempi[55],tempj[55],tempk[55],templ[55],tempm[55],tempn[55],tempo[55];
    FILE *infile;
    int k=0;
    infile=fopen("flight.txt","r");
    if(infile==NULL){
        printf("system error\n");
        exit(1);
    }
    strcpy(Comparison, COM);
    strcpy(Comparisond, COMA);
    while(fscanf(infile,"%s %s %s %s %s %s %s %s %s %s %s %s %s %s %s",Flightnumber,takeoff,landing,departuretime,flighttime,modela,modelb,punctualityrate,firstfares,bussinessfares,economyfares,airline,votes,pilotsa,pilotsb)!=EOF){
        if(x==1){
            strcpy(Comparisonb, modelb);
        }
        if(x==2){
            strcpy(Comparisonb, airline);
        }
        if(x==3){
            strcpy(Comparisonb, takeoff);
            strcpy(Comparisonc, landing);
        }
        if(x==4){
            strcpy(Comparisonb, Flightnumber);
        }
        
        if(strcmp(Comparisonb,Comparison)==0&&(x==1||x==2||x==4)){
            strcpy(Flightnumbera[k],Flightnumber);
            strcpy(airlinea[k],airline);
            strcpy(takeoffa[k],takeoff);
            strcpy(landinga[k],landing);
            strcpy(departuretimea[k],departuretime);
            strcpy(flighttimea[k],flighttime);
            strcpy(modelaa[k],modela);
            strcpy(modelba[k],modelb);
            strcpy(punctualityratea[k],punctualityrate);
            strcpy(pilotsaa[k],pilotsa);
            strcpy(pilotsba[k],pilotsb);
            strcpy(firstfaresa[k],firstfares);
            strcpy(bussinessfaresa[k],bussinessfares);
            strcpy(economyfaresa[k],economyfares);
            strcpy(votesa[k],votes);
            k++;
        }
        if(strcmp(Comparisonb,Comparison)==0&&x==3&&strcmp(Comparisonc,Comparisond)==0){
            strcpy(Flightnumbera[k],Flightnumber);
            strcpy(airlinea[k],airline);
            strcpy(takeoffa[k],takeoff);
            strcpy(landinga[k],landing);
            strcpy(departuretimea[k],departuretime);
            strcpy(flighttimea[k],flighttime);
            strcpy(modelaa[k],modela);
            strcpy(modelba[k],modelb);
            strcpy(punctualityratea[k],punctualityrate);
            strcpy(pilotsaa[k],pilotsa);
            strcpy(pilotsba[k],pilotsb);
            strcpy(firstfaresa[k],firstfares);
            strcpy(bussinessfaresa[k],bussinessfares);
            strcpy(economyfaresa[k],economyfares);
            strcpy(votesa[k],votes);
            k++;
        }
        
    }
    fclose(infile);
    if(y==1){
        for(int i=0;i<k-1;i++) {
            
            for(int j=i+1;j<k;j++){
                if(strcmp(departuretimea[i],departuretimea[j])>0){
                    
                    strcpy(tempa, Flightnumbera[i]);
                    strcpy(tempb, airlinea[i]);
                    strcpy(tempc, takeoffa[i]);
                    strcpy(tempd, landinga[i]);
                    strcpy(tempe, departuretimea[i]);
                    strcpy(tempf, flighttimea[i]);
                    strcpy(tempg, modelaa[i]);
                    strcpy(temph, modelba[i]);
                    strcpy(tempi, punctualityratea[i]);
                    strcpy(tempj, pilotsaa[i]);
                    strcpy(tempk, pilotsba[i]);
                    strcpy(templ, firstfaresa[i]);
                    strcpy(tempm, bussinessfaresa[i]);
                    strcpy(tempn, economyfaresa[i]);
                    strcpy(tempo, votesa[i]);
                    
                    strcpy(Flightnumbera[i], Flightnumbera[j]);
                    strcpy(airlinea[i], airlinea[j]);
                    strcpy(takeoffa[i], takeoffa[j]);
                    strcpy(landinga[i], landinga[j]);
                    strcpy(departuretimea[i], departuretimea[j]);
                    strcpy(flighttimea[i], flighttimea[j]);
                    strcpy(modelaa[i], modelaa[j]);
                    strcpy(modelba[i], modelba[j]);
                    strcpy(punctualityratea[i], punctualityratea[j]);
                    strcpy(pilotsaa[i], pilotsaa[j]);
                    strcpy(firstfaresa[i], firstfaresa[j]);
                    strcpy(bussinessfaresa[i], bussinessfaresa[j]);
                    strcpy(economyfaresa[i], economyfaresa[j]);
                    strcpy(votesa[i], votesa[j]);
                    strcpy(pilotsba[i], pilotsba[j]);
                    
                    strcpy(Flightnumbera[j], tempa);
                    strcpy(airlinea[j], tempb);
                    strcpy(takeoffa[j], tempc);
                    strcpy(landinga[j], tempd);
                    strcpy(departuretimea[j], tempe);
                    strcpy(flighttimea[j], tempf);
                    strcpy(modelaa[j], tempg);
                    strcpy(modelba[j], temph);
                    strcpy(punctualityratea[j], tempi);
                    strcpy(pilotsaa[j], tempj);
                    strcpy(pilotsba[j], tempk);
                    strcpy(firstfaresa[j], templ);
                    strcpy(bussinessfaresa[j], tempm);
                    strcpy(economyfaresa[j], tempn);
                    strcpy(votesa[j], tempo);
                    
                }
            }
        }
        for (int g=0; g<k; g++) {
            printf("%s %s %s %s %s %s %s %s %s %s %s %s %s %s %s\n",Flightnumbera[g],takeoffa[g],landinga[g],departuretimea[g],flighttimea[g],modelaa[g],modelba[g],punctualityratea[g],firstfaresa[g],bussinessfaresa[g],economyfaresa[g],airlinea[g],votesa[g],pilotsaa[g],pilotsba[g]);
        }
    }
    if(y==2){
        for(int i=0;i<k-1;i++) {
            
            for(int j=i+1;j<k;j++){
                if(atoi(economyfaresa[i])<atoi(economyfaresa[j])){
                    
                    strcpy(tempa, Flightnumbera[i]);
                    strcpy(tempb, airlinea[i]);
                    strcpy(tempc, takeoffa[i]);
                    strcpy(tempd, landinga[i]);
                    strcpy(tempe, departuretimea[i]);
                    strcpy(tempf, flighttimea[i]);
                    strcpy(tempg, modelaa[i]);
                    strcpy(temph, modelba[i]);
                    strcpy(tempi, punctualityratea[i]);
                    strcpy(tempj, pilotsaa[i]);
                    strcpy(tempk, pilotsba[i]);
                    strcpy(templ, firstfaresa[i]);
                    strcpy(tempm, bussinessfaresa[i]);
                    strcpy(tempn, economyfaresa[i]);
                    strcpy(tempo, votesa[i]);
                    
                    strcpy(Flightnumbera[i], Flightnumbera[j]);
                    strcpy(airlinea[i], airlinea[j]);
                    strcpy(takeoffa[i], takeoffa[j]);
                    strcpy(landinga[i], landinga[j]);
                    strcpy(departuretimea[i], departuretimea[j]);
                    strcpy(flighttimea[i], flighttimea[j]);
                    strcpy(modelaa[i], modelaa[j]);
                    strcpy(modelba[i], modelba[j]);
                    strcpy(punctualityratea[i], punctualityratea[j]);
                    strcpy(pilotsaa[i], pilotsaa[j]);
                    strcpy(firstfaresa[i], firstfaresa[j]);
                    strcpy(bussinessfaresa[i], bussinessfaresa[j]);
                    strcpy(economyfaresa[i], economyfaresa[j]);
                    strcpy(votesa[i], votesa[j]);
                    strcpy(pilotsba[i], pilotsba[j]);
                    
                    strcpy(Flightnumbera[j], tempa);
                    strcpy(airlinea[j], tempb);
                    strcpy(takeoffa[j], tempc);
                    strcpy(landinga[j], tempd);
                    strcpy(departuretimea[j], tempe);
                    strcpy(flighttimea[j], tempf);
                    strcpy(modelaa[j], tempg);
                    strcpy(modelba[j], temph);
                    strcpy(punctualityratea[j], tempi);
                    strcpy(pilotsaa[j], tempj);
                    strcpy(pilotsba[j], tempk);
                    strcpy(firstfaresa[j], templ);
                    strcpy(bussinessfaresa[j], tempm);
                    strcpy(economyfaresa[j], tempn);
                    strcpy(votesa[j], tempo);
                    
                }
            }
        }
        for (int g=0; g<k; g++) {
            printf("%s %s %s %s %s %s %s %s %s %s %s %s %s %s %s\n",Flightnumbera[g],takeoffa[g],landinga[g],departuretimea[g],flighttimea[g],modelaa[g],modelba[g],punctualityratea[g],firstfaresa[g],bussinessfaresa[g],economyfaresa[g],airlinea[g],votesa[g],pilotsaa[g],pilotsba[g]);
        }
        
    }
    if(y==3){
        for(int i=0;i<k-1;i++) {
            
            for(int j=i+1;j<k;j++){
                if(strcmp(landinga[i],landinga[j])>0){
                    
                    strcpy(tempa, Flightnumbera[i]);
                    strcpy(tempb, airlinea[i]);
                    strcpy(tempc, takeoffa[i]);
                    strcpy(tempd, landinga[i]);
                    strcpy(tempe, departuretimea[i]);
                    strcpy(tempf, flighttimea[i]);
                    strcpy(tempg, modelaa[i]);
                    strcpy(temph, modelba[i]);
                    strcpy(tempi, punctualityratea[i]);
                    strcpy(tempj, pilotsaa[i]);
                    strcpy(tempk, pilotsba[i]);
                    strcpy(templ, firstfaresa[i]);
                    strcpy(tempm, bussinessfaresa[i]);
                    strcpy(tempn, economyfaresa[i]);
                    strcpy(tempo, votesa[i]);
                    
                    strcpy(Flightnumbera[i], Flightnumbera[j]);
                    strcpy(airlinea[i], airlinea[j]);
                    strcpy(takeoffa[i], takeoffa[j]);
                    strcpy(landinga[i], landinga[j]);
                    strcpy(departuretimea[i], departuretimea[j]);
                    strcpy(flighttimea[i], flighttimea[j]);
                    strcpy(modelaa[i], modelaa[j]);
                    strcpy(modelba[i], modelba[j]);
                    strcpy(punctualityratea[i], punctualityratea[j]);
                    strcpy(pilotsaa[i], pilotsaa[j]);
                    strcpy(firstfaresa[i], firstfaresa[j]);
                    strcpy(bussinessfaresa[i], bussinessfaresa[j]);
                    strcpy(economyfaresa[i], economyfaresa[j]);
                    strcpy(votesa[i], votesa[j]);
                    strcpy(pilotsba[i], pilotsba[j]);
                    
                    strcpy(Flightnumbera[j], tempa);
                    strcpy(airlinea[j], tempb);
                    strcpy(takeoffa[j], tempc);
                    strcpy(landinga[j], tempd);
                    strcpy(departuretimea[j], tempe);
                    strcpy(flighttimea[j], tempf);
                    strcpy(modelaa[j], tempg);
                    strcpy(modelba[j], temph);
                    strcpy(punctualityratea[j], tempi);
                    strcpy(pilotsaa[j], tempj);
                    strcpy(pilotsba[j], tempk);
                    strcpy(firstfaresa[j], templ);
                    strcpy(bussinessfaresa[j], tempm);
                    strcpy(economyfaresa[j], tempn);
                    strcpy(votesa[j], tempo);
                }
            }
        }
        for (int g=0; g<k; g++) {
            printf("%s %s %s %s %s %s %s %s %s %s %s %s %s %s %s\n",Flightnumbera[g],takeoffa[g],landinga[g],departuretimea[g],flighttimea[g],modelaa[g],modelba[g],punctualityratea[g],firstfaresa[g],bussinessfaresa[g],economyfaresa[g],airlinea[g],votesa[g],pilotsaa[g],pilotsba[g]);
        }
        
    }
    if(y==4){
        for (int g=0; g<k; g++) {
            printf("%s %s %s %s %s %s %s %s %s %s %s %s %s %s %s\n",Flightnumbera[g],takeoffa[g],landinga[g],departuretimea[g],flighttimea[g],modelaa[g],modelba[g],punctualityratea[g],firstfaresa[g],bussinessfaresa[g],economyfaresa[g],airlinea[g],votesa[g],pilotsaa[g],pilotsba[g]);
        }
        
    }
    
    
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
    char Flightnumber[20],airline[15],takeoff[15],landing[15],departuretime[15],flighttime[15],firstseatnumber[55],bussinessseatnumber[55],economyseatnumber[55],modela[15],modelb[15],punctualityrate[15],pilotsa[15],pilotsb[15],firstfares[15],bussinessfares[15],economyfares[55],seat[55],determine[15],votes[15],Flightnumberb[20],pilotsaa[15],pilotsbb[15],departuretimea[15],departuretimeb[15],departuretimec[15];
    int valid=0;
    char phantom;
    FILE *infile;
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
        if(valid==1&&strlen(Flightnumber)!=6){
            valid=0;
        }
        if(valid==1&&phantom==' '){
            valid=0;
        }
        infile=fopen("flight.txt","r");
        if(infile==NULL){
            printf("system error\n");
            exit(1);
        }
        while(fscanf(infile,"%s %s %s %s %s %s %s %s %s %s %s %s %s %s %s",Flightnumberb,takeoff,landing,departuretime,flighttime,modela,modelb,punctualityrate,firstfares,bussinessfares,economyfares,airline,votes,pilotsa,pilotsb)!=EOF){
            if(valid==1&&strcmp(Flightnumber, Flightnumberb)==0){
                printf("Flight number already exists, please re-enter\n");
                valid=0;
            }
        }
        fclose(infile);
        
    }
    while (valid==1) {
        printf("Pilots A\n");
        scanf("%s",pilotsa);
        scanf("%c",&phantom);
        infile=fopen("flight.txt","r");
        if(infile==NULL){
            printf("system error\n");
            exit(1);
        }
        while(fscanf(infile,"%s %s %s %s %s %s %s %s %s %s %s %s %s %s %s",Flightnumberb,takeoff,landing,departuretime,flighttime,modela,modelb,punctualityrate,firstfares,bussinessfares,economyfares,airline,votes,pilotsaa,pilotsbb)!=EOF){
            if(strcmp(pilotsbb, pilotsa)==0||strcmp(pilotsaa, pilotsa)==0){
                strcpy(departuretimea, departuretime);
                if(strcmp(departuretimeb,departuretimea)<0){
                    strcpy(departuretimeb, departuretimea);
                }
            }
        }
        
        if(phantom!=' '){
            valid=0;
        }
    }
    while (valid==0) {
        printf("Pilots B\n");
        scanf("%s",pilotsb);
        scanf("%c",&phantom);
        infile=fopen("flight.txt","r");
        if(infile==NULL){
            printf("system error\n");
            exit(1);
        }
        while(fscanf(infile,"%s %s %s %s %s %s %s %s %s %s %s %s %s %s %s",Flightnumberb,takeoff,landing,departuretime,flighttime,modela,modelb,punctualityrate,firstfares,bussinessfares,economyfares,airline,votes,pilotsaa,pilotsbb)!=EOF){
            if(strcmp(pilotsbb, pilotsb)==0||strcmp(pilotsaa, pilotsb)==0){
                strcpy(departuretimea, departuretime);
                if(strcmp(departuretimec,departuretimea)<0){
                    strcpy(departuretimec, departuretimea);
                }
            }
        }
        fclose(infile);
        if(phantom!=' '){
            valid=1;
        }
        if(valid==1&&strcmp(pilotsb, pilotsa)==0){
            valid=0;
        }
    }
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
        if(valid==0&&strlen(departuretime)!=5){
            valid=1;
        }
        if(valid==0&&phantom==' '){
            valid=1;
        }
        if(valid==0&&abs(atoi(departuretime)-atoi(departuretimeb))<10){
            printf("The pilot is flying, please re-enter the flight time\n");
            valid=1;
        }
        if(valid==0&&abs(atoi(departuretime)-atoi(departuretimec))<10){
            printf("The pilot is flying, please re-enter the flight time\n");
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
        if(valid==1&&strlen(flighttime)!=5){
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
        if(valid==0&&strlen(punctualityrate)!=5){
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
                if(valid==1&&strlen(firstfares)!=5){
                    valid=0;
                }
            }
        }
        if(valid==1&&isdigit(firstfares[2])!=0){
            if(firstfares[3]!='.'||isdigit(firstfares[4])==0||isdigit(firstfares[5])==0){
                valid=0;
            }
            if(valid==1&&strlen(firstfares)!=6){
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
        if(isdigit(bussinessfares[2])==0&&bussinessfares[2]!='.'&&valid==0){
            valid=1;
        }
        if(valid==0&&bussinessfares[2]=='.'){
            if(isdigit(bussinessfares[3])==0||isdigit(bussinessfares[4])==0){
                valid=1;
            }
            if(valid==0&&strlen(bussinessfares)!=5){
                valid=1;
            }
        }
        if(valid==0&&isdigit(bussinessfares[2])!=0){
            if(bussinessfares[3]!='.'||isdigit(bussinessfares[4])==0||isdigit(bussinessfares[5])==0){
                valid=1;
            }
            if(valid==0&&strlen(bussinessfares)!=6){
                valid=1;
            }
        }
        if(valid==0&&phantom==' '){
            valid=1;
        }
    }
    while (valid==0) {
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
            if(valid==1&&strlen(economyfares)!=5){
                valid=0;
            }
        }
        if(valid==1&&isdigit(economyfares[2])!=0){
            if(economyfares[3]!='.'||isdigit(economyfares[4])==0||isdigit(economyfares[5])==0){
                valid=0;
            }
            if(valid==1&&strlen(economyfares)!=6){
                valid=0;
            }
        }
        if(valid==1&&phantom==' '){
            valid=0;
        }
    }
    while (valid==1) {
        printf("Airline\n");
        printf("Currently supports the top ten airlines nationwide\n");
        scanf("%s",airline);
        scanf("%c",&phantom);
        if (strcmp(airline,"CA")==0||strcmp(airline,"MU")==0||strcmp(airline,"CZ")==0) {
            valid=0;
        }
        if (strcmp(airline,"HU")==0||strcmp(airline,"ZH")==0||strcmp(airline,"FM")==0) {
            valid=0;
        }
        if (strcmp(airline,"MF")==0||strcmp(airline,"3U")==0||strcmp(airline,"SC")==0) {
            valid=0;
        }
        if (strcmp(airline,"9C")==0) {
            valid=0;
        }
        if(valid==0&&phantom==' '){
            valid=1;
        }
    }
    if(strcmp(modela,"large")==0){
        strcpy(votes, "360");
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
        strcpy(votes, "200");
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
        strcpy(votes, "100");
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
    while (valid==0) {
        printf("determine\n");
        printf("Make a change: determine or negative\n");
        scanf("%s",determine);
        scanf("%c",&phantom);
        if (strcmp(determine,"determine")==0||strcmp(determine,"negative")==0) {
            valid=1;
        }
        if(valid==1&&phantom==' '){
            valid=0;
        }
    }
    if(strcmp(determine,"determine")==0){
        infile=fopen("flight.txt","a+");
        if(infile==NULL){
            printf("system error\n");
            exit(1);
        }
        fprintf(infile,"%s %s %s %s %s %s %s %s %s %s %s %s %s %s %s\n",Flightnumber,takeoff,landing,departuretime,flighttime,modela,modelb,punctualityrate,firstfares,bussinessfares,economyfares,airline,votes,pilotsa,pilotsb);
        fclose(infile);
    }
}
