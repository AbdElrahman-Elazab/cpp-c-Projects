#pragma once
#pragma warning(disable:4996)
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<iomanip>//for setw

using namespace std;
const string ClientsFileName = "Clients.txt";

namespace MyLib
{
	class clsCalculator
	{
	private:
		float _Result = 0;
		float _LastNumber = 0;
		string _LastOperation = "Clear";
		float _PreviousResult = 0;
		bool _IsZero(float Number)
		{
			return (Number == 0);
		}
	public:
		void Add(float Number)
		{
			_LastNumber = Number;
			_PreviousResult = _Result;
			_LastOperation = "Adding";
			_Result += Number;
		}
		void Subtract(float Number)
		{
			_LastNumber = Number;
			_PreviousResult = _Result;
			_LastOperation = "Subtracting";
			_Result -= Number;
		}
		
			void Divide(float Number)
		{
			_LastNumber = Number;
			if (_IsZero(Number))
			{
				Number = 1;
			}
			_PreviousResult = _Result;
			_LastOperation = "Dividing";
			_Result /= Number;
		}
		void Multiply(float Number)
		{
			_LastNumber = Number;
			_LastOperation = "Multiplying";
			_PreviousResult = _Result;
			_Result *= Number;
		}
		float GetFinalResults()
		{
			return _Result;
		}
		void Clear()
		{
			_LastNumber = 0;
			_PreviousResult = 0;
			_LastOperation = "Clear";
			_Result = 0;
		}
		
			void CancelLastOperation()
		{
			_LastNumber = 0;
			_LastOperation = "Cancelling Last Operation";
			_Result = _PreviousResult;
		}
		void PrintResult()
		{
			cout << "Result ";
			cout << "After " << _LastOperation << " " <<
				_LastNumber << " is: " << _Result << "\n";
		}
	};


	void LoadDataFromFileTOVector(string FileName, vector <string>& vFileContent) {
		fstream MyFile;
		MyFile.open(FileName, ios::in);
		if (MyFile.is_open()) {
			string Line;
			while (getline(MyFile, Line)) {

				vFileContent.push_back(Line);

			}
			MyFile.close();
		}
	}
	
	void SaveVectorToFile(string FileName, vector <string>& vFileContent) {
		fstream MyFile;
		MyFile.open(FileName, ios::out);
		if (MyFile.is_open()) {

			for (string& Line : vFileContent) {
				if (Line != "") {
					MyFile << Line << endl;
				}

			}
			MyFile.close();
		}
	}
	
	void UpdateRecordInFile(string FileName, string Record, string  UpdateTo) {
		vector <string> vFileContent;
		LoadDataFromFileTOVector(FileName, vFileContent);
		for (string& Line : vFileContent) {
			if (Line == Record) {
				Line = UpdateTo;
			}

		}
		SaveVectorToFile(FileName, vFileContent);
	}
	
	void DeleteRecordFromFile(string FileName, string Record) {


		vector <string> vFileContent;
		LoadDataFromFileTOVector(FileName, vFileContent);
		for (string& Line : vFileContent) {
			if (Line == Record) {
				Line = "";
			}

		}
		SaveVectorToFile(FileName, vFileContent);
	}
	
	void PrintFileContent(string FileName) {
		fstream MyFile;
		MyFile.open(FileName, ios::in);
		if (MyFile.is_open()) {
			string Line;
			while (getline(MyFile, Line)) {

				cout << Line << endl;
			}
			MyFile.close();
		}
	}
	
	void ShowThe_Local_and_UTC_Time() {
		time_t t = time(0); // get time now
		char* dt = ctime(&t); // convert in string form
		cout << "Local date and time is: " << dt << "\n";
		// converting now to tm struct for UTC date/time
		tm* gmtm = gmtime(&t);
		dt = asctime(gmtm);
		cout << "UTC date and time is: " << dt;
	}
	
	int PrintNumber(int Base, int Power) {
		if (Power == 0)
			return 1;
		else {
			return(Base * PrintNumber(Base, Power - 1));
		}
	} 

	int ReadNumber() {
		int Number;
		cout << "Please Enter Number ?";
		cin >> Number;
		while (cin.fail()) {
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "Invalide Number,Enter a valide one:" << endl;
			cin >> Number;
		}
		return Number;
	}


	string PrintUpper(string s1) {
		for (int i = 0; i < s1.length(); i++) {

			s1[i] = toupper(s1[i]);

		}
		return s1;
	}


	string PrintLower(string s1) {
		for (int i = 0; i < s1.length(); i++) {

			s1[i] = tolower(s1[i]);

		}
		return s1;
	}

	char InvertLetterCase(char char1) {
		return isupper(char1) ? tolower(char1) : toupper(char1);
	}

	string InvertAllStringLettersCase(string s1) {
		for (short i = 0; i < s1.length(); i++) {
			s1[i] = InvertLetterCase(s1[i]);
		}
		return s1;
	}
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
	string JoinString(vector<string> vString, string Delim)
	{
		string S1;
		for (string& s : vString)
		{
			S1 = S1 + s + Delim;
		}
		return S1.substr(0, S1.length() - Delim.length());
	}
	string LowerAllString(string S1)
	{
		for (short i = 0; i < S1.length(); i++)
		{
			S1[i] = tolower(S1[i]);
		}
		return S1;
	}
 
	struct sClient
	{
		string AccountNumber;
		string PinCode;
		string Name;
		string Phone;
		double AccountBalance;
		bool MarkForDelete = false;
	};
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
			S1.erase(0, pos + Delim.length());
		}
		if (S1 != "")
		{
			vString.push_back(S1); // it adds last word of the string.
		}
		return vString;
	}

	sClient ConvertLinetoRecord(string Line, string Seperator = "#//#")
	{
		sClient Client;
		vector<string> vClientData;
		vClientData = SplitString(Line, Seperator);
		Client.AccountNumber = vClientData[0];
		Client.PinCode = vClientData[1];
		Client.Name = vClientData[2];
		Client.Phone = vClientData[3];
		Client.AccountBalance = stod(vClientData[4]);
		return Client;
	}
	string ConvertRecordToLine(sClient Client, string Seperator =
		"#//#")
	{
		string stClientRecord = "";
		stClientRecord += Client.AccountNumber + Seperator;
		stClientRecord += Client.PinCode + Seperator;
		stClientRecord += Client.Name + Seperator;
		stClientRecord += Client.Phone + Seperator;
		stClientRecord += to_string(Client.AccountBalance);
		return stClientRecord;
	}

	vector <sClient> LoadCleintsDataFromFile(string FileName)
	{
		vector <sClient> vClients;
		fstream MyFile;
		MyFile.open(FileName, ios::in);//read Mode
		if (MyFile.is_open())
		{
			string Line;
			sClient Client;
			while (getline(MyFile, Line))
			{
				Client = ConvertLinetoRecord(Line);
				vClients.push_back(Client);
			}
			MyFile.close();
		}
		return vClients;
	}
	void PrintClientCard(sClient Client)
	{
		cout << "\nThe following are the client details:\n";
		cout << "\nAccout Number: " << Client.AccountNumber;
		cout << "\nPin Code : " << Client.PinCode;
		cout << "\nName : " << Client.Name;
		cout << "\nPhone : " << Client.Phone;
		cout << "\nAccount Balance: " << Client.AccountBalance;
	}

	bool FindClientByAccountNumber(string AccountNumber, vector
		<sClient> vClients, sClient& Client)
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
	bool MarkClientForDeleteByAccountNumber(string AccountNumber,
		vector <sClient>& vClients)
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
	sClient ChangeClientRecord(string AccountNumber)
	{
		sClient Client;
		Client.AccountNumber = AccountNumber;
		cout << "\n\nEnter PinCode? ";
		getline(cin >> ws, Client.PinCode);
		cout << "Enter Name? ";
		getline(cin, Client.Name);
		cout << "Enter Phone? ";
		getline(cin, Client.Phone);
		cout << "Enter AccountBalance? ";
		cin >> Client.AccountBalance;
		return Client;
	}

	vector <sClient> SaveCleintsDataToFile(string FileName, vector<sClient> vClients)
	{
		fstream MyFile;
		MyFile.open(FileName, ios::out);//overwrite
		string DataLine;
		if (MyFile.is_open())
		{
			for (sClient C : vClients)
			{
				if (C.MarkForDelete == false)
				{

					DataLine = ConvertRecordToLine(C);
					MyFile << DataLine << endl;
				}
			}
			MyFile.close();
		}
		return vClients;
	}

	bool DeleteClientByAccountNumber(string AccountNumber, vector<sClient>& vClients)
	{
		sClient Client;
		char Answer = 'n';
		if (FindClientByAccountNumber(AccountNumber, vClients,
			Client))
		{
			PrintClientCard(Client);
			cout << "\n\nAre you sure you want update this client? y/n ? ";
			cin >> Answer;
			if (Answer == 'y' || Answer == 'Y')
			{
				for (sClient& C : vClients)
				{
					if (C.AccountNumber == AccountNumber)
					{
						C = ChangeClientRecord(AccountNumber);
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
	string ReadClientAccountNumber()
	{
		string AccountNumber = "";
		cout << "\nPlease enter AccountNumber? ";
		cin >> AccountNumber;
		return AccountNumber;
	}
}
