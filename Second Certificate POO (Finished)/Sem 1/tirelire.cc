#include <iostream>
using namespace std;

/*******************************************
 * Complétez le programme à partir d'ici.
 *******************************************/

class Tirelire{
	
	double montant;
	
	public:
	
	
	double getMontant(){return montant;}
	
	void afficher(){  
		
		if(montant ==0) { cout << "Vous etes sans le sou."<<endl;}
		else {cout << "Vous avez : "<<montant <<" euros dans votre tirelire."<<endl;
		
		
		    }
		    }
	
	void remplir(double m){ if(m>0){montant = montant + m;}}
	void vider (){montant =0;}
	void secouer(){if(montant > 0) {cout <<   "Bing bing" << endl;}}
	void puiser(double m){
		if(m>0) {
		
		 if(m<montant) {montant = montant - m;}
		 else {vider();}
		}
		
		}
		
	bool montant_suffisant(double budget , double& solde){
		if(budget <= 0) { solde = montant;
			return true;}
		else if (montant > budget) {
			puiser(budget);
			solde = montant;
			return true;
			}
		else {
			
			solde = budget - montant;
			return false;
			
			}	
		
		
		}
		
	
	double calculerSolde(double budget){
		
		if(budget<= 0) {return montant;}
		else {
			
			return montant-budget;
			}
		
		
		}
	
	
	
	
	
	
	
	};









/*******************************************
 * Ne rien modifier après cette ligne.
 *******************************************/

int main()
{
  Tirelire piggy;

  piggy.vider();
  piggy.secouer();
  piggy.afficher();

  piggy.puiser(20.0);
  piggy.secouer();
  piggy.afficher();

  piggy.remplir(550.0);
  piggy.secouer();
  piggy.afficher();

  piggy.puiser(10.0);
  piggy.puiser(5.0);
  piggy.afficher();

  cout << endl;

  // le budget de vos vacances de rève.
  double budget;

  cout << "Donnez le budget de vos vacances : ";
  cin >> budget;

  // ce qui resterait dans la tirelire après les
  // vacances
  double solde(0.0);

  if (piggy.montant_suffisant(budget, solde)) {
    cout << "Vous êtes assez riche pour partir en vacances !"
         << endl
         << "Il vous restera " << solde << " euros"
         << " à la rentrée." << endl << endl;
    piggy.puiser(budget);
  } else {
    cout << "Il vous manque " << solde << " euros"
         << " pour partir en vacances !" << endl << endl;
  }
  return 0;
}
