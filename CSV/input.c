#include "main.h"

void new_group_input() {

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
        // printf("name_i: %d", name_i);
        // printf("name: %s", name);
        if (name==NULL && name_i < num_of_users) {
            puts("Number of user names given doesn't match number of users");
            exit(EXIT_FAILURE);
        }
    }

    new_group_action(file_str, names_arr, num_of_users);
}

void log_input() {

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
    update_bills(user1, user2, ch, message);
}

void add_user_input() {
    char addedUser[USERNAME_MAX];
    
    puts("Enter user: ");
    fgets(addedUser, USERNAME_MAX, stdin);
    
    add_user(addedUser);

}