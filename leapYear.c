#include <stdio.h>
#include <stdbool.h>
bool leapYear(int year) {
  if (year % 4 != 0) {
    return false;
} else if (year % 100 != 0) {
    return true;
} else if (year % 400 != 0) {
    return false;
} else {
    return true;
  }
}

int main() {
  int year = 0;

  printf("Enter a year between 1800 and 10000: ");
  scanf("%d", &year);

  if (leapYear(year)) printf("%d is a leap year.", year);
  else printf("%d is not a leap year.", year);
}
