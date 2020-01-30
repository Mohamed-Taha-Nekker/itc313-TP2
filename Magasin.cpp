#include "Magasin.h"

using namespace std;
 
Magasin::Magasin(){}

Magasin::Magasin(vector<Produit*> produits){
	m_produits = produits;
}

void Magasin::ajoutProduit(string titreproduit, double prixproduit, int quantitedisponible, string descriptionproduit){
	m_produits.push_back(new Produit(titreproduit, prixproduit, quantitedisponible, descriptionproduit));
}

void Magasin::affichageProduits(){
	cout<<"Produits disponibles : "<<endl<<endl;
	cout<<"Nom\t\t\tDescription\t\t\tQuantite\tPrix"<<endl;
	for(int i=0; (unsigned)i<m_produits.size(); i++){
		cout<<m_produits[i]->getTitreProduit();
		m_produits[i]->tabulations(m_produits[i]->getTitreProduit().length(), true);
		cout<<m_produits[i]->getDescriptionProduit();
		m_produits[i]->tabulations(m_produits[i]->getDescriptionProduit().length(), false);
		cout<<m_produits[i]->getQuantiteDisponible()
				 <<"\t\t"
				 <<m_produits[i]->getPrixProduit()<<"€"<<endl;
	}
	cout<<endl;
}

void Magasin::affichageProduitParNom(string nomproduit){
	cout<<"Details du produit : "<<endl<<endl;
	for(int i=0; (unsigned)i<m_produits.size(); i++){
		if(m_produits[i]->getTitreProduit()==nomproduit){
			cout<<m_produits[i]->getTitreProduit();
			m_produits[i]->tabulations(m_produits[i]->getTitreProduit().length(), true);
			cout<<m_produits[i]->getDescriptionProduit();
			m_produits[i]->tabulations(m_produits[i]->getDescriptionProduit().length(), false);
			cout<<m_produits[i]->getQuantiteDisponible()
				     <<"\t\t"
				     <<m_produits[i]->getPrixProduit()<<"€"<<endl;
		}
	}
	cout<<endl;
}

void Magasin::majQuantiteProduit(string nomproduit, int quantiteproduit){
	for(int i=0; (unsigned)i<m_produits.size(); i++){
		if(m_produits[i]->getTitreProduit()==nomproduit){
			m_produits[i]->setQuantiteDisponible(quantiteproduit);
			break;
		}
	}
}

void Magasin::ajoutClient(string nomclient, string prenomclient){
	int id;
	if(m_clients.size()==0)
		id=1;
	else
		id=m_clients[m_clients.size()-1]->getIdClient()+1;
	
	m_clients.push_back(new Client(id, nomclient, prenomclient));
}

void Magasin::affichageClients(){
	cout<<"Clients : "<<endl<<endl
			 <<"ID\t\tIdentité"<<endl;
	for(int i=0; (unsigned)i<m_clients.size(); i++){	
		cout<<m_clients[i]->getIdClient()
				 <<"\t\t"
				 <<m_clients[i]->getNomClient()
				 <<" "
				 <<m_clients[i]->getPrenomClient()
				 <<endl;
	}	
	cout<<endl;
}

void Magasin::affichageClientParNom(string nomclient, string prenomclient){
	cout<<"Details du client : "<<endl<<endl;
	for(int i=0; (unsigned)i<m_clients.size(); i++){	
		if(m_clients[i]->getNomClient()==nomclient && m_clients[i]->getPrenomClient()==prenomclient){
			cout<<m_clients[i]->getIdClient()
					 <<"\t\t"
					 <<m_clients[i]->getNomClient()
					 <<" "
					 <<m_clients[i]->getPrenomClient()
					 <<endl;
		}
	}	
	cout<<endl;
}

void Magasin::affichageClientParNom(int idclient){
	cout<<"Details du client : "<<endl<<endl;
	for(int i=0; (unsigned)i<m_clients.size(); i++){	
		if(m_clients[i]->getIdClient()==idclient){
			cout<<m_clients[i]->getIdClient()
					 <<"\t\t"
					 <<m_clients[i]->getNomClient()
					 <<" "
					 <<m_clients[i]->getPrenomClient()
					 <<endl;
		}
	}	
	cout<<endl;
}

void Magasin::ajoutProduitPanierClient(string nomclient, string prenomclient, string nomproduit){
	for(int i=0; (unsigned)i<m_clients.size(); i++){	
		if(m_clients[i]->getNomClient()==nomclient && m_clients[i]->getPrenomClient()==prenomclient){
			for(int j=0; (unsigned)j<m_produits.size(); j++){ 
				if(m_produits[j]->getTitreProduit()==nomproduit){
					if(m_produits[j]->getQuantiteDisponible()>0){
						m_clients[i]->addProduit(*m_produits[j]);
						m_produits[j]->setQuantiteDisponible(m_produits[j]->getQuantiteDisponible()-1);
						break;
					}
					else
						cout<<"Le produit n'est plus disponible"<<endl;
				}
			}
		}
	}
}

void Magasin::ajoutProduitPanierClient(int idclient, string nomproduit){
	for(int i=0; (unsigned)i<m_clients.size(); i++){	
		if(m_clients[i]->getIdClient()==idclient){
			for(int j=0; (unsigned)j<m_produits.size(); j++){
				if(m_produits[j]->getTitreProduit()==nomproduit){
					if(m_produits[j]->getQuantiteDisponible()>0){
						m_clients[i]->addProduit(*m_produits[j]);
						m_produits[j]->setQuantiteDisponible(m_produits[j]->getQuantiteDisponible()-1);
						break;
					}
					else
						cout<<"Le produit n'est plus disponible"<<endl;
				}
			}
		}
	}
}

void Magasin::effacerProduitPanierClient(string nomclient, string prenomclient, string nomproduit){
	for(int i=0; (unsigned)i<m_clients.size(); i++){	
		if(m_clients[i]->getNomClient()==nomclient && m_clients[i]->getPrenomClient()==prenomclient){
			for(int j=0; (unsigned)j<m_produits.size(); j++){ 
				if(m_produits[j]->getTitreProduit()==nomproduit){ 
					m_produits[j]->setQuantiteDisponible(m_produits[j]->getQuantiteDisponible()+m_clients[i]->getQuantiteObjet(nomproduit));
					m_clients[i]->supprimerProduit(nomproduit);

				}
			}
		}
	}
}

void Magasin::effacerProduitPanierClient(int idclient, string nomproduit){
	for(int i=0; (unsigned)i<m_clients.size(); i++){	
		if(m_clients[i]->getIdClient()==idclient){
			for(int j=0; (unsigned)j<m_produits.size(); j++){ 
				if(m_produits[j]->getTitreProduit()==nomproduit){ 
					m_produits[j]->setQuantiteDisponible(m_produits[j]->getQuantiteDisponible()+m_clients[i]->getQuantiteObjet(nomproduit));
					m_clients[i]->supprimerProduit(nomproduit);
				}
			}
		}
	}
}

void Magasin::setProduitPanierClient(string nomclient, string prenomclient, string nomproduit, int quantiteproduit){
	for(int i=0; (unsigned)i<m_clients.size(); i++){
		if(m_clients[i]->getNomClient()==nomclient && m_clients[i]->getPrenomClient()== prenomclient){
			for(int j=0; (unsigned)j<m_produits.size(); j++){ 
				if(m_produits[j]->getTitreProduit()==nomproduit){ 
					m_clients[i]->modifQuantiteObjet(nomproduit, quantiteproduit);
					m_produits[j]->setQuantiteDisponible(m_produits[j]->getQuantiteDisponible()-quantiteproduit);
					cout<<"La quantitée du produit "<<nomproduit<<" a été modifiée !"<<endl;
				}
			}
		}
	}
}

void Magasin::setProduitPanierClient(int idclient, string nomproduit, int quantiteproduit){
	for(int i=0; (unsigned)i<m_clients.size(); i++){	
		if(m_clients[i]->getIdClient()==idclient){
			for(int j=0; (unsigned)j<m_produits.size(); j++){ //si on trouve le client, on cherche le produit dans le magasin
				if(m_produits[j]->getTitreProduit()==nomproduit){ //si on trouve le produit, 
					m_clients[i]->modifQuantiteObjet(nomproduit, quantiteproduit);
					m_produits[j]->setQuantiteDisponible(m_produits[j]->getQuantiteDisponible()-quantiteproduit);
					cout<<"La quantitée du produit "<<nomproduit<<" a été modifiée !"<<endl;
				}
			}
		}
	}
}