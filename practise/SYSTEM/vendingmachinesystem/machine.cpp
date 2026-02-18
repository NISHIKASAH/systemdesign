#include<iostream>
using namespace std;

class VendingMachine ;
class VendingState { 
    public : 
    virtual VendingState * insertcoin(VendingMachine * machine , int coins)=0;
      virtual VendingState * selectitem(VendingMachine * machine )=0;
        virtual VendingState * dispenseitem(VendingMachine * machine )=0;
       virtual VendingState * returncoin(VendingMachine * machine) =0;
        virtual VendingState * refill(VendingMachine * machine , int qty) =0;

        virtual string getStateName() =0;

        ~VendingState() {}
        

};

class VendingMachine {

    public : 
    int insertedcoin ;
    int itemscount ; 
    int itemsprice;


    VendingMachine(int count, int price);
    VendingState * currentstate ; 
    VendingState * nocoinstate ;
    VendingState* hascoinstate; 
    VendingState * dispensestate;
    VendingState * soldoutstate;


    void insertCoin(int coins);
    void selectcoin();
    void dispenseitem();
    void refill(int qty );
    void returncoin();

   int getItem(){
    return itemscount;
   }
   int decrementitemcount(){
    itemscount--;
   }
   int incrementitemcount(int count){
    itemscount += count;
   }
   int addCoins(int count){
    insertedcoin += count;
   }
   void setInsertedCoin(int count){
    insertedcoin = count;
   }
   
int getInsertedCoin(){
    return insertedcoin;

}
void setPrice(int price){
    itemsprice = price;
}
int getPrice(){
    return itemsprice;
}

void PrintStatus();

 VendingState* getNoCoinstate() {
    return nocoinstate;
 }
VendingState* getHasCoinstate(){
    return hascoinstate;
}

VendingState * getDispenseItemstate(){
    return dispensestate;
}
VendingState* getSoldOutstate(){
    return soldoutstate;
}

};
class Nocoinstate : public VendingState {
    public : 
    VendingState * insertcoin(VendingMachine * machine , int coins) override {
        cout<<"--got coin to insert--"<<endl;
        machine->setInsertedCoin(coins);
        return machine->getHasCoinstate();
    }
       VendingState * selectitem(VendingMachine * machine ) override {
          cout<<"--No coin to select--"<<endl;
          return machine->getNoCoinstate();
       }
        VendingState * dispenseitem(VendingMachine * machine ) override {
             cout<<"--No coin to dispense--"<<endl;
             return machine->getNoCoinstate();
        }
       VendingState * returncoin(VendingMachine * machine) override {
        cout<<"--no coin to return--"<<endl;
        return machine->getNoCoinstate();
       }
       VendingState * refill(VendingMachine * machine , int items) override {
         machine->incrementitemcount(items);
         cout<<"--refill items--"<<endl;
         return machine->getNoCoinstate();
       }
        string getStateName() override {
        return "nocoinstate";
        }

};

class Hascoinstate : public VendingState {
    public : 
    VendingState * insertcoin(VendingMachine * machine , int coins) override {
        machine->addCoins(coins);
        cout<<"--additional coins added--"<<endl;
        return machine->getHasCoinstate();
    }
       VendingState * selectitem(VendingMachine * machine ) override {
           if(machine->getPrice() <= machine->insertedcoin){
                cout<<"--item selected--"<<endl;
                int change = machine->insertedcoin - machine->getPrice();
                if(change >0){
                    cout<<"--Change return of rupees--"<<change<<endl;
                    machine->setInsertedCoin(0);
                }
               return machine->getDispenseItemstate();
            }
                cout << "--Not enough coins to buy item--" << endl;
    return machine->getHasCoinstate();

       }
        VendingState * dispenseitem(VendingMachine * machine ) override {
           cout<<"--please select item first--"<<endl;
           return machine->getHasCoinstate();
        }
       VendingState * returncoin(VendingMachine * machine) override {
        cout<<"--coin returned--"<<endl;
        machine->setInsertedCoin(0);
        return machine->getNoCoinstate();
       }
       VendingState * refill(VendingMachine * machine , int items) override {
        
         cout<<"--can't refill items--"<<endl;
         return machine->getHasCoinstate();
       }
        string getStateName() override {
        return "hascoinstate";
        }

};
class Dispensestate : public VendingState {
    public : 
    VendingState * insertcoin(VendingMachine * machine , int coins) override {
        cout<<"--no coin to insert at dispense state-- "<<endl;
        return machine->getDispenseItemstate();
    }
       VendingState * selectitem(VendingMachine * machine ) override {
         cout<<"--already at dispense state, no item to select--"<<endl;
        return machine->getDispenseItemstate();
       }
        VendingState * dispenseitem(VendingMachine * machine ) override {
            cout<<"--items has been dispense--" <<endl;
            machine->decrementitemcount();
            machine->setInsertedCoin(0);
            if(machine->getItem() >0){
                
                return machine->getNoCoinstate();
            }
            else{
                cout<<"--item got sold out--"<<endl;
                return  machine->getSoldOutstate();
            }
           
        }
       VendingState * returncoin(VendingMachine * machine) override {
        cout<<"--cant return coin while dispensing--"<<endl;
        return machine->getDispenseItemstate();
       }
       VendingState * refill(VendingMachine * machine , int items) override {
         cout<<"--cant refill while dispensing--"<<endl;
       return  machine->getDispenseItemstate();
       }
        string getStateName() override {
        return "dispensestate";
        }

};
class Soldoutstate : public VendingState {
    public : 
    VendingState * insertcoin(VendingMachine * machine , int coins) override {
        cout<<"--items already sold out--"<<endl;
        return machine->getSoldOutstate();
    }
       VendingState * selectitem(VendingMachine * machine ) override {
         cout<<"--items already sold out--"<<endl;
        return machine->getSoldOutstate();
       }
        VendingState * dispenseitem(VendingMachine * machine ) override {
            cout<<"--items already sold out--"<<endl;
        return machine->getSoldOutstate();
        }
       VendingState * returncoin(VendingMachine * machine) override {
        cout<<"--items already sold out--"<<endl;
        return machine->getSoldOutstate();
       }
       VendingState * refill(VendingMachine * machine , int items) override {
         machine->incrementitemcount(items);
         cout<<"--refill items--"<<endl;
        return machine->getNoCoinstate();
       }
        string getStateName() override {
        return "soldoutstate";
        }

};

   VendingMachine :: VendingMachine(int count, int price) {
       this-> itemscount = count; 
        this->itemsprice = price; 
       this-> insertedcoin = 0;
        nocoinstate = new Nocoinstate();
        hascoinstate = new Hascoinstate();
        dispensestate = new Dispensestate();
        soldoutstate = new Soldoutstate();

        if(itemscount >0){
            currentstate = nocoinstate;
        }
        else{
            currentstate = soldoutstate;
        }



    }


void VendingMachine :: insertCoin( int coin){
    currentstate = currentstate->insertcoin(this, coin);

}

void VendingMachine :: selectcoin(){
    currentstate = currentstate->selectitem(this);
}

void VendingMachine :: dispenseitem(){
    currentstate = currentstate->dispenseitem(this);
}

void VendingMachine :: refill(int qty){
    currentstate = currentstate->refill(this, qty );
}

void VendingMachine :: returncoin(){
    currentstate = currentstate->returncoin(this);
}
void VendingMachine :: PrintStatus(){
    cout<<"Remaining item :"<<itemscount<<endl; 
   cout<<"inserted coin :" << insertedcoin<<endl;
   cout<<"current state : " <<currentstate->getStateName()<<endl;



}

int main(){
    VendingMachine * machine = new VendingMachine(2 , 20);
    machine->PrintStatus();

    //before inserting selecting
   machine->selectcoin();
   machine->PrintStatus();

   //after insert coin ,selecting
   machine->insertCoin(30);
   machine->PrintStatus();

   machine->selectcoin();
   machine->PrintStatus();

   //before dispening
   machine->returncoin();
   machine->PrintStatus();

   // dispensing
   machine->dispenseitem();
   machine->PrintStatus();
   //return coin after dispensing
   machine->returncoin();
   machine->PrintStatus();


}