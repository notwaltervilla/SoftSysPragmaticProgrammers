#include<stdio.h>
#include <stdlib.h>
#include<string.h>


void create_csv(char *filename, int a[][3], char names[][10], int n, int m) {

    FILE *fp;
    // filename=strcat(filename,".csv");
    fp=fopen(filename,"w+");
    fprintf(fp,"Name Walter Melody Simrun");
    
    for(int i = 0; i < m; i++){
        fprintf(fp, "\n%s", names[i+1]);
        for(int j = 0; j < n; j++) {
            fprintf(fp," %d", a[i][j]);
        }
    }
    fclose(fp);
}

void change_point_in_csv(char *file, int c, int r, int change) {

    FILE* fp = fopen(file, "r");
    if (!fp) printf("Can't open file (loc_func)\n"); 
    else {
        // create new csv which we will copy all values from old csv into, except for changed value
        FILE *new_fp;
        char *new_file = "newfile";
        new_fp = fopen(new_file,"w+");
        char buffer[1024];
        int column;
        int row = 0;
        
        while (fgets(buffer, 1024, fp)) {
            column = 0;
            char* value = strtok(buffer, " \n");
            while (value) {
                if (column == c && row == r) {
                    int num = atoi(value);
                    num += change;
                    fprintf(new_fp, "%d ", num);
                }
                else (fprintf(new_fp,"%s ", value));
                value = strtok(NULL, " \n");
                column++;
            }
            fprintf(new_fp,"\n");
            row++;
        }
        fclose(fp);
        fclose(new_fp);

        rename(new_file, file);
        remove(file);
    }
}

void print_csv(char *file_path) {
    FILE* file = fopen(file_path, "w+");
    if (!file) printf("Can't open file (print_func)\n"); 
    else {
        char buffer[1024];
        while (fgets(buffer, 1024, fp)) {
            char* value = strtok(buffer, " ");
            while (value) {
                printf("%s ", value);
                value = strtok(NULL, " ");
            }
        }
        printf("\n");
        fclose(fp);
    }
}

/*  TODO:
    Functions to
        - create new CSV, input names
        - add new person to CSV
        - log an expense
        - log a settlement
        - output personal bill
        - view exchanges for input person

 */
int main() {
 
    int a[3][3]={{1,2,3},{4,5,6},{7,8,9}};
    // int a[3][3] = {0};
    char names[5][10] = {"Name", "Walter", "Melody", "Simrun", "Patrick"};
    char str[100];
    printf("Enter the filename: ");
    fgets(str, 500, stdin);
    create_csv(str, a, names, 3, 3);
    // print_csv(str);
    // change_point_in_csv(str, 1, 1, 2);

    return 0;
 
}
