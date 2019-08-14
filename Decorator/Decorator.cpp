#include <iostream>
#include <string>

using namespace std;

class Hero
{
public:
    virtual void levelup(){};
};

class BlindMonk : public Hero
{
public:
    BlindMonk(){ this->name = "BlindMonk"; }
    void levelup(){
        cout<<name<<" level up!"<<endl;
    }
private:
    string name;
};

class Skills : public Hero
{
public:
    void levelup(){};
protected:
    Hero* hero;
};

class Skills_Q : public Skills
{
public:
    Skills_Q(Hero *hero){
        this->hero = hero;
        this->skill_name = "fists punch";
    }
    void levelup(){
        hero->levelup();
        getskills();
    }
    void getskills(){
        cout<<"Learned Q Skill : "<<skill_name<<endl;
    }
private:
    string skill_name;
};

class Skills_W : public Skills
{
public:
    Skills_W(Hero *hero){
        this->hero = hero;
        this->skill_name = "foot punch";
    }
    void levelup(){
        hero->levelup();
        getskills();
    }
    void getskills(){
        cout<<"Learned W Skill : "<<skill_name<<endl;
    }
private:
    string skill_name;
};

class Skills_E : public Skills
{
public:
    Skills_E(Hero *hero){
        this->hero = hero;
        this->skill_name = "head punch";
    }
    void levelup(){
        hero->levelup();
        getskills();
    }
    void getskills(){
        cout<<"Learned E Skill : "<<skill_name<<endl;
    }
private:
    string skill_name;
};

class Skills_R : public Skills
{
public:
    Skills_R(Hero *hero){
        this->hero = hero;
        this->skill_name = "body punch";
    }
    void levelup(){
        hero->levelup();
        getskills();
    }
    void getskills(){
        cout<<"Learned R Skill : "<<skill_name<<endl;
    }
private:
    string skill_name;
};

int main()
{
    Hero* blindmonk = new BlindMonk();
    Skills* q = new Skills_Q(blindmonk);
    Skills* w = new Skills_W(q);
    Skills* e = new Skills_E(w);
    Skills* r = new Skills_R(blindmonk);
    blindmonk->levelup();
    blindmonk->levelup();
    e->levelup();
    r->levelup();
    return 0;
}