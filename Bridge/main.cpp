#include <iostream>
#include <string>
using namespace std;

class App
{
public:
	virtual void Install(string name){};
};

class Explorer : public App
{
private:
	void Install(string name){
		cout<<name<<" install "<<"Explorer!"<<endl;
	}
};

class Game : public App
{
private:
	void Install(string name){
		cout<<name<<" install "<<"Game!"<<endl;
	}
};

class Phone
{
protected:
	App* app;
	string name;
public:
	virtual void Install() = 0;
	void SetApp(App* app) {
		this->app = app;
	}
};

class OPPO : public Phone
{
private:
	void Install() {
		app->Install(this->name);
	}
public:
	OPPO(){
		this->name = "OPPO";
	}
};

class VIVO : public Phone
{
private:
	void Install() {
		app->Install(this->name);
	}
public:
	VIVO(){
		this->name = "VIVO";
	}
};

class HUAWEI : public Phone
{
private:
	void Install() {
		app->Install(this->name);
	}
public:
	HUAWEI(){
		this->name = "HUAWEI";
	}
};

int main()
{
	Phone* textphone = new HUAWEI;
	textphone->SetApp(new Game);
	textphone->Install();
	Phone* textmobile = new VIVO;
	textmobile->SetApp(new Explorer);
	textmobile->Install();
	return 0;
}