#include <stdio.h>
#include <dirent.h>

int main (void)
{
    struct dirent *file_in_folder;
    DIR *d;
    d = opendir("/");
    while ((file_in_folder = readdir(d)) != NULL) puts(file_in_folder->d_name);
    closedir(d);
    return 0;
}