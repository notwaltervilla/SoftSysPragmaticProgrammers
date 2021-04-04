#include "input.h"

#define MAXLINE 200

int user_to_index(char* filename, char *user);
void new_group_action(char* filename, char* names[], int num_of_users);
void change_point_in_csv_action(char *file, int c, int r, int change);
