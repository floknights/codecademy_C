int main() {

  double weight;
  int planet;

  printf("Please enter your current weight on Earth: ");
  scanf("%lf", &weight);
 
  printf("\nPlease choose from the following planets:\n\n");
  printf("1. Mercury\n2. Venus\n3. Mars\n4. Jupiter\n");
  printf("5. Saturn\n6. Uranus\n7. Neptune\n\n");
 
  printf("Which planet are you visiting? ");
  scanf("%d", &planet);
 
  switch (planet) {
  case 1:
    weight = weight * 0.38;
    break;
  case 2:
    weight = weight * 0.91;
    break;
  case 3:
    weight = weight * 0.38;
    break;
  case 4:
    weight = weight * 2.34;
    break;
  case 5:
    weight = weight * 1.06;
    break;
  case 6:
    weight = weight * 0.92;
    break;
  case 7:
    weight = weight * 1.19;
    break;
  default:
    printf("Error: Invalid planet.\n");
  }
  printf("\nYour weight on %d is %lf\n", planet, weight);
}
