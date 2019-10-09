#include <iostream>

using namespace std;

class Command
{
public:
    virtual void excute() = 0;
};

class Light
{
public:
    void On() {
        cout<<"Light opened!"<<endl;
    }
    void Off() {
        cout<<"Light close!"<<endl;
    }
};

class LightOn : public Command
{
public:
    LightOn(Light* light) {
        this->light = light;
    }
    void excute() {
        light->On();
    }
private:
    Light* light;
};

class LightOff : public Command
{
public:
    LightOff(Light* light) {
        this->light = light;
    }
    void excute() {
        light->Off();
    }
private:
    Light* light;
};

class XiaoAi
{
public:
    void SetCommand(Command* command) {
        this->command = command;
    }
    void DoCommand(){
        command->excute();
    }
private:
    Command* command;
};

int main(int argc, char **argv)
{
    XiaoAi* xiaoai = new XiaoAi;
    Light* light = new Light;
    Command* cd = NULL;
    cd = new LightOn(light);
    xiaoai->SetCommand(cd);
    xiaoai->DoCommand();
    cd = new LightOff(light);
    xiaoai->SetCommand(cd);
    xiaoai->DoCommand();
	return 0;
}
