#include <bits/stdc++.h>
using namespace std;

class INotification
{
public:
    virtual string getContent() = 0;
};

class Notification : public INotification
{
    string content;

public:
    Notification(string c)
    {
        content = c;
    }
    string getContent() override
    {
        return content;
    }
};

//********  DECORATOR ***********//

class IDecorator : public INotification
{
    protected :
    INotification *notification;

public:
    IDecorator(INotification *n)
    {
        notification = n;
    }

};

class SignatureDecorator : public IDecorator
{
    string extraText;

public:
    SignatureDecorator(INotification *notifi, string msg) : IDecorator(notifi)
    {
        extraText = msg;
    }
    string getContent() override
    {
        return notification->getContent() + extraText ; 
    }
};

class TimeStampDecorator : public IDecorator
{
    string timing;

public:
    TimeStampDecorator(INotification *n, string time) : IDecorator(n)
    {
        timing = time;
    };
    string getContent() override
    {
        return notification->getContent() + timing;
    }
};

// *********  Observer  & obserable to receive notification content ************//

class IObserver
{
public:
    virtual void getUpdate() = 0;
};

class IObservable
{
public:
    virtual void addObserver(IObserver *observer) = 0;
    virtual void removeObserver(IObserver *observer) = 0;
    virtual vector<IObserver *> getObserverList() = 0;
};

class Observable : public IObservable
{
private:
    vector<IObserver *> observerList;
    INotification *currentnotification;

public:
    Observable()
    {
        currentnotification = nullptr;
    }
    void addObserver(IObserver *observer) override
    {
        observerList.push_back(observer);
    }

    void removeObserver(IObserver *observer) override
    {
        for (auto ob : observerList)
        {
            if (ob == observer)
            {
                delete observer;
            }
        }
    }
    vector<IObserver *> getObserverList() override
    {
        return observerList;
    }
    void notifyObserver()
    {
        for (auto it : observerList)
        {
            it->getUpdate();
        }
    }
    void setNotification(INotification *n)
    {
        currentnotification = n;
        notifyObserver();
    }

    INotification *getNotification()
    {
        return currentnotification;
    }
};

class Logging : public IObserver
{
    Observable *observable;

public:
    Logging(Observable *ob)
    {
        this->observable = ob;
    }
    void getUpdate() override
    {
        cout << "Your Notification Update : " << observable->getNotification()->getContent();
    }
};

//************ Strategy  for sending various type of notification *************//

class NotificationStrategy
{
public:
    virtual void sendNotification(string content) = 0;
};
class EmailNotification : public NotificationStrategy
{
    string emailId;

public:
    EmailNotification(string id)
    {
        emailId = id;
    }
    void sendNotification(string content)
    {
        cout << "send to your email : " << emailId << ":" << content << endl;
    }
};

class SMSNotification : public NotificationStrategy
{
    int phoneNo;

public:
    SMSNotification(int phone)
    {
        phoneNo = phone;
    }
    void sendNotification(string content)
    {
        cout << "send to your phoneNo: " << phoneNo << ":" << content << endl;
    }
};

class PopUpNotification : public NotificationStrategy
{
public:
    void sendNotification(string content)
    {
        cout << "pop up msg :" << content << endl;
    }
};

class NotificationEnginer : public IObserver
{
    Observable *observable;
    vector<NotificationStrategy *> strategylist;

public:
    NotificationEnginer(Observable *ob)
    {
        observable = ob;
    }
    void addNotificationStrategy(NotificationStrategy *st)
    {
        strategylist.push_back(st);
    }
    void deleteNotificationStrategy(NotificationStrategy *strategy)
    {
        for (NotificationStrategy *st : strategylist)
        {
            if (st == strategy)
            {
                delete st;
            }
        }
    }
    void getUpdate() override
    {
        string content = observable->getNotification()->getContent();
        for (NotificationStrategy *st : strategylist)
        {
            st->sendNotification(content);
        }
    }
};



//**************  Notification services ***********************//

class NotificationService
{
    vector<INotification *> notificationList;
    Observable *observable;
    static NotificationService *serviceInstance;

    NotificationService()
    {
        observable = new Observable();
    }

public:
    static NotificationService *getServiceInstace()
    {
        if (serviceInstance == nullptr)
        {
            serviceInstance = new NotificationService();
        }
        return serviceInstance;
    }
    void addNotification(INotification *notifi)
    {
        notificationList.push_back(notifi);
    }
    Observable *getObservable()
    {
        return observable;
    }
    void sendNotification(INotification *notification)
    {
        notificationList.push_back(notification);
        observable->setNotification(notification);
        observable->notifyObserver();
    }
    void showNotificationStorage(){
       for(int i=0;i<notificationList.size();i++){
        cout<<"No . "<<i+1 << notificationList[i]->getContent() << endl;
       }
    }
    ~NotificationService()
    {
        delete observable;
    }
};
NotificationService *NotificationService ::serviceInstance = nullptr;

int main()
{

    Notification *notifi = new Notification("your order has been shipped");
    IDecorator *signDec = new SignatureDecorator(notifi, "By today evening");

    NotificationService *serviceInstance = NotificationService ::getServiceInstace();

    Observable *observable = serviceInstance->getObservable();
    IObserver *logger = new Logging(observable);

    NotificationEnginer *observer3 = new NotificationEnginer(observable);
    EmailNotification *email = new EmailNotification("abc@gmail.com");
    SMSNotification *sms = new SMSNotification(987654347);

    observer3->addNotificationStrategy(email);
    observer3->addNotificationStrategy(sms);
    observer3->addNotificationStrategy(sms);

    observable->addObserver(logger);
    observable->addObserver(observer3);



    serviceInstance->sendNotification(signDec);
    // serviceInstance->showNotificationStorage();
    
}