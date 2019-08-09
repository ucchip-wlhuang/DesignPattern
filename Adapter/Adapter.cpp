#include <iostream>
#include <string>
using namespace std;

class SDcard
{
public:
	virtual string SDread() = 0;
};

class SDcardImp : public SDcard
{
private:
	string SDread(){
		string msg = " read SD-card!";
		return msg;
	}
public:
	SDcardImp(){
		cout<<"Get a SD-card"<<endl;
	}
};

class PC
{
public:
	virtual void read(SDcard* sdc){};
	PC(){
		cout<<"PC only read SD-card"<<endl;
	}
};

class Dell : public PC
{
private:
	void read(SDcard* sdc){
		cout<<"Dell"<<sdc->SDread()<<endl;
	}
};

class TFcard
{
public:
	virtual string TFRead() = 0;
};

class TFcardImp : public TFcard
{
private:
	string TFRead(){
		string msg = " read TF-card!";
		return msg;
	}
public:
	TFcardImp(){
		cout<<"Get a TF-card"<<endl;
	}
};

class Adapter : public SDcard
{
private:
	TFcard* src;
public:
	Adapter(TFcard* src){
		cout<<"Adapter plug : TF-card to SD-card"<<endl;
		this->src = src;
	}
	string SDread(){
		return src->TFRead();
	}
};

int main()
{
	PC* computer = new Dell();
	SDcard* sd = new SDcardImp();
	TFcard* tf = new TFcardImp();
	computer->read(sd);
	Adapter* TFtoSD = new Adapter(tf);
	computer->read(TFtoSD);
	return 0;
}

