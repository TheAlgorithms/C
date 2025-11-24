/**
 * @file
 * @brief Rock–Paper–Scissors (Player vs Computer)
 * @details
 * Matches Player vs Computer in best-of-N rounds.
 * Uses same clean structure as Hangman template.
 * ASCII icons included for ROCK, PAPER, SCISSORS.
 * Author: [Nexora](https://github.com/nxora)
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* --- DATA STRUCTURE — HOLDS MATCH RESULTS --- */
struct game_instance {
    int player_score;
    int computer_score;
    int rounds;
};

/* --- FUNCTION PROTOTYPES --- */
struct game_instance new_game(void);
int play_round(void);
const char* move_name(int);
void picture(int, int);
void print_round_result(int);

/* ---------------- MAIN ---------------- */
int main() {

    char again = 'y';

    while (again == 'y' || again == 'Y') {

        struct game_instance game = new_game();

        printf("\n====== ROCK — PAPER — SCISSORS ======\n");

        for (int i = 1; i <= game.rounds; i++) {

            printf("\n---- Round %d ----\n", i);

            int result = play_round();
            print_round_result(result);

            if (result == 1) game.player_score++;
            else if (result == -1) game.computer_score++;

            printf("Score → You: %d | Computer: %d\n",
                   game.player_score, game.computer_score);
        }

        printf("\n===== MATCH RESULTS =====\n");

        if (game.player_score > game.computer_score)
            printf("🎉 You win the match!\n");
        else if (game.player_score < game.computer_score)
            printf("💀 Computer wins the match.\n");
        else
            printf("🤝 It's a draw!\n");

        printf("\nPlay again? (y/n): ");
        scanf(" %c", &again);
    }

    printf("\nThanks for playing!\n");
    return 0;
}

/* ---------------- CREATE NEW GAME ---------------- */
struct game_instance new_game(void) {

    struct game_instance game;

    printf("\nHow many rounds do you want to play? ");
    scanf("%d", &game.rounds);

    game.player_score = 0;
    game.computer_score = 0;

    srand(time(NULL)); // seed RNG

    return game;
}

/* ---------------- PLAY SINGLE ROUND ---------------- */
int play_round(void) {

    int player, comp;

    printf("Choose your move:\n");
    printf("[0] Rock\n[1] Paper\n[2] Scissors\n");
    printf("Enter choice: ");
    scanf("%d", &player);

    while (player < 0 || player > 2) {
        printf("Invalid choice. Enter 0-2: ");
        scanf("%d", &player);
    }

    comp = rand() % 3;

    printf("\nYou chose: %s\n", move_name(player));
    printf("Computer chose: %s\n", move_name(comp));

    picture(player, comp);

    /* winner logic */
    if (player == comp) return 0;
    if ((player == 0 && comp == 2) ||
        (player == 1 && comp == 0) ||
        (player == 2 && comp == 1))
        return 1;

    return -1;
}

/* ---------------- NAME OF MOVE ---------------- */
const char* move_name(int m) {
    switch (m) {
        case 0: return "Rock";
        case 1: return "Paper";
        default: return "Scissors";
    }
}

/* ---------------- ASCII ART ---------------- */
void picture(int p, int c) {

    const char* rock =
            "    _______\n"
            "---'   ____)\n"
            "      (_____)\n"
            "      (_____)\n"
            "      (____)\n"
            "---.__(___)\n";

    const char* paper =
            "     _______\n"
            "---'    ____)____\n"
            "           ______)\n"
            "          _______)\n"
            "         _______)\n"
            "---.__________)\n";

    const char* scissors =
            "    _______\n"
            "---'   ____)____\n"
            "          ______)\n"
            "       __________)\n"
            "      (____)\n"
            "---.__(___)\n";

    printf("\nYour move:\n%s", (p == 0 ? rock : p == 1 ? paper : scissors));

    printf("\nComputer move:\n%s", (c == 0 ? rock : c == 1 ? paper : scissors));
}

/* ---------------- PRINT ROUND WINNER ---------------- */
void print_round_result(int r) {
    if (r == 1) printf("🟢 You win this round!\n");
    else if (r == -1) printf("🔴 Computer wins this round!\n");
    else printf("🟡 It's a draw!\n");
}
