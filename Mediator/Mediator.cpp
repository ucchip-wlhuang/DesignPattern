#include <iostream>
#include <string>
#include <ctime>
using namespace std;

class Pivot
{
public:
    void Show(string name, string msg);
};

class Member
{
public:
    virtual void Send(string msg) = 0;
};

class ChatRoom : public Pivot
{
public:
    static void Show(string name, string msg){
        time_t now = time(0);
        cout<<ctime(&now)<<"    ["<<name<<"] : "<<msg<<endl;
    }
};

class User : public Member
{
public:
    User(string name){
        this->name = name;
    }
    void Send(string msg){
        ChatRoom::Show(this->name, msg);
    }
private:
    string name;
};

int main()
{
    Member* p1 = new User("Tim");
    Member* p2 = new User("John");
    Member* p3 = new User("Alice");
    p1->Send("Hello, everyone!");
    p2->Send("Welcome to the chatroom.");
    p3->Send("Nice to meet you, my name is Alice.");
    p2->Send("Nice to meet you, too.");
    return 0;
}