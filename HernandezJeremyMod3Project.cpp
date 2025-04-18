#include <iostream>
#include <string>
using namespace std;

class FSA {
    private:
        enum State{Start, dotA1, dotB1, dotA2, dotB2, retT, retF};
    public:
        State currentState = Start;
        
        bool ProcessChar(char c){
            switch (currentState) {
                case Start:
                    if (c == 'a'){
                        currentState = dotA1;
                    }
                    else if (c == 'b'){
                        currentState = dotA2;
                    }
                    else if (c == 'c'){
                        currentState = Start;
                    }
                    else if (c == '.'){
                        currentState = retF;
                    }
                    else{
                        currentState = retF;
                    }
                    break;
                case dotA1:
                    if (c == 'a'){
                        currentState = dotB1;
                    }
                    else if (c == 'b'){
                        currentState = Start;
                    }
                    else if (c == 'c'){
                        currentState = Start;
                    }
                    else if (c == '.'){
                        currentState = retF;
                    }
                    else{
                        currentState = retF;
                    }
                    break;
                case dotA2:
                    if (c == 'a'){
                        currentState = Start;
                    }
                    else if (c == 'b'){
                        currentState = dotB2;
                    }
                    else if (c == 'c'){
                        currentState = Start;
                    }
                    else if (c == '.'){
                        currentState = retF;
                    }
                    else{
                        currentState = retF;
                    }
                    break;
                case dotB1:
                    if (c == 'a'){
                        currentState = retT;
                    }
                    else if (c == 'b'){
                        currentState = Start;
                    }
                    else if (c == 'c'){
                        currentState = Start;
                    }
                    else if (c == '.'){
                        currentState = retF;
                    }
                    else{
                        currentState = retF;
                    }
                    break;
                case dotB2:
                    if (c == 'a'){
                        currentState = Start;
                    }
                    else if (c == 'b'){
                        currentState = retT;
                    }
                    else if (c == 'c'){
                        currentState = Start;
                    }
                    else if (c == '.'){
                        currentState = retF;
                    }
                    else{
                        currentState = retF;
                    }
                    break;
            }
            return (currentState == retT) || (currentState == retF);
        }
        bool isAccepted() const{
            return currentState == retT;
        }
};

int main()
{
    FSA fsa;
    string input;
    
    cout<<"Enter a string (alphabt (a,b)) follow by '.': ";
    cin >> input;
    
    for (char c : input)
        if (fsa.ProcessChar(c)){
            if(fsa.isAccepted())
                cout<<"String is accepted (3 straight a's or b's)"<<endl;
            else
                cout<<"String is not accepted."<<endl;
            break;
        }

    return 0;
}