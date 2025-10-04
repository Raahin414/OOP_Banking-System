#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <stack>
#include <vector>
#include <cctype>
#include <iomanip>
#include <fstream>

using namespace std;

bool isNumber(const string& str) {
    if (str.empty()) return false;

    // Check if the first character is a digit or '+'/'-'
    if (!isdigit(str[0]) && str[0] != '+' && str[0] != '-') return false;

    bool dotFound = false;
    for (size_t i = 1; i < str.length(); ++i) {
        if (!isdigit(str[i])) {
            if (str[i] == '.') {
                if (dotFound) return false; // More than one dot
                dotFound = true;
            }
            else {
                return false; // Non-digit character found
            }
        }
    }
    return true;
}

bool hasNoNumbers(const std::string& str) {
    for (char c : str) {
        if (std::isdigit(c)) {
            return false;
        }
    }
    return true;
}

bool isString(const std::string& str) {
    bool hasAlpha = false;
    for (char c : str) {
        if (std::isalpha(c)) {
            hasAlpha = true;
        }
    }
    return hasAlpha;
}

bool isInteger(const std::string& str) {
    if (str.empty()) return false;
    for (char c : str) {
        if (!std::isdigit(c)) {
            return false;
        }
    }
    return true;
}

class Person {
protected:
    string ownerName;
    string phoneNo;
    string nic;
    string address;
    string inheritor;
    string inheritcnic;
public:

    Person() {
        try {
            while (true) {
                cout << "Enter full name of the new account owner" << endl;
                cin.ignore();
                getline(cin, ownerName);
                if (hasNoNumbers(ownerName)) break;
                cout << "The owner name is not correct.Please try again." << endl;
            }
            while (true) {
                cout << "Enter phone number (11 digits): " << endl;
                cin >> phoneNo;
                if (phoneNo.length() == 11 && isInteger(phoneNo)) break;
                cout << "Invalid phone number. Please enter 11 digits." << endl;
            }

            while (true) {
                cout << "Enter National Identity Card Number (13 digits): " << endl;
                cin >> nic;
                if (nic.length() == 13 && isInteger(nic)) break;
                cout << "Invalid NIC number. Please enter 13 digits." << endl;
            }

            cout << "Enter full address" << endl;
            cin.ignore();
            getline(cin, address);

            while (true) {
                cout << "Enter next of kin" << endl;
                cin.ignore();
                getline(cin, inheritor);
                if (hasNoNumbers(inheritor)) break;
                cout << "The name entered is not correct. Try again." << endl;
            }

            while (true) {
                cout << "Enter the NIC of next of kin (13 digits): " << endl;
                cin >> inheritcnic;
                if (inheritcnic.length() == 13 && isInteger(inheritcnic)) break;
                cout << "Invalid NIC number. Please enter 13 digits." << endl;
            }
        }
        catch (const exception& e) {
            cerr << "Error: " << e.what() << endl;
        }
    }

    void edit() {
        try {
            while (true) {
                cout << "Enter full name of the new account owner" << endl;
                cin.ignore();
                getline(cin, ownerName);
                if (hasNoNumbers(ownerName)) break;
                cout << "The owner name is not correct.Please try again." << endl;
            }
            while (true) {
                cout << "Enter phone number (11 digits): " << endl;
                cin >> phoneNo;
                if (phoneNo.length() == 11 && isInteger(phoneNo)) break;
                cout << "Invalid phone number. Please enter 11 digits." << endl;
            }

            while (true) {
                cout << "Enter National Identity Card Number (13 digits): " << endl;
                cin >> nic;
                if (nic.length() == 13 && isInteger(nic)) break;
                cout << "Invalid NIC number. Please enter 13 digits." << endl;
            }

            cout << "Enter full address" << endl;
            cin.ignore();
            getline(cin, address);

            while (true) {
                cout << "Enter next of kin" << endl;
                cin.ignore();
                getline(cin, inheritor);
                if (hasNoNumbers(inheritor)) break;
                cout << "The name entered is not correct. Try again." << endl;
            }

            while (true) {
                cout << "Enter the NIC of next of kin (13 digits): " << endl;
                cin >> inheritcnic;
                if (inheritcnic.length() == 13 && isInteger(inheritcnic)) break;
                cout << "Invalid NIC number. Please enter 13 digits." << endl;
            }
        }
        catch (const exception& e) {
            cerr << "Error: " << e.what() << endl;
        }
        cout << endl << "Iformation updated successfully!" << endl;
    }

    Person(string n, string p, string ni, string ad) {
        ownerName = n;
        phoneNo = p;
        nic = ni;
        address = ad;
    }

    string getOwnerName() const {
        return ownerName;
    }

    /*void serialize(const string& filename) {
        ofstream file(filename, ios::binary);
        if (!file.is_open()) {
            cerr << "Error: Failed to open file for writing." << endl;
            return;
        }
        file.write(reinterpret_cast<const char*>(this), sizeof(*this));
        file.close();
        cout << "Object serialized successfully." << endl;
    }

    static Person deserialize(const string& filename) {
        Person obj;
        ifstream file(filename, ios::binary);
        if (!file.is_open()) {
            cerr << "Error: Failed to open file for reading." << endl;
            return obj;
        }
        file.read(reinterpret_cast<char*>(&obj), sizeof(obj));
        file.close();
        cout << "Object deserialized successfully." << endl;
        return obj;
    }*/
};

bool countDigits(int number) {
    if (number == 0) return 1; // Special case for 0
    int count = 0;
    while (number != 0) {
        number /= 10;
        count++;
    }
    if (count == 4) return true;
    else return false;
}

class BankAccount : public Person {
protected:
    string accountNumber;
    int password;
    long double balance;
    long double loan;
    long double ploan;


public:
    BankAccount(const string& accNum, double l = 0) : Person() {
        int p;
        string in;
        double bal;
        while (true) {
            cout << "Enter a password of your choice (4 digits): ";
            cin >> in;
            if (isInteger(in)) {
                p = stoi(in);
                if (countDigits(p)) break;
            }
            cout << "The password must be of 4 numbers" << endl;

        }
        in = " ";
        while (true) {
            cout << "Enter initial balance: ";
            cin >> in;
            if (isNumber(in)) {
                bal = stod(in);
                if (bal > 0) break;
            }
            cout << "You cannot enter a negative balance or a alphanumeric value, try again" << endl;
        }
        accountNumber = accNum;
        balance = bal;
        password = p;
        loan = 0;
        ploan = 0;
    }


    virtual ~BankAccount() {}

    virtual void interest() {};

    virtual void deposit(double amount) {
        balance += amount;
    }

    virtual bool withdraw(double amount) = 0;

    virtual bool transfer(BankAccount* receiver, double amount) = 0;

    virtual void viewBalance() const {
        cout << "Account Owner: " << ownerName << endl;
        cout << "Account Number: " << accountNumber << endl;
        std::cout << fixed; std::cout << setprecision(6);
        cout << "Balance: $" << balance << endl;
        cout << "Loan : $ " << loan << endl;
    }

    double getBalance() const {
        return balance;
    }

    int getPassword() const {
        return password;
    }

    string getAccountNumber() const {
        return accountNumber;
    }

    double loanInfo() const {
        return loan;
    }

    void setLoan(double amount) {
        ploan += amount;
    }

    double getploan() {
        return ploan;
    }

    bool getLoan(double amount) {
        double in = balance - loan;
        if (amount <= in * 30 / 100) {
            balance = balance + amount;
            loan += amount;
            ploan = 0;
            return true;
        }
        else
        {
            ploan = 0;
            return false;
        }
    }

    bool returnloan() {
        if (loan == 0) {
            cout << "There is no loan on this account" << endl;
            return false;
        }
        if ((balance - (loan + loan * 20 / 100)) > 0) {
            balance = balance - (loan + loan * 20 / 100);
            loan = 0;
            cout << "Loan paid off successfully";
            return true;
        }
        else
            cout << "Sufficient funds not available" << endl;
        return false;
    }
};

vector<BankAccount*> accounts;

class SavingsAccount : public BankAccount {
private:
    double interestRate;

public:
    SavingsAccount(const string& accnum) : BankAccount(accnum, 0) {
        interestRate = 13.5;
    }

    bool withdraw(double amount) {
        if (balance >= amount) {
            balance -= amount;
            cout << "Amount withdrawn successfully" << endl;
            return true;
        }
        else {
            cout << "Insufficient Funds" << endl;
            return false;
        }
    }

    bool transfer(BankAccount* receiver, double amount) {
        if (balance >= amount) {
            receiver->deposit(amount);
            balance -= amount;
            cout << "Amount transferred successfully" << endl;
            return true;
        }
        else {
            cout << "Insufficient Funds" << endl;
            return false;
        }
    }
    double getint() {
        return balance * interestRate / 100;
    }

    void interest() {
        balance += (balance * interestRate / 100);
    }
};

class checkingAccount : public BankAccount {
public:
    checkingAccount(const string& accNum) : BankAccount(accNum, 0) {}

    bool withdraw(double amount) {
        if (balance >= amount) {
            balance -= amount;
            cout << "Amount withdrawn successfully" << endl;
            return true;
        }
        else {
            cout << "Insufficient Funds" << endl;
            return false;
        }
    }

    bool transfer(BankAccount* receiver, double amount) {
        if (balance >= amount) {
            receiver->deposit(amount);
            balance -= amount;
            cout << "Amount transferred successfully" << endl;
            return true;
        }
        else {
            cout << "Insufficient Funds" << endl;
            return false;
        }
    }


};

class BusinessAccount : public BankAccount {
public:
    BusinessAccount(const string& accNum) : BankAccount(accNum, 0) {}

    bool withdraw(double amount) {
        if (balance >= amount) {
            balance -= amount;
            cout << "Amount withdrawn successfully" << endl;
            return true;
        }
        else {
            cout << "Insufficient Funds" << endl;
            return false;
        }
    }

    bool transfer(BankAccount* receiver, double amount) {
        if (balance >= amount) {
            receiver->deposit(amount);
            balance -= amount;
            cout << "Amount transferred successfully" << endl;
            return true;
        }
        else {
            cout << "Insufficient Funds" << endl;
            return false;
        }
    }


};

class IndexFinder {
public:
    int operator()(const vector<BankAccount*>& accounts, const string& accountNumber) {
        for (int i = 0; i < accounts.size(); ++i) {
            if (accounts[i]->getAccountNumber() == accountNumber) {
                return i;
            }
        }
        return -1;
    }
};
IndexFinder findAccountIndex;

class Transaction {
public:
    map<string, vector<pair<double, string>>> tran;

    void operator()(string anum, double amount, string m) {
        tran[anum].emplace_back(amount, m);
    }

    void statement(string anum) {
        int n = 1;
        cout << "Statement of Accounts for Account Number " << anum << endl;
        for (const auto& entry : tran[anum]) {
            cout << n << " " << "$" << entry.first << "   " << entry.second << endl;
            ++n;
        }
    }
};
Transaction t;

class Admin : public Person {
    string id;
    int password;
public:
    Admin(string n, string p, string ni, string ad, string i, int ps) : Person(n, p, ni, ad) {
        id = i;
        password = ps;
    }

    void AccInfo(vector<BankAccount*> accounts) {
        for (auto& account : accounts) {
            cout << "Account Owner: " << account->getOwnerName() << endl;
            cout << "Account Number: " << account->getAccountNumber() << endl;
            cout << "Balance: $" << account->getBalance() << endl;
            cout << "Loan on the account: $" << account->loanInfo() << endl;
        }
    }
    string getad() {
        return id;
    }
    int getp() {
        return password;
    }

    void loanReq(stack <string>& req) {
        while (!req.empty()) {

            int index = findAccountIndex(accounts, req.top());
            if (accounts[index]->getLoan(accounts[index]->getploan()) == true) {
                t(accounts[index]->getAccountNumber(), accounts[index]->loanInfo(), "Loan recieved ");
                cout << "Loan request from Account Number: " << accounts[index]->getAccountNumber() << " APPROVED." << endl;
            }
            else {
                cout << "Loan request from Account Number : " << accounts[index]->getAccountNumber() << " REJECTED ." << endl;
            }
            req.pop();
        }
        cout << "All loan applications handled" << endl;
    }
    void release(vector<BankAccount*> accounts) {
        string type, n;
        for (auto& account : accounts) {
            n = account->getAccountNumber();
            for (int i = 0; i < 2; i++) {
                type += n[i];
            }
            if (type == "AS") {
                t(n, account->getBalance() * 13.5 / 100, "Interest recieved");
                account->interest();
            }
            cout << "Annual Interest released sucessfully" << endl;
        }
    }
    void Change(vector<BankAccount*> accounts) {
        string accNum;
        cout << "Enter account number to edit info or transfer" << endl;
        cin >> accNum;
        int index = findAccountIndex(accounts, accNum);
        if (index != -1) {
            accounts[index]->edit();
        }
    }
};




int main() {
    stack<string> loan;
    string adminAccountNumber = "ADMIN1";
    string adminOwnerName = "ADuser1";
    int adminPassword = 1234;
    Admin admin("Raahin", "03322489414", "4230151556011", "Main_Branch", adminAccountNumber, adminPassword);
    int ans = 0;
    int option{ 0 };
    cout << "Welcome to Custom Banking System" << endl << endl;
    string accNum;
    string in;
    int password;
    // Admin options logic
    while (option != -10 || ans != -10) {
        cout << endl;
        while (true) {
            cout << "Enter Account Number: ";
            getline(cin, accNum);
            while (accNum.size() < 1){
                cin.clear();
                cin.sync();
                cout << "wrong input"<<endl;
                cout << "Enter Account Number: ";
                getline(cin, accNum);
                continue;
            }
            cout << "Enter Password: ";
            cin >> in;
            if (isInteger(in)) {
                password = stoi(in);
                in = " ";
                break;
            }
            cout << "Account not found try again" << endl;
        }
        if (admin.getad() == accNum && admin.getp() == password) {
            option = 0;
            while (option != -1) {
                cout << endl;
                while (true) {
                    cout << "1. Create account" << endl;
                    cout << "2. View All Accounts" << endl;
                    cout << "3. Handle Loan application" << endl;
                    cout << "4. Release Anual Interest" << endl;
                    cout << "5. Change account information" << endl;
                    cout << "Press -1 to return to login" << endl;
                    cout << "Enter option: " << endl;
                    cin >> in;
                    if (in == "-1") {
                        option = -1;
                        break;
                    }

                    if (isInteger(in)) {
                        option = stoi(in);
                        in = " ";
                        break;
                    }
                    cout << "Enter a valid option" << endl;
                }
                switch (option) {
                case 1: {
                    int atype;
                    while (true) {
                        cout << "Press 1 to create a Checking Account, Press 2 to create a Savings Account, Press 3 to create a Business Account\n";
                        cin >> in;
                        if (isInteger(in)) {
                            atype = stoi(in);
                            in = " ";
                            break;
                        }
                        cout << "Input a valid option" << endl;
                    }
                    string accNum;
                    switch (atype) {
                    case 1: {
                        accNum = "AC" + to_string(accounts.size() + 1); // Generate account number
                        accounts.push_back(new checkingAccount(accNum));
                        int index = findAccountIndex(accounts, accNum);
                        t(accNum, accounts[index]->getBalance(), "Balance at opening");
                        cout << "Checking Account successfully created with account number " << accNum << endl;
                        break;
                    }
                    case 2: {
                        accNum = "AS" + to_string(accounts.size() + 1); // Generate account number
                        accounts.push_back(new SavingsAccount(accNum));
                        int index = findAccountIndex(accounts, accNum);
                        t(accNum, accounts[index]->getBalance(), "Balance at opening");
                        cout << "Savings Account successfully created with account number " << accNum << endl;
                        break;
                    }
                    case 3: {
                        accNum = "BA" + to_string(accounts.size() + 1); // Generate account number
                        accounts.push_back(new BusinessAccount(accNum));
                        int index = findAccountIndex(accounts, accNum);
                        t(accNum, accounts[index]->getBalance(), "Balance at opening");
                        cout << "Business Account successfully created with account number " << accNum << endl;
                        cout << endl;
                        break;
                    }
                    default: {
                        cout << "Invalid input, try again" << endl;
                    }

                    }
                    break;
                }
                case 2: {
                    admin.AccInfo(accounts);
                    break;
                }
                case 3: {
                    admin.loanReq(loan);
                    break;
                }
                case 4: {
                    admin.release(accounts);
                    break;
                }
                case 5: {
                    admin.Change(accounts);
                    break;
                }
                case -1: {
                    break;
                }
                default: {
                    cout << "Invalid input" << endl;
                }
                }
            }
        }
        else {
            int index = findAccountIndex(accounts, accNum);
            if (index != -1) {
                if (accounts[index]->getPassword() == password) {
                    ans = 0;
                    while (ans != -1) {
                        cout << endl;
                        while (true) {
                            cout << "Welcome to HBL Banking System" << endl;

                            cout << "Press 1 to view balance" << endl;
                            cout << "Press 2 to deposit in account" << endl;
                            cout << "Press 3 to withdraw from account" << endl;
                            cout << "Press 4 to transfer funds" << endl;
                            cout << "Press 5 to open Loan Services" << endl;
                            cout << "Press 6 to view account statement" << endl;
                            cout << "Press -1 to return to login" << endl;
                            cout << endl;
                            cin >> in;
                            if (in == "-1") {
                                ans = -1;
                                break;
                            }
                            if (in == "-10") {
                                ans = -10;
                                break;
                            }

                            if (isInteger(in)) {
                                ans = stoi(in);
                                in = " ";
                                break;
                            }
                            cout << "Input a valid option" << endl;
                        }
                        switch (ans) {
                        case 1: {
                            accounts[index]->viewBalance();
                            cout << endl;
                            break;
                        }
                        case 2: {
                            double amount;
                            while (true) {
                                cout << "Enter deposit amount: ";
                                cin >> in;
                                if (isNumber(in)) {
                                    amount = stod(in);
                                    in = " ";
                                    break;
                                }
                                cout << "Amount is not in correct format, try again" << endl;
                            }
                            accounts[index]->deposit(amount);
                            t(accNum, amount, "Deposited in Account");
                            cout << "Deposit Successful" << endl;
                            break;
                        }
                        case 3: {
                            bool check;
                            double amount;
                            while (true) {
                                cout << "Enter withdrawal amount: ";
                                cin >> in;
                                if (isNumber(in)) {
                                    amount = stod(in);
                                    in = " ";
                                    break;
                                }
                                cout << "Amount is not in correct format, try again";
                            }
                            check = accounts[index]->withdraw(amount);
                            if (check)
                                t(accNum, amount, "Withdrawn from Account");
                            break;
                        }
                        case 4: {
                            string receiverAccNum;
                            double amount;
                            cout << "Enter Receiver Account Number: ";
                            cin >> receiverAccNum;
                            int receiverIndex = findAccountIndex(accounts, receiverAccNum);
                            if (receiverIndex != -1) {
                                bool check;
                                while (true) {
                                    cout << "Enter transfer amount: ";
                                    cin >> in;
                                    if (isNumber(in)) {
                                        amount = stod(in);
                                        in = " ";
                                        break;
                                    }
                                    cout << "Amount is not in correct format, try again" << endl;
                                }
                                check = accounts[index]->transfer(accounts[receiverIndex], amount);
                                if (check) {
                                    t(accNum, amount, "Transfered to " + receiverAccNum);
                                    t(receiverAccNum, amount, "Recieved by" + accNum);
                                }
                            }
                            else {
                                cout << "Receiver Account not found" << endl;
                            }
                            cout << endl;
                            break;
                        }
                        case 5: {

                            cout << endl;
                            int a;
                            cout << "Press 1 to return loan and Press 2 to apply for loan" << endl;
                            cin >> a;
                            if (a == 2) {

                                cout << "The current loan interest is 20% deducted at the time of repayment." << endl;
                                cout << "Enter the loan amount required: " << endl;
                                double loanAmount;
                                while (true) {
                                    cin >> in;
                                    if (isNumber(in)) {
                                        loanAmount = stod(in);
                                        in = " ";
                                        break;
                                    }
                                    cout << "Amount not in correct format,try again" << endl;
                                }
                                accounts[index]->setLoan(loanAmount);
                                string type;
                                string n = accounts[index]->getAccountNumber();
                                for (int i = 0; i < 2; i++) {
                                    type += n[i];
                                }
                                if (type == "BA") {
                                    cout << endl << "You are a Business Account holder and are eligible for a instant overdraft of upto 15% of your account balance" << endl;
                                    if (accounts[index]->getLoan(accounts[index]->getploan())) {
                                        t(accounts[index]->getAccountNumber(), loanAmount, "Overdraft recieved ");
                                        cout << "Your application has been processed and the instant overdraft is transfered" << endl;
                                        break;
                                    }
                                    else {
                                        cout << "The request has been declined try again!" << endl;
                                        break;
                                    }
                                }
                                else {
                                    cout << "Your loan application has been sent to precess, kindly check your account balance in some time." << endl;
                                    loan.push(accounts[index]->getAccountNumber());
                                    break;
                                }
                            }

                            else if (a == 1) {
                                bool c;
                                double l = accounts[index]->loanInfo();
                                c = accounts[index]->returnloan();
                                if (c)
                                    t(accounts[index]->getAccountNumber(), l, "Loan paid off");

                            }
                            else {
                                cout << "Incorrect option try again" << endl;
                                cout << endl;
                                break;
                            }
                            cout << endl;
                            break;
                        }

                        case 6: {
                            cout << "Statement is of account number " << accNum << endl;
                            t.statement(accNum);
                            break;


                        }
                        case -1: {
                            ans = -1;
                            break;
                        }
                        default: {
                            cout << "Invalid Input" << endl;
                            break;
                        }
                        }
                    }
                }
                else
                    cout << "Password is not correct" << endl;
            }
            else
                cout << "Account not found try again" << endl;
        }
    }

    for (auto* account : accounts)
        delete account;
    return 0;
}











