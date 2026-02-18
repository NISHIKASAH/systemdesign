#include <bits/stdc++.h>
using namespace std;

class ModelTrainer
{
protected:
    void loadData(string path)
    {
        cout << "Loading data from given path " << path << endl;
    }
    void preprocessor()
    {
        cout << "Splitting into train/test and normalize " << endl;
    }
    virtual void trainModel() = 0;
    virtual void evaluateModel() = 0;
    virtual void saveModel() = 0;
    public :
    void TrainingMethod(const string &path)
    {
        loadData(path);
        preprocessor();
         trainModel();
        evaluateModel();
        saveModel();
    }
};

class NeuralModelTrainer : public ModelTrainer
{
public:
    void trainModel() override {
        cout<<"Neural model training "<<endl;
    }
    void evaluateModel()  override {
        cout<<"Evaluating neural model trainer"<<endl;
    }
    void saveModel()override {
        cout<<"Saving neural model "<<endl;
    }
};

class ClassicModelTrainer : public ModelTrainer
{
public:
    void trainModel() override {
        cout<<"Classic model training "<<endl;
    }
    void evaluateModel()  override {
        cout<<"Evaluating Classic model trainer"<<endl;
    }
    void saveModel()override {
        cout<<"Saving Classic model  "<<endl;
    }
};

int main(){
    ModelTrainer * model = new ClassicModelTrainer();
    model->TrainingMethod("/data/sample.txt");

    cout<<"----------------------------"<<endl;
    ModelTrainer * model2 = new NeuralModelTrainer();
    model2->TrainingMethod("/data/neural.txt");
}