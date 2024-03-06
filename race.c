#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

struct Race {
  int numberOfLaps;
  int currentLap;
  char firstPlaceDriverName[40];
  char firstPlaceRaceCarColor[20];
};
struct RaceCar {
  char driverName[40];
  char raceCarColor[20];
  int totalLapTime;
};

void printIntro(void) {
  printf("Welcome to our main event digital race fans!\nI hope everybody has their snacks because we are about to begin!\n");
}
void printCountDown() {
  printf("Racers ready! In...\n5\n4\n3\n2\n1\nRace!\n");
}
void printFirstPlaceAfterLap(struct Race race) {
  printf("After lap number %d:\n%s is in front with the %s race car!\n", race.currentLap, race.firstPlaceDriverName, race.firstPlaceRaceCarColor);
}
void printCongratulation(struct Race race) {
  printf("Lets all congratulate %s in the %s race car for an amazing performance.\nIt truly was a great race and everybody have a good night!", race.firstPlaceDriverName, race.firstPlaceRaceCarColor);
}

int calculateTimeToCompleteLap() {
  int speed = (rand() % 3) + 1;
  int acceleration = (rand() % 3) + 1;
  int nerves = (rand() % 3) + 1;
  return speed + acceleration + nerves;
}
void updateRaceCar(struct RaceCar* raceCar) {
  raceCar->totalLapTime += calculateTimeToCompleteLap();
}
void updateFirstPlace(struct Race* race, struct RaceCar* raceCar1, struct RaceCar* raceCar2) {
  if (raceCar1->totalLapTime <= raceCar2->totalLapTime) {
    strcpy(race->firstPlaceDriverName, raceCar1->driverName);
    strcpy(race->firstPlaceRaceCarColor, raceCar1->raceCarColor);
  } else {
    strcpy(race->firstPlaceDriverName, raceCar2->driverName);
    strcpy(race->firstPlaceRaceCarColor, raceCar2->raceCarColor);
  }
}
void startRace(struct RaceCar* raceCar1, struct RaceCar* raceCar2) {
  struct Race race = {5, 1, "", ""};
  for (race.currentLap = 1; race.currentLap <= race.numberOfLaps; race.currentLap++) {
    updateRaceCar(raceCar1);
    updateRaceCar(raceCar2);
    updateFirstPlace(&race, raceCar1, raceCar2);
    printFirstPlaceAfterLap(race);
  }
  printCongratulation(race);
}

int main() {
	srand(time(0));
  printIntro();
  printCountDown();

  struct RaceCar raceCar1 = {"Mario", "red", 0};
  struct RaceCar raceCar2 = {"Luigi", "green", 0};

  startRace(&raceCar1, &raceCar2);
  
};
