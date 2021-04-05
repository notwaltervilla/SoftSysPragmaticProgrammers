#include<stdio.h>
#include <stdlib.h>
#include<string.h>

#define MAXLINE 200
#define USERNAME_MAX 20
#define MESSAGE_MAX 100


// initialize CSV file with values 0, generate bill txt files
void new_group_action(char* filename, char* names[], int num_of_users) {

    FILE *csv_file;
    FILE *bill_file;

    // filename=strcat(filename,".csv");
    csv_file = fopen(filename,"w+");

    fprintf(csv_file,"Name");
    for (int n = 0; n < num_of_users; n++) {
        fprintf(csv_file, " %s", names[n]);
    }

    for(int i = 0; i < num_of_users; i++) {
        // Set up CSV file
        fprintf(csv_file, "\n%s", names[i]);
        for(int j = 0; j < num_of_users; j++) {
            fprintf(csv_file," %d", 0);
        }

        // Create bill file
        bill_file = fopen(names[i],"w+");
        fclose(bill_file);
    }
    fclose(csv_file);
}

int user_to_index(char* filename, char *user) {

    FILE *file;
    char line[MAXLINE + 6];
    int loop_index = 0;
    int target_index = -1;

    file = fopen(filename,"r");
    if (fgets(line, sizeof (line), file)) {
        char* value = strtok(line, " \n");
        while (value) {
            // printf("value: %s, user: %s\n", value, user);
            if (strcmp(value, user) == 0) {
                target_index = loop_index;
                // printf("target i: %d\n", target_index);
            }
            value = strtok(NULL, " \n");
            loop_index++;
        }
    }

    return target_index;
}

// Given row, col index, increment the value at that location by 'change'
void change_point_in_csv_action(char *file, int c, int r, int change) {

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

void create_group_input() {

    char file_str[FILENAME_MAX];
    char name_str[MAXLINE];
    char n_of_users[4];
    int num_of_users;

    puts("Enter filename: ");
    fgets(file_str, FILENAME_MAX, stdin);

    puts("Enter number of users: ");
    fgets(n_of_users, 4, stdin);
    num_of_users = atoi(n_of_users);

    char* names_arr[num_of_users];
    puts("Enter user names: ");
    fgets(name_str, MAXLINE, stdin);
    char* name = strtok(name_str, " \n");
    int name_i = 0;
    while (name) {
        names_arr[name_i] = name;
        name = strtok(NULL, " \n");
        name_i++;
    }

    new_group_action(file_str, names_arr, num_of_users);

}

void change_point_in_csv_input() {

    char file_str[FILENAME_MAX];
    char user1[USERNAME_MAX], user2[USERNAME_MAX];
    char change[5];
    char message[MESSAGE_MAX];
    int one, two, ch;

    puts("Enter filename: ");
    fgets(file_str, 100, stdin);

    puts("Enter first user: ");
    fgets(user1, USERNAME_MAX, stdin);
    user1[strcspn(user1, "\n")] = 0;
    one = user_to_index(file_str, user1);

    puts("Enter second user: ");
    fgets(user2, USERNAME_MAX, stdin);
    user2[strcspn(user2, "\n")] = 0;
    two = user_to_index(file_str, user2);

    puts("Enter change value: ");
    fgets(change, 5, stdin);
    ch = atoi(change);

    puts("Enter message: ");
    fgets(message, MESSAGE_MAX, stdin);

    // printf("1: %d\n", one);
    // printf("2: %d\n", two);
    // printf("change: %d\n", ch);

    change_point_in_csv_action(file_str, one, two, ch);
    // update_bills(user1, user2, message);
}

// void update_bills(char* p1, char* p2, char* message) {

// }

/*  TODO:
    Functions to
        DONE create new group, input names
        -    add new user
        DONE log an expense / settlement (**need to modify to take in user names instead of ints)
        -    output personal bill
        -    view exchanges for input person

 */
int main() {

    char action[3];

    puts("0: Set up new group");
    puts("1: Log expense or settlement");
    puts("2: Add user");
    puts("3: Generate personal bill");
    puts("4: View exchanges for user");
    puts("5: View all exchanges");
    
    puts("What would you like to do? (Input Number)");
    fgets(action, 3, stdin);
    int action_num = atoi(action);
    switch(action_num) {
        case 0:
            create_group_input();
            break;

        case 1:
            change_point_in_csv_input();
            break;

        /* you can have any number of case statements */
        default : /* Optional */
            printf("default");
    }
}