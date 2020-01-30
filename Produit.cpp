#include "Produit.h"

using namespace std;

Produit::Produit(){}
Produit::Produit(string titreproduit, double prixproduit, int quantitedisponible, string descriptionproduit){
	m_titreproduit = titreproduit;
	m_quantitedisponible = quantitedisponible;
	m_prixproduit = prixproduit;
	m_descriptionproduit = descriptionproduit;
}

string Produit::getTitreProduit() const{
	return m_titreproduit;
}
string Produit::getDescriptionProduit() const{
	return m_descriptionproduit;
}
int Produit::getQuantiteDisponible() const{
	return m_quantitedisponible;
}
double Produit::getPrixProduit() const{
	return m_prixproduit;
}

void Produit::setQuantiteDisponible(int quantitedisponible){
	m_quantitedisponible = quantitedisponible;
}

void Produit::tabulations(int longeurmot, bool name){
	int tabs = longeurmot/8;
	int i=0;
	if(name)
		tabs=3-tabs; 
	else
		tabs=4-tabs; 

	while(i<tabs){
			cout<<"\t";
			i++;
		}
}

ostream& operator<<(ostream& flux, Produit& produit){
	flux<<"Titre Produit : "<<produit.getTitreProduit()<<endl
	  	  <<"Description Produit : "<<produit.getDescriptionProduit()<<endl
		  <<"Quantite Disponible : "<<produit.getQuantiteDisponible()<<endl
		  <<"Prix Produit : "<<produit.getPrixProduit()<<endl;
	return flux;
}