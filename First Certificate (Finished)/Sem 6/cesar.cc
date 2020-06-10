#include <iostream>
#include <vector>
#include <string.h>
using namespace std;


char decale (char c , char debut , int decalage){
	
	 while (decalage < 0){
		 
		 decalage += 26;

		 }
		 
     		 
	return debut + (((c - debut) + decalage) % 26);
	
	}

char code ( char c , int d){
	
	
	if(c >= 'a' and c <= 'z') {
		
		
		return decale(c,'a',d);
		
		}
		else 
	if(c >= 'A' and c <= 'Z') {
		
		
		return decale(c,'A',d);
		
		}
		
		
		else {
		 return c;
	 }
	
	
	
	}

string code ( string chaine , int d){
	string res("");
		string var("");

	for ( size_t i = 0 ; i< chaine.size(); i ++ ) {
		
		if ( chaine[i] == ' ' ) {res.insert(i," ");}
		
		else {
			var = code(chaine[i],d);
			res.insert(i,var);
			
			
			
			}
		
		
		}
	return res;
	
	}
	


string decode ( string chaine , int d ) {
	
	
	
	string res("");
	string var("");
	for ( size_t i = 0 ; i< chaine.size(); i ++ ) {
		
		if ( chaine[i] == ' ' ) {res.insert(i," ");}
		
		else {
			var = code(chaine[i],-d);
			res.insert(i,var);
			
			
			
			}
		
		
		}
	return res;
	
	
	
	
	}

void afficher ( string c ){
	
	
	for (size_t i = 0 ; i<c.size();i++){
		
		cout << c[i];
		}
		cout << endl;
	
	}



int main(){
	string mes,cod,dec;
	int d(0);
	
	cout << "entrer ton message : " ;
	getline(cin, mes);
	cout << "entrer  le decalage : " ;
    cin >> d;

	cod = code(mes , d);
	cout << "ton message code est : "  ;
	afficher(cod);
	dec = decode(cod , d);
	cout << "ton message apres le decodage : "  ;
	afficher(dec);
	
	
	
	
	
return 0 ;
	}
