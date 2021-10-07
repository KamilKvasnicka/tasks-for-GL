#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv) {
    if(argc != 3) {
        printf("You need to pass two numbers.\n");
        return 1;
    }
    
    int first_len = strlen(argv[1]);
    int second_len = strlen(argv[2]);

    char* p = (char*) calloc(first_len + second_len, sizeof(char));
    if(!p) {
        printf("Cannot allocate memory\n");
        return 1;
    }

    int offset = 0;
    int final_len = first_len + second_len;
    for(int i = second_len - 1, k = final_len - 1; i >= 0; i--, k--) {
        offset = 0;
        for(int j = first_len - 1, l = k; j >= 0; j--, l--) {
            int product = (argv[2][i] - '0') * (argv[1][j] - '0');
            p[l] = p[l] + product + offset;
            offset = p[l] / 10;
            p[l] %= 10;
            if(j == 0 && offset != 0) {
                p[l-1] = offset;
            }
        }
    }

    for(int m = 0; m < final_len; m++) p[m] = (char) (p[m] + '0');
    printf("%s * %s = %s\n", argv[1], argv[2], p);
    printf("\n");
    free(p);
    return 0;
}
