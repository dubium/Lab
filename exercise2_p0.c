#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "utils.h"
#include "exercise2_p0.h"

/*----------------------------- Functions Exercise 2 -------------------------*/

/**
 * Reads the lines of a text file into an array.
 *
 * @param file_path The minimum number accepted.
 * @param lines An array of strings where the contents of the file are read.
 * @param max_line_length The maximum length of the lines in the file.
 * @return The number of lines successfully read or ERROR_FILE when the file cannot be read.
 *
 */
int read_lines_file(char* file_path, char** lines, int max_line_length) {

// Implement this function

}

/**
 * Returns the length of a string.
 *
 * @param str Input string.
 * @return The number of characters in the string.
 *
 */
int string_length(char* str) {

// Implement this function

}

/**
 * Ex. 2.1
 * Indicates whether the first string passed is the reverse of the second one.
 *
 * @param string1 A string.
 * @param string2 A string.
 * @return A boolean value indicating whether the two passed strings are the reverse of each other.
 *
 */
bool is_reverse(char* string1, char* string2) {

// Implement this function

}

/**
* Ex. 2.2
* Counts the total number of occurrences of the second string in the first one.
*
* @param string1 A string.
* @param string2 A string.
* @return An integer value indicating the number of times that the second string occurs in the first one.
*
*/
int count_substring(char* string1, char* string2) {

// Implement this function

}

/**
* Ex. 2.3.1
* Concatenates two strings and returns the result.
*
* @param string1 A string.
* @param string2 A string.
* @return A string with the concatenation of the two passed strings.
*
*/
char* concat_strings(char* string1, char* string2) {

// Implement this function

}

/**
* Ex. 2.3.2
* Concatenates two strings and returns the result in the first string.
*
* @param string1 A string.
* @param string2 A string.
*
*/
void concat_strings_mod(char* string1, char* string2) {

// Implement this function

}

/*-------------------------------- Execise 2 ----------------------------*/

void exercise_2() {

    printf("\n--- Exercise 2 ---\n");

    char strings_file_path[MAX_LENGTH_FILEPATH_EX2];
    strcpy(strings_file_path, FILEPATH_EX2);
    char* lines[MAX_NUM_LINES_EX2];

    // Assign memory for each line;
    int max_line_length = (MAX_STRING_LENGTH_EX2 + 1)* 2 + 1;
    for (int i = 0; i < MAX_NUM_LINES_EX2; i++) {
        lines[i] = (char*)malloc(max_line_length * sizeof(char));
    }

    int number_read_lines = read_lines_file(strings_file_path, lines, max_line_length);
    if (number_read_lines != ERROR_FILE) {
        printf("Read %d lines from file: %s\n", number_read_lines, strings_file_path);
        press_key("Press <ENTER> to continue\n");

        int num_line = 0;
        // We need string1 to be big enough to contain the concatenation of both strings in exercise 2.3.2.
        char string1[2*MAX_STRING_LENGTH_EX2 + 1];
        char string2[MAX_STRING_LENGTH_EX2 + 1];
        while (num_line < number_read_lines) {
            if (sscanf(lines[num_line], "%s %s", string1, string2) == 2) {
                printf("Read strings '%s' and '%s'.\n", string1, string2);

                /* 2.1 - Are strings reversed? */
                printf("'%s' is", string1);
                if (!is_reverse(string1, string2)) {
                    printf(" not");
                }
                printf(" the reverse of '%s'\n", string2);

                /* 2.2 - Count occurrences of substring */
                int count = count_substring(string1, string2);
                if (count > 0) {
                    printf("'%s' occurs %d times in '%s'\n", string2, count, string1);
                } else {
                    printf("'%s' does not occur in '%s'\n", string2, string1);
                }

                /* 2.3.1 - Concatenate two strings and returns the result */
                char* str_concat = concat_strings(string1, string2);
                printf("The concatenation of '%s' and '%s' is '%s'\n", string1, string2, str_concat);
                free(str_concat);

                /* 2.3.1 - Concatenate two strings and return the result in the first string */
                printf("The concatenation of '%s' and '%s' is ", string1, string2);
                concat_strings_mod(string1, string2);
                printf("'%s'\n", string1);

            }
            press_key("Press <ENTER> to continue\n");
            num_line++;
        }
    } else { // read_lines_file returned ERROR_FILE.
        printf("The file %s could not be read.\n", strings_file_path);
    }

    // Free the dynamically allocated memory.
    for (int i = 0; i < MAX_NUM_LINES_EX2; i++) {
        free(lines[i]);
    }

}