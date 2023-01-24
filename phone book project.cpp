#include <iostream> 
#include <fstream>
#include <string>
#include <sstream>  

using namespace std;
char validate(string);

////////////////////////// function to add new record ////////////////////////////////////

void AddNumber()
{
    string name , adress , email_adress;
    int phone;
    cout<<"Enter your Name: ";
    cin>>name;
    cout<<"Enter your Phone no. :";
    cin>>phone;
    cout<<"Enter your Email: ";
    cin>>email_adress;
    cout<<"Enter your Adress: ";
    cin>>adress;
    char response = validate(name);
    
    if(response == 'y')
	{
        cout<<"Name Record Already Exists!"<<endl<<endl;
    }
    else
	{
        ofstream addnum;
        addnum.open("PhoneBook.csv");
        addnum << name << "," << phone << "," << email_adress<< "," << adress <<endl;
        addnum.close();
        cout<<"\nRecord Saved to File......\n";
    }
}

/////////////////// Function to display previous record //////////////////////////////////

int DisplayRecords()
 {
    int i = 0;
    ifstream file("PhoneBook.csv");
    string line;
    while (getline(file, line))
	 {
        istringstream iss(line);
        string field;
        while (getline(iss, field, ','))
		 {
            if(i==0)
			{
            	cout<<"=================="<<endl;
                cout<<"Name = ";
                i++;
            }
            else if(i==1){
                cout<<"Phone = ";
                i++;
            }
            else if(i==2){
                cout<<"Email Adress = ";
                i++;
            }
            else{
                cout<<"Adress = ";
                i++;  
            }
            cout<<field<<endl;
            
        }
        cout<<"================="<<endl;
    }
}

char validate(string s)
{
    ifstream check("PhoneBook.csv");
    string line;
    while(getline(check , line))
	{
        istringstream line3 (line);
        string field;
        while(getline(line3, field, ','))
		{
            if (s != field){
                continue;
            }
            else
			{
                return 'y';
            }
            break;
        }
     }

}
//////////////////////// function to search record by name //////////////////////////////
void SearchByName()
{
    string name;
    cout<<"Enter a Name: ";
    cin>>name;
    ifstream file("PhoneBook.csv");
    string line;
    bool found = false;
    while (getline(file, line))
	 {
        istringstream iss(line);
        string field;
        int i = 0;
        while (getline(iss, field, ','))
		{
            if(i == 0 && field == name)
			{
                found = true;
                cout<<"Name = "<<field<<endl;
            }
            else if(i == 1 && found)
			{
                cout<<"Phone = "<<field<<endl;
            }
            else if(i == 2 && found)
			{
                cout<<"Email Adress = "<<field<<endl;
            }
            else if(i == 3 && found)
			{
                cout<<"Adress = "<<field<<endl;
                cout<<"================="<<endl;
            }
            i++;
        }
    }
    if(!found)
	{
        cout<<"Record not found"<<endl;
    }
}


void menu()
{
	int choise;
	while(1)
	{
		cout<<"............................................\n";
        cout<<"           PHONE BOOK MANAGEMENT\n";
        cout<<"............................................\n\n";
        cout<<"::::::::::::::: PROGRAM MENU :::::::::::::::\n";
        cout<<"0. Exit\n";
        cout<<"1. Save New Phone Record\n";
        cout<<"2. Display All Saved Records\n";
        cout<<"3. Search by Name\n";
        cout<<"Enter Your Choice : ";
        cin>>choise;
        char i;
        switch(choise)
        {
        	case 0:  
				i = 'y';
				break;
            case 1: 
				AddNumber(); 
				break;
            case 2: 
				DisplayRecords(); 
				break;
			case 3:
				SearchByName();
				break;
        }
		if(i=='y')
		{
			break;
		}	
	}
}

////////////////// main function ////////////////////////
int main()
{
	menu();
	
}
