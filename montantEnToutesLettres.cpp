//
// Created by jonat on 19.10.2021.
//

#include "montantEnToutesLettres.h"
#include <math.h>

using namespace std;

const long double MAX_NUMBER = 999999999999.99;
const long double MIN_NUMBER = 00.00;

string montantEnToutesLettres(long double montant){
    if(montant>MAX_NUMBER){
        return "erreur : montant trop grand";
    }
    if(montant < MIN_NUMBER){
        return "erreur : montant negatif";
    }
    if(montant == 0.0)
    {
        return "zero franc";
    }

    string outputString = "";
    unsigned long long francs = montant;
    unsigned long long centimes = (montant - francs) * 100;
    unsigned int nbChiffreInFrancs = log(francs);
    unsigned int nbChiffreInCentimes = log(centimes);

    return outputString;
}

string dizaineEnToutesLettres(int dizaine){
    string outputString = "";
    switch(dizaine){
    case 0:
        break;
    case 1:
        outputString = "dix";
        break;
    case 2:
        outputString = "vingt";
        break;
    case 3:
        outputString = "trente";
        break;
    case 4:
        outputString = "quarante";
        break;
    case 5:
        outputString = "cinquante";
        break;
    case 6:
        outputString = "soixante";
        break;
    case 7:
        outputString = "septante";
        break;
    case 8:
        outputString = "huitante";
        break;
    case 9:
        outputString = "nonante";
    }
    return outputString;
}

