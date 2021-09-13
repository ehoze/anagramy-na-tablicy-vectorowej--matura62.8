#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstring>
using namespace std;
int anagram_counter;
char w1[101], w2[101];
class zadanie682
{
                vector <string> slowa;
       			
        public:
                void wprowadz();
                void wypisz();
                void obliczanie();
                bool checkif_anagram(char *w1, char *w2);
                int zapiszDoPliku(const char *);             
};

void zadanie682::wprowadz()
{

		fstream plik;  
        string wprowadzany;
        plik.open("C:\\4PI Eryk\\anagramy\\dane_napisy.txt", ios::in); 
         if(plik.good()) 
            while(!plik.eof()) 
                {
                	plik >> wprowadzany;
                	slowa.push_back(wprowadzany);
                }
                   plik.close();   
}

bool zadanie682::checkif_anagram(char *w1, char *w2)
{
							/////// {
							///////		czêœæ sprawdzaj¹ca i obliczaj¹ca czy s³owa s¹ czy nie s¹ anagramami.
	
  	int wlen1 = strlen(w1), wlen2 = strlen(w2);
  	
  	
	if(wlen1 != wlen2)
	{
		cout << "Nie anagram\n";	
		return false;
	}
  	
  	int oblicz[127] = {}; 
  	
	  for(int i = 0; i < wlen1; i++)
  		oblicz[w1[i]]++;
  	
	  for(int i = 0; i < wlen1; i++)
  		oblicz[w2[i]]--;
  		
  	for(int i = 0; i < 127; i++)
  		if(oblicz[i] != 0) 
  		{
  			cout << "Nie anagram\n";	
  			return false; // < nie s¹ >
		}
  		
			
			
							/////// }
		
  return true; // < jeœli zwróci prawdê to s¹ >
} 


void zadanie682::wypisz()
{
		for (int i = 0; i < slowa.size(); i+=2)
		{
//			cout << slowa[i] << endl;
			
			char w1[slowa[i].length() + 1];
			strcpy(w1, slowa[i].c_str()); 
			
			char w2[slowa[i+1].length() + 1];
			strcpy(w2, slowa[i+1].c_str()); 
			
			cout << w1 << " " << w2 << endl;	
			        if(checkif_anagram(w1, w2))
					{
			        	anagram_counter++;	
					}	
					else
					{
						
					}
			checkif_anagram(w1, w2);
		}
		cout << endl << anagram_counter;
}

int zadanie682::zapiszDoPliku(const char *nazwa)
{	
        ofstream plik;
        plik.open(nazwa);
    	plik << "Anagramow w pliku tekstowym dane bylo: " << anagram_counter;
        plik.close();
}



int main()
{
	zadanie682 x;
    x.wprowadz();
    x.wypisz();
//    x.obliczanie();
    x.zapiszDoPliku("C:\\4PI Eryk\\anagramy\\wynik.txt");
    return 0;
}
