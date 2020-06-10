#include <iostream>
using namespace std;

int main()
{
  int debut(0);
  do {
    cout << "de (>= 1) ? ";
    cin >> debut;
  } while (debut < 1);

  int fin(0);
  do {
    cout << "a (>= " << debut << ") ? ";
    cin >> fin;
  } while (fin < debut);

  /*******************************************
   * Completez le programme a partir d'ici.
   *******************************************/

for ( int i = debut ; i<=fin ; i++ ) 
{

 int k = i;
 int res=0;
 while (k != 0){
   
   res++;
  if ( k%3 == 0 )
  {
   k = k+4;
  
  }
  else if (k%4==0){
  
  k = k/2;
  }
 
  else 
  {
	  k-- ; 
  }
 
 }
 
 
cout << i <<" -> " << res << endl;


}
  /*******************************************
   * Ne rien modifier apres cette ligne.
   *******************************************/

  return 0;
}
