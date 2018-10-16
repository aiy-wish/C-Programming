#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int findMaxIdx(int array[], int n){
  int maxIdx = 0;

  for(int i = 0; i<n;i++){
    if(array[i] > array[maxIdx]){
      maxIdx = i;
    }
  }
  return maxIdx;
}



int getKey(FILE *f){
  int freq[26]={0};
  int ch = 0;
  int maxIdx;
  
  while((ch = fgetc(f)) != EOF){
    if(isalpha(ch)){
      freq[tolower(ch) - 'a']++;
    }
  }
  maxIdx = findMaxIdx(freq,26);
  return (maxIdx +22)%26;
}

int main (int argc, char ** argv){
  FILE * f;
  int key;
  
  if(argc != 2){
    fprintf(stderr,"Usage: %s file\n",argv[0]);
   return EXIT_FAILURE;
  }

  f = fopen(argv[1], "r");
  if(f == NULL){
    fprintf(stderr,"Failed to open file %s\n",argv[1]);
    return EXIT_FAILURE;
  }

  key = getKey(f);
  printf("%d\n",key);

  fclose(f);
  
  return EXIT_SUCCESS;
}
    
