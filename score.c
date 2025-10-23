#include <stdio.h>

int main(void) {
  int score;
  while(1) {
    printf("Enter the NFL score (Enter 1 to stop): ");
    if (scanf("%d", &score) != 1) {
      return 0;
    }
    if (score == 1) {
      break;
    }
    if (score <= 0) {
      printf("Invalid score.\n");
      continue;
    }
    printf("Possible combinations of scoring plays if a team's score is %d:\n", score);
    int td8, td7, td6, fg3, s2;
    for (td8 = 0; td8 <= score / 8; ++td8) {
      int rem8 = score - td8 * 8;
      for (td7 = 0; td7 <= rem8 / 7; ++td7) {
        int rem7 = rem8 - td7 * 7;
        for (td6 = 0; td6 <= rem7 / 6; ++td6) {
          int rem6 = rem7 - td6 * 6;
          for (fg3 = 0; fg3 <= rem6 / 3; ++fg3) {
            int rem3 = rem6 - fg3 * 3;
            if (rem3 % 2 == 0) {
              s2 = rem3 / 2;
              printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n", td8, td7, td6, fg3, s2);
            }
          }
        }
      }
    }
  }
  return 0;
}