#include "Client.h"

using namespace std;

Client::Client(){}

Client::Client(int idclient, string nomclient, string prenomclient, vector<Produit> listeproduits){
	m_idclient = idclient;
	m_nomclient = nomclient;
	m_prenomclient = prenomclient;
	m_listeproduits = listeproduits;
}

int Client::getIdClient(){
	return m_idclient;
}

string Client::getNomClient(){
	return m_nomclient;
}
string Client::getPrenomClient(){
	return m_prenomclient;
}
vector<Produit> Client::getListeProduits(){
	return m_listeproduits;
}

void Client::addProduit(Produit produit){
	m_listeproduits.push_back(produit);
}

void Client::viderListeProduits(){
	m_listeproduits.clear();
}

void Client::modifQuantiteObjet(string nomproduit, int quantiteproduit){
	for(int i=0; (unsigned)i<m_listeproduits.size(); i++){
		if(m_listeproduits[i].getTitreProduit()==nomproduit){
			m_listeproduits[i].setQuantiteDisponible(quantiteproduit);
			break;
		}
	}
}

void Client::supprimerProduit(string nomproduit){
	for(int i=0; (unsigned)i<m_listeproduits.size(); i++){
		if(m_listeproduits[i].getTitreProduit()==nomproduit){
			m_listeproduits.erase(m_listeproduits.begin()+i);
			break;
		}
	}
}

int Client::getQuantiteObjet(string nomproduit){
	for(int i=0; (unsigned)i<m_listeproduits.size();i++){
		if(m_listeproduits[i].getTitreProduit()==nomproduit)
			return m_listeproduits[i].getQuantiteDisponible();
	}
	return 0;
}

ostream& operator<<(ostream& flux, Client& client){

	flux<<"ID Client : "<<client.getIdClient()<<endl;
	flux<<"Identitée : "<<client.getNomClient()<<" "<<client.getPrenomClient()<<endl<<endl;

	flux<<"Produits dans le panier : "<<endl<<endl;
	flux<<"Nom\t\t\tDescription\t\t\tQuantite\tPrix"<<endl;
	for(int i=0; (unsigned)i<client.getListeProduits().size(); i++){
		flux<<client.getListeProduits()[i].getTitreProduit();
		client.getListeProduits()[i].tabulations(client.getListeProduits()[i].getTitreProduit().length(), true);
		flux<<client.getListeProduits()[i].getDescriptionProduit();
		client.getListeProduits()[i].tabulations(client.getListeProduits()[i].getDescriptionProduit().length(), false);
		flux<<client.getListeProduits()[i].getQuantiteDisponible()
				 <<"\t\t"
				 <<client.getListeProduits()[i].getPrixProduit()<<"€"<<endl;
	}
	flux<<endl;


	return flux;

}