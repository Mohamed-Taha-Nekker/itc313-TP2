#ifndef _Magasin_h
#define _Magasin_h

#include "Produit.h"
#include "Client.h"
#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Magasin{
public:
	Magasin();
	Magasin(vector<Produit*> produits);
	void ajoutProduit(string titreproduit, double prixproduit, int quantitedisponible, string descriptionproduit);
	void affichageProduits();
	void affichageProduitParNom(string nomproduit);
	void majQuantiteProduit(string nomproduit, int quantiteproduit);
	void ajoutClient(string nomclient, string prenomclient);
	void affichageClients();
	void affichageClientParNom(string nomclient, string prenomclient);
	void affichageClientParNom(int idclient);
	void ajoutProduitPanierClient(string nomclient, string prenomclient, string nomproduit);
	void ajoutProduitPanierClient(int idclient, string nomproduit);
	void effacerProduitPanierClient(string nomclient, string prenomclient, string nomproduit);
	void effacerProduitPanierClient(int idclient, string nomproduit);
	void setProduitPanierClient(string nomclient, string prenomclient, string nomproduit, int quantiteproduit);
	void setProduitPanierClient(int idclient, string nomproduit, int quantiteproduit);
private:
	vector<Produit*> m_produits;
	vector<Client*> m_clients;
};

#endif