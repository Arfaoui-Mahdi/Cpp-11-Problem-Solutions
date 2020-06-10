#include <iostream>
#include <vector>
#include <string.h>
using namespace std;



int somme_consecutifs_max(vector<int> tab) {
	
	
	int max(0);
	int res(0);
	
	
	for(size_t i(0); i<tab.size();i++){
		
		if(tab[i] != 0){
			res = res+tab[i];	
			
			if(res>= max){
				
				max= res;
				}
			
			}
			else {
				
				res =0;
				}
		
		
		
		
		}
	//cout << "somme_consecutifs_max "<<max << endl;
	return max;
	
	}


vector<size_t> lignes_max (vector<vector<int>> tab){
	
	vector<int> tab_max;
	int num;
	
	for(int i(0) ; i < tab.size(); i++){
	
		num = somme_consecutifs_max(tab[i]);
		tab_max.push_back(num);
	    //cout << "affiche tab_max " << i << " = " << tab_max[i] << endl ;
		}
		
	int max(0);	
	vector<size_t> res;
	
	for(size_t i(0) ; i < tab_max.size(); i++){
    
    if(tab_max[i]>max){
		
		max = tab_max[i];
		res.clear();
		res.push_back(i);
		
		}
		else if (tab_max[i] == max){
			res.push_back(i);
			}
			else {continue;}
    
    
    }	
	//cout << "lignes_max sizzzzzze  "<<res.size()<< endl;
	return res;
	
	}
	

vector<vector<int>> tranches_max(vector<vector<int>> tab) {
	
	vector<size_t> tMax;
	int index;
	vector<vector<int>> res;
	
	tMax = lignes_max(tab);
	
	//cout << "tranche max 1"<< endl;
	for (size_t i(0) ; i < tMax.size(); i++){
		//cout << "tranche max for "<< i << endl;
			index = tMax[i];	
       
			res.push_back(tab[index]);
			
			
		
		}
	//cout << "tranche max sizee "<< res.size() << endl;
	return res;
	
	}


int main(){
	
	vector<vector<int>> tab(
	{
		{2 ,1, 0 ,2 ,0, 3, 2},
        {0, 1 ,0 ,7 ,0},
        {1, 0 ,1 ,3 ,2, 0 ,3, 0 ,4},
        {5 ,0, 5},
        {1 ,1, 1 ,1 ,1 ,1, 1}
		
		}
		);
		
		vector<vector<int>> res;
		
		
		res = tranches_max(tab);
		
		//cout << "siiiiiiiiiiiize " << res.size();
		for ( size_t i(0) ; i < res.size(); i++){
			//cout << "main for " << endl;
			for(size_t j(0) ; j < res[i].size(); j++){
				
				
				cout << res[i][j];
				
				}
				cout<<endl;
			
			}
	
	
	return 0;
	}
