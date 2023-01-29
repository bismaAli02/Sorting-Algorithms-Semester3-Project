#include <iostream>
#include <fstream>
using namespace std;

class Organization
{
public:
    int index;
    string ID;
    string name;
    string country;
    string website;
    string description;
    int founded;
    string industry;
    int no_of_emp;
    Organization(int index, string ID, string name, string country, string website, string description, int founded, string industry, int no_of_emp)
    {
        this->index = index;
        this->ID = ID;
        this->name = name;
        this->country = country;
        this->website = website;
        this->description = description;
        this->founded = founded;
        this->industry = industry;
        this->no_of_emp = no_of_emp;
    }
    Organization()
    {
        return;
    }
};