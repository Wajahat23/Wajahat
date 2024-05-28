#include <iostream>
#include <string>
using namespace std;
void brf(int&,int&,int&,int&);
int main(){
	float r, a;
	string s, n, d;
	int i, num, left, cond1, b, k, no[7]={3, 6, 4, 9, 11, 7, 6}; 
	loop:
		cout<<"|===============================|"<<endl;
		cout<<"|      Welcome to Library       |"<<endl;
		cout<<"|===============================|"<<endl;
		st:
		cout<<"Select your occupation"<<endl<<"1. Student"<<endl<<"2. Teacher"<<endl<<"Enter the corresponding number : ";
		cin>>i;
		if(i==1){
    		cout<<"Please enter your roll no : ";
			cin>>r;
		    cout<<"Enter your age : ";	
		    cin>>a;
		    cin.ignore(1,'\n');
		    cout<<"Enter your Gender : ";
		    getline(cin,s);
		}
		else if(i==2){
			cin.ignore(1,'\n');
			cout<<"Please enter your name : ";
			getline(cin,n);
			cout<<"please enter your department name : ";
			getline(cin,d);
		}
		else{
			cout<<"Enter only 1 or 2"<<endl;
			goto st;
		}
		iban:
		cout<<"==========================================="<<endl;
		cout<<"     We have following types of book       "<<endl;
 		cout<<"==========================================="<<endl;
 		cout<<"Book 1 is : The world as i see it "<<endl;
		cout<<"The IBAN no. of book is 10 "<<endl;
 		cout<<"Book 2 is : The rise of Germany "<<endl;
 		cout<<"The IBAN no. of book is 20 "<<endl;
 		cout<<"Book 3 is : Nineteen eighty-four "<<endl;
 		cout<<"The IBAN no. of book is 30 "<<endl;
 		cout<<"Book 4 is : Kulliyat-e-Iqbal "<<endl;
 		cout<<"The IBAN no. of book is 40 "<<endl;
 		if(a>=18 || i==2){
 			cout<<"Book 5 is : Crab Town "<<endl;
 			cout<<"The IBAN no. of book is 50 "<<endl;
 			cout<<"Book 6 is : Wildfire "<<endl;
 			cout<<"The IBAN no. of book is 60 "<<endl;
 			cout<<"Book 7 is : Fifty Shades of grey "<<endl;
 			cout<<"The IBAN no. of book is 70 "<<endl<<endl;
		}
		cout<<"Write IBAN no. of book you want to borrow : ";
		cin>>b;
		cout<<endl<<endl;
		switch(b){
			case 10:
				cout<<"The name of the Book is : The world as i see it"<<endl;
  				cout<<"Name of the Author is : Albert Einstein"<<endl;
  				cout<<"The book was published by : John Lane The Bodley Head"<<endl;
  				cout<<"The book was issued in : 1934"<<endl;
 				cout<<"The price of the Book is 500rs "<<endl;
 				cout<<"We have " <<no[0]<< " copies of this book "<<endl;
 				brf(no[0],num,left,k);
				break;
			case 20:
				cout<<"The name of the Book is :  The rise of Germany"<<endl;
  				cout<<"Name of the Author is : James Holland"<<endl;
  				cout<<"The book was published by : Atlantic Monthly press"<<endl;
 				cout<<"The book was issued in : oct 14, 2015     "<<endl;
				cout<<"The price of the Book is 300rs "<<endl;
				cout<<"We have " <<no[1]<< " copies of this book "<<endl;	
				brf(no[1],num,left,k);
				break;
			case 30:
				cout<<"The name of the Book is :   Nineteen eighty-four"<<endl;
				cout<<"Name of the Author is : George Orwell"<<endl;
				cout<<"The book was published by : Secker & Warburg"<<endl;
				cout<<"The book was issued in : 1949    "<<endl;
				cout<<"The price of the Book is 400rs "<<endl;
				cout<<"We have " <<no[2]<< " copies of this book "<<endl;
				brf(no[2],num,left,k);
				break;
			case 40:
				cout<<"The name of the Book is :   Kulliyat-e-Iqbal"<<endl;
  				cout<<"Name of the Author is : Dr Allama Muhammad Iqbal"<<endl;
			  	cout<<"The book was published by : Farid Book depo"<<endl;
			  	cout<<"The book was issued in : 2016    "<<endl;
			  	cout<<"The price of the Book is 1000rs "<<endl;
			  	cout<<"We have " <<no[3]<< " copies of this book "<<endl;
			  	brf(no[3],num,left,k);
				break;
			case 50:
				cout<<"The name of the Book is :   Crab Town"<<endl;
  				cout<<"Name of the Author is : Carlton Mellick III"<<endl;
			  	cout<<"The book was published by : Eraserhead Press"<<endl;
			  	cout<<"The book was issued in : 2011    "<<endl;
			  	cout<<"The price of the Book is 600rs "<<endl;
			  	cout<<"We have " <<no[4]<< " copies of this book "<<endl;
			  	brf(no[4],num,left,k);
				break;		
			case 60:
				cout<<"The name of the Book is :   Wildfire"<<endl;
  				cout<<"Name of the Author is : Karsten Knight"<<endl;
			  	cout<<"The book was published by : Simon Schuster Books for Young Readers"<<endl;
			  	cout<<"The book was issued in : 2011    "<<endl;
			  	cout<<"The price of the Book is 780rs "<<endl;
			  	cout<<"We have " <<no[5]<< " copies of this book "<<endl;
			  	brf(no[5],num,left,k);
				break;
			case 70:
				cout<<"The name of the Book is :   Fifty Shades Of Grey"<<endl;
  				cout<<"Name of the Author is : E. L. James"<<endl;
			  	cout<<"The book was published by : Vintage"<<endl;
			  	cout<<"The book was issued in : 2011    "<<endl;
			  	cout<<"The price of the Book is 800rs "<<endl;
			  	cout<<"We have " <<no[6]<< " copies of this book "<<endl;
			  	brf(no[6],num,left,k);
				break;	
			default:
				cout<<"Enter correct IBAN no."<<endl;	
				goto iban;
		}
		cout<<endl<<endl<<"The number of books now present in the library are : "<<left<<endl;
		if(k==1){
			cout<<"The number of books borrowed are : "<<num<<endl;
		}
		else if(k==2){
			cout<<"The number of books returned are : "<<num<<endl;
		}
		if(i==1){
			cout<<"//////  Student detail  \\\\\\"<<endl;
			cout<<"roll no. : "<<r<<endl;
			cout<<"age of the student : "<<a<<endl;
			cout<<"Student's Gender : "<<s<<endl;
			cout<<"Thank-you"<<endl<<endl;
		}
		else if(i==2){
			cout<<"//////  Teacher detail  \\\\\\"<<endl;
			cout<<"Name of the Teacher : "<<n<<endl;
			cout<<"Department : "<<d<<endl;
			cout<<"Thank-you"<<endl<<endl;
		}	
	cout<<"==============================="<<endl;
	cout<<"           Continue?           "<<endl;
	cout<<"==============================="<<endl;
	cout<<"1. Yes"<<endl<<"2. No"<<endl<<"Enter the corresponding number : ";
	cin>>cond1;
	if(cond1==1){   
		goto loop;
	}
	else{
	cout<<"============================="<<endl;
	cout<<"           Goodbye           "<<endl;
	cout<<"============================="<<endl;
	}

	
	system("pause");
	return 0;
}

void brf(int& var1 /* no[]*/, int& var2 /*num*/, int& var3 /*left*/, int& var4){
	int a;
	select:
		cout<<endl<<endl<<"Would you like to..."<<endl<<"1. Borrow the book"<<endl<<"2. Return the book"<<endl<<"Enter corresponding number : ";
		cin>>a;
		var4=a;
		if(a==1){
			cout<<"1st copy is only for official use cannot be issued "<<endl;
			book:
			cout<<"how many copies you want to borrow : ";
			cin>>var2;
			if(var2>var1-1){
				cout<<"not enough books to borrow"<<endl;
				goto book;
			}
			else{
				var1-=var2;
				var3=var1;
			}
		}
		else if(a==2){
			nam:
			cout<<"How many copies are you willing to return : ";
			cin>>var2;
			if(var2>0){
				var1+=var2;
				var3=var1;
			}
			else{
				cout<<"Invalid amount"<<endl;
				goto nam;
			}
		}
		else{
			cout<<"Enter only 1 or 2"<<endl;
			goto select;
		}
}
