#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_TRIES 6
#define WORD_LENGTH 100

void printWord(char *word, int length) {
    for (int i = 0; i < length; i++) {
        printf("%c ", word[i]);
    }
    printf("\n");
}

int isWordGuessed(char *word, char *guessedWord, int length) {
    for (int i = 0; i < length; i++) {
        if (word[i] != guessedWord[i]) {
            return 0;
        }
    }
    return 1;
}

int main() {
    char word[WORD_LENGTH];
    printf("Enter the word to be guessed: ");
    scanf("%s", word);

    int wordLength = strlen(word);
    char guessedWord[WORD_LENGTH];
    for (int i = 0; i < wordLength; i++) {
        guessedWord[i] = '_';
    }

    int tries = 0;
    int correctGuess = 0;
    char guess;

    while (tries < MAX_TRIES && !isWordGuessed(word, guessedWord, wordLength)) {
        printf("Current word: ");
        printWord(guessedWord, wordLength);

        printf("Enter your guess: ");
        scanf(" %c", &guess);
        guess = tolower(guess);

        correctGuess = 0;
        for (int i = 0; i < wordLength; i++) {
            if (word[i] == guess) {
                guessedWord[i] = guess;
                correctGuess = 1;
            }
        }

        if (!correctGuess) {
            tries++;
            printf("Incorrect guess! You have %d tries left.\n", MAX_TRIES - tries);
        }
    }

    if (isWordGuessed(word, guessedWord, wordLength)) {
        printf("Congratulations! You guessed the word: %s\n", word);
    } else {
        printf("Sorry, you've been hanged! The word was: %s\n", word);
    }

    return 0;
}
