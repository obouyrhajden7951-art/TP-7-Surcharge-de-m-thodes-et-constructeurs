/*
 * Ex2.cpp
 *
 *  Created on: 29 oct. 2026
 *      Author: hP
 */
#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Article {
    string nom;
    double prixUnitaire;
    int quantite;
    double tva; // en pourcentage
};

class Facture {
private:
    vector<Article> articles;

public:
    // Version 1 : nom + prix (quantite = 1, TVA = 0%)
    void ajouterArticle(string nom, double prix) {
        articles.push_back({nom, prix, 1, 0});
    }

    // Version 2 : nom + prix + quantite (TVA = 0%)
    void ajouterArticle(string nom, double prix, int quantite) {
        articles.push_back({nom, prix, quantite, 0});
    }

    // Version 3 : nom + prix + quantite + TVA
    void ajouterArticle(string nom, double prix, int quantite, double tva) {
        articles.push_back({nom, prix, quantite, tva});
    }

    void afficherTotal() const {
        double total = 0;
        cout << "===== FACTURE =====" << endl;
        for (const Article& a : articles) {
            double ligne = a.prixUnitaire * a.quantite * (1 + a.tva / 100);
            cout << a.nom << " | " << a.prixUnitaire << " x " << a.quantite
                 << " | TVA " << a.tva << "% | " << ligne << " DH" << endl;
            total += ligne;
        }
        cout << "-------------------" << endl;
        cout << "TOTAL : " << total << " DH" << endl;
    }
};

int main() {
    Facture f;
    f.ajouterArticle("Stylo", 5);
    f.ajouterArticle("Cahier", 12, 3);
    f.ajouterArticle("Clavier", 150, 2, 20);

    f.afficherTotal();
    return 0;
}



