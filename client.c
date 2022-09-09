#include<stdio.h>
#include"header.h"
#include<string.h>
#include<time.h>
#include<stdlib.h>

int main()
{
    welcome();
    int s1;
    int s2;
	char player[15];
	int choice;
    printf("\n\n\n1.Player information\t2.Scorecard\t3.Quiz\t4.Quit\nEnter your choice: ");
    scanf("%d",&s1);
    
    do{
        switch (s1)
        {
        case 1: 
                printf("\n\n1.Find player\t2.Create a new player\t3.Go back\nEnter your choice: ");
                scanf("%d",&s2);
                fflush(stdin);
                switch(s2)
                {
                    case 1: search_player();
                            break;

                     case 2: new_player();
					 printf("\nSuccessfully created a new player.\n");
                            break;

                    case 3: break;

                    default:printf("Invalid option!\n");
                            break; 
                }
				break;
        case 2:  
				srand(time(NULL));
				fflush(stdin);
				MENU();
				char select;
				scanf("%c",&select);
				do{
				switch(select)
				{
					case('a'):
						print_scorecard();
						break;
					case('b'):
							menu();
							scanf("%d",&choice);
							switch(choice)
							{
								case 1:
									printf("\nEnter player's name: ");
									scanf("%s",player);
									printf("\nBatting\tRuns\tBalls\tFours\tSixes\tStrike_rate\n");
									scorecard_batsman(player);
									break;
								case 2:
									fflush(stdin);
									printf("\nEnter player's name: ");
									scanf("%s",player);
									printf("\nBowling\tOver\tMaiden\tRun\tWicket\tEconomy\n");
									scorecard_bowler(player);
									fflush(stdin);
									break;
								case 3:
										fflush(stdin);
									break;
								default:printf("Invalid option!\n");
										fflush(stdin);
                            			break;	
							}
							break;
							
					case('c'):
							exit(0);
					default:printf("Invalid option!\n");
							fflush(stdin);
                            break;		
						
				}
				MENU();
				scanf("%c",&select);
				fflush(stdin);
				}while(select!=('a'||'b'||'c'));       
							break;

        case 3: quiz();
				break;
        case 4: exit(0);
				break;


        
        default:printf("Invalid option!\n");
                break;
        }
        printf("\n\n\n1.Player information\t2.Scorecard\t3.Quiz\nEnter your choice: ");
        scanf("%d",&s1);        

        
    }while(s1!=4);
    
    return 0;
}