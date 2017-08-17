//
//  main.c
//  小学期
//
//  Created by kingwang on 2017/8/17.
//  Copyright © 2017年 kingwang. All rights reserved.
//

#include <stdio.h>
#include<stdlib.h>
#include <ctype.h>
#include<string.h>
#include<time.h>

void idnum();
void math();
void watch();
int isvalidInt(char val[]);
int i,a,b;
int n=0;
int cost;
char p;
char val[10];
FILE *stu;
struct comp
{
    int w;
    char e;
    int r;
    char y[5];
    int z;
}num[10];
int main()
{
    char a;
    idnum();
    while(i==1)
    {   printf("(a)	Start a test\n");
        printf("(b)	Check scores\n");
        printf("(c)	Exit\n");
        scanf("%c",&a);
        if(a=='a')
        { math();}
        else if(a=='b')
        {printf("\n____________________\n");
            printf("YOURID| RESULT| TIMR\n");
            watch();}
        else if(a=='c')
        {exit(1);}
        
    }
    
    return 0;
}









void idnum() {
    printf("Enter an ID number:\n");
    scanf("%s",val);
    scanf("%c",&p);
    while(isvalidInt(val)==0)
    {   printf("Illegal input!\n");
        printf("(a)Enter an ID number:\n");
        printf("(b)Exit\n");
        scanf("%s",val);
        scanf("%c",&p);
        if(val[0]=='b')
            break;}
    if(isvalidInt(val)==1)
    { i=1;
        printf("pass!\n");
        printf("Your ID number is:%s\n",val);}
}





int isvalidInt(char val[])
{     int valid=0;
    int k=2;
    if(isalpha(val[0])!=0&&isalpha(val[1])!=0)
        valid=1;
    while(valid==1&&k<6)
    { if(isdigit(val[k])==0)
    { valid=0;}
        k++;}
    if(valid==1&&strlen(val)!=6)
    { valid=0;}
    if(valid==1&&p==' ')
    {valid=0;}
    return valid;
}




void math()
{  int g;int u=0;
    int  t,e, k,n = 0,l=1,w=0;
    char c[5];
    char s='a',r,o;
    printf("Start:\n");
    time_t timer;
    struct tm *tblock;
    time_t start ,end ;
    int cost;
    time(&start);
    srand((unsigned)time(0));
    //srand( (int) clock()* time(NULL) );
    while (l<=10)
    { printf("The %d topic:\n",l);
        w=1+(int)rand()%4;
        a = (int)rand() % 99;
        b = (int)rand() %99;
        k=0;
        switch (w)
        {
            case 1:
                while(k==0)
                {a = (int)rand() % 99;
                    b = (int)rand() %99;
                    if(a*b>0&&a*b<100)
                    {k=1;}}
                s='*';
                t=a * b;
                break;
            case 2:
                while(k==0)
                {a = (int)rand() % 99;
                    b = 1+(int)rand() % 99;
                    if(a>b&&a%b==0)
                    {k=1;}}
                s='/';
                t=a/ b;
                break;
            case 3:
                while(k==0)
                { a = (int)rand() % 99;
                    b = (int)rand() % 99;
                    if(a+b<100)
                    {k=1;}}
                s='+';
                t = a + b;
                break;
            case 4:
                while(k==0)
                { a = (int)rand() % 99;
                    b = (int)rand() % 99;
                    if(a>b)
                    {k=1;}}
                s='-';
                t = a - b;
                break;
            default:
                printf("Error");
                exit(1);
        }     printf("%d%c%d=", a, s, b);
        scanf("%s", c);
        num[u].w=a;
        num[u].e=s;
        num[u].r=b;
        num[u].y[0]=c[0];
        num[u].y[1]=c[1];
        num[u].z=t;
        u++;
        
        while (isdigit(c[0])==0) {
            printf("Illegal input!\n");
            scanf("%s", c);
        }
        e=atoi(c);
        if (e==t)
        {
            printf("Correct!\n");
            n += 10;
        }
        else
        {
            printf("Wrong,Right key :%d\n", t);
            
        }
        printf("present score:%d\n", n);
        if(l<=9)
        {  printf("next topic!\n");
        }
        else
        {printf("The test ended!\n");
        }
        l++;
    }
    time(&end);
    cost=difftime(end,start);
    timer=time(NULL);
    tblock=localtime(&timer);
    stu=fopen("king.txt","a+");
    if (stu==NULL) {
        printf("no\n");
        exit(1);
    }
    fprintf(stu,"%6s%6d%7d",val,n,cost);
    fclose(stu);
    printf("\n______________________________\n");
    printf("Question| Ur Answ|Correct Answ\n");
    for(g=0;g<10;g++)
    {printf("%4d%c%2d%8s%8d\n",num[g].w,num[g].e,num[g].r,num[g].y,num[g].z);}
    scanf("%c",&o);
    printf("your Overall result:%d\n",n);
    printf("You use the time is:%dseconds\n",cost);
    printf("Local time is: %s",asctime(tblock));
    while(1)
    {   printf("\n(a)Returns\n");
        printf("(b)Exit\n");
        scanf("%c",&r);
        if(r=='a')
        { printf("Your ID number is:%s\n",val);
            scanf("%c",&o);
            break;}
        else if (r=='b')
        { exit(1);}
        
    }
}





void watch()
{   int v=0;
    int y=0;
    int h=1;
    int g=0;
    int j=0;
    char r,o;
    char val1[10];
    while(v<7)
    {val1[v]=val[v];
        v++;}
    stu=fopen("king.txt","r");
    if (stu==NULL) {
        printf("no\n");
        exit(1);
    }
    while(fscanf(stu, "%6s%6d%7d",val,&n,&cost)!=EOF)
    {h=1;y=0;g=0;
        while(y<8)
        {if(val[y]!=val1[y])
        { h=0;}
            y++;}
        if(h==1)
        {  printf("%6s%6d%7ds\n",val,n,cost);}
        if(h==0)
        {while(g<8)
        { val[g]=val1[g];
            g++;}
        }   }
    fclose(stu);
    while(j<8)
    { val[j]=val1[j];
        j++;}
    scanf("%c",&o);
    while(1)
    {printf("\n(a)Returns\n");
        printf("(b)Exit\n");
        scanf("%c",&r);
        if(r=='a')
        { printf("\nYour ID number is:%s\n",val);
            scanf("%c",&o);
            break;}
        else if (r=='b')
        { exit(1);}
        
    }
}



