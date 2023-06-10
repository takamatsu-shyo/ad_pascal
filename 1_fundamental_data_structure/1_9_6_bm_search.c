#include <stdio.h>
#include <string.h>

#define ASCII_SIZE 128

int bm_seach(char *text, char *pattern, int pattern_len, int text_len){

    printf("--Table--\n");
    int text_index, pattern_index, skip_index;
    int shift_table[ASCII_SIZE];

    for (text_index = 0; text_index < ASCII_SIZE; text_index++)
        shift_table[text_index] = pattern_len;

    for (pattern_index = 0; pattern_index < pattern_len - 1; pattern_index++)
    {
        int shift = pattern_len - pattern_index - 1;
        unsigned char pattern_char = (unsigned char)pattern[pattern_index];
        shift_table[pattern_char] = shift;
    }

    for (text_index = 32; text_index < ASCII_SIZE; text_index++)
    {
        printf("%c", text_index);
    }
    printf("\n");
 
    for (text_index = 32; text_index < ASCII_SIZE; text_index++)
    {
        printf("%d", shift_table[text_index]);
    }
    printf("\n");
 

    printf("--Search--\n");

    for (int text_index = pattern_len - 1; text_index < text_len;){
        int pattern_index = pattern_len - 1;

        printf("Compare: %c-%c\n", text[text_index], pattern[pattern_index]);
        while (text[text_index] == pattern[pattern_index])
        {
            printf("Match: %c-%c\n", text[text_index], pattern[pattern_index]);
            if (pattern_index == 0)
                return text_index;
            text_index--;
            pattern_index--;
        }
        skip_index = shift_table[(unsigned char)text[text_index]];
        text_index += (pattern_len - pattern_index > skip_index) ? pattern_len - pattern_index : skip_index;
        printf("Next text_index: %d\n", text_index);

    }

    return -1;
}

int main(){
    char text[] = "Hoola-Hoola girls like Hooligans.";
    char pattern[] = "Hooligan";

    printf("--Input--\n");
    printf("Text   : %s\n", text);
    printf("Pattern: %s\n", pattern);
 
    int position = bm_seach(text, pattern, strlen(pattern), strlen(text));

    if (position != -1)
        printf("Pattern found at %d.\n.", position);
    else
        printf("Pattern not found.\n");

    return 0;
}

