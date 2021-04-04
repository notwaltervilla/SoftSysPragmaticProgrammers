#include<stdio.h>
#include <stdlib.h>
#include<string.h>


// initialize CSV files with values 0
void new_csv(char *filename, char* names[], int num_of_users) {
// void new_csv(char *filename, char names[][10], int num_of_users) {
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
        // implementation-defined?
        // https://stackoverflow.com/questions/41926099/does-the-c-rename-function-delete-files
        rename(new_file, file);
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
        DONE create new CSV, input names
        -    add new person to CSV
        -    log an expense
        -    log a settlement
        -    output personal bill
        -    view exchanges for input person

 */
void create_csv_action() {

    char file_str[100];
    char name_str[500];
    char n_of_users[3];
    int num_of_users;

    printf("Enter filename: ");
    fgets(file_str, 100, stdin);

    printf("Enter number of users: ");
    fgets(n_of_users, 3, stdin);
    num_of_users = atoi(n_of_users);

    char* names_arr[num_of_users];
    printf("Enter user names: ");
    fgets(name_str, 500, stdin);
    char* name = strtok(name_str, " \n");
    int name_i = 0;
    while (name) {
        names_arr[name_i] = name;
        name = strtok(NULL, " \n");
        name_i++;
    }

    new_csv(file_str, names_arr, num_of_users);

}

void change_point_in_csv_action() {

    char file_str[100];
    char first[3];
    char second[3];
    char change[3];
    int one, two, ch;

    printf("Enter filename: ");
    fgets(file_str, 100, stdin);

    printf("Enter first value: ");
    fgets(first, 3, stdin);
    one = atoi(first);

    printf("Enter second value: ");
    fgets(second, 3, stdin);
    two = atoi(second);

    printf("Enter change value: ");
    fgets(change, 3, stdin);
    ch = atoi(change);

    printf("1: %d\n", one);
    printf("2: %d\n", two);
    printf("change: %d\n", ch);

    change_point_in_csv(file_str, one, two, ch);
}

int main() {

    char action[3];

    printf("What would you like to do? (Input Number)\n");
    fgets(action, 3, stdin);
    int action_num = atoi(action);
    switch(action_num) {
        case 0:
            create_csv_action();
            break;

        case 1:
            change_point_in_csv_action();
            break;

        /* you can have any number of case statements */
        default : /* Optional */
            printf("default");
    }
}