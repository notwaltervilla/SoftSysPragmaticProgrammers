#include "main.h"

#define MAXLINE 200
#define BUFFER_SIZE 1000

int user_to_index(char* filename, char* user) {

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

// initialize CSV file with values 0, generate bill txt files
void new_group_action(char* filename, char* names[], int num_of_users) {

    FILE *csv_file;
    FILE *bill_file;

    // filename=strcat(filename,".csv");
    csv_file = fopen(filename,"w+");

    // this makes the top bar in the CSV file
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

// Given row, col index, increment the value at that location by 'change'
void change_point_in_csv_action(char* file, int c, int r, int change) {

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

void update_bills(char* user1, char* user2, int payment, char* message) {

    FILE *file;

    file = fopen(user1, "a");
    if(file == NULL) {
        perror("Error opening user1 file");
    }
    fprintf(file, "You paid %s $%d\n", user2, payment);
    fprintf(file, "%s", message);
    fclose(file);

    file = fopen(user2, "a");
    if(file == NULL) {
        perror("Error opening user2 file");
    }
    fprintf(file, "%s paid you $%d\n", user1, payment);
    fprintf(file, "%s", message);
    fclose(file);
}

void add_user(char *addedUser) {
    FILE *file;
    FILE *fPtr;
    FILE *fTemp;
    char buffer[BUFFER_SIZE];
    char c[1000];
    const char zero[3] = " 0";
    char user_count[4];
    int userCount;

    // This makes the new users individual csv file
    char *name = addedUser;
    file = fopen(name, "w+");

    // This is going to replace the first line in the CSV with adding the new User to that line
    // After this, we can just append to the file. 
    char group_name[MAXLINE]; 
    int line_number = 1; 

    // Getting location where to add the user to + count number of users NOW in the group
    puts("Add this user to: ");
    fgets(group_name, MAXLINE, stdin);
    puts("How many users are in this group now (including the new member)? ");
    fgets(user_count, 4, stdin);
    userCount = atoi(user_count);

    // Open the required file:
    fPtr = fopen(group_name, "r");
    fTemp = fopen("replace.tmp", "w");

    /* fopen() return NULL if unable to open file in given mode. */
    if (fPtr == NULL || fTemp == NULL)
    {
        /* Unable to open file hence exit */
        printf("\nUnable to open file.\n");
        printf("Please check whether file exists and you have read/write privilege.\n");
        exit(EXIT_SUCCESS);
    }

    int count = 1;
    while (fgets(buffer, BUFFER_SIZE, fPtr)) {
        char* val = strtok(buffer, "\n");
        if (count == 1) {
            sprintf(val, "%s %s", val, name);
            fprintf(fTemp, "%s", val);
        }
        if (count > 1) {
            val = strcat(val, zero);
            fprintf(fTemp, "%s\n", val);
        }
        printf("val: %s", val);
        count++;
    }
    

    // Adding the last line
    name[strcspn(name, "\n")] = 0;
    fprintf(fTemp, "%s", name);               // changed from replace.tmp to fTemp
    for (int a = 0; a < userCount; a++) {
        fprintf(fTemp," %d", 0);                //  changed from replace.tmp to fTemp
    }

    fclose(fPtr);
    fclose(fTemp);
    /* Rename temporary file as original file */
    rename("replace.tmp", group_name);
    /* Once made a new file, I want to 
        1. Write to the "name bar" in the CSV file
        2. Append to the file and make row with 0's
    */

    fclose(file);
    mainMenu();
}