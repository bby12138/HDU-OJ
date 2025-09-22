/*
HDU OJ 2072
 */
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    string str;
    while (getline(cin, str))
    {
        if (str == "#")
        {
            break;
        }
        while (!str.empty()&&str.back() == ' ')
        {
            str.pop_back();
        }
        while (!str.empty()&&str.front()==' ')
        {
            str.erase(0,1);
        }
        if (str.empty())
        {
            cout << 0 << endl;
            continue;
        }

        string word;
        vector<string> words;
        for (char c : str)
        {
            if (c != ' ')
            {
                word.push_back(c);
            }else
            {
                if (!word.empty())
                {
                    words.push_back(word);
                    word.clear();
                }
            }
        }
        if (!word.empty())
        {
            words.push_back(word);
        }


        int count = 0;
        vector<string> uniqueWords;
        for (const string& word1 : words)
        {
            bool is_duplicate = false;
            for (const string& uword: uniqueWords)
            {
                if (word1 == uword)
                {
                    is_duplicate = true;
                }
            }
            if (!is_duplicate)
            {
                uniqueWords.push_back(word1);
                count++;
            }
        }

        cout << count << endl;

    }
    return 0;
}