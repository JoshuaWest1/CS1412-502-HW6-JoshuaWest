#include <stdio.h>
// --------------------------------------------------------------------------------
// AUTHOR: Joshua Wade West
// FILENAME: HW6.cpp
// SPECIFICATION: Calculates the Candidate with the most votes
// FOR: CS 1412 Lab- Section 502

int main(void) {

  int Vote_Table[5][5] = {{1,192,48,206,37},//The declaration of the table
                          {2,147,90,312,21},
                          {3,186,12,121,38},
                          {4,114,21,408,39},
                          {5,267,13,382,29}};
int Total_Votes = 0;// value for total # of values
int Canidate[5] = {0} ;// array for the # of votes each candidate got
double CanidatePercentage[5] = {1};//array for the percentage from the above array
char CanLetter[5] = {'A','B','C','D'} ;
double Num, Den;// used for finding percentage


printf("\nFor Candidate C, Does she have 108 Votes in Precinct 4?\n(type Y for Yes Or N for No)\n");// asks user if Candidate has 108 votes
char choice;
scanf("%c",&choice);
if(choice == 'Y' || choice == 'y'){Vote_Table[3][3] = 108;}// if answered yes, changes the value for Candidate C precinct 4 into 108 



printf("\n\n");
printf("             Candidate    Candidate     Candidate    Candidate\n");// top layer of the table
printf("Precinct         A            B             C            D\n\n");


//OutPuts the # of votes for each candidate
for(int i = 0 ; i < 5; i++){
  for(int j = 0 ; j < 5; j++){
    printf("    %d       ",Vote_Table[i][j]);
    if(j == 4){  printf("\n"); }//after each line this moves to the next one
  }
}


//Calculates the total votes
for(int i = 0 ; i < 5; i++){
  for(int j = 0 ; j < 4; j++){

Total_Votes = Total_Votes + Vote_Table[i][j+1];
  }}


//Finds the Total # of votes per Candidate
for(int j = 0 ; j < 4; j++){
  for(int i = 0 ; i < 5; i++){
Canidate[j] = Canidate[j] + Vote_Table[i][j+1];
  }}


//Finds the Percentage of Votes for each Candidate
for(int j = 0 ; j < 4; j++){
Num = Canidate[j];
Den = Total_Votes;
CanidatePercentage[j] = Num/Den * 100 ;
}


printf("\n");
printf("Total Votes\n");

printf("   %d         %d          %d          %d          %d\n",// Outputs the total votes for each Canidate
Total_Votes,Canidate[0],Canidate[1],Canidate[2],Canidate[3]);

printf("\nPercentage\n");
printf("   100");
//Outputs the percentage of votes for each Canidate
for(int j = 0 ; j < 4; j++){
printf("         %0.2f",CanidatePercentage[j]);
}


int highest[5];//declare a temporary variable array for Candidate array
char Winner[5];//declare a temporary variable array for Canletter array
for(int j = 0 ; j < 4; j++){
highest[j] = Canidate[j];//input Candidate values into highest
Winner[j] = CanLetter[j];//input CanLetter values into Winner
}


//calculates the candidate with the highest # of votes 
for (int i = 1; i < 5; ++i) {
        if (highest[0] < highest[i]){
            highest[0] = highest[i];
            Winner[0] = Winner[i];
        }
    }

if(highest[0] > Total_Votes/2){ //Determines if the candidate with the most votes has over 50% of the votes
printf("\n\n\n\nThe Winner is Candidate %c  ", Winner[0]);// out puts the candidate with the most votes. BUT DUE TO THE ELECTORAL COLLEGE THE ACTUAL WINNER IS CANDIDATE A, CAUSE WHY THE HECK NOT
}

//I'm SO Sorry for how hideous this is, i couldnt figure out a shorter way.

else{// if no candidate has over 50% of the votes
if(Canidate[0] > Canidate[1] && Canidate[0] > Canidate[2] && Canidate[0] > Canidate[3]){//if Candidate 1 has the most votes
printf("\n\nWith no Candidate with over half of the Votes \nThe Candidate with the most votes is Candidate %c  ", CanLetter[0]);

if(Canidate[1] > Canidate[2] && Canidate[1] > Canidate[3]){printf("\nThe Candidate with the second most votes is Candidate %c", CanLetter[1]);};//if Candidate 2 has the 2nd most votes
if(Canidate[2] > Canidate[1] && Canidate[2] > Canidate[3]){printf("\nThe Candidate with the second most votes is Candidate %c", CanLetter[2]);};//if Candidate 3 has the 2nd most votes
if(Canidate[3] > Canidate[1] && Canidate[3] > Canidate[2]){printf("\nThe Candidate with the second most votes is Candidate %c", CanLetter[3]);};//if Candidate 4 has the 2nd most votes
}

    else if(Canidate[1] > Canidate[0] && Canidate[1] > Canidate[2] && Canidate[1] > Canidate[3]){//if Candidate 2 has the most votes
      printf("\n\nWith no Candidate with over half of the Votes \nThe Candidate with the most votes is Candidate %c  ", CanLetter[1]);

    if(Canidate[0] > Canidate[2] && Canidate[0] > Canidate[3]){printf("\nThe Candidate with the second most votes is Candidate %c", CanLetter[0]);};//if Candidate 1 has the 2nd most votes
    if(Canidate[2] > Canidate[0] && Canidate[2] > Canidate[3]){printf("\nThe Candidate with the second most votes is Candidate %c", CanLetter[2]);};//if Candidate 2 has the 2nd most votes
    if(Canidate[3] > Canidate[0] && Canidate[3] > Canidate[2]){printf("\nThe Candidate with the second most votes is Candidate %c", CanLetter[3]);};//if Candidate 4 has the 2nd most votes
    }

        else if(Canidate[2] > Canidate[0] && Canidate[2] > Canidate[1] && Canidate[2] > Canidate[3]){//if Candidate 3 has the most votes
          printf("\n\nWith no Candidate with over half of the Votes \nThe Candidate with the most votes is Candidate %c  ", CanLetter[2]);

        if(Canidate[0] > Canidate[1] && Canidate[0] > Canidate[3]){printf("\nThe Candidate with the second most votes is Candidate %c", CanLetter[0]);};//if Candidate 1 has the 2nd most votes
        if(Canidate[1] > Canidate[0] && Canidate[1] > Canidate[3]){printf("\nThe Candidate with the second most votes is Candidate %c", CanLetter[1]);};//if Candidate 2 has the 2nd most votes
        if(Canidate[3] > Canidate[0] && Canidate[3] > Canidate[1]){printf("\nThe Candidate with the second most votes is Candidate %c", CanLetter[3]);};//if Candidate 4 has the 2nd most votes
        }

            else if(Canidate[3] > Canidate[0] && Canidate[3] > Canidate[1] && Canidate[3] > Canidate[2]){//if Candidate 4 has the most votes
              printf("\n\nWith no Candidate with over half of the Votes \nThe Candidate with the most votes is Candidate %c  ", CanLetter[3]);

            if(Canidate[0] > Canidate[1] && Canidate[0] > Canidate[2]){printf("\nThe Candidate with the second most votes is Candidate %c", CanLetter[0]);};//if Candidate 1 has the 2nd most votes
            if(Canidate[1] > Canidate[0] && Canidate[1] > Canidate[2]){printf("\nThe Candidate with the second most votes is Candidate %c", CanLetter[1]);};//if Candidate 2 has the 2nd most votes
            if(Canidate[2] > Canidate[0] && Canidate[2] > Canidate[1]){printf("\nThe Candidate with the second most votes is Candidate %c", CanLetter[2]);};//if Candidate 3 has the 2nd most votes
            }
}

  return 0;
}