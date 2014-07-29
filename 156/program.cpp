#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
char arr[1001][25];
bool anagram(const char *arg1, const char *arg2)
{
	if(strlen(arg1) != strlen(arg2))
		return false;

	int freq[26] = {0};
	
	int len = strlen(arg1);
	for(int i = 0; i < len; ++i)
		freq[tolower(arg1[i])-'a']++;

	len = strlen(arg2);
	for(int i = 0; i < len; ++i)
		freq[tolower(arg2[i])-'a']--;

	for(int i = 0; i < 26; ++i)
	{
		if(freq[i] != 0)
			return false;
	}

	return true;
}

int main()
{

	int i = 0;
#ifdef DEBUG
	freopen("./sample.txt", "r", stdin);
#endif

	/* get a list of words to form the dictonary */ 
	
	while( scanf("%s", &arr[i][0]))
	{
		if(arr[i][0] == '#')
			break;
		i++;
	}
	
	/* no of words in dictonary */
	int cnt = i;

	/* start comparing with each other */
	bool found = true;
	for( int i = 0; i < cnt; ++i)
	{
		found = false;
		for(int j = i+1; j < cnt; ++j)
		{
			if( anagram(arr[i], arr[j]))
			{
				/* mark each matched word as zero */
				arr[j][0] = 0;
				found = true;
			}
		} 
		/* mark top level word as matched */
		if(found)
			arr[i][0] = 0;
	}
	/* sort the word remaining */
	for(int i = 0; i < cnt; ++i)
	{
		for(int j = i+1; j < cnt ; ++j)
		{
			if( strcmp(arr[i], arr[j]) > 0)
			{
				char tmp[25] = {0};
				strcpy(tmp, arr[i]);
				strcpy(arr[i], arr[j]);
				strcpy(arr[j], tmp);
			}
		}
	}
	/* print each non marked word as output */
	for(int i = 0; i < cnt; ++i)
	{
		if(arr[i][0] != 0)
			cout << arr[i] << endl;
	}
	return 0;
}
