#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printMenu(void) {

    printf("\n\n");

    printf("1. Rock\n");
    printf("2. Scissor\n");
    printf("3. Paper\n");
    printf("4. Quit\n");

}

void yellow() {
  printf("\033[1;33m");
}

void reset () {
  printf("\033[0m");
}

int main()
{

    system("color 07");

    printf("\n\tRock, Scissor Paper Game by Kalo");

    int Rock, Scissor, Paper, exit, userChoice, userCount, computerCount;

    exit = 0;

    userCount = 0;

    computerCount = 0;

    do {

    Rock = 0; Scissor = 0; Paper = 0;

    printMenu();

    printf("\n Enter your choice: ");

    scanf("%d", &userChoice);

    if(userChoice == 1) {
        Rock = 1; //Win under scissor
    } else if(userChoice == 2) {
        Scissor = 1; //Win under paper
    } else if(userChoice == 3) {
        Paper = 1; //Win under Rock
    } else if(userChoice == 4) {
        exit = 1;
    } else {
        printf("\nInvalid choice. Try again!");
    }

    printf("\n");

    yellow();


    if(Rock == 1) {
        printf("You choose Rock <--> ");
    } else if(Scissor == 1) {
        printf("You choose Scissor <--> ");
    } else if(Paper == 1) {
        printf("You choose Paper <--> ");
    }

    srand(time(NULL));   // Initialization, should only be called once.

    int random = rand();      // Returns a pseudo-random integer between 0 and RAND_MAX.

    int randomZeroOne = random % 2;

    if(Rock == 1 && Scissor == 0 && Paper == 0) {
        if(randomZeroOne == 0) {

        Scissor = 1;

        printf("Computer chooses Scissor");

        } else {

        Paper = 1;
        printf("Computer chooses Paper");
        }

        if(Rock == 1 && Scissor == 1) {
        //When I choose Rock
        //Rock beat Scissor

        printf("\n\nYou win!\n");

        userCount++;

        } else if (Rock == 1 && Paper == 1) {
        //When i choose Rock
        //Rock lose from Paper

        printf("\n\nComputer win!\n");

        computerCount++;


        }
    }

    if(Rock == 0 && Scissor == 1 && Paper == 0) {
        if(randomZeroOne == 0) {

        Rock = 1;

        printf("Computer chooses Rock");

        } else {

        Paper = 1;

        printf("Computer chooses Paper");

        }

        if(Scissor == 1 && Rock == 1 ) {
        //When I choose Scissor
        //Scissor lose from Rock

        printf("\n\nComputer win!\n");

        computerCount++;


        } else if (Scissor == 1 && Paper == 1) {
        //When i choose Rock
        //Rock lose from Paper

        printf("\n\nYou win!\n");

        userCount++;


        }
    }

    if(Rock == 0 && Scissor == 0 && Paper == 1) {
        if(randomZeroOne == 0) {

        Rock = 1;

        printf("Computer chooses Rock");

        } else {

        Scissor = 1;

        printf("Computer chooses Scissor");

        }

        if(Paper == 1 && Rock == 1) {
        //When I choose Paper
        //Paper beat Rock

        printf("\n\nYou win!\n");

        userCount++;

        } else if (Paper == 1 && Scissor == 1) {
        //When i choose Rock
        //Paper lose from Scissor

        printf("\n\nComputer win!\n");

        computerCount++;

        }
    }

    printf("Wins: You: %d | Computer: %d", userCount, computerCount);

    reset();

    } while( exit == 0);



    printf("\n\n\n\n");
    return 0;
}
