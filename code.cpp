using namespace std;
#include<iostream>
#include<stdlib.h>
#include<fstream>
class rental_system
{
	int a,sur;
	int charge_per_hour,rental_time;
	string car_name,selected_car;
	char status;
	public:
	void after_selection(string selected_car);
	void surcharge_demo();
};
void rental_system::after_selection(string selected_car)
{
		ifstream ob("saibhau.txt");
		if(ob==NULL)
		cout<<"File not exist";
		else
		{
			for(a=1;a<=10;a++)
			{
				ob>>car_name>>charge_per_hour;
				if(car_name==selected_car)
				{
					cout<<"For how much hours you want to acquire the vehicle? ";
					cin>>rental_time;
					cout<<"Your fare is "<<charge_per_hour*rental_time<<"\n";
					cout<<"Surcharge for every extra hour is 20% more than the rental time. ";
					cout<<"Press 'Y' to check a demo : ";
					cin>>status;
					if(status=='Y')
					{
						cout<<"Enter surplus number of hours : ";
						cin>>sur;
						cout<<"Your fare is "<<charge_per_hour*rental_time+sur*charge_per_hour+sur*(charge_per_hour/5);
					}
					exit(0);
				}
			}
			cout<<"Sorry! Car not available. Please select from the given list \n";
		}
}
int main()
{
	int charge_per_hour,a,rental_time;
	string car_name,selected_car;
	rental_system rent1;
	while(1)
	{
		ifstream ob("saibhau.txt");
		if(ob==NULL)
		cout<<"File not exist";
		else
		{	
			cout<<"\n";
	    	for(a=1;a<=10;a++)
			{
		  		ob>>car_name>>charge_per_hour;
		  		cout<<car_name<<"\t\t"<<charge_per_hour<<"\n";
			}
			cout<<"Choose your car : ";
			cin>>selected_car;
			rent1.after_selection(selected_car);
		}	
	}
}
