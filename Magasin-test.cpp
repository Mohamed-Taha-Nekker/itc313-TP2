#include "Magasin.h"

using namespace std;
 
int main(){

	Magasin Leclerc;
	Leclerc.ajoutProduit("Oasis", 1.80, 30, "Boisson gazeuse");
	Leclerc.ajoutProduit("Packet Christaline", 1.03, 17, "Eau");
	Leclerc.ajoutProduit("Lays", 1.7, 50, "Chips");
	Leclerc.affichageProduits();
	Leclerc.ajoutClient("Nekker", "Taha");
	Leclerc.ajoutClient("Majri", "Amine");
	Leclerc.affichageClients();
	Leclerc.affichageClientParNom("Nekker", "Taha");
	Leclerc.affichageClientParNom(2);
	Leclerc.ajoutProduitPanierClient("Nekker", "Taha","Lays");
	Leclerc.affichageProduits();
	Leclerc.effacerProduitPanierClient("Nekker", "Taha","Lays");
	Leclerc.ajoutProduitPanierClient("Nekker", "Taha","Lays");
	Leclerc.setProduitPanierClient("Nekker", "Taha","Oasis", 10);
	return 0;
}