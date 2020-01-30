#ifndef _Commande_h
#define _Commande_h

#include "Produit.h"
#include "Client.h"
#include <vector>

using namespace std;

class Commande{
public:
	Commande(Client client, vector<Produit> produitscommandes, bool status);
	Client getClient();
	vector<Produit> getProduitsCommandes();
	bool getStatus();
private:
	Client m_client;
	vector<Produit> m_produitscommandes;
	bool m_status;
};

ostream& operator<<(ostream& flux, Commande& commande);

#endif