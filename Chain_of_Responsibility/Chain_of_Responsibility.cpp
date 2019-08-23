#include <iostream>
#include <string>

using namespace std;

class AbstractApply
{
public:
    const static int Boss = 1;
    const static int Manager = 2;
    const static int Office = 3;
    virtual void Read(string msg) = 0;
    void SetNextRes(AbstractApply* next){
        this->next = next;
    }
    void Check(int level, string msg){
        if(this->next==NULL){
            Read(msg);
            cout<<"The chain of responsibility is finished!"<<endl;
        }
        else
        {
            if(this->level>level){
                Read(msg);
                next->Check(level, msg);
            }
            else {
                Read(msg);
                
            }
        }
        
    }
protected:
    AbstractApply* next = NULL;
    int level;
};

class BossCheck : public AbstractApply
{
public:
    BossCheck(int level){
        this->level = level;
    }
    void Read(string msg){
        cout<<"Boss read the apply ------ "<<msg<<endl;
    }
};


class ManagerCheck : public AbstractApply
{
public:
    ManagerCheck(int level){
        this->level = level;
    }
    void Read(string msg){
        cout<<"Manager read the apply ------ "<<msg<<endl;
    }
};

class OfficeCheck : public AbstractApply
{
public:
    OfficeCheck(int level){
        this->level = level;
    }
    void Read(string msg){
        cout<<"Office read the apply ------ "<<msg<<endl;
    }
};

class Chain
{
public:
    Chain(){
        first = new OfficeCheck(AbstractApply::Office);
        AbstractApply* m = new ManagerCheck(AbstractApply::Manager);
        AbstractApply* b = new BossCheck(AbstractApply::Boss);
        first->SetNextRes(m);
        m->SetNextRes(b);
    }
    void Res(int level, string msg){
        first->Check(level, msg);
    }
private:
    AbstractApply* first;
};

int main(int argc, char **argv)
{
	Chain chain;
    cout<<"---Send message to Office:"<<endl;
    chain.Res(AbstractApply::Office, "Hello, Office!");
    cout<<"---Send message to Manager:"<<endl;
    chain.Res(AbstractApply::Manager, "Hello, Manager!");
    cout<<"---Send message to Boss:"<<endl;
    chain.Res(AbstractApply::Boss, "Hello, Boss!");
	return 0;
}
