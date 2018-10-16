#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//This function is used to figure out the ordering
//of the strings in qsort.  You do not need
//to modify it.
int stringOrder(const void * vp1, const void * vp2) {
  const char * const * p1 = vp1;
  const char * const * p2 = vp2;
  return strcmp(*p1, *p2);
}
//This function will sort and print data (whose length is count).
void sortData(char ** data, size_t count) {
  qsort(data, count, sizeof(char *), stringOrder);
}



int main(int argc, char ** argv){
  /**
  if(argc == 0){
    fprintf(stderr, "few arguments \n");
    return EXIT_FAILURE;
  }
  else if (argc == 1){
    char ** arr = NULL;
    char * line = NULL;
    size_t sz = 0;
    int i = 0;
    while (getline(&line,&sz,stdin)>=0){
      arr = realloc(arr,(i+1)*sizeof(*arr));
      arr[i] = line;
      line = NULL;
      i++;
    }
    free(line);
    sortData(arr,i);
    for(int j =0; j<1; j++){
      printf("%s",arr[j]);
      free(arr[j]);
    }
    free(arr);
  }
  else{
    for(int x = 1; x<argc; x++){
      char ** arr = NULL;
      char * line = NULL;
      size_t sz = 0;
      int i = 0;
      FILE *f = fopen(argv[x],"r");
      if(f == NULL){
	perror("Could not open file");
	return EXIT_FAILURE;
      }
      while(getline(&line,&sz,f)>=0){
	arr = realloc(arr,(i+1)*sizeof(*arr));
	arr[i] = line;
	line = NULL;
	i++;
      }
      free(line);
      sortData(arr,i);
      for(int j = 0; j<i; j++){
	printf("%s",arr[j]);
	free(arr[j]);
      }
      free(arr);
      if(fclose(f)!=0){
	perror("Failed to close the input file!");
	return EXIT_FAILURE;
      }
    }
  **/

  if(argc==1){
    FILE * f = stdin;
    if(f==NULL){
      fprintf(stderr,"Failed to open file from stdin\n");
      return EXIT_FAILURE;
    }

    size_t j =0;
    char ** lines = NULL;
    char * line = NULL;
    size_t sz = 0;
    while(getline(&line,&sz,f)>=0){
      lines = realloc(lines,(j+1)*sizeof(*lines));
      lines[j] = line;
      line = NULL;
      j++;
    }
    free(line);

    if(j==0){
      fprintf(stderr,"Input must contain at least one line of text.\n");
      return EXIT_FAILURE;
    }

    sortData(lines,j);

    int k;
    for(k=0;k<j;k++){
      printf("%s\n",lines[k]);
    }

    for(k=0; k<j;k++){
      free(lines[k]);
    }
    free(lines);
    if(fclose(f)!=0){
      perror("Failed to close the file!");
      return EXIT_FAILURE;
    }
  }
  else{
    size_t i = 1;
    while (i<argc){
      FILE *f = fopen(argv[i],"r");
      if(f==NULL){
	fprintf(stderr,"Failed to open file: %s\n",argv[i]);
	return EXIT_FAILURE;
      }
      size_t j = 0;
      char ** lines = NULL;
      char * line = NULL;
      size_t sz = 0;
      while(getline(&line,&sz,f)>=0){
	lines = realloc(lines,(j+1)*sizeof(*lines));
	lines[j] = line;
	line = NULL;
	j++;
      }
      free(line);
      if(j==0){
	fprintf(stderr,"File (%s) must contain at least one line of text.\n",argv[i]);
	return EXIT_FAILURE;
      }
      sortData(lines,j);
      int k;
      for(k =0; k<j;k++){
	printf("%s\n",lines[k]);
      }

      for(k =0;k<j;k++){
	free(lines[k]);
      }
      free(lines);
      i++;
      if(fclose(f)!=0){
	perror("Failed to close the file!");
	return EXIT_FAILURE;
      }
    }
  } //WRITE YOUR CODE HERE!
  return EXIT_SUCCESS;
}
