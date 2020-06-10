#include <iostream>
#include <cmath>
using namespace std;

enum Pavillon { JollyRogers, CompagnieDuSenegal, CompagnieDOstende };

enum Etat { Intact, Endommage, Coule };

int sq(int x)
{
  return x*x;
}

class Coordonnees
{
public:
  Coordonnees(int un_x, int un_y) : x_(un_x), y_(un_y) {}
  int x() const {
    return x_;
  }
  int y() const {
    return y_;
  }
  void operator+=(Coordonnees const& autre); // à définir plus bas
private:
  int x_;
  int y_;
};

class Navire
{
  /*****************************************************
   * Compléter le code à partir d'ici
   *****************************************************/
protected :
	Coordonnees position_ ;
	Pavillon pavillon_;
	Etat etat_;
	const int rayon_rencontre = 10 ;
public : 

	Navire(int un_x , int un_y , Pavillon pav , Etat etat = Intact):position_(un_x,un_y),pavillon_(pav),etat_(etat){}
	
	Coordonnees position() const { return position_; }
	
	void avancer(int de_x, int de_y){
		
		if(etat_ != Coule){ 
			
			position_.operator +=(Coordonnees(de_x,de_y));
			
			 }
		
		}
		
		
	void renflouer(){ etat_ = Intact; }
	
	virtual ostream& afficher(ostream& sortie) {
		sortie<<"blablabla";
		return sortie;
		};
	
	virtual void attaque(Navire& nav) = 0;
	
	virtual void replique(Navire& nav) = 0;
	
	virtual void est_touche() = 0;
	
	double distance(Coordonnees const& cord){
		
		return sqrt( sq(position().x()-cord.x())+ sq(position().y()-cord.y()) );
		
		}
	
	void rencontrer(Navire& nav){
		
		double dis = distance( nav.position());
		if(
		(etat_ != Coule)and
		(nav.etat_ != Coule)and
		(pavillon_ != nav.pavillon_)and
		(dis < rayon_rencontre)
		){
			
			attaque(nav);
			nav.replique(*this);
			
			}
		
		}
};

void Coordonnees::operator+=(Coordonnees const& autre)
{
  // à définir ici
  
  x_ = x_ + autre.x_;
  y_ = y_ + autre.y_;

}

double distance ( Coordonnees const& cord1 , Coordonnees const& cord2){
	
	return sqrt( sq(cord1.x()-cord2.x())+ sq(cord1.y()-cord2.y()) );
	
	}
	
ostream& operator<<(ostream& sortie , Coordonnees const& cord ){ //du class Coordonnees
	
	sortie << "("<<cord.x()<<", "<<cord.y()<<")";
	return sortie;
	
	}
	
ostream& operator<<(ostream& sortie , Pavillon p){ // operator<< du Pavillon
	
	if(p == JollyRogers){ sortie<<"pirate"; return sortie; }
	else if ( p == CompagnieDuSenegal){ sortie << "français"; return sortie;}
	else if ( p == CompagnieDOstende){ sortie << "autrichien"; return sortie; }
	else { sortie << "pavillon inconnu"; return sortie;}
	
	}

ostream& operator<<(ostream& sortie , Etat p){ // operator<< du Etat
	
	if(p == Intact){ sortie<<"intact"; return sortie; }
	else if ( p == Endommage){ sortie << "ayant subi des dommages" ; return sortie;}
	else if ( p == Coule){ sortie << "coulé"; return sortie; }
	else { sortie << "état inconnu"; return sortie;}
	
	}
	

	
	

	
	
class Pirate : public virtual Navire{
	
public:
	Pirate(int un_x , int un_y , Pavillon pav , Etat etat = Intact):Navire(un_x , un_y , pav , etat){}
	
	ostream& afficher(ostream& sortie) override {
		
		sortie << "bateau pirate en "<<this->position_<<" battant pavillon "<<this->pavillon_<<", "<<this->etat_;
		return sortie;
		}
		
		
	void attaque(Navire& nav) override{
		
		cout << "A l'abordage !"<<endl;
		nav.est_touche();
		
		}
	
	void replique(Navire& nav) override{
		
		if(etat_ != Coule){ 
			
			cout << "Non mais, ils nous attaquent ! On riposte !!"<<endl;
			attaque(nav);
			
			 }
		
		}
		
		
	void est_touche() override {
		
		if(etat_ == Intact) { etat_ = Endommage; }
		else if ( etat_ == Endommage ) {etat_ = Coule; }
		
		}
	};
	
	
class Marchand : public virtual Navire{
	
	public :
	
	Marchand(int un_x , int un_y , Pavillon pav , Etat etat = Intact):Navire(un_x , un_y , pav , etat){}

	ostream& afficher(ostream& sortie) override {
		
		sortie << "navire marchand en "<<this->position_<<" battant pavillon "<<this->pavillon_<<", "<<this->etat_;
		return sortie;
		}
		
		
	void attaque(Navire& nav) override{
		
		cout<<" On vous aura ! (insultes) "<<endl;
		
		}
	
	void replique(Navire& nav) override {
		
		if(etat_ == Coule){ cout << "SOS je coule ! "<<endl;}
		else { cout<< "Même pas peur !"<<endl; }
		
		}
	void est_touche() override {etat_ = Coule;}
	
	
	
	
	};
	
	
class Felon : public Pirate , public Marchand{
	
	public : 
	
Felon(int un_x , int un_y , Pavillon pav , Etat etat = Intact): Navire(un_x, un_y, pav, etat),Pirate(un_x, un_y, pav, etat),Marchand(un_x, un_y, pav, etat){}
 using Pirate::attaque;
 using Marchand::replique;
 using Pirate::est_touche;
	
	void attaque(Navire& nav) override { Pirate::attaque(nav); }
	void replique(Navire& nav) override{ Marchand::replique(nav); }
	void est_touche() override { Pirate::est_touche();}
	
	
	ostream& afficher(ostream& sortie) override {
		
		sortie << "navire félon en "<<this->position_<<" battant pavillon "<<this->pavillon_<<", "<<this->etat_;
		return sortie;
		}
	};
	
	
double distance ( Navire& nav1 , Navire& nav2) {
	
	
	return distance(nav1.position(),nav2.position());
	
	}
	
ostream& operator<<(ostream& sortie , Navire& nav) {
	//Navire* nav1 = new Navire(nav);
	nav.afficher(sortie);
	return sortie;
	
	}
/*******************************************
 * Ne rien modifier après cette ligne.
 *******************************************/

void rencontre(Navire& ship1, Navire& ship2)
{
  cout << "Avant la rencontre :" << endl;
  cout << ship1 << endl;
  cout << ship2 << endl;
  cout << "Distance : " << distance(ship1, ship2) << endl;
  ship1.rencontrer(ship2);
  cout << "Apres la rencontre :" << endl;
  cout << ship1 << endl;
  cout << ship2 << endl;
}

int main()
{
  // Test de la partie 1
  cout << "===== Test de la partie 1 =====" << endl << endl;

  // Un bateau pirate 0,0
  Pirate ship1(0, 0, JollyRogers);
  cout << ship1 << endl;

  // Un bateau marchand en 25,0
  Marchand ship2(25, 0, CompagnieDuSenegal);
  cout << ship2 << endl;

  cout << "Distance : " << distance(ship1, ship2) << endl;

  cout << "Quelques déplacements..." << endl;
  cout << "  en haut à droite :" << endl;
  // Se déplace de 75 unités à droite et 10 en haut
  ship1.avancer(75, 10);
  cout << ship1 << endl;

  cout << "  vers le bas :" << endl;
  ship1.avancer(0, -5);
  cout << ship1 << endl;

  cout << endl << "===== Test de la partie 2 =====" << endl << endl;

  cout << "Bateau pirate et marchand ennemis (trop loins) :" << endl;
  rencontre(ship1, ship2);

  cout << endl << "Bateau pirate et marchand ennemis (proches) :" << endl;
  ship1.avancer(-40, -2);
  ship2.avancer(10, 2);
  rencontre(ship1, ship2);

  cout << endl << "Deux bateaux pirates ennemis intacts (proches) :" << endl;
  Pirate ship3(33, 8, CompagnieDOstende);
  rencontre(ship1, ship3);

  cout << endl << "Bateaux pirates avec dommages, ennemis :" << endl;
  rencontre(ship1, ship3);

  cout << endl << "Bateaux marchands ennemis :" << endl;
  Marchand ship4(21, 7, CompagnieDuSenegal);
  Marchand ship5(27, 2, CompagnieDOstende);
  rencontre(ship4, ship5);

  cout << endl << "Pirate vs Felon :" << endl;
  ship3.renflouer();
  Felon ship6(32, 10, CompagnieDuSenegal);
  rencontre(ship3, ship6);

  cout << endl << "Felon vs Pirate :" << endl;
  rencontre(ship6, ship3);

  return 0;
}
