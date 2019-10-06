#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <argp.h>
#include <argz.h>
#include <unistd.h>

uint8_t S[256];
uint8_t T[256];
int globalI = 0, globalJ = 0;

/* Program documentation. */
static char doc[] = "A program implementing the RC4 encryption/decryption algorithm";

/* A description of the arguments we accept. */
static char args_doc[] = "KEY";

/* The options we understand. */
static struct argp_option options[] = {
        {"decrypt", 'd', 0,      0, "Decrypt the given data"},
        {"encrypt", 'e', 0,      0, "Encrypt the given data"},
        {"output",  'o', "FILE", 0, "Output to FILE instead of standard output"},
        {0}
};

/* Used by main to communicate with parse_opt. */
struct arguments {
    char *key;                /* KEY */
    char *output_file;
    int encrypt, decrypt;
};

/* Parse a single option. */
static error_t parse_opt(int key, char *arg, struct argp_state *state) {
    /* Get the input argument from argp_parse, which we
       know is a pointer to our arguments structure. */
    struct arguments *arguments = state->input;

    switch (key) {
        case 'd':
            arguments->decrypt = 1;
            break;
        case 'e':
            arguments->encrypt = 1;
            break;
        case 'o':
            if (arg == NULL) {
                arguments->output_file = "-";
            } else {
                arguments->output_file = arg;
            }
            break;
        case ARGP_KEY_ARG:
            // it requires exactly one argument, the key
            if (state->arg_num > 1) {
                argp_usage(state);
            }
            arguments->key = arg;
            break;
        case ARGP_KEY_END:
            // Not enough arguments.
            if (state->arg_num < 1) {
                argp_usage(state);
            }
            break;
        default:
            return ARGP_ERR_UNKNOWN;
    }
    return 0;
}

/* Our argp parser. */
static struct argp argp = {options, parse_opt, args_doc, doc};

// swaps two values in an array
void swapValues(uint8_t *a, uint8_t i, uint8_t j) {
    uint8_t tmp = a[j];
    a[j] = a[i];
    a[i] = tmp;
}

// initializes the permutation in the array S
void initializeVariables(char *key) {
    // key-scheduling algorithm

    int keyLen = strlen(key);
    for (int i = 0; i < 256; i++) {
        S[i] = (char) i;
        T[i] = key[i % keyLen];
    }

    int j = 0;
    for (int i = 0; i < 256; i++) {
        j = (j + S[i] + T[i]) % 256;
        swapValues(S, i, j);
    }
}

// the RC4 algorithm
uint8_t rc4Output(const uint8_t data) {
    uint8_t outputBuf;
    // pseudo random generation algorithm
    globalI = (globalI + 1) % 256;
    globalJ = (globalJ + S[globalI]) % 256;

    swapValues(S, globalI, globalJ);

    uint8_t t = S[(S[globalI] + S[globalJ]) % 256];

    outputBuf = t ^ data; // the main operation, XOR

    return outputBuf;
}

int main(int argc, char **argv) {
    struct arguments arguments;

    /* Default values. */
    arguments.output_file = "-";
    arguments.decrypt = 1; // by default it will output data as decryption
    arguments.encrypt = 0;

    /* Parse our arguments; every option seen by parse_opt will
       be reflected in arguments. */
    argp_parse(&argp, argc, argv, 0, 0, &arguments);

    initializeVariables(arguments.key);

    uint8_t buf[1]; // temporary buffer for reading the byte
    int totalBytes = 0; // total read bytes
    uint8_t *outputData = malloc(sizeof(uint8_t) * 0);

    // skipping the first 256 bytes of the stream
    for (int i = 0; i < 256; i++) {
        rc4Output(0);
    }

    // reading every byte,
    while (read(0, buf, sizeof(buf)) > 0) {
        totalBytes++;
        outputData = realloc(outputData, totalBytes);
        // add every new byte to the newly reallocated array of en(de)crypted bytes
        outputData[totalBytes - 1] = rc4Output(buf[0]);
    }

    // killing the last byte to avoid memory leaks and illegal memory accesses
    outputData = realloc(outputData, --totalBytes);

    if (arguments.encrypt == 1) {
        if (strcmp(arguments.output_file, "-") == 0) { // printing to stdin if no file name specified
            printf("Encrypted text:\n");
            for (int i = 0; i < totalBytes; i++) {
                printf("%02hhX", outputData[i]);
            }
        } else {
            FILE *filePointer;
            filePointer = fopen(arguments.output_file, "w");

            if (filePointer == NULL) {
                fprintf(stderr, "Unable to create file %s.\n", arguments.output_file);
                exit(EXIT_FAILURE);
            }
            fputs(outputData, filePointer);
            printf("File successfully encrypted to %s.\n", arguments.output_file);
            fclose(filePointer);
        }
    } else if (arguments.decrypt == 1) {
        if (strcmp(arguments.output_file, "-") == 0) { // printing to stdin if no file name specified
            printf("Decrypted text:\n");
            for (int i = 0; i < totalBytes - 1; i++) {
                printf("%c", outputData[i]);
            }
        } else {
            FILE *filePointer;
            filePointer = fopen(arguments.output_file, "w");

            if (filePointer == NULL) {
                fprintf(stderr, "Unable to create file %s.\n", arguments.output_file);
                exit(EXIT_FAILURE);
            }
            fputs(outputData, filePointer);
            printf("File successfully decrypted to %s.\n", arguments.output_file);
            fclose(filePointer);
        }
    }
    // avoid memory leaks
    free(outputData);
    return 0;
}
