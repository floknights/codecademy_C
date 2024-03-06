#include <stdio.h>
#include <stdbool.h>
bool leapYear(int year) {
  return (year % 4 == 0 && (year % 100 || year % 400 == 0));
}

int main() {
  int year = 0;

  printf("Enter a year between 1800 and 10000: ");
  scanf("%d", &year);

  if (leapYear(year)) printf("%d is a leap year.", year);
  else printf("%d is not a leap year.", year);
}
