#include <iostream>
#include <string>

using namespace std;

class Shape{
	public:
	virtual void Draw() {};
};

class Circle : public Shape{
	void Draw(){ cout<<"Draw a circle"<<endl; }
};

class Square : public Shape{
	void Draw(){ cout<<"Draw a square"<<endl;  }
};

class Rectangle : public Shape{
	void Draw(){ cout<<"Draw a rectangle"<<endl;  }
};

class Triangle : public Shape{
	void Draw(){ cout<<"Draw a triangle"<<endl;  }
};

class Casual : public Shape{
	void Draw(){ cout<<"Draw casually"<<endl;  }
};

class ShapeFactory{
	public:
	static Shape* Relshape(string type) {
		if(!type.compare("CIRCLE")) {
			return new Circle(); 
		} else if(!type.compare("SQUARE")) {
			return new Square(); 
		} else if(!type.compare("RECTANGLE")) {
			return new Rectangle();
		} else if(!type.compare("TRIANGLE")) {
			return new Triangle();
		} else {
			return new Casual();
		}
	}
};

class FactoryPattern{
public:
	FactoryPattern(){
		cout<<"************MENU*************"<<endl;
		cout<<"*** 1.CirCle              ***"<<endl;
		cout<<"*** 2.Square              ***"<<endl;
		cout<<"*** 3.Rectangle           ***"<<endl;
		cout<<"*** 4.Triangle            ***"<<endl;
		cout<<"*** 5.Casually            ***"<<endl;
		cout<<"*****************************"<<endl;
		cout<<"FactoryPattern------What do you want to draw?"<<endl;
		cout<<"Answer-----  ";
		cin>>tag;
		switch(tag)
		{
			case 1:shape= ShapeFactory::Relshape("CIRCLE");	break;
			case 2:shape= ShapeFactory::Relshape("SQUARE");	break;
			case 3:shape= ShapeFactory::Relshape("RECTANGLE");	break;
			case 4:shape= ShapeFactory::Relshape("TRIANGLE");	break;
			default:shape= ShapeFactory::Relshape("");	break;
		}
		shape->Draw();
	}
	~FactoryPattern(){}
private:
	int tag;
	Shape* shape;
};

int main()
{
	FactoryPattern factory;
	return 0;
}