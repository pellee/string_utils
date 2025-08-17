#include <stdio.h>
#include <string.h>

const char *DELIMITER = " ";

void wordCount(char *str_original) {
  const char *str_token = strtok(str_original, DELIMITER);
  int word_count = 0;

  while (str_token != NULL) {
    word_count++;
    str_token = strtok(NULL, DELIMITER);
  }

  printf("word count: %d\n", word_count);
}

int main(int argc, const char **argv) {

  if (strcmp(argv[1], "-wc") != 0) {
    printf("command not found\n");
    return 0;
  }
  wordCount((char *)argv[2]);
  return 0;
}
