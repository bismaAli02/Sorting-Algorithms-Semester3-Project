#include <iostream>
#include <conio.h>
#include <fstream>
#include <string>
#include <chrono>
#include <vector>
#include <sstream>
#include <queue>
#include <chrono>
#include "Organization.h"
#include "OrganizationDL.h"
#include "menuUI.h"
using namespace std;
vector<Organization> organizations;

void sortSelector(int sortType, string fileNo, int sortBase)
{
    organizations.clear();
    string fileName = "Text Files\\organizations-" + fileNo + ".csv";
    organizations = OrganizationDL::ReadFromFile(organizations, fileName);
    auto start = chrono::steady_clock::now();
    if (sortType == 1)
    {
        if (sortBase == 1)
            organizations = OrganizationDL::bubbleSort(organizations);
        else
        {
            organizations = OrganizationDL::bubbleSort2(organizations);
        }
    }
    else if (sortType == 2)
    {
        if (sortBase == 1)
            organizations = OrganizationDL::selectionSort(organizations);
        else
            organizations = OrganizationDL::selectionSort2(organizations);
    }
    else if (sortType == 3)
    {
        if (sortBase == 1)
            organizations = OrganizationDL::insertionSort(organizations);
        else
            organizations = OrganizationDL::insertionSort2(organizations);
    }
    else if (sortType == 4)
    {
        if (sortBase == 1)
            organizations = OrganizationDL::mergeSort(organizations, 0, organizations.size() - 1);
        else
            organizations = OrganizationDL::mergeSort2(organizations, 0, organizations.size() - 1);
    }
    else if (sortType == 5)
    {
        if (sortBase == 1)
            organizations = OrganizationDL::quickSort(organizations);
        else
            organizations = OrganizationDL::quickSort2(organizations);
    }
    else if (sortType == 6)
    {
        if (sortBase == 1)
            organizations = OrganizationDL::heapSort(organizations, organizations.size());
        else
            organizations = OrganizationDL::heapSort2(organizations, organizations.size());
    }
    else if (sortType == 7)
    {
        if (sortBase == 1)
            organizations = OrganizationDL::countingSort(organizations);
        else
            organizations = OrganizationDL::countingSort2(organizations);
    }
    else if (sortType == 8)
    {
        if (sortBase == 1)
            organizations = OrganizationDL::radixSort(organizations);
        else
            organizations = OrganizationDL::radixSort2(organizations);
    }
    else if (sortType == 9)
    {
        if (sortBase == 1)
            organizations = OrganizationDL::bucketSort(organizations);
        else
            organizations = OrganizationDL::bucketSort2(organizations);
    }
    auto end = chrono::steady_clock::now();
    // MenuUI::printRec(organizations);

    OrganizationDL::writeInFile(organizations, fileNo, sortBase);
    auto diff = end - start;
    double time = chrono::duration<double, milli>(diff).count();
    cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;
}
main()
{
    int sortType;
    string fileNo;
    int sortBase;
    string op = "";
    while (true)
    {
        op = MenuUI::MainMenu();
        system("cls");
        if (op == "1" || op == "2" || op == "3" || op == "4" || op == "5" || op == "6" || op == "7" || op == "8" || op == "9")
        {
            sortType = stoi(op);
            string op1 = MenuUI::subMenu1();
            system("cls");
            if (op1 == "1")
            {
                fileNo = "100";
            }
            else if (op1 == "2")
            {
                fileNo = "1000";
            }
            else if (op1 == "3")
            {
                fileNo = "10000";
            }
            else if (op1 == "4")
            {
                fileNo = "100000";
            }
            else if (op1 == "5")
            {
                fileNo = "500000";
            }
            else if (op1 == "6")
            {
            }
            else
            {
                cout << "You choose wrong option";
            }
            if (op1 == "1" || op1 == "2" || op1 == "3" || op1 == "4" || op1 == "5")
            {
                string op2 = MenuUI::subMenu2();
                system("cls");
                if (op2 == "1" || op2 == "2")
                {
                    sortBase = stoi(op2);
                    sortSelector(sortType, fileNo, sortBase);
                }
            }
        }
        else if (op == "0")
        {
            break;
        }
        else
        {
            cout << "You choose wrong option";
        }
    }
}
