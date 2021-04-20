#include "main.h"

int length(char *string) {
    int l = 0;
    while(string[l] != '\0') {
        l++;
    }
    return l;
}

int string_check(char *string1, char *string2) {
    int i;

    if (length(string1) != length(string2)) { return 0; }

    for (i = 0; i < length(string1); i++) {
        if (string1[i] != string2[i]) {
            return 0;
        }
    }

    return 1;
}

#ifndef TESTING

int main() {

    char *str;
    char **text;
    int *columns, lines = 0;

    str = (char*)malloc(1 * sizeof(char));
    columns = (int*)malloc(256 * sizeof(int));
    text = (char**)malloc(256 * sizeof(char*));

    str[0] = ' ';

    printf("Enter your text. Enter empty string to stop.\n");

    while (!string_check(str, "\n")) {

        fgets(str, 255, stdin);
        columns[lines] = length(str) - 1;

        text[lines] = (char*)malloc(columns[lines] * sizeof(char));

        for(int j = 0; j < length(str); j++) {
            text[lines][j] = str[j];
        }

        lines++;
    }

    free(str);

    printf("Your text with reversed words:\n");

    text[lines - 1][columns[lines]] = ' ';

    for(int i = lines - 1; i >= 0; i--) {
        for(int j = columns[i] - 1; j >= 0; j--) {
            printf("%c", text[i][j]);
        }
        printf("\n");
    }

    free(columns);
    free(text);
}

#endif
