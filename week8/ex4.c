#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/resource.h>

int main(void) {
  
  char *p;
  struct rusage usage;
  for (int i=0;i<10;i++){
    p = malloc(10485760);//allocate
    memset(p, '0', 10485760);//fill it with zeros
    getrusage(RUSAGE_SELF, &usage);//get info
    printf("Memory usage %ld (KB)\n", usage.ru_maxrss);
    sleep(1);
  }
  return 0;
}
