#include <iostream>
#include <string>

#define SIZE 5

using namespace std;

class Iterator
{
public:
    virtual int HasNext() = 0;
    virtual string Next() = 0;
};

class Container
{
public:
    virtual Iterator* getIterator() = 0;
};

class Suitcase : public Container
{
public:
    class SuitScan : public Iterator
    {
    public:
        SuitScan(string* thing){
            this->thing = thing;
        }
        int HasNext(){
            if(index+1>=SIZE){
                return 0;
            }
            return 1;
        }
        string Next(){
            if(index<SIZE){
                index++;
                return *thing++;
            }
            return NULL;
        }
    private:
        int index = 0;
        string* thing;
    };
    void Putin(string thing){
        if(use < space) {
            item[use++] = thing;
        }
        else {
            cout<<"This suitcase is full."<<endl;
        }
    }
    Iterator* getIterator(){
        return new SuitScan(item);
    }
    
private:
    string item[SIZE];
    int space = SIZE;
    int use = 0;
};

int main()
{
    Suitcase s;
    Iterator* it = s.getIterator();
    string item;
    s.Putin("bottle");
    s.Putin("toothpaste");
    s.Putin("knife");
    s.Putin("book");
    while(it->HasNext()){
        item = it->Next();
        if(item == "knife"){
            cout<<"Di~Di~Di~"<<endl<<"The prohibited item: "<<item<<endl;
        }
    }
    cout<<"Scanning Finished!"<<endl;
    return 0;
}