#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

/*****************************************************
  * Compléter le code à partir d'ici
 *****************************************************/

class Produit{
	
	protected :
string nom;
string unite;
	public:

Produit(string n , string u =""):nom(n),unite(u){}
string getNom() const {return nom;}
string getUnite()const {return unite;}

virtual string toString()const{return nom;}

virtual const Produit* adapter(double n) const {return this; }	
virtual double quantiteTotale(const string& nomProduit){
	
	if(nom == nomProduit) return 1;
	else return 0;
	
	}
	
//void operator=(const Produit* prod) const {
	
	//nom = prod->nom;
	//unite = prod->unite;
	
	//}
	};

class Ingredient {
	
    const Produit &produit;
	double quantite;
	
public :
	
	Ingredient(Produit const& pro , double nb):produit(pro),quantite(nb){}
	double getQuantite() const {return quantite;}
	
	Produit const& getProduit() const {return produit;}
	//string toString(){return produit.toString(); }
	
	string descriptionAdaptee() {
		
		const Produit* ptr = &produit;
		ptr = ptr->adapter(quantite);
		//ptr->adapter(quantite);
		return to_string(quantite)+" "+ptr->getUnite()+" de "+ptr->toString();
			
		}
		
	double quantiteTotale(const string& nomProduit) {
	    Produit* ptr = new Produit(this->produit);
		//Produit*  ptr = &produit;
		double qnt = ptr->quantiteTotale(nomProduit);
		return quantite * qnt;
		
		}
		
	//void operator=(Ingredient const& ingred) const {
		//const Produit* ptr = &(ingred.getProduit());
		//produit.operator=(ptr);
		//quantite = ingred.getQuantite();
		//}
		
	//void setIng(Ingredient ing) { 
		//produit = ing.getProduit(); 
		//quantite = ing.getQuantite();
		 //}
	};
	
class Recette {
	
	private : 
string nom;
double nbFois_;
vector<Ingredient> ing;

	public : 
	
Recette (string n , double nb = 1  ) : nom(n) , nbFois_(nb){}
 
 void ajouter(const Produit& p, double quantite) {
	 //const Produit& pp = p;
	 ing.push_back(Ingredient(p , (quantite*nbFois_ )));
	 
	 }
	 
 //void setIng(vector<Ingredient> in){ 
	 //for(size_t i = 0 ; i< in.size();i++){
		 
		 //ing[i] = in[i];
		 
		 //} 
	 //}
	 
 Recette adapter(double n) {
	 //vector <Ingredient> nou;
	 double nbn = nbFois_*n;
	 Recette nouv =  Recette(nom,nbn);
	 for(auto in : ing){
		 
		 nouv.ing.push_back(Ingredient(in.getProduit() , (in.getQuantite()*n)));
		 
		 }
	 
	 
	 //nouv.setIng(nou);
	 //nouv->setIng(nou);
	 return nouv;
	 
	 }
	 
	 
 string toString(){
	 string var;
	 string fois(to_string(nbFois_));
     fois.erase(fois.find_last_not_of('0') + 1, std::string::npos);
     if (fois.back() == '.') fois.pop_back();
     
	var = "Recette \""+ nom +"\" x "+fois+": \n";
	 for(size_t i = 0 ; i < ing.size();i++){
		 if(i == ing.size()-1){
			 string g = to_string(i+1);
			 var= var +g + ". " + ing[i].descriptionAdaptee(); } 
		 else{
		 string g = to_string(i+1);
		 var = var +g + ". "+ing[i].descriptionAdaptee()+"\n";
	         }
		 }
	 return var;
	 }

	
	
	double quantiteTotale(const string& nomProduit) const {
		vector<Ingredient> v (ing);
		double som = 0 ;
		
		for(size_t i = 0 ; i < ing.size() ; i ++){
			
			som = som + v[i].quantiteTotale(nomProduit);
			
			}
					

		return som;
		}
	
	
	};
	
class ProduitCuisine : public Produit{
	
	Recette rec ;
	
public : 
	ProduitCuisine(string name):Produit(name,"portion(s)"), rec(name){}
	
	void ajouterARecette(const Produit& produit, double quantite){
		
		rec.ajouter(produit,quantite);
		
		}
	
	
	
	
	
	const ProduitCuisine* adapter(double n) const override {
		
		ProduitCuisine* ptr (new ProduitCuisine(*this));
		//Recette rece(rec.adapter(n));
		ptr->rec = ptr->rec.adapter(n);
		
		return ptr;
		}	
		
		
	string toString() const override{
		
		
			Recette* ptr = new Recette(this->rec);
			return (Produit::toString()+ "\n" + ptr->toString());
			
			}
			
			
	double quantiteTotale(const string& nomProduit) override {
			
			if(nomProduit == nom ) return 1;
			else {
				
				return rec.quantiteTotale( nomProduit);
				
				}
			
			}
	
		
	};

// polymorphysme mta3 adapter w toString w func lokhra mta3 ingredient


/*******************************************
 * Ne rien modifier après cette ligne.
 *******************************************/
void afficherQuantiteTotale(const Recette& recette, const Produit& produit)
{
  string nom = produit.getNom();
  cout << "Cette recette contient " << recette.quantiteTotale(nom)
       << " " << produit.getUnite() << " de " << nom << endl;
}

int main()
{
  // quelques produits de base
  Produit oeufs("oeufs");
  Produit farine("farine", "grammes");
  Produit beurre("beurre", "grammes");
  Produit sucreGlace("sucre glace", "grammes");
  Produit chocolatNoir("chocolat noir", "grammes");
  Produit amandesMoulues("amandes moulues", "grammes");
  Produit extraitAmandes("extrait d'amandes", "gouttes");

  ProduitCuisine glacage("glaçage au chocolat");
  // recette pour une portion de glaçage:
  glacage.ajouterARecette(chocolatNoir, 200);
  glacage.ajouterARecette(beurre, 25);
  glacage.ajouterARecette(sucreGlace, 100);
  cout << glacage.toString() << endl;

  ProduitCuisine glacageParfume("glaçage au chocolat parfumé");
  // besoin de 1 portions de glaçage au chocolat et de 2 gouttes
  // d'extrait d'amandes pour 1 portion de glaçage parfumé

  glacageParfume.ajouterARecette(extraitAmandes, 2);
  glacageParfume.ajouterARecette(glacage, 1);
  cout << glacageParfume.toString() << endl;

  Recette recette("tourte glacée au chocolat");
  recette.ajouter(oeufs, 5);
  recette.ajouter(farine, 150);
  recette.ajouter(beurre, 100);
  recette.ajouter(amandesMoulues, 50);
  recette.ajouter(glacageParfume, 2);

  cout << "===  Recette finale  =====" << endl;
  cout << recette.toString() << endl;
  afficherQuantiteTotale(recette, beurre);
  cout << endl;

  // double recette
  Recette doubleRecette = recette.adapter(2);
  cout << "===  Recette finale x 2 ===" << endl;
  cout << doubleRecette.toString() << endl;

  afficherQuantiteTotale(doubleRecette, beurre);
  afficherQuantiteTotale(doubleRecette, oeufs);
  afficherQuantiteTotale(doubleRecette, extraitAmandes);
  afficherQuantiteTotale(doubleRecette, glacage);
  cout << endl;

  cout << "===========================\n" << endl;
  cout << "Vérification que le glaçage n'a pas été modifié :\n";
  cout << glacage.toString() << endl;

  return 0;
}
