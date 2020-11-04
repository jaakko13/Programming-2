#include <iostream>
#include <string>
using namespace std;

class PersonData
{
private:
	string lastName;     
	string firstName;    
	string address;      
	string city;         
	string state;        
	string zip;          
	string phone;		

public:

	PersonData(string ln, string fn, string addr, string c, string s, string z, string ph)
	{
		lastName = ln;
		firstName = fn;
		address = addr;
		city = c;
		state = s;
		zip = z;
		phone = ph;
	}

	PersonData()
	{
		lastName = "";
		firstName = "";
		address = "";
		city = "";
		state = "";
		zip = "";
		phone = "";
	}
	void setLastName(string ln){
		lastName = ln;
	}
	void setFirstName(string fn){
		firstName = fn;
	}
	void setAddress(string addr){
		address = addr;
	}
	void setCity(string c){
		city = c;
	}
	void setState(string s){
		state = s;
	}
	void setZip(string z){
		zip = z;
	}
	void setPhone(string ph){
		phone = ph;
	}
	
	string getLastName() const{
		return lastName;
	}
	string getFirstName() const{
		return firstName;
	}
	string getAddress() const{
		return address;
	}
	string getCity() const{
		return city;
	}
	string getState() const{
		return state;
	}
	string getZip() const{
		return zip;
	}
	string getPhone() const{
		return phone;
	}
};


class CustomerData : public PersonData
{
private:
	int customerNumber;     
	bool mailingList;     

public:
	CustomerData(string ln, string fn, string addr, string c, string s, string z, string ph, int cn, bool ml) :
		PersonData(ln, fn, addr, c, s, z, ph){
		customerNumber = cn;
		mailingList = ml;
	}

	CustomerData() : PersonData(){
		customerNumber = 0;
		mailingList = false;
	}
	void setCustomerNumber(int cn){
		customerNumber = cn;
	}
	void setMailingList(bool ml){
		mailingList = ml;
	}
	int getCustomerNumber(){
		return customerNumber;
	}
	bool getMailingList(){
		return mailingList;
	}
};

class PreferredCustomer : public CustomerData {
private:
	double purchasesAmount;
	double discountLevel;
public:
	PreferredCustomer(double purch , double disc) {
		purchasesAmount = purch;
		discountLevel = disc;
	}
	PreferredCustomer() : CustomerData() {
		purchasesAmount = 0;
		discountLevel = 0;
	}

	void setPurchasesAmount(double purch) {
		purchasesAmount = purch;
	}
	void setDiscountLevel(double disc) {
		discountLevel = disc;
	}
	double getPurchasesAmount() {
		return purchasesAmount;
	}
	double getDiscountLevel() {
		return discountLevel;
	}
};

int main() {
	double disc = 0;
	double purch = -1;

	while (purch < 0)
	{
		cout << "Enter the amount of purchases made(dollar amount):";
		cin >> purch;
	}
	
	if (purch >= 500 && purch < 1000)
	{
		disc = 5;
	}
	else if(purch >= 1000 && purch < 1500)
	{
		disc = 6;
	}
	else if (purch >= 1500 && purch < 2000)
	{
		disc = 7;
	}
	else if (purch >= 2000)
	{
		disc = 10;
	}

	PreferredCustomer me(purch, disc);
	cout << "Purchase amount:" << me.getPurchasesAmount() << endl;
	cout << "Discount Level:" << me.getDiscountLevel() << "% discount on all future purchases." << endl;

}