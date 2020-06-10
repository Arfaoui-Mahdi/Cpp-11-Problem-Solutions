
#include <iostream>
using namespace std;

int demander_annee() {
int year = 0;	
	 do{
		cout << "Entrez une annee (1583-4000) : " ;
		cin >> year;
		 
		 }while(year<1583 or year > 4000);
	
	return year;
	}
	
	
int date_Paques(int year){
	
	int siecle,q,M,N,d,e,jour,p;
	
	
	siecle = year/100;
	p= (13+8*siecle)/25;
	q=siecle/4;
	M=(15 - p + siecle-q)%30;
	N=4+siecle-(q%7);
	d = (M+19*(year%19))%30;
	e = (2 * (year % 4) + 4 * (year % 7) + 6 * d + N) % 7;
	jour = e+d+22;
	if((e == 6)and((d==29) or ((d==28) and (((11*(M+1))%30)<19))))
	{ 
		jour = jour -7 ;
		
		
		 }
	
	
	
	
		
	
	return jour;
	}



void affiche_date(int year , int day){
	
	if (day <= 31) {
	
	cout <<"Date de Paques en "<<year<<" : " <<day<<" mars"<<endl;
	
	}
	else{
			cout <<"Date de Paques en "<<year<<" : " <<day-31<<" avril"<<endl;
	
		}
	
	
	
	}






int main(){
	
	int annee = demander_annee();
	int jour = date_Paques(annee);
	affiche_date(annee , jour);
	
	return 0;
	}
