//
// Created by Gregory Knapp on 5/2/20.
//

#pragma once
#include <iostream>
#include <string>
#include <stack>
#include "ExpressionManagerInterface.h"

using namespace std;


class ExpressionManager : public ExpressionManagerInterface
{
public:
    ExpressionManager() {}
    virtual ~ExpressionManager() {}

    //Main Lab functions
    bool isBalanced(string expression);
    string postfixToInfix(string postfixExpression);
    string postfixEvaluate(string postfixExpression);

    //Helper Functions
    int EvaluateOperator(stack<int>& opStack, char op);
    bool is_operator(char ch) const {
        return OPERATORS_NO_PARA.find(ch) != std::string::npos;
    }

private:
    // Data fields
    const string OPERATORS_NO_PARA = "+-*/%";
};