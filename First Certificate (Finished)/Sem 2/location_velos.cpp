#include <iostream>
using namespace std;

int main()
{
  cout << "Donnez l'heure de dÃ©but de la location (un entier) : ";
  int debut;
  cin >> debut;

  cout << "Donnez l'heure de fin de la location (un entier) : ";
  int fin;
  cin >> fin;

  /*****************************************************
   * ComplÃ©ter le code Ã  partir d'ici
   *****************************************************/
   int heure1,heure2,v1;
   int tarif1(0);
   int tarif2(0);
   bool flag1(false),flag2(false);
   
    if ( debut < 0 or fin > 24) {
    cout << "Les heures doivent Ãªtre comprises entre 0 et 24 !" << endl;
} else if ( debut == fin){
    cout << "Bizarre, vous n'avez pas louÃ© votre vÃ©lo bien longtemps !" << endl;
} else if (debut > fin) {
    cout << "Bizarre, le dÃ©but de la location est aprÃ¨s la fin ..." << endl;
}
 else 
 
   if ( (debut <= 7 and fin <= 7 ) or ( debut >=17 and fin >=17 ) ){
	   
	   heure1=tarif1 = (fin-debut)*1;
	   flag1=true;
   }
   
   else if (debut >=7 and fin <= 17)
   {    
	    heure2 = (fin - debut);
	    tarif2 = heure2 * 2;
	    flag2=true;
   }
   
   else {
	   
      flag1=flag2=true;
      
      
      if (debut <= 7) {
		  heure1 = 7 - debut;
		  tarif1= heure1;
		   if (fin <= 17 ){
			   
			   heure2 = fin - 7;
			   tarif2 = heure2 * 2 ;
			   }
		   else {
			   	heure2 = 17 - 7 ;
			   	tarif2 = heure2*2;
			   	v1= fin - 17 ; 
			   	tarif1 = tarif1 + v1 ;
			    heure1= tarif1 ;

				   
				   }
	  
	  } else {
		  
		  if (fin <= 17 ){
			   
			   heure2 = fin - debut;
			   tarif2 = heure2 * 2 ;
			   }
		   else {
			   	heure2 = 17 - debut ;
			   	tarif2 = heure2*2;
			   	v1= fin - 17 ; 
			   	tarif1 = tarif1 + v1 ;
			   	heure1= tarif1 ;
				   
				   }
		  
		  
		  }
   
   
   }
	   
	   
	   
    cout << "Vous avez louÃ© votre vÃ©lo pendant" << endl;
if (flag1 and not flag2 ){

      cout << heure1 << " heure(s) au tarif horaire de " 
           << " 1 franc(s)" << endl;

    cout << "Le montant total Ã  payer est de " << tarif1
         << " franc(s)." << endl;
	 }
	 
	else if ( flag1 and flag2)  {
		
		cout << heure1 << " heure(s) au tarif horaire de " 
           << " 1 franc(s)" << endl;
		cout << heure2 << " heure(s) au tarif horaire de " 
           << " 2 franc(s)" << endl;

        cout << "Le montant total Ã  payer est de " << tarif2+tarif1
         << " franc(s)." << endl;
		
		
		} 
		
	else if ( not flag1 and flag2) {
		
		
		cout << heure2 << " heure(s) au tarif horaire de " 
           << " 2 franc(s)" << endl;

        cout << "Le montant total Ã  payer est de " << tarif2
         << " franc(s)." << endl;
		
		
		}	
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 

  /*******************************************
   * Ne rien modifier aprÃ¨s cette ligne.
   *******************************************/

  return 0;
}
