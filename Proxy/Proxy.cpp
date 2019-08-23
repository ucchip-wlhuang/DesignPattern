#include <iostream>

using namespace std;

class Telecom
{
public:
    virtual void CheckLog() = 0;
    virtual void AddClient() = 0;
};

class Company : public Telecom
{
public:
    void CheckLog(){
        cout<<"Company: Succeed to check log!"<<endl;
    }
    void AddClient(){
        cout<<"Company: Succeed to add client!"<<endl;
    }
};

class ServiceHall : public  Telecom
{
public:
    ServiceHall(Company* cp){
        this->cp = cp;
    }
    void CheckLog(){
        cout<<"ServiceHall: Sorry, no authority!"<<endl;
    }
    void AddClient(){
        cp->AddClient();
    }
private:
    Company* cp;
};

int main()
{
    Company* cp = new Company;
    Telecom* sh = new ServiceHall(cp);
    cout<<"~In Telecom ServiceHall"<<endl<<"--CheckLog"<<endl;
    sh->CheckLog();
    cout<<"--AddClient"<<endl;
    sh->AddClient();
    cout<<"~In Telecom Company"<<endl<<"--CheckLog"<<endl;
    cp->CheckLog();
    cout<<"--AddClient"<<endl;
    cp->AddClient();
    return 0;
}