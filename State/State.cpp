#include <iostream>
#include <string>

using namespace std;

class State
{
public:
    virtual State* Switch() = 0;
    virtual void Input(string str) = 0;
};

class OpenState : public State
{
public:
    State* Switch();
    void Input(string str){
        cout<<str<<endl;
    }
};

class CloseState : public State
{
public:
    State* Switch();
    void Input(string str){
    }
};

//Function can be split out from the class
//If just cross-reference by point or &, we can use class forward declearation, e.g. class OpenState;

State* OpenState::Switch(){
        cout<<"Change to close state!"<<endl;
        return new CloseState;
}

State* CloseState::Switch(){
        cout<<"Change to open state!"<<endl;
        return new OpenState;
}

class PC
{
public:
    PC(){
        this->state = new CloseState;
    }
    void PressSwitch(){
        this->state = state->Switch();
    }
    void InputContext(string str){
        state->Input(str);
    }
private:
    State* state;
};

int main()
{
    PC pc;
    pc.InputContext("qwertyuiop");
    pc.PressSwitch();
    pc.InputContext("asdfghjkl");
    pc.PressSwitch();
    pc.InputContext("zxcvbnm");
    return 0;
}