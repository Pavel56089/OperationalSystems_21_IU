//
// Created by Павел Бахаруев on 14.09.2021.
//

#include <unistd.h>

int main() {

    for (int i = 0; i < 5; i++) {
        fork();
        sleep(5);
    }

    return 0;

}
/*
 * output for 3:
a.out─┬─a.out───a.out
      └─a.out
a.out─┬─a.out─┬─a.out───a.out
      │       └─a.out
      ├─a.out───a.out
      └─a.out

 * output for 5:
a.out─┬─a.out─┬─a.out─┬─a.out─┬─a.out───a.out
      │       │       │       └─a.out
      │       │       ├─a.out───a.out
      │       │       └─a.out
      │       ├─a.out─┬─a.out───a.out
      │       │       └─a.out
      │       ├─a.out───a.out
      │       └─a.out
      ├─a.out─┬─a.out─┬─a.out───a.out
      │       │       └─a.out
      │       ├─a.out───a.out
      │       └─a.out
      ├─a.out─┬─a.out───a.out
      │       └─a.out
      ├─a.out───a.out
      └─a.out
2^3=8 processes
2^5 = 32 processes
 */