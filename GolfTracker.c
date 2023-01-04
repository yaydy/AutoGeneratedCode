#include <stdio.h>
#include <stdlib.h>

#define MAX_PLAYERS 10
#define MAX_HOLES 18

struct player {
  char name[32];
  int scores[MAX_HOLES];
};

int main(void) {
  int num_players, num_holes;
  printf("Enter the number of players: ");
  scanf("%d", &num_players);
  
  printf("Enter the number of holes: ");
  scanf("%d", &num_holes);
  
  struct player players[MAX_PLAYERS];
  
  for (int i = 0; i < num_players; i++) {
    printf("Enter the name of player %d: ", i + 1);
    scanf("%s", players[i].name);
  }
  
  for (int i = 0; i < num_players; i++) {
    printf("Enter the scores for %s: ", players[i].name);
    for (int j = 0; j < num_holes; j++) {
      scanf("%d", &players[i].scores[j]);
    }
  }
  
  printf("\n");
  printf("Scores:\n");
  for (int i = 0; i < num_players; i++) {
    printf("%s: ", players[i].name);
    int total_score = 0;
    for (int j = 0; j < num_holes; j++) {
      printf("%d ", players[i].scores[j]);
      total_score += players[i].scores[j];
    }
    printf("(Total: %d)", total_score);
    printf("\n");
  }
  
  return 0;
}
