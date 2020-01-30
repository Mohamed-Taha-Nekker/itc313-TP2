#include "Commande.h"

using namespace std;

Commande::Commande(Client client, vector<Produit> produitscommandes, bool status){
	m_client = client;
	m_produitscommandes = produitscommandes;
	m_status = status;
}

Client Commande::getClient(){
	return m_client;
}

vector<Produit> Commande::getProduitsCommandes(){
	return m_produitscommandes;
}

bool Commande::getStatus(){
	return m_status;
}

ostream& operator<<(ostream& flux, Commande& commande){
	int produits=commande.getProduitsCommandes().size();
	flux<<"Le client "<<commande.getClient().getNomClient()<<" "<<commande.getClient().getPrenomClient();
	switch(produits){
		case 0 : cout<<" n'a aucun produit dans son panier d'achat."<<endl;
		break;
		case 1 : cout<<" a un seul produit dans son panier : "<<endl <<commande.getProduitsCommandes()[0]<<endl;
		break;
		default: cout<<" a dans son panier les produits suivants : "<<endl;

		cout<<"Nom\t\t\tDescription\t\t\tQuantite\tPrix"<<endl;
		for(int i=0; i<produits; i++){
			cout<<commande.getProduitsCommandes()[i].getTitreProduit();
			commande.getProduitsCommandes()[i].tabulations(commande.getProduitsCommandes()[i].getTitreProduit().length(), true);
			cout<<commande.getProduitsCommandes()[i].getDescriptionProduit();
			commande.getProduitsCommandes()[i].tabulations(commande.getProduitsCommandes()[i].getDescriptionProduit().length(), false);
			cout<<commande.getProduitsCommandes()[i].getQuantiteDisponible()
					 <<"\t\t"
					 <<commande.getProduitsCommandes()[i].getPrixProduit()<<"€"<<endl;
		}
		cout<<endl;
	}
		  	  
	return flux;
}