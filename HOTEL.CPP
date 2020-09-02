#include<iostream.h>
#include<conio.h>
#include<fstream.h>
#include<process.h>
\*
    Mukta Choudhury
    
*\
class hotel_management
{
	public:
		void user_details()
		{
			char check;
			cout<<"Are you a guest of the hotel:"<<endl;
			cin.get(check);
			if(check=='Y')
			{
				int roomno;
				cout<<"Enter room no:"<<endl;
				cin>>roomno;
			}
			cout<<"\t""1.Indian""\n" "\n"" 2.Chinese"<<endl;
			int choice;
			cout<<"Enter choice:"<<endl;
			cin>>choice;
			switch(choice)
			{
			    case 1:cout<<"Indian food options"<<endl;
				   cout<<"Roti 100"<<endl;
				   cout<<"Rice 100"<<endl;
				int order;
				cout<<"Enter order:"<<endl;
				cin>>order;
				switch(order)
				{case 1:cout<<"\t""Your bill is rs 100"<<endl;
					break;
				 case 2:cout<<"\t""Your bill is rs 100"<<endl;
					break;
				 default:cout<<"\t""Wrong input"<<endl;
					break;
				}
			  break;

			  case 2:cout<<"Chinese food menu"<<endl;
				 cout<<"Fried rice rs 100"<<endl;
				 cout<<"chowmein rs100"<<endl;
				int order2;
				cout<<"Enter order:"<<endl;
				cin>>order2;
				switch(order2)
				{
				  case 1:cout<<"Your bill is rs 100";
					 break;
				  case 2:cout<<"Your total bill is rs 100:";
					 break;
				  default:cout<<"Wrong";
				}
			 break;
			 default:exit(0);
		}
     }
	     public:
		void write_record()
		{
			ofstream outfile;
			outfile.open("guest.dat",ios::binary,ios::app);
			hotel_management obj;
			obj.user_details();
			outfile.write((char*)&obj,sizeof(obj));
			outfile.close();
		}
};
		void main()
		{       clrscr();
			hotel_management obj;
			obj.user_details();
			obj.write_record();
			getch();
		}

