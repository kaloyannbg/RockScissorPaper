#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printMenu(void) {

    printf("1. Rock\n");
    printf("2. Scissors\n");
    printf("3. Paper\n");
    printf("4. Quit\n");
    printf("\n");

}

void yellow(void) {
    printf("\033[1;33m");
}

void resetColor(void) {
    printf("\033[0m");
}

int main()
{

    system("color 07");

    int userChoice, compChoice;

    int Rock, Scissors, Paper;

    int compRock, compScissors, compPaper;

    int userWins, compWins, draws;

    userWins = 0, compWins = 0, draws = 0;

    printf("\nRSP GAME By Kalo\n\n");

    do {

    Rock = 0, Scissors = 0, Paper = 0;

    compRock = 0, compScissors = 0; compPaper = 0;

    printMenu();

    printf("Enter your choice: ");

    scanf("%d", &userChoice);

    printf("\n\n");

    yellow();

    if(userChoice == 1) {
        Rock = 1;
        printf("You choose Rock");
    } else if(userChoice == 2) {
        Scissors = 1;
        printf("You choose Scissors");
    } else if(userChoice == 3) {
        Paper = 1;
        printf("You choose Paper");
    } else if(userChoice == 4) {
        printf("Bye Bye!");
    } else {
        printf("Invalid choice. Try again.");
    }

    printf(" <----> ");

    srand(time(NULL));   // Initialization, should only be called once.

    int random = rand();      // Returns a pseudo-random integer between 0 and RAND_MAX.

    int randomNumber = random % 3; //random number from 0 to 2

    if(randomNumber == 0 ) {
        compRock = 1;
        printf("Computer choose Rock");
    } else if(randomNumber == 1) {
        compScissors = 1;
        printf("Computer choose Scissors");
    } else {
        compPaper = 1;
        printf("Computer choose Paper");
    }

    printf("\n\n");


    if(Rock == 1 && compRock == 1) {
        printf("No one win"); //Draw
        draws++;
    } else if(Rock == 1 && compScissors == 1) {
        printf("You win!"); //Human win
        userWins++;
    } else if(Rock == 1 && compPaper == 1) {
        printf("Computer win!"); //PC win
        compWins++;
    }


    if(Scissors == 1 && compScissors == 1) {
        printf("No one win"); //Draw
        draws++;
    } else if(Scissors == 1 && compPaper == 1) {
        printf("You win!"); //Human win
        userWins++;
    } else if(Scissors == 1 && compRock == 1) {
        printf("Computer win!"); //PC win
        compWins++;
    }


    if(Paper == 1 && compPaper == 1) {
        printf("No one win"); //Draw
        draws++;
    } else if(Paper == 1 && compRock == 1) {
        printf("You win!"); //Human win
        userWins++;
    } else if(Paper == 1 && compScissors == 1) {
        printf("Computer win!"); //PC win
        compWins++;
    }

        printf("\n\n");
        printf("Your wins: %d | Computer Wins: %d, Draws: %d", userWins, compWins, draws);
        printf("\n\n");

        resetColor();

    } while(userChoice != 4);


    return 0;
}
