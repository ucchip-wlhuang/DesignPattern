#include <iostream>
using namespace std;

class Device
{
public:
	virtual void Open(){};
	virtual void Close(){};
};

class Screen : public Device
{
public:
	void Open() {
		cout<<"Screen Open!"<<endl;
	}
	void Close() {
		cout<<"Screen Close~"<<endl;
	}
};

class CPU : public Device
{
public:
	void Open() {
		cout<<"CPU Open!"<<endl;
	}
	void Close() {
		cout<<"CPU Close~"<<endl;
	}
};

class Drive : public Device
{
public:
	void Open() {
		cout<<"Drive Open!"<<endl;
	}
	void Close() {
		cout<<"Drive Close~"<<endl;
	}
};

class Computer    //reception client
{
private:
	Screen screen;
	CPU cpu;
	Drive drive;
	
public:	
	void OpenPC() {
		screen.Open();
		cpu.Open();
		drive.Open();
	}
	void ClosePC() {
		screen.Close();
		cpu.Close();
		drive.Close();
	}
};

int main(int argc, char **argv)
{
	Computer* pc = new Computer;
	pc->OpenPC();
	pc->ClosePC();
	return 0;
}
