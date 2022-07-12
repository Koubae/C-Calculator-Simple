#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <string>
#include <array>
#include <cmath>




class Calculator
{



public: 
    Calculator();   /// Constructor
    virtual ~Calculator() = default; /// Virtual destructor to prevent delete errors

    // ----------------------
    //  Methods
    // ----------------------

    /// Calculator Methods
    void run(const std::string&, const std::string&, const std::string&); 
    double add(std::string, std::string);
    double subtract(std::string, std::string);
    double multiply(std::string, std::string);
    double divide(std::string, std::string);
    double square(std::string, std::string);
    double sqrt(std::string, std::string);


    /// Helpers 

    void printPrompt();
    /// Parse input subs in number value when strings result or mem are entered
    double parseFloat(const std::string&) const; 


    double getResult();    
    

private: 
    double result;
    double mem;

    int routeFormula(const std::string);


};


#endif // CALCULATOR_H