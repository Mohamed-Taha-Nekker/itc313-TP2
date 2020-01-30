#include <iostream>
#include "Client.h"
#include <string>
#include "Produit.h"

using namespace std;

int main(){

	Client Client1(1, "Nekker", "Taha");
	Produit Produit1("Fraise", 3.5);
	Produit Produit2("Bananes", 1.11);
	Produit Produit3("Kiwi", 4.20);
	Client1.addProduit(Produit1);
	cout<<Client1;
	Client1.viderListeProduits();
	Client1.addProduit(Produit2);
	Client1.addProduit(Produit3);
	Client1.modifQuantiteObjet("Bananes", 3);
	cout<<Client1;
	return 0;
}