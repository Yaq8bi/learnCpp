/*
Description
Write a program to let a user guess a secret random number in the range of 0 and 99.
The user shall have maximum 10 attempts to guess the secret number.
After every guess a message should be presented to inform the user if the entered value was correct, too small or too big.
After each game the program shall offer a new game.
*/
#include <iostream>
#include <random>   //randomnes
#include <unistd.h> //sleep func

int main()
{

    std::random_device dev;                                                // seed
    std::mt19937 rng(dev());                                               // takes the seed,
    std::uniform_int_distribution<std::mt19937::result_type> dist6(0, 99); // type, minn and max val

    int randomNumber = dist6(rng); // feed the time to rand.

    while (1)
    {
        int menuChoice = 0;
        int playerChoice = 0;
        int attempts = 10;

        std::cout << " ~~~ Welcome to random number guesser ~~~\v 1. Play\n 2. Random Number\n 3. Exit" << std::endl;
        std::cin >> menuChoice;

        switch (menuChoice)
        {
        case 1:
            // attempts ; if playerchoice
            while (attempts >= 0 && attempts <= 10)
            {
                std::cout << "Make a guess, what is the hidden number I'm thinking of now?\v\tTries left: " << attempts << std::endl;
                std::cin >> playerChoice;

                if (playerChoice == randomNumber)
                {
                    std::cout << "Correct, you guessed the number " << randomNumber << " right!" << std::endl;
                    break;
                }
                else if (playerChoice < randomNumber)
                {
                    std::cout << "Wrong, go HIGHER!\v\tTries left: " << attempts << "\n"
                              << std::endl;
                    attempts--;
                }
                else if (playerChoice > randomNumber)
                {
                    std::cout << "Wrong, go LOWER!\v\tTries left: " << attempts << "\n"
                              << std::endl;
                    attempts--;
                }
                usleep(1000000);

                std::cin.clear();
                std::cin.fail();
            }

            break;

        case 2:
            std::cout << randomNumber << std::endl;
            break;

        case 3:
            std::cout << "You chose to exit!" << std::endl;
            exit(3);
            break;

        default:
            std::cout << "No choices were made!" << std::endl;
            break;
        }

        std::cout << "Thank you for playing, BYE!" << std::endl;
        if (attempts < 0 && playerChoice != randomNumber)
        {
            std::cout << "\vThe random number was:\t" << randomNumber << std::endl;
        }
        return 0;
    }
}

/*
int randomNum()
{
    int rndmNum = 0;

    srand(time(NULL));

    rndmNum = rand() % 100;

    return rndmNum;
}

*/

