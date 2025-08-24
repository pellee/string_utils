#include "commands/count.h"
#include <stdio.h>
#include <string.h>

int validate_commands(const char *cmd) {
  const char *commands[] = {"count"};
  const int VALID_CMD_LENGTH = 1;

  for (int i = 0; i < VALID_CMD_LENGTH; i++) {
    if (strcmp(commands[i], cmd) == 0) {
      return i + 1;
    }
  }

  return 0;
}

int validate_mandatory_flags(const char *mflag) {
  const char *flags[] = {"--text", "-t", "--file", "file"};
  const int VALID_MANDATORY_FLAGS_LENGTH = 2;

  for (int i = 0; i < VALID_MANDATORY_FLAGS_LENGTH; i++) {
    if (strcmp(flags[i], mflag) == 0) {
      switch (i) {
      case 0:
      case 1:
        return 1;
      case 2:
      case 3:
        return 2;
      }
    }
  }

  return 0;
}

int validate_flags(const char *flag) {
  const char *flags[] = {"--words",       "-w", "--vowels",    "-v",
                         "--letters",     "-l", "--consonats", "-c",
                         "--puntuaction", "-p"};
  const int VALID_FLAGS_LENGTH = 10;
  int i;

  for (i = 0; i < VALID_FLAGS_LENGTH; i++) {
    if (strcmp(flags[i], flag) == 0) {
      switch (i) {
      case 0:
      case 1:
        return 1;
      case 2:
      case 3:
        return 2;
      case 4:
      case 5:
        return 3;
      case 6:
      case 7:
        return 4;
      case 8:
      case 9:
        return 5;
      }
    }
  }

  return 0;
}

int main(int argc, const char **argv) {
  int selected_cmd = validate_commands(argv[1]);
  if (selected_cmd == 0) {
    printf("command not found!\n");
    return 0;
  }

  int selected_mflag = validate_mandatory_flags(argv[2]);
  if (selected_mflag == 0) {
    printf("mandatory flag not found!\n");
    return 0;
  }

  const char *text = strdup(argv[3]);
  int selected_flag = validate_flags(argv[4]);

  int verbose_flag = 0;
  if (strcmp(argv[5], "-V") == 0) {
    verbose_flag = 1;
  }

  switch (selected_flag) {
  case 1:
    word_count((char *)text);
    break;
  case 2:
    vowel_count(text, &verbose_flag);
    break;
  case 3:
    letter_count(text);
    break;
  case 4:
    consonant_count(text);
    break;
  case 5:
    puntaction_marks_count(text);
    break;
  default:
    printf("flag not found!\n");
  }

  return 0;
}
