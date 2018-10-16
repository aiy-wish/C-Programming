#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "kv.h"

//Helper method
kvpair_t* splitPairs(char * str) {
  char * value1 = strchr(str,'=');
  *value1='\0';
  value1++;
  char * n = strchr(value1,'\n');
  if(n!=NULL){
    *n = '\0';
  }
  kvpair_t* pair = malloc((size_t)sizeof(*pair));
  pair->key=str;
  pair->value = value1;
  return pair;
}

kvarray_t * readKVs(const char * fname){
  //WRITE ME

  FILE * f = fopen(fname, "r");
  if(f ==NULL){
    perror("Could not open file");
    return NULL;
  }

  char * line = NULL;
  size_t sz = 0;
  kvpair_t * curr_pair = NULL;

  kvarray_t * kv_array = malloc ((size_t)(sizeof(*kv_array)));
  kv_array->size = 0;
  kv_array->arr = NULL;

  while(getline(&line,&sz,f)>=0){
    curr_pair = splitPairs(line);
    kv_array->arr = realloc(kv_array->arr,(kv_array->size+1)*sizeof(*kv_array->arr));
    kv_array->arr[kv_array->size] = curr_pair;
    kv_array->size++;
    line=NULL;
  }
  free(line);

  int result = fclose(f);
  if(result != 0){
    return NULL;
  }
  return kv_array;

    /**kvarray_t * kvarray = malloc(sizeof(*kvarray));
  kvarray->pairs = NULL;
  kvarray->length = 0;
  FILE *f = fopen(fname,"r");
  if(f==NULL){
    perror("open file failed\n");
    return NULL;
  }
  char * line = NULL;
  size_t sz;
  while((getline(&line,&sz,f)>=0)){
    char * lincpy = malloc((strlen(line)-1)*sizeof(*lincpy));
    for(int j = 0;j<strlen(line)-1;j++){
      lincpy[j] = line[j];
    }
    char * pch = strtok(lincpy,"=");
    char * key = pch;
    pch = NULL;
    pch = strtok(NULL,"=");
    char * value = pch;
    (kvarray->length)++;
    kvarray->pairs = realloc(kvarray->pairs,(kvarray->length)*sizeof(*(kvarray->pairs)));
    kvarray->pairs[(kvarray->length)-1].key = key;
    kvarray->pairs[(kvarray->length)-1].value = value;
    key = NULL;
    value = NULL;
    line = NULL;
    free(key);
    free(value);
  }
  free(line);

  if(fclose(f)<0){
    perror("close file failed\n");
    return NULL;
  }
  return kvarray;**/
  
}

void freeKVs(kvarray_t * pairs) {
  //WRITE ME
  for(int i =0;i<pairs->size;i++){
    free(pairs->arr[i]->key);
    free(pairs->arr[i]);
  }
  free(pairs->arr);
  free(pairs);
  /**for(int i=0;i<pairs->length;i++){
    free(pairs->pairs[i].key);
  }
  free(pairs->pairs);
  free(pairs);**/
}

void printKVs(kvarray_t * pairs) {
  //WRITE ME
  kvpair_t* curr_pair;
  for(int i=0;i<pairs->size;i++){
    curr_pair = pairs->arr[i];
    printf("key = '%s' value = '%s'\n",curr_pair->key,curr_pair->value);
    }
  /**for(int i = 0; i<pairs->length;i++){
    printf("keys is %s,value is %s\n",pairs->pairs[i].key,pairs->pairs[i].value);
    }**/
}

char * lookupValue(kvarray_t * pairs, const char * key) {
  //WRITE ME
  kvpair_t* curr_pair;
  for(int i=0;i<pairs->size;i++){
    curr_pair = pairs->arr[i];
    if(!strcmp(curr_pair->key,key)){
      return curr_pair->value;
    }
  }
  return NULL;

  /**for(int i =0; i<pairs->length;i++){
    if(strncmp(pairs->pairs[i].key,key,strlen(pairs->pairs[i].key))==0){
      return pairs->pairs[i].value;
    }
  }
  return NULL;**/
}
