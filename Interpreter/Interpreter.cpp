#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;

/*rule
 * <expression> ::= <person> from <city>
 * <city> ::= Chongqing | Shanghai
 * <person> ::= old | child | woman
 */

class Expression
{
public:
    virtual bool interpret(string context) = 0;
};

class TerminalExpression : public Expression
{
public:
    TerminalExpression(string data[], int len) {    //array name which is converted will become a point
        for(int i=0; i<len; i++){
            this->data.push_back(data[i]);
        }
    }
    bool interpret(string context){
        if(find(data.begin(),data.end(),context)!=data.end()) {
            return true;
        }
        return false;
    }
private:
    vector<string> data;
};

class NonTerminalExpression : public Expression
{
public:
    NonTerminalExpression(Expression* left, Expression* right) {
        this->left = left;
        this->right = right;
    }
    bool interpret(string context){
        char* temp = new char[strlen(context.c_str())+1];
        strcpy(temp, context.c_str());
        string person(strtok(temp, " from "));
        string city(strtok(NULL, " from "));
        return left->interpret(person) && right->interpret(city);
    }
private:
    Expression* left = NULL;
    Expression* right = NULL;
};

class Context
{ 
public:
    Context(){
        city = new TerminalExpression(citys, sizeof(citys)/sizeof(citys[0]));
        person = new TerminalExpression(persons, sizeof(persons)/sizeof(persons[0]));
        card = new NonTerminalExpression(person, city);
    }
    void scan(string context){
        if(card->interpret(context)) {
            cout<<"Hello,"<<context<<". Free this time!"<<endl;
        }
        else {
            cout<<"Hello,"<<context<<". Cost two dollars!"<<endl;
        }
    }
private:
    string citys[2] = {"Chongqing", "Shanghai"};
    string persons[3] = {"child", "woman"};
    Expression* city;
    Expression* person;
    Expression* card;
};

int main()
{
    Context bus;
    bus.scan("man from Chongqing");
    bus.scan("child from Shanghai");
    bus.scan("woman from Guangdong");
    bus.scan("man from Guangdong");
    return 0;
}