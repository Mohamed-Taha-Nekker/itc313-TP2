#ifndef _Produit_h
#define _Produit_h

#include <string>
#include <iostream>

using namespace std;

class Produit{
public:
	Produit();
	Produit(string titreproduit, double prixproduit, int quantitedisponible=1, string descriptionproduit="Console de jeu SONY");
	string getTitreProduit() const;
	string getDescriptionProduit() const;
	int getQuantiteDisponible() const;
	double getPrixProduit() const;
	void setQuantiteDisponible(int quantitedisponible);
	void tabulations(int longeurmot, bool name);
private:
	string m_titreproduit;
	string m_descriptionproduit;
	int m_quantitedisponible;
	double m_prixproduit;
};

ostream& operator<<(ostream& flux, Produit& produit);

#endif