#include<stdio.h>
#include <stdlib.h>
#include<string.h>

// create CSV file of given array values
void create_csv(char *filename, int a[][4], char names[][10], int num_of_users) {
    FILE *file;
    // filename=strcat(filename,".csv");
    file = fopen(filename,"w+");
    fprintf(file,"Name Walter Melody Simrun Patrick");
    
    for(int i = 0; i < num_of_users; i++){
        fprintf(file, "\n%s", names[i+1]);
        for(int j = 0; j < num_of_users; j++) {
            fprintf(file," %d", a[i][j]);
        }
    }
    fclose(file);
}

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

int main() {
 
    int a[4][4]={{1,2,3,3},{4,5,6,6},{7,8,9,9},{7,8,9,9}};
    // int a[3][3] = {0};
    // char names[][10] = {"Name", "Walter", "Melody", "Simrun", "Patrick"};
    char names_arr[][10] = {"Walter", "Melody", "Simrun", "Patrick"};
    char file_str[100];
    
    printf("Enter the filename: ");
    fgets(file_str, 500, stdin);
    // create_csv(file_str, a, names, 4);
    new_csv(file_str, names_arr, 4);
    // print_csv(file_str);
    // change_point_in_csv(file_str, 1, 1, 2);

    return 0;
}
