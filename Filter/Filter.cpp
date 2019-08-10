#include <iostream>
#include <string>
#include <list>
#include <algorithm>
using namespace std;

class Person
{
public:
	Person(string name, string gender, int age, string marialStatus, string job = "NULL"){
		this->name = name;
		this->gender = gender;
		this->age = age;
		this->marialStatus = marialStatus;
		this->job = job;
	}
	string GetName(){
		return name;
	}
	string GetGender(){
		return gender;
	}
	int GetAge(){
		return age;
	}
	string GetMs(){
		return marialStatus;
	}
	string GetJob(){
		return job;
	}
	bool operator==(const Person &other){   //operator == to compare two person, "const" is neccessary
		if(this->name==other.name&&this->age==other.age&&this->gender==other.gender&&this->marialStatus==other.marialStatus&&this->job==other.job){
			return true;
		}
		else{
			return false;
		}
	}	
private:
	string name;
	string gender;
	int age;
	string marialStatus;
	string job;
};

void Show(list<Person> showlist){    //for_each(,,) the third parament which uses function_name need to be static function
	for(list<Person>::iterator iter = showlist.begin(); iter!=showlist.end(); iter++){
		Person instance(*iter);
		cout<<"Name:"<<instance.GetName()<<"\tGender:"<<instance.GetGender()<<"\tAge:"<<instance.GetAge()<<"\tMarialStatus:"<<instance.GetMs()<<"\tJob:"<<instance.GetJob()<<endl;
	}
}

class Filter
{
public:
	virtual list<Person> BaseCriteria(list<Person> base) = 0;
};

class CriteriaFemale : public Filter
{
public:
	list<Person> BaseCriteria(list<Person> base){
		list<Person> ret_list;
		for_each(base.begin(), base.end(), [&](Person instance){
			if(instance.GetGender()=="Female"){
				ret_list.push_back(instance);
			}
		});
		return ret_list;
	}
};

class CriteriaSingle : public Filter
{
public:
	list<Person> BaseCriteria(list<Person> base){
		list<Person> ret_list;
		for_each(base.begin(), base.end(), [&](Person instance){
			if(instance.GetMs()=="Single"){
				ret_list.push_back(instance);
			}
		});
		return ret_list;
	}
};

class AndCriteria : public Filter
{
public:
	AndCriteria(Filter* first, Filter* second)
	{
		this->first = first;
		this->second = second;
	}
	list<Person> BaseCriteria(list<Person> base){
		list<Person> first_list = first->BaseCriteria(base);
		list<Person> second_list = second->BaseCriteria(first_list);
		return second_list;
	}
private:
	Filter* first;
	Filter* second;
};

class OrCriteria : public Filter
{
public:
	OrCriteria(Filter* first, Filter* second)
	{
		this->first = first;
		this->second = second;
	}
	list<Person> BaseCriteria(list<Person> base){
		list<Person> first_list = first->BaseCriteria(base);
		list<Person> second_list = second->BaseCriteria(base);
		for(list<Person>::iterator iter = second_list.begin(); iter!=second_list.end(); iter++){
			list<Person>::iterator it = find(first_list.begin(), first_list.end(), (*iter));
			if(it == first_list.end()){
				first_list.push_back(*iter);
			}
		}
		return first_list;
	}
private:
	Filter* first;
	Filter* second;
};

int main()
{
	list<Person> person_list;
	person_list.push_back(Person("Alice", "Female", 24, "Married"));
	person_list.push_back(Person("Peter", "Male", 26, "Married", "teacher"));
	person_list.push_back(Person("Billy", "Female", 17, "Single", "student"));
	person_list.push_back(Person("Ben", "Male", 12, "Single", "student"));
	person_list.push_back(Person("Jane", "Female", 32, "Married", "waitress"));
	Filter* female = new CriteriaFemale;
	Filter* single = new CriteriaSingle;
	Filter* femAndsin = new AndCriteria(new CriteriaFemale, new CriteriaSingle);
	Filter* femOrsin = new OrCriteria(new CriteriaFemale, new CriteriaSingle);
	list<Person> female_list = female->BaseCriteria(person_list);
	list<Person> single_list = single->BaseCriteria(person_list);
	list<Person> femAndsin_list = femAndsin->BaseCriteria(person_list);
	list<Person> femOrsin_list = femOrsin->BaseCriteria(person_list);
	cout<<"\n---------------------------------Full List----------------------------------"<<endl;
	Show(person_list);
	cout<<"\n--------------------------------Female List---------------------------------"<<endl;
	Show(female_list);
	cout<<"\n--------------------------------Single List---------------------------------"<<endl;
	Show(single_list);
	cout<<"\n---------------------------Female And Single List---------------------------"<<endl;
	Show(femAndsin_list);
	cout<<"\n---------------------------Female Or Single List----------------------------"<<endl;
	Show(femOrsin_list);
	return 0;
}