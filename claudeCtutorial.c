#include <stdio.h>   // gives us printf (printing to the screen)

// A macro (from Lecture 1): the pre-processor replaces MAX_COUNT with 5
// before compiling. Note the brackets are good practice.
#define MAX_COUNT (5)

// A function: takes two ints, returns an int.
// The types are written in front: return type, then parameter types.
int add(int a, int b) {
    return a + b;
}

// A function that returns nothing is declared "void".
void printLine(void) {
    printf("----------------------------------------\n");
}

int main() {

    // ---------------------------------------------
    // 1. VARIABLES AND TYPES
    // ---------------------------------------------
    // In C you must declare the type of every variable before using it.
    int age = 19;               // whole number
    double price = 4.99;        // decimal number (more precise)
    float temperature = 21.5f;  // decimal number (less precise than double)
    char letter = 'A';          // a single character, in single quotes
    // Note: C has no built-in "string" type. Text is an array of chars,
    // shown later in section 7.

    printf("1. VARIABLES AND TYPES\n");
    // printf format specifiers: %d int, %f decimal, %c char
    printf("age = %d\n", age);
    printf("price = %.2f\n", price);          // .2 means 2 decimal places
    printf("temperature = %.1f\n", temperature);
    printf("letter = %c\n", letter);
    printLine();

    // ---------------------------------------------
    // 2. ARITHMETIC (watch out for integer division!)
    // ---------------------------------------------
    printf("2. ARITHMETIC\n");
    int x = 7;
    int y = 2;
    printf("x + y = %d\n", x + y);            // 9
    printf("x - y = %d\n", x - y);            // 5
    printf("x * y = %d\n", x * y);            // 14
    printf("x / y = %d\n", x / y);            // 3  (integer division drops .5)
    printf("x %% y = %d\n", x % y);           // 1  (remainder; %% prints a %)
    printf("7.0 / 2 = %.1f\n", 7.0 / 2);      // 3.5 (a decimal is involved)
    printf("add(3, 4) = %d\n", add(3, 4));    // calling our own function
    printLine();

    // ---------------------------------------------
    // 3. SELECTION: if / else if / else
    // ---------------------------------------------
    printf("3. SELECTION (if / else)\n");
    int score = 65;
    if (score >= 70) {
        printf("Grade: First\n");
    } else if (score >= 60) {
        printf("Grade: Upper second\n");      // this one runs for 65
    } else {
        printf("Grade: Below upper second\n");
    }

    // Comparison operators: == != < > <= >=
    // Logical operators: && (and), || (or), ! (not)
    if (age >= 18 && age < 65) {
        printf("You are a working-age adult.\n");
    }

    // Ternary operator: condition ? valueIfTrue : valueIfFalse
    printf("%d is %s\n", x, (x % 2 == 0) ? "even" : "odd");
    printLine();

    // ---------------------------------------------
    // 4. SELECTION: switch
    // ---------------------------------------------
    printf("4. SELECTION (switch)\n");
    int day = 3;
    switch (day) {
        case 1:
            printf("Monday\n");
            break;                            // break stops it running on
        case 2:
            printf("Tuesday\n");
            break;
        case 3:
            printf("Wednesday\n");            // this one runs
            break;
        default:
            printf("Some other day\n");       // runs if nothing matched
    }
    printLine();

    // ---------------------------------------------
    // 5. LOOPS
    // ---------------------------------------------
    printf("5. LOOPS\n");

    // for loop: (start; keep going while true; step each time)
    printf("for loop: ");
    for (int i = 1; i <= MAX_COUNT; i++) {    // i++ means i = i + 1
        printf("%d ", i);
    }
    printf("\n");

    // while loop: checks the condition BEFORE each run
    printf("while loop: ");
    int n = 10;
    while (n > 0) {
        printf("%d ", n);
        n = n - 3;                            // 10 7 4 1
    }
    printf("\n");

    // do-while loop: runs at least once, checks the condition AFTER
    printf("do-while loop: ");
    int k = 0;
    do {
        printf("%d ", k);
        k++;
    } while (k < 3);                          // 0 1 2
    printf("\n");

    // break leaves the loop early; continue skips to the next round
    printf("break/continue: ");
    for (int i = 1; i <= 10; i++) {
        if (i % 2 == 0) {
            continue;                         // skip even numbers
        }
        if (i > 7) {
            break;                            // stop once i is above 7
        }
        printf("%d ", i);                     // 1 3 5 7
    }
    printf("\n");

    // Nested loops: a small multiplication table
    printf("nested loops:\n");
    for (int row = 1; row <= 3; row++) {
        for (int col = 1; col <= 3; col++) {
            printf("%d\t", row * col);        // \t is a tab
        }
        printf("\n");
    }
    printLine();

    // ---------------------------------------------
    // 6. ARRAYS (a fixed-size list of the same type)
    // ---------------------------------------------
    printf("6. ARRAYS\n");
    int numbers[5] = {10, 20, 30, 40, 50};    // indexes run from 0 to 4
    int total = 0;
    for (int i = 0; i < 5; i++) {
        total += numbers[i];                  // += means total = total + ...
    }
    printf("first = %d, last = %d, total = %d\n",
           numbers[0], numbers[4], total);
    printf("average = %.1f\n", total / 5.0);
    printLine();

    // ---------------------------------------------
    // 7. TEXT (strings are arrays of chars)
    // ---------------------------------------------
    printf("7. TEXT\n");
    char name[] = "Paras";                    // C adds a hidden '\0' at the end
    printf("Hello, %s!\n", name);             // %s prints a string
    printf("First letter: %c\n", name[0]);
    // Count characters by walking until the '\0' end marker
    int length = 0;
    while (name[length] != '\0') {
        length++;
    }
    printf("Length of name: %d\n", length);
    printLine();

    return 0;                                 // 0 means "finished normally"
}