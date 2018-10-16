#include <stdio.h>
#include <stdlib.h>

size_t maxSeq(int * array, size_t n){

  size_t longest = 0;

  if(n == 0){
    return longest;
  }
  else{
    size_t maxSeq = 1;
    size_t currentMaxSeq = 1;
    longest = 1;

    for(size_t i = 0; i < (n-1); i++){
      if(array[i] < array[i+1]){
	longest++;
	currentMaxSeq = longest;

	if(currentMaxSeq > maxSeq){
	  maxSeq = currentMaxSeq;
	}
      }
      else{
	longest = 1;
	currentMaxSeq = longest;
      }
    }
    return maxSeq;
  }
}
