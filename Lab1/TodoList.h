//
// Created by Gregory Knapp on 4/29/20.
//


#ifndef TODO_LIST_H
#define TODO_LIST_H

#include <iostream>
#include <string>
#include "TodoListInterface.h"
#include <fstream>
#include <vector>

using namespace std;

class TodoList : public TodoListInterface {
public:
    TodoList() {
        ifstream infile ("TODOList.txt");
        string line;
        if (infile.is_open()) {
            while (getline(infile, line)) {
                tasks.push_back(line);
            }
            infile.close();
        }
    }
    virtual ~TodoList() {
        ofstream outfile;
        outfile.open("TODOList.txt", ofstream::out | ofstream::trunc);

        for(int i = 0; i < tasks.size(); i++) {
            outfile << tasks[i] << endl;
        }
        outfile.close();
    }

    virtual void add(string date, string task) {
        cout << "Adding task \"" << task << "\" to " << date << " on my To Do List" << endl;
        tasks.push_back(date + " - " + task);
    }
    virtual void remove(string task) {
        cout << "Removing task \"" << task << "\" from my To Do List" << endl;

        for (int i = 0; i < tasks.size(); i++) {
            if (tasks[i].find(task) != string::npos) {
                tasks.erase(tasks.begin() + i);
                break;
            }
        }
    }

    virtual void printTodoList() {
        cout << "Printing entire To Do List" << endl;

        for (int i = 0; i < tasks.size(); i++) {
            cout << tasks[i] << endl;
        }
    }

    virtual void printDaysTasks(string date) {

        cout << "Printing tasks for: " << date << endl;

        for (int i = 0; i < tasks.size(); i++) {
            if (tasks[i].find(date) != string::npos) {

                int found = tasks[i].find('-');

                cout << tasks[i].substr(found + 2, string::npos) << endl;
            }
        }
    }

private:
    vector<string> tasks;
};
#endif