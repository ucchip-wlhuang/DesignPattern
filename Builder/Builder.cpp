#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Packing
{
public:
	virtual string Pack(){return NULL;}
};

class Wrapper : public Packing
{
	string Pack(){
		return "Wrapped";
	}
};

class Bottle : public Packing
{
	string Pack(){
		return "Bottle";
	}
};

class Item
{
public:
	virtual string GetName(){return NULL;}
	virtual float GetPrice(){return 0;}
	virtual Packing* GetPack(){return NULL;}
};

class Burger : public Item
{
public:
	Packing* GetPack(){
		return new Wrapper;
	}
};

class VerBurger : public Burger
{
public:
	string GetName(){
		return "VerBurger";
	}
	float GetPrice(){
		return 8.2;
	}
};

class ChickenBurger : public Burger
{
public:
	string GetName(){
		return "ChickenBurger";
	}
	float GetPrice(){
		return 14.2;
	}
};

class ColdDrink : public Item
{
public:
	Packing* GetPack(){
		return new Bottle;
	}
};

class Coke : public ColdDrink
{
public:
	string GetName(){
		return "Coke";
	}
	float GetPrice(){
		return 6;
	}
};

class Pepsi : public ColdDrink
{
public:
	string GetName(){
		return "Pepsi";
	}
	float GetPrice(){
		return 5.5;
	}
};

class Meal
{
private:
	vector<Item> list; 
	float sum = 0;
	string name;
public:
	void Add(Item* item){
		cout<<"Item: "<<item->GetName()<<",  Packing: "<<item->GetPack()->Pack()<<",  Price: $"<<item->GetPrice()<<endl;
		sum += item->GetPrice();
		list.push_back(*item);
	}
	void ShowSum(){
		cout<<"Total Cost: $"<<sum<<endl;
	}
	void SetName(string m_meal){
		this->name = m_meal;
	}
	void ShowName(){
		cout<<"Meal: "<<name<<endl;
	}
};

class MealBuilder
{
public:
	void VegMeal(){
		Meal veg;
		veg.SetName("VegMeal 1");
		veg.ShowName();
		veg.Add(new VerBurger);
		veg.Add(new Coke);
		veg.ShowSum();
		cout<<endl;
	}
	void NonVegMeal(){
		Meal nonveg;
		nonveg.SetName("Non-veg Meal v2.0");
		nonveg.ShowName();
		nonveg.Add(new ChickenBurger);
		nonveg.Add(new Pepsi);
		nonveg.ShowSum();
		cout<<endl;
	}
};

int main(int argc, char **argv)
{
	MealBuilder mealbuild;
	mealbuild.VegMeal();
	mealbuild.NonVegMeal();
	return 0;
}
