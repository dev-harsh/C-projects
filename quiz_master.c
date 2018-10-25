#include <stdio.h>
int main()
{
	printf("***** WelCome to the Quiz Master Software ***** \n It gives you the analytics of a quiz competition \n");

	int ques,parti,i,j,highest;
	
	printf("\nEnter the Number of Participants - ");
	scanf("%d",&parti);

	printf("Enter the Number of Questions - ");
	scanf("%d",&ques);

	int score[parti];//array to store scores of each participants
	char anskey[ques],bufferclear,answer[parti][ques];
	
	printf("\nEnter the Answer Keys of the following question number :-\n");

	for(i=0;i<ques;i++) //accepting the answer keys
	{
	    printf("\nQuestion %d - ",i+1);
	    scanf("%c",&bufferclear);//to clear the buffer while entering the input
	    scanf("%c",&anskey[i]);
	}

	for (i=0;i<parti;i++) //accepting the answers of each participants in a 2D array
	{
		score[i]=0;  //initializing to 0 to avoid the garbage value
		printf("\nEnter the Answer given by Participant %d\n",i+1);

		for(j=0;j<ques;j++)
		{
		    printf("\nQuestion %d - ",j+1);
		    scanf("%c",&bufferclear); //to clear the buffer while entering the input
		    scanf("%c",&answer[i][j]);

		    if(answer[i][j]==anskey[j])//checking whether the answer matches with the answer key
		    	score[i]++;
		}
	}
	highest=score[0];//assuming the score of 1st participant to be the highest

	printf("\n\nFollowing are the scores of the Participants\n");

	for(i=0;i<parti;i++)
	{
		printf("Participant %d = %d\n",i+1,score[i]); //displaying the scores of individual participants

		if(score[i]>highest) //to find the highest score
			highest=score[i];
	}

	printf("\n******WINNER******\n");
	printf("|| With a High Score of %d ||\n",highest );

	for(i=0;i<parti;i++)
	{
		if(score[i]==highest)
			printf("* Participant %d\n",i+1); //displaying the participants with the highest score
	}
	return 0;
}