//
// Created by Gregory Knapp on 5/2/20.
//
#include "ExpressionManager.h"
#include <sstream>
#include <cctype>
#include <vector>
#include <cmath>

//Go back and do by self if possible.

bool ExpressionManager::isBalanced(string expression) {

    stack<string> charStack;
    istringstream ss(expression);
    string next;

    while (ss >> next) {
        if (next == "(" || next == "{" || next == "[") {
            charStack.push(next);
        }
        else if (next == ")" || next == "}" || next == "]") {
            if (charStack.empty()) {
                return false;
            }
            string last = charStack.top();
            charStack.pop();
            if ((next == ")" && last != "(") || (next == "}" && last != "{") || (next == "]" && last != "[")) {
                return false;
            }
        }
    }

    if (!charStack.empty()) {
        return false;
    }
    return true;
}


string ExpressionManager::postfixToInfix(string postfixExpression) {

    stack<string> expressionStack;
    istringstream ss(postfixExpression);
    string token;
    vector<string> tokens;

    //First empty the stack.
    while (!expressionStack.empty()) {
        expressionStack.pop();
    }

    //Get string stream, convert to string vector
    while(getline(ss, token, ' ')) {
        tokens.push_back(token);
    }


    //Read by character, determine if operand or operator
    for (int i = 0; i < tokens.size(); i++) {
        string currentLine = tokens[i];

        //If is a digit - Add to stack
        if (isdigit(currentLine[0])) {
            if (currentLine.find('.') != string::npos) {
                return "invalid";
            }
            expressionStack.push(currentLine);

        }
            //If is an operator - Pop top two and evaluate, add back to stack
        else if (is_operator(currentLine[0])) {

            if (expressionStack.size() < 2) {
                return "invalid";
            } else {
                string rhs = expressionStack.top();
                expressionStack.pop();
                string lhs = expressionStack.top();
                expressionStack.pop();

                string newExpression = "( " + lhs + " " +  currentLine + " " + rhs + " )";
                expressionStack.push(newExpression);
            }
        }
            //If anything else, throw exception
        else {
            cout << "this is not a valid symbol" << endl;
        }
    }

    if (expressionStack.size() == 1) {
        return expressionStack.top();
    }
    else {
        return "invalid";
    }
}


string ExpressionManager::postfixEvaluate(string postfixExpression) {

    istringstream ss(postfixExpression);
    string token;
    vector<string> tokens;
    stack<int> operand_stack;

    //First empty the stack.
    while (!operand_stack.empty()) {
        operand_stack.pop();
    }

    //Get string stream, convert to string vector
    while(getline(ss, token, ' ')) {
        tokens.push_back(token);
    }

    //Read by character, determine if operand or operator
    for (int i = 0; i < tokens.size(); i++) {
            string currentLine = tokens[i];

        //If is a digit - Add to stack
        if (isdigit(currentLine[0])) {
            if (currentLine.find('.') != string::npos) {
                return "invalid";
            }
            int value = stoi(currentLine);
                operand_stack.push(value);
        }
        //If is an operator - Pop top two and evaluate, add back to stack
        else if (is_operator(currentLine[0])){
            char op = currentLine[0];
            int result;

            try {
                result = EvaluateOperator(operand_stack, op);
            }

            catch (int e) {
                cout << "not enough operands";
                return("invalid");
            }
            catch (...) {
                cout << "zero division";
                return ("invalid");
            }
            operand_stack.push(result);
        }
        //If anything else, throw exception
        else {
            return "invalid";
        }

    }

    //If unbalanced amount of characters, throw exceptions.
    if (!operand_stack.empty()) {
        int answer = operand_stack.top();
        operand_stack.pop();
        if (operand_stack.empty()) {
            return to_string(answer);
        }
        else {
            return "invalid";
        }
    }
    else {
        return "invalid";
    }
}

int ExpressionManager::EvaluateOperator(stack<int>& opStack,char op) {

    if (opStack.empty()) {
        throw 1;
    }

    int rhs = opStack.top();
    opStack.pop();

    if (opStack.empty()) {
        throw 2;
    }

    int lhs = opStack.top();
    opStack.pop();
    int result = 0;
    switch (op) {
        case '+' :
            result = lhs + rhs;
            break;
        case '-' :
            result = lhs - rhs;
            break;
        case '*' :
            result = lhs * rhs;
            break;
        case '/' :
            if (rhs == 0) {
                throw std::domain_error("division by zero");
            }
            result = lhs / rhs;
            break;
        case '%' :
            result = lhs % rhs;
            break;
    }

    return result;
}