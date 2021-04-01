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

// initialize CSV files with values 0
void new_csv(char *filename, char* names[], int num_of_users) {
    FILE *file;
    // filename=strcat(filename,".csv");
    file = fopen(filename,"w+");

    fprintf(file,"Name");
    for (int n = 0; n < num_of_users; n++) {
        fprintf(file, " %s", names[n]);
    }

    for(int i = 0; i < num_of_users; i++) {
        fprintf(file, "\n%s", names[i]);
        for(int j = 0; j < num_of_users; j++) {
            fprintf(file," %d", 0);
        }
    }
    fclose(file);
}

// Given row, col index, increment the value at that location by 'change'
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
        // rename updated file to original name, delete old file
        rename(new_file, file);
        remove(file);
    }
}

void print_csv(char *file_path) {
    FILE* file = fopen(file_path, "w+");
    if (!file) printf("Can't open file (print_func)\n"); 
    else {
        char buffer[1024];
        while (fgets(buffer, 1024, file)) {
            char* value = strtok(buffer, " ");
            while (value) {
                printf("%s ", value);
                value = strtok(NULL, " ");
            }
        }
        printf("\n");
        fclose(file);
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
// int main() {
 
//     int a[4][4]={{1,2,3,3},{4,5,6,6},{7,8,9,9},{7,8,9,9}};
//     // int a[3][3] = {0};
//     char names[][10] = {"Name", "Walter", "Melody", "Simrun", "Patrick"};
//     char names_arr[][10] = {"Walter", "Melody", "Simrun", "Patrick"};
//     char file_str[100];
    
//     printf("Enter the filename: ");
//     fgets(file_str, 500, stdin);
//     // create_csv(file_str, a, names, 4);
//     new_csv(file_str, names_arr, 4);
//     // print_csv(file_str);
//     // change_point_in_csv(file_str, 1, 1, 2);

//     return 0;
// }

int main() {

    char file_str[100];
    char name_str[500];
    char n_of_users[2];
    int num_of_users;

    printf("Enter filename: ");
    fgets(file_str, 100, stdin);

    printf("Enter number of users: ");
    fgets(n_of_users, 2, stdin);
    num_of_users = atoi(n_of_users);
    
    char* names_arr[num_of_users];
    printf("Enter user names: ");
    fgets(name_str, 500, stdin);

    // char* names_arr[num_of_users];
    // char* name = strtok(name_str, " ");
    // int name_i = 0;
    // while (name) {
    //     names_arr[name_i] = name;
    //     name = strtok(NULL, " ");
    //     name_i++;
    // }

    new_csv(file_str, names_arr, 4);
    // print_csv(file_str);
    // change_point_in_csv(file_str, 1, 1, 2);

    return 0;
 
}