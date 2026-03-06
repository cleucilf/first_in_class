// Add standard C libraries and create main with command line args
// Create variables such as: tax_amount, meal_cost, tip_amount,total_bill
//Create a variable that will randomly choose from the 4 meals  
// Output tax_amount, meal_cost, tip_amount,total_bill
#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include <time.h> 

int main (int argc, char *argv[]){
    double tax_amount = 0, meal_cost = 0, tip_amount = 0,total_bill = 0;
    time_t t;  

    // Check if exactly 3 args were passed. If not, it will return an err on the terminal
    if (argc !=3 ){
        fprintf(stderr,"YOU NEED TO PASS EXACTLY TWO ARGUMENTS\n");
        return 1;
    }
    else {
            // Assigns the first and second args to their variables and converts them into percentage
            for (int i = 1; i < 3; i++){
                if (i == 1){
                    tax_amount = (atof(argv[i])/100);
                }
                else{
                    tip_amount = ((atof(argv[i]))/100);
            }
        }
    } 
    // creates a random number from 0 to 3 based on time, and the meal is chosen based on the number
    srand((unsigned)time(&t)); 
    
    switch (rand()%4)
    {
    case 0:
        meal_cost = 9.95;
        break;
    case 1:
        meal_cost = 4.55;
        break;
    case 2:
        meal_cost = 13.25;
        break;
    case 3:
        meal_cost = 22.35;
        break;    
    }
    // Calculations
    tax_amount = (meal_cost * tax_amount);
    tip_amount = (meal_cost * tip_amount);
    total_bill = meal_cost + tax_amount + tip_amount;
    // Print the results
    printf("Meal cost: $%.2f\n",meal_cost);
    printf("Tax amount: $%.2f\n",tax_amount);
    fprintf(stderr,"Tip amount: $%.2f\n",tip_amount);
    printf("Total bill: $%.2f\n",total_bill);

return 0;
}