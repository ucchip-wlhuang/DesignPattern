#include <iostream>
#include <string>
using namespace std;

class PayWay
{
public:
    virtual bool Pay(float money) = 0;
};

class WeChatpay : public PayWay
{
public:
    WeChatpay(float balance){
        this->balance = balance;
    }
    bool Pay(float money){
        cout<<"Using WeChat Pay..."<<endl;
        if(money <= balance){
            this->balance = this->balance - money;
            return true;
        }
        return false;
    }
private:
    float balance;
};

class Alipay : public PayWay
{
public:
    Alipay(float balance){
        this->balance = balance;
    }
    bool Pay(float money){
        cout<<"Use Alipay Pay..."<<endl;
        if(money <= balance){
            this->balance = this->balance - money;
            return true;
        }
        return false;
    }
private:
    float balance;
};

class PaySystem
{
public:
    void SetPayWay(PayWay* pw){
        this->pw = pw;
    }
    bool PayMoney(float money){
        if(pw->Pay(money)){
            cout<<"Successful Payment!"<<endl;
            return true;
        }
        else
        {
            cout<<"Failed Payment!"<<endl;
            return false;
        }
    }
private:
    PayWay* pw;
};

int main()
{
    float price = 57.2;
    PaySystem ps;
    PayWay* ali = new Alipay(36.15);
    PayWay* wechat = new WeChatpay(100);
    ps.SetPayWay(ali);
    if(!ps.PayMoney(price)){
        ps.SetPayWay(wechat);
        ps.PayMoney(price);
    }
    return 0;
}