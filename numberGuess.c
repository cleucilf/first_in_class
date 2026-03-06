//Stage 1: Create a small version of the program that includes: 
//input from user: int, output: string (right or wrong), and random number generator.
//Stage 2: Add constraints (input validation), menu of options with only 1 (with low or high suggestions) and 3 functioning
// Stage 3: Add file ops
#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include <time.h> 

int main (int argc, char *argv[]){
    
    time_t t;
    int min_number = 1, max_number = 10;
    int rd_num = 0;
    int user_guess;
    
    srand((unsigned)time(&t));
    rd_num = rand() % (max_number - min_number + 1) + min_number;
    
    printf("%d\n",rd_num);   
    printf("Type in a number between 1 and 10: ");
    scanf("%d",&user_guess);
    
    if(user_guess == rd_num){
        printf("You guessed right\n");
    } else{
        printf("You guessed wrong\n");
    }

    return 0;
}