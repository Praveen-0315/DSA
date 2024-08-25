#include<iostream>
using namespace std;

class BankAccount 
{
    string name,type;
    float balance_amount;
    long AccountNum;

    public:
    void initialize();
    long get_Account();
    void deposit(float);
    void withdraw(float);
    void display();
};

void BankAccount :: initialize()
{
    cout << "\nEnter name:";
    cin >> name;
    cout << "Account type: Enter 1 for Saving and 2 for Current :";
    int choice;
    cin >> choice;
    if(choice == 1)
    {
        type = "Saving";
    }
    else if(choice == 2)
    {
        type = "Current";
    }
    cout << "Enter account number:";
    cin >> AccountNum;
    cout << "Enter balance amount:";
    cin >> balance_amount;
}

long BankAccount :: get_Account()
{
    return AccountNum;
}

void BankAccount :: deposit(float amount)
{
    balance_amount += amount;
}

void BankAccount :: withdraw(float amount)
{
    if(amount > balance_amount)
    {
        cout << "Not Enough Balance"<<endl;
    }
    else
    {
        balance_amount -= amount; 
    }
}

void BankAccount :: display()
{
    cout << "Name:"<< name << endl << "Balance Amount: " << balance_amount<<endl<< "Type of account: "<< type ;
    cout<< endl<<endl;   
}

int main()
{
    BankAccount customer[2];
    for(int i = 0; i < 2; i++){
        cout << "Enter details of customer " << i+1 << ":";
        customer[i].initialize();
    }
    char ch;
    do 
    {
        cout << "1.Deposit \n2.Withdrawl \n3.Display Details \n4.Exit \nEnter Choice:";
        cin >> ch;
        int customer_no = -1;
        if(ch == '1' || ch == '2' || ch == '3')
        {
            long account;
            cout << "Enter Account Number:";
            cin >> account;
            for(int i = 0; i < 10; i++)
            {
                if(customer[i].get_Account() == account)
                {
                    customer_no = i;
                    break;
                }
            }
            if(customer_no == -1)
            {
                cout << "Enter Correct Account Number!" <<endl;
            }
        }
        if(customer_no != -1)
        {
            if(ch == '1')
            {
                cout << "Enter amount to be deposited:";
                int amount;
                cin >> amount;
                customer[customer_no].deposit(amount);
            }
            else if(ch == '2')
            {
                cout << "Enter amount to be withdrawed:";
                int amount;
                cin >> amount;
                customer[customer_no].withdraw(amount);
            }
            else if(ch == '3')
            {
                customer[customer_no].display();
            }
        }
        if(ch == '4')
        {
            cout << "Thank You";
            break;
        }
        else if(ch < '1' || ch > '4')
        {
            cout << "Incorrect Choice:";
        }
    }while(ch != '4');
}

