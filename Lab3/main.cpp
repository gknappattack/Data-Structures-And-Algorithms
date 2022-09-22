#include <set>
#include <vector>
#include <map>
#include <list>
#include <sstream>
#include <fstream>
#include <iostream>
#include <utility>
using namespace std;

void add_set(set<string>& mySet, string fileName);
void add_list(list<string>& myList, string fileName);
const void write_set(set<string> mySet, string userFile);
const void write_vector(vector<string> myVector, string userFile);
const void write_map(map<string, string> myMap, string userFile);

int main(int argc, char *argv[]) {
    list<string> nephiList;
    set<string> firstNephi;


    //Getting input from file, adding to set
    add_set(firstNephi, argv[1]);
    //Writing content of set to user-named file
    //write_set(firstNephi, argv[2]);

    //Getting input from file, adding to vector
    add_list(nephiList, argv[1]);
    //Writing content of vector to user-named file
    //write_vector(nephiVector, argv[2]);



    map<list<string>, vector<string>> wordmap;
    list<string> state;
    int M = 2;

    for (int i = 0; i < M; i++) {
        state.push_back("");
    }

    for (list<string>::iterator it=nephiList.begin(); it!=nephiList.end(); it++) {
        wordmap[state].push_back(*it);
        state.push_back(*it);
        state.pop_front();
    }

    state.clear();
    for (int i = 0; i < M; i++) {
        state.push_back("");
    }
    srand(time(nullptr));

    for (int i = 0; i < 31; i++) {
        if (i == 5 || i == 12 || i == 17 || i == 24 || i == 31) {
            cout << endl;
        }
        int ind = rand() % wordmap[state].size();

        cout << wordmap[state][ind]<<" ";

        state.push_back(wordmap[state][ind]);
        state.pop_front();
    }

    return 0;
}

void add_set(set<string>& mySet, string fileName) {
    ifstream infile(fileName);
    string textLine;

    if(!infile.is_open()) {
        cout << "Could not open file, please try again.";
    }
    else {
        while (getline(infile, textLine )){
            istringstream textStream(textLine);
            string token;
            while (textStream >> token) {
                string nopunct = "";
                for(auto &c : token) { // Remove Punctuation
                    if (isalpha(c)) {
                        nopunct += c;
                    }
                }
                mySet.insert(nopunct);
            }


        }
    }
    infile.close();
}

void add_list(list<string>& myList, string fileName) {
    ifstream infile(fileName);
    string textLine;

    if(!infile.is_open()) {
        cout << "Could not open file, please try again.";
    }
    else {
        while (getline(infile, textLine )){
            istringstream textStream(textLine);
            string token;
            while (textStream >> token) {
                string nopunct = "";
                for(auto &c : token) { // Remove Punctuation
                    if (isalpha(c)) {
                        nopunct += c;
                    }
                }
                myList.push_back(nopunct);
            }


        }
    }
    infile.close();
}

const void write_set(set<string> mySet, string userFile) {

    string setFileName = userFile + "_set.txt";
    ofstream outFile;
    outFile.open(setFileName, ios::trunc | ios::out);

    if (!outFile.is_open()) {
        cout << "Could not create file to write to, try again." << endl;
    }
    else {
        for (set<string>::iterator it = mySet.begin(); it != mySet.end(); it++) {
            outFile << *it << endl;
        }
    }

    outFile.close();
}

const void write_vector(vector<string> myVector, string userFile) {

    string setFileName = userFile + "_vector.txt";
    ofstream outFile;
    outFile.open(setFileName, ios::trunc | ios::out);

    if (!outFile.is_open()) {
        cout << "Could not create file to write to, try again." << endl;
    }
    else {
        for (int i = 0; i < myVector.size(); i++) {
            outFile << myVector.at(i) << endl;
        }
    }

    outFile.close();
}

const void write_map(map<string, string> myMap, string userFile) {

    string setFileName = userFile + "_map.txt";
    ofstream outFile;
    outFile.open(setFileName, ios::trunc | ios::out);

    if (!outFile.is_open()) {
        cout << "Could not create file to write to, try again." << endl;
    }
    else {
        for (map<string, string>::iterator it = myMap.begin(); it != myMap.end(); it++) {
            outFile << it->first << ", " << it->second << endl;
        }
    }

    outFile.close();
}