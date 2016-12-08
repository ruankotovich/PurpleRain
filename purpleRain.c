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

#define CALM 200
#define SOFT 100
#define HARD 50

void setup(int speed, int raindrops, int rows){
  int i,j, startY;

  char* matrix[raindrops][rows];

  for(i=0;i<raindrops;i++){
    for (j = 0; j < rows; j++) {
      matrix[i][j] = rand()%2? (rand()%2? " ┋ ": " ┊ ") : "   ";
    }
  }

  startY = 0;
  while(1){

    printf("%sOne more day to regret...\n",MAG);

    for(i=rows;i >= 0;i--){
      for (j=0; j < raindrops; j++) {
        printf("%s",matrix[(i+startY) % rows][j]);
        if(i==startY){
          matrix[i][j] = rand()%2? (rand()%2? " ┋ ": " ┊ ") : "   ";
        }
      }
      printf("\n");
    }

    clear();
    usleep(speed << 10);
    fflush(stdout);
    startY = startY+1 % rows;
  }
}

int main(int argc, char **argv) {
  clear();
  srand(time(NULL));
  int a = 40, b = 20;
  int type = HARD;

  if(argc == 4){
    a = atoi(argv[1]);
    b = atoi(argv[2]);
    type = atoi(argv[3]);
  }
  
  setup(type,a,b);
}
