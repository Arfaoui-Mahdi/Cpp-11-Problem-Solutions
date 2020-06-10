#include <iostream>
#include <ctime>

// pour les nombres aléatoires
#include <random>
#include <cstring> // strlen

using namespace std;

// ======================================================================
// Couleur au hasard
std::uniform_int_distribution<int> distribution;
std::default_random_engine generateur(time(NULL)); /* NOT using std::random_device since not
                                                    * all compilers seems to support it :-( */

char tirer_couleur()
{
  static const char* const couleurs = ".RGBCYM";
  static const int nb = strlen(couleurs) - 1;

  return couleurs[distribution(generateur,
                               std::uniform_int_distribution<int>::param_type {0, nb})];
}

// ======================================================================
char poser_question()
{
  char lu(' ');
  cout << "Entrez une couleur : ";
  cin >> lu;
  return lu;
}

// ---- prototype -------------------------------------------------------
bool couleur_valide(char c);

// ======================================================================
char lire_couleur()
{
  char lu(poser_question());
  while (not couleur_valide(lu)) {
    cout << "'" << lu << "' n'est pas une couleur valide." << endl;
    cout << "Les couleurs possibles sont : ., R, G, B, C, Y ou M." << endl;
    lu = poser_question();
  }
  return lu;
}

// ======================================================================
void afficher_couleurs(char c1, char c2, char c3, char c4)
{
  cout << ' ' << c1 << ' ' << c2 << ' ' << c3 << ' ' << c4;
}

// ======================================================================
void afficher(int nb, char c)
{
  while (nb-- > 0) {
    cout << c;
  }
}

// ---- prototype -------------------------------------------------------
void afficher_reponses(char c1, char c2, char c3, char c4,
                       char r1, char r2, char r3, char r4);

// ======================================================================
void afficher_coup(char c1, char c2, char c3, char c4,
                   char r1, char r2, char r3, char r4)
{
  afficher_couleurs(c1, c2, c3, c4);
  cout << " : ";
  afficher_reponses(c1, c2, c3, c4,
                    r1, r2, r3, r4);
  cout << endl;
}

// ======================================================================
void message_gagne(int nb_coups)
{
  cout << "Bravo ! Vous avez trouvé en " << nb_coups << " coups." << endl;
}

// ======================================================================
void message_perdu(char c1, char c2, char c3, char c4)
{
  cout << "Perdu :-(" << endl;
  cout << "La bonne combinaison était : ";
  afficher_couleurs(c1, c2, c3, c4);
  cout << endl;
}

/*****************************************************
 * Compléter le code à partir d'ici
 *****************************************************/

// ======================================================================
bool couleur_valide(char c)
{
	if(c == 'R' or c == '.' or c ==  'G' or c == 'B' or c == 'C' or c == 'Y' or c == 'M'){
	    
	   return true;
	   
	}
	return false;
}

// ======================================================================
bool verifier( char c1 , char& c2 , int& score)
{
	if (c1 == c2) {
		 c2 = 'x';
		 score++;
		 return true;}
		 else 
		 return false;           
}

// ======================================================================
void apparier( char c , char& r1 , char& r2 , char& r3 , int& score )
{
	if (  not verifier(c,r1,score)){
		if( not verifier(c,r2,score)){
			if(not verifier(c,r3,score)){}
			
			}
		
		}
}

// ======================================================================
void afficher_reponses(char c1, char c2, char c3, char c4,
                       char r1, char r2, char r3, char r4)
{
	int score = 0;
	int T[4]={0,0,0,0};
	char C[4];
	/*char R[4];
	R[0] = r1; C[1] = r2 ; R[2] = r3 ; R[3] = r4;*/
	C[0] = c1; C[1] = c2 ; C[2] = c3 ; C[3] = c4;
		
		if(c1 == r1) {T[0]=1;}
		if(c2 == r2) {T[1]=1;}
		if(c3 == r3) {T[2]=1;}
		if(c3 == r3) {T[3]=1;}
		
	
	for (int i = 0 ; i<4 ; i++){
		
		if(T[i] == 1) {
			afficher(1,'#');
			}
		else {
			
			apparier(C[i],r2 , r3 , r4 , score);
			if(score != 0){ afficher(score, '+' );}
			
			    else{ 
		            afficher(1,'-');
	                }    
			}	
		
		
		
		}

			
	
	
}

// ======================================================================
bool gagne(char c1, char c2, char c3, char c4,
           char r1, char r2, char r3, char r4)
{
	if(c1==r1 and c2==r2 and c3==r3 and c4 == r4){
		return true;
		}
		else{
	return false;	
	}
}

// ======================================================================
void jouer(int max = 8)
{
	char r1 , r2 , r3 ,r4 , c1 , c2 , c3 , c4;

r1 = tirer_couleur(); //references
r2 = tirer_couleur(); //references	
r3 = tirer_couleur();//references	
r4 = tirer_couleur(); //references	


bool flag = false;
int fin = 0;

while ( ( flag ) or  (fin < max) ){
	fin = fin + 1 ;
	c1 = lire_couleur();
	c2 = lire_couleur();
	c3 = lire_couleur();
	c4 = lire_couleur();
	
	
	afficher_coup(c1 , c2, c3, c4 , r1, r2 , r3, r4);
	flag = gagne(c1 , c2, c3, c4 , r1, r2 , r3, r4);
	
	
	}
	
	if(flag == true){
		
		message_gagne(fin);
		
		}
		else{
			
			message_perdu(r1,r2,r3,r4);
			}

 

	
	
}

/*******************************************
 * Ne rien modifier après cette ligne.
 *******************************************/

int main()
{
  jouer();
  return 0;
}
