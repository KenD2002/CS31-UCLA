#include <string>
#include <iostream>

using namespace std;

int locateMaximum(const string array[], int n);
bool matchingValuesTogether(const string array[], int n);
bool hasDuplicates(const string array[], int n);
string majorityElement(const string array[], int n);
bool hasReverse(const string array[], int n);
int findLastOccurrence(const string array[], int n, string target);
int countFloatingPointValues(const string array[], int n);
int replaceAll(string array[], int n, char letterToReplace, char letterToFill);


int main()
{

    return 0;
}


int locateMaximum(const string array[], int n)
{
    if(n <= 0)
    {
        return -1;
    }
    
    int maxIdx = 0;
    for(int i = 1; i < n; i ++)
    {
        if(array[i] > array[maxIdx])
        {
            maxIdx = i;
        }
    }
    
    return maxIdx;
}

bool matchingValuesTogether(const string array[], int n)
{
    if(n <= 0)
    {
        return false;
    }
    
    for(int i = 1; i < n; i ++)
    {
        for(int j = 0; j < i; j ++)
        {
            if(array[j] == array[i])
            {
                for(int k = j + 1; k < i + 1; j ++)
                {
                    if(array[k] != array[k-1])
                    {
                        return false;
                    }
                }
            }
        }
    }
    
    return true;
}

bool hasDuplicates(const string array[], int n)
{
    if(n <= 0)
    {
        return false;
    }
    
    for(int i = 1; i < n; i ++)
    {
        for(int j = 0; j < i; j ++)
        {
            if(array[i] == array[j])
            {
                return true;
            }
        }
    }
    
    return false;
}

string majorityElement(const string array[], int n)
{
    if(n <= 0 || !hasDuplicates(array, n))
    {
        return "";
    }
    
    if(n == 1)
    {
        return array[0];
    }
    
    int count = 1;
    for(int i = 1; i < n; i ++)
    {
        for(int j = 0; j < i; j ++)
        {
            if(array[i] == array[j])
            {
                count ++;
                if(count > n / 2.0)
                {
                    return array[i];
                }
            }
        }
        count = 1;
    }
    
    return "";
}

bool hasReverse(const string array[], int n)
{
    if(n <= 0)
    {
        return false;
    }
    
    int emptyNum = 0;
    for(int m = 0; m < n; m ++)
    {
        if(array[m] == "")
        {
            emptyNum ++;
        }
        if(emptyNum == 2)
        {
            return true;
        }
    }
    
    for(int i = 1; i < n; i ++)
    {
        for(int j = 0; j < i; j ++)
        {
            if(array[i].size() == array[j].size())
            {
                for(int k = 0; k < array[i].size(); k ++)
                {
                    if(array[i].at(k) != array[j].at(k))
                    {
                        break;
                    }
                    if(k == array[i].size() - 1)
                    {
                        return true;
                    }
                }
            }
        }
    }
    
    return false;
}

int findLastOccurrence(const string array[], int n, string target)
{
    if(n <= 0)
    {
        return -1;
    }
    
    for(int m = 0; m < n; m ++)
    {
        if(array[m] == target)
        {
            break;
        }
        if(m == n - 1)
        {
            return -1;
        }
    }
    
    int lastIdx = 0;
    for(int i = 0; i < n; i ++)
    {
        if(array[i] == target)
        {
            lastIdx = i;
        }
    }
    
    return lastIdx;
}

int countFloatingPointValues(const string array[], int n)
{
    if(n <= 0)
    {
        return -1;
    }
    
    int count = 0;
    for(int i = 0; i < n; i ++)
    {
        if(array[i] == "")
        {
            continue;
        }
        
        int pointNum = 0;
        for(int j = 0; j < array[i].size(); j ++)
        {
            if(array[i].at(j) == '.')
            {
                pointNum ++;
            }
            
            if(pointNum == 2)
            {
                break;
            }
            
            else if((!isdigit(array[i].at(j))) && (array[i].at(j) != '+') && (array[i].at(j) != '-') && (array[i].at(j) != '.'))
            {
                break;
            }
            
            else if((array[i].at(j) == '+' || array[i].at(j) == '-') && j >= 1)
            {
                break;
            }
            
            else if(j == array[i].size()-1)
            {
                count ++;
            }
        }
    }
    
    return count;
}

int replaceAll(string array[], int n, char letterToReplace, char letterToFill)
{
    if(n <= 0)
    {
        return -1;
    }
    
    int replaceNum = 0;
    for(int i = 0; i < n; i ++)
    {
        if(array[i] == "")
        {
            continue;
        }
        
        for(int j = 0; j < array[i].size(); j ++)
        {
            if(array[i].at(j) == letterToReplace)
            {
                array[i].at(j) = letterToFill;
                replaceNum ++;
            }
        }
    }
    
    return replaceNum;
}
