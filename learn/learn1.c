#include <stdio.h>
#include <stdbool.h>

int main() {

    // variable = A reusable container for a value.
    //                   Behaves as if it were the value it contains.

    // int = whole numbers (4 bytes in modern systems)
    // float = single-precision decimal number (4 bytes)
    // double = double-precision decimal number (8 bytes)
    // char = single character (1 byte)
    // char[] = array of characters (size varies)
    // bool = true or false (1 byte, requires <stdbool.h>)

    int age = 21;
    int year = 2025;
    int quantity = 1;

    printf("You are %d years old\n", age);
    printf("The year is %d\n", year);
    printf("You have ordered %d x items\n", quantity);

    float gpa = 2.5;
    float price = 19.99;
    float temperature = -10.1;

    printf("The price is $%f\n", price);
    printf("Your gpa is %f\n", gpa);
    printf("The temperature is %f°F\n", temperature); 

    double pi = 3.14159265358979;
    double e = 2.7182818284590;

    printf("The value of pi is %lf\n", pi);
    printf("The value of e is %lf\n", e);

    char grade = 'A';
    char symbol = '!';
    char currency = '$';

    printf("Your letter grade is %c\n", grade);
    printf("%c is your favorite symbol\n", symbol);
    printf("The currency is in %c\n", currency);
   
    char name[] = "Bro Code";
    char food[] = "pizza";
    char email[] = "fake123@gmail.com";
   
    printf("Hello %s\n", name);
    printf("Your favorite food is %s\n", food);
    printf("Your email is %s\n", email);

    bool isOnline = true;

    bool isStudent = false;
    bool forSale = true;

    if(isOnline){
        printf("You are online");
    }
    else{
        printf("You are offline");
    }
   
    return 0;
}