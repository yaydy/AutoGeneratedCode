#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_WORD_LENGTH 50

int main() {
    // Open the word list file
    FILE *fp = fopen("wordlist.txt", "r");
    if (fp == NULL) {
        printf("Error: Could not open word list file.\n");
        return 1;
    }

    // Read the words from the file into an array
    char words[10000][MAX_WORD_LENGTH];
    int num_words = 0;
    while (fgets(words[num_words], MAX_WORD_LENGTH, fp)) {
        words[num_words][strcspn(words[num_words], "\r\n")] = 0; // Remove newline character
        num_words++;
    }

    // Close the file
    fclose(fp);

    // Prompt the user to enter a word
    char word[MAX_WORD_LENGTH];
    printf("Enter a word: ");
    scanf("%s", word);

    // Check if the word is spelled correctly
    bool correct = false;
    for (int i = 0; i < num_words; i++) {
        if (strcmp(word, words[i]) == 0) {
            correct = true;
            break;
        }
    }

    // Print the result
    if (correct) {
        printf("The word is spelled correctly.\n");
    } else {
        printf("The word is spelled incorrectly.\n");
    }

    return 0;
}
