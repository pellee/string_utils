#include <stdio.h>
#include <string.h>
#include "commands/count.h"


int main(int argc, const char **argv) {

  if (strcmp(argv[1], "-wc") == 0)
    word_count((char *)argv[2]);
  else if (strcmp(argv[1], "-vc") == 0)
    vowel_count(argv[2]);
  else if (strcmp(argv[1], "-cc") == 0)
    letter_count(argv[2]);
  else if (strcmp(argv[1], "-cnc") == 0)
    consonant_count(argv[2]);
  else
    printf("command not found\n");

  return 0;
}
