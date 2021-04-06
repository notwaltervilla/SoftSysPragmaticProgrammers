#include "main.h"

/*  TODO:
    Functions to
        DONE create new group, input names
        -    add new user
        DONE log an expense / settlement
        -    view exchanges for input person

 */



/* Main menu tool in order to reuse for other parts of our tracker*/
void mainMenu() {
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
            new_group_input();
            break;

        case 1:
            log_input();
            break;

        case 2: 
            add_user_input();
            break;

        default : /* Optional */
            printf("default");
    }
}

int main() {
    
    mainMenu();

}
    
