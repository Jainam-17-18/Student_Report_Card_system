#include "Project.h"
#include <bits/stdc++.h>
#include <iomanip>
#include <conio.h>
#include <sstream>
#include <fstream>
#include <stdlib.h>
#include <chrono>
#include <thread>
using namespace std;
void delay()
{
    using namespace std::this_thread;     // sleep_for, sleep_until
    using namespace std::chrono_literals; // ns, us, ms, s, h, etc.
    using std::chrono::system_clock;

    sleep_for(10us);//here we can increase and decrease time delay....
    sleep_until(system_clock::now() + 1s);
}
void animation()
{
    system("cls");
    cout<<"\n\n========================================\n";
    cout<<">>>>>>>>";
    cout.width(32);
    cout<<" ";
    cout<<" # 20%";
    cout<<"\n========================================\n";
    delay();
    system("cls");
    cout<<"\n\n========================================\n";
    cout<<">>>>>>>>>>>>>>>>>>>>";
    cout.width(20);
    cout<<" ";
    cout<<" # 50%";
    cout<<"\n========================================\n";
    delay();
    system("cls");
    cout<<"\n\n========================================\n";
    cout<<">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>";
    cout<<" # 100%";
    cout<<"\n========================================\n";

}
Project::Project(int MAX_Students)
{
    Maximum = MAX_Students;
    for(int i =0; i <Maximum  ; i++) // setup a default value
    {
        DETAIL *D = new DETAIL();
        arr[i] = D;
        arr[i]->flag = 0;
        arr[i]->name = "-";
        arr[i]->student_id = (i + 202001001);
        for(int j = 0; j < 6; j++)
        {
            arr[i]->Grades[j] = -1;
        }
    }
}
bool check_id(int id, int Maximum)
{
    if(id >= 202001001 && id <= (202001000 + Maximum))
        return true;
    else
        return false;
}
bool check_point(int point)
{
    if(point >=0 && point <=10)
        return true;
    else
        return false;
}
void Project::enter()
{

    int id;

    cout<<"\nPlease Enter Student ID (202001001 - "<<(202001000 + Maximum)<<") : ";
    cin>>id;
    while(!check_id(id,Maximum))  // check id is valid or not if not then ask to enter id
    {
        cout<<"\nPlease enter in range 202001001 - "<<(202001000 + Maximum)<<") : ";
        cin>>id;
    }
    Enter_plus(id);
}
void Project::Enter_plus(int St_ID)
{
    int id = St_ID;
    int point;
    string n;
    cin.ignore();
    cout<<"\nEnter name of student : ";
    getline(cin, n);
    arr[id - 202001001]->name = n;
    // taking grades of every courses....
    cout<<endl;
    for(int i=0; i<6; i++)
    {
        if(i==0)
            cout<<"Enter grade point of Data Structure               : ";
        else if(i==1)
            cout<<"Enter grade point of Data Structure Lab           : ";
        else if(i==2)
            cout<<"Enter grade point of Discrete Mathematics         : ";
        else if(i==3)
            cout<<"Enter grade point of Digital Logic Design         : ";
        else if(i==4)
            cout<<"Enter grade point of Intro. Communication System  : ";
        else if(i==5)
            cout<<"Enter grade point of Approaches to Indian Society : ";

        cin>>point;
        while(!check_point(point))
        {
            cout<<"Please enter valid grade points                   : ";
            cin>>point;
        }

        arr[id - 202001001]->Grades[i] = point;

    }

    cout << "\n\n>>Recorded..." << endl << endl;

    arr[id - 202001001]->flag = 1;
    arr[id - 202001001]->student_id = id;
}
void Project::edit()
{
    char ch;

    display();
    cout << endl << endl;

    cout << "\nThis was your current record...." << endl;
    cout << "Do you still want edit your details? [Y/N] : ";
    cin >> ch;
    cout << endl;

    if(ch == 'Y' || ch == 'y')
    {
        enter();
    }
    else
    {
        return;
    }
}

void Project::display()
{

    int id;
    char ch;
    cout<<endl<<endl;
    cout<<"Please Enter Student ID (202001001 - "<<(202001000 + Maximum)<<") : ";
    cin>>id;
    while(!check_id(id,Maximum))  // check id is valid or not if not then ask to enter id
    {
        cout<<"Please enter in range 202001001 - "<<(202001000 + Maximum)<<") : ";
        cin>>id;
    }
    system("cls");
    cout<<endl<<endl;
    if(arr[id - 202001001]->flag==1)
    {
        cout<<"|======================================================================================================================|";
        cout<<endl;
        cout<<"|";
        cout.width(10);
        cout<<"Name";
        cout<<":";
        cout.width(35);
        cout<<arr[id- 202001001]->name;
        cout.width(10);
        cout<<" |";
        cout.width(13);
        cout<<"Student ID";
        cout<<":";
        cout.width(30);
        cout<<arr[id- 202001001]->student_id;
        cout.width(18);
        cout<<" ";
        cout<<"|"<<endl;

        cout<<"|";
        cout.width(10);
        cout<<"Batch";
        cout<<":";
        cout.width(35);
        cout<<2020;
        cout.width(10);
        cout<<" |";
        cout.width(13);
        cout<<"Semester";
        cout<<":";
        cout.width(30);
        cout<<"Semester 2";
        cout.width(18);
        cout<<" ";
        cout<<"|"<<endl;

        cout<<"|";
        cout.width(10);
        cout<<"Program";
        cout<<":";
        cout.width(35);
        cout<<"B.Tech (ICT)";
        cout.width(72);
        cout<<" ";
        cout<<"|";
        cout<<endl;
        cout<<"|======================================================================================================================|\n";

        cout<<"|";
        cout.width(40);
        cout<<"COURSE TITLE";
        cout<<" |";
        cout.width(15);
        cout<<"COURSE CODE";
        cout<<" |";
        cout.width(25);
        cout<<"CREDIT HOURS";
        cout<<" |";
        cout.width(15);
        cout<<"GRADE";
        cout<<" |";
        cout.width(15);
        cout<<"GRADE POINTS";
        cout<<"|"<<endl;
        cout<<"|______________________________________________________________________________________________________________________|\n";
        for(int i= 0; i<6; i++)
        {
            cout<<"|";
            cout.width(40);
            if(i==0)
                cout<<"Data Structures";
            else if(i==1)
                cout<<"Data Structure Lab";
            else if(i==2)
                cout<<"Discrete Mathematics";
            else if(i==3)
                cout<<"Digital Logic Design";
            else if(i==4)
                cout<<"Introduction to Communication Systems";
            else
                cout<<"Approaches to Indian Society";
            cout<<" |";
            cout.width(15);
            if(i==0)
                cout<<"IT205";
            else if(i==1)
                cout<<"IT206";
            else if(i==2)
                cout<<"SC205";
            else if(i==3)
                cout<<"EL114";
            else if(i==4)
                cout<<"CT111";
            else
                cout<<"HM106";
            cout<<" |";
            cout.width(25);
            if(i==1)
                cout<<"2.00 (0.00+ 0.00+ 4.00)";
            else if(i==2)
                cout<<"4.00 (3.00+ 1.00+ 0.00)";
            else if(i==3 || i == 4)
                cout<<"4.50 (3.00+ 0.00+ 3.00)";
            else // 0 5
                cout<<"3.00 (3.00+ 0.00+ 0.00)";
            cout<<" |";
            cout.width(15);
            if(arr[id - 202001001]->Grades[i] == 10)
                cout<<"AA";
            else if(arr[id - 202001001]->Grades[i] == 9)
                cout<<"AB";
            else if(arr[id - 202001001]->Grades[i] == 8)
                cout<<"BB";
            else if(arr[id - 202001001]->Grades[i] == 7)
                cout<<"BC";
            else if(arr[id - 202001001]->Grades[i] == 6)
                cout<<"CC";
            else if(arr[id - 202001001]->Grades[i] == 5)
                cout<<"CD";
            else if(arr[id - 202001001]->Grades[i] == 4)
                cout<<"DD";
            else if(arr[id - 202001001]->Grades[i] == 3)
                cout<<"DE";
            else if(arr[id - 202001001]->Grades[i] < 3)
                cout<<"F";
            cout<<" |";
            cout.width(15);
            //............
            if(i==0 || i==5)
                cout<<3.0*arr[id - 202001001]->Grades[i];
            else if(i==1)
                cout<<2.0*arr[id - 202001001]->Grades[i];
            else if(i==2)
                cout<<4.0*arr[id - 202001001]->Grades[i];
            else
                cout<<4.5*arr[id - 202001001]->Grades[i];

            cout<<"|";
            cout<<endl;

        }
        cout<<"|======================================================================================================================|\n";
        cout<<"|======================================================================================================================|\n";
        cout<<"|";
        cout.width(28);
        cout<<"CREDITS REGISTERED";
        cout<<" |";
        cout.width(28);
        cout<<"CREDITS EARNED";
        cout<<" |";
        cout.width(28);
        cout<<"GRADE POINTS EARNED";
        cout<<" |";
        cout.width(27);
        cout<<"SPI";
        cout<<" |";
        cout<<endl;
        cout<<"|______________________________________________________________________________________________________________________|\n";
        SPI_count(id);
        cout<<"|";
        cout.width(28);
        cout<<"21.00";
        cout<<" |";
        cout.width(28);
        cout<<CreditEarn_count(id);
        cout<<" |";
        cout.width(28);
        cout<<(float)arr[id - 202001001]->Grade_points_earn;
        cout<<" |";
        cout.width(27);
        cout<<arr[id - 202001001]->SPI;
        cout<<" |";
        cout<<endl;
        cout<<"|______________________________________________________________________________________________________________________|\n";
        cout<<"\n************************************************************************************************************************\n\n";


    }


    // same type of display if no details are there...............................
    if(arr[id - 202001001]->flag==0)
    {
        cout<<"|======================================================================================================================|";
        cout<<endl;
        cout<<"|";
        cout.width(10);
        cout<<"Name";
        cout<<":";
        cout.width(35);
        cout<<"--";
        cout.width(10);
        cout<<" |";
        cout.width(13);
        cout<<"Student ID";
        cout<<":";
        cout.width(30);
        cout<<id;
        cout.width(18);
        cout<<" ";
        cout<<"|"<<endl;

        cout<<"|";
        cout.width(10);
        cout<<"Batch";
        cout<<":";
        cout.width(35);
        cout<<2020;
        cout.width(10);
        cout<<" |";
        cout.width(13);
        cout<<"Semester";
        cout<<":";
        cout.width(30);
        cout<<"Semester 2";
        cout.width(18);
        cout<<" ";
        cout<<"|"<<endl;

        cout<<"|";
        cout.width(10);
        cout<<"Program";
        cout<<":";
        cout.width(35);
        cout<<"B.Tech (ICT)";
        cout.width(72);
        cout<<" ";
        cout<<"|";
        cout<<endl;
        cout<<"|======================================================================================================================|\n";

        cout<<"|";
        cout.width(40);
        cout<<"COURSE TITLE";
        cout<<" |";
        cout.width(15);
        cout<<"COURSE CODE";
        cout<<" |";
        cout.width(25);
        cout<<"CREDIT HOURS";
        cout<<" |";
        cout.width(15);
        cout<<"GRADE";
        cout<<" |";
        cout.width(15);
        cout<<"GRADE POINTS";
        cout<<"|"<<endl;
        cout<<"|______________________________________________________________________________________________________________________|\n";
        for(int i= 0; i<6; i++)
        {
            cout<<"|";
            cout.width(40);
            if(i==0)
                cout<<"Data Structures";
            else if(i==1)
                cout<<"Data Structure Lab";
            else if(i==2)
                cout<<"Discrete Mathematics";
            else if(i==3)
                cout<<"Digital Logic Design";
            else if(i==4)
                cout<<"Introduction to Communication Systems";
            else
                cout<<"Approaches to Indian Society";
            cout<<" |";
            cout.width(15);
            if(i==0)
                cout<<"IT205";
            else if(i==1)
                cout<<"IT206";
            else if(i==2)
                cout<<"SC205";
            else if(i==3)
                cout<<"EL114";
            else if(i==4)
                cout<<"CT111";
            else
                cout<<"HM106";
            cout<<" |";
            cout.width(25);
            if(i==1)
                cout<<"2.00 (0.00+ 0.00+ 4.00)";
            else if(i==2)
                cout<<"4.00 (3.00+ 1.00+ 0.00)";
            else if(i==3 || i == 4)
                cout<<"4.50 (3.00+ 0.00+ 3.00)";
            else // 0 5
                cout<<"3.00 (3.00+ 0.00+ 0.00)";
            cout<<" |";
            cout.width(15);
            cout<<"-";
            cout<<" |";
            cout.width(15);
            cout<<"-";
            cout<<"|";
            cout<<endl;

        }
        cout<<"|======================================================================================================================|\n";
        cout<<"|======================================================================================================================|\n";
        cout<<"|";
        cout.width(28);
        cout<<"CREDITS REGISTERED";
        cout<<" |";
        cout.width(28);
        cout<<"CREDITS EARNED";
        cout<<" |";
        cout.width(28);
        cout<<"GRADE POINTS EARNED";
        cout<<" |";
        cout.width(27);
        cout<<"SPI";
        cout<<" |";
        cout<<endl;
        cout<<"|______________________________________________________________________________________________________________________|\n";
        //SPI_count(id);
        cout<<"|";
        cout.width(28);
        cout<<"21.00";
        cout<<" |";
        cout.width(28);
        cout<<"-";
        cout<<" |";
        cout.width(28);
        cout<<"-";
        cout<<" |";
        cout.width(27);
        cout<<"-";
        cout<<" |";
        cout<<endl;
        cout<<"|______________________________________________________________________________________________________________________|\n";
        cout<<"\n************************************************************************************************************************\n\n";

        cout<<"There is no details here !\n\n";
        cout<<"Do you want to enter details ?[Y/N]\n";
        cin>>ch;
        if(ch == 'N' || ch == 'n')
            return;
        else if(ch == 'Y' || ch == 'y')
        {
            Enter_plus(id);
        }
        else
            return;


    }
}
double Project::CreditEarn_count(int id)
{
    double count = 0;
    int temp = id - 202001001;
    for(int i=0; i<6; i++)
    {
        if(arr[temp]->Grades[i]>=4 && (i == 0 || i == 5))
            count += 3.0;
        else if(arr[temp]->Grades[i]>=4 && i == 1)
            count += 2.0;
        else if(arr[temp]->Grades[i]>=4 && i == 2)
            count += 4.0;
        else
            count += 4.5;
    }

    return count;
}
void Project::SPI_count(int id)
{
    int temp = id - 202001001;
    double spi = 0;
    double Grade_point = 0;
    if(arr[temp]==0)
    {
        arr[temp]->SPI = -1;
    }
    else
    {
        for(int i=0; i<6; i++)
        {
            spi += arr[temp]->Grades[i];

            if(i==1)
                Grade_point += 2.0*arr[temp]->Grades[i];
            else if(i==2)
                Grade_point += 4.0*arr[temp]->Grades[i];
            else if(i==3 || i == 4)
                Grade_point += 4.5*arr[temp]->Grades[i];
            else
                Grade_point += 3.0*arr[temp]->Grades[i];
        }
        arr[temp]->Grade_points_earn = Grade_point;
        spi = spi/6;
        arr[temp]->SPI = spi;
    }

}

void Project::Delete_Detail()
{
    int id;
    cout<<endl<<endl;
    cout<<"Please Enter Student ID (202001001 - "<<(202001000 + Maximum)<<") : ";
    cin>>id;
    while(!check_id(id,Maximum))  // check id is valid or not if not then ask to enter id
    {
        cout<<"Please enter in range 202001001 - "<<(202001000 + Maximum)<<") : ";
        cin>>id;
    }
    if(arr[id - 202001001]->flag == 1)
    {
        arr[id - 202001001]->flag = 0;
        arr[id - 202001001]->name = "-";
        for(int j = 0; j < 6; j++)
        {
            arr[id - 202001001]->Grades[j] = -1;
        }
        cout<<"\n\n>> Detail Deleted....\n\n";
    }
    else
    {
        cout<<"\n\n>> No detail there to delete!\n\n";
    }

}
void Project::sort_by_detail()
{
    double id_array[Maximum][2];
    double result[Maximum+1][2];
    double result2[Maximum+1][3];

    int index=0,index2 = 1,choice = 10,i = 0, k = 0, temp_id,flag = 0,count = 0;

    double spi_given;

    for(int i=0; i<Maximum; i++)
    {
        SPI_count(i + 202001001);
    }
    for(int i =0; i<Maximum; i++)
    {
        id_array[i][0] = arr[i]->student_id;
        if(arr[i]->flag == 0)
            id_array[i][1] = -1;
        else
            id_array[i][1] = arr[i]->SPI;
    }
    cout<<"\n\n==================================================================\n";
    cout<<"\nHow to do want to filter?\n";
    cout<<"Enter...\n";
    cout<<"...1 for The students whose SPI is greater than given No.\n";
    cout<<"...2 for The students whose SPI is lesser than given No.\n";
    cout<<"...3 for The student who are among the highest SPI in the class\n";
    cout<<"...4 for The student who has fail in atleast in 1 course\n";
    cout<<"...0 to return to main menu\n\n";
    cout<<"==================================================================\n\n";
    while(choice !=0)
    {
        cout << "\nEnter the choice you want to continue with : ";
        cin>>choice;
        switch(choice)
        {

        case 1:
            cout<<"Enter SPI : ";
            cin>>spi_given;

            while(!check_point(spi_given))
            {
                cout<<"Please enter valid SPI                            : ";
                cin>>spi_given;
            }
            index=0;
            result[index][0] = -1;
            for(int j = 0; j < Maximum ; j++)
            {
                if(id_array[j][1] >= spi_given)
                {
                    result[index][1] = id_array[j][1];
                    result[index][0] = id_array[j][0];
                    index++;
                    result[index][0] = -1;
                    result[index][1] = -1;
                }
            }
            result[Maximum][0]=-1;
            cout<<"\n|======================================================================|\n";
            k = 0;
            cout<<"|";
            cout.width(4);
            cout<<"Sr.No";
            cout<<" |";
            cout.width(14);
            cout<<"Student ID";
            cout<<" |";
            cout.width(35);
            cout<<"NAME";
            cout<<" |";
            cout.width(10);
            cout<<"SPI";
            cout<<"|";
            cout<<endl;
            while(result[k][0]!=-1)
            {
                temp_id = (int)result[k][0];
                cout<<"|";
                cout.width(4);
                cout<<k+1<<".";
                cout<<" |";
                cout.width(14);
                cout<<temp_id;
                cout<<" |";
                cout.width(35);
                cout<<arr[(int)(result[k][0] - 202001001)]->name;
                cout<<" |";
                cout.width(10);
                cout<<result[k][1];
                cout<<"|";
                cout<<endl;
                k++;
            }
            cout<<"|======================================================================|\n\n";
            break;
        case 2:
            cout<<"Enter SPI : ";
            cin>>spi_given;
            index=0;
            while(!check_point(spi_given))
            {
                cout<<"Please enter valid SPI                            : ";
                cin>>spi_given;
            }
            for(int j = 0; j < Maximum ; j++)
            {
                if(id_array[j][1] <= spi_given)
                {
                    result[index][1] = id_array[j][1];
                    result[index][0] = id_array[j][0];
                    index++;
                    result[index][0] = -1;
                    result[index][1] = -1;
                }
            }
            result[Maximum][0]=-1;
            cout<<"\n|======================================================================|\n";
            k = 0;
            i = 0;
            cout<<"|";
            cout.width(4);
            cout<<"Sr.No";
            cout<<" |";
            cout.width(14);
            cout<<"Student ID";
            cout<<" |";
            cout.width(35);
            cout<<"NAME";
            cout<<" |";
            cout.width(10);
            cout<<"SPI";
            cout<<"|";
            cout<<endl;
            while(result[k][0]!=-1)
            {
                if(result[k][1]== -1) // remove the condition in which it print nothing
                {
                    k++;
                }
                else
                {
                    temp_id = (int)result[k][0];
                    cout<<"|";
                    cout.width(4);
                    cout<<i+1<<".";
                    cout<<" |";
                    cout.width(14);
                    cout<<temp_id;
                    cout<<" |";
                    cout.width(35);
                    cout<<arr[(int)(result[k][0] - 202001001)]->name;
                    cout<<" |";
                    cout.width(10);
                    cout<<result[k][1];
                    cout<<"|";
                    cout<<endl;
                    k++;
                    i++;
                }
            }
            cout<<"|======================================================================|\n\n";
            break;
        case 3:
            index =0; // highest
            index2 = 1; // if two or more highest..
            result[index][0] = -1;
            result[index][1] = 0;
            for(int j = 0; j<Maximum;j++)
            {
                if(id_array[j][1]>result[index][1])  // for greater
                {
                    result[index][1]=id_array[j][1];
                    result[index][0]=id_array[j][0];
                    index2 = 1;
                }
                k = j + 1;
                if(id_array[k][1]==result[index][1])  // if same then
                {
                    result[index2][1]=id_array[k][1];
                    result[index2][0]=id_array[k][0];
                    index2++;
                }
                result[index2][0] = -1;
                result[index2][1] = -1;
            }
            result[Maximum][0] = -1;
            cout<<"\n|======================================================================|\n";
            cout<<"|";
            cout.width(4);
            cout<<"Sr.No";
            cout<<" |";
            cout.width(14);
            cout<<"Student ID";
            cout<<" |";
            cout.width(35);
            cout<<"NAME";
            cout<<" |";
            cout.width(10);
            cout<<"SPI";
            cout<<"|";
            cout<<endl;
            k = 0;
            while(result[k][0]!=-1)
            {
                temp_id = (int)result[k][0];
                cout<<"|";
                cout.width(4);
                cout<<k+1<<".";
                cout<<" |";
                cout.width(14);
                cout<<temp_id;
                cout<<" |";
                cout.width(35);
                cout<<arr[(int)(result[k][0] - 202001001)]->name;
                cout<<" |";
                cout.width(10);
                cout<<result[k][1];
                cout<<"|";
                cout<<endl;
                k++;
            }

            cout<<"|======================================================================|\n\n";
            break;
        case 4:

            index = 0;
            i = 0;
            result2[i][0] = -1;
            for(int a=0; a<Maximum; a++) // filtering
            {
                flag = 0;
                count = 0;
                for(int b=0; b<6; b++)
                {
                    if((arr[a]->Grades[b])<3 && arr[a]->flag == 1)
                    {
                        flag = 1;
                        count++;
                    }
                }
                if(flag == 1)
                {
                    result2[index][0] = arr[a]->student_id; // id
                    result2[index][1] = arr[a]->SPI;        // SPI
                    result2[index][2] = count;              // no of course in which failed
                    index++;
                    result2[index][0] = -1;

                }
            }

            result2[Maximum][0]=-1;
            // displaying...
            cout<<"Students who got failed in atleast in one subject : \n\n";
            cout<<"|============================================================================================|\n";
            cout<<"|";
            cout.width(4);
            cout<<"Sr.No";
            cout<<" |";
            cout.width(14);
            cout<<"Student ID";
            cout<<" |";
            cout.width(35);
            cout<<"NAME";
            cout<<" |";
            cout.width(10);
            cout<<"SPI";
            cout<<" |";
            cout.width(20);
            cout<<"No. of Course (fail)";
            cout<<"|";
            cout<<endl;
            k = 0;
            while(result2[k][0]!= -1)
            {
                temp_id = (int)result2[k][0];
                cout<<"|";
                cout.width(4);
                cout<<k+1<<".";
                cout<<" |";
                cout.width(14);
                cout<<temp_id;
                cout<<" |";
                cout.width(35);
                cout<<arr[(int)(result2[k][0] - 202001001)]->name;
                cout<<" |";
                cout.width(10);
                cout<<result2[k][1];
                cout<<" |";
                cout.width(20);
                cout<<result2[k][2];
                cout<<"|";
                cout<<endl;
                k++;
            }
            cout<<"|============================================================================================|\n";
            break;

        case 0:
            cout<<"\n>> Back to Main Page\n\n\n";
            delay();
            break;
        default:
            cout<<"\n>> Invalid choice..!" <<endl;

            break;
        }
    }

}

void Project::result()
{

    int choice=10;

    while(choice != 0)
    {
        cout << "===========================================================" << endl;
        cout << "Enter..." << endl;
        cout << "...1 if you want to see the result of a particular student." << endl;
        cout << "...0 if you want to return to Main Page." << endl;
        cout << "===========================================================" << endl << endl;

        cout << "Enter the choice you want to continue with: ";
        cin >> choice;
        cout << endl;
        system("cls");

        switch (choice)
        {
        case 1:
            display();
            break;

        case 0:
            cout<<"\n>> Back to Main Page\n\n\n";
            break;

        default:
            cout << "\n>> Invalid choice..!" << endl;
        }
    }
}

void Project::edit_delete()
{

    int choice;
    cout << endl;
    cout << "=================================================" << endl ;
    cout << "Enter..." << endl;
    cout << "...1 if you want to Edit the Student Record." << endl;
    cout << "...2 if you want to Delete the Student Record." << endl;
    cout << "...0 if you want to return to Main Page." << endl;
    cout << "=================================================" << endl << endl;

    cout << "Enter the choice you want to continue with: ";
    cin >> choice;
    cout << endl;
    system("cls");

    switch (choice)
    {
    case 1:
        edit();
        delay();
        break;

    case 2:
        Delete_Detail();
        delay();
        break;

    case 0:
        cout<<"\n>> Back to Main Page\n\n\n";
        break;

    default:
        system("cls");
        cout << "\n> Invalid choice..!"  << endl;
        edit_delete();
    }
}

void Project::write_file()
{
    ofstream myproject;
    myproject.open("Partail_Data_Set.csv"); // here we can change file
    myproject << "Student ID" << "," << "Student Name" << "," << "DSA" << "," << "DSA Lab" << "," << "DM" << "," << "DLD" << "," << "CT" << "," << "HM" << "," << "SPI" << endl;
    for(int i = 0; i < Maximum; i++)
    {
        if(arr[i] -> flag == 0)
        {
            myproject << (i + 202001001) << "," << "-" << "," << "-" << "," << "-" << "," << "-" << "," << "-" << "," << "-" << "," << "-" << "," << "-" << endl;
        }
        else
        {
            SPI_count(arr[i] ->student_id);
            myproject << (i + 202001001) << "," << arr[i] ->name  << "," << arr[i] ->Grades[0] << "," << arr[i] ->Grades[1] << "," << arr[i] ->Grades[2] << "," << arr[i] ->Grades[3] << "," << arr[i] ->Grades[4] << "," << arr[i] ->Grades[5] << "," << arr[i] ->SPI << endl;
        }
    }
}
void Project::read_file()
{
    ifstream myproject;
    myproject.open("Partail_Data_Set.csv"); // here we can change file
    vector<string> row;
    string line, word, temp;
    int id=-1,DS=-1,DS_lab=-1,DM=-1,DLD=-1,CT=-1,HM=-1;
    float spi=-1;
    string name;
    int count=0;
    string check = "-";
    while(myproject.good())
    {
        if(count ==0) // heading
        {
            count++;
            row.clear();
            getline(myproject, line);
            stringstream s(line);
            while (getline(s, word, ','))
            {

                row.push_back(word);
            }
        }
        else
        {

            row.clear();
            getline(myproject, line);
            stringstream s(line);
            while (getline(s, word, ','))
            {

                row.push_back(word);
            }
            stringstream ss(row[0]);
            ss>>id;
            name = row[1];
            if(name.compare(check) !=0)
            {
                stringstream temp1(row[2]);
                temp1>>DS;
                stringstream temp2(row[3]);
                temp2>>DS_lab;
                stringstream temp3(row[4]);
                temp3>>DM;
                stringstream temp4(row[5]);
                temp4>>DLD;
                stringstream temp5(row[6]);
                temp5>>CT;
                stringstream temp6(row[7]);
                temp6>>HM;
                stringstream temp7(row[8]);
                temp7>>spi;

                arr[id - 202001001]->name=name;
                arr[id - 202001001]->Grades[0]=DS;
                arr[id - 202001001]->Grades[1]=DS_lab;
                arr[id - 202001001]->Grades[2]=DM;
                arr[id - 202001001]->Grades[3]=DLD;
                arr[id - 202001001]->Grades[4]=CT;
                arr[id - 202001001]->Grades[5]=HM;
                arr[id - 202001001]->flag = 1;
                arr[id - 202001001]->Grade_points_earn = CreditEarn_count(id);
                arr[id - 202001001]->SPI=spi;
                SPI_count(id); // this will make correct SPI if the file has wrong spi


            }
            count++;
        }
        if(count - 1 == Maximum)
            break;
    }
    // animation type
    animation();
}
