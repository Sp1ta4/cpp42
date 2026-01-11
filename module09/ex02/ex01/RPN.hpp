#pragma once

#include <stack>
#include <list>
#include <iostream>
#include <cstdlib>
#include <sstream>
#include <stdexcept>
#include <cctype>
#include <string>

class RPN {
private:
    std::list<std::string> _inputData;
    std::stack<int>        _stack;

    bool _isOperation(const std::string &element) const;
    bool _elementIsValid(const std::string &element) const;
    bool _isAllSpace(const std::string &input) const;
    int  _calculate(int num1, int num2, const std::string &operand) const;
    void _trimElement(std::string &token) const;
    void _splitInput(const std::string &input);
    void _processInput();

public:
    RPN();
    RPN(const RPN &other);
    ~RPN();
    RPN &operator=(const RPN &other);

    void start(const std::string &input);
};
