#include <iostream>
#include <string>
#include <vector>
#include <cstring>
using namespace std;




void intvector() {
    vector<int> uservector;
    vector<int>::iterator i;
    string userinput;
    while(true) {
        cout << "What int do you want to add to the vector the program will reverse?: If you are finished adding to the vector, enter 'done' and then hit Return" << endl;
        cin >> userinput;
        if(userinput == "done") {
            break;
        } else {
            string::size_type sz;
            int temp = stoi(userinput, &sz);
            uservector.push_back(temp);
        }    
    }
    for(i=uservector.end()-1; i != uservector.begin()-1; --i) {
    cout << *i << endl;
    }
}

void floatvector() {
    vector<float> uservector;
    vector<float>::iterator i;
    string userinput;
    while(true) {
        cout << "What float do you want to add to the vector the program will reverse?: If you are finished adding to the vector, enter 'done' and then hit Return" << endl;
        cin >> userinput;
        if(userinput == "done") {
            break;
        } else {
            string::size_type sz;
            float temp = stof(userinput, &sz);
            uservector.push_back(temp);
        }    
    }
    for(i=uservector.end()-1; i != uservector.begin()-1; --i) {
    cout << *i << endl;
    }
}

void doublevector() {
    vector<double> uservector;
    vector<double>::iterator i;
    string userinput;
    while(true) {
        cout << "What double do you want to add to the vector the program will reverse?: If you are finished adding to the vector, enter 'done' and then hit Return" << endl;
        cin >> userinput;
        if(userinput == "done") {
            break;
        } else {
            string::size_type sz;
            double temp = stod(userinput, &sz);
            uservector.push_back(temp);
        }    
    }
    for(i=uservector.end()-1; i != uservector.begin()-1; --i) {
    cout << *i << endl;
    }
}

void boolvector() {
    vector<bool> uservector;
    vector<bool>::iterator i;
    string userinput;
    while(true) {
        cout << "What bool do you want to add to the vector the program will reverse?: If you are finished adding to the vector, enter 'done' and then hit Return" << endl;
        cin >> userinput;
        if(userinput == "done") {
            break;
        } else if (userinput == "TRUE" || userinput == "True" || userinput == "true") {
            uservector.push_back(true);
        } else if (userinput == "FALSE" || userinput == "False" || userinput == "false") {
            uservector.push_back(false);
        } else {
            cout << "Please enter a valid boolean value: either True/TRUE/true or False/FALSE/false" << endl;
        }    
    }
    for(i=uservector.end()-1; i != uservector.begin()-1; --i) {
    cout << *i << endl;
    }
}

void charvector() {
    vector<char> uservector;
    vector<char>::iterator i;
    string userinput;
    while(true) {
        cout << "What char do you want to add to the vector the program will reverse?: If you are finished adding to the vector, enter 'done' and then hit Return" << endl;
        cin >> userinput;
        char *cstringuserinput = new char[userinput.length() + 1];
        strcpy(cstringuserinput, userinput.c_str());
        if(userinput == "done") {
            break;
        } else {
            uservector.push_back(*cstringuserinput);
        }    
    }
    for(i=uservector.end()-1; i != uservector.begin()-1; --i) {
    cout << *i << endl;
    }
}


void stringvector() {
    vector<string> uservector;
    vector<string>::iterator i;
    string userinput;
    while(true) {
        cout << "What string do you want to add to the vector the program will reverse?: If you are finished adding to the vector, enter 'done' and then hit Return" << endl;
        cin >> userinput;
        if(userinput == "done") {
            break;
        } else {
            uservector.push_back(userinput);
        }    
    }
    for(i=uservector.end()-1; i != uservector.begin()-1; --i) {
    cout << *i << endl;
    }
}





int main() {
  cout << "Pick what kind of vector you want to reverse: int, float, double, bool, or char" << endl;
  string userinput;
  cin >> userinput;
  if(userinput == "int") {
    intvector();
  } else if (userinput == "float") {
    floatvector();
  } else if (userinput == "double") {
    doublevector();
  } else if (userinput == "bool") {
    boolvector();
  } else if (userinput == "char") {
    charvector();
  } else if (userinput == "string") {
    stringvector();
  } else {
    cout << "Enter a valid value: int for integer, float for floating point, bool for boolean, char for character vector" << endl;
  }
}