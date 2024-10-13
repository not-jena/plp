#include <iostream>
#include <string>
using namespace std;

int main() {
    //a one-condition if/else statement
    int x= 2;
    int y=1;
    if (x > y) {
        std::cout << x << " is greater than "<< y << std::endl;
    }

    //a multi-condition if/else statement

    int number;
    cout << "Enter an integer: ";
    cin >> number;
    if (number > 0) {
        cout << "You entered a positive integer: " << number << endl;}
    else{
        cout << "You entered a negative integer: " << number << endl;
    }





    //if/elif/else statements
    string dogCat;
    cout << "Enter dog or cat: "; // Type a number and press enter
    cin >> dogCat;
    
    if (dogCat == "cat") {
        std::cout << "meow "<< std::endl;}
    else if (dogCat == "dog"){
        std::cout << "woof "<< std::endl;}
    else{
        std::cout << "moo "<< std::endl;}

    //short circut
    if (x < 0 || y > 5) {
        std::cout << "X is less than zero and Y is greater than 5" << std::endl;
        }
    else{
        std::cout << "X is greater than zero and Y is less than 5" << std::endl;
        }
    
    
    //switch
    int day = 4; //Thursday

    switch (day) {
        case 1:
            std::cout << "Monday :(\n";
            break;
        case 2:
            std::cout << "Tuesday :(\n";
            break;
        case 3:
            std::cout << "Hump Day\n";
            break;
        case 4:
            std::cout << "Thursday :(\n";
            break;
        case 5:
            std::cout << "Friday!!\n";
            break;
        case 6:
            std::cout << "Saturday!!\n";
            break;
        case 7:
            std::cout << "Sunday!!\n";
            break;
        default:
            std::cout << "Invalid day?\n";
    }

    return 0;
}