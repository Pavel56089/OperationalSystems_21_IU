#include <stdlib.h>
#include <string.h>
#include <unistd.h>
int main(void) {
  
  char *p;
  for (int i=0;i<10;i++){
    p = malloc(10485760);
    memset(p, '0', 10485760);
    sleep(1);
  }
  return 0;
}

//When the process has lack of virtual memory, it starts to use swap memory. Also I saw quite freeze when so become too high.