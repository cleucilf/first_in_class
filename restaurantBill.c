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
    char meal_name [4][10] = {"Salad,","Soup","Sandwich","Pizza"};
    time_t t;  

    if (argc !=3 ){
        printf("YOU NEED TO PASS EXACTLY TWO ARGUMENTS\n");
        return 0;
    }
    else {
            for (int i = 1; i < 3; i++){
                if (i == 1){
                    tax_amount = (atof(argv[i])/100);
                }
                else{
                    tip_amount = ((atof(argv[i]))/100);
            }
        }
    } 
    srand((unsigned)time(&t)); 
    
    switch (rand()%4)
    {
    case 0:
        meal_cost = 9.95;
        meal_name[0];
        break;
    case 1:
        meal_cost = 4.55;
        meal_name[1];
        break;
    case 2:
        meal_cost = 13.25;
        meal_name[2];
        break;
    case 3:
        meal_cost = 22.35;
        meal_name[3];
        break;    
    }

    tax_amount = (meal_cost * tax_amount);
    tip_amount = (meal_cost * tip_amount);
    total_bill = meal_cost + tax_amount + tip_amount;
    printf("Meal cost: $%.2f\n",meal_cost);
    printf("Tax amount: $%.2f\n",tax_amount);
    printf("Tip amount: $%.2f\n",tip_amount);
    printf("Total bill: $%.2f\n",total_bill);

return 0;
}