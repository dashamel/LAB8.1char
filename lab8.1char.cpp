#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring> 
using namespace std;
int CountPairs(char* s) 
{
	int count = 0,
		pos = 0;  
	char* t;
	while (t = strchr(s + pos, 'aa')) 
	{
		pos = t - s + 1;  
		if ((s[pos + 1] == 'a') || 
			(s[pos + 1] == 'b') ||
			(s[pos + 1] == 'c'))  
			count++;
	}
	return count;  
}


char* Change(char* s) // s = �������� �� ������� ����� 
{
    char* t = new char[strlen(s) * 3 / 2 + 1]; // ���'��� ��� ����� �����
    char* p;
    int pos1 = 0, // pos1 = ������� ������� ������
        pos2 = 0; // ���� ������ 
    *t = 0; 

    while (s[pos1] != '\0') // ���� �� ����� ����� 
    {
        if ((s[pos1] == 'a' && s[pos1 + 1] == 'a') ||
            (s[pos1] == 'b' && s[pos1 + 1] == 'b') ||
            (s[pos1] == 'c' && s[pos1 + 1] == 'c'))
        {
            strcat(t, "***"); 
            pos1 += 2; 
        }
        else
        {
            strncat(t, s + pos1, 1); // ���� 
            pos1++; 
        }
    }

    strcpy(s, t); 
    delete[] t; 
    return s;   
}


int main()
{
	char str[101];
		cout << "Enter string:" << endl; 
	cin.getline(str, 100);
	cout << "String contained " << CountPairs(str) << " groups of 'aa', 'bb' or 'cc'" << endl;  
	char* dest = new char[151];
	dest = Change(str);
	cout << "Modified string (param) : " << str << endl;
	cout << "Modified string (result): " << dest << endl;
	return 0;
}
