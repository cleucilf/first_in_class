// Stage 1: Create a small version of the program that includes:
// input from user: int, output: string (right or wrong), and random number generator.
// Stage 2: Add constraints (input validation), menu of options with only 1 (with low or high suggestions) and 3 functioning
//  Stage 3: Add file ops
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <stdbool.h>

// Declaration and init of global Variables
#define MAX_ALLOWED 100
int games_played = 0;
int guesses_per_game[100];
int win_per_game[100];
char user_menu_choice[20];
time_t t;
int min_number = 1, max_number = 10;
int rd_num = 0;
int choice;

// display menu + input validation
void menu()
{
    do
    {
        printf("Press 1 to play\n");
        printf("Press 2 to change the max number\n");
        printf("Press 3 to quit\n");
        scanf(" %19s", user_menu_choice);
        int is_number = 1;
        for (int i = 0; i < strlen(user_menu_choice); i++)
        {
            if (!isdigit(user_menu_choice[i]))
            {
                is_number = 0;
                break;
            }
        }
        if (is_number == 0)
        {
            printf("Invalid input. Enter 1, 2, or 3\n");
            continue;
        }
        choice = atoi(user_menu_choice);
        if (choice < 1 || choice > 3)
        {
            printf("Invalid input. Choose 1, 2, or 3\n");
            continue;
        }
        else
        {
            break;
        }
    } while (true);
}

int main(int argc, char *argv[])
{
    // If file is not NULL, Opens it and reads the value stored. .
    FILE *fp = fopen("save_user_max_number.txt", "r");

    if (fp != NULL)
    {
        int loaded_max;
        if (fscanf(fp, "%d", &loaded_max) == 1)
        {
            if (loaded_max >= min_number && loaded_max <= MAX_ALLOWED)
            {
                max_number = loaded_max;
            }
        }
        fclose(fp);
    }

    srand((unsigned)time(&t));
    do
    {
        menu();
        if (choice == 1)
        {
            rd_num = rand() % (max_number - min_number + 1) + min_number;
            int guesses = 0;
            char user_guess[20];
            int guess_num;
            do
            {
                printf("Type a number between 1 and %d or 'q' to quit: ", max_number);
                scanf("%19s", user_guess);

                if ((user_guess[0] == 'q' || user_guess[0] == 'Q') && strlen(user_guess) == 1)
                {
                    if (games_played < 100)
                    {
                        guesses_per_game[games_played] = guesses;
                        win_per_game[games_played] = 0;
                        games_played++;
                    }
                    break;
                }
                int is_number = 1;
                for (int i = 0; i < strlen(user_guess); i++)
                {
                    if (!isdigit(user_guess[i]))
                    {
                        is_number = 0;
                        break;
                    }
                }

                if (is_number == 0)
                {
                    printf("Invalid input\n");
                    continue;
                }
                guess_num = atoi(user_guess);
                if (guess_num < min_number || guess_num > max_number)
                {
                    printf("Out of range!\n");
                    continue;
                }
                guesses++;
                if (guess_num == rd_num)
                {
                    printf("You guessed right\n");
                    if (games_played < 100)
                    {
                        guesses_per_game[games_played] = guesses;
                        win_per_game[games_played] = 1;
                        games_played++;
                    }
                    break;
                }
                else if (guess_num < rd_num)
                {
                    printf("Higher\n");
                }
                else if (guess_num > rd_num)
                {
                    printf("Lower\n");
                }

            } while (true);
        }
        else if (choice == 2)
        {
            char new_max_str[4];
            int new_max;

            do
            {
                printf("Enter a new max number (must be less or equal than %d): ", MAX_ALLOWED);
                scanf(" %3s", new_max_str);

                int is_number = 1;
                for (int i = 0; i < strlen(new_max_str); i++)
                {
                    if (!isdigit(new_max_str[i]))
                    {
                        is_number = 0;
                        break;
                    }
                }

                if (is_number == 0)
                {
                    printf("Invalid input. Type a number.\n");
                    continue;
                }

                new_max = atoi(new_max_str);

                if (new_max < min_number || new_max > MAX_ALLOWED)
                {
                    printf("Out of range! Type a number between %d and %d.\n", min_number, MAX_ALLOWED);
                    continue;
                }

                max_number = new_max;

                FILE *fp = fopen("save_user_max_number.txt", "w");
                if (fp == NULL)
                {
                    perror("Error creating file");
                    continue;
                }
                else
                {
                    fprintf(fp, "%d\n", max_number);
                    fclose(fp);
                    printf("Max number updated to %d.\n", max_number);
                }
                break;

            } while (true);
        }
        else if (choice == 3)
        {
            printf("Thank you for playing!\n");

            if (games_played == 0)
            {
                printf("No games played.\n");
            }
            else
            {
                for (int i = 0; i < games_played; i++)
                {
                    if (win_per_game[i] == 1)
                    {
                        printf("Game %d: WON in %d guesses\n", i + 1, guesses_per_game[i]);
                    }
                    else
                    {
                        printf("Game %d: LOST (quit) after %d guesses\n", i + 1, guesses_per_game[i]);
                    }
                }
            }
        }

    } while (choice != 3);

    return 0;
}