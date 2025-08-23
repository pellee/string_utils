#include <ctype.h>
#include <stdio.h>
#include <string.h>

const char *DELIMITER = " ";
const char CONSONANTS[] = "BCDFGHJKLMNPQRSTVWXYZ";
const char VOWELS[] = "AEIOU";
const char LETTERS[] = "AEIOUBCDFGHJKLMNPQRSTVWXYZ";

void word_count(char *str) {
  const char *str_token = strtok(str, DELIMITER);
  int word_count = 0;

  while (str_token != NULL) {
    word_count++;
    str_token = strtok(NULL, DELIMITER);
  }

  printf("word count: %d\n", word_count);
}

void chars_found_in_list(const char *input_str, const char *chars_list,
                         const char *text_to_print) {
  int char_count = 0;
  for (int i = 0; i < strlen(input_str); i++) {
    for (int j = 0; j < strlen(chars_list); j++) {
      if (toupper(input_str[i]) == chars_list[j]) {
        char_count++;
      }
    }
  }
  printf("%s found: %d\n", text_to_print, char_count);
}

void letter_count(const char *str) {
  chars_found_in_list(str, LETTERS, "letters");
}

void consonant_count(const char *str) {
  chars_found_in_list(str, CONSONANTS, "consonants");
}

void vowel_count(const char *str) {
  chars_found_in_list(str, VOWELS, "vowels");
}
