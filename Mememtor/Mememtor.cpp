#include <iostream>
#include <algorithm>
#include <list>
#include <string>
#include <ctime>
using namespace std;

static int id = 0;

class Save
{
public:
    Save(int Pass, int RoleNum, float Comp_degree, string Difficulty){
        this->Id = id++;
        this->Time = to_string(time(0));
        this->Pass = Pass;
        this->RoleNum = RoleNum;
        this->Comp_degree = Comp_degree;
        this->Difficulty = Difficulty;
    }
public:
    int Id;
    string Time;
    int Pass;
    int RoleNum;
    float Comp_degree;
    string Difficulty;
};

class SaveManage
{
public:
    void Add(Save* s){
        savelist.push_back(s);
    }
    Save* Get(int Id){
        for(it = savelist.begin(); (*it)->Id != Id && it != savelist.end(); it++){};
        if((*it)->Id == Id){
            return *it;
        }
        else{
            cout<<"No found!"<<endl;
            return NULL;
        }
    }
    void Show(){
        cout<<"***********   SaveList   ***********"<<endl;
        for(it = savelist.begin(); it != savelist.end(); it++){
            cout<<"     | "<<"Id: "<<(*it)->Id<<endl;
            cout<<"-----| Time: "<<(*it)->Time<<endl;
            cout<<"     | Degree of Complement: "<<(*it)->Comp_degree<<"%"<<endl<<endl;
        }
        cout<<endl;
    }
private:
    list<Save*> savelist;
    list<Save*>::iterator it;
};

class Game
{
public:
    void setState(int Pass, int RoleNum, float Comp_degree, string Difficulty){
        this->Pass = Pass;
        this->RoleNum = RoleNum;
        this->Comp_degree = Comp_degree;
        this->Difficulty = Difficulty;
    }
    void showState(){
        cout<<"---------Current State--------"<<endl;
        cout<<" Pass: "<<this->Pass<<endl;
        cout<<" RoleNum: "<<this->RoleNum<<endl;
        cout<<" Degree of completion: "<<this->Comp_degree<<"%"<<endl;
        cout<<" Difficulty: "<<Difficulty<<endl;
        cout<<endl;
    }
    void saveState(){
        SaveM.Add(new Save(this->Pass, this->RoleNum, this->Comp_degree, this->Difficulty));
    }
    void backSave(int Id){
        Save *s  = SaveM.Get(Id);
        if(s != NULL){
            this->Pass = s->Pass;
            this->RoleNum = s->RoleNum;
            this->Comp_degree = s->Comp_degree;
            this->Difficulty = s->Difficulty;
            cout<<"Change to the Save ID"<<s->Id<<"!"<<endl<<endl;
        }
    }
    void showSave(){
        SaveM.Show();
    }
private:
    int Pass;
    int RoleNum;
    float Comp_degree;
    string Difficulty;
    SaveManage SaveM;
};

int main()
{
    Game Mario;
    Mario.setState(1,2,13.5,"easy");
    Mario.saveState();
    Mario.setState(3,2,31.8,"easy");
    Mario.saveState();
    Mario.showSave();
    Mario.showState();
    Mario.backSave(0);
    Mario.showState();
    return 0;
}