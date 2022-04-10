#include <iostream>
#include <fstream>
#include <iomanip> //use for setw,endl function
#include <conio.h>
using namespace std;

//----------------------------------------------------------------------------------------------
//  - EMPLOYEE CLASS -

class Employee
{
public:
	int Employee_No = 0;
	char Employee_Name[50];
	char Employee_Post[30];
	int Employee_Experience = 0;
	float basicSalary = 0;
	float Total_Salary = 0;
	void addEmployee();
	void report();
	void show_Employee();
	virtual void getSalary_Details()
	{

	}
	virtual void salaryCalculation()
	{

	}
};

// OFFICER CLASS 

class officer : public Employee
{
public:
	float allowanceSalary = 0;
	float incentiveSalary = 0;
	void getSalary_Details();
	void salaryCalculation();
};

void officer::getSalary_Details()
{
	cout << "\n\tENTER OFFICER SALARY DETAILS" << endl;
	cout << "\n Enter Basic Salary : ";
	cin >> basicSalary;
	cout << "\n Enter Allowance : ";
	cin >> allowanceSalary;
	cout << "\n Enter Incentive : ";
	cin >> incentiveSalary;
}

void officer::salaryCalculation()
{
	Total_Salary = basicSalary + allowanceSalary + incentiveSalary;
	cout << "\n\tOFFICER SALARY" << endl;
	cout << "\n Basic      = " << basicSalary;
	cout << "\n Allowance  = " << allowanceSalary;
	cout << "\n Incentive  = " << incentiveSalary;
	cout << "\n             ______________________";
	cout << "\nTOTAL SALARY= " << Total_Salary;
	cout << "\n             ______________________";
	cout << "\n             ______________________";

}

// MANAGER CLASS 

class Manager : public officer
{
public:
	float fuelAllowance = 0;
	float bonusSalary = 0;
	void getSalary_Details();
	void salaryCalculation();

};

void Manager::getSalary_Details()
{
	cout << "\n\tENTER MANAGER SALARY DETAILS" << endl;
	cout << "\n Enter Basic Salary : ";
	cin >> basicSalary;
	cout << "\n Enter Allowance : ";
	cin >> allowanceSalary;
	cout << "\n Enter Incentive : ";
	cin >> incentiveSalary;
	cout << "\n Enter Fuel Allowance :";
	cin >> fuelAllowance;
	cout << "\n Enter Bonus Salary : ";
	cin >> bonusSalary;
}

void Manager::salaryCalculation()
{
	Total_Salary = basicSalary + allowanceSalary + incentiveSalary + fuelAllowance + bonusSalary;
	cout << "\n\tMANAGER SALARY" << endl;
	cout << "\n Basic        = " << basicSalary;
	cout << "\n Allowance    = " << allowanceSalary;
	cout << "\n Incentive    = " << incentiveSalary;
	cout << "\n Fuel Allowance=" << fuelAllowance;
	cout << "\n Bonus Salary  =" << bonusSalary;
	cout << "\n               ______________________";
	cout << "\nTOTAL SALARY  = " << Total_Salary;
	cout << "\n               ______________________";
	cout << "\n               ______________________";

}

// OTHER EMPLOYEE CLASS

class Other_Employees : public Employee
{
public:
	int OThours = 0;
	float OThourSalary = 0;

	void getSalary_Details();
	void salaryCalculation();
};

void Other_Employees::getSalary_Details()
{
	cout << "\n\tENTER OTHER EMPLOYEES SALARY DETAILS" << endl;
	cout << "\n Enter Basic Salary : ";
	cin >> basicSalary;
	cout << "\n Enter salary per OT Hour : ";
	cin >> OThourSalary;
}

void Other_Employees::salaryCalculation()
{
	cout << "\nEnter OT Hours : ";
	cin >> OThours;
	Total_Salary = basicSalary + (OThours * OThourSalary);
	cout << "\n\tOFFICER SALARY" << endl;
	cout << "\n Basic      = " << basicSalary;
	cout << "\n OT Salary  =" << OThours * OThourSalary;
	cout << "\n             ______________________";
	cout << "\nTOTAL SALARY= " << Total_Salary;
	cout << "\n             ______________________";
	cout << "\n             ______________________";
}
//---------------------------------------------------------

void Employee::addEmployee()
{
	cout << "\nEnter Employee Number : ";
	cin >> Employee_No;
	cout << "\nEnter Employee Name : ";
	cin.ignore();
	cin.getline(Employee_Name, 50);
	cout << "\nEnter No of Experience Years : ";
	cin >> Employee_Experience;
	cout << "\nEnter Employee Post : ";
	cin.ignore();
	cin.getline(Employee_Post, 30);
}

void Employee::report()
{
	cout << Employee_No << setw(10) << " " << Employee_Name << setw(10) << " " << Employee_Post << setw(6) << " " << Employee_Experience << endl;
}

void Employee::show_Employee()
{
	cout << "\nEmployee Name : " << Employee_Name;
	cout << "\nEmployee Post : " << Employee_Post;
	cout << "\nEmployee Experience : " << Employee_Experience;
}

//---------------------------
void addEmployee_record();
void show_AllEmployee();
void search_employee(int n);
//---------------------------

void choise_Employee()
{
	Employee employee;
	Manager manager;
	officer Officer;
	Other_Employees Oemployee;
	fstream fp,fp1;
	char menu2choice, menu3choice;
	int menu4choice, menu5choice;
	cout << "[1].Add Employee\n[2].Salary Calculation\n[3].All Employee List\n[4].Search Employee\n[5].Exit";
	cin >> menu2choice;
	switch (menu2choice)
	{
	case '1':
		addEmployee_record();
		break;

	case '2':
		cout << "\n[1].Add Salary Values\n[2].Employee Total Salary \n[3].Exit";
		cin >> menu3choice;

		switch (menu3choice)
		{
		case '1':
			cout << "\nChoose Employee Category : \n[1].Manager\n[2].Officer\n[3].Other employee\n";
			cin >> menu4choice;
			if (menu4choice == 1)
			{
				manager.getSalary_Details();
				fp.open("manager.dat", ios::out | ios::binary);
				fp.write((char*)&manager, sizeof(Manager));
				fp.close();
			}
			else if (menu4choice == 2)
			{
				Officer.getSalary_Details();
				fp.open("officer.dat", ios::out | ios::binary);
				fp.write((char*)&Officer, sizeof(officer));
				fp.close();
			}
			else if (menu4choice == 3)
			{
				Oemployee.getSalary_Details();
				fp.open("other.dat", ios::out | ios::binary);
				fp.write((char*)&Oemployee, sizeof(Other_Employees));
				fp.close();
			}
			else
			{
				cout << "\nInvalid Input...";
				break;
			}
			break;
		case'2':
			cout << "\nChoose Employee Category : \n[1].Manager\n[2].Officer\n[3].Other employee\n";
			cin >> menu5choice;
			if (menu5choice == 1)
			{
				fp1.open("manager.dat", ios::in | ios::binary);
				fp1.read((char*)&manager, sizeof(Manager));
				manager.salaryCalculation();
				fp1.close();
			}
			else if (menu5choice == 2)
			{
				fp1.open("officer.dat", ios::in | ios::binary);
				fp1.read((char*)&Officer, sizeof(officer));
				Officer.salaryCalculation();
				fp1.close();
			}
			else if (menu5choice == 3)
			{
				fp1.open("other.dat", ios::in | ios::binary);
				fp1.read((char*)&Oemployee, sizeof(Other_Employees));
				Oemployee.salaryCalculation();
				fp1.close();
			}
			else
			{
				cout << "\nInvalid Input...";
				break;
			}
			break;
		case '3':
			break;

		default:
			cout << "\nInvalid Input.......";
			break;
		}
		break;
	case'3':
		show_AllEmployee();
		break;

	case '4':
		int num;
		cout << "\n\n\tEnter the account no. : "; cin >> num;
		search_employee(num);
		break;

	case '5':
		break;

	default:
		cout << "\nInvalid Input.......";
		break;
	}
}


//---- CUSTOMER Class ----

class Customer
{
public:
	int Acc_No;
	int cus_ID;
	char cus_Name[50];
	float Acc_balance;
	void create_Acc();
	void show_Account();
	void Acc_modify();
	void Deposit(int x);
	void Withdraw(int x);
	void Cus_Report();
};

void Customer::create_Acc()
{
	cout << "Enter Account Number : ";
	cin >> Acc_No;
	cout << "\nEnter Account Holder Name : ";
	cin.ignore();
	cin.getline(cus_Name, 50);
	cout << "\nEnter Account Holder NIC No :";
	cin >> cus_ID;
	cout << "\nEnter Account Opening Balance :";
	cin >> Acc_balance;
}

void Customer::show_Account()
{
	cout << "\nAccount number : " << Acc_No;
	cout << "\nAccount Holder's name : " << cus_Name;
	cout << "\nAccount Holder NIC : " << cus_ID;
	cout << "\nBalance amount : " << Acc_balance;
}

void Customer::Deposit(int x)
{
	Acc_balance += x;
}

void Customer::Withdraw(int x)
{
	Acc_balance -= x;
}

void Customer::Acc_modify()
{
	cout << "\nAccount number : " << Acc_No;
	cout << "\nModify account Holder's name : ";
	cin.ignore();
	cin.getline(cus_Name, 50);
	cout << "\nModify account Holder's NIC :  ";
	cin >> cus_ID;
	cout << "\nModify balance amount : ";
	cin >> Acc_balance;
}

void Customer::Cus_Report()
{
	cout << Acc_No << setw(15) << cus_Name << setw(16) << cus_ID << setw(15) << Acc_balance << endl;
}

//-------------------------------------------
void addCustomer_record();
void search_acc(int n);
void modify_Acc(int n);
void file_DepositeWithdraw(int n, int option);
void show_AllCustomer();
void delete_Acc(int n);
//-------------------------------------------


void transactions()
{
	int menu3choice, num;
	cout << "\nChoose your transaction type : \n[1].Deposit Amount \n[2].Withdraw Amount\n[3].Exit\n";
	cin >> menu3choice;
	cout << "\n\n\tEnter the account no. : "; cin >> num;
	file_DepositeWithdraw(num, menu3choice);
}

void choice_Customer()
{
	int num;
	char menu2choice;
	cout << "\n[1].Open Account\n[2].Transactions\n[3].Account Settings\n[4].Account Information\n[5].All Account Holder List\n[6].Exit\n";
	cin >> menu2choice;
	switch (menu2choice)
	{
	case '1':
		addCustomer_record();
		break;

	case '2':
		transactions();
		break;

	case '3':
		int n;
		cout << "\nChoose your setting :  \n\t[1].Modify An Account \n\t[2].Delete Account";
		cin >> n;
		cout << "\n\n\tEnter the account no. : "; cin >> num;
		if (n == 1)
		{
			modify_Acc(num);
		}
		else if (n == 2)
		{
			delete_Acc(num);
		}
		else
		{
			break;
		}
		break;

	case '4':
		cout << "\n\n\tEnter the account no. : "; cin >> num;
		search_acc(num);
		break;

	case '5':
		show_AllCustomer();
		break;

	case '6':
		break;

	default:
		cout << "\nImvalid Input.........";
		break;
	}
}



int main()
{
	char menu1choise, choiceYN = 'Y';
	cout << "\n\n\t    =*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=\n\t    |#>\t\t\t\t\t\t\t\t    <#|\n";
	cout << "\t      |#>      >>>>>>>>>>>>>__WELCOME TO\t\t\t  <#|\n\t\t|#>\t\t\t\t\t\t\t<#|\n\t      |#>\t\t\t BANKING MANAGEMENT SYSTEM__<<<<< <#|\n\t    |#>\t\t\t\t\t\t\t\t    <#|\n";
	cout << "\t    =*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=\n\n\n";

	do
	{
		cout << "\n\nChoose Category :";
		cout << "\n\t[1].Employee\n\t[2].Customer\n\t[3].Exit";
		cin >> menu1choise;
		switch (menu1choise)
		{
		case '1':
			choise_Employee();
			break;

		case '2':
			choice_Customer();
			break;

		case '3':
			cout << "\n\n^^^^^^^^^^^^=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=^^^^^^^^^^^^\n";
			cout << "\t                   >>>>>>>>>>>>>__THANK YOU__<<<<<<<<<<<<<\n";
			cout << "\t    =*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=\n\n\n";
			cout << " __________________________________________________________________________________________\n ";
			cout << "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n ";
			cout << "******************************************************************************************\n ";

			return 0;

		default:
			cout << "\n Invalid Input.......";
			cout << "\n\n^^^^^^^^^^^^=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=^^^^^^^^^^^^\n";
			cout << "\t                   >>>>>>>>>>>>>__THANK YOU__<<<<<<<<<<<<<\n";
			cout << "\t    =*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=\n\n\n";
			cout << " __________________________________________________________________________________________\n ";
			cout << "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n ";
			cout << "******************************************************************************************\n ";

			return 0;
		}

		cout << "\n Do you want to do anything else ? ";
		cin >> choiceYN;

	} while (choiceYN == 'Y');

	cout << "\n\n^^^^^^^^^^^^=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=^^^^^^^^^^^^\n";
	cout << "\t                   >>>>>>>>>>>>>__THANK YOU__<<<<<<<<<<<<<\n";
	cout << "\t    =*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=\n\n\n";
	cout << " __________________________________________________________________________________________\n ";
	cout << "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n ";
	cout << "******************************************************************************************\n ";

	return 0;
}


//___________________ EMPLOYEE - File Handling _____________________


void addEmployee_record()
{
	ofstream(outfile);
	Employee employee;

		outfile.open("Employee.dat", ios::app | ios::binary);
			employee.addEmployee();
			outfile.write((char*)&employee, sizeof(Employee));

	outfile.close();
}


void show_AllEmployee()
{
	Employee employee;
	ifstream(infile);
	infile.open("Employee.dat", ios::in | ios::binary);
	if (!infile)
	{
		cout << "File could not Found";
		return;
	}
	cout << "\n\n\t\tEMPLOYEE LIST\n\n";
	cout << "===========================================================\n";
	cout << "Emp no.      NAME           Post      Expirience \n";
	cout << "===========================================================\n";

	while (infile.read((char*)&employee, sizeof(Employee)))
	{
		employee.report();
	}
	infile.close();
}


void search_employee(int n)
{
	Employee employee;
	bool flag = false;
	ifstream inFile;
	inFile.open("Employee.dat", ios::binary);
	if (!inFile)
	{
		cout << "File could not be open. press any key...";
		return;
	}

	while (inFile.read(reinterpret_cast<char*> (&employee), sizeof(Employee)))
	{
		if (employee.Employee_No == n)
		{
			employee.show_Employee();
			flag = true;
		}
	}
	inFile.close();
	if (flag == false)
		cout << "\n\nEmployee number not exist";
}




//___________________ CUSTOMER - File Handling _____________________


void addCustomer_record()
{
	Customer customer;
	ofstream(outfile);
	outfile.open("Customer.dat", ios::app | ios::binary);
	customer.create_Acc();
	outfile.write((char*)&customer, sizeof(Customer));
}

void search_acc(int n)
{
	Customer customer;
	bool flag = false;
	ifstream inFile;
	inFile.open("Customer.dat", ios::in | ios::binary);
	if (!inFile)
	{
		cout << "File could not be open. press any key...";
		return;
	}

	while (inFile.read((char*)&customer, sizeof(Customer)))
	{
		if (customer.Acc_No == n)
		{
			customer.show_Account();
			flag = true;
		}
	}
	inFile.close();
	if (flag == false)
		cout << "\n\nAccount number not exist";

}

void modify_Acc(int n)
{
	bool found = false;
	Customer customer;
	fstream File;
	File.open("Customer.dat", ios::binary | ios::in | ios::out);
	if (!File)
	{
		cout << "File could not be open. press any key...";
		return;
	}
	while (!File.eof() && found == false)
	{
		File.read(reinterpret_cast<char*> (&customer), sizeof(Customer));
		if (customer.Acc_No == n)
		{
			customer.show_Account();
			cout << "\n\nEnter new account details" << endl;
			customer.Acc_modify();
			int pos = (-1) * static_cast<int>(sizeof(customer));
			File.seekp(pos, ios::cur);
			File.write(reinterpret_cast<char*> (&customer), sizeof(Customer));
			cout << "\n\n\t Record updated";
			found = true;
		}
	}
	File.close();
	if (found == false)
		cout << "\n\n Record not found";
}


void file_DepositeWithdraw(int n, int option)
{
	Customer customer;
	int amt;
	bool found = false;
	fstream File;
	File.open("Customer.dat", ios::binary | ios::in | ios::out);
	if (!File)
	{
		cout << "File could not be open, press any key...";
		return;
	}
	while ((char*)&customer,sizeof(Customer) && found == false)
	{
		File.read(reinterpret_cast<char*> (&customer), sizeof(Customer));
		if (customer.Acc_No == n)
		{
			found = true;
			customer.show_Account();
			if (option == 1)
			{
				cout << "\n\n\tTo deposit amount ";
				cout << "\n\nEnter the amount to deposit";
				cin >> amt;
				customer.Deposit(amt);
			}
			if (option == 2)
			{
				cout << "\n\n\tWithdraw amount ";
				cout << "\n\nEnter amount to withdraw";
				cin >> amt;
				float bal = customer.Acc_balance - amt;
				if (bal < 1000)
					cout << "Insufficient balance";
				else
					customer.Withdraw(amt);
			}
			int pos = (-1) * static_cast<int>(sizeof(customer));
			File.seekp(pos, ios::cur);
			File.write(reinterpret_cast<char*> (&customer), sizeof(Customer));
			cout << "\n\n\tRecord updated";
		}
	}
	File.close();
	if (found == false)
		cout << "\n\nRecord not found";
}


void show_AllCustomer()
{
	Customer customer;
	ifstream(infile);
	infile.open("Customer.dat", ios::in | ios::binary);
	if (!infile)
	{
		cout << "File could not Found";
		return;
	}
	cout << "\n\n\t\tACCOUNT LIST\n\n";
	cout << "==========================================================\n";
	cout << "Acc no.      NAME           NIC            Account Balance\n";
	cout << "==========================================================\n";

	while (infile.read((char*)&customer, sizeof(Customer)))
	{
		customer.Cus_Report();
	}
	infile.close();
}

void delete_Acc(int n)
{
	Customer customer;
	ifstream inFile;
	ofstream outFile;
	inFile.open("Customer.dat", ios::in | ios::binary);
	if (!inFile)
	{
		cout << "File could not be open. press any key...";
		return;
	}
	outFile.open("Temp.dat", ios::out | ios::binary);
	inFile.seekg(0, ios::beg);
	while (inFile.read((char*)&customer, sizeof(Customer)));
	{
		if (customer.Acc_No != n)
		{
			outFile.write((char*)&customer, sizeof(Customer));
		}
	}
	inFile.close();
	outFile.close();
	remove("Customer.dat");
	rename("Temp.dat", "Customer.dat");

		cout << "\n\n\tRecord deleted..";
}
