/*
 * Ex1.cpp
 *
 *  Created on: 29 oct. 2026
 *      Author: hP
 */
#include <iostream>
#include <string>
using namespace std;

class Contact {
private:
    string nom;
    string telephone;
    string email;

public:
    // Constructeur 1 : nom uniquement
    Contact(string n) : nom(n), telephone("Non renseigne"), email("Non renseigne") {}

    // Constructeur 2 : nom + telephone
    Contact(string n, string tel) : nom(n), telephone(tel), email("Non renseigne") {}

    // Constructeur 3 : nom + telephone + email
    Contact(string n, string tel, string mail) : nom(n), telephone(tel), email(mail) {}

    void afficher() const {
        cout << "Nom       : " << nom << endl;
        cout << "Telephone : " << telephone << endl;
        cout << "Email     : " << email << endl;
        cout << "--------------------------" << endl;
    }
};

int Main() {
    Contact c1("Ahmed");
    Contact c2("Sara", "0612345678");
    Contact c3("Youssef", "0698765432", "youssef@mail.com");

    c1.afficher();
    c2.afficher();
    c3.afficher();

    return 0;
}
