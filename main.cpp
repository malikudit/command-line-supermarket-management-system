// header files used

#include <fstream.h>
#include <conio.h>
#include <string.h>
#include <stdio.h>
#include <iomanip.h>
#include <dos.h>

class product
{
  int pno, quant;
  char name[50], categ[50] ;
  float price, qty, tax, disc ;

  public :
  void crt()
  {
    cout<<"Please enter the product number: "<<endl;
    cin>>pno;
    cout<<endl<<"Please enter the product category: "<<endl;
    gets(categ);
    cout<<"Please enter the product name: "<<endl;
    gets(name);
    cout<<"Please enter the product quantity: "<<endl;
    cin >>quant;
    cout<<"Please enter the product price: "<<endl;
    cin>>price;
    cout<<"Please enter the discount (%) on the product: "<<endl;
    cin>>disc;
  }

 void order()
  {
    cout<<"Please enter the product number: "<<endl;
    cin>>pno;
    cout<<"Please enter the product quantity: "<<endl;
    cin>>quant;
  }

  void shw ()
  {
    cout<<endl;
    cout<<"The product number of the product is: "<<pno<<endl;
    cout<<"The category of the product is: "<<categ<<endl;
    puts(categ);
    cout<<endl;
    cout<<"The name of the product is: "<<name<<endl;    
    cout<<endl;
    cout<<"The quantity of the product is: "<<quant<<endl;
    cout<<"The price of the product is: " <<price<<endl;
    cout<<"The discount (%) on the product is: "<<disc<<"%"<<endl;
  }

  char* retcateg ()
  { return categ; }

  int retquant()
  { return quant; }

  int retpno()
  { return pno; }

  int retdisc()
  { return disc; }

  char* retname()
  { return name; }

  float retprice()
  { return price; }
  
  void update(int q)
  { quant-=q; }

};

// class ends here

void menu1();
void userintro();

void searchpno()
{
  clrscr ();
  fstream fil;
  product p ;
  int n, c=0;
  fil.open("admin.dat", ios::binary | ios::in);
  cout<<"Enter Product number you want to search: "<<endl;
  cin>>n;
  while(fil.read((char*)&p,sizeof(p)))
  {
    if(p.retpno() == n)
    {
      cout << endl ;
      p.shw();
      c++ ;
    }
  }
  if (c==0)
  {
    cout <<"Sorry! "<<endl ;
    cout<<"Product number not found"<<endl ;
  }
  fil.close ()   ;
}


 void searchcateg()
{
  clrscr ();
  fstream fil;
  product p ;
  char a[40];
  int c = 0;
  fil.open("admin.dat", ios::binary | ios::in);
  cout << "Enter the product category you want to search"<<endl ;
  gets(a);
  while(fil.read((char*)&p,sizeof(p)))
  {
    if(strcmpi(p.retcateg(),a)==0)
    {
      cout << endl ;
      p.shw();
      c++ ;
    }
   }
   if (c==0)
  {
    cout<<"Sorry!"<<endl<<"Product category not found"<<endl ;
  }
  fil.close ();
  }

 void searchname()
{
  clrscr ();
  fstream fil;
  product p ;
  char a[40];
  int c=0;
  fil.open("admin.dat", ios::binary | ios::in);
  cout << "Enter the product name you want to search"<<endl ;
  gets(a);
  while(fil.read((char*)&p,sizeof(p)))
  {
    if(strcmpi(p.retname(),a)==0)
    {
      cout << endl ;
      p.shw();
      c++ ;
    }
  }
  if (c==0)
  {
    cout <<"Product name not found"<<endl ;
   }
  fil.close ();
  };

void create()
{
  clrscr () ;
  char username[40], password ;
  cout << "Enter Username: " ;
  gets(username) ;
  cout << "Enter Password: "   ;
  password=getche();
  clrscr() ;
  if(strcmpi(username,"project")==0 && password=='p')
   {
   product p;
   fstream fil ;
   fil.open("admin.dat", ios::binary | ios::out) ;
   char c ;
   do
   {
    p.crt() ;
    fil.write((char*)&p,sizeof(p));
    cout<<"To add more items press Y or y: " ;
    cin>>c;
    clrscr();
   }
   while (c=='y'||c=='Y');
   fil.close () ;
   }
  else
   {
  cout<<"Either you have entered the wrong username or the wrong password"<<endl;
  cout<<"Please try again"<<endl ;
  }
}

void displayadmin()
{
  clrscr();
  product p ;
  fstream fil ;
  fil.open("admin.dat" ,ios::binary|ios::in);
  gotoxy(0,1);
cout<<"----------------------------------------------------------- ---------------- ----" <<endl ;

  cout<<endl;
  gotoxy(4,3);
  cout<<"P.No";
  gotoxy(10,3);
  cout<<"Category";
  gotoxy(23,3);
  cout<<"Name";
  gotoxy(35,3);
  cout<<"Quantity";
  gotoxy(48,3);
  cout<<"Price";
  gotoxy(57,3);
  cout<< "Discount";
  gotoxy(70,3);
  cout<<"Total";
  cout<<endl;
  int i=2;
  cout<<"--------------------------------------------------------------------------------"<<endl;
  while(fil.read((char*)&p,sizeof(p)))
  {
    i+=2;
    gotoxy(4,3+i);
    cout<<p.retpno();
    gotoxy(10,3+i);
    puts(p.retcateg());
    gotoxy(23,3+i);
    puts(p.retname());
    gotoxy(37,3+i);
    cout<<p.retquant();
    gotoxy(48,3+i);
    cout<<p.retprice();
    gotoxy(60,3+i);
    cout<<p.retdisc();
    gotoxy(70,3+i);
    cout<<p.retquant()*(((100-p.retdisc())*p.retprice())/100);

  }
  cout<<endl;
cout<<"------------------------------------------------------------- -------------------"<<endl;
  fil.close();
  }

void print()
{  cout<<"Print your invoice"<<endl;
  fstream fil1,fil2;
  product p;
  fil1.open("user.dat",ios::binary|ios::in);
  fil2.open("PRT",ios::binary|ios::in);
  gotoxy(0,1);
cout<<"------------------------------------------------------------------- -----------"<<endl ;

  cout<<endl;
  gotoxy(4,3);
  cout<<"P.No";
  gotoxy(10,3);
  cout<<"Category";
  gotoxy(21,3);
  cout <<"Name";
  gotoxy(38,3);
  cout<<"Quantity";
  gotoxy(44,3);
  cout<<"Price";
  gotoxy(52,3);
  cout<<"Discount";
  gotoxy(63,3);
  cout<<"Total";
  cout<<endl;
  int i=2;
cout<<"------------------------------------------------------------- -------------------"<<endl;

  while(fil1.read((char*)&p,sizeof(p)))
  {
    i+=2;
    gotoxy(4,3+i);
    cout<<p.retpno();
    gotoxy(10,3+i);
    puts(p.retcateg());
    gotoxy(21,3+i);
    puts(p.retname());
    gotoxy(33,3+i);
    cout<<p.retquant();
    gotoxy(48,3+i);
    cout<< p.retprice();
    gotoxy(52,3+i);
    cout<< p.retdisc();
    gotoxy(63,3+i);
    cout<< p.retquant()*(((100-p.retdisc())*p.retprice())/100);

  }
  cout<<endl;

  cout<<"------------------------------------------------------------------- -------------"<<endl;
  fil1.close();
  fil2.close();
  getch();

}

void displayorder()
{
  clrscr();
  product p;
  char x;
  fstream fil;
  fil.open("admin.dat", ios::binary | ios::in);
  gotoxy(0,1);

cout<<"------------------------------------------------------------------ -------------"<<endl ;

  cout<<endl;
  gotoxy(4,3);
  cout<< "P.No";
  gotoxy(10,3);
  cout<<"Category";
  gotoxy(21,3);
  cout<<"Name";
  gotoxy(33,3);
  cout<<"Quantity";
  gotoxy(45,3) ;
  cout<<" Price ";
  gotoxy(52,3) ;
  cout<<" Discount";
  gotoxy(63,3);
  cout<<"Total";
  cout<<endl;
  int i=2 ;

cout<<"--------------------------------------------------------------------------------"<<endl;

  while(fil.read((char*)&p,sizeof(p)))
  {
    i+=2;
    gotoxy(4,3+i);
    cout<<p.retpno();
    gotoxy(10,3+i);
    puts(p.retcateg());
    gotoxy(21,3+i);
    puts(p.retname());
    gotoxy(33,3+i);
    cout<<p.retquant();
    gotoxy(45,3+i);
    cout<<p.retprice();
    gotoxy(52,3+i);
    cout<<"  "<<p.retdisc();
    gotoxy(63,3+i);
    cout<<p.retquant()*(((100-p.retdisc())*p.retprice())/100);

  }
  cout<<endl;
  
cout<<"----------------------------------------------------------- ---------------------"<<endl;

  cout<<endl<<endl<<endl;
  do
  {
  p.order();
  cout<<"Want to add more items(y/n)?";
  cin>>x;
  }
  while(x=='y'|| x=='Y');
  fil.close();
  getch();
}

void displayinvoice()
{
  clrscr();
  product p;
  fstream fil;
  fil.open("admin.dat", ios::binary | ios::in);
  gotoxy(0,1);
cout<<"---------------------------------------------------------------- ---------------"<<endl;

  cout<<endl;
  gotoxy(4,3);
  cout<<"P.No";
  gotoxy(10,3);
  cout<<"Category";
  gotoxy(21,3);
  cout<<"Name";
  gotoxy(33,3);
  cout<<"Quantity";
  gotoxy(45,3);
  cout<<"Price";
  gotoxy(52,3);
  cout<<"Discount";
  gotoxy(63,3);
  cout<<"Total";
  cout<<endl;
  int i=2;

cout<<"---------------------------------------------------------------- ----------------"<<endl ;
  while(fil.read((char*)&p,sizeof(p)))
  {
    i+=2;
    gotoxy(4,3+i);
    cout<< p.retpno();
    gotoxy(10,3+i);
    puts(p.retcateg());
    gotoxy(21,3+i);
    puts(p.retname());
    gotoxy(33,3+i);
    cout<<p.retquant();
    gotoxy(45,3+i);
    cout<<p.retprice();
    gotoxy(52,3+i);
    cout<<p.retdisc();
    gotoxy(63,3+i) ;
    cout<< p.retquant()*(((100-p.retdisc())*p.retprice())/100);

  }
  cout<<endl;
  cout<<"------------------------------------------------------------------- -------------"<<endl;
  fil.close() ;
  getch ();
}

void userlogin()
{
 clrscr();
 char username[20], password;
 cout<<"Enter username: ";
 gets(username);
 cout<<"Enter password: ";
 password=getche();
 if(strcmpi(username,"user")==0&&password=='u')
 {
  userintro();
  }
  }

void userintro()
{
  int n;
  clrscr();
 do
 {
   cout<<"1.Order Product"<<endl;
   cout<<"2.Softcopy of Invoice"<<endl;
   cout<<"3.Print Invoice"<<endl;
   cout<<"4.To Go Back" <<endl;
   cin>>n;
   clrscr();
   switch(n)
    {
      case 1:displayorder();break;
      case 2:displayinvoice();break;
      case 3:print();     break;
      case 4:             break;
      default:cout<<"Wrong choice!";
    }
   }while(n!=4);
  }

void add()
{
  clrscr();
  char username[40], password ;

  cout<<"Enter Username: "<<endl;
  gets(username) ;
  cout<<"Enter Password: ";
  password=getche();
  clrscr() ;
  if(strcmpi(username,"project")==0 && password=='p')
{
  product p;
  fstream fil ;
  fil.open("admin.dat" ,ios::binary|ios::app);
  char c;
  do
  {
    p.crt();

    fil.write((char*)&p, sizeof(p));
    cout<<"To add more items press Y or y: ";
    cin>>c;

  }
  while (c=='y'||c=='Y');
  fil.close ();
  }
  else
  {
    cout<<"Either you have entered the wrong username or the wrong password"<<endl;
    cout<<"Please try again"<<endl;
  }
}

void del()
{
  clrscr();
  fstream fil1,fil2;
  fil1.open("admin.dat", ios::binary | ios::in);
  fil2.open("admin2.dat", ios::binary | ios::out);
  char username[40], password;
  cout << "Enter Username: "<<endl;
  gets(username);
  cout<<"Enter Password: "<<endl;
  password=getche();
  clrscr();
  if(strcmpi(username,"project")==0 && password=='p')
  {
    clrscr();
    product p;
    fstream fil1, fil2;
    int inod ;
    cout<<"Enter product number to be entered"<<endl;
    cout<<"Pr.No.: "<<endl;
    cin>>inod;
    int del=0;
    while(fil1.read((char*)&p,sizeof(p)))
    {
      if (p.retpno()!=inod)
      {
    fil2.write((char*)&p,sizeof(p));
      }
    else
    {
      del++;
    }
   }
  clrscr();
  if(!del)
  {
    cout<<"Item not found"<<endl;
  }
  else

  {
    cout<<"Item has been deleted"<<endl;
  }
  }
  else
  {
    cout<<"Either you have entered the wrong username or the wrong password"<<endl;
    cout<<"Please try again"<<endl ;
  }
  fil1.close();
  fil2.close();
  }

void sortpnohl()
{
  fstream F;
  F.open("admin.DAT", ios::binary | ios::in | ios::out);
  F.seekg(0, ios::end);
  int NOR=F.tellg()/sizeof(product);
  product PJ,PJ1;
  for (int i=0; i<NOR-1; i++)
  for (int j=0; j<NOR-i-1; j++)
    {
      F.seekg(j*sizeof(product));
      F.read((char*)&PJ,sizeof(product));
      F.read((char*)&PJ1,sizeof(product));
  if (PJ.retpno()<PJ1.retpno())
    {
      F.seekp(j*sizeof(product));
      F.write((char*)&PJ1,sizeof(product));
      F.write((char*)&PJ,sizeof(product));
    }
  }
  F.close();
  displayadmin();
}


void sortnamehl()
{
   fstream F;
  F.open("admin.DAT", ios::binary | ios::in | ios::out);
  F.seekg(0, ios::end);
  int NOR=F.tellg()/sizeof(product);
  product PJ,PJ1;
  for (int i=0; i<NOR-1; i++)
  for (int j=0; j<NOR-i-1; j++)
    {
      F.seekg(j*sizeof(product));
      F.read((char*)&PJ,sizeof(product));
      F.read((char*)&PJ1,sizeof(product));
  if (strcmpi(PJ.retname(),PJ1.retname())<0)
    {
      F.seekp(j*sizeof(product));
      F.write((char*)&PJ1,sizeof(product));
      F.write((char*)&PJ,sizeof(product));
    }
  }
  F.close();
  displayadmin();
}

 void sortpricehl()
{
  fstream F;
  F.open("admin.DAT", ios::binary | ios::in | ios::out);
  F.seekg(0, ios::end);
  int NOR=F.tellg()/sizeof(product);
  product PJ,PJ1;
  for (int i=0; i<NOR-1; i++)
  for (int j=0; j<NOR-i-1; j++)
    {
      F.seekg(j*sizeof(product));
      F.read((char*)&PJ,sizeof(product));
      F.read((char*)&PJ1,sizeof(product));
  if (PJ.retprice()<PJ1.retprice())
    {
      F.seekp(j*sizeof(product));
      F.write((char*)&PJ1,sizeof(product));
      F.write((char*)&PJ,sizeof(product));
    }
  }
  F.close();
  displayadmin();
}

void sortpnolh()
{
  fstream F;
  F.open("admin.DAT", ios::binary | ios::in | ios::out);
  F.seekg(0,ios::end);
  int NOR=F.tellg()/sizeof(product);
  product PJ,PJ1;
  for (int i=0; i<NOR-1; i++)
  for (int j=0; j<NOR-i-1; j++)
    {
      F.seekg(j*sizeof(product));
      F.read((char*)&PJ,sizeof(product));
      F.read((char*)&PJ1,sizeof(product));
  if (PJ.retpno()>PJ1.retpno())
    {
      F.seekp(j*sizeof(product));
      F.write((char*)&PJ1,sizeof(product));
      F.write((char*)&PJ,sizeof(product));
    }
  }
  F.close();
  displayadmin();
}


void sortnamelh()
{
   fstream F;
  F.open("admin.DAT",ios::binary|ios::in|ios::out);
  F.seekg(0,ios::end);
  int NOR=F.tellg()/sizeof(product);
  product PJ,PJ1;
  for (int i=0;i<NOR-1;i++)
  for (int j=0;j<NOR-i-1;j++)
    {
      F.seekg(j*sizeof(product));
      F.read((char*)&PJ,sizeof(product));
      F.read((char*)&PJ1,sizeof(product));
  if (strcmpi(PJ.retname(),PJ1.retname())>0)
    {
      F.seekp(j*sizeof(product));
      F.write((char*)&PJ1,sizeof(product));
      F.write((char*)&PJ,sizeof(product));
    }
  }
  F.close();
  displayadmin();
}

void sortpricelh()
{
  fstream F;
  F.open("admin.DAT",ios::binary|ios::in|ios::out);
  F.seekg(0,ios::end);
  int NOR=F.tellg()/sizeof(product);
  product PJ,PJ1;
  for (int i=0;i<NOR-1;i++)
  for (int j=0;j<NOR-i-1;j++)
    {
      F.seekg(j*sizeof(product));
      F.read((char*)&PJ,sizeof(product));
      F.read((char*)&PJ1,sizeof(product));
  if (PJ.retprice()>PJ1.retprice())
    {
      F.seekp(j*sizeof(product));
      F.write((char*)&PJ1,sizeof(product));
      F.write((char*)&PJ,sizeof(product));
    }
  }
  F.close();
  displayadmin();
}

void intro()
{
  gotoxy(50,50) ;
  delay(1000);
  cout<<"                                     Welcome! "<<endl;
  delay(1800);
  cout<<"                           To The Global Cooperation's"<<endl;
  delay(1000);
  gotoxy(50,50) ;
  cout<<"                      SUPERMARKET ";
  delay(500);
  cout<<"DATABASE ";
  delay(500);
  cout<<"MANAGEMENT ";
  delay(500);
  cout<<"SYSTEM ";
  delay(500);
  clrscr();
  menu1();
  getch();
}

void sortintro()
{
    int a;
    clrscr() ;
    do
    {
        cout<<"1.Sort by Product No.(high to low)"<<endl ;
        cout<<"2.Sort by Product No.(low to high)"<<endl;
        cout<<"3.Sort by Name(Last to First)"<<endl;
        cout<<"4.Sort by Name(First to Last)"<<endl;
        cout<<"5.Sort by Price(High to Low)"<<endl;
        cout<<"6.Sort by Price(Low to High)"<<endl;
        cout<<"0. Go back"<<endl;
        cin>>a;
        switch(a)
        {
            case 1:sortpnohl(); break;
            case 2:sortpnolh(); break;
            case 3:sortnamehl(); break;
            case 4:sortnamelh(); break;
            case 7:sortpricehl(); break;
            case 8:sortpricelh(); break;
            case 0:                break;
        }

    }while(a!=0);
    clrscr();
}

void searchintro()
{
    int a;
    clrscr() ;
    do
    {
        cout<<"1.Search Product No."<<endl;
        cout<<"2.Search Name"<<endl;
        cout<<"3.Search Category"<<endl;
        cout<<"4.Go Back"<<endl;
        cin>>a;
        switch(a)
        {
            case 1:searchpno(); break;
            case 2:searchname(); break;
            case 3:searchcateg(); break;
        }

    }while(a!=4);
 clrscr();

}

void adminintro()
{
  clrscr () ;
  int a;
  do
  {
     cout <<"1:Create"<<endl;
     cout <<"2:Display"<<endl;
     cout <<"3:Add more items"<<endl;
     cout <<"4:Sort"<<endl;
     cout <<"5:Search"<<endl;
     cout <<"6:Exit"<<endl;
    cin>>a;
    clrscr();
     switch (a)
     {
          case 1:create();break;
          case 2:displayadmin();break ;
          case 3:add(); break;
          case 4:sortintro();break;
          case 5:searchintro();break;
          case 6:               break;
          default: cout<<"Incorrect value entered!"<<endl;
     }
  }
  while (a!=6);
}

void menu1()
{
  int a;
  do
  {
     clrscr();
     cout<<"Hi!"<<endl;
     cout<<"Press 1 for USER"<<endl
         <<"Press 2 for ADMIN"<<endl<<"Press 3 to EXIT"<<endl;
     cin>>a;

     switch(a)
     {
       case 1 : userlogin() ; break ;
       case 2 : adminintro(); break ;
       case 3 : cout<<"Goodbye!"; break;
      } 
   } while(a!=3);
}

void main ()
{
  clrscr();
  intro();
  getch() ;
}
