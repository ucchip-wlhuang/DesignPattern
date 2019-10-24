#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class AbstractPosition
{
public:
    virtual void Show() = 0;
    //State Pattern and Null Object Pattern is combined
    string GetPosName(){
        return pos_name;
    }
protected:
    string pos_name;
};

class Position : public AbstractPosition
{
public:
    Position(string pos_name, string stuff_name, float salary){
        this->pos_name = pos_name;
        this->stuff_name = stuff_name;
        this->salary = salary;
    }
    void Show(){
        cout<<setw(10)<<this->pos_name<<"\t"<<setw(10)<<this->stuff_name<<"\t"<<setw(10)<<this->salary<<endl;
    }
    AbstractPosition* OffDuty();
private:
    string stuff_name;
    float salary;
};

class NullPosition : public AbstractPosition
{
public:
    NullPosition(string pos_name){
        this->pos_name = pos_name;
    }
    void Show(){
        cout<<setw(10)<<this->pos_name<<endl;
    }
    AbstractPosition* OnDuty(string n, float s);
};

AbstractPosition* Position::OffDuty(){
    return new NullPosition(this->pos_name);
}

AbstractPosition* NullPosition::OnDuty(string n, float s){
    if(s >= 0){
        return new Position(this->pos_name, n, s);
    }
    else{
        cout<<"Salary input-value is unavilable!"<<endl;
        return new NullPosition(this->pos_name);
    }
}

class PositionList
{
public:
    void Add(AbstractPosition* ap){
        pos_list.push_back(ap);
    }
    void Traverse(){
        cout<<"*************************************************"<<endl;
        cout<<setw(10)<<"Position"<<"\t"<<setw(10)<<"Name"<<"\t"<<setw(10)<<"Salary"<<endl;
        for(it = pos_list.begin(); it != pos_list.end(); it++){
            (*it)->Show();
        }
        cout<<"*************************************************"<<endl<<endl;
    }
    void OnDuty(string pos_name, string stuff_name, float salary){
        for(it = pos_list.begin(); it != pos_list.end(); it++){
            if((*it)->GetPosName() == pos_name){
                *it = ((NullPosition*)(*it))->OnDuty(stuff_name, salary);
            }
        }
    }
    void OffDuty(string pos_name){
        for(it = pos_list.begin(); it != pos_list.end(); it++){
            if((*it)->GetPosName() == pos_name){
                *it = ((Position*)(*it))->OffDuty();
            }
        }
    }
private:
    vector<AbstractPosition*> pos_list;
    vector<AbstractPosition*>::iterator it;
};

int main()
{
    PositionList pl;
    pl.Add(new Position("BOSS", "Jerry", 12345.6));
    pl.Add(new Position("Manager", "Tom", 9876.5));
    pl.Add(new NullPosition("Designer"));
    pl.Add(new NullPosition("Cleaner"));
    pl.Add(new Position("Programmer", "Addy", 5600));
    pl.Traverse();
    cout<<"Peter want to get Designer's job with 546.46$."<<endl;
    pl.OnDuty("Designer", "Peter", 546.46);
    pl.Traverse();
    cout<<"Mary want to get Cleaner's job with -130.41$."<<endl;
    pl.OnDuty("Cleaner", "Mary", -130.41);
    pl.Traverse();
    cout<<"The programmer left the company."<<endl;
    pl.OffDuty("Programmer");
    pl.Traverse();
    return 0;
}