#include "Commande.h"

using namespace std;

int main(){
	
	vector<Produit> produits_commandes;
	produits_commandes.push_back(Produit("PS4", 500));
	produits_commandes.push_back(Produit("Television", 750));
	Client Client1(1,"Nekker","Taha");
	Commande cmd(Client1,produits_commandes,true);
	cout<<cmd;
	return 0;
}