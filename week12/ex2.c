#include <linux/input.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

int main() {
    struct input_event bb[64];
    int a;
    int write = open("/dev/input/by-path/platform-i8042-serio-0-event-kbd", O_RDONLY);
    while (1) {
        int readd = read(write, bb, sizeof(bb));
        for (int i = 0; i < (int) (write / sizeof(struct input_event)); i++) {
            if (bb[i].type != EV_KEY || bb[i].value == 2){
              a = 1;
            }else{
              if (bb[i].value == 1) {
                printf("1 0x%x (%d)\n", bb[i].code, bb[i].code);
              } else {
                printf("0 0x%x (%d)\n", bb[i].code, bb[i].code);
              }
            }
        }

    }
    return 0;
}