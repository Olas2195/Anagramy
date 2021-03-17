#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

using namespace std;

class anagram {
	ifstream plik1;
	ofstream plik2;
	string wyrazy;
	string slowo1;
	string slowo2;
	string s1;
	string s2;
	
	public:
		anagram();
		~anagram();
		
		void pobranie();
		void oddzielenie(string wyrazy);
		void dlugosc();
		string zamianaMale(string slowo);
		string stringSort(string slowo);
		void porownanie();
		void zapisF();
		void zapisT();
			
};

anagram::anagram() {
	plik1.open("we.txt");
	plik2.open("wy.txt");
}

void anagram::pobranie() {
	plik2<<"[\n";
	cout<<"[\n";
	if(plik1.good())
		while(!plik1.eof())	{
			getline(plik1, wyrazy);
			this->oddzielenie(wyrazy);
			this->dlugosc();			
		}
	plik2<<"]";
	cout<<"]";
}

void anagram::oddzielenie(string wyrazy) {
	stringstream s(wyrazy);
	
	s>>slowo1;
	s>>slowo2;
}

void anagram::dlugosc() {
	if(slowo1.length()==slowo2.length()) {
		s1 = this->zamianaMale(slowo1);
		s2 = this->zamianaMale(slowo2);
		
		s1 = this->stringSort(s1);
		s2 = this->stringSort(s2);
		
		this->porownanie();		
	}
	else {
		this->zapisF();
	}
}

string anagram::zamianaMale(string slowo) {
	for(int i=0; i<slowo.length(); i++) {
		if(slowo[i]>64 && slowo[i]<90)
			slowo[i]+=32;
	}
	return slowo;
}

string anagram::stringSort(string slowo) {
	int t[256];
	string wynik("");
	
	for(int i=0; i<256; i++)
		t[i]=0;
	
	for(int i=0; i<slowo.length(); i++)
		t[slowo[i]]++;			
	
	for(int i=0; i<256; i++) {
		if(t[i]>0)
			for(int j=1; j<=t[i]; j++)
				wynik+=i;
	}
	return wynik;	
}

void anagram::porownanie() {
	for(int i=0; i<s1.length(); i++) {
		if(s1[i]!=s2[i]) {
			this->zapisF();
			return;
		}
	}
	this->zapisT();
}

void anagram::zapisF() {
	cout<<"{\"slowo1\":\""<<slowo1<<"\",\"slowo2\":\""<<slowo2<<"\",\"anagram\":\"NIE\"},\n";
	plik2<<"{\"slowo1\":\""<<slowo1<<"\",\"slowo2\":\""<<slowo2<<"\",\"anagram\":\"NIE\"},\n";
}

void anagram::zapisT() {
	cout<<"{\"slowo1\":\""<<slowo1<<"\",\"slowo2\":\""<<slowo2<<"\",\"anagram\":\"TAK\"},\n";
	plik2<<"{\"slowo1\":\""<<slowo1<<"\",\"slowo2\":\""<<slowo2<<"\",\"anagram\":\"TAK\"},\n";	
}

anagram::~anagram() {
	plik1.close();
	plik2.close();
}

int main() {
	anagram a1;
	a1.pobranie();	
	return 0;
}

