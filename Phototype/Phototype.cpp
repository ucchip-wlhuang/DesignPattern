#include <iostream>
#include <string>
using namespace std;

static int id = 0;

class Monkey
{
public:
	Monkey(){};
	virtual ~Monkey(){};
	virtual Monkey* Clone() = 0;
	virtual void Play(){};
};

class SunWukong : public Monkey
{
public:
	SunWukong(string name, string item){
		m_strName = name;
		m_playitem = item;
	}
	~SunWukong(){}
	
	SunWukong(const SunWukong &other){
		m_strName = "MonkeySon" + to_string(++id);
		m_playitem = "everything";
		cout<<other.m_strName<<" use its hair to clone a "<<m_strName<<endl;
	}
	
	Monkey* Clone() {
		return new SunWukong(*this);
	}
	void Play(){
		cout<<m_strName<<" play "<<m_playitem<<endl;
	}
private:
	string m_strName;
	string m_playitem;
};

int main()
{
	Monkey* SWK = new SunWukong("Qi Tian Da Sheng", "Golden-Hoop-Stick");	
	SWK->Play();
	Monkey* son = SWK->Clone();
	son->Play();
	Monkey* grandson = SWK->Clone();
	grandson->Play();
	Monkey* sonson = son->Clone();
	sonson->Play();
	return 0;
}