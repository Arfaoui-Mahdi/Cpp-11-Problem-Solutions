#include <iostream>
#include <vector>
using namespace std;

/*******************************************
 * Complétez le programme à partir d'ici.
 *******************************************/
 typedef vector<vector<int> > Carte;

struct Position {
	int i;
	int j;
	
	};
	
void ajoute_unique(vector<int>& ensemble, int valeur)
{
}
bool convexite_lignes(Carte& carte, vector<int> const& labels_bords)
{
return true;
}

bool convexite_lignes(Carte& carte)
{
	
return true;
}
void affiche(Carte const& carte){
	
	size_t L = carte.size();
	size_t C = carte[1].size();
	
	for(size_t i(0) ; i < L ; i++) {
		
		for(size_t j(0); j < C ; j++){
			
		     cout << carte[i][j];
			
			}
			cout<< endl;
		}
	cout << endl << "----" << endl;
	
	}
	
bool binaire(Carte const& carte){
	
	
	bool flag(true);
	
	
	
	for(auto ligne : carte){
		for(auto el : ligne){
			//cout << " element est : " << el << " et flag est : "<<flag << endl;
			if ( (el!=0) and (el!=1)){return false;}
			//cout << " element est : " << el << " et flag est : "<<flag << endl;
			}
		
		
		}
	
	
	return flag;
	
	}	
	

	
bool verifie_et_modifie(Carte& carte) {
	bool flag;
	//bool v;
	
	if((carte.empty())){
				cout << "Votre carte du terrain ne contient pas que des 0 et des 1." << endl;
                return false;
                }
	
	flag =  binaire(carte);
	
	if(flag == true){
		
		bool flag_B = false;
	bool flag_P = false;
	//int count(0);
	size_t pos;
	
	
	
	
	for(size_t i(0) ; i < carte.size(); i++) {
		
		  for(size_t j(0); j<carte[i].size(); j++){ 
			  
			if(j==0){flag_B=true;}
			else {flag_B=false;}
			
			
			
			
			if((carte[i][j] ==0) and (carte[i][j-1] == 1) and (j!=0)){ flag_P=true; pos = j; }
			
			if((carte[i][j] ==1) and (flag_B == false) and (flag_P=true)){
				for(size_t k(pos) ; k < j ; k++){
					
					carte[i][k] = 1;
					
					}
				flag_P=false;
				
				}
			
           }
           
		  
    }
		
		return true;
		
		}
		else {
			   
			    cout << "Votre carte du terrain ne contient pas que des 0 et des 1." << endl;
                return false;			
			 }
	
	
	}	
	
	
	
double longueur_cloture(Carte const& carte, double echelle )	{
	
	double unit=0.0;
	size_t L = carte.size();
	size_t C = carte[1].size();
	
	
	for(size_t i(0) ; i < L; ++i) {
		
		
		for(size_t j(0); j< C; ++j){
			
		 if(i==0){ //awel star
			 
			  if((j==0) and (carte[i][j] == 1)){  				   //mouraba3 mel fou9 al imin = 1 (A)
				  if(carte.size() == 1 and carte[0].size() != 1 ){
					   unit = unit +3.0;
					   } 
					   else if (carte.size() == 1 and carte[0].size() == 1){
						   
						   unit = unit +4.0;
						   }
					   else{
					   unit = unit + 2.0;  
				   }
					   } 

				  
			  else if (( j>0) and (j < C -1) and (carte[i][j] == 1)) { // ligne 1
				  
				  if(carte.size() == 1){
					  unit= unit +2.0;
				  if (carte[i][j-1] == 0){unit = unit +1.0;}
				  if (carte[i][j+1] == 0){unit = unit +1.0;}
					  
					  }
					  else {
				  unit++;
				  if (carte[i][j-1] == 0){unit = unit +1.0;}
				  if (carte[i][j+1] == 0){unit = unit +1.0;}
				  }
				   }
				   
			  else if ((j == (C - 1)) and ((carte[i][j] == 1))) { unit += 2.0; } //mouraba3 B   
			 
			 }	
			 
			 else if ((i>0) and (i < (L -1))) { //westani
				 
				  if((j==0) and (carte[i][j] == 1) ){ //ligne 4
					  
					  unit = unit +1.0; 
					  if (carte[i-1][j] == 0){unit = unit +1.0;}
				      if (carte[i+1][j] == 0){unit = unit +1.0;}  
				      
				  }
				  
				  else if ( (j > 0) and (j < C -1)){ //core
					  
					  if (carte[i][j] == 1){
						  	
						  if(carte[i-1][j] == 0 ) {unit = unit +1.0;}//fou9 l 1
						  
						  
						  if(carte[i+1][j] == 0 ) {unit = unit +1.0;}// ta7t 1
						  
						  
						  if(carte[i][j+1] == 0 ) {unit = unit +1.0;}//al imin 1
						  
						  
						  if(carte[i][j-1] == 0 ) {unit = unit +1.0;}//al isar 1
						  
						  		  
						  }
					  
					  }
					  
				 else if ((j == (C-1)) and (carte[i][j] == 1) ){ // ligne 2
					  
					  unit = unit +1.0; 
					  if (carte[i-1][j] == 0){unit = unit +1.0;}
				      if (carte[i+1][j] == 0){unit = unit +1.0;} 
					
					 
					 }  
				  
				  
				  		  
				 
			 }
			 
			 else if ( i == (L -1 ) ) { // ekher star
				 
				 if((j==0) and (carte[i][j] == 1)){  unit = unit + 2.0; } //mouraba3 D
				  
			  else if (( j>0) and (j < (C-1)) and (carte[i][j] == 1)) { // ligne 3
				  
				  unit = unit +1.0;
				  if (carte[i][j-1] == 0){unit = unit +1.0;}
				  if (carte[i][j+1] == 0){unit = unit +1.0;}
				  	  
				   }
				   
			  else if (j == (C - 1) and (carte[i][j] == 1)) { unit += 2.0; }
				  
				  
				 }
		
		
		
			
		}
			
	}
	
	 
	
	return unit*echelle;
	
	
	
	
	
	}
	double longueur_cloture(Carte const& carte, double echelle = 2.5 );
	
	
	//deeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeuuuxieme partie 
	
/*	
void marque_composantes(Carte& carte){
	vector<Position> tab;
	int composante(1);
	
	
	
	
	}
*/
          

/*******************************************
 * Ne rien modifier après cette ligne.
 *******************************************/

int main()
{
  Carte carte = {
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,0,0},
    {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,0,0},
    {0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,1,0,0},
    {0,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,0,0,0,0},
    {0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0},
    {0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0},
    {0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0},
    {0,0,0,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0},
    {0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0},
    {0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
  };

  cout << "Carte au départ :" << endl;
  affiche(carte);
  if (verifie_et_modifie(carte)) {
    cout << "Carte après modification :" << endl;
    affiche(carte);
    cout << "Il vous faut " << longueur_cloture(carte)
         << " mètres de clôture pour votre terrain."
         << endl;
  }

  return 0;
}
