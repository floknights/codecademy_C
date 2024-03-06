#include <stdio.h>
#include <stdbool.h>

bool leapYear(int yy) { //checks for leap year
  return (yy % 4 == 0 && (yy % 100 || yy % 400 == 0));
}

int daysinMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; //lists the number of days in each month

void addtoDate(int* dd, int* mm, int* yy, int daysleftAdd) {
  int daysleftMonth; //number of days left in the current month
  while (daysleftAdd > 0) {
    daysleftMonth = daysinMonth[*mm] - *dd;
    if (*mm == 2 && leapYear(*yy)) { //checks for February & leap year
      daysleftMonth++; //adds a leap day
    }
    if (daysleftAdd > daysleftMonth) {
      daysleftAdd -= daysleftMonth + 1; //reduces days left to add by number of days until the next month
      *dd = 1; //resets to 1st of the month
      if (*mm == 12) { //checks if we are in December
        *mm = 1; //the next month is January
        *yy = *yy + 1; //increase year by 1
    } else *mm = *mm + 1; //increase month by 1
  } else {
      *dd = *dd + daysleftAdd; //adds number of days left to add to current date
      daysleftAdd = 0;
    }
  }
}

int main() {
  int dd, mm, yy, daysleftAdd;

  printf("Please enter a date between the years 1800 and 9999 in the format DD/MM/YYYY: \n");
  scanf("%d/%d/%d", &dd, &mm, &yy);

  printf("Please enter the number of days you would like to add to this date: \n");
  scanf("%d", &daysleftAdd);

  addtoDate(&dd, &mm, &yy, daysleftAdd);
  printf("The new date is %d/%d/%d.\n", dd, mm, yy);
}
