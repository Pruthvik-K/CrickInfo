#include<stdio.h>
#include<string.h>
#include"header.h"
int new_player()
{
    char name[100];
    FILE* f = fopen("index.txt","a");
    printf("Enter name and nick names of the player : ");
    scanf("%s",name);
    fprintf(f,"\n%s,%s.txt,",name,name);
    strcat(name,".txt");
    FILE* f2 = fopen(name,"w");
    printf("Enter the details of the player and press '@' to finish :");
    char c;
    c = getc(stdin);
    while(c!='@')
    {
        fputc(c,f2);
        c = getc(stdin);
    }

    fclose(f);
    fclose(f2);
    return 0;

}