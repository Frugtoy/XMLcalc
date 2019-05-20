#include "calculator.h"

calculator::calculator(){}
 calculator::~calculator(){}

float calculator::div(int first_digit , int second_digit){return static_cast <float>(first_digit) / second_digit;}
int calculator::sum(int first_digit , int second_digit){return first_digit + second_digit;}
int calculator:: mult(int first_digit , int second_digit){return first_digit * second_digit;}
int calculator::diff(int first_digit , int second_digit){return first_digit - second_digit;}
