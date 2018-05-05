#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Checker
{
private:
    int S=0,n=-1;
    string status;
public:
    Checker(int Sal,int age,string job,int PPM)
    {
        int salary=Sal,Age=age,installment=PPM;
        string Job=job;
        if(salary>installment)
        {
            S++;
            cout<<"You are eligible Salary wise"<<endl;
        }
        else
        {
            cout<<"Your salary is not upto the loan requirement"<<endl;
        }

        if(Job=="labour")
        {
            cout<<"your job title is not qualified for a loan"<<endl;
        }
        else
        {
            S++;
            cout<<"Your Job title is eligible  for a loan"<<endl;
        }
        if(Age<20)
        {
            cout<<"According to our policy you are too young to be granted a loan"<<endl;
        }
        else
        {
            S++;
            cout<<"You are Age wise eligible"<<endl;
        }
        if(S!=3)
        {
            n=0;
            cout<<"Kindly check above for you dont pass one or more of our eligibility criteria";

        }
        else
        {
            cout<<"You are Completely Eligible for Loan"<<endl;
            n=1;

        }
    }
    int getstatus()
    {
    if(n==0)
    {
        return 0;
    }
    else
        return 1;
    }
};
int main()
{
    string Name,Job,Address;
    int Age,ID,Salary,amount;
    double PPM;
    uint64_t CNIC;
    ifstream infile;
    infile.open("Data.txt");
    infile>>Name>>Age>>ID>>CNIC>>Job>>Salary>>Address>>amount>>PPM;
    Checker c(Salary,Age,Job,PPM);
    infile.close();
    ofstream outfile;
    outfile.open("Data.txt",std::ios_base::app);
    outfile <<endl<< c.getstatus();
    outfile.close();

}
