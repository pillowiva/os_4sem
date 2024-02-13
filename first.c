#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof(arr[0]))
#define YES 'y'
#define NO 'n'

// programming language - C

// my task 
void print_task() {
    printf("10. Sum of array elements.\n");
}

// check input of size of array
int get_integer() {
    char answer[256];
    int x;
    char temp[256];
    do {
        fgets(answer, sizeof(answer), stdin);
        if (sscanf(answer, "%d%s", &x, temp) != 1) {
            printf("Incorrect input. Try again: ");
        } else {
            break;
        }
    } while (1);
    return x;
}

// check input of array elements
double get_double() {
    char answer[256];
    double x;
    char temp[256];
    do {
        fgets(answer, sizeof(answer), stdin);
        if (sscanf(answer, "%lf%s", &x, temp) != 1) {
            printf("Incorrect input. Try again: ");
        } else {
            break;
        }
    } while (1);
    return x;
}

// check for continue
char valid_continue() {
    char answer;
    
    printf("Do you want to continue? (y/n) >> ");
    scanf(" %c", &answer); 

    answer = tolower(answer);

    while (answer != YES && answer != NO || getchar() != '\n') {
        printf("Do you want to continue? (y/n) >> ");
        scanf(" %2c", &answer);
        answer = tolower(answer);
    }

    return answer;
}

// filling the array
double* input_array(int size) {
    double* arr = malloc(size * sizeof(double));
    printf("Enter array elements:\n");
    for (int i = 0; i < size; ++i) {
        arr[i] = get_double();
    }
    return arr;
}

// function sum of array elements
double sum(const double *arr, int size) {
    double sum = 0.0;
    for (int i = 0; i < size; ++i) {
        sum += arr[i];
    }
    return sum;
}

// print sum
void print_sum(double sum_elements) {
    printf("Sum of array elements: %f\n", sum_elements);
}

// completing the task
void task() {
    printf("Enter size of array: ");
    int size = get_integer();
    double* arr = input_array(size);
    double sum_elements = sum(arr, size);
    print_sum(sum_elements);
    free(arr);
}

int main() {
    print_task();
    char answer = YES;
    while (answer == YES) {
        task();
        answer = valid_continue();
    }
    return 0;
}
