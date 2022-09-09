#include"header.h"
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void menu()
{
	printf("\n		||||||choose||||||		\n");
	printf("		    1)Batting 		     \n");
	printf("		    2)Bowling      \n");
	printf("		    3)Back        \n");
	printf("\n");	
	printf("Enter your choice: ");
}

void MENU()
{
	printf("\n 		 >>>>select<<<<     \n");
	printf("		 a)Scorecard of a team		 \n");
	printf("		 b)Random scorecard of a player		 \n");
	printf("		 c)Quit			\n");
	printf("Please enter your choice: ");
}

void scorecard_batsman(char const *player)
{
	float run;
	float balls;
	int fours;
	int sixes;
	float strike_rate;
	
	int total;
	
	int run_lower=0,run_upper=150;
	run=(rand()%(run_upper-run_lower+1))+run_lower;
	
	int ball_lower=0,ball_upper=30;
	int add=(rand()%(ball_upper-ball_lower))+ball_lower;
	balls = run+add;
	
	do{
	int four_lower=0,four_upper=15;
	fours=(rand()%(four_upper-four_lower))+four_lower;
	
	int six_lower=0,six_upper=10;
	sixes=(rand()%(six_upper-six_lower))+six_lower;
	
	total=(4*fours)+(6*sixes);
	
	}while(!(total<=run));
	
	strike_rate=(run*100)/balls;
	
	printf("%s\t%0.0f\t%0.0f\t%d\t%d\t%0.2f\n",player,run,balls,fours,sixes,strike_rate);
	
}

void scorecard_bowler(char const *player)
{
	float overs;
	int maidens;
	float run;
	int wickets;
	float economy;
	
	
	
	int overs_min=4,overs_max=16;
	overs=(rand()%(overs_max-overs_min+1))+overs_min;
	
	do{
	int maiden_lower=0,maiden_upper=5;
	maidens=(rand()%(maiden_upper-maiden_lower+1))+maiden_lower;
	}while(!(maidens<overs));
	
	int run_min=10,run_max=53;
	run=(rand()%(run_min-run_max+1))+run_min;
	
	int wic_lower=0,wic_upper=10;
	wickets=(rand()%(wic_lower-wic_upper))+wic_lower;
	
	economy=run/overs;
	
	printf("%s\t%0.0f\t%d\t%0.0f\t%d\t%0.2f\n",player,overs,maidens,run,wickets,economy);
	
}



void select_match()
{	
	FILE *fmatch=fopen("matches.tsv","r");
	char s[200];
	while(fgets(s,200,fmatch))
	{
		printf("%s\n",s);
	}
	fclose(fmatch);
	printf("\nKindly enter your chioce: ");
}


void print_scorecard()
{
	select_match();
	char str[5];char buffer[13];
	scanf("%s",str);
	sprintf(buffer,"%s.txt",str);
	FILE *fp=fopen(buffer,"r");
	char store[200];
	while(fgets(store,200,fp))
	{
		printf("%s",store);
	}
	fclose(fp);
}




