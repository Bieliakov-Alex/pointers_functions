#include <iostream>
//#include <string.h> // c-header (don't use)
//#include <string> // cpp header for c-style strings (try not to use it)

//функции
int my_function(int);/*{ //передача аргументов по значению
    return -operand;
}*/

float my_function(float);/*{
    float result = 1.0 * operand;
    return result;
}*/

int my_new_function(int*); //передача аргументов по указателю

int main()
{
    //указатели
    int a = 10;
    int* pointer = &a;

    std::cout<<"a: "<<a<<" pointer: "<<pointer<<std::endl;

    int* new_pointer = pointer;
    ++new_pointer;
    //++ -- + -
    std::cout<<sizeof(int)<<" "<<new_pointer-pointer<<std::endl;
    //std::cout<<"pointer: "<<pointer<<std::endl;
    ++(*pointer);
    std::cout<<"a: "<<a<<std::endl;

    const int* pointer1 = &a; //указатель на константу
    int* const pointer2 = &a; //константный указатель

    ++pointer1;
    //++pointer2; //нельзя менять значение константного указателя

    //++(*pointer1); //нельзя менять значение, на которое указывает указатель на константу
    ++(*pointer2);

    const int* const pointer3 = &a;

    int* one_variable = new int;
    unsigned int size_of_array_of_int = 10;
    size_t some_var=5;
    //std::cout<<size_of_array_of_int<<std::endl;
    //int size_of_array_of_int = 10;
    int* array_of_int = new int[size_of_array_of_int];

    delete one_variable;
    delete[] array_of_int;

    //функции

    int not_operand = 5;

    float result = my_function(not_operand);
    std::cout<<result<<std::endl;
    std::cout<<not_operand<<std::endl;

    int* b = new int;
    *b = 5;
    std::cout<<"b: "<<b<<std::endl;
    int new_result = my_new_function(b);
    std::cout<<"b: "<<b<<std::endl;
    std::cout<<"*b: "<<*b<<std::endl;

    return 0;
}

int my_function(int operand){
    std::cout<<"Int function"<<std::endl;
    operand = -operand;
    return operand;
}

float my_function(float operand){
    std::cout<<"Float function"<<std::endl;
    float result = 1.0 * operand;
    return result;
}

int my_new_function(const int* const operand){
    ++(*operand);
    std::cout<<"operand: "<<operand<<std::endl;
    ++operand;
    std::cout<<"operand: "<<operand<<std::endl;
    return *operand;
}
