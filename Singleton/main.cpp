#include <iostream>

using namespace std;

class LazySingleton //Lazy Pattern
{
private:
	LazySingleton(){}
	static LazySingleton *m_pInstance;
public:
	static LazySingleton * GetInstance()
	{
		if(m_pInstance == NULL) {
			m_pInstance = new LazySingleton();
			cout<<"Construct lazy singleton Succeed!"<<endl;
		}
		else {
			cout<<"The lazy singleton has already been constructed. No need to do again."<<endl;
		}
		return m_pInstance;
	}
};

LazySingleton* LazySingleton::m_pInstance = NULL;	//static variables need to be inited out of class.

int main()
{
	LazySingleton* p1 = LazySingleton::GetInstance();
	LazySingleton* p2 = p1 -> GetInstance();
	LazySingleton & ref = *LazySingleton::GetInstance();
	return 0;
}