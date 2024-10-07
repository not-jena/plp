#include <iostream>
using namespace std;

//function to multiply 2 values
int myFunction(int x, int y){
  return x*y;
}

//function to calculate factorial recursively
long long factorial(int n){

    // Base case - If n is 0 or 1, return 1
    if (n == 0 || n == 1) {
        return 1;
    }
    // Recursive case - Return n multiplied by
    // factorial of (n-1)

    return n * factorial(n - 1);
}

//splits a string every space charcter
//https://www.geeksforgeeks.org/how-to-split-a-string-in-cc-python-and-java/
void split_string(string s, char c){
    string temp = "";
        for(int i=0; i<(int)s.size(); i++){
        //if the charcter is not a space the append it to the temp variable
        //if you have completed the word print it and start a new word
        if(s[i] != c){
            temp += s[i];
        }
        else{
            cout << temp << endl;
                temp = "";
        }
    }
      
    cout << temp;
    
}

//check if its pass-by-value or pass-by-reference
void modify(int p) {
    p = 101;  // Assign a new value to the parameter
}

int main()
{
    cout << myFunction(3,5)<<endl; //call function to multiply

    int num = 5;
    // printing the factorial
    cout << "The factorial of " << num << " is "
         << factorial(num) << endl; //call recursive function


    string s = "hello my name is jena";    // string to be split
    char c = ' ';    // delimiter around which string is to be split
  
    split_string(s, c);
    cout << endl;


    int a = 32;
    cout << "Before modify function: a = " << a << endl;
    modify(a); //pass the variable to the function
    cout << "After modify function: a = " << a << endl;
    //c++ passes arguments by value by default for primitive types like int
    //c++ actually supports both pass bys


    return 0;
}