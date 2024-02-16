#include <iostream>
#include <limits>

#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof(arr[0]))
#define YES 'y'
#define NO 'n'

using namespace std;

// Programming language - c++

// my task 
void print_task() {
    std::cout << "10. Sum of array elements." << std::endl;
}

// check input of size of array
int get_integer() {
    int x;
     while (!(std::cin >> x) || (std::cin.peek() != '\n'))
    {
        std::cin.clear();
        std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
        std::cout << "Wrong value! Try again: ";
    }
    return x;
}

// check input of array elements
double get_double() {
    double x;
    while (!(std::cin >> x) || (std::cin.peek() != '\n'))
    {
        std::cin.clear();
        std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
        std::cout << "Wrong value! Try again: ";
    }
    return x;
}

// check for continue
char valid_continue() {
    char answer;

    std::cout << "Do you want to continue? (y/n) >> ";
    std::cin >> answer;
    
    answer = std::tolower(answer);

    while (answer != YES && answer != NO || std::cin.get() != '\n') {
        std::cout << "Do you want to continue? (y/n) >> ";
        std::cin >> answer;
        answer = std::tolower(answer);
    }

    return answer;
}

// filling the array
double* input_array(int size) {
    double* arr = new double[size];
    std::cout << "Enter array elements:" << std::endl;
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
    std::cout << "Sum of array elements: " << sum_elements << std::endl;
}

// completing the task
void task() {
    std::cout << "Enter size of array: ";
    int size = get_integer();
    double* arr = input_array(size);
    double sum_elements = sum(arr, size);
    print_sum(sum_elements);
    delete[] arr;
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
