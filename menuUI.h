#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class MenuUI
{
public:
    static string MainMenu()
    {
        cout << "Press 1 For Bubble Sort" << endl;
        cout << "Press 2 For Selection Sort" << endl;
        cout << "Press 3 For Insertion Sort" << endl;
        cout << "Press 4 For Merge Sort" << endl;
        cout << "Press 5 For Quick Sort" << endl;
        cout << "Press 6 For Heap Sort" << endl;
        cout << "Press 7 For Counting Sort" << endl;
        cout << "Press 8 For Radix Sort" << endl;
        cout << "Press 9 For Bucket Sort" << endl;
        cout << "Press 0 to Exit" << endl;
        cout << "Your Option >>";
        string op;
        cin >> op;
        return op;
    }

    static string subMenu1()
    {
        cout << "Press 1 For 100 records" << endl;
        cout << "Press 2 For 1000 records" << endl;
        cout << "Press 3 For 10000 records" << endl;
        cout << "Press 4 For 100000 records" << endl;
        cout << "Press 5 For 500000 records" << endl;
        cout << "Press 6 to Go back" << endl;
        cout << "Your Option >>";
        string op;
        cin >> op;
        return op;
    }

    static string subMenu2()
    {
        cout << "Press1 For sorting index " << endl;
        cout << "Press2 For sorting on the base of No of Employees" << endl;
        cout << "Press 3 to Go back" << endl;
        cout << "Your Option >>";
        string op;
        cin >> op;
        return op;
    }

    static void printRec(vector<Organization> orgs)
    {
        for (int i = 0; i < orgs.size(); i++)
        {
            print(orgs[i]);
        }
    }
    static void print(Organization org)
    {
        // cout << org.index << "    " << org.no_of_emp << endl;
        cout << org.index << " " << org.ID << " " << org.name << " " << org.country << " " << org.website << " " << org.description << " " << org.founded << " " << org.industry << " " << org.no_of_emp << endl;
    }
};
