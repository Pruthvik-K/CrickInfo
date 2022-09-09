#include"header.h"
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>





int search_player()
{
    FILE* f_index=fopen("index.txt","r");
    FILE* f_player;
    char line[300];
    char name[100];
    printf("Enter the name of the player: ");
    fflush(stdin);
    gets(name);
    

    printf("\n");
    
    char* p_name;
    char *ret=NULL;
    while(fgets(line,300,f_index)!=NULL && ret==NULL)
    {
       p_name=strtok(line,",");
       ret = strstr(p_name, name);

       if(ret!=NULL)
       {
           p_name=strtok(NULL,",");
           f_player=fopen(p_name,"r");
           
           if(f_player==NULL)
           {
               printf("Error in opening file!\n");
           }
          else
          {
            char c;
            c = fgetc(f_player);
            while (c != EOF)
            {
                    printf ("%c", c);
                    c = fgetc(f_player);
            }
            
                fclose(f_player);
                return 0;
            }
       }
            
       
       else
       {
           p_name=strtok(NULL,",");   
       }  
    }   
    printf("Player not found!\n\n");
   
    fclose(f_index);
       
    
}



