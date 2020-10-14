/*
1. create PI or LPS table for the pattern
2. comparing the character of text string with our pattern string
	if(txt[i] == pat[j])
    	i++
        j++
    if(j == len_pat)
    	print i-j
    else
    	if(j!=0)
    		j=lps[j-1];
        else
        	i++;
 3. Repeat the 2nd step until end of loops
*/
#include <iostream>
using namespace std;
void LPS(int *lps, string pat, int len)
{
    int count = 0, i = 1;
    lps[0] = 0;
    while (i < len)
    {
        if (pat[i] == pat[count])
        {
            count++;
            lps[i] = count;
            i++;
        }
        else
        {
            if (count != 0)
                count = lps[count - 1];
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}
void KMPSearch(string txt, string pat)
{
    int l_txt = txt.length();
    int l_pat = pat.length();
    int lps[l_pat];
    LPS(lps, pat, l_pat);
    int i = 0, j = 0;
    while (i < l_txt)
    {
        if (txt[i] == pat[j])
        {
            i++;
            j++;
        }
        if (j == l_pat)
        {
            cout << "Found pattern at index " << i - j << endl;
            j = lps[j - 1];
        }
        else if (i < l_txt && txt[i] != pat[j])
        {
            if (j != 0)
                j = lps[j - 1];
            else
                i = i + 1;
        }
    }
}
int main()
{
    string txt, pat;
    getline(cin, txt); //CDCDCDCDE
    cin >> pat;        //CDCDE
    KMPSearch(txt, pat);
    return 0;
}