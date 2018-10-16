#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "outname.h"

char * computeOutputFileName(const char * inputName) {
  //WRITE ME

  size_t len;
  char *outName;

  len = strlen(inputName);
  outName = malloc(len + 8);
  memcpy(outName, inputName, len);
  memcpy(outName + len, ".counts",8);
  return outName;
}
