/*
 * EX3.cpp
 *
 *  Created on: 29 oct. 2026
 *      Author: hP
 */

#include <iostream>
using namespace std;

class CompteBancaire {
private:
    double solde;
    int codeSecurite;
    static const int LIMITE_SANS_CODE = 1000;

public:
    // Constructeur sans solde initial
    CompteBancaire() : solde(0), codeSecurite(1234) {
        cout << "Compte ouvert avec un solde de 0 DH." << endl;
    }

    // Constructeur avec solde initial
    CompteBancaire(double soldeInitial) : codeSecurite(1234) {
        if (soldeInitial < 0) {
            cout << "Solde initial invalide, mis a 0." << endl;
            solde = 0;
        } else {
            solde = soldeInitial;
            cout << "Compte ouvert avec un solde de " << solde << " DH." << endl;
        }
    }

    void afficherSolde() const {
        cout << "Solde actuel : " << solde << " DH" << endl;
    }

    // Retrait simple : limite a 1000 DH
    void retrait(double montant) {
        if (montant <= 0) {
            cout << "Montant invalide." << endl;
        } else if (montant > LIMITE_SANS_CODE) {
            cout << "Retrait superieur a " << LIMITE_SANS_CODE
                 << " DH : code de securite requis." << endl;
        } else if (montant > solde) {
            cout << "Solde insuffisant." << endl;
        } else {
            solde -= montant;
            cout << "Retrait de " << montant << " DH effectue." << endl;
        }
    }

    // Retrait avec code de securite : pas de limite (dans la limite du solde)
    void retrait(double montant, int code) {
        if (code != codeSecurite) {
            cout << "Code de securite incorrect. Retrait refuse." << endl;
        } else if (montant <= 0) {
            cout << "Montant invalide." << endl;
        } else if (montant > solde) {
            cout << "Solde insuffisant." << endl;
        } else {
            solde -= montant;
            cout << "Retrait securise de " << montant << " DH effectue." << endl;
        }
    }
};

int main() {
    CompteBancaire c1;
    CompteBancaire c2(5000);

    c2.afficherSolde();
    c2.retrait(300);          // OK
    c2.retrait(2000);         // refuse : code requis
    c2.retrait(2000, 9999);   // refuse : mauvais code
    c2.retrait(2000, 1234);   // OK
    c2.afficherSolde();

    c1.retrait(50);           // solde insuffisant
    return 0;
}



