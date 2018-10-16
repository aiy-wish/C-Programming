#include <stdio.h>
#include <stdlib.h>

unsigned power(unsigned x, unsigned y);

void test(unsigned x, unsigned y, unsigned expected_answer){
  if(power(x,y) != expected_answer){
    exit(EXIT_FAILURE);
  }
}

int main(){
  
  test(2,2,4);
  test(9,4,6561);
  test(0,0,1);
  test(1,1,1);
  test(7,5,16807);
  test(2.0,4,16);
  test(4,2.0,16.0);
  test(4.0,2.0,16.0);
  test(8,0,1);
  //test(5.2,2,27.04);
  test(-2,2,4);
  test(2,10,1024);
  test(4,0,1);
  test(2,1,2);
  test(-2,1,-2);
  test(-0.4,2,0.16);
  
}
