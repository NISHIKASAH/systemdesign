#include <iostream>
using namespace std;

class Desktop
{
public:
    string motherboard;
    string processor;
    string storage;
    string brand;

    void display()
    {
        
        cout << "MotherBoard : " << motherboard;
        cout << "Processor : " << processor;
        cout << "Storage : " << storage;
        cout << "Brand : " << brand;
    }
};

class DesktopBuilder
{
protected:
    Desktop desktop;

public:
    virtual void buildMotherboard() = 0;
    virtual void buildProcessor() = 0;
    virtual void buildstorage() = 0;
    virtual void buildbrand() = 0;
    Desktop getDesktop()
    {
        return desktop;
    }
};

class DellDesktopBuilder : public DesktopBuilder
{

    void buildMotherboard()
    {
        desktop.motherboard = "dell motherboard";
    }
    void buildProcessor()
    {
        desktop.processor = "dell processor";
    }
    void buildstorage()
    {
        desktop.storage = "dell storage";
    }
    void buildbrand()
    {
        desktop.brand = "dell brand";
    }
};

class HpDesktopBuilder : public DesktopBuilder
{

    void buildMotherboard()
    {
        desktop.motherboard = "hp motherboard";
    }
    void buildProcessor()
    {
        desktop.processor = "hp processor";
    }
    void buildstorage()
    {
        desktop.storage = "hp storage";
    }
    void buildbrand()
    {
        desktop.brand = "hp brand";
    }
};

class BuilderDirectory
{
private:
    DesktopBuilder *builder;

public:
    BuilderDirectory(DesktopBuilder *buildertype)
    {
        builder = buildertype;
    }

    Desktop buildDesktop()
    {
        builder->buildbrand();
        builder->buildMotherboard();
        builder->buildProcessor();
        builder->buildstorage();

        return builder->getDesktop();
    }
};

int main()
{

    DesktopBuilder *builder = new DellDesktopBuilder();
    BuilderDirectory *directory = new BuilderDirectory(builder);
    Desktop desktop = directory->buildDesktop();
    desktop.display();
}