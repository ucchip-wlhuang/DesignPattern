#include <iostream>

using namespace std;

class WebCourse
{
public:
    virtual void Process() final{  //final only can be used on virtual function and class in C++
        MakePPT();
        RecordVideo();
        if(HasHomework()){
            SetHomework();
        }
        ProvideSource();
        UpLoad();
    }
protected:
    virtual void MakePPT(){
        cout<<"Make PPT"<<endl;
    }
    void RecordVideo(){
        cout<<"Record Video"<<endl;
    }
    virtual void SetHomework() = 0;
    virtual void ProvideSource(){   //Difference from SetHomework() is just SetHomework() must be defined in child class
    }                               //Hook function, to help add extended function
    void UpLoad(){
        cout<<"Upload to the website"<<endl;
    }
    virtual bool HasHomework(){
        return false;
    }
};

class Java : public WebCourse
{
public:
    bool HasHomework(){
        return true;
    }
    void MakePPT(){
    }
    void SetHomework(){
        cout<<"Set Java Homeword"<<endl;
    }
};

class C : public WebCourse
{
public:
    void SetHomework(){     //Because SetHomework() in base class is interface. Although we don't need it, but we still need to write this.
        cout<<"Set C Homeword"<<endl;
    }
    void ProvideSource(){
        cout<<"Provide CodeLite-13.0"<<endl;
        ProvideDemo();
    }
    void ProvideDemo(){
        cout<<"Provide C projects' demos"<<endl;
    }
};

int main()
{
    WebCourse* wc = new Java;
    cout<<"Make Java Course Process:"<<endl;
    wc->Process();
    
    wc = new C;
    cout<<endl<<"Make C Course Process:"<<endl;
    wc->Process();
    return 0;
}