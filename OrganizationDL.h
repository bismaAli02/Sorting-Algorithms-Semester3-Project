#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class OrganizationDL
{
public:
    static vector<Organization> organizations;
    static Organization ParseRecord(string line)
    {
        string index;
        string ID;
        string name;
        string country;
        string website;
        string description;
        string founded;
        string industry;
        string no_of_emp;
        stringstream lineStream(line);
        getline(lineStream, index, ',');
        getline(lineStream, ID, ',');
        getline(lineStream, name, ',');
        getline(lineStream, country, ',');
        getline(lineStream, website, ',');
        getline(lineStream, description, ',');
        getline(lineStream, founded, ',');
        getline(lineStream, industry, ',');
        getline(lineStream, no_of_emp, ',');
        Organization org = Organization(stoi(index), ID, name, country, website, description, stoi(founded), industry, stoi(no_of_emp));
        return org;
    }
    static vector<Organization> ReadFromFile(vector<Organization> organizations, string filename)
    {
        int count = 0;
        ifstream file;
        file.open(filename);
        string line;
        while (getline(file, line))
        {
            if (count != 0)
            {
                Organization org = ParseRecord(line);
                organizations.push_back(org);
            }
            count++;
        }
        file.close();
        return organizations;
    }
    static void writeInFile(vector<Organization> organizations, string fileNo, int sortBase)
    {
        string fileName = "Sorted Text Files\\organizations-" + to_string(sortBase) + "-" + fileNo + ".csv";
        fstream fs;
        fs.open(fileName, ios::out);
        for (int i = 0; i < organizations.size(); i++)
        {
            fs << organizations[i].index << "," << organizations[i].ID << "," << organizations[i].name << "," << organizations[i].website << "," << organizations[i].country << "," << organizations[i].description << "," << organizations[i].founded << "," << organizations[i].industry << "," << organizations[i].no_of_emp << endl;
        }
        fs.close();
    }

    static vector<Organization> bubbleSort2(vector<Organization> &organizations)
    {
        for (int x = 0; x < organizations.size() - 1; x++)
        {
            bool isSwapped = false;
            for (int y = 0; y < organizations.size() - x - 1; y++)
            {
                if (organizations[y].no_of_emp > organizations[y + 1].no_of_emp)
                {
                    swap(organizations[y], organizations[y + 1]);
                    isSwapped = true;
                }
            }
            if (!isSwapped)
            {
                break;
            }
        }
        return organizations;
    }
    static int findMinimum2(vector<Organization> orgs, int start, int end)
    {
        int min = orgs[start].no_of_emp;
        int minIdx = start;
        for (int x = start; x < end; x++)
        {
            if (min > orgs[x].no_of_emp)
            {
                min = orgs[x].no_of_emp;
                minIdx = x;
            }
        }
        return minIdx;
    }
    static vector<Organization> selectionSort2(vector<Organization> &organizations)
    {
        for (int x = 0; x < organizations.size() - 1; x++)
        {
            int minIdx = findMinimum2(organizations, x, organizations.size());
            swap(organizations[x], organizations[minIdx]);
        }
        return organizations;
    }
    static vector<Organization> insertionSort2(vector<Organization> &organizations)
    {
        for (int x = 1; x < organizations.size(); x++)
        {
            Organization key = organizations[x];
            int y = x - 1;
            while (y >= 0 && organizations[y].no_of_emp > key.no_of_emp)
            {
                organizations[y + 1] = organizations[y];
                y--;
            }
            organizations[y + 1] = key;
        }
        return organizations;
    }
    static void merge2(vector<Organization> &organizations, int start, int mid, int end)
    {
        int i = start;
        int j = mid + 1;
        queue<Organization> tempArr;
        while (i <= mid && j <= end)
        {
            if (organizations[i].no_of_emp < organizations[j].no_of_emp)
            {
                tempArr.push(organizations[i]);
                i++;
            }
            else
            {
                tempArr.push(organizations[j]);
                j++;
            }
        }
        while (i <= mid)
        {
            tempArr.push(organizations[i]);
            i++;
        }
        while (j <= end)
        {
            tempArr.push(organizations[j]);
            j++;
        }
        for (int x = start; x <= end; x++)
        {
            organizations[x] = tempArr.front();
            tempArr.pop();
        }
    }
    static vector<Organization> mergeSort2(vector<Organization> &organizations, int start, int end)
    {
        if (start < end)
        {
            int mid = (start + end) / 2;
            mergeSort2(organizations, start, mid);
            mergeSort2(organizations, mid + 1, end);
            merge2(organizations, start, mid, end);
        }
        return organizations;
    }

    static vector<Organization> bubbleSort(vector<Organization> &organizations)
    {
        for (int x = 0; x < organizations.size() - 1; x++)
        {
            cout << organizations.size();
            bool isSwapped = false;
            for (int y = 0; y < organizations.size() - x - 1; y++)
            {
                if (organizations[y].index > organizations[y + 1].index)
                {
                    swap(organizations[y], organizations[y + 1]);
                    isSwapped = true;
                }
            }
            if (!isSwapped)
            {
                break;
            }
        }
        return organizations;
    }
    static int findMinimum(vector<Organization> orgs, int start, int end)
    {
        int min = orgs[start].index;
        int minIndex = start;
        for (int x = start; x < end; x++)
        {
            if (min > orgs[x].index)
            {
                min = orgs[x].index;
                minIndex = x;
            }
        }
        return minIndex;
    }
    static vector<Organization> selectionSort(vector<Organization> &organizations)
    {
        for (int x = 0; x < organizations.size() - 1; x++)
        {
            int minIndex = findMinimum(organizations, x, organizations.size());
            swap(organizations[x], organizations[minIndex]);
        }
        return organizations;
    }
    static vector<Organization> insertionSort(vector<Organization> &organizations)
    {
        for (int x = 1; x < organizations.size(); x++)
        {
            Organization key = organizations[x];
            int y = x - 1;
            while (y >= 0 && organizations[y].index > key.index)
            {
                organizations[y + 1] = organizations[y];
                y--;
            }
            organizations[y + 1] = key;
        }
        return organizations;
    }
    static void merge(vector<Organization> &organizations, int start, int mid, int end)
    {
        int i = start;
        int j = mid + 1;
        queue<Organization> tempArr;
        while (i <= mid && j <= end)
        {
            if (organizations[i].index < organizations[j].index)
            {
                tempArr.push(organizations[i]);
                i++;
            }
            else
            {
                tempArr.push(organizations[j]);
                j++;
            }
        }
        while (i <= mid)
        {
            tempArr.push(organizations[i]);
            i++;
        }
        while (j <= end)
        {
            tempArr.push(organizations[j]);
            j++;
        }
        for (int x = start; x <= end; x++)
        {
            organizations[x] = tempArr.front();
            tempArr.pop();
        }
    }
    static vector<Organization> mergeSort(vector<Organization> &organizations, int start, int end)
    {
        if (start < end)
        {
            int mid = (start + end) / 2;
            mergeSort(organizations, start, mid);
            mergeSort(organizations, mid + 1, end);
            merge(organizations, start, mid, end);
        }
        return organizations;
    }

    static int partition(vector<Organization> &organizations, int start, int end, int pivot)
    {
        int left = start;
        int right = end;
        while (left <= right)
        {
            while (organizations[left].index < organizations[pivot].index && left <= end)
                left++;
            while (organizations[right].index >= organizations[pivot].index && right >= start)
                right--;
            if (left < right)
                swap(organizations[left], organizations[right]);
        }
        swap(organizations[right], organizations[pivot]);
        return right;
    }
    static void quickSort(vector<Organization> &organizations, int start, int end)
    {
        if (start < end)
        {
            int pivot = start;
            int mid = partition(organizations, start + 1, end, pivot);
            quickSort(organizations, start, mid - 1);
            quickSort(organizations, mid + 1, end);
        }
    }
    static vector<Organization> quickSort(vector<Organization> &organizations)
    {
        quickSort(organizations, 0, organizations.size());
        return organizations;
    }

    static int leftChildIndex(int i)
    {
        return (2 * i) + 1;
    }
    static int rightChildIndex(int i)
    {
        return (2 * i) + 2;
    }

    static void heapify(vector<Organization> &organizations, int size, int index)
    {
        int maxIndex;
        while (true)
        {
            int lIdx = leftChildIndex(index);
            int rIdx = rightChildIndex(index);
            if (rIdx >= size)
            {
                if (lIdx >= size)
                    return;
                else
                    maxIndex = lIdx;
            }
            else
            {
                if (organizations[lIdx].index >= organizations[rIdx].index)
                    maxIndex = lIdx;
                else
                    maxIndex = rIdx;
            }
            if (organizations[index].index < organizations[maxIndex].index)
            {
                swap(organizations[index], organizations[maxIndex]);
                index = maxIndex;
            }
            else
                return;
        }
    }

    static vector<Organization> heapSort(vector<Organization> &organizations, int size)
    {
        for (int x = (size / 2) - 1; x >= 0; x--)
        {
            heapify(organizations, size, x);
        }
        for (int x = size - 1; x > 0; x--)
        {
            swap(organizations[0], organizations[x]);
            heapify(organizations, x, 0);
        }
        return organizations;
    }
    static int FindMaximum(vector<Organization> &organizations)
    {
        int maxVal = organizations[0].index;
        for (int i = 0; i < organizations.size(); i++)
        {
            if (maxVal < organizations[i].index)
            {
                maxVal = organizations[i].index;
            }
        }

        return maxVal;
    }
    static int FindMaximum2(vector<Organization> &organizations)
    {
        int maxVal = organizations[0].no_of_emp;
        for (int i = 0; i < organizations.size(); i++)
        {
            if (maxVal < organizations[i].no_of_emp)
            {
                maxVal = organizations[i].no_of_emp;
            }
        }

        return maxVal;
    }

    static vector<Organization> countingSort(vector<Organization> &organizations)
    {
        int max = FindMaximum(organizations);
        vector<int> count(max + 1);
        vector<Organization> output(organizations.size());
        for (int x = 0; x < organizations.size(); x++)
        {
            count[organizations[x].index]++;
        }
        for (int x = 1; x < count.size(); x++)
        {
            count[x] = count[x - 1] + count[x];
        }
        for (int x = organizations.size() - 1; x >= 0; x--)
        {
            int index = count[organizations[x].index] - 1;
            count[organizations[x].index]--;
            output[index] = organizations[x];
        }
        for (int x = 0; x < output.size(); x++)
        {
            organizations[x] = output[x];
        }
        return organizations;
    }

    static void countingSort(vector<Organization> &organizations, int place)
    {
        vector<int> count(10);
        vector<Organization> output(organizations.size());
        for (int x = 0; x < organizations.size(); x++)
        {
            count[(organizations[x].index / place) % 10]++;
        }
        for (int x = 1; x < count.size(); x++)
        {
            count[x] = count[x - 1] + count[x];
        }
        for (int x = organizations.size() - 1; x >= 0; x--)
        {
            int index = count[(organizations[x].index / place) % 10] - 1;
            count[(organizations[x].index / place) % 10]--;
            output[index] = organizations[x];
        }
        for (int x = 0; x < output.size(); x++)
        {
            organizations[x] = output[x];
        }
    }
    static vector<Organization> radixSort(vector<Organization> &organizations)
    {
        int max = FindMaximum(organizations);
        int place = 1;
        while ((max / place) > 0)
        {
            countingSort(organizations, place);
            place = place * 10;
        }
        return organizations;
    }

    static vector<Organization> bucketSort(vector<Organization> &organizations)
    {
        vector<vector<Organization>> bucket(organizations.size());
        for (int x = 0; x < organizations.size(); x++)
        {
            bucket[int((organizations[x].index * organizations.size()) % organizations.size())].push_back(organizations[x]);
        }
        for (int x = 0; x < bucket.size(); x++)
        {
            insertionSort(bucket[x]);
        }
        int index = 0;
        for (int x = 0; x < bucket.size(); x++)
        {
            for (int y = 0; y < bucket[x].size(); y++)
            {
                organizations[index] = bucket[x][y];
                index++;
            }
        }
        return organizations;
    }
    static int partition2(vector<Organization> &organizations, int start, int end, int pivot)
    {
        int left = start;
        int right = end;
        while (left <= right)
        {
            while (left <= end && organizations[left].no_of_emp < organizations[pivot].no_of_emp)
                left++;
            while (right >= start && organizations[right].no_of_emp >= organizations[pivot].no_of_emp)
                right--;
            if (left < right)
                swap(organizations[left], organizations[right]);
        }
        swap(organizations[right], organizations[pivot]);
        return right;
    }
    static void quickSort2(vector<Organization> &organizations, int start, int end)
    {
        if (start < end)
        {
            int pivot = start;
            int mid = partition2(organizations, start + 1, end, pivot);
            quickSort2(organizations, start, mid - 1);
            quickSort2(organizations, mid + 1, end);
        }
    }
    static vector<Organization> quickSort2(vector<Organization> &organizations)
    {
        quickSort2(organizations, 0, organizations.size());
        return organizations;
    }
    static void heapify2(vector<Organization> &organizations, int size, int index)
    {
        int maxIndex;
        while (true)
        {
            int lIdx = leftChildIndex(index);
            int rIdx = rightChildIndex(index);
            if (rIdx >= size)
            {
                if (lIdx >= size)
                    return;
                else
                    maxIndex = lIdx;
            }
            else
            {
                if (organizations[lIdx].no_of_emp >= organizations[rIdx].no_of_emp)
                    maxIndex = lIdx;
                else
                    maxIndex = rIdx;
            }
            if (organizations[index].no_of_emp < organizations[maxIndex].no_of_emp)
            {
                swap(organizations[index], organizations[maxIndex]);
                index = maxIndex;
            }
            else
                return;
        }
    }

    static vector<Organization> heapSort2(vector<Organization> &organizations, int size)
    {
        for (int x = (size / 2) - 1; x >= 0; x--)
        {
            heapify2(organizations, size, x);
        }
        for (int x = size - 1; x > 0; x--)
        {
            swap(organizations[0], organizations[x]);
            heapify2(organizations, x, 0);
        }
        return organizations;
    }

    static vector<Organization> countingSort2(vector<Organization> &organizations)
    {
        int max = FindMaximum2(organizations);
        vector<int> count(max + 1);
        vector<Organization> output(organizations.size());
        for (int x = 0; x < organizations.size(); x++)
        {
            count[organizations[x].no_of_emp]++;
        }
        for (int x = 1; x < count.size(); x++)
        {
            count[x] = count[x - 1] + count[x];
        }
        for (int x = organizations.size() - 1; x >= 0; x--)
        {
            int index = count[organizations[x].no_of_emp] - 1;
            count[organizations[x].no_of_emp]--;
            output[index] = organizations[x];
        }
        for (int x = 0; x < output.size(); x++)
        {
            organizations[x] = output[x];
        }
        return organizations;
    }
    static void countingSort2(vector<Organization> &organizations, int place)
    {
        vector<int> count(10);
        vector<Organization> output(organizations.size());
        for (int x = 0; x < organizations.size(); x++)
        {
            count[(organizations[x].no_of_emp / place) % 10]++;
        }
        for (int x = 1; x < count.size(); x++)
        {
            count[x] = count[x - 1] + count[x];
        }
        for (int x = organizations.size() - 1; x >= 0; x--)
        {
            int index = count[(organizations[x].no_of_emp / place) % 10] - 1;
            count[(organizations[x].no_of_emp / place) % 10]--;
            output[index] = organizations[x];
        }
        for (int x = 0; x < output.size(); x++)
        {
            organizations[x] = output[x];
        }
    }
    static vector<Organization> radixSort2(vector<Organization> &organizations)
    {
        int max = FindMaximum2(organizations);
        int place = 1;
        while ((max / place) > 0)
        {
            countingSort2(organizations, place);
            place = place * 10;
        }
        return organizations;
    }

    static vector<Organization> bucketSort2(vector<Organization> &organizations)
    {
        vector<vector<Organization>> bucket(organizations.size());
        for (int x = 0; x < organizations.size(); x++)
        {
            bucket[int((organizations[x].no_of_emp * organizations.size()) % organizations.size())].push_back(organizations[x]);
        }
        for (int x = 0; x < bucket.size(); x++)
        {
            insertionSort2(bucket[x]);
        }
        int index = 0;
        for (int x = 0; x < bucket.size(); x++)
        {
            for (int y = 0; y < bucket[x].size(); y++)
            {
                organizations[index] = bucket[x][y];
                index++;
            }
        }
        return organizations;
    }
};