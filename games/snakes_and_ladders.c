/*
 * Snake and Ladders Game (Single Player)
 * Author: KarthikeyaPila
 *
 * A simple console-based implementation of Snake and Ladders.
 * Roll the dice and try to reach exactly 100.
 * Ladders move you up, snakes move you down.
 *
 * Compile: gcc snake_game.c -o snake_game
 * Run: ./snake_game
 */


#include <stdio.h>  // for input output functions. -> printf, scanf
#include <stdlib.h> // for memory allocated functions -> calloc
#include <time.h>   // used with srand()

int update_pos_if_ladder_snake(int player_position) {
    int ladder_snake_pos[16][2] = {                                    // -> these are the ladder and snake positions.
        {4, 14}, {9, 31}, {20, 38}, {28, 84}, {40, 59},                // -> if the 0th index is greater than 1st index => represents a snake
        {51, 67}, {63, 81}, {71, 91}, {17, 7}, {54, 34},               // -> if the 0th index is lesser than the 1st index => represents a ladder
        {62, 19}, {64, 60}, {87, 24}, {93, 73}, {95, 75}, {99, 2}};

    for (int j = 0; j < 16; j++) {
        if (player_position == ladder_snake_pos[j][0])
        {
            player_position = ladder_snake_pos[j][1];
            break; // Once matched, no need to check further
        }
    }
    
    return player_position;
}

int main(){
    int no_of_players = 1;

    printf("Let's play Snake and Ladders! (Single Player Mode)\n");
    printf("Let's start the game!\n");

    int *player_position_arr = calloc(no_of_players, sizeof(int));

    printf("\nOkay, let's start the game.\n");

    printf("You are currently at: %d\n", player_position_arr[0]);

    srand(time(NULL));  // Seed random generator once here

    while (player_position_arr[0] < 100){
        printf("\nRoll the dice by pressing Enter\n");
        while (getchar() != '\n');  // Wait for Enter key (ignore other characters)

        int dice = (rand() % 6) + 1;                        // this gives a value between 1 and 6 both included.
        printf("Dice value: %d\n", dice);

        if (player_position_arr[0] + dice > 100) {
            dice = 0; 
            printf("Oops, you need the exact number to reach 100.\n");
        }

        player_position_arr[0] += dice;
        int updated_pos = update_pos_if_ladder_snake(player_position_arr[0]);

        if (updated_pos > player_position_arr[0]) {         // this executes when the late r position is higher than the previous position => got up a ladder
            printf("Let's go! You climbed a ladder!\n");
        }
        else if (updated_pos < player_position_arr[0]) {    
            printf("Oh no! You got bitten by a snake.\n");  // this executes when the later position is lower than the previous position => got bitten by a snake.
        }
    
        player_position_arr[0] = updated_pos;               // assigns the new player position after the dice roll.
        printf("You are now at: %d\n", updated_pos);
    }
    
    //the loop ends when the player reaches 100.
    printf("\nCongrats, you won!!\n");

    free(player_position_arr);

    return 0;
}