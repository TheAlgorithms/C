/**
 * @file
 * @brief C implementation of hangman game. Wikipedia: https://en.wikipedia.org/wiki/Hangman_(game)
 * @details
 * Simple, readable version of hangman.
 * Changed graphic to duck instead of traditional stick figure (same number of guesses).
 * @author [AtlantaEmrys2002](https://github.com/AtlantaEmrys2002)
*/

#include <ctype.h> /// for main()
#include <stdio.h> /// for main(), new_word(), new_guess(), won()
#include <stdlib.h> /// for all functions
#include <string.h> /// for main()
#include <time.h> /// for new_game()
#include <assert.h> /// for self-testing

// global variable - word to guess
char current_word[100] = "";

//functions
void new_game(); // creates a new game
int new_guess(char, const char guesses[], int size); // checks if player has already played letter
int in_word(char, const char word[], unsigned int size); // checks if letter is in word
void picture(int score); // outputs image of duck (instead of hang man)
void won(int score); // checks if player has won or lost

/**
 * @brief Self-test Implementations
 * @returns void
 */
static void test() {
    /*checks in_word returns correct results (e.g. c is in cat, d is not in flower)*/
    assert(in_word('c', "cat", 3) == 1);
    assert(in_word('d', "flower,", 6) == -1);
    /*checks new_guess returns correct results (e.g. d is in dhjkl and has been guessed before, but e is not and hasn't been guessed before)*/
    //assert(new_guess('d', "dhjkl", 5) == 1);
    assert(new_guess('z', "testing", 5) == -1);
}

/**
 * @brief Main Function
 * @returns 0 on exit
 */
int main() {

    test();


    char guess;
    char guesses[25] = ""; // previous guesses
    int guesses_size;
    int incorrect = 0; // incorrect guesses counter
    char hidden[100] = ""; // hidden word

    new_game();

    for (int i = 0; i < (strlen(current_word)); i++) {
        hidden[i] = '_';
    }

    // main loop - asks player for guesses
    while ((strchr(hidden, '_') != NULL) && incorrect <= 12) {
        do {
            printf("\n****************************\n");
            printf("Your word: ");

            for (int i = 0; i < (strlen(current_word)); i++) {
                printf("%c ", hidden[i]);
            }

            if ((strlen(guesses)) > 0) {
                printf("\nSo far, you have guessed: ");
                for (int i = 0; i < (strlen(guesses)); i++) {
                    printf("%c ", guesses[i]);
                }
            }

            printf("\nYou have %d guesses left.", (12 - incorrect));
            printf("\nPlease enter a letter: ");
            scanf(" %c", &guess);
            guess = tolower(guess);

            guesses_size = sizeof(guesses) / sizeof(char);

        } while (new_guess(guess, guesses, guesses_size) != -1);

        guesses[strlen(guesses)] = guess; // adds new letter to guesses array

        if (in_word(guess, current_word, strlen(current_word)) == 1) {
            printf("That letter is in the word!");
            for (int i = 0; i < strlen(current_word); i++) {
                if ((current_word[i]) == guess) {
                    hidden[i] = guess;
                }
            }
        } else {
            printf("That letter is not in the word.\n");
            incorrect++;
        }
        picture(incorrect);
    }

    won(incorrect);
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
 * @param letter letter guessed by user
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
 * @returns void
 */
void new_game() {

    int line_number = 0;
    int random_num;
    int s = 0;

    FILE *fptr;
    fptr = fopen("words.txt", "r");

    if (fptr == NULL){
        fprintf(stderr, "File not found.");
        exit(EXIT_FAILURE);
    }

    // counts number of words in file - assumes each word on new line
    while (fgets(current_word, 100, fptr) != NULL) {
        line_number++;
    }
    rewind(fptr);

    srand(time(NULL));
    random_num = rand() % line_number;

    // selects randomly generated word
    while (s <= random_num){
        fgets(current_word, 100, fptr);
        s++;
    }

    // formats string correctly
    if (strchr(current_word, '\n') != NULL){
        current_word[strlen(current_word) - 1] = '\0';
    }
    else {
        current_word[strlen(current_word)] = '\0';
    }
    fclose(fptr);
}

/**
 * @brief checks if player has won or lost
 * @param score how many incorrect guesses player has made
 * @returns void
 */
void won(int score) {
    if (score > 12) {
        printf("\nYou lost! The word was: %s", current_word);
    }
    else {
        printf("\nYou won! You had %d guesses left", (12 - score));
    }
}

/*
 * @brief gradually draws duck as user gets letters incorrect
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
