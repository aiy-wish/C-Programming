#include <stdio.h>
#include <stdlib.h>

unsigned power (unsigned x, unsigned y){

  unsigned answer = 0;

  if(y==0){
    return 1;
  }
  else if(y >0){
    return (x * power(x,y-1));
  }
  return answer;
}


  
  
