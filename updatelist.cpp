#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <boost/spirit/home/support/detail/hold_any.hpp>
using namespace std;
using namespace boost::spirit;


typedef boost::spirit::hold_any hold_any;

int main () {
    string userinput;
    // vector<string> castinformation;
    vector <hold_any> uservector;
    while(true) {
        cout << "What do you want to add to the list? (Add either an int, a double, a bool, or a string/char)" << endl;
        cin >> userinput;
        if(userinput == std::string("done")) {
            cout << "\n\n";
            break;
        } else {
            // char *cstringuserinput = new char[userinput.length() + 1];
            // strcpy(cstringuserinput, userinput.c_str());
            hold_any temp;
            temp = std::string(userinput);
            uservector.push_back(temp);
        }    
    }

    vector<hold_any>::iterator i;
    for(i=uservector.end()-1; i != uservector.begin()-1; --i) {
        cout << *i << endl;
    }


}