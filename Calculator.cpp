#include <iostream>
#include <vector>
#include <algorithm>

#include "Calculator.h"


// Initialize the calculator with some default values
Calculator::Calculator() : result(0.0), mem(0.0) {} // todo: improve, there isn't a better way???


/**
 * @brief Check if value in a vector
 * 
 * @credit: https://stackoverflow.com/a/20303915/13903942
 * 
 * @param value 
 * @param array 
 * @return true 
 * @return false 
 */
bool inArray(const std::string &value, const std::vector<std::string> &array) 
{
    return std::find(array.begin(), array.end(), value) != array.end();
}

// ----------------------
//  Methods
// ----------------------

/// Calculator Methods
void Calculator::run(const std::string& x, const std::string& formula, const std::string& y)
{
    int _operation = this->routeFormula(formula);

    switch (_operation)
    {
        case 1:
            result = add(x, y);
            /* code */
            break;
        case 2:
            result = subtract(x, y);
            /* code */
            break;
        case 3:
            result =  divide(x, y);
            /* code */
            break;
        case 4:
            result = multiply(x, y);
            /* code */
            break;
        case 5:
            result = square(x, y);
            /* code */
            break;   
        case -1:
        default:
            std::cout << "Invalid Input\n";
            break;
    }

    return;

}

double Calculator::add(std::string x, std::string y)
{
    result = parseFloat(x) + parseFloat(y);
    return result;

}
double Calculator::subtract(std::string x, std::string y)
{
    result = parseFloat(x) - parseFloat(y);
    return result;
}

double Calculator::multiply(std::string x, std::string y)
{
    result = parseFloat(x) * parseFloat(y);
    return result;
}

double Calculator::divide(std::string x, std::string y)
{
    result = parseFloat(x) / parseFloat(y);
    return result;
}

double Calculator::square(std::string x, std::string y)
{

    std::cout << "square\n";
    return result;
}

double Calculator::sqrt(std::string x, std::string y)
{

    std::cout << "sqrt\n";
    return result;
}


/// Helpers 
void Calculator::printPrompt()
{
    std::cout << "\n\nEnter an operation (+, -, /, *, sqrt, square, change, setmem, printmem) or exit\n"
        << ">>> ";
}


/**
 * @brief Conversts a string into a double
 * 
 * @param value 
 * @return double 
 */
double Calculator::parseFloat(const std::string& value) const
{
    return std::stod(value);
}


double Calculator::getResult()
{
    return result;
}

int Calculator::routeFormula(const std::string formula)
{

 // -------------------
    // CONSTANTS   TODO: Check how to do it properly in c++
    // -------------------
    const std::vector<std::string> INPUTS_ADD{ "+", "add", "addition", "sum"};
    const std::vector<std::string> INPUTS_SUBTRACT{"-", "sub", "subtraction", "minus"};
    const std::vector<std::string> INPUTS_DIVIDE{"/", "divide", "div"};
    const std::vector<std::string> INPUTS_MULTIPLY{"*", "mul", "multiply", "times"};
    const std::vector<std::string> INPUTS_SQRT{"sqrt"};
    if (inArray(formula, INPUTS_ADD))
    {
        return 1;
    }
    else if (inArray(formula, INPUTS_SUBTRACT))
    {
        return 2;
    } 
    else if (inArray(formula, INPUTS_DIVIDE))
    {
        return 3;
    }
    else if (inArray(formula, INPUTS_MULTIPLY))
    {
        return 4;
    }
    else if (inArray(formula, INPUTS_SQRT))
    { 
        return 5;
    } 
    
    return -1;
}