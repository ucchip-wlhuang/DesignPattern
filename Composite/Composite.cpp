#include <iostream>
#include <string>
#include <list>
#include <algorithm>
using namespace std;

class IFile
{
public:
    virtual void Add(IFile* file){};
    virtual void Show() = 0;
    virtual void Setpos(string backdir) = 0;
    virtual ~IFile(){};

};

class File : public IFile
{
public:
    File(string name){ this->name = name; }
    void Show(){
        cout<<pos<<name<<endl;
    }
    void Setpos(string backdir){
        pos.append(backdir);
    }
private:
    string name;
    string pos = "";
};

class Folder : public IFile
{
public:
    Folder(string name){ this->name = name; }
    void Add(IFile* file){
        filelist.push_back(file);
        file->Setpos(pos);
    }
    void Show(){
        for(list<IFile*>::iterator iter = filelist.begin(); iter!=filelist.end(); iter++){
           (*iter)->Show(); 
        }
    }
    void Setpos(string backdir){
        pos.append(backdir);
        pos.append(name);
        pos.append("/");
    }
private:
    list<IFile*> filelist;
    string name;
    string pos = "";
};

int main()
{
    IFile* root = new Folder("root");
    root->Setpos("/");
    IFile* file1 = new File("undefined");
    IFile* folder1 = new Folder("firstf");
    root->Add(file1);
    root->Add(folder1);
    IFile* file2 = new File("undefined2");
    folder1->Add(file2);
    folder1->Add(new File("hello.cpp"));
    root->Add(new File("globals.h"));
    IFile* folder2 = new Folder("secondf");
    folder1->Add(folder2);
    folder2->Add(new File("globals.h"));
    cout<<"Under root folder:"<<endl;
    root->Show();
    cout<<"\nUnder folder1 folder:"<<endl;
    folder1->Show();
    return 0;
}