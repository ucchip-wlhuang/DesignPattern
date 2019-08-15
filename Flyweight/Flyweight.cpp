#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Str
{
public:
    Str(){};
    Str(string str, int value){
        cout<<"Construct "<<str<<endl;
        this->str = str;
        this->value = value;
    }
    bool operator==(const string &other)
    {
        if(other == this->str){
            return true;
        }
        return false;
    }
    int Getvalue()
    {
        return value;
    }
    void Setvalue(int value)
    {
        this->value = value;
    }
    void Show()
    {
        cout<<str<<" : "<<value<<endl;
    }
private:
    string str;
    int value;
};

class StringPool
{
public:
    Str* Create(string temp_str, int val)
    {
        iter = find(pool.begin(), pool.end(), temp_str);
        if(iter == pool.end())
        {
            Str* s = new Str(temp_str, val);
            pool.push_back(*s);
            return s;
        }
        else
        {
            if(iter->Getvalue() != val)
            {
                iter->Setvalue(val);
            }
            return &(*iter);
        }
    }
private:
    vector<Str> pool;
    vector<Str>::iterator iter;
};

int main()
{
    StringPool sp;
    Str* a = sp.Create("hello", 12);
    a->Show();
    Str* b = sp.Create("world", -5);
    b->Show();
    Str* c = sp.Create("hello", 16);
    c->Show();
    return 0;
}