#include <iostream>

using namespace std;

class LazySingleton //Lazy Pattern
{
private:
	LazySingleton(){
		cout<<"Construct lazy singleton Succeed!"<<endl;
	}
	static LazySingleton *m_pInstance;
public:
	static LazySingleton * GetInstance()
	{
		if(m_pInstance == NULL) {
			m_pInstance = new LazySingleton();
		}
		else {
			cout<<"The lazy singleton has already been constructed. Get lazy singleton Succeed!"<<endl;
		}
		return m_pInstance;
	}
};

class HungrySingleton //Hungry Pattern
{
private:
	HungrySingleton(){
		cout<<"Construct hungry singleton Succeed!"<<endl;
	}
	static HungrySingleton *m_hpInstance;
public:
	static HungrySingleton * GetInstance()
	{
		cout<<"Get hungry singleton Succeed!"<<endl;
		return m_hpInstance;
	}
};

LazySingleton* LazySingleton::m_pInstance = NULL;	//static variables need to be inited out of class.
HungrySingleton* HungrySingleton::m_hpInstance = new HungrySingleton;

int main()
{
	LazySingleton* p1 = LazySingleton::GetInstance();
	LazySingleton* p2 = p1 -> GetInstance();
	LazySingleton & ref = *LazySingleton::GetInstance();
	
	HungrySingleton* h1 = HungrySingleton::GetInstance();
	HungrySingleton* h2 = h1 -> GetInstance();
	HungrySingleton & href = *HungrySingleton::GetInstance();
	return 0;
}