#include <iostream>
#include <iomanip> // pour setprecision()
using namespace std;

int main()
{
  // Réduire le format d'affichage
  cout << setprecision(4);

  // Paramètres
  double taux_croissance_lapins(0.3);
  double taux_attaque(0.01);
  double taux_croissance_renards(0.008);
  double taux_mortalite(0.1);
  int duree(50);

  double renards_i(0.0);
  double lapins_i(0.0);

  /*****************************************************
   * Compléter le code à partir d'ici
   *****************************************************/

  // ===== PARTIE 1 =====
  // Saisie des populations initiales
do{
  cout << "Combien de renards au départ (>= 2) ? ";
  cin >> renards_i ;
 }while ( renards_i < 2 );
 
 do{ 
  cout << "Combien de lapins au départ  (>= 5) ? ";
  cin >> lapins_i ;
}while (lapins_i < 5);


  // ===== PARTIE 2 =====
  // Première simulation
  cout <<  endl << "***** Le taux d'attaque vaut "<< taux_attaque * 100 << "%" <<  endl;
  
  double nb_lapins ;
  double nb_renards;
  nb_lapins =lapins_i;
  nb_renards=renards_i;
  double lapinsN,renardsN;
  lapinsN = lapins_i;
  renardsN = renards_i;

for ( int i = 1 ; i <= duree ; i++) {
	
	nb_lapins = lapinsN * (1.0 + taux_croissance_lapins - taux_attaque * renardsN );
	nb_renards = renardsN * (1.0 + taux_attaque * lapinsN * taux_croissance_renards - taux_mortalite);


    lapinsN = nb_lapins;
    renardsN = nb_renards;

  if(lapinsN < 0 ) { lapinsN = 0 ; }
  if(renardsN < 0 ) { renardsN = 0; }
  if(nb_lapins < 0 ) { nb_lapins = 0 ; }
  if(nb_renards < 0 ) { nb_renards = 0; }

  cout << "Après "<< i << " mois, il y a "<<nb_lapins <<" lapins et "<<nb_renards <<" renards" << endl;
	
	}

  // ===== PARTIE 3 =====
  // Variation du taux d'attaque
  cout << endl;
  
double tauI(0.0);
double tauF(0.0);

do{
  cout << "taux d'attaque au départ en % (entre 0.5 et 6) ? ";
  cin >> tauI;
}while( tauI <0.5 or tauI > 6);
  
do{
  cout << "taux d'attaque à la fin  en % (entre " << tauI;
  cout << " et 6) ? ";
  cin >> tauF ;
}while ( tauF < tauI or tauF > 6);
  
  
  
  
  nb_lapins =lapins_i;
  nb_renards=renards_i;

  lapinsN = lapins_i;
  renardsN = renards_i;

 
  int ind_L(0),ind_R(0);
for ( taux_attaque = tauI ; taux_attaque < tauF ; taux_attaque++){
	
		 cout << "\n***** Le taux d’attaque vaut " << taux_attaque <<"%"<< endl;
	
	int i;
  for (  i = 1 ; i <= duree ; ++i) {
	
	nb_lapins = lapinsN * (1.0 + taux_croissance_lapins - taux_attaque/100 * renardsN );
	nb_renards = renardsN * (1.0 + taux_attaque /100* lapinsN * taux_croissance_renards - taux_mortalite);


    lapinsN = nb_lapins;
    renardsN = nb_renards;
    
      if(nb_lapins < 0 ) { nb_lapins = 0 ; }
  if(nb_renards < 0 ) { nb_renards = 0; }
    
if ( nb_renards <= 5){ ind_R = 1;}
if (nb_renards <= 2) {ind_R = 2; break;}
if (nb_lapins <=5 ) {ind_L = 1;}
if (nb_lapins <=2 ) {ind_L = 2; break ;}

if ((ind_R == 1) and (nb_renards > 5) ) { ind_R = 3 ; }
if ((ind_L == 1 )and (nb_lapins > 5 )) { ind_L = 3 ; }


	
	}
	
	
	
	 //******************************************
	 
	 if ( i == 51) { i = 50;}
	cout << "Après "<< i <<" mois, il y a " << nb_lapins <<" lapins et " << nb_renards <<" renards" <<endl;
	
	
	
	if ( ind_R!=1 and ind_R!=2 and ind_R!=3 and ind_L!=1 and ind_L!=2 and ind_L!=3) {
		
		
		cout << "Les lapins et les renards ont des populations stables." << endl;
		}
		
		else{
	 
if ( ind_R == 2) { cout << "Les renards ont été en voie d'extinction" << endl;
	               cout << "et les renards ont disparu :-(" << endl; }

else if ( ind_R == 3) { cout << "Les renards ont été en voie d'extinction" << endl;
	                    cout << "mais la population est remontée ! Ouf !" << endl;}
	                    
	                    

	 
	 
	 
	 
	 
if ( ind_L == 2) { cout << "Les lapins ont été en voie d'extinction" << endl;
	               cout << "et les lapins ont disparu :-(" << endl; }

else if ( ind_L == 3) { cout << "Les lapins ont été en voie d'extinction" << endl;
	                    cout << "mais la population est remontée ! Ouf !" << endl;}
	                    

                  
	                    
	             }     
	                    

	cout << endl;                    

	                     

	
}
 

  /*******************************************
   * Ne rien modifier après cette ligne.
   *******************************************/

  return 0;
}
