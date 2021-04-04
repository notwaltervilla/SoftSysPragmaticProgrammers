#include <stdlib.h>
#include "action.h"

/*  TODO:
    Functions to
        DONE create new group, input names
        -    add new user
        DONE log an expense / settlement
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
