//Michael Fletes, Kristine Laranjo
//Camel Game
//10 November 2015

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

void choices();
/*
Precondition: Player chooses an option out of the 6 possibilities.
Postcondition: Calls the appropriate function according to player choice.
Summary: Shows a list of options to the user.
*/
void drinkCanteen(int& canteen, int& playerThirst);
/*
Precondition: Takes in two pass by reference parameters.
Postcondition: Resets the playerThirst to zero.
Summary: Checks if there's any water in canteen.
*/
void moderateSpeed(int& playerThirst, int& camelTiredness, int& natives, int& distance);
/*
Precondition: Takes in 4 pass by reference parameters.
Postcondition: Adds to playerThirst, camelTiredness, natives (random) and distance (random)
Summary: Generates random number for the two distances and adds it to the total distance respectively.
*/
void fullSpeed(int& playerThirst, int& camelTiredness, int& natives, int& distance);
/*
Precondition: Takes in 4 pass by reference parameters.
Postcondition: Adds more to playerThirst, camelTiredness, natives (random) and distance (random)
Summary: Generates random number for the two distances and adds it to the total distance respectively.
*/
void nightStop(int& camelTiredness, int& natives, int& distance);
/*
Precondition: Takes in 3 pass by reference parameters.
Postcondition: Resets camelTiredness to zero, adds to the natives.
Summary: Prints that the camel is happy.
*/
void status(int& distance, int& natives, int& canteen);
/*
Precondition: Takes in 3 pass by reference parameters.
Postcondition: Prints the distance traveled, how far natives are, and what is left in canteen.
Summary: Prints the status.
*/

int main()
{
    cout << "\nWelcome to Camel!" << endl;
    cout << "You have stolen a camel to make your way across the great Mobi Desert." << endl;
    cout << "The natives want their camel back and are chasing you down." << endl;
    cout << "Survive your desert trek and outrun the natives!" << endl << endl;
    
    //calls the choice function.
    choices();
    return 0;
}
// ****************************************************
void choices()
{
    //seed our randum number generator
    srand(time(0));
    int canteen = 5, playerThirst = 0, distance = 0, camelTiredness = 0, natives = -20;
    int oasis = 1 + rand() % 20, lucky;
    int counter = 0;
    char choice;
    bool done = false;
    
    do
    {
        //creates a random number to see if it equals oasis
        lucky = 1 + rand() % 20;

        if(lucky == oasis)
        {//if true then resent stats to 0
            cout << "You found an oasis!" << endl;
            playerThirst = 0;
            camelTiredness = 0;
            canteen = 5;
        }
        //our extra feature, natives will go faster after the first 100 miles are traversed
        if(distance >= 100 && counter < 1)
        {
            counter++;
            cout << "The natives have gotten faster! BEWARE!!" << endl;
        }
              
        if(playerThirst > 6)
        {
            cout << "You died of thirst :(" << endl;
            cout << "Sorry, you lose.\n" << endl;
            break;
        }
        else if(camelTiredness > 8)
        {
            cout << "Your camel died :(" << endl;
            cout << "Sorry, you lose.\n" << endl;
            break;
        }
        if(playerThirst > 4)
        {
            cout << "You are thirsty." << endl;
        }
        else if(camelTiredness > 5)
        {
            cout << "Your camel is tired." << endl;
        }
        //choices for user
        cout << "\nWhat do you want to do?" << endl;
        cout << "(A) Drink from your canteen." << endl;
        cout << "(B) Ahead moderate speed." << endl;
        cout << "(C) Ahead full speed." << endl;
        cout << "(D) Stop and rest." << endl;
        cout << "(E) Status check." << endl;
        cout << "(Q) Quit." << endl;
        cout << "Your choice: ";
        cin >> choice;
        choice = toupper(choice);
       
        switch (choice)
        {
            case 'A': drinkCanteen(canteen, playerThirst);
                      break;
            case 'B': moderateSpeed(playerThirst, camelTiredness, natives, distance);
                      break;
            case 'C': fullSpeed(playerThirst, camelTiredness, natives, distance);
                      break;
            case 'D': nightStop(camelTiredness, natives, distance);
                      break;
            case 'E': status(distance, natives, canteen);
                      break;
            default: 
                cout << "Thank You for playing!" << endl << endl;
                done = true;
        } 
       // win/lose conditions
        if (natives >= distance)
        {
            cout << "The natives caught up to you." << endl;
            cout << "Sorry, you lose. :(" << endl << endl;
            done = true;
        }
        if (distance >= 200)
        {
            cout << "\n\nCONGRATULATIONS!" << endl
                 << "You made it across the desert and escaped from the natives!\n\n";
            done = true;
        }
       
       
    } while (done == false);
}
// ****************************************************
void drinkCanteen(int& canteen, int& playerThirst)
{
    if(canteen > 0)//checks to see if there are still sips left in the canteen
    {    
        canteen --;
        playerThirst = 0;
        //subtracts 1 si[ to canteen and resets thirst
        cout << "\nGood to go." << endl;
    }   
    else
        cout << "\nYou have no water left.";
}
// ****************************************************
void moderateSpeed(int& playerThirst, int& camelTiredness, int& natives, int& distance)
{
    srand(time(0));
    //creates a randum number between 7 and 12 for distance
    distance += 5 + (rand() % 8);
    cout << "\nYou traveled " << distance << " miles." << endl;
    //increments playerThirst and camelTiredness by 1.
    playerThirst++;
    camelTiredness++;
    
    if(distance < 100)//increase native speed after the first 100 miles
        natives += 7 + rand() % 8;
    else
        natives += 8 + rand() % 9;
}
// ****************************************************
void fullSpeed(int& playerThirst, int& camelTiredness, int& natives, int& distance)
{
    srand(time(0));
    //creates a random number between 10 and 20 and adds to total distance
    distance += 10 + (rand() % 11);
    cout << "\nYou traveled " << distance << " miles." << endl;
    playerThirst++;
    //camel tiredness goes up by a randum number between 1 and 3
    camelTiredness += 1 + rand() % 3;
    //increase native speed after the first 100 miles
    if(distance < 100)
        natives += 7 + rand() % 8;
    else
        natives += 9 + rand() % 9;
}
// ****************************************************
void nightStop(int& camelTiredness, int& natives, int&distance)
{
    camelTiredness = 0;
    cout << "\nYour camel is happy. :)" << endl;
    //increments natives distance by a random number
    natives += 7 + rand() % 8;
    
    if(distance > 100)
        natives += 3;
}
// ****************************************************
void status(int& distance, int& natives, int& canteen)
{
    int far;
    //prints stats to user
    cout << "\nYou traveled " << distance << " miles." << endl;
    cout << "You have " << canteen << " sips left in your canteen." << endl;
    far = distance - natives;
    cout << "Natives are " << far << " miles away from you." << endl;
}

camel_game.cpp
Displaying camel_game.cpp.
