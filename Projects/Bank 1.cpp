#include<iostream>
#include<vector>
#include<iomanip>//for setw
#include<fstream>
#include<ctime>
#include <string>
#include<cstdlib>//for rand()
using namespace std;
const string ClientsFileName = "Clients.txt";
enum eTrans {
	Depositt = 1, Withdraww = 2,
	TotalBalancess = 3, MainMenuee = 4
};
struct sClient {
	string AccountNumber = "";
	string PinCode = "";
	string Name = "";
	string phone = "";
	double Balance = 0;
	bool MarkForDelete = false;
};
void TranseactionsServiece(eTrans Number);
void SpecifyTheService(vector<sClient>& vClient);

void PrintMainMenueScreen() {

	cout << "===============================================\n";
	cout << "\t\tMain Menue Screen\t\t\n";
	cout << "===============================================\n";
	cout << "\t[1] Show Client List.\n";
	cout << "\t[2] Add New Client.\n";
	cout << "\t[3] Delet Client.\n";
	cout << "\t[4] Ubdate Client Info.\n";
	cout << "\t[5] Find Client.\n";
	cout << "\t[6] Transactions.\n";
	cout << "\t[7] Exit.\n";
	cout << "===============================================\n";

}
//show Main Menue

vector<string> SplitString(string S1, string Delim)
{
	vector<string> vString;
	short pos = 0;
	string sWord; // define a string variable
	// use find() function to get the position of the delimiters
	while ((pos = S1.find(Delim)) != std::string::npos)
	{
		sWord = S1.substr(0, pos); // store the word

		if (sWord != "")
		{
			vString.push_back(sWord);
		}
		S1.erase(0, pos + Delim.length()); /* erase() until
		positon and move to next word. */
	}
	if (S1 != "")
	{
		vString.push_back(S1); // it adds last word of the string.
	}

	return vString;
}
//string words in string vector
sClient ConvertLinetoRecord(string s1) {
	vector<string>vClient;
	sClient Client;
	vClient = SplitString(s1, "#//#");
	Client.AccountNumber = vClient[0];
	Client.PinCode = vClient[1];
	Client.Name = vClient[2];
	Client.phone = vClient[3];
	Client.Balance = stod(vClient[4]);
	return Client;
}

vector<sClient> LoadCleintsDataFromFile(string FileName) {

	vector<sClient>vClient;
	fstream Myfile;

	Myfile.open(FileName, ios::in);
	if (Myfile.is_open()) {
		string line;
		sClient Client;
		while (getline(Myfile, line)) {
			Client = ConvertLinetoRecord(line);
			vClient.push_back(Client);


		}
		Myfile.close();
	}

	return vClient;
}
void PrintOneClientRecords(sClient Client) {

	cout << "|" << setw(15) << Client.AccountNumber;
	cout << "|" << setw(10) << Client.PinCode;
	cout << "|" << setw(40) << Client.Name;
	cout << "|" << setw(10) << Client.phone;
	cout << "|" << setw(10) << Client.Balance;


}
void PrintAllClientRecords(vector <sClient> vClient) {
	cout << "\n\t\t\t\t\tClient List (" << vClient.size() << ")Client(s).\n";

	cout << "------------------------------------------------------------------------------------------------------\n\n";
	cout << "|" << setw(15) << left << " Account Number ";
	cout << "|" << setw(10) << left << " Pin Code ";
	cout << "|" << setw(40) << left << " Client Name ";
	cout << "|" << setw(10) << left << " Phone ";
	cout << "|" << setw(10) << left << " Balance " << endl;
	cout << "\n-----------------------------------------------------------------------------------------------------\n\n";

	for (sClient Client : vClient) {
		PrintOneClientRecords(Client);
		cout << endl;
	}
	cout << "\n------------------------------------------------------------------------------------------------------\n";

}
void GoBackToMainMenu() {
	cout << "\nPress any key to go back to main menu...";
	system("pause>0");
}
void ShowAllClients(vector<sClient>vClient) {

	if (vClient.empty()) {
		cout << "\nNo clients found or file is empty!\n";
	}
	else {
		PrintAllClientRecords(vClient);
	}
}
sClient Chang_AddAddClientRecord(string AccountNumber)
{
	sClient Client;
	Client.AccountNumber = AccountNumber;
	cout << "\n\nEnter PinCode? ";
	getline(cin >> ws, Client.PinCode);
	cout << "Enter Name? ";
	getline(cin, Client.Name);
	cout << "Enter Phone? ";
	getline(cin, Client.phone);
	cout << "Enter AccountBalance? ";
	cin >> Client.Balance;
	return Client;
}

string ConvertRecordToLine(sClient Client, string Seperator = "#//#")
{
	string stClientRecord = "";
	stClientRecord += Client.AccountNumber + Seperator;
	stClientRecord += Client.PinCode + Seperator;
	stClientRecord += Client.Name + Seperator;
	stClientRecord += Client.phone + Seperator;
	stClientRecord += to_string(Client.Balance);
	return stClientRecord;
}
vector<sClient> SaveCleintsDataToFile(string FileName, vector<sClient>& vClient) {

	fstream Myfile;
	string Dataline;

	Myfile.open(FileName, ios::out);
	if (Myfile.is_open()) {
		for (sClient c : vClient) {
			if (c.MarkForDelete == false) {
				Dataline = ConvertRecordToLine(c);
				Myfile << Dataline << endl;
			}
		}
		Myfile.close();
	}

	return vClient;

}

bool TestIsHere(vector<sClient>vClient, string AccountNumber) {

	for (sClient Client : vClient) {

		if (Client.AccountNumber == AccountNumber) {
			cout << "Client with [" << AccountNumber << "] already exists, Entre another Account Number?";
			return false;
		}
	}

	return true;
}
void AddNewCLient(vector<sClient>& vClient) {

	string AccountNumber = "";
	sClient Client;

	do {
		cout << "Enrer Account Number to creat one?";
		cin >> AccountNumber;

	} while (TestIsHere(vClient, AccountNumber) == false);

	Client = Chang_AddAddClientRecord(AccountNumber);

	vClient.push_back(Client);




}
void PrintTheAddShape() {

	system("cls");
	cout << "\n--------------------------------------\n";
	cout << "\tAdd New Clients Screen\t";
	cout << "\n--------------------------------------\n";

}
void PrintDeletShape() {

	system("cls");
	cout << "\n--------------------------------------\n";
	cout << "\tDelet Client Screen\t";
	cout << "\n--------------------------------------\n";

}
void PrintUptadShape() {

	system("cls");
	cout << "\n--------------------------------------\n";
	cout << "\tUpdate Client Screen\t";
	cout << "\n--------------------------------------\n";

}
void PrintFindShape() {

	system("cls");
	cout << "\n--------------------------------------\n";
	cout << "\tUpdate Find Screen\t";
	cout << "\n--------------------------------------\n";

}
void PrintEndShape() {

	system("cls");
	cout << "\n--------------------------------------\n";
	cout << "\tProgram Ends :-)\t";
	cout << "\n--------------------------------------\n";

}


void AddmoreClients(vector<sClient> vClient) {
	char Answer = 'Y';
	do {
		PrintTheAddShape();
		AddNewCLient(vClient);
		SaveCleintsDataToFile(ClientsFileName, vClient);
		cout << "Client Add Successfully,Are you need add more clients? Y / N ?";
		cin >> Answer;

	} while (toupper(Answer) == 'Y');

}

void PrintClientRecords(sClient Client) {

	cout << "\nThe Following are Client detals:\n";
	cout << "\n------------------------------------------------------\n";
	cout << "\nAccount Number: " << Client.AccountNumber;
	cout << "\nPin Code: " << Client.PinCode;
	cout << "\nName: " << Client.Name;
	cout << "\nPhone: " << Client.phone;
	cout << "\nAccont Balance: " << Client.Balance;
	cout << "\n\n------------------------------------------------------\n";

}
sClient MarkeToDelet(sClient& Client) {
	char Answer = 'n';

	PrintClientRecords(Client);
	cout << "Are You sure to delet this Client? Y / N ?";
	cin >> Answer;

	if (toupper(Answer) == 'Y') {
		Client.MarkForDelete = true;

	}

	return Client;
}

bool FindClientByAccountNumber(string AccountNumber, vector<sClient> vClients, sClient& Client)
{
	for (sClient C : vClients)
	{
		if (C.AccountNumber == AccountNumber)
		{
			Client = C;
			return true;
		}
	}
	return false;
}

bool MarkClientForDeleteByAccountNumber(string AccountNumber, vector <sClient>& vClients)
{
	for (sClient& C : vClients)
	{
		if (C.AccountNumber == AccountNumber)
		{
			C.MarkForDelete = true;
			return true;
		}
	}
	return false;
}
void DeletClient(vector<sClient>& vClient) {

	string AccountNumber;
	sClient Client;
	char Answer = 'Y';

	PrintDeletShape();

	cout << "\n\nEnrer Account Number to delet ?";
	cin >> AccountNumber;

	if (FindClientByAccountNumber(AccountNumber, vClient, Client) == true) {
		PrintClientRecords(Client);
		cout << "Are You sure to delet this Client? Y / N ?";
		cin >> Answer;

		if (Answer == 'y' || Answer == 'Y') {

			MarkClientForDeleteByAccountNumber(AccountNumber, vClient);

			SaveCleintsDataToFile(ClientsFileName, vClient);

			cout << "\n\nClient Deleted Successfully.";

		}

	}

	else
	{
		cout << "\nClient with Account Number (" << AccountNumber
			<< ") is Not Found!";

	}


}
bool UpdateClientByAccountNumber(vector<sClient>& vClients)
{
	sClient Client;
	char Answer = 'n';
	string AccountNumber;

	PrintDeletShape();

	cout << "\n\nEnrer Account Number to update ?";
	cin >> AccountNumber;

	if (FindClientByAccountNumber(AccountNumber, vClients, Client))
	{
		PrintClientRecords(Client);

		cout << "\n\nAre you sure you want update this client? y/n ? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			for (sClient& C : vClients)
			{
				if (C.AccountNumber == AccountNumber)
				{
					C = Chang_AddAddClientRecord(AccountNumber);
					break;
				}
			}

			SaveCleintsDataToFile(ClientsFileName, vClients);
			//Refresh Clients

			cout << "\n\nClient Updated Successfully.";
			return true;
		}
	}
	else
	{
		cout << "\nClient with Account Number (" << AccountNumber
			<< ") is Not Found!";
		return false;
	}
}
void FindClient(vector<sClient>& vClient) {
	sClient Client;
	string AccountNumber;

	PrintFindShape();

	cout << "\n\nEnrer Account Number to update ?";
	cin >> AccountNumber;

	if (FindClientByAccountNumber(AccountNumber, vClient, Client))
	{
		PrintClientRecords(Client);
	}
	else {
		cout << "\nClient with Account Number (" << AccountNumber
			<< ") is Not Found!";
	}
}


short ReadNumber() {
	short Number = 0;
	cout << "Choice what do you whant to do? [1]To[4]?";
	cin >> Number;
	return Number;
}

bool FindAccountNumber(vector<sClient>vClient, string AccountNuber, sClient& Client) {
	for (sClient c : vClient)
		if (c.AccountNumber == AccountNuber) {
			Client = c;
			return true;
		}

	return false;
}
string ReadClientAccountNumber()
{
	string AccountNumber = "";

	cout << "\nPlease enter AccountNumber? ";
	cin >> AccountNumber;
	return AccountNumber;

}


void BehindDebosit(vector<sClient>& vClient) {
	sClient Client;
	string AccountNumber;
	double Amount;
	char Answer = 'n';
	AccountNumber = ReadClientAccountNumber();
	while (FindClientByAccountNumber(AccountNumber, vClient, Client) == false) {
		cout << "\nThis Account [" << AccountNumber << "] not found , Enter another number?";
		AccountNumber = ReadClientAccountNumber();

	}

	PrintClientRecords(Client);

	cout << "pleas Enter deposit amount?";
	cin >> Amount;

	cout << "\n\nAre you sure you want perform this transaction? y/n ? ";
	cin >> Answer;
	if (Answer == 'Y' || Answer == 'y') {
		for (sClient& C : vClient)
		{
			if (C.AccountNumber == AccountNumber)
			{
				C.Balance += Amount;
				break;
			}
		}
		SaveCleintsDataToFile(ClientsFileName, vClient);
		cout << "Done successfullly , New balance= " << Client.Balance + Amount << ".\n";
	}

}
void TransactionsShape() {
	system("cls");
	cout << "\n==========================================\n";
	cout << "\tTransactoins Menue Screen\t";
	cout << "\n==========================================\n";
	cout << "\t[1] Deposit.\n";
	cout << "\t[2] Withdraw.\n";
	cout << "\t[3] Total Balances.\n";
	cout << "\t[4] Main Menue.\n";
	cout << "\n===============================\n";
	TranseactionsServiece((eTrans)ReadNumber());

}
void GoBackToTransactionsMenu() {

	cout << "\nPress any key to go back to Transaction menu...";
	system("pause>0");
	TransactionsShape();
}
void Deposit() {

	system("cls");
	cout << "\n--------------------------------------\n";
	cout << "\tDepoist\t";
	cout << "\n--------------------------------------\n";
	vector<sClient>vClient;
	vClient = LoadCleintsDataFromFile(ClientsFileName);
	BehindDebosit(vClient);

}

void BehindWithdraw(vector<sClient>& vClient) {
	sClient Client;
	string AccountNumber;
	double Amount;
	char Answer = 'n';
	AccountNumber = ReadClientAccountNumber();
	if (FindClientByAccountNumber(AccountNumber, vClient, Client)) {





		PrintClientRecords(Client);

		cout << "\npleas Enter deposit amount?";
		cin >> Amount;

		while (Amount >= Client.Balance) {
			cout << "Amount Exceeds the balance, you can withdraw up to: " << Client.Balance;
			cout << "\npleas Enter deposit amount?";
			cin >> Amount;

		}

		cout << "\n\nAre you sure you want perform this transaction? y/n ? ";
		cin >> Answer;
		if (Answer == 'Y' || Answer == 'y') {
			for (sClient& C : vClient)
			{
				if (C.AccountNumber == AccountNumber)
				{
					C.Balance -= Amount;
					break;
				}
			}
			SaveCleintsDataToFile(ClientsFileName, vClient);
			cout << "Done successfullly , New balance= " << Client.Balance - Amount << ".\n";
		}
	}
	else {
		cout << "\nThis Account [" << AccountNumber << "] not found , Enter another number?";
	}
}
void Withdraw() {

	system("cls");
	cout << "\n--------------------------------------\n";
	cout << "\tWithdraw\t";
	cout << "\n--------------------------------------\n";
	vector<sClient>vClient;
	vClient = LoadCleintsDataFromFile(ClientsFileName);
	BehindWithdraw(vClient);

}
void BehindTotalBalance(vector<sClient>& vClient) {
	double Total = 0;
	cout << "\n\t\t\t\t\tClient List (" << vClient.size() << ")Client(s).\n";

	cout << "------------------------------------------------------------------------------------------------------\n\n";
	cout << "|" << setw(20) << left << " Account Number ";

	cout << "|" << setw(50) << left << " Client Name ";

	cout << "|" << setw(20) << left << " Balance " << endl;
	cout << "\n-----------------------------------------------------------------------------------------------------\n\n";

	for (sClient Client : vClient) {
		Total += Client.Balance;
		PrintOneClientRecords(Client);
		cout << endl;
	}
	cout << "\n-------------------------------------------------------------------------------------------------------\n";
	cout << "\t\t\t\tTotal Balance = " << Total << "\t\t\t\t\n";
}
void TotalBalance() {

	system("cls");
	cout << "\n-------------------------------------------------------------------------------------------------------\n";
	cout << "\t\t\t\tTotal Balance\t\t\t\t";
	cout << "\n-------------------------------------------------------------------------------------------------------\n";
	vector<sClient>vClient;
	vClient = LoadCleintsDataFromFile(ClientsFileName);
	BehindTotalBalance(vClient);

}
void PrintTransactionRecords(sClient Client) {

	cout << "|" << setw(20) << Client.AccountNumber;

	cout << "|" << setw(50) << Client.Name;

	cout << "|" << setw(20) << Client.Balance;


}
void MainMenu() {
	vector <sClient>vClient;
	vClient = LoadCleintsDataFromFile(ClientsFileName);
	SpecifyTheService(vClient);

}
void TranseactionsServiece(eTrans Number) {

	switch (Number) {

	case eTrans::Depositt:

		system("cls");
		Deposit();
		GoBackToTransactionsMenu();
		break;
	case eTrans::Withdraww:
		system("cls");
		Withdraw();
		GoBackToTransactionsMenu();
		break;
	case eTrans::TotalBalancess:
		system("cls");
		TotalBalance();
		GoBackToTransactionsMenu();
		break;
	case eTrans::MainMenuee:
		system("cls");
		MainMenu();

		break;

	}

}









void SpecifyTheService(vector<sClient>& vClient) {
	short Number = 0;
	do {
		system("cls");
		PrintMainMenueScreen();
		vClient = LoadCleintsDataFromFile(ClientsFileName);

		short Number = 0;
		cout << "Choose what do you want to do? [1 to 7]?";
		cin >> Number;
		switch (Number) {
		case 1:
			system("cls");
			ShowAllClients(vClient);
			GoBackToMainMenu();

			break;
		case 2:
			system("cls");
			AddmoreClients(vClient);
			GoBackToMainMenu();
			break;
		case 3:
			system("cls");
			DeletClient(vClient);
			GoBackToMainMenu();
			break;
		case 4:
			system("cls");
			UpdateClientByAccountNumber(vClient);
			GoBackToMainMenu();
			break;
		case 5:
			system("cls");
			FindClient(vClient);
			GoBackToMainMenu();
			break;
		case 6:
			system("cls");
			TransactionsShape();
			GoBackToMainMenu();
			break;
		case 7:
			PrintEndShape();
			exit(0);
			break;
		default:
			cout << "Invalid choice. Please try again.\n";
			GoBackToMainMenu();
		}
	} while (Number != 7);
}

// complete


int main()
{
	vector<sClient>vClient;

	SpecifyTheService(vClient);


	system("pause>0");
	return 0;
}
