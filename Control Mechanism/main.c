#include <stdio.h>
#include <math.h>

#define MENU_EXIT -1
#define MENU_QUADRATIC 1
#define MENU_FIZZBUZZ 2
#define MENU_MERSENNE 3
#define MENU_SHAPES 4

void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main() {
    // Variables to store user's name initials
    char first_name_initial, last_name_initial;

    // Welcome message and prompt for the first letter of the first name
    printf("Hello,\nWhat is the first letter of your first name?\n");
    scanf(" %c", &first_name_initial); // Assume valid input
    clear_input_buffer();

    // Prompt for the first letter of the last name
    printf("What is the first letter of your last name?\n");
    scanf(" %c", &last_name_initial); // Assume valid input
    clear_input_buffer();

    // Convert initials to uppercase
    first_name_initial = toupper(first_name_initial);
    last_name_initial = toupper(last_name_initial);

    // Welcome message with user's initials
    printf("Hello %c. %c, welcome to our menu!\n", first_name_initial, last_name_initial);

    // Menu options loop
    int choice;
    do {
        // Menu Options
        printf("Choose 1 for equations, 2 for Fizz Buzz, 3 for Mersenne numbers, 4 for shapes and -1 for exit\n");
        scanf("%d", &choice); // Assume valid input
        clear_input_buffer();

        switch(choice) {
            case MENU_QUADRATIC: // Quadratic equation
    printf("Welcome to quadratic equation!\nEnter coefficients a, b, and c:\n");
    double a, b, c;
    while (scanf("%lf %lf %lf", &a, &b, &c) != 3) {
        clear_input_buffer();
        printf("Invalid input. Enter coefficients a, b, and c again:\n");
    }
    clear_input_buffer();

    // Printing the quadratic equation
    printf("The quadratic equation is\n");
if (a != 0) {
    if (a == 1)
        printf("X^2 ");
    else
        printf("%.2fX^2 ", a);
}

if (b != 0) {
    if (b == 1)
        printf("+ X ");
    else if (b < 0)
        printf("- %.2fX ", -b);
    else
        printf("+ %.2fX ", b);
}

if (c != 0) {
    if (c < 0)
        printf("- %.2f ", -c);
    else
        printf("+ %.2f ", c);
}

printf("= 0\n");

    // Handling special cases
    if (a == 0) {
        printf("The equation is linear: %.2fX + %.2f = 0\n", b, c);
        double result = -c / b;
        printf("Result of the equation: %.2f\n", result);
    } else {
        // Calculating discriminant
        double discriminant = b * b - 4 * a * c;
        if (discriminant > 0) {
            // Two real roots
            double root1 = (-b - sqrt(discriminant)) / (2 * a);
            double root2 = (-b + sqrt(discriminant)) / (2 * a);
            printf("root1 = %.2f and root2 = %.2f\n", root1, root2);
        } else if (discriminant == 0) {
            // One real root
            double root = -b / (2 * a);
            printf("root1 = root2 = %.2f\n", root);
        } else {
            // Complex roots
            double realPart = -b / (2 * a);
            double imaginaryPart = sqrt(-discriminant) / (2 * a);
            printf("root1 = %.2f + %.2fi and root2 = %.2f - %.2fi\n", realPart, fabs(imaginaryPart), realPart, fabs(imaginaryPart));
        }
    }
    printf("\n");
    break;

            case MENU_FIZZBUZZ: // Fizz Buzz
                printf("Welcome to Fizz Buzz!\nEnter 2 numbers between 2-9 (single digit each):");
                int num1, num2;
                while (scanf("%d %d", &num1, &num2) != 2 || num1 < 2 || num1 > 9 || num2 < 2 || num2 > 9 || num1 == num2) {
                    clear_input_buffer();
                    printf("Invalid input. Enter 2 numbers between 2-9 (single digit each) again:\n");
                }
                clear_input_buffer();

                printf("Enter a two-digit number:");
                int two_digit_num;
                while (scanf("%d", &two_digit_num) != 1) {
                    clear_input_buffer();
                    printf("Invalid input. Enter a two-digit number again:\n");
                }
                clear_input_buffer();

                // Fizz Buzz logic
                for (int i = 1; i <= two_digit_num; ++i) {
                    if (i % num1 == 0 && i % 10 == num2)
                        printf("FizzBuzz\n");
                    else if (i % num1 == 0)
                        printf("Fizz\n");
                    else if (i % 10 == num2)
                        printf("Buzz\n");
                    else
                        printf("%d\n", i);
                }
                printf("\n");
                break;

            case MENU_MERSENNE: // Mersenne numbers
                printf("Welcome to Mersenne numbers!\nEnter 2 positive numbers smaller than 1000:\n");
                int range_start, range_end;
                while (scanf("%d %d", &range_start, &range_end) != 2 || range_start >= range_end || range_start <= 0 || range_end >= 1000) {
                    clear_input_buffer();
                    printf("Invalid input. Enter 2 positive numbers smaller than 1000 again:\n");
                }
                clear_input_buffer();

                // Print Mersenne numbers within the range
                int mersenne_candidate = 1;
                while ((1 << mersenne_candidate) < range_end) {
                    int candidate = (1 << mersenne_candidate) - 1;
                    if (candidate >= range_start && candidate <= range_end) {
                        printf("%d\n", candidate);
                    }
                    mersenne_candidate++;
                }
                printf("\n");
                break;

            case MENU_SHAPES: // Shapes
                printf("Welcome to Shapes!\nWhat shape do you want to pick?\n 1 for square, 2 for triangle, 3 for star\n");
                int shape_choice;
                while (scanf("%d", &shape_choice) != 1 || shape_choice < 1 || shape_choice > 3) {
                    clear_input_buffer();
                    printf("Invalid shape choice. Enter 1 for square, 2 for triangle, or 3 for star:\n");
                }
                clear_input_buffer();

                printf("Enter size (10-20):");
                int size;

                    while (scanf("%d", &size) != 1 || size < 10 || size > 20) {
                        clear_input_buffer();
                        printf("Invalid size. Enter a size between 10 and 20:");
                    }
                    clear_input_buffer();

                    // Draw shapes based on user's choice
                    switch (shape_choice) {

                        case 1: // square
                            for (int j = 1; j <= size; j++) {
                                for (int i = 1; i <= size; i++) {
                                    if (i == 1 || i == size || j == 1 || j == size) {
                                        printf("O");
                                    } else {
                                        printf("-");
                                    }
                                }
                                printf("\n");
                            }
                            break;

                        case 2:

                for (int i = 1; i <= size; i++) {//loop for triangle
                    for (int j = 1; j <= i; j++) {
                        if (j == 1 || i == j) {
                            printf("0");
                        }
                        else {
                            printf("-");
                        }
                    }
                    printf("\n");
                }
                break;

                                case 3:// star
                for (int j = 1; j <= (size * 2) - 1; j++) { //line1
                    if (j == size) {
                        printf("0");
                    }
                    else {
                        printf("-");
                    }
                }
                printf("\n");
                for (int j = 1; j <= (size * 2) - 1; j++) {//line 2
                    if (j == size - 1) {
                        printf("0");
                    }
                    else if (j == size + 1) {
                        printf("0");
                    }
                    else {
                        printf("-");
                    }
                }
                printf("\n");
                for (int j = 1; j <= (size * 2) - 1; j++) {//line 3
                    printf("0");
                }
                printf("\n");
                for (int j = 1; j <= (size * 2) - 1; j++) {//line 4
                    if (j == size + (size - 2)) {
                        printf("0");
                    }
                    else if (j == size - (size - 2)) {
                        printf("0");
                    }
                    else {
                        printf("-");
                    }
                }
                printf("\n");
                for (int j = 1; j <= (size * 2) - 1; j++) {//line 5
                    if (j == size + (size - 3)) {
                        printf("0");
                    }
                    else if (j == size - (size - 3)) {
                        printf("0");
                    }
                    else {
                        printf("-");
                    }
                }
                printf("\n");
                for (int j = 1; j <= (size * 2) - 1; j++) {//line 4
                    if (j == size + (size - 2)) {
                        printf("0");
                    }
                    else if (j == size - (size - 2)) {
                        printf("0");
                    }
                    else {
                        printf("-");
                    }
                }
                printf("\n");
                for (int j = 1; j <= (size * 2) - 1; j++) {//line 3
                    printf("0");
                }
                printf("\n");
                for (int j = 1; j <= (size * 2) - 1; j++) {//line 2
                    if (j == size - 1) {
                        printf("0");
                    }
                    else if (j == size + 1) {
                        printf("0");
                    }
                    else {
                        printf("-");
                    }
                }
                printf("\n");
                for (int j = 1; j <= (size * 2) - 1; j++) { //line1
                    if (j == size) {
                        printf("0");
                    }
                    else {
                        printf("-");
                    }
                }
                break;
            }

                           break;

            case MENU_EXIT: // Exit
                printf("Thank you, %c. %c, have a nice day!\n", first_name_initial, last_name_initial);
                break;

            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != MENU_EXIT);

    return 0;
}
