#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int main() {

    // if statement = Do some code if a condition is true

    // EXAMPLE 1

    int age = 0;

    printf("Enter your age: ");
    scanf("%d", &age);

    if(age >= 65){
        printf("You are a senior");
    }
    else if(age >= 18){
        printf("You are an adult");
    }
    else if(age < 0){
        printf("You haven't been born yet");
    }
    else if(age == 0){
        printf("You are a new born");
    }
    else{
        printf("You are a child");
    }

    // EXAMPLE 2

    bool isStudent = true;

    printf("Are you a student? (1 = true, 0 = false): ");
    scanf("%d", &isStudent);

    if(isStudent){
        printf("You are a student");
    }
    else{
        printf("You are NOT a student");
    }

    // EXAMPLE 3

    char name[50] = "";

    printf("Enter your name: ");
    fgets(name, sizeof(name), stdin);
    name[strlen(name) - 1] = '\0';

    if(strlen(name) == 0){
        printf("You did not enter your name");
    }
    else{
        printf("Hello %s", name);
    }

    return 0;
}