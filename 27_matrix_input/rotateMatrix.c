#include <stdlib.h>
#include <stdio.h>
//#include <string.h>

#define COLS 10
#define ROWS 10

/**void rotate(FILE * f){
  char matrix[11][12];
  for(int i=0; i<10; i++){
    if(fgets(matrix[i],12,f)==NULL){
      fprintf(stderr,"File too short.\n");
      exit(EXIT_FAILURE);
    }
    if(strchr(matrix[i],'\n')==NULL){
      fprintf(stderr,"Line too long.\n");
      exit(EXIT_FAILURE);
    }
    if(*(strchr(matrix[i], '\n')+1) != '\0'){
      fprintf(stderr,"Line too short.\n");
      exit(EXIT_FAILURE);
    }
    
  }
  if(fgetc(f) != EOF){
    fprintf(stderr,"File too long.\n");
    exit(EXIT_FAILURE);
  }
  for(int i = 0; i<10; i++){
    for(int j=9; j>= 0; j--){
      printf("%c",matrix[j][i]);
    }
    printf("\n");
  }
  }**/

void error(const char *message){
  fprintf(stderr, "Invalid input: %s\n",message);
  exit(EXIT_FAILURE);
}

void read_line(char line[], FILE *f){
  int i;
  int ch;

  i=0;
  for(;;){
    ch = fgetc(f);
    switch(ch){
    case '\n':
      if(i==COLS){
	line[COLS] = '\0';
	return;
      }
      else{
	error("line is too short");
      }
      break;
    case EOF:
      if(i==COLS){
	error("unexpected EOF");
      }
      else{
	error("Line is too short");
      }
      break;
    default:
      if(i<COLS){
	line[i++] = (char) ch;
      }
      else{
	error("line is too long");
      }
      break;
    }
  }
}

void print_rotated(char M[ROWS][COLS]){
  int i;
  int j;
  for(i = 0; i<ROWS; i++){
    for(j = 0; j<COLS;j++){
      putchar(M[COLS-1-j][i]);
    }
    putchar('\n');
  }
}

int main(int argc, char ** argv){
  char matrix[ROWS][COLS];
  int i;
  int ch;

  if(argc != 2){
    fprintf(stderr, "Usage: rotateMatrix input\n");
    exit(EXIT_FAILURE);
  }

  FILE * f = fopen(argv[1], "r");
  if(f == NULL){
    fprintf(stderr,"Could not open %s\n",argv[1]);
    exit(EXIT_FAILURE);
  }
  for(i = 0; i<ROWS; i++){
    read_line(matrix[i],f);
  }

  if((ch = fgetc(f) != EOF)){
    fprintf(stderr,"Invalid input: file is too long (read %d instead of EOF)\n",ch);
    exit(EXIT_FAILURE);
  }
  fclose(f);

  print_rotated(matrix);
  
  return 0;
}
