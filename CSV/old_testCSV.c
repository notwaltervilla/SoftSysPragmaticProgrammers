#include<stdio.h>
#include <stdlib.h>
#include<string.h>

// for now, check if can locate target spot
void locate_point_in_csv(char *file, int c, int r) {
    FILE* fp = fopen(file, "r");
    if (!fp) printf("Can't open file (loc_func)\n"); 
    else {
        char buffer[1024];
        int column;
        int row = 0;
        
        while (fgets(buffer, 1024, fp)) {
            column = 0;
            char* value = strtok(buffer, ", ");
            while (value) {
                if (column == c && row == r) printf("*");
                printf("%s ", value);
                value = strtok(NULL, ", ");
                column++;
            }
            row++;
        }
        printf("\n");
        fclose(fp);
    }
}