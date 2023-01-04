#include <stdio.h>
#include <string.h>

char* reverse_string(const char* str) {
  // Allocate a buffer for the reversed string
  size_t len = strlen(str);
  char* reversed = malloc(len + 1);

  // Reverse the string
  for (size_t i = 0; i < len; i++) {
    reversed[i] = str[len - i - 1];
  }
  reversed[len] = '\0';

  return reversed;
}
