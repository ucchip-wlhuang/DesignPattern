#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Copper;   //the declaration can be used on point
class Paper;

class Visitor
{
public:
    virtual void create(Copper* m) = 0;
    virtual void create(Paper* m) = 0;
};

class ArtCompany : public Visitor
{
public:
    void create(Copper* m){
        cout<<"Bronze statue"<<endl;
    }
    void create(Paper* m){
        cout<<"Paper painting"<<endl;
    }
};

class Mint : public Visitor
{
public:
    void create(Copper* m){
        cout<<"Copper coins"<<endl;
    }
    void create(Paper* m){
        cout<<"Paper currency"<<endl;
    }
};

class Material
{
public:
    virtual void Accept(Visitor* v) = 0;
    virtual string GetName() = 0;
};

class Copper : public Material
{
public:
    void Accept(Visitor* v){
        v->create(this);        //transmit this class point to identify which overload function would be called
    }
    string GetName(){
        return "Copper";
    }
};

class Paper : public Material
{
public:
    void Accept(Visitor* v){
        v->create(this);
    }
    string GetName(){
        return "Paper";
    }
};

class MaterialSet
{
public:
    void Add(Material* m){
        materialset.push_back(m);
    }
    void Accept(Visitor* v){
        for(it = materialset.begin(); it != materialset.end(); it++){
            (*it)->Accept(v);
        }
    }
    void Show(){
        for(it = materialset.begin(); it != materialset.end(); it++){
            cout<<(*it)->GetName()<<endl;
        }
    }
private:
    vector<Material*> materialset;
    vector<Material*>::iterator it;
};

int main()
{
    MaterialSet ms;
    ms.Add(new Copper);
    ms.Add(new Paper);
    cout<<"Q:What do we have?"<<endl;
    ms.Show();
    
    Visitor* v = new Mint;
    cout<<endl<<"Q:What can the mint make with above materials?"<<endl;
    ms.Accept(v);
    
    v = new ArtCompany;
    cout<<endl<<"Q:What can the artcompany make with above materials?"<<endl;
    ms.Accept(v);
    return 0;
}