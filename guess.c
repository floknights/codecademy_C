#include <stdio.h>

int main() {

  int guess;
  int tries = 0;

  printf("I’m thinking of a number between 1 and 10.\n");
  printf("Try to guess the number: ");
  scanf("%d", &guess);

  while (guess != 8 && tries < 50) {
  printf("Wrong number, guess again: ");
  scanf("%d", &guess);
  tries++;
}

  if (guess == 8) {
    printf("You got it!\n");
  }
}
