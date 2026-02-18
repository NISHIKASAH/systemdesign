#include <bits/stdc++.h>
using namespace std;

class AtmDispenser
{
protected:
    AtmDispenser *handlernext;
    AtmDispenser()
    {
        handlernext = nullptr;
    }

public:
    virtual void dispense(double amount) = 0;
    void setHandler(AtmDispenser *handler)
    {
        handlernext = handler;
    }
};

class ThousandNotesDispense : public AtmDispenser
{
    int thousandnotes;

public:
    ThousandNotesDispense(int notes)
    {
        thousandnotes = notes;
    }
    void dispense(double amount) override
    {
        int Totalnoofnotes = amount / 1000;
        int remainingAmount = amount;
        if (Totalnoofnotes > thousandnotes)
        {
            Totalnoofnotes = thousandnotes;
            thousandnotes = 0;
        }
        else
        {
            thousandnotes = thousandnotes - Totalnoofnotes;
        }
        if (Totalnoofnotes > 0)
        {
            cout << "Despencing " << Totalnoofnotes << "  x 1000" << endl;
            remainingAmount = remainingAmount - (Totalnoofnotes * 1000);
        }
        if (remainingAmount > 0)
        {
            if (handlernext != nullptr)
                handlernext->dispense(remainingAmount);
            else
            {
                cout << "Insufficient balance for remaming amount " << endl;
            }
        }
    }
};

class HundredNotes : public AtmDispenser
{
private:
    int hunderednotes;

public:
    HundredNotes(int notes)
    {
        hunderednotes = notes;
    }
    void dispense(double amount) override
    {

        int Totalnoofnotes = amount / 100;
        int remainingAmount = amount;
        if (Totalnoofnotes > hunderednotes)
        {
            Totalnoofnotes = hunderednotes;
            hunderednotes = 0;
        }
        else
        {
            hunderednotes = hunderednotes - Totalnoofnotes;
        }
        if (Totalnoofnotes > 0)
        {
            cout << "Despencing " << Totalnoofnotes << "  x 100" << endl;
            remainingAmount = remainingAmount - (Totalnoofnotes * 100);
        }
        if (remainingAmount > 0)
        {
            if (handlernext != nullptr)
                handlernext->dispense(remainingAmount);

            else
            {
                cout << "Insufficient balance for remaming amount " << endl;
            }
        }
    }
};

class FiftyNotes : public AtmDispenser
{
private:
    int fiftynotes;

public:
    FiftyNotes(int notes)
    {
        fiftynotes = notes;
    }
    void dispense(double amount) override
    {

        int Totalnoofnotes = amount / 50;
        int remainingAmount = amount;
        if (Totalnoofnotes > fiftynotes)
        {
            Totalnoofnotes = fiftynotes;
            fiftynotes = 0;
        }
        else
        {
            fiftynotes = fiftynotes - Totalnoofnotes;
        }
        if (Totalnoofnotes > 0)
        {
            cout << "Despencing " << Totalnoofnotes << "  x 50" << endl;
            remainingAmount = remainingAmount - (Totalnoofnotes * 50);
        }
        if (remainingAmount > 0)
        {
            if (handlernext != nullptr)
                handlernext->dispense(remainingAmount);

            else
            {
                cout << "Insufficient balance for remaming amount " << endl;
            }
        }
    }
};
int main()
{
    AtmDispenser *thousand1 = new ThousandNotesDispense(5);
    AtmDispenser *hundered_1 = new HundredNotes(6);
    AtmDispenser *fifty_1 = new FiftyNotes(2);
    thousand1->setHandler(hundered_1);
    hundered_1->setHandler(fifty_1);
    fifty_1->setHandler(nullptr);
    thousand1->dispense(3550);
};