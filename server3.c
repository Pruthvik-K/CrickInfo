#include"header.h"
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void quiz()
{
    FILE *fp1=fopen("quiz.txt","r");
    
    
    if(fp1==NULL)
    {
        printf("Error ! Issue in the file...");
    }
     else
    {
        int no_que;
        char que[500];
        char ans[500];
        
        int count =0;
        printf("Enter the number of questions you want to attend (max 30):\n " );
        scanf("%d",&no_que);
        if(no_que>30)
        {
            printf("You exceeded the limit!");
        }
    else{
        for(int i=0;i<no_que;i++)
        {
            for(int j=0;j<5;j++)
            {
            fgets(que,200,fp1);
            puts(que);
            }
            fgets(que,200,fp1);
            int x=atoi(que);
            printf("Choose your option: ");
            scanf("%s",&ans);
            int y=atoi(ans);

            if(x==y)
            {
                printf("Your answer is correct.\n\n");
                count++;
            }

            else
            {
                printf("Your answer is wrong.\n\n");
            }

        }
        printf("Your score is: %d/%d\n",count,no_que);
    }
    }


}  