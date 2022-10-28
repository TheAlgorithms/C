// Rock Paper Scissors Program
// RPS.c
// Created by: David Gillick
// I acknowledge that all my contributions will be made under the project's
// license.
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int i, userScore = 0, computerScore = 0;  // record the score
    int userChoice, computerChoice;           // record the choice
    int seed;

    printf("Please enter a random number seed: \n");
    scanf("%d", &seed);
    srand(seed);

    // Checks user input is valid (1,2,3)
    for (i = 0; i < 10; i++)  // sets the game for 10 valid rounds

        printf(
            "Please enter 1 for Rock, 2 for Paper or 3 for Scissors: \n");  // prompts the user to enter a choice
    {
        scanf(" %d", &userChoice);  // user input
        while (userChoice > 3 ||
               userChoice < 1)  // checks if user input is valid
        {
            printf("Invalid input, please enter 1, 2 or 3: \n");
            scanf(" %d", &userChoice);
        }

        // This is the computer's choice
        computerChoice = rand() % 3 + 1;

        // This is the scoring system
        // all possible outcomes
        if (userChoice == 1 && computerChoice == 3)
        {
            printf(
                "User choice is ROCK.\nComputer choice is SCISSORS.\nUser wins "
                "because ROCK beats SCISSORS.\n");
            userScore++;
        }

        else if (userChoice == 2 && computerChoice == 1)
        {
            printf(
                "User choice is PAPER.\nComputer choice is ROCK.\nComputer "
                "wins because ROCK beats PAPER.\n");
            userScore++;
        }

        else if (userChoice == 3 && computerChoice == 2)
        {
            printf(
                "User choice is SCISSORS.\nComputer choice is PAPER.\nUser "
                "wins because SCISSORS beats PAPER.\n");
            userScore++;
        }

        else if (userChoice == 1 && computerChoice == 2)
        {
            printf(
                "User choice is ROCK.\nComputer choice is PAPER.\nComputer "
                "wins because PAPER beats ROCK.\n");
            computerScore++;
        }

        else if (userChoice == 2 && computerChoice == 3)
        {
            printf(
                "User choice is PAPER.\nComputer choice is SCISSORS.\nComputer "
                "wins because SCISSORS beats PAPER.\n");
            computerScore++;
        }

        else if (userChoice == 3 && computerChoice == 1)
        {
            printf(
                "User choice is SCISSORS.\nComputer choice is ROCK.\nComputer "
                "wins because ROCK beats SCISSORS.\n");
            computerScore++;
        }

        else if (userChoice == 3 && computerChoice == 3)
        {
            printf("User choice is SCISSORS.\n");
            printf("Computer choice is SCISSORS.\n");
            printf(
                "It's a draw. Computer chose SCISSORS and User also chose "
                "SCISSORS.\n");
        }

        else if (userChoice == 2 && computerChoice == 2)
        {
            printf("User choice is PAPER.\n");
            printf("Computer choice is PAPER.\n");
            printf(
                "It's a draw. Computer chose PAPER and User also chose "
                "PAPER.\n");
        }

        else if (userChoice == 1 && computerChoice == 1)
        {
            printf("User choice is ROCK.\n");
            printf("Computer choice is ROCK.\n");
            printf(
                "It's a draw. Computer chose ROCK and User also chose ROCK.\n");
        }
    }
    // This is the final score
    if (userScore > computerScore)
    {
        printf("In 10 games, user won %d times and computer won %d times. \n",
               userScore, computerScore);
    }
    else if (userScore == 1 && userScore < computerScore)
    {
        printf("In 10 games, computer won %d times and user won %d time. \n",
               computerScore, userScore);
    }
    else if (userScore < computerScore)
    {
        printf("In 10 games, computer won %d times and user won %d times. \n",
               computerScore, userScore);
    }

    return 0;
}
