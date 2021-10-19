/*
-----------------------------------------------------------------------------------
Nom du fichier : <nom du fichier>.<xxx> (xxx = h ou cpp)
Auteur(s) : <prénom> <nom>
Date creation : <jj.mm.aaaa>
Description : <à compléter>
Remarque(s) : <à compléter>
Compilateur : Mingw-w64 g++ 11.1.0
-----------------------------------------------------------------------------------
*/
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include "montantEnToutesLettres.h"

using namespace std;
int main() {
    long double d;
    while(cin >> d)
    {
        cout << fixed << setprecision(2)
            << d << endl
            << montantEnToutesLettres(d) << endl;
    }
 return EXIT_SUCCESS;
}