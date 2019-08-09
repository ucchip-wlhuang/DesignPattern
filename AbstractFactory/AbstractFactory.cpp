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
public:
	virtual Mouse* CreateMouse(){return NULL;};
	virtual Keyboard* CreateKeyboard(){return NULL;};
};

class DellFactory : public Factory
{
private:
	Mouse* CreateMouse(){
		return new DellMouse;
	}
	Keyboard* CreateKeyboard(){
		return new DellKeyboard;
	}
};

class HpFactory : public Factory
{
private:
	Mouse* CreateMouse(){
		return new HpMouse;
	}
	Keyboard* CreateKeyboard(){
		return new HpKeyboard;
	}
};

int main()
{
	Factory* factory = new DellFactory;
	Mouse* mouse = factory->CreateMouse();
	mouse->SayHi();
	Keyboard* keyboard = factory->CreateKeyboard();
	keyboard->SayHello();
	
	return 0;
}