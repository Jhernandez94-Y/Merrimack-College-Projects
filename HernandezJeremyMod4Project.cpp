#include <iostream>
#include <string>
using namespace std;

// S -> a or b
// if a => a or b by itself repeated (True) or empty character (True)
// b => b => a by itself or repeated (True) or empty character (True) 
// All other inputs result in False and aren't accepted

class FSA {
private:
    enum State {Start, A1, A2, B1, B2, AcceptA, AcceptB, Reject};

public:
    State currentState = Start;

    bool ProcessChar(char c) {
        switch (currentState) {
            case Start:
                if (c == 'a') {
                    currentState = A1;  
                }
                else if (c == 'b') {
                    currentState = B1;
                }
                else {
                    currentState = Reject;  
                }
                break;
                
            case A1:
                if (c == 'a' || c == 'b') {
                    currentState = A2; 
                }
                else {
                    currentState = Reject; 
                }
                break;
                
            case A2:
                if (c == 'a' || c == 'b') {
                    currentState = AcceptA;  
                }

                else {
                    currentState = Reject;  
                }
                break;
                
            case B1:
                if (c == 'b') {
                    currentState = B2;  
                }
                else {
                    currentState = Reject;  
                }
                break;

            case B2:
                if (c == 'a') {
                    currentState = AcceptB; 
                }
                else if (c == 'b') {
                    currentState = Reject;  
                }
                break;
                
            case AcceptA:
                if (c == 'a' || c == 'b') {
                    currentState = AcceptA;  
                }
                else {
                    currentState = Reject;
                }
                break;

            case AcceptB:
                if (c == 'a') {
                    currentState = AcceptB;  
                }
                else{
                    currentState = Reject;
                }
                break;

            case Reject:
                return false;  
        }
        return currentState != Reject;  
    }

    bool isAccepted() const {
        return currentState == AcceptA || currentState == AcceptB; 
    }
};

int main() {
    FSA fsa;
    string input;
    
    cout << "Enter a string (alphabet a and b): ";
    cin >> input;

    for (char c : input) {
        if (!fsa.ProcessChar(c)) {
            cout << "String is not accepted." << endl;
            return 0;  
        }
    }

    if (fsa.isAccepted()) {
        cout << "String is accepted." << endl;
    } else {
        cout << "String is not accepted." << endl;
    }

    return 0;
}