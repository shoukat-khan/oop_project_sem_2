#include <iostream>
#include <string>
#include <string.h>
#include <conio.h>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include <fstream>
using namespace std;
const int max_users = 60;
class user {
	// 5 variables 
private:
	string cnic;
	string fullname;
	string mobile_no;
	string email;


public:
	user() {
		cnic = "";
		fullname = "";
		mobile_no = "";
		email = "";
	}
	user(string fn = "", string cn = "", string mo_no = "", string e = "") {

		cnic = cn;
		fullname = fn;
		mobile_no = mo_no;
		email = e;

	}
	string getemail() {
		return email;
	}
	string getcnic() {
		return cnic;
	}
	string getfullname() {
		return fullname;
	}
	string getmobile_no() {
		return mobile_no;
	}

	void setfullname(string fn) {
		fullname = fn;
	}
	void setcnic(string c) {
		cnic = c;
	}
	void setemail(string e) {
		email = e;
	}
	void setMob_no(string num) {
		mobile_no = num;
	}
	bool validatePassword(string s) {
		bool hasUppercase = false;
		bool hasLowercase = false;
		bool hasSpecialChar = false;
		bool hasNumber = false;

		for (int i = 0; i < s.length(); i++) {
			char c = s[i];
			if (c >= 'A' && c <= 'Z') {
				hasUppercase = true;
			}
			else if (c >= 'a' && c <= 'z') {
				hasLowercase = true;
			}
			else if (c >= '0' && c <= '9') {
				hasNumber = true;
			}
			else {
				hasSpecialChar = true;
			}

			if (hasUppercase && hasLowercase && hasSpecialChar && hasNumber) {
				return true;
			}
		}

		return false;
	}
};

class passenger :public user {
	string password;
public:
	void setpassword(string p) {
		password = p;
	}
	string getpassword() {
		return password;
	}
	passenger(string name = "", string cnic = "", string p = "", string mobile_no = "", string email = "") :user(name, cnic, mobile_no, email) {
		password = p;
	}
};

class admin :public user {
	string password;
public:
	void setpassword(string p) {
		password = p;
	}
	string getpassword() {
		return password;
	}
	admin(string name = "", string cnic = "", string p = "", string mobile_no = "", string email = "") :user(name, cnic, mobile_no, email) {
		password = p;
	}
	void restrictPassengers(int maxPassengers) {

	}

};
// user new user??????E|EE

class userdata {
	admin* staff;
	passenger* pass;
	static int no_of_passenger;
	static int no_of_admin;
	int total;
	int no_of_login;
public:
	//getter and setter 
	void setno_of_login(int ww) {
		no_of_login = ww;
	}
	int getvalueelogin() {
		return no_of_login;
	}
	passenger getno_of_login(int i) {
		return pass[i];
	}
	//getter 
	int gettotal() {
		return total;
	}
	int getno_of_passenger() {
		return no_of_passenger;
	}
	int getno_of_admin() {
		return no_of_admin;
	}
	//constructor
	userdata() {

		staff = new admin[3];
		pass = new passenger[max_users];
		total = no_of_passenger + no_of_admin;
	}
	//check on cnic of admin
	bool cnic_validationadmin(string c) {
		bool x = false;
		for (int i = 0; i < no_of_admin; i++) {
			staff[i].getcnic() == c;
			cout << "\n cnic same were found please enter valid cnic else u are a register user ";
			x = true;
		}
		if (c.length() == 13 && x == false)
			return true;
		else
			return false;
	}
	bool cnic_validationpassenger(string c) {
		bool x = false;
		for (int i = 0; i < no_of_passenger; i++) {
			pass[i].getcnic() == c;
			cout << "\n cnic same were found please enter valid cnic else u are a register user ";
			x = true;
		}
		if (c.length() == 13 && x == false)
			return true;
		else
			return false;
	}
	//password entery function 
	string entrpassword() {
		string n, c, e, p, cn;
		char ch;
		while (true) {
			ch = _getch();    // function from the conio library

			if (ch == 13) { // ASCII for enter key
				break;
			}
			else if (ch == 8) { //ASCII for backspace key
				if (p.length() > 0) {
					string newPassword = "";
					for (int i = 0; i < p.length() - 1; i++) {
						newPassword += p[i];
					}
					p = newPassword;
					cout << "\b \b"; // Move cursor back, print space, move cursor back again
				}
			}
			else {
				p += ch;
				cout << "*";
			}
		}
		//////// for to confirm in login time
		cout << p;
		return p;
	}
	//add admin in the array 

	void addamin()
	{
		int x = 1;
		int y = 1;
		string mob_no;
		string n, c, e, p, cn;
		ofstream outputFileadmin("E:\\outputadmin.txt", ios::app);

		
		cout << "enter admin name \t";
		cin >> n;

		staff[no_of_admin].setfullname(n);
		
		outputFileadmin << staff[no_of_admin].getfullname() << endl;
		cout << "\n:enter password \t";

		string s;

		do {
			if (x >= 2) {
				cout << "reenter password \n";
			}
			s = entrpassword();
			staff[no_of_admin].validatePassword(s);
			x++;
		} while (staff[no_of_admin].validatePassword(s) == false);

		
		


		staff[no_of_admin].setpassword(s);
		outputFileadmin << staff[no_of_admin].getpassword() << endl;
		//cnic function has been saved here //////// cnic
		cout << "\n:enter cnic of admin \t";
		do {
			if (y >= 2) {
				cout << ":\n reenter valid cnic or u are a register user  \t";
			}

			cin >> c;
			y++;
		} while (cnic_validationadmin(c) == false);

		cout << "\n :enter the email of staff\t";
		cin >> e;
		staff[no_of_admin].setemail(e);
		cout << "\n :enter the mobile_no of staff\t";
		cin >> mob_no;
		staff[no_of_admin].setMob_no(mob_no);
		no_of_admin++;
		outputFileadmin.close();
	}
	//add passenger in class 

	void addpassenger()
	{
		int y = 1;
		string mob_no;
		string n, c, e, p, cn;
		ofstream outputFilepassenger("E:\\outputpassenger.txt",ios::app );
		cout << "enter passenger name \t";
		cin >> n;
		pass[no_of_admin].setfullname(n);
		outputFilepassenger<<pass[no_of_admin].getfullname()<<endl;
		cout << "\n:enter password \t";
		string s;
		int x = 1;
		do {
			if (x >= 2) {
				cout << "reenter password \n";
			}

			s = entrpassword();
			pass[no_of_admin].validatePassword(s);
			x++;
		} while (pass[no_of_admin].validatePassword(s) == false);

		pass[no_of_admin].setpassword(s);
		outputFilepassenger << pass[no_of_admin].getpassword()<<endl;
		cout << "\n:enter cnic of admin \t";
		//cnic function has been saved here //////// cnic 
		do {
			if (y >= 2) {
				cout << ":\n reenter valid cnic or you are an register people \t";
			}
			cin >> c;
			y++;
		} while (cnic_validationpassenger(c) == false);

		cout << "\n :enter the email of passenger\t";
		cin >> e;
		staff[no_of_admin].setemail(e);
		cout << "\n :enter the mobile_no of passesnger\t";
		cin >> mob_no;
		staff[no_of_admin].setMob_no(mob_no);

		no_of_passenger++;
		outputFilepassenger.close();
	}
	bool loginadmin() {
		string nam, pwd;
		bool k = false;
		bool g = false, y = false;
		cout << "enter the admin name please enter valid\t";
		cin >> nam;
		cout << "\nenter the admin password please enter valid \t";
		cin >> pwd;
		for (int x = 0; x < no_of_admin; x++) {

			if (staff[x].getfullname() == nam && staff[x].getpassword() == pwd) {
				cout << pass[x].getfullname() << ": sucssesfully logined";
				return true;
			}
		}
		if (k == false) {
			cout << "register the user 1st then proceed forward";
		}
		return false;
	}
	bool loginpassenger() {
		bool k = false;
		string nam, pwd;
		cout << "enter the passenger name please enter valid\t";
		cin >> nam;
		cout << "\nenter the passenger password please enter valid \t";
		cin >> pwd;

		for (int x = 0; x < no_of_passenger; x++) {
			if (pass[x].getfullname() == nam && pass[x].getpassword() == pwd) {
				x = no_of_login;
				cout << pass[x].getfullname() << ": sucssesfully logined";
				return  true;
			}
		}
		if (k == false) {
			cout << "register the user 1st then proceed forward";
		}
		return k;
	}
};
int  userdata::no_of_admin = 0;
int  userdata::no_of_passenger = 0;
/// <summary>
/// /////////////////////////................./////////////////
/// </summary>
class flight_s {

protected:
	double arrival_time;
	double departure_time;
	double total_time;
	public:
	string local_c;
	string arrival_country;

	string local[5] = { "peshawar","lahore","karachi", "QUETTA","ISLAMABAD" };
	string countries[25] = {
   "United States","China","Japan", "Germany",
   "United Kingdom", "France","Italy","Canada","South Korea",
   "Australia","Russia","Spain","Mexico","Indonesia",
   "Netherlands","Saudi Arabia", "Switzerland","Turkey",
   "Poland","Sweden","Belgium","Iran","Norway","Austria","UAE"
	};

	//to get values at specific position in array
	string getlocal(int v) {
		return local[v];
	}
	string getinternational(int j) {
		return countries[j];
	}
	void setarray(int z) {
		swap(local[z], local[4]);
	}

	void setlocal(string loc) {
		local_c = loc;
	}
	string getarrival() {
		return arrival_country;;
	}
	string getlocalcountry() {
		return local_c;
	}

	//setter and getter 
	void setdeparture(double i) {
		departure_time = i;
	}
	double getdeparture_time() {
		return departure_time;
	}
	void setarrivaltime(double get)
	{
		arrival_time = get;
	}
	double getarrivaltime() {
		return arrival_time;
	}
	void settotaltime(double c)
	{
		total_time = c;
	}
	double gettotaltime() {
		return total_time;
	}
};
//////////////////////////////////////////////.........................
class international
{
	flight_s* internation;
public:
	string h;
	static int economy_seat;
	static  int buisiness_seat;
	international() {
		internation = new flight_s[5];
	}
	flight_s getflight_international(int i) {
		return internation[i];
	}
	void display() {
		srand(time(0));
		int  k = 1;
		char i;
		char x;
		
		cout << "select departure airport :\n";
		cout << "1. ISLAMABAD\n";
		cout << "2. QUETTA\n";
		cout << "3. KARACHI\n";
		cout << "4. PESHAWAR \n";
		cout << "5. LAHORE\n";
		do {
			cin >> x;
		} while (x!='1'&& x != '2'&&x != '3'&& x != '4'&& x != '5');
		cout << "select north or south\n";
		cout << "1. north\n 2.south";
		do {
			if (k >= 2) {
				cout << "please enter vlaid no";
			}
			cin >> i;
			if (i == '1') {
				h = "N0RTH";
			}
			if (i == '2')
			{
				h = "SOUTH";
			}
			k++;
		} while (i != '1' && i != '2');
		switch (x) {
		case '1':
			for (int i = 0; i < 5; i++) {

				internation[i].getlocal(4);
				internation[i].setlocal(internation[i].getlocal(4) + h);

				int random = rand() % 25;
				internation[i].arrival_country = internation[i].getinternational(random);
				if (internation[i].arrival_country == "United States") {
					internation[i].settotaltime(20.0);
				}

				else if (internation[i].arrival_country == "China") {
					internation[i].settotaltime(2.5);

				}
				else if (internation[i].arrival_country == "Japan") {
					internation[i].settotaltime(23.0);
				}

				else if (internation[i].arrival_country == "Germany") {
					internation[i].settotaltime(24.0);
				}
				else if (internation[i].arrival_country == "United Kingdom") {
					internation[i].settotaltime(21.0);
				}
				else if (internation[i].arrival_country == "Italy") {
					internation[i].settotaltime(18.0);
				}
				else if (internation[i].arrival_country == "Canada") {
					internation[i].settotaltime(24.0);
				}
				else if (internation[i].arrival_country == "South Korea") {
					internation[i].settotaltime(17.5);
				}
				else if (internation[i].arrival_country == "Australia") {
					internation[i].settotaltime(23.5);
				}
				else if (internation[i].arrival_country == "Russia") {
					internation[i].settotaltime(15.6);
				}
				else if (internation[i].arrival_country == "Spain") {
					internation[i].settotaltime(15.0);
				}
				else if (internation[i].arrival_country == "Mexico") {
					internation[i].settotaltime(16.5);
				}
				else if (internation[i].arrival_country == "Indonesia") {
					internation[i].settotaltime(12.3);
				}
				else if (internation[i].arrival_country == "Netherlands") {
					internation[i].settotaltime(14.6);
				}
				else if (internation[i].arrival_country == "Saudi Arabia") {
					internation[i].settotaltime(12.5);
				}
				else if (internation[i].arrival_country == "Switzerland") {
					internation[i].settotaltime(19.4);
				}
				else if (internation[i].arrival_country == "Turkey") {
					internation[i].settotaltime(11.0);
				}
				else if (internation[i].arrival_country == "Poland") {
					internation[i].settotaltime(13.6);
				}
				else if (internation[i].arrival_country == "Sweden") {
					internation[i].settotaltime(09.9);
				}
				else if (internation[i].arrival_country == "Belgium") {
					internation[i].settotaltime(08.0);
				}
				else if (internation[i].arrival_country == "Iran") {
					internation[i].settotaltime(04.0);
				}
				else if (internation[i].arrival_country == "Norway") {
					internation[i].settotaltime(14.6);
				}

				else if (internation[i].arrival_country == "Austria") {
					internation[i].settotaltime(22.2);
				}
				else if (internation[i].arrival_country == "UAE") {
					internation[i].settotaltime(48.5);
				}

			}
			break;
		case '2':
			for (int i = 0; i < 5; i++) {

				internation[i].getlocal(3);
				internation[i].setlocal(internation[i].getlocal(3) + h);

				int random = rand() % 25;
				internation[i].arrival_country = internation[i].getinternational(random);
				if (internation[i].arrival_country == "United States") {
					internation[i].settotaltime(20.0);
				}

				else if (internation[i].arrival_country == "China") {
					internation[i].settotaltime(2.5);

				}
				else if (internation[i].arrival_country == "Japan") {
					internation[i].settotaltime(23.0);
				}

				else if (internation[i].arrival_country == "Germany") {
					internation[i].settotaltime(24.0);
				}
				else if (internation[i].arrival_country == "United Kingdom") {
					internation[i].settotaltime(21.0);
				}
				else if (internation[i].arrival_country == "Italy") {
					internation[i].settotaltime(18.0);
				}
				else if (internation[i].arrival_country == "Canada") {
					internation[i].settotaltime(24.0);
				}
				else if (internation[i].arrival_country == "South Korea") {
					internation[i].settotaltime(17.5);
				}
				else if (internation[i].arrival_country == "Australia") {
					internation[i].settotaltime(23.5);
				}
				else if (internation[i].arrival_country == "Russia") {
					internation[i].settotaltime(15.6);
				}
				else if (internation[i].arrival_country == "Spain") {
					internation[i].settotaltime(15.0);
				}
				else if (internation[i].arrival_country == "Mexico") {
					internation[i].settotaltime(16.5);
				}
				else if (internation[i].arrival_country == "Indonesia") {
					internation[i].settotaltime(12.3);
				}
				else if (internation[i].arrival_country == "Netherlands") {
					internation[i].settotaltime(14.6);
				}
				else if (internation[i].arrival_country == "Saudi Arabia") {
					internation[i].settotaltime(12.5);
				}
				else if (internation[i].arrival_country == "Switzerland") {
					internation[i].settotaltime(19.4);
				}
				else if (internation[i].arrival_country == "Turkey") {
					internation[i].settotaltime(11.0);
				}
				else if (internation[i].arrival_country == "Poland") {
					internation[i].settotaltime(13.6);
				}
				else if (internation[i].arrival_country == "Sweden") {
					internation[i].settotaltime(09.9);
				}
				else if (internation[i].arrival_country == "Belgium") {
					internation[i].settotaltime(08.0);
				}
				else if (internation[i].arrival_country == "Iran") {
					internation[i].settotaltime(04.0);
				}
				else if (internation[i].arrival_country == "Norway") {
					internation[i].settotaltime(14.6);
				}

				else if (internation[i].arrival_country == "Austria") {
					internation[i].settotaltime(22.2);
				}
				else if (internation[i].arrival_country == "UAE") {
					internation[i].settotaltime(48.5);
				}

			}
			break;
		case '3':
			for (int i = 0; i < 5; i++) {

				internation[i].getlocal(2);
				internation[i].setlocal(internation[i].getlocal(2) + h);

				int random = rand() % 25;
				internation[i].arrival_country = internation[i].getinternational(random);
				if (internation[i].arrival_country == "United States") {
					internation[i].settotaltime(20.0);
				}

				else if (internation[i].arrival_country == "China") {
					internation[i].settotaltime(2.5);

				}
				else if (internation[i].arrival_country == "Japan") {
					internation[i].settotaltime(23.0);
				}

				else if (internation[i].arrival_country == "Germany") {
					internation[i].settotaltime(24.0);
				}
				else if (internation[i].arrival_country == "United Kingdom") {
					internation[i].settotaltime(21.0);
				}
				else if (internation[i].arrival_country == "Italy") {
					internation[i].settotaltime(18.0);
				}
				else if (internation[i].arrival_country == "Canada") {
					internation[i].settotaltime(24.0);
				}
				else if (internation[i].arrival_country == "South Korea") {
					internation[i].settotaltime(17.5);
				}
				else if (internation[i].arrival_country == "Australia") {
					internation[i].settotaltime(23.5);
				}
				else if (internation[i].arrival_country == "Russia") {
					internation[i].settotaltime(15.6);
				}
				else if (internation[i].arrival_country == "Spain") {
					internation[i].settotaltime(15.0);
				}
				else if (internation[i].arrival_country == "Mexico") {
					internation[i].settotaltime(16.5);
				}
				else if (internation[i].arrival_country == "Indonesia") {
					internation[i].settotaltime(12.3);
				}
				else if (internation[i].arrival_country == "Netherlands") {
					internation[i].settotaltime(14.6);
				}
				else if (internation[i].arrival_country == "Saudi Arabia") {
					internation[i].settotaltime(12.5);
				}
				else if (internation[i].arrival_country == "Switzerland") {
					internation[i].settotaltime(19.4);
				}
				else if (internation[i].arrival_country == "Turkey") {
					internation[i].settotaltime(11.0);
				}
				else if (internation[i].arrival_country == "Poland") {
					internation[i].settotaltime(13.6);
				}
				else if (internation[i].arrival_country == "Sweden") {
					internation[i].settotaltime(09.9);
				}
				else if (internation[i].arrival_country == "Belgium") {
					internation[i].settotaltime(08.0);
				}
				else if (internation[i].arrival_country == "Iran") {
					internation[i].settotaltime(04.0);
				}
				else if (internation[i].arrival_country == "Norway") {
					internation[i].settotaltime(14.6);
				}

				else if (internation[i].arrival_country == "Austria") {
					internation[i].settotaltime(22.2);
				}
				else if (internation[i].arrival_country == "UAE") {
					internation[i].settotaltime(48.5);
				}

			}
			break;

		case '4':
			for (int i = 0; i < 5; i++) {

				internation[i].getlocal(0);
				internation[i].setlocal(internation[i].getlocal(0) + h);

				int random = rand() % 25;
				internation[i].arrival_country = internation[i].getinternational(random);
				if (internation[i].arrival_country == "United States") {
					internation[i].settotaltime(20.0);
				}

				else if (internation[i].arrival_country == "China") {
					internation[i].settotaltime(2.5);

				}
				else if (internation[i].arrival_country == "Japan") {
					internation[i].settotaltime(23.0);
				}

				else if (internation[i].arrival_country == "Germany") {
					internation[i].settotaltime(24.0);
				}
				else if (internation[i].arrival_country == "United Kingdom") {
					internation[i].settotaltime(21.0);
				}
				else if (internation[i].arrival_country == "Italy") {
					internation[i].settotaltime(18.0);
				}
				else if (internation[i].arrival_country == "Canada") {
					internation[i].settotaltime(24.0);
				}
				else if (internation[i].arrival_country == "South Korea") {
					internation[i].settotaltime(17.5);
				}
				else if (internation[i].arrival_country == "Australia") {
					internation[i].settotaltime(23.5);
				}
				else if (internation[i].arrival_country == "Russia") {
					internation[i].settotaltime(15.6);
				}
				else if (internation[i].arrival_country == "Spain") {
					internation[i].settotaltime(15.0);
				}
				else if (internation[i].arrival_country == "Mexico") {
					internation[i].settotaltime(16.5);
				}
				else if (internation[i].arrival_country == "Indonesia") {
					internation[i].settotaltime(12.3);
				}
				else if (internation[i].arrival_country == "Netherlands") {
					internation[i].settotaltime(14.6);
				}
				else if (internation[i].arrival_country == "Saudi Arabia") {
					internation[i].settotaltime(12.5);
				}
				else if (internation[i].arrival_country == "Switzerland") {
					internation[i].settotaltime(19.4);
				}
				else if (internation[i].arrival_country == "Turkey") {
					internation[i].settotaltime(11.0);
				}
				else if (internation[i].arrival_country == "Poland") {
					internation[i].settotaltime(13.6);
				}
				else if (internation[i].arrival_country == "Sweden") {
					internation[i].settotaltime(09.9);
				}
				else if (internation[i].arrival_country == "Belgium") {
					internation[i].settotaltime(08.0);
				}
				else if (internation[i].arrival_country == "Iran") {
					internation[i].settotaltime(04.0);
				}
				else if (internation[i].arrival_country == "Norway") {
					internation[i].settotaltime(14.6);
				}

				else if (internation[i].arrival_country == "Austria") {
					internation[i].settotaltime(22.2);
				}
				else if (internation[i].arrival_country == "UAE") {
					internation[i].settotaltime(48.5);
				}

			}
			break;
		case '5':
			for (int i = 0; i < 5; i++) {

				internation[i].getlocal(1);
				internation[i].setlocal(internation[i].getlocal(1) + h);

				int random = rand() % 25;
				internation[i].arrival_country = internation[i].getinternational(random);
				if (internation[i].arrival_country == "United States") {
					internation[i].settotaltime(20.0);
				}

				else if (internation[i].arrival_country == "China") {
					internation[i].settotaltime(2.5);

				}
				else if (internation[i].arrival_country == "Japan") {
					internation[i].settotaltime(23.0);
				}

				else if (internation[i].arrival_country == "Germany") {
					internation[i].settotaltime(24.0);
				}
				else if (internation[i].arrival_country == "United Kingdom") {
					internation[i].settotaltime(21.0);
				}
				else if (internation[i].arrival_country == "Italy") {
					internation[i].settotaltime(18.0);
				}
				else if (internation[i].arrival_country == "Canada") {
					internation[i].settotaltime(24.0);
				}
				else if (internation[i].arrival_country == "South Korea") {
					internation[i].settotaltime(17.5);
				}
				else if (internation[i].arrival_country == "Australia") {
					internation[i].settotaltime(23.5);
				}
				else if (internation[i].arrival_country == "Russia") {
					internation[i].settotaltime(15.6);
				}
				else if (internation[i].arrival_country == "Spain") {
					internation[i].settotaltime(15.0);
				}
				else if (internation[i].arrival_country == "Mexico") {
					internation[i].settotaltime(16.5);
				}
				else if (internation[i].arrival_country == "Indonesia") {
					internation[i].settotaltime(12.3);
				}
				else if (internation[i].arrival_country == "Netherlands") {
					internation[i].settotaltime(14.6);
				}
				else if (internation[i].arrival_country == "Saudi Arabia") {
					internation[i].settotaltime(12.5);
				}
				else if (internation[i].arrival_country == "Switzerland") {
					internation[i].settotaltime(19.4);
				}
				else if (internation[i].arrival_country == "Turkey") {
					internation[i].settotaltime(11.0);
				}
				else if (internation[i].arrival_country == "Poland") {
					internation[i].settotaltime(13.6);
				}
				else if (internation[i].arrival_country == "Sweden") {
					internation[i].settotaltime(09.9);
				}
				else if (internation[i].arrival_country == "Belgium") {
					internation[i].settotaltime(08.0);
				}
				else if (internation[i].arrival_country == "Iran") {
					internation[i].settotaltime(04.0);
				}
				else if (internation[i].arrival_country == "Norway") {
					internation[i].settotaltime(14.6);
				}

				else if (internation[i].arrival_country == "Austria") {
					internation[i].settotaltime(22.2);
				}
				else if (internation[i].arrival_country == "UAE") {
					internation[i].settotaltime(48.5);
				}

			}
			break;
		}
		internation[0].setdeparture(3.0);
		internation[1].setdeparture(5.0);
		internation[2].setdeparture(11.0);
		internation[3].setdeparture(17.0);
		internation[4].setdeparture(24.0);

		cout << fixed << setprecision(2);
		cout << h << "departure Airpot" << "         " << "Arrival airport" << "         " << "departure time " << "         " << "Arrival time " << "          " << "     total time  " << endl;
		for (int t = 0; t < 5; t++) {
			internation[t].setarrivaltime(internation[t].getdeparture_time() + internation[t].gettotaltime());

			cout << internation[t].getlocalcountry() << "\t\t\t" << internation[t].getarrival() << "\t\t\t" << internation[t].getdeparture_time() << "\t\t\t" << internation[t].getarrivaltime() << "\t\t\t" << internation[t].gettotaltime() << endl;

		}
	}
	void totaldisplay() {
		cout << fixed << setprecision(2);
		cout << h << "departure Airpot" << "         " << "Arrival airport" << "         " << "departure time " << "         " << "Arrival time " << "          " << "     total time  " << endl;
		for (int t = 0; t < 5; t++) {
			internation[t].setarrivaltime(internation[t].getdeparture_time() + internation[t].gettotaltime());

			cout << internation[t].getlocalcountry() << "\t\t\t" << internation[t].getarrival() << "\t\t\t" << internation[t].getdeparture_time() << "\t\t\t" << internation[t].getarrivaltime() << "\t\t\t" << internation[t].gettotaltime() << endl;

		}
	}
};

int  international::buisiness_seat = 10;
int  international::economy_seat = 50;
class local {
	flight_s* fls;
public:
	string h;
	static int economy_seat;
	static int buisiness_seat;
	local() {
		fls = new flight_s[10];
	}
	flight_s getflight_shedule(int i) {
		return fls[i];
	}
	void display() {
		srand(time(0));
		char x;
		char i;
			int k = 1;

		cout << "select departure airport :\n";
		do {
			cout << "1. ISLAMABAD\n";
			cout << "2. QUETTA\n";
			cout << "3. KARACHI\n";
			cout << "4. PESHAWAR \n";
			cout << "5. LAHORE\n";
			cout << "enter valid id ";
			cin >> x;
		} while (x != '1' && x != '2' && x != '3' && x != '4' && x != '5');
		cout << "select north or south\n";
		cout << "1. north\n 2.south";
		do {
			if (k >= 2) {
				cout << "please enter vlaid no";
			}
			cin >> i;
			if (i == '1') {
				h = "N0RTH";
			}
			if (i == '2')
			{
				h = "SOUTH";
			}
			k++;
		} while (i != '1' && i != '2');
		switch (x) {
		case '1':
			for (int i = 0; i < 10; i++) {
				fls[i].getlocal(4);
				fls[i].setlocal(fls[i].getlocal(4) + h);
				fls[i].setarray(4);
				int random = rand() % 3;
				fls[i].arrival_country = fls[i].getlocal(random);

				if (fls[i].arrival_country == "karachi") {
					fls[i].settotaltime(1.5);
				}
				else if (fls[i].arrival_country == "peshawar") {
					fls[i].settotaltime(0.6);

				}
				else if (fls[i].arrival_country == "lahore") {
					fls[i].settotaltime(0.5);
				}

				else if (fls[i].arrival_country == "QUETTA") {
					fls[i].settotaltime(1.2);
				}
			}

			break;
		case '2':
			for (int i = 0; i < 10; i++) {
				fls[i].getlocal(3);
				fls[i].setarray(3);
				fls[i].setlocal(fls[i].getlocal(4) + h);
				int random = rand() % 3;
				fls[i].arrival_country = fls[i].getlocal(random);
				if (fls[i].arrival_country == "karachi") {
					fls[i].settotaltime(0.8);
				}

				else if (fls[i].arrival_country == "peshawar") {
					fls[i].settotaltime(1.5);

				}
				else if (fls[i].arrival_country == "lahore") {
					fls[i].settotaltime(1.2);
				}

				else if (fls[i].arrival_country == "ISLAMABAD") {
					fls[i].settotaltime(1.5);
				}
			}
			break;
		case '3':
			for (int i = 0; i < 10; i++) {
				fls[i].getlocal(2) + h;
				fls[i].setarray(2);
				fls[i].setlocal(fls[i].getlocal(4) + h);
				int random = rand() % 3;
				fls[i].arrival_country = fls[i].getlocal(random);
				if (fls[i].arrival_country == "QUETTA") {
					fls[i].settotaltime(0.8);
				}

				else if (fls[i].arrival_country == "peshawar") {
					fls[i].settotaltime(1.1);

				}
				else if (fls[i].arrival_country == "lahore") {
					fls[i].settotaltime(1.2);
				}

				else if (fls[i].arrival_country == "ISLAMABAD") {
					fls[i].settotaltime(1.5);
				}
			}
			break;

		case '4':
			for (int i = 0; i < 10; i++) {

				fls[i].getlocal(0) + h;
				fls[i].setarray(0);
				fls[i].setlocal(fls[i].getlocal(4) + h);
				int random = rand() % 3;
				fls[i].arrival_country = fls[i].getlocal(random);
				if (fls[i].arrival_country == "QUETTA") {
					fls[i].settotaltime(1.2);
				}

				else if (fls[i].arrival_country == "karachi") {
					fls[i].settotaltime(1.5);

				}
				else if (fls[i].arrival_country == "lahore") {
					fls[i].settotaltime(0.5);
				}

				else if (fls[i].arrival_country == "ISLAMABAD") {
					fls[i].settotaltime(0.6);
				}

			}
			break;
		case '5':

			for (int i = 0; i < 10; i++) {
				fls[i].getlocal(1) + h;
				fls[i].setarray(1);
				fls[i].setlocal(fls[i].getlocal(4) + h);
				int random = rand() % 3;
				fls[i].arrival_country = fls[i].getlocal(random);
				if (fls[i].arrival_country == "QUETTA") {
					fls[i].settotaltime(1.2);
				}

				else if (fls[i].arrival_country == "karachi") {
					fls[i].settotaltime(1.5);

				}
				else if (fls[i].arrival_country == "ISLAMABAD") {
					fls[i].settotaltime(0.5);
				}

				else if (fls[i].arrival_country == "peshawar") {
					fls[i].settotaltime(0.6);
				}
			}
			break;
		}

		fls[0].setdeparture(0.0);
		fls[1].setdeparture(2.0);
		fls[2].setdeparture(6.0);
		fls[3].setdeparture(8.0);
		fls[4].setdeparture(10.2);
		fls[5].setdeparture(12.1);
		fls[6].setdeparture(14.5);
		fls[7].setdeparture(16.6);
		fls[8].setdeparture(18.3);
		fls[9].setdeparture(23.4);

		cout << fixed << setprecision(2);
		cout << h << "departure Airpot" << "         " << "Arrival airport" << "         " << "departure time " << "         " << "Arrival time " << "          " << "     total time  " << endl;
		for (int t = 0; t < 10; t++) {
			fls[t].setarrivaltime(fls[t].getdeparture_time() + fls[t].gettotaltime());

			cout << fls[t].getlocalcountry() << "\t\t\t" << fls[t].getarrival() << "\t\t\t" << fls[t].getdeparture_time() << "\t\t\t" << fls[t].getarrivaltime() << "\t\t\t" << fls[t].gettotaltime() << endl;

		}
	}
	void displaytotal() {
		cout << fixed << setprecision(2);
		cout << h << "departure Airpot" << "         " << "Arrival airport" << "         " << "departure time " << "         " << "Arrival time " << "          " << "     total time  " << endl;
		for (int t = 0; t < 10; t++) {
			fls[t].setarrivaltime(fls[t].getdeparture_time() + fls[t].gettotaltime());

			cout << fls[t].getlocalcountry() << "\t\t\t" << fls[t].getarrival() << "\t\t\t" << fls[t].getdeparture_time() << "\t\t\t" << fls[t].getarrivaltime() << "\t\t\t" << fls[t].gettotaltime() << endl;

		}

	}

};
int  local::buisiness_seat = 10;
int  local::economy_seat = 50;
class booking {
	string newemail;
	string newname;
	string new_cnic;
	userdata * us;
	local loc;
	international inter;
	int x = us->getno_of_passenger();
	int h = us->getno_of_admin();

public:
	booking() {
		us = new userdata[x];
	}
	string getnewemail() {
		return  newemail;
	}
	string getnewname() {
		return newname;
	}
	string getnew_cnic() {
		return new_cnic;
	}
	bool passport() {
		cout  << "do you have inter national passport and visa stamped yes or not Y/N ";
		char ch;
		cin >> ch;
		if (tolower(ch) == 'y') {
			return true;

		}
		else
			return 0;
			
	}
	//reshedule function for local
	void flight_reshedulelocal(local &loc ){
		double depart;
		int k;
		cout << fixed << setprecision(2);
		cout << "departure Airpot" << "         " << "Arrival airport" << "         " << "departure time " << "         " << "Arrival time " << "          " << "     total time  " << endl;
		for (int i = 0; i < 10; i++) {
			cout << i + 1 << ".   " << loc.getflight_shedule(i).getlocalcountry() << "\t\t" << loc.getflight_shedule(i).getarrival() << "\t" << loc.getflight_shedule(i).getdeparture_time() << "\t\t" << loc.getflight_shedule(i).getarrivaltime() << "\t" << loc.getflight_shedule(i).gettotaltime() << endl;
		}
		cout << "\n\nenter the id of flight you want to reshedule";
		cin >> k;
		cout << "enter the resheduled departure time ";
		cin >> depart ;
		cout << "the following fligth is resheduled";
		loc.getflight_shedule(k).setdeparture(depart);
		cout << fixed << setprecision(2);
		cout << h << "departure Airpot" << "         " << "Arrival airport" << "         " << "departure time " << "         " << "Arrival time " << "          " << "     total time  " << endl;
			cout  << ".   " << loc.getflight_shedule(k).getlocalcountry() << "\t\t" << loc.getflight_shedule(k).getarrival() << "\t" << depart << "\t\t" << depart+ loc.getflight_shedule(k).gettotaltime() << "\t" << loc.getflight_shedule(k).gettotaltime() << endl;
	}
	void flight_resheduleinternational(international& inter) {
		double depart;
		int k;
		cout << fixed << setprecision(2);
		cout << "departure Airpot" << "         " << "Arrival airport" << "         " << "departure time " << "         " << "Arrival time " << "          " << "     total time  " << endl;
		for (int i = 0; i < 5; i++) {
			cout << i + 1 << ".   " << inter.getflight_international(i).getlocalcountry() << "\t\t" << inter.getflight_international(i).getarrival() << "\t" << inter.getflight_international(i).getdeparture_time() << "\t\t" << inter.getflight_international(i).getarrivaltime() << "\t" << inter.getflight_international(i).gettotaltime() << endl;
		}
		cout << "\n\nenter the id of flight you want to reshedule";
		cin >> k;
		cout << "enter the resheduled departure time ";
		cin >> depart;
		cout << "the following fligth is resheduled";
		cout << fixed << setprecision(2);
		inter.getflight_international(k).setdeparture(depart);
		
		cout << h << "departure Airpot" << "         " << "Arrival airport" << "         " << "departure time " << "         " << "Arrival time " << "          " << "     total time  " << endl;
		cout  << ".   " << inter.getflight_international(k).getlocalcountry() << "\t\t" << inter.getflight_international(k).getarrival() << "\t" << depart << "\t\t" << depart+ inter.getflight_international(k).gettotaltime() << "\t" << inter.getflight_international(k).gettotaltime() << endl;
	}
	//reshedule function for international
	void seat_reservation_international(userdata& obj, international& inter)
	{
		int k, type, sea;
		cout << fixed << setprecision(2);
		cout << h << "departure Airpot" << "         " << "Arrival airport" << "         " << "departure time " << "         " << "Arrival time " << "          " << "     total time  " << endl;
		for (int i = 0; i < 5; i++) {
			cout << i + 1 << ".   " << inter.getflight_international(i).getlocalcountry() << "\t\t" << inter.getflight_international(i).getarrival() << "\t" << inter.getflight_international(i).getdeparture_time() << "\t\t" << inter.getflight_international(i).getarrivaltime() << "\t" << inter.getflight_international(i).gettotaltime() << endl;
		}
		cout << "Please enter valid id for todays fligth" << endl;
		cin >> k;
		 {
			cout << "departure country =" << inter.getflight_international(k - 1).getlocalcountry() << endl;
			cout << "arrival country   =" << inter.getflight_international(k - 1).getarrival() << endl;
			cout << "departure time   =" << inter.getflight_international(k - 1).getdeparture_time() << endl;
			cout << "arrival time    =" << inter.getflight_international(k - 1).getarrivaltime() << endl;
			cout << "\nenter the passenger name that has to take flight   = ";
			cin >> newname;
			cout << "\n\n enter the passenger email that has to take flight ";
			cin >> newemail;
			cout << "\n\nenter cnic";
			cin >> new_cnic;
		}
		cout << "enter seat type \n 1.economical \n 2.bussines class ";
		cin >> type;
		switch (type) {
		case 1:

			cout << "\n no of avaliable seats are     =   " << inter.economy_seat << endl;
			cout << "\nenter no of seats ";
			cin >> sea;
			if (sea < inter.economy_seat) {
				inter.economy_seat = inter.economy_seat - sea;
				cout << "bill is  =" << (20000 * sea) * (inter.getflight_international(k - 1).gettotaltime());
				cout << "do youant to confirm \n1.confirm\n2.exit ";
				cin >> type;
				if (type == 1) {
					obj.getno_of_login(obj.getvalueelogin());
					cout << "\n\n////////////.................Reciept......................../////////\n\n\n";
					cout << "name    =" << newname << endl;
					cout << "cnic       =" << new_cnic << endl;
					cout << "email      =" << newemail << endl;
					cout << "Ticket type == Econical class       =" << endl;
					cout << "flight info";
					cout << "departure country =" << inter.getflight_international(k - 1).getlocalcountry() << endl;
					cout << "arrival country   =" << inter.getflight_international(k - 1).getarrival() << endl;
					cout << "departure time   =" << inter.getflight_international(k - 1).getdeparture_time() << endl;
					cout << "arrival time    =" << inter.getflight_international(k - 1).getarrivaltime() << endl;
					cout << "bill payed is  =" << (20000 * sea) * (inter.getflight_international(k - 1).gettotaltime());
					cout << "\n\n\n\nDO you want to cancle tickets ?\n1.Cancel\n any key to confirmed";
					cin >> type;
					if (type == 1) {
						cout << "name    =" << newname << endl;
						cout << "cnic       =" << new_cnic << endl;
						cout << "email      =" << newemail << endl;
						cout << "Ticket type == Econical class       =" << endl;
						cout << "\nenter no of seats ";
						cin >> sea;
						cout << "has cancel the ticket \n";
						cout << "amout after 25 % curcharges are  =" << (20000 * sea) * (inter.getflight_international(k - 1).gettotaltime()) * 0.75;
						inter.economy_seat = inter.economy_seat + sea;

					}

				}
				else
					cout << "\nticket connfirmed\n";
			}
			else
				cout << "we have less no of seats ";

			break;
		case 2:
			cout << "avalible seats are  =  " << inter.buisiness_seat;
			cout << "\nenter no of seats ";
			cin >> sea;
			if (sea < inter.buisiness_seat) {
				inter.buisiness_seat = inter.buisiness_seat - sea;
				cout << "bill is  =" << (20000 * sea) * (inter.getflight_international(k - 1).gettotaltime());
				cout << "do youant to confirm \n1.confirm\n2.exit ";
				cin >> type;
				if (type == 1) {
					obj.getno_of_login(obj.getvalueelogin());
					cout << "Reciept\n";
					cout << "name    =" << newname << endl;
					cout << "cnic       =" << new_cnic<< endl;
					cout << "email      =" << newemail << endl;
					cout << "Ticket type == Business class      =" << endl;
					cout << "flight info";
					cout << "departure country =" << inter.getflight_international(k - 1).getlocalcountry() << endl;
					cout << "arrival country   =" << inter.getflight_international(k - 1).getarrival() << endl;
					cout << "departure time   =" << inter.getflight_international(k - 1).getdeparture_time() << endl;
					cout << "arrival time    =" << inter.getflight_international(k - 1).getarrivaltime() << endl;
					cout << "bill payed is  =" << (20000 * sea) * (inter.getflight_international(k - 1).gettotaltime());

					cout << "\n\n\n\nDO you want to cancle tickets ?\n1.Cancel\n2.any key to confirmed ";
					cin >> type;
					if (type == 1) {
						cout << "name    =" << newname << endl;
						cout << "cnic       =" << new_cnic << endl;
						cout << "email      =" << newemail << endl;
						cout << "Ticket type == Bussines class class       =" << endl;
						cout << "\nenter no of seats ";
						cin >> sea;
						cout << "has cancel the ticket \n";
						cout << "amout after 25 % curcharges are  =" << (20000 * sea) * (inter.getflight_international(k - 1).gettotaltime()) * 0.75;
						inter.buisiness_seat = inter.buisiness_seat + sea;
					}
					else
						cout << "ticket confirmed";

				}
			}
			else
				cout << "you have less no of seats ";
			break;
		}

	}
	void seat_reservation_local(userdata& obj, local& fls) {
		int k;
		int sea;
		int type;
		cout << fixed << setprecision(2);
		cout << h << "departure Airpot" << "         " << "Arrival airport" << "         " << "departure time " << "         " << "Arrival time " << "          " << "     total time  " << endl;
		for (int i = 0; i < 10; i++) {
			cout << i + 1 << ".   " << fls.getflight_shedule(i).getlocalcountry() << "\t\t" << fls.getflight_shedule(i).getarrival() << "\t" << fls.getflight_shedule(i).getdeparture_time() << "\t\t" << fls.getflight_shedule(i).getarrivaltime() << "\t" << fls.getflight_shedule(i).gettotaltime() << endl;
		}
		do {
			cout << "Please enter valid id  =for todays fligth" << endl;

			cin >> k;
		} while (k > 10 && k < 1);

		 {
			cout << "departure country =" << fls.getflight_shedule(k - 1).getlocalcountry() << endl;
			cout << "arrival country   =" << fls.getflight_shedule(k - 1).getarrival() << endl;
			cout << "departure time   =" << fls.getflight_shedule(k - 1).getdeparture_time() << endl;
			cout << "arrival time    =" << fls.getflight_shedule(k - 1).getarrivaltime() << endl;
			cout<<"enter name of passenger";
			cin >> newname;
			cout << "\n\n enter the passenger email that has to take flight ";
			cin >> newemail;
			cout << "\n\nenter cnic";
			cin >> new_cnic;
		}
		cout << "enter seat type \n 1.economical \n 2.bussines class ";
		cin >> type;
		switch (type) {
		case 1:
			cout << "avaliable seats are  =  "<<fls.economy_seat;
			cout << "\nenter no of seats ";
			cin >> sea;
			if (sea < fls.economy_seat) {
				fls.economy_seat = fls.economy_seat - sea;
				cout << "bill is  =" << (10000 * sea) * (fls.getflight_shedule(k - 1).gettotaltime());
				cout << "do youant to confirm \n1.confirm\n2.exit ";
				cin >> type;
				if (type == 1) {
					obj.getno_of_login(obj.getvalueelogin());
					cout << "Reciept\n";
					cout << "name    =" << newname << endl;
					cout << "cnic       =" << new_cnic << endl;
					cout << "email      =" << newemail << endl;
					cout << "Ticket type == Econical class       =" << endl;
					cout << "flight info";
					cout << "departure country =" << fls.getflight_shedule(k - 1).getlocalcountry() << endl;
					cout << "arrival country   =" << fls.getflight_shedule(k - 1).getarrival() << endl;
					cout << "departure time   =" << fls.getflight_shedule(k - 1).getdeparture_time() << endl;
					cout << "arrival time    =" << fls.getflight_shedule(k - 1).getarrivaltime() << endl;
					cout << "bill payed is  =" << (20000 * sea) * (fls.getflight_shedule(k - 1).gettotaltime());
					cout << "\n\n\n\nDO you want to cancle tickets ?\n1.Cancel2.go with ticket";
					cin >> type;
					if (type == 1) {
						cout << "name    =" << newname << endl;
						cout << "cnic       =" << new_cnic << endl;
						cout << "email      =" << newemail << endl;
						cout << "Ticket type == Econical class       =" << endl;
						cout << "\nenter no of seats ";
						cin >> sea;
						cout << "has cancel the ticket \n";
						cout << "Amount return after 25% of surcharges are" << ((10000 * sea) * (fls.getflight_shedule(k - 1).gettotaltime())) * 0.75;
						fls.economy_seat = sea + fls.economy_seat;
					}
				}

			}
			else
				cout << "their is less no of seats ";

			break;
		case 2:
			cout << "avaliable seats are  =  " << fls.buisiness_seat;
			cout << "\nenter no of seats ";
			cin >> sea;
			if (sea < fls.buisiness_seat) {
				fls.buisiness_seat = fls.buisiness_seat - sea;
				cout << "bill is  =" << (10000 * sea) * (fls.getflight_shedule(k - 1).gettotaltime());
				cout << "do youant to confirm \n1.confirm\n2.exit ";
				cin >> type;
				if (type == 1) {
					obj.getno_of_login(obj.getvalueelogin());
					cout << "Reciept\n";
					cout << "name    =" << newname << endl;
					cout << "cnic       =" << new_cnic << endl;
					cout << "email      =" << newemail << endl;
					cout << "Ticket type == Bussines class class       =" << endl;
					cout << "flight info";
					cout << "departure country =" << fls.getflight_shedule(k - 1).getlocalcountry() << endl;
					cout << "arrival country   =" << fls.getflight_shedule(k - 1).getarrival() << endl;
					cout << "departure time   =" << fls.getflight_shedule(k - 1).getdeparture_time() << endl;
					cout << "arrival time    =" << fls.getflight_shedule(k - 1).getarrivaltime() << endl;
					cout << "bill payed is  =" << (10000 * sea) * (fls.getflight_shedule(k - 1).gettotaltime());
					cout << "\n\n\n\nDO you want to cancle tickets ?\n1.Cancel2.go with ticket";
					cin >> type;
					if (type == 1) {
						cout << "name    =" << newname << endl;
						cout << "cnic       =" << new_cnic << endl;
						cout << "email      =" << newemail << endl;
						cout << "Ticket type == Bussines class class       =" << endl;
						cout << "\nenter no of seats ";
						cin >> sea;
						cout << "has cancel the ticket \n";
						cout << "Amount return after 25% of surcharges are" << ((10000 * sea) * (fls.getflight_shedule(k - 1).gettotaltime())) * 0.75;
						fls.buisiness_seat = sea + fls.buisiness_seat;
					}
				}

			}
			else
				cout << "you have less no of seats ";
			break;
		}

	}
};

int main() {
	cout << "/t/t/t --------NUCES AIRLINE FLIGHT RESERVATION SYSTEM-------/t/t\n";
	bool u = false, ad = false;
	userdata userd;
	local fls;
	booking BOO;
	international inter;
	cout << "LOCAL FLIGTHs\n";
	fls.display();
	cout << "\n\nINTERNATIONAL FLIGTH ";
	inter.display();
	char choice;
	while (true) {
		cout << "Welcome to NUCES Airline Flight System (NAFS)" << endl;
		cout << "Please choose an option from the menu below: " << endl;
		cout << "1. register new user" << endl;
		cout << "2. login " << endl;
		cout << "3. Flight Reservation" << endl;
		cout << "4. Flight reshedule" << endl;
		cout << "5. Flight Schedule" << endl;
		cout << "6. Fligth cancellation" << endl;
		cout << "7. About NAFS" << endl;
		cout << "8. complains" << endl;
		cout << "9. contact us" << endl;
		cout << "//////////////////////////////// press E to Exit/////////////////////////////////////////" << endl;
		cout << " Enter your choice : ";
		cin >> choice;
		switch (choice) {
		case '1':
			cout << "You have selected regesteration as a new user\n";
			cout << "\n1. register new passenger" << endl;
			cout << "\n2. register new staff " << endl;
			cout << "\n3. to exit " << endl;
			char x;
			do {
				cin >> x;
			} while (x != '1' && x != '2' && x != '3');
			switch (x) {
			case '1':
				cout << ":add a newpassenger" << endl;
				userd.addpassenger();
				break;
			case '2':
				cout << ":add a newpassenger" << endl;
				userd.addamin();
				break;
			case '3':
				continue;
			}
			break;
		case '2':

			char choise;
			cout << "You have logedin to following \n\n\n." << endl;
			cout << "1.passenger login\n 2.admin login\n\n";
			do {
				cout << "enter valid id ";
				cin >> choise;
			} while (choise != '1' && choise != '2');
			switch (choise) {
			case '1':
				u = userd.loginpassenger();
				
				break;

			case '2':

				ad = userd.loginadmin();
				

				break;
			}

			break;
		case '3':
		char c;
			if (u == 1) {
				do {
					cout << "for local fligth reservation\n1. local fligth\n2.international fligth";
					do {
						cin >> c;
					} while (c != '1'&& c != '2');
					switch (c){
					case '1':
						cout << "You have selected local Flight Reservation." << endl;
					BOO.seat_reservation_local(userd, fls);
					break;
					case '2':
					  
						cout << "You have selected international Flight Reservation." << endl;
						if (BOO.passport() == 1) {
							BOO.seat_reservation_international(userd, inter);
						}
						break;
					}

				} while (c != '1' && c != '2');
			}
			else
				cout << "please login 1st as a passenger/n";
			break;

			
		case '4':
			char choic;
			if (ad == 1) {
				cout << "enter the flight type you want to reshedule it ." << endl;
				cout << "1.For local \n 2.For international";
				do {
					cin >> choic;
				} while (choic!='1'&& choic!='2');
				switch (choic) {
				case '1': 
					BOO.flight_reshedulelocal(fls);
				
						break;

				case '2':
					BOO.flight_resheduleinternational(inter);
					break;
				}
			}
			else
				cout << "please login 1st as admin panel\n";
			break;
		case '5':
			char y;
			cout << "You have selected Flight Schedule." << endl;
			cout << "1.LOCAL FLIGHT\n2.INTERNATIONAL FLIGHT";
			do {
				cout << "enter valid id ";
				cin >> y;
			} while (y != '1' && y != '2');
			if (y == '1')
			{
				cout << "LOCAL FLIGTHs\n";
				fls.displaytotal();
			}
			else if (y == '2')
			{
				cout << "\n\nINTERNATIONAL FLIGTH ";
				inter.totaldisplay();
			}

			break;
		case '6':
			cout << "You have selected Account Details." << endl;
			break;
		case '7':
			cout << "Welcome to NUCES Airline Flight System (NAFS)." << endl;
			cout << "NAFS is functional in five major cities of Pakistan: Islamabad, Lahore, Quetta, Peshawar, and Karachi." << endl;
			cout << "Each city has two airports located at the North and South." << endl;
			cout << "NAFS has a total of 50 airplanes, with 10 airplanes in each city." << endl;
			cout << "A maximum of 5 airplanes can land at a time in an airport." << endl;
			cout << "NAFS has established a network of flights in 25 countries around the globe." << endl;
			cout << "Due to the COVID situation, some countries have travel bans." << endl;
			cout << "NAFS greatly values its passengers and abides by the international traveling laws." << endl;
			cout << "50,000 passengers use NAFS annually." << endl;
			cout << "Ten Local flights and Five International flights take off from each airport daily depending on their schedule." << endl;
			cout << "Each plane of NAFS has a seating capacity of 50 passengers in economy class and 10 in business class." << endl;
			cout << "During the COVID days, passengers are seated with a gap of one seat." << endl;

			break;
		case '8':
			char r;
			cout << "1.To complain \n any other key to exit" << endl;
			cin >> r;
			if (r == '1') {
				cout << "Enter complain on email  =  Pia@grc21  click here to send mail\n";

			}
			else
				break;
			break;
		case '9':
			cout << "Email" << "\t\t\t" << "contact no\t\t\twhatsapp number\t\t\t\n";
			cout << "Pia@grc21\t\t051-234568\t\t\t0300000000000000\n\n\n";
			break;
		case 'e':
			cout << "Thanks for chosing NAFS services";
			return 0;
		default:
			cout << "\n\n\nInvalid choice. Please choose again.\n\n\n" << endl;
			break;
		}

		cout << endl;
	}
}
