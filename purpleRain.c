#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define BLU   "\x1B[34m"
#define MAG   "\x1B[35m"
#define CYN   "\x1B[36m"
#define WHT   "\x1B[37m"
#define RESET "\x1B[0m"
#define clear() printf("\033[H\033[J")

#define RAINDROPS 40
#define ROWS 20

void setup(){
  int i,j, startY;

  char* matrix[RAINDROPS][ROWS];

  for(i=0;i<RAINDROPS;i++){
    for (j = 0; j < ROWS; j++) {
      matrix[i][j] = rand()%2? (rand()%2? " ┋ ": " ┊ ") : "   ";
    }
  }

  startY = 0;
  while(1){

    printf("%sOne more day to regret...\n",MAG);

    for(i=ROWS;i >= 0;i--){
      for (j=0; j < RAINDROPS; j++) {
        printf("%s",matrix[(i+startY) % ROWS][j]);
        if(rand() % 3 && i==0){
          matrix[i][j] = rand()%2? (rand()%2? " ┋ ": " ┊ ") : "   ";
        }
      }
      printf("\n");
    }

    clear();
    usleep(50000);
    fflush(stdout);
    startY = startY+1 % ROWS;
  }
}

int main() {
  clear();
  srand(time(NULL));
  setup();
}
