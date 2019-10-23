#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>

using namespace std;

class Observer
{
public:
    virtual float CompareBid(float bp) = 0;
    virtual void PayMoney(float pm) = 0;
};

class Bidder : public Observer
{
public:
    int id;
    Bidder(int id, float money){
        this->id = id;
        this->money = money;
    }
    float CompareBid(float bp){
        srand((unsigned int)time(0));
        if(bp < money){
            return bp + (rand() % (int)((money - bp + 0.1)*10))/10.0;
        }
        return 0;
    }
    void PayMoney(float pm){
        this->money = this->money - pm;
    }
private:
    float money;
};

class ObserverList
{
public:
    int max_id;
    int bid_num;
    float max;
    void Add(Observer* ob){
        blist.push_back(ob);
    }
    void GetBidPrice(float m){
        float o_pri;
        bid_num = 0;
        max = m;
        for(it = blist.begin(); it != blist.end(); it++){
            o_pri = (*it)->CompareBid(m);
            if(o_pri != 0){
                cout<<"Bidder No."<<((Bidder*)(*it))->id<<" has bidded "<<o_pri<<"$"<<endl;
                bid_num++;
            }
            if(max < o_pri){
                max_id = ((Bidder*)(*it))->id;
                max = o_pri;
            }
        }
    }
    Observer* Findtop(int id){
        for(it = blist.begin(); it != blist.end(); it++){
            if(((Bidder*)(*it))->id == id)
                return  *it;
        }
        return NULL;
    }
private:
    vector<Observer*> blist;
    vector<Observer*>::iterator it;
};

class Auctioneer
{
public:
    void SendBid(ObserverList oblist, float price){
            cout<<"First Price:"<<price<<"$"<<endl;
            oblist.GetBidPrice(price);
            if(oblist.bid_num == 0){
                cout<<"This item is passed!"<<endl;
            }
            else
            {
                while(oblist.bid_num > 1){
                    cout<<"Next Price:"<<oblist.max<<"$"<<endl;
                    oblist.GetBidPrice(oblist.max);
                }
                oblist.Findtop(oblist.max_id)->PayMoney(oblist.max);
                cout<<"Congrate Bidder No."<<oblist.max_id<<" has got the item by "<<oblist.max<<"$"<<endl;
            }
    }
};

int main()
{
    Auctioneer auc;
    ObserverList oblist;
    cout<<"*******  Bid Ready Start  *******"<<endl;
    oblist.Add(new Bidder(1, 458));
    oblist.Add(new Bidder(2, 453.5));
    oblist.Add(new Bidder(3, 454.7));
    oblist.Add(new Bidder(4, 453.6));
    oblist.Add(new Bidder(5, 450.2));
    cout<<endl<<"********* Item 1 *********"<<endl;
    auc.SendBid(oblist, 60);
    cout<<endl<<"********* Item 2 *********"<<endl;
    auc.SendBid(oblist, 68.5);
    cout<<endl<<"********* Item 3 *********"<<endl;
    auc.SendBid(oblist, 33.8);
    cout<<endl<<"********* Item 4 *********"<<endl;
    auc.SendBid(oblist, 50);
    cout<<endl<<"********* Item 5 *********"<<endl;
    auc.SendBid(oblist, 26.7);
    cout<<endl<<"********* Item 6 *********"<<endl;
    auc.SendBid(oblist, 70);
    cout<<endl<<"********* Item 7 *********"<<endl;
    auc.SendBid(oblist, 38.5);
    cout<<endl<<"********* Item 8 *********"<<endl;
    auc.SendBid(oblist, 33.8);
    cout<<endl<<"********* Item 9 *********"<<endl;
    auc.SendBid(oblist, 26.7);
    return 0;
}