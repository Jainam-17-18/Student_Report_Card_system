#include <iostream>
#include <fstream>
#include <chrono>
#include <thread>

#include "Project.h"

using namespace std;
void main_menu()
{
    cout << "====================================================" << endl;
    cout << "You have the following options to continue with...." << endl ;
    cout << "Enter..." << endl;
    cout << "...1 to continue with Entry section." << endl;
    cout << "...2 to continue with Edit and delete Section." << endl;
    cout << "...3 to continue with Result Section." << endl;
    cout << "...4 to continue with Filter Section." <<endl<<endl;
    cout << "...0 to exit..." << endl;
    cout << "====================================================" << endl << endl;

}
void time_delay()
{
    using namespace std::this_thread;     // sleep_for, sleep_until
    using namespace std::chrono_literals; // ns, us, ms, s, h, etc.
    using std::chrono::system_clock;

    sleep_for(1ms);//here we can increase and decrease time delay....
    sleep_until(system_clock::now() + 1s);
}
void animation_end()
{
    system("cls");
    cout<<"Saving...";
    cout<<"\n\n========================================\n";
    cout<<">>>>>>>>";
    cout.width(32);
    cout<<" ";
    cout<<" # 20%";
    cout<<"\n========================================\n";
    time_delay();
    system("cls");
    cout<<"Saving.";
    cout<<"\n\n========================================\n";
    cout<<">>>>>>>>>>>>>>>>>>>>";
    cout.width(20);
    cout<<" ";
    cout<<" # 50%";
    cout<<"\n========================================\n";
    time_delay();
    system("cls");
    cout<<"Saving....";
    cout<<"\n\n========================================\n";
    cout<<">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>";
    cout<<" # 100%";
    cout<<"\n========================================\n";
    time_delay();
    system("cls");
    cout<<"Saved..\n";
    cout << "\nProgram Ended..."<<endl;

}

void title()
{
    cout.width(50);
    cout<<" ";
    cout<<"=================================="<<endl;
    cout.width(50);
    cout<<" ";
    cout<<" ~: STUDENT REPORT CARD SYSTEM :~ " << endl;
    cout.width(50);
    cout<<" ";
    cout<<"=================================="<<endl<<endl<<endl;
}
int main()
{
    //system("COLOR 0A");
    Project p(500);
    title();
    // if the data(information) file was there then ask to retain....
    char ch;
    ifstream ifile;
    ifile.open("Partail_Data_Set.csv"); // change file as per needed
    if(ifile)
    {
        cout<<"Do you want to retain information which was previously there?[Y/N] : ";
        cin>>ch;
        if(ch=='Y'||ch=='y')
        {
            p.read_file();
            cout<<"\n\n>> Information Retained"<<endl<<endl;
        }
        else
        {
            cout<<"The data will reset!"<<endl;
            cout<<"Please conform, Do you don't want to retain?[Y/N] : ";
            cin>>ch;
            if(!(ch=='Y'&& ch=='y'))
            {
                p.read_file();
                cout<<"\n\n>> Information Retained"<<endl<<endl;
            }
        }
    }
    time_delay();
    system("cls");

    int option = 10;

    while (option != 0)
    {
        system("cls");
        title();
        main_menu();

        cout << "Enter your option that you want to continue with: ";
        cin >> option;
        cout << endl;

        system("cls");

        switch (option)
        {
        case 1:
            p.enter();
            time_delay();
            break;

        case 2:
            p.edit_delete();
            break;

        case 3:
            p.result();
            break;

        case 4:
            p.sort_by_detail();
            break;
        case 0:

            break;
        default:
            cout << "\n>> Invalid choice..!" << endl;
            time_delay();
            break;
        }
    }
    p.write_file(); // this will write information to a file
    animation_end();
    return 0;
}
