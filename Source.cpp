#include <iostream>
#include <iomanip>
using namespace std;
#undef NULL

/*
Jake Davis
CS 215 J001
Spring 2014
Programming Assignment #2
*/

/*
When prompted the user will select an option from the menu into a character called
answer. The function called will be dependent on what answer is set equal to. If ‘e’ is
chosen, the ReadBackwards function will be called to input numbers. If ‘m’ is
chosen, the function MultiplyVegisimal will be called to multiply the current list. If ‘a’
is chosen, the function AddVegisimal will be called to add the current list to new
vegisimal numbers. If ‘h’ is called the menu will be shown. If ‘q’ is called the program
will quit.
*/

typedef int element; //element equals int
const int NULL = 0; // Null is set to 0
const char Sentinel = '#'; //Sentinel value to stop

class listnode{
public:
	element data;
	listnode* next;
};

class LList{
private:
	listnode* head;
	listnode* tail;
public:
	LList();
	~LList();
	void ReadBackwards();
	void Clean();
	void ConvertBack();
	void Menu();
	void AddMultiply();
	void PrintInReverse();
	void AddVigesimal();
	char Read_element();
	void Vigesimalinput();
	void MultiplyVigesimal();
	void HelpMenu();
	void Print();
	void Read();
	void Outputquit();
	void InsertTail(element);
	void InsertHead(element);
	void duplicate(LList &);
	void steal(LList &);
	void ConvertAscii();
	void reverse();
};

int main(){
	LList A;

	cout << "\n""Vigesimal Calculator, Version 1.0" << endl;
	cout << "(c) 2014, Jake Davis" << endl;
	cout << endl;

	A.Menu();

	return 0;

}

LList::LList(){
	//PRE: none
	//Post: the N.o. LList is valid and empty

	head = NULL;
}

LList::~LList(){
	//PRE: N.O. LList is valid
	//Post: N.O.LList is valid and empty
	//all memory for its listnodes have been return to the heap.

	Clean();
}

void LList::Clean(){
	//Pre: the N.o.LList is valid
	//Post: The N.O. LList is valid
	//and empty and all of the memory
	//for its listnodes has been returned
	//to the system memory pool (the "heap")
	listnode* temp; //temp is a listnode
	while (head != NULL){
		temp = head; //head is set equal to temp
		head = head->next; //head equals head pointing to next
		delete temp; //temp is deleted
	}
}

void LList::steal(LList & victim){
	//The N.O. and victim LList are valid
	//except all of the N.O.'s original listnodes were
	//giving back to the heap,all of the victim's
	//listnodes now are on the N.O., and victim is empty
	Clean();

	head = victim.head; //head equals the victims head

	tail = victim.tail; //tail equals the victims tail

	victim.head = NULL; //head is equal to 0

}

//This function will read the N.O. backwards
void LList::ReadBackwards(){
	//PRE: none
	//Post: Same of read forward exepct backwards
	//instead of forward
	element userval; //value from Read_element()
	listnode* temp; //temp is a listnode

	Clean();
	cout << "Enter a vigesimal number, followed by " << Sentinel << ":";
	userval = Read_element();
	//Will not run if equal to #
	while (userval != Sentinel){
		temp = new listnode;
		temp->data = userval;
		temp->next = head;
		if (head == NULL)
			tail = temp;
		else
			;
		head = temp;
		userval = Read_element();
	}
}


void LList::reverse(){
	//PRe: the N.o. LList valid
	//Post: the N.O. and source LLists are unchaneged except the 
	//n.O.'s original listnodes have been giving back to the 
	//heap, and the N.O. is now listnode-by list node duplicated
	//of the source unchaged except its elements are now in 
	//reverse order

	LList helper; //Will not change N.O.
	listnode * temp; //temp will be used to reverse the LList
	temp = head;
	while (temp != NULL){

		helper.InsertHead(temp->data);
		temp = temp->next;
	}
	steal(helper);

}
void LList::duplicate(LList & source){
	//PRe: the N.o. LList valid
	//Post: the N.O. and source LLists are unchaneged except the 
	//n.O.'s original listnodes have been giving back to the 
	//heap, and the N.O. is now listnode-by list node duplicated
	//of the source

	listnode * temp;

	Clean();

	temp = source.head;

	while (temp != NULL){

		InsertTail(temp->data);

		temp = temp->next;

	}

}

void LList::AddVigesimal(){
	//PRE:the N.O. LList is valid
	//Post: The native object is added with helper

	LList helper;
	LList combo;

	int remainder = 0; //Will be carried over depending on what is
					   //inputted
	int number; //temp1 + temp2 will be the outcome of the two
				//LLists added together

	helper.ReadBackwards();
	helper.reverse();

	listnode * temp1;

	listnode * temp2;

	listnode * temp3;

	temp1 = head; 

	temp2 = helper.head;

	temp3 = combo.head;

	ConvertAscii();

	helper.ConvertAscii();

	while ((temp1 != NULL)&&(temp2!=NULL)){
		number = (temp1->data) + (temp2->data) + remainder;
		remainder = 0;
		//If number is base 20
		//Number will be subtracted by 20
		//example:
		//13+20=33(number)
		//33-20=13
		//13=D
		//remainder is 1 (1D)
		while (number > 19){
			number = number - 20;
			remainder++;
		}
		combo.InsertTail(number);
		number = 0;		

		temp1 = temp1->next;
		temp2 = temp2->next;
	}
	duplicate(combo);// should change the native object to combo
	helper.Clean();
}

void LList::MultiplyVigesimal(){
	//multiply the number to the current vigesimal num linked list
	//easy way to do multiplication 
	LList helper;
	LList Orig;



	helper.ReadBackwards();
	helper.ConvertAscii();


	listnode * temp1 = head;
	listnode * temp2 = helper.head;
	listnode * temp3;

	int counter = 0; 
	
	int first;

		//take the number you are multiplying
		//by and break it up 

		//173 * 84 = 14532

		//= (173*4) + (173 * 80) = 14532

		//= (173*4) + (173 * 8 * 10) = 14532

		//= (173 * 4) + (1730 * 8) = 14532

		// call the add method to add 173 to 
		// itself 4 time then add 1730 

		//In a for loop
	

	
	//use division and % for adding the numbers together 


	// call addvigesimalnum() to find the value of the newest input number


}

void LList::AddMultiply(){

	LList helper;
	LList combo;

	int remainder = 0;
	int number;
	int value = 0;

	listnode * temp1;

	listnode * temp2;

	listnode * temp3;

	temp1 = head;

	temp2 = helper.head;

	temp3 = combo.head;

	ConvertAscii();

	while ((temp1 != NULL) && (temp2!= NULL)){
		number = (temp1->data) + (temp2->data) + remainder;
		remainder = 0;
		while (number > 19){
			number = number - 20;
			remainder++;
		}
		cout << number << endl;
		InsertTail(number);
		number = 0;

		temp1 = temp1->next;
	}
	duplicate(combo);// should change the native object to combo
	helper.Clean();
}

void LList::InsertTail(element val){
	//PRE: the N.O. LList is valid
	//Post: The N.O. Llist is unchanged
	//except it now contains a new listnode at
	//its head end containing the thing
	listnode* temp;
	temp = new listnode;
	temp->data = val;
	temp->next = NULL;
	if (head == NULL)
		head = temp;
	else{
		tail->next = temp;
	}
	tail = temp;

}
void LList::InsertHead(element val){
	//PRE: the N.O. LList is valid
	//Post: The N.O. Llist is unchanged
	//except it now contains a new listnode at
	//its head end containing the thing

	listnode* temp;

	temp = new listnode;

	temp->data = val;

	temp->next = head;

	if (head == NULL)

		tail = temp;

	else

		;

	head = temp;

}

char LList::Read_element(){
	char val; //will check with ASCII code
	cin >> val;
	while (!cin.good()){
		cout << "Invalid response, should be a number 0-9 or a";
		cout << " letter A-J, try again: ";
		cin.clear();
		cin.ignore(80, '\n');
		cin >> val;
	}
	return val;
}

void LList::Menu(){
		int useranswer;//will be the command
		cout << endl;
		cout << "Current vigesimal number is:";
		Print();
		cout << endl;
		cout << "Command (h for help) : ";
		useranswer = Read_element();

		switch (useranswer){
		case 'E':
		case 'e':
			Vigesimalinput();
			reverse();
			Menu();
			break;
		case 'A':
		case 'a':
			AddVigesimal();
			Menu();
			break;
		case 'M':
		case 'm':
			MultiplyVigesimal();
			Menu();
			break;
		case 'H':
		case 'h':
			HelpMenu();
			Menu();
			break;
		case 'Q':
		case 'q':
			Outputquit();
			break;
		default:
			cout << "Invalid command";
			break;
		}
}

void LList::ConvertBack(){
	listnode * temp3;
	temp3 = head;
	int test; //will be the data of the listnode
	//Uses ConvertAscii to check the value
	//And convert it back to ASCII code
	while (temp3 != NULL){
		test = temp3->data;
		if ((test >= 0) && (test <= 9)){
			temp3->data = (temp3->data) + '0';
		}
		else if ((test >= 10) && (test <= 19)){
			temp3->data = (temp3->data) + 55;
		}
		temp3 = temp3->next;
	}

}
void LList::ConvertAscii(){
	//convert ASCII to Vigesimal values
	listnode * temp3;
	temp3 = head;
	char test; //data that temp is pointing to
	while (temp3 != NULL){
		test = temp3->data;
		if ((test >= 48) && (test <=57)){
			temp3->data = (temp3->data) - '0';
		}
		else if ((test >= 65) && (test <=74)){
			temp3->data = (temp3->data) - 'A' + 10;
		}
		temp3 = temp3->next;
	}

}
void LList::Vigesimalinput(){
	ReadBackwards();
}

void LList::Outputquit(){
	cout << "Finished Vigesimal Calculator, version 1.0" ;
	

}

void LList::HelpMenu(){
	//will output the valid commands the 
	//user can choose from when called
	cout << endl;
	cout << "Valid Commands are: " << endl;
	cout << setw(20) << "e enter    enter the current ";
	cout << setw(20) << "vigesimal number from the keyboard" << endl;
	cout << setw(20) << "a add      add a new vigesimal number to ";
	cout << setw(20) << "the current vig. number" << endl;
	cout << setw(20) << "m multiply multiply a new ";
	cout << setw(20) << "vigesimal number by ";
	cout << setw(20) << "the current vig. number" << endl;
	cout << setw(20) << "h help     show this help menu" << endl;
	cout << setw(20) << "q quit     quit the program" << endl;

	Menu();
}


void LList::Print(){ 
	//PRE: the N.O. List is valid
	//POST: the N.O is unchanged
	ConvertBack();
	char userval;
	for (listnode* temp = head; temp != NULL; temp = temp->next) {
		userval = temp->data;
		cout << userval;
		
		
	}
}