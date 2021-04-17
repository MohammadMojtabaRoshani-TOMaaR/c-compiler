#include <stdio.h>
#include "include/c.h"

int main(int argc, char* argv[]) {
    if (argc < 2){
        printf("ERROR: THE INPUT FILE MUSE BE SPECIFIED\n");
        return 1;
    }

    c_compiler_file(argv[1]);
    printf("INFO[compiler]: EXIT\n");
    return 0;
}
