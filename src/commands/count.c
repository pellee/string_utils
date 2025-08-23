#include <ctype.h>
#include <stdio.h>
#include <string.h>

const char *DELIMITER = " ";
const int VOWELS_QUAN = 5;

void word_count(char *str) {
  const char *str_token = strtok(str, DELIMITER);
  int word_count = 0;

  while (str_token != NULL) {
    word_count++;
    str_token = strtok(NULL, DELIMITER);
  }

  printf("word count: %d\n", word_count);
}

void letter_count(const char *str) {
  int chars_count = 0;
  for (int i = 0; i < strlen(str); i++) {
    if (str[i] != ' ')
      chars_count++;
  }
  printf("letters found: %d\n", chars_count);
}

void consonant_count(const char *str) {
  const char consonants[] = "BCDFGHJKLMNPQRSTVWXYZ";
  int consonants_found = 0;

  for (int i = 0; i < strlen(str); i++) {
    for (int j = 0; j < strlen(consonants); j++) {
      if (toupper(str[i]) == consonants[j]) {
        consonants_found++;
      }
    }
  }

  printf("consotants found: %d\n", consonants_found);
}

void vowel_count(const char *str) {
  const char vowels[] = "AEIOU";
  int vowels_found = 0;

  for (int i = 0; i < strlen(str); i++) {
    for (int j = 0; j < VOWELS_QUAN; j++) {
      if (toupper(str[i]) == vowels[j])
        vowels_found++;
    }
  }

  printf("vowels found: %d\n", vowels_found);
}
