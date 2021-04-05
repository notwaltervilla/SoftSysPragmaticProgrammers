#include <stdio.h>
#include <string.h>

/*

Pros: 
- Successfully established struct for suitemember
- Can manipulate values for the struct values

Cons:
- Not sure how to call each "profile" to manipulate values for the users
- Values are not saving; need to use fopen() in order to call these values again. 
*/



int main(int argc, char *argv[]) {
    
    // define 'suiteMember' struct

    typedef struct suiteMember {
        char *name;
        int amount;
    } suiteMember;


    suiteMember Walter = {"Walter", 0};
    suiteMember Simrun = {"Simrun", 0};
    suiteMember Loren = {"Loren", 0};
    suiteMember Melody = {"Melody", 0};
    suiteMember Patrick = {"Patrick", 0};
    suiteMember Alana = {"Alana", 0};

    
    char input1[10]; // I am the person who is paying
    char input2[10]; // I am the person getting paid
    int pay; 

    // getting value for input1
    printf("Who are you: ");
    scanf("%s", input1);
    switch(input1) {
        case "Simrun":
            // refer to Simrun's structure
        case "Alana":
            // refer to Alana's structure
        case "Melody":
            // refer to Melody's structure
        case "Walter":
            // refer to Walter's structure
        case "Loren":
            // refer to Loren's structure
        case "Patrick":
            // refer to Patrick's structure
        default:
            printf("Not a valid member of the suite! \n");
    }
    printf("Excellent! You are %s. \n", input1);


    // getting value for input2
    printf("Who do you want to pay: ");
    scanf("%s", input2);
    printf("Great! You are paying %s! \n", input2);


    // getting value for pay
    printf("Enter amount: ");
    scanf("%i", &pay);
    printf("Okay! You are paying %s $%i \n", input2, pay);



    Walter.amount -= pay;
    Simrun.amount += pay;

    printf("Walter has %i \n", Walter.amount);
    printf("Simrun has %i \n", Simrun.amount);
    return 1;
}
