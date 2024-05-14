#include <stdio.h>
#include <stdlib.h>

#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

// Function prototypes
void clearScreen();
void showLogo();
void readMessage(char **word, int max_length);
void configureAnimation(int *speed, int *window_size, int *direction);
void animateText(char **word, int *speed, int *window_size, int *direction);
void addPadding(char **word, int padding);
void displaceWord(char *word, int direction);


void clearScreen() {
    // Clear the screen depending on the OS
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void showLogo() {
    printf("  _     ___  ___       _  _            _             \n");
    printf(" | |   | __||   \\   __| |(_) ___ _ __ | | __ _  _  _ \n");
    printf(" | |__ | _| | |) | / _` || |(_-<| '_ \\| |/ _` || || |\n");
    printf(" |____||___||___/  \\__,_||_|/__/| .__/|_|\\__,_| \\_, |\n");
    printf("                                |_|             |__/ \n\n");
}

void readMessage(char **word, int max_length) {
    showLogo();
    *word = (char *) malloc(max_length * sizeof(char));

    if (*word == NULL) {
        printf("Memory allocation failed\n");
    }

    printf("Enter your word: ");
    fgets(*word, max_length, stdin);
}

void configureAnimation(int *speed, int *window_size, int *direction) {
    printf("Enter the speed of the animation (ms) (recomended: 150): ");
    scanf("%d", speed);
    printf("Enter the window size (number of characters): ");
    scanf("%d", window_size);
    printf("Enter the direction of the animation (0 = left, 1 = right): ");
    scanf("%d", direction);
}

void animateText(char **word, int *speed, int *window_size, int *direction) {
    while (TRUE) {
        // Print the logo
        showLogo();
        // Displace the word
        displaceWord(*word, *direction);

        // Print the word in the window
        for (int i = 0; i < *window_size + 2; i++) {
            printf("#");
        }
        printf("\n#");
        for (int i = 0; i < *window_size; i++) {
            printf(" ");
        }
        printf("#\n");
        printf("#");
        // Print first window_size characters of the word
        for (int i = 0; i < *window_size; i++) {
            printf("%c", (*word)[i]);
        }
        printf("#\n");
        printf("#");
        for (int i = 0; i < *window_size; i++) {
            printf(" ");
        }
        printf("#\n");
        for (int i = 0; i < *window_size + 2; i++) {
            printf("#");
        }
        printf("\n");
        #ifdef _WIN32
        Sleep(*speed);
        #else
        sleep(*speed / 1000);
        #endif
        clearScreen();
    }
}

void addPadding(char **word, int max_length) {
    int word_length = strlen(*word);
    if ((*word)[word_length - 1] == '\n') {
        (*word)[--word_length] = '\0'; // Remove newline character
    }

    int padding = max_length - word_length;
    int left_padding = padding / 2;
    int right_padding = padding - left_padding;

    // Allocate memory for the result with the correct size
    char *result = (char *) malloc(max_length * sizeof(char) + 1); // +1 for null terminator
    if (result == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    // Fill left padding with spaces
    memset(result, ' ', left_padding);
    result[left_padding] = '\0';

    // Append the word to the result
    strcat(result, *word);

    // Fill right padding with spaces
    memset(result + left_padding + word_length, ' ', right_padding);
    result[left_padding + word_length + right_padding] = '\0'; // Correct termination

    // Copy the result back, ensuring *word has enough space or reallocating *word
    strcpy(*word, result); // This assumes *word was initially allocated with enough space

    free(result);
}

void displaceWord(char *word, int direction) {
    // Allocate memory for the entire word plus the null terminator.
    char *temp = (char *)malloc(strlen(word));

    // Check if malloc returned NULL (memory allocation failed).
    if (temp == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    int length = strlen(word);

    if (direction == 0) {
        // Left displacement
        for (int i = 0; i < length - 1; i++) {
            temp[i] = word[i + 1];
        }
        temp[length - 1] = word[0];
    } else if (direction == 1) {
        // Right displacement
        temp[0] = word[length - 1];
        for (int i = 1; i < length; i++) {
            temp[i] = word[i - 1];
        }
    }

    // Add the null terminator at the end.
    temp[length] = '\0';

    // Save the new word in the original pointer.
    strcpy(word, temp);

    // Free the allocated memory.
    free(temp);
}


int main() {
    char *word;
    int max_length = 70;
    int speed, window_size, direction;

    readMessage(&word, max_length);

    addPadding(&word, max_length);

    clearScreen();

    configureAnimation(&speed, &window_size, &direction);

    animateText(&word, &speed, &window_size, &direction);
    return 0;
}