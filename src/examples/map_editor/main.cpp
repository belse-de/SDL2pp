//
// Created by belse on 19.06.18.
//

#include <iostream>
#include <vector>

using namespace std;

int main(int argC, char* argV[]){
    vector<string> args(argV, argV + argC);

    cout << "Hello world!" << endl;
    cout << "Args:\n";
    for(auto const &arg : args){
        cout << "  " << arg << "\n";
    }
    cout << "Hello user!" << endl;


    cout << "Goodbye cruel world!" << endl;
    return EXIT_SUCCESS;
}
