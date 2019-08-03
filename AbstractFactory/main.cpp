#include <iostream>

using namespace std;

class Mouse
{
public:
	virtual void SayHi(){};
};

class DellMouse : public Mouse
{
private:
	void SayHi(){
		cout<<"Hi, I'm DellMouse."<<endl;
	}
};

class HpMouse : public Mouse
{
private:
	void SayHi(){
		cout<<"Hi, I'm HpMouse."<<endl;
	}
};

class Keyboard
{
public:
	virtual void SayHello(){};
};

class DellKeyboard : public Keyboard
{
private:
	void SayHello(){
		cout<<"Hello, I'm DellKeyboard."<<endl;
	}
};

class HpKeyboard : public Keyboard
{
private:
	void SayHello(){
		cout<<"Hello, I'm HpKeyboard."<<endl;
	}
};

class Factory
{
protected:
	virtual Mouse* CreateMouse();
	virtual Keyboard* CreateKeyboard();
};

class DellFactory : public Factory
{
public:
	Mouse* CreateMouse(){
		return new DellMouse;
	}
	Keyboard* CreateKeyboard(){
		return new DellKeyboard;
	}
};

class HpFactory : public Factory
{
public:
	Mouse* CreateMouse(){
		return new HpMouse;
	}
	Keyboard* CreateKeyboard(){
		return new HpKeyboard;
	}
};

int main()
{
	DellFactory dellfactory;
	Mouse* dellmouse = dellfactory.CreateMouse();
	dellmouse->SayHi();
	Keyboard* dellkeyboard = dellfactory.CreateKeyboard();
	dellkeyboard->SayHello();
	
	return 0;
}