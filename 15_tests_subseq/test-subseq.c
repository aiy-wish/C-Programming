#include <stdio.h>
#include <stdlib.h>

size_t maxSeq(int * array, size_t n);

void test(int * array, size_t n, size_t correct){
  if(maxSeq(array, n) != correct){
    exit(EXIT_FAILURE);
  }
}

int main(){

  int array1[] = {1,2,3,4};
  test(array1,4,4);

  int array2[] = {1,2,3,4,5};
  test(array2,5,5);

  int array3[] = {1,2,3,3,4,5};
  test(array3,6,3);
  
  int array4[] = {9,8,7,6,5};
  test(array4,5,1);

  int array5[] = {};
  test(array5,0,0);

  int array6[] = {1};
  test(array6,1,1);

  int array7[] = {1,2,-5,-4,-3};
  test(array7,5,3);
  
  return EXIT_SUCCESS;

}
