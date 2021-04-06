#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINE 200
#define USERNAME_MAX 20
#define MESSAGE_MAX 100
#define BUFFER_SIZE 1000

void new_group_input();
void log_input();
void new_group_action(char* filename, char* names[], int num_of_users);
void update_bills(char* user1, char* user2, int payment, char* message);
int user_to_index(char* filename, char* user);
void change_point_in_csv_action(char* file, int c, int r, int change);

// "Add User" function call
void add_user_input();
void add_user(char *addedUser);

// "Main menu" function call
void mainMenu();
void add_user(char *addedUser);