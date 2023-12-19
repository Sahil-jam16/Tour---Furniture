//C++ PROJECT -  IMPLEMENTATION OF FURNITURE AS A REAL-WORLD ENTITY
#include<iostream>
#include<fstream>
#include<iomanip>
#include<cstring>
#include<conio.h>

using namespace std;

void funColour();
void funType(int sub_choice);
void funSizes();
//void funSit();

//Abstract Class
class Furniture
{
public:

    string type;
    string colour;

    //Default Constructor
    Furniture()
    {
        //ctor
    }

    //Pure Virtual Function
    virtual void funGetData()=0;
    //Pure Virtual Function
    virtual void funShowData()=0;
};

//public inheritance of Furniture in Table
class Table:public Furniture
{
public:
    //Default Constructor
    Table()
    {
        //ctor
    }
    string size;
    void funWrite();
    void funPlace();
    //Friend Function
    //friend void funSit();
    void funGetData();
    void funShowData();
    ~Table()
    {
        //dtor
    }
};

void Table::funWrite()
{
    cout<<"Used for Writing"<<endl;
}

void Table::funPlace()
{
    cout<<"Used for Placing Objects"<<endl;
}

void Table::funGetData()
{

    int choice=1;
    //creating fstream object to write into file
    fstream fin;
    fin.open("tables.txt",ios::out|ios::app);
    if(!fin)
        cout<<"\n Can't Open The File"<<endl;
    else
    {
        funType(choice);
        cout<<"\n  Enter the Type of the Table : "<<endl;
        fflush(stdin);
        getline(cin,type);
        //cin>>type;
        funColour();
        cout<<"\n  Enter the Colour of Table            : "<<endl;
        //getline(cin,colour);
        cin>>colour;
        //funSizes();
        funSizes();
        cout<<"\n  Enter the Size of the Table          : "<<endl;
        cin>>size;
        fin<<type<<"\n";
        fin<<colour<<"\n";
        fin<<size<<"\n";

    }
    fin.close();

    /*if(type=="wood")
    {
        cout<<"Choose The Colour : "<<endl;
        cout<<"1.Dark Wood \t 2.Light Wood \t 3. Brick Wood"<<endl;
        cin>>choice;
        swicth(choice)
        {
        case 1:
            cout<<"1000 per inch ";
            cout<<"Hence The cost of your Selected Table is : "<<(1000*size)<<"/- only"<<endl;
        }
    }*/

}

void Table::funShowData()
{
    int count = 1,flag_table=0;
    cout<<"\n  Details of The Table Tour is "<<endl;
    //creating fstream object to read from file
    fstream fout;
    fout.open("tables.txt",ios::in);
    string s;
    if(fout)
    {
        cout<<"Table No : "<<count<<endl;
        while(getline(fout,s))
        {
            if(flag_table==3)
            {
                count+=count;
                cout<<"Table No : "<<count++<<endl;
                flag_table=0;

            }
             flag_table++;
            cout<<s<<endl;
            //cout<<"\n";
        }
        cout<<"*END OF TABLES*"<<endl;
    }
}


class Cushion;      //forward declaration , class forwarding

//public inheritance of Furniture in Chair
class Chair:public Furniture
{
private:
    int legs;
public:
    //Default Constructor
    Chair()
    {
        //ctor
    }
    void funGetData();
    friend void fun_Sit_Chair(Chair c);
    void funShowData();
    ~Chair()
    {
        //dtor
    }
};


void Chair::funGetData()
{
    int choice=2;
    //creating fstream object to write into file
    fstream fin;
    fin.open("Chairs.txt",ios::out|ios::app);
    if(!fin)
        cout<<"\n Can't Open The File"<<endl;
        else
        {
            funType(choice);          //friend function
            cout<<"\n  Enter the Type of the Chair   : "<<endl;
            fflush(stdin);
            getline(cin,type);
            //cin>>type;
            funColour();        //friend function
            cout<<"\n  Enter the Colour of the Chair : "<<endl;
            //getline(cin,colour);
            fflush(stdin);
            cin>>colour;
            fin<<type<<"\n";
            fin<<colour<<"\n";
        }

        fin.close();

}

void Chair::funShowData()
{
    int count2 = 1,flag_chair=0;
    cout<<"Details of The Chairs Tour is "<<endl;
    //creating fstream object to read from file
    fstream fout;
    fout.open("chairs.txt",ios::in);
    string s;
    if(fout)
    {
        cout<<"Chair No : "<<count2<<endl;
        while(getline(fout,s))
        {
            if(flag_chair==2)
            {
                count2+=count2;
                cout<<"Chair No : "<<count2++<<endl;
                flag_chair=0;

            }
            flag_chair++;
            cout<<s<<endl;
        }
        cout<<"*END OF CHAIRS*"<<endl;
    }
}

//Stand-Out Class
class Cushion
{
public:

    string cus_type;
    Cushion()
    {
        //ctor
    }
    void cushion_types()
    {
        cout<<"\n  Types of Cushions are - \n";
        cout<<" 1.NATURAL FILL CUSHION\n"<<" 2.SYNTHETIC FILL CUSHION\n"<<" 3.POLY-CULSTER CUSHION\n"<<" 4.FOAM CUSHION\n"<<" 5.MEMORY FOAM CUSHION\n";
    }
    ~Cushion()
    {
        //dtor
    }
};

//public inheritance of Furniture in Bed
class Bed:public Furniture
{
    private:
        string design;
        string frame;
    public:
        //aggregation
        Cushion cus;

        //Default Constructor
        Bed()
        {
            //ctor
        }

        void funSleep();
        void funGetData();
        friend void fun_Sit_bed(Bed b);       //friend function
        void funShowData();
        ~Bed()
        {
            //dtor
        }
};

void Bed::funGetData()
{
    int choice=3;
    //creating fstream object to write into file
    fstream fin;
    fin.open("beds.txt",ios::out|ios::app);
    if(!fin)
        cout<<"Coundn't Open The File"<<endl;
    else
    {
        funType(choice);
        cout<<"\n  Enter the Type of the Bed   : "<<endl;
        fflush(stdin);
        getline(cin,type);
        funColour();
        cout<<"\n  Enter the Colour of the Bed : "<<endl;
        cin>>colour;
        cus.cushion_types();
        cout<<"\n  Enter the Cushion type of the Bed : "<<endl;
        fflush(stdin);
        getline(cin,cus.cus_type);
        fin<<type<<"\n";
        fin<<colour<<"\n";
        fin<<cus.cus_type<<"\n";
    }
    fin.close();
}

void Bed::funShowData()
{
    int count3 = 1,flag_bed=0;
    cout<<"\n  Details of The Beds Tour are - "<<endl;
    //creating fstream object to read from file
    fstream fout;
    fout.open("beds.txt",ios::in);
    string s;
    if(fout)
    {
        cout<<"Bed No : "<<count3<<endl;
        while(getline(fout,s))
        {
            if(flag_bed==3)
            {
                count3+=count3;
                cout<<"Chair No : "<<count3++<<endl;
                flag_bed=0;

            }
            flag_bed++;

            cout<<s<<endl;
        }
        cout<<"*END OF BEDS*"<<endl;
    }
}



void fun_Sit_chair(Chair c)
{
    cout<<"This futniture of type Chair allows the user to Sit on it\n";
}

void fun_Sit_bed(Bed b)
{
    cout<<"\n  This futniture of type Bed allows the user to Sit on it\n";
}

//function to display sizes
void funSizes()
{
    cout<<"\nSIZE'S ARE - "<<endl;
    cout<<" 1.MEDIUM "<<"\n"<<" 2.SMALL "<<"\n"<<" 3.LARGE "<<endl;
}

//function to display colours
void funColour()
{
    cout<<"\nCOLOURS ARE - "<<endl;
    cout<<" 1.BLUE "<<"\n"<<" 2.RED "<<"\n"<<" 3.YELLOW "<<"\n"<<" 4.GREEN "<<"\n"<<" 5.MAGENTA "<<"\n"<<" 6.WHITE "<<"\n"<<" 7.BLACK "<<"\n"<<" 8.PINK "<<"\n"<<" 9.BROWN "<<"\n"<<" 10.GREY "<<endl;
}

//function to display the types
void funType(int sub_choice)
{
    int choice_types;
   // cout<<"Enter the Furniture to Record its Type [1-TABLE 2-CHAIR 3-BED] - "<<endl;
   // cin>>choice_types;
    switch(sub_choice)
    {
        case 1:
            cout<<"\nTABLES TYPES ARE - "<<endl;
            cout<<" 1.DINNING TABLE "<<"\n"<<" 2.STUDY TABLE "<<"\n"<< " 3.BEDSIDE TABLE "<<"\n"<<" 4.DROP-LEAF TABLE "<<"\n"<<" 5.GATE-LEG TABLE"<<endl;
            break;
        case 2:
            cout<<"\nCHAIR TYPES ARE - "<<endl;
            cout<<" 1.ROLLING CHAIR "<<"\n"<<" 2.STATIC CHAIR "<<"\n"<< " 3.EASY-CHAIR "<<"\n"<< " 4.LAYDOWN CHAIR "<<"\n"<< " 5.PUSH-BACK CHAIR "<<endl;
            break;
        case 3:
            cout<<"\nBED TYPES ARE - "<<endl;
            cout<<" 1.AIR BED "<<"\n"<<" 2.BOX BED "<<"\n"<<" 3.BUNK BED "<<"\n"<<" 4.CANOPY BED "<<"\n"<<" 5.INFANT BED "<<endl;
            break;
        default:
            cout<<" Wrong Selection"<<endl;
            break;

    }
}

void description()
{
    cout<<"THIS TOUR CONSISTS THE DETAILS OF THE VARIOUS FURNITURES SUCH AS TABLES , CHAIRS AND BEDS"<<endl;
    cout<<"FURNITURE IS A BASE CLASS AND TABLE , CHAIR , BED ARE INHERITED FROM FURNITURE "<<endl;
    cout<<"VARIOUS OOPS CONCEPTS USED HERE ARE INHERITANCE , AGGREGATION , ABSTRACT CLASS , VIRTUAL FUNCTIONS , FILES , ENCAPSULATION , ABSTRACTION ,FRIEND FUNCTION ,EXCEPTION HANDLING "<<endl;
    cout<<"VARIOUS HEADERS USED IN THIS ARE IOSTREAM , FSTREAM , CSTRING , CONIO , IOMANIP "<<endl;
    cout<<"THIS IS DONE BY : "<<endl;
    cout<<"21PC19 - NANDA PRANESH.S"<<endl;
    cout<<"21PC27 - SAHIL JAMADAR SK"<<endl;

}

int main()
{
    Table t1;
    Chair c1,cp;
    Bed b1,bp;
    int choice_sel,option,key=1;

    while(key)
    {

        system("cls");
        cout<<"\t\t          -------------------------------------------           "<<endl;
        cout<<"\t\t          |***---WELCOME TO THE FURNITURE TOUR---***|            "<<endl;
        cout<<"\t\t          -------------------------------------------           "<<endl;
        cout<<"\n||***TABLES***|| \t ||***CHAIRS***|| \t ||***BEDS***|| \t ||***DESCRIPTION TOUR***||"<<endl;
        cout<<"\n\nPress 1 for Tour Tables\n"<<endl;
        cout<<"Press 2 for Tour Chairs\n"<<endl;
        cout<<"Press 3 for Tour Beds\n"<<endl;
        cout<<"Press 4 for See Tour Description\n"<<endl;
        cout<<"Press 5 for Exit \n"<<endl;
        cin>>option;


    switch(option)
    {
        //exception handling
        /*try
            {
                if(option==0)
                    throw option;
            }
            catch(int x)
            {
                cout<<"Invalid Option";
            }
            catch(...)
            {}*/

        case 1:
            system("cls");
            t1.funGetData();
            t1.funShowData();
            t1.funWrite();
            t1.funPlace();
            break;
        case 2:
            system("cls");
            c1.funGetData();
            c1.funShowData();
            fun_Sit_chair(cp);
            break;
        case 3:
            system("cls");
            b1.funGetData();
            b1.funShowData();
            fun_Sit_bed(bp);
            break;
        case 4:
            system("cls");
            description();
            break;
        case 5:
            exit(0);
            break;
        default:
            system("cls");
            cout<<"*WRONG SELECTION *"<<endl;
            break;
    }
    getch();
    system("cls");
    cout<<"\n\n***DO YOU WANT TO CONTINUE ?*** "<<endl;
    cin>>key;

    }
    return 0;
}
