//
//  main.c
//  小学期
//
//  Created by kingwang on 2017/8/17.
//  Copyright © 2017年 kingwang. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

void registered();

int main()
{
    registered();
    return 0;
}


void registered(){
    int i=1;
    char a;
    while(i==1)
    {
        printf("(a)Individual user registration\n");
        printf("(b)Administrator registration\n");
        printf("(c)	Exit\n");
        scanf("%c",&a);
        if(a=='a')
        {
        }
        else if(a=='b')
        {printf("\n____________________\n");
            printf("YOURID| RESULT| TIMR\n");
        }
        else if(a=='c')
        {exit(1);}
    }
}
