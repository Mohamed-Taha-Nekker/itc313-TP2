#ifndef _Client_h
#define _Client_h

#include "Produit.h"
#include <vector>
#include <iostream>
#include <string>

using namespace std;

class Client{
public:
	Client();
	Client(int idclient, string nomclient, string prenomclient, vector<Produit> listeproduits={});
	int getIdClient();
	string getNomClient();
	string getPrenomClient();
	vector<Produit> getListeProduits();
	void addProduit(Produit produit);
	void viderListeProduits();
	void modifQuantiteObjet(string tnomproduit, int tquantiteproduit);
	void supprimerProduit(string nomproduit);
	int getQuantiteObjet(string nomproduit);
private:
	int m_idclient;
	string m_nomclient;
	string m_prenomclient;
	vector<Produit> m_listeproduits;
};

ostream& operator<<(ostream& flux, Client& client);
#endif