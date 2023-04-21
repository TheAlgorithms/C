/**
 * @file
 * @brief C implementation of [Hangman Game](https://en.wikipedia.org/wiki/Hangman_(game))
 * @details
 * Simple, readable version of hangman.
 * Changed graphic to duck instead of traditional stick figure (same number of guesses).
 * @author [AtlantaEmrys2002](https://github.com/AtlantaEmrys2002)
*/

#include <ctype.h> /// for main() - tolower()
#include <stdio.h> /// for main(), new_word(), new_guess(), won() - I/O operations
#include <stdlib.h> /// for all functions - exit(), rand() and file functions
#include <string.h> /// for main() - for string operations strlen, strchr, strcpy
#include <time.h> /// for new_game() - used with srand() for declaring new game instance

/*
 * @brief game_instance structure that holds current state of game
 */
struct game_instance{

    char current_word[30]; ///< word to be guessed by player
    char hidden[30]; ///< hidden version of word that is displayed to player
    int size; ///< size of word
    int incorrect; ///< number of incorrect guesses
    char guesses[25]; ///< previous guesses
    int guesses_size; ///< size of guesses array

};

// function prototypes
struct game_instance new_game(void); // creates a new game
int new_guess(char, const char guesses[], int size); // checks if player has already played letter
int in_word(char, const char word[], unsigned int size); // checks if letter is in word
void picture(int score); // outputs image of duck (instead of hang man)
void won(const char word[], int score); // checks if player has won or lost

/**
 * @brief Main Function
 * @returns 0 on exit
 */
int main() {

    struct game_instance game = new_game(); // new game created
    char guess; // current letter guessed by player

    // main loop - asks player for guesses
    while ((strchr(game.hidden, '_') != NULL) && game.incorrect <= 12) {
        do {
            printf("\n****************************\n");
            printf("Your word: ");

            for (int i = 0; i < game.size; i++) {
                printf("%c ", game.hidden[i]);
            }

            if (game.guesses_size > 0) {
                printf("\nSo far, you have guessed: ");
                for (int i = 0; i < game.guesses_size; i++) {
                    printf("%c ", game.guesses[i]);
                }
            }

            printf("\nYou have %d guesses left.", (12 - game.incorrect));
            printf("\nPlease enter a letter: ");
            scanf(" %c", &guess);
            guess = tolower(guess);

        } while (new_guess(guess, game.guesses, game.guesses_size) != -1);

        game.guesses[game.guesses_size] = guess; // adds new letter to guesses array
        game.guesses_size++; // updates size of guesses array

        if (in_word(guess, game.current_word, game.size) == 1) {
            printf("That letter is in the word!");
            for (int i = 0; i < game.size; i++) {
                if ((game.current_word[i]) == guess) {
                    game.hidden[i] = guess;
                }
            }
        } else {
            printf("That letter is not in the word.\n");
            (game.incorrect)++;
        }
        picture(game.incorrect);
    }

    won(game.current_word, game.incorrect);
    return 0;
}

/**
 * @brief checks if letter has been guessed before
 * @param new_guess letter that has been guessed by player
 * @param guesses array of player's previous guesses
 * @param size size of guesses[] array
 * @returns 1 if letter has been guessed before
 * @returns -1 if letter has not been guessed before
 */
int new_guess(char new_guess, const char guesses[], int size) {

    for (int j = 0; j < size; j++) {
        if (guesses[j] == new_guess) {
            printf("\nYou have already guessed that letter.");
            return 1;
        }
    }

    return -1;
}

/**
 * @brief checks if letter is in current word
 * @param letter letter guessed by player
 * @param word current word
 * @param size length of word
 * @returns 1 if letter is in word
 * @returns -1 if letter is not in word
 */
int in_word(char letter, const char word[], unsigned int size) {

    for (int i = 0; i < size; i++) {
        if ((word[i]) == letter) {
            return 1;
        }
    }

    return -1;
}

/**
 * @brief creates a new game - generates a random word and stores in global variable current_word
 * @returns current_game - a new game instance containing randomly selected word, its length and hidden version of word
 */
struct game_instance new_game() {

    char word[30]; // used throughout function

    FILE *fptr;
    fptr = fopen("games/words.txt", "r");

    if (fptr == NULL){
        fprintf(stderr, "File not found.\n");
        exit(EXIT_FAILURE);
    }

    // counts number of words in file - assumes each word on new line
    int line_number = 0;
    while (fgets(word, 30, fptr) != NULL) {
        line_number++;
    }

    rewind(fptr);

    // generates random number
    int random_num;
    srand(time(NULL));
    random_num = rand() % line_number;

    // selects randomly generated word
    int s = 0;
    while (s <= random_num){
        fgets(word, 30, fptr);
        s++;
    }

    // formats string correctly
    if (strchr(word, '\n') != NULL){
        word[strlen(word) - 1] = '\0';
    }

    fclose(fptr);

    // creates new game instance
    struct game_instance current_game;
    strcpy(current_game.current_word, word);
    current_game.size = strlen(word);
    for (int i = 0; i < (strlen(word)); i++) {
        current_game.hidden[i] = '_';
    }
    current_game.incorrect = 0;
    current_game.guesses_size = 0;

    return current_game;
}

/**
 * @brief checks if player has won or lost
 * @param word the word player has attempted to guess
 * @param score how many incorrect guesses player has made
 * @returns void
 */
void won(const char word[], int score) {
    if (score > 12) {
        printf("\nYou lost! The word was: %s.\n", word);
    }
    else {
        printf("\nYou won! You had %d guesses left.\n", (12 - score));
    }
}

/*
 * @brief gradually draws duck as player gets letters incorrect
 * @param score how many incorrect guesses player has made
 * @returns void
 */
void picture(int score) {

    switch(score) {

        case 12:
            printf("\n      _\n"
                   "  __( ' )> \n"
                   " \\_ < _ ) ");
            break;

        case 11:
            printf("\n      _\n"
                   "  __( ' )\n"
                   " \\_ < _ ) ");
            break;

        case 10:
            printf("\n      _\n"
                   "  __(   )\n"
                   " \\_ < _ ) ");
            break;

        case 9:
            printf("\n        \n"
                   "  __(   )\n"
                   " \\_ < _ ) ");
            break;

        case 8:
            printf("\n        \n"
                   "  __(    \n"
                   " \\_ < _ ) ");
            break;

        case 7:
            printf("\n        \n"
                   "  __     \n"
                   " \\_ < _ ) ");
            break;

        case 6:
            printf("\n        \n"
                   "  _      \n"
                   " \\_ < _ ) ");
            break;

        case 5:
            printf("\n        \n"
                   "  _      \n"
                   "   _ < _ ) ");
            break;

        case 4:
            printf("\n        \n"
                   "         \n"
                   "   _ < _ ) ");
            break;

        case 3:
            printf("\n        \n"
                   "         \n"
                   "     < _ ) ");
            break;

        case 2:
            printf("\n        \n"
                   "         \n"
                   "       _ ) ");
            break;

        case 1:
            printf("\n        \n"
                   "         \n"
                   "         ) ");
            break;

        case 0:
            break;

        default:
            printf("\n      _\n"
                   "  __( ' )> QUACK!\n"
                   " \\_ < _ ) ");
            break;
    }
}
