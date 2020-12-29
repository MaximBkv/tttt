#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{
    char s1[100];
    ifstream fin("task4.txt");
    fin.getline(s1, 100);
    fin.close();

    string s;
    s = string (s1);

    ofstream fout("task4.txt");
    fout << s <<endl;

    string:: iterator bg = s.begin(), en = s.end(), it;
    it = s.begin();

    int ind = s.rfind(" ");
    string key = "";
    it = s.end()-1;
    while (*it != ' ')
    {
        key = *it + key;
        --it;
    }

    int len = key.length();
    ind = -1;

    while(s.find(key, ind+1) != string::npos)
    {
        ind = s.find(key, ind+1);
        if (ind>0 && s[ind-1]==' ')
        {
            if (ind < len+s.length() && s[ind+len] == ' ')
                s.erase(ind, len);

        }
        else if (ind == 0)
        {
            if (ind < len+s.length() && s[ind+len] == ' ')
                s.erase(ind, len);

        }

    }
    it = s.begin();
    s.erase(s.length() - key.length(), key.length());
    fout << "Удалим последнее слово: " << s << endl;

    while(s.find("  ") != string::npos)
    {
        s.erase(s.find("  "), 1);
    }

    if(*(s.end()-1) == ' ')
       {
        s.erase(s.end()-1);
       }
    if(*bg == ' ')
    {
        s.erase(bg);
    }
    cout<<endl;
    fout <<  "Без пробелов: " << s << endl;

    it = s.begin();
    while (it != s.end())
    {
        if (*it == ' ')
            s.erase(it - 1);
        else
        ++it;
    }
    if (it == s.end()) (s.erase(it - 1));
    fout << "Удалим последнюю букву: " << s << endl;
    fout.close();
    return 0;
}
