//
// Created by jonat on 19.10.2021.
//

#include "montantEnToutesLettres.h"
#include <math.h>

using namespace std;

const long double MAX_NUMBER = 999999999999.99;
const long double MIN_NUMBER = 00.00;


string montantEnToutesLettres(long double montant);
string chiffresEnToutesLettres(const unsigned int& chiffres);
string dizaineEnToutesLettres(const unsigned int& dizaine);
string francsEnToutesLettres(long long francs);
string nombreParticuliersEnToutesLettres(const unsigned int& nombreParticuliers);
string convertBlocCentaine(const unsigned int numberToConvert, const bool& isLastPart);
string affichageGrandNombres(const bool& is_francs_restants, const bool& is_centaine_only, const bool& is_multiple, const string& nomGrandNombre);


string montantEnToutesLettres(long double montant){
    //Return dès le début pour eviter un traitement trop long pour un resultat rapide
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
    unsigned long long centimes = round((montant - francs) * 100);
    if(centimes >= 100){
        centimes = centimes%100;
        francs += 1;
    }

    if(francs) {
        outputString += francsEnToutesLettres(francs);
        outputString += (francs > 1) ? " francs" : " franc";
        if(centimes) {
            outputString += " et ";
        }
    }

    if(centimes) {
        outputString += dizaineEnToutesLettres(centimes);
        outputString += (centimes > 1) ? " centimes" : " centime";
    }

    return outputString;
}

string chiffresEnToutesLettres(const unsigned int& chiffre){
    string outputString = "";
    switch(chiffre){
        case 0:
            break;
        case 1:
            outputString = "un";
            break;
        case 2:
            outputString = "deux";
            break;
        case 3:
            outputString = "trois";
            break;
        case 4:
            outputString = "quatre";
            break;
        case 5:
            outputString = "cinq";
            break;
        case 6:
            outputString = "six";
            break;
        case 7:
            outputString = "sept";
            break;
        case 8:
            outputString = "huit";
            break;
        case 9:
            outputString = "neuf";
    }
    return outputString;
}

string dizaineEnToutesLettres(const unsigned int& dizaine){
    string tmpString = "";
    int dizaineFirst = dizaine / 10;
    int reste = dizaine % 10;
    switch(dizaineFirst){
        case 0:
            break;
        case 1:
            if (reste && reste < 7)
                return nombreParticuliersEnToutesLettres(reste);
            tmpString = "dix";
            break;
        case 2:
            tmpString = "vingt";
            break;
        case 3:
            tmpString = "trente";
            break;
        case 4:
            tmpString = "quarante";
            break;
        case 5:
            tmpString = "cinquante";
            break;
        case 6:
            tmpString = "soixante";
            break;
        case 7:
            tmpString = "septante";
            break;
        case 8:
            tmpString = "huitante";
            break;
        case 9:
            tmpString = "nonante";
    }
    if(reste){
        if(dizaineFirst) {
            if (reste == 1)
                tmpString += "-et-";
            else
                tmpString += "-";
        }
        tmpString += chiffresEnToutesLettres(reste);
    }
    return tmpString;
}

string francsEnToutesLettres(long long francs){
    string francsEnToutesLettres = "";
    for (unsigned long long i = 1000000000000; i >= 1; i /= 1000) {
        //Split en partie de 3
        unsigned int tranche = francs / i;
        if (tranche != 0) {
            francsEnToutesLettres += convertBlocCentaine(tranche, i == 1 || (francs - tranche * i) == 0);
            francs -= tranche * i;
            switch (i) {
                case 1000000000:
                    francsEnToutesLettres += affichageGrandNombres(francs, !(tranche%100), tranche > 1, "milliard");
                    break;
                case 1000000:
                    francsEnToutesLettres += affichageGrandNombres(francs, !(tranche%100), tranche > 1, "million");
                    break;
                case 1000:
                    if(tranche > 1){
                        francsEnToutesLettres += "-";
                    }else{
                        francsEnToutesLettres = francsEnToutesLettres.substr(0,francsEnToutesLettres.length()-2);
                    }
                    francsEnToutesLettres += "mille";
            }
        }

        if (francsEnToutesLettres != "" && francs)
            francsEnToutesLettres += "-";
    }
    return francsEnToutesLettres;
}

string nombreParticuliersEnToutesLettres(const unsigned int& nombreParticuliers){
    string tmpString;
    switch(nombreParticuliers){
        case 1:
            tmpString = "onze";
            break;
        case 2:
            tmpString = "douze";
            break;
        case 3:
            tmpString = "treize";
            break;
        case 4:
            tmpString = "quatorze";
            break;
        case 5:
            tmpString = "quinze";
            break;
        case 6:
            tmpString = "seize";
            break;
    }
    return tmpString;
}

string convertBlocCentaine(const unsigned int numberToConvert, const bool& isLastPart){
    string tmpString = "";
    const unsigned int centaine = numberToConvert / 100;
    const unsigned int dizaine = numberToConvert % 100;
    if(centaine) {
        if(centaine != 1)
            tmpString += chiffresEnToutesLettres(centaine) + "-";
        tmpString += "cent";
    }
    if(dizaine) {
        if (centaine)
            tmpString += "-";
        tmpString += dizaineEnToutesLettres(dizaine);
    }
    if(centaine > 1 && !dizaine && isLastPart)
        tmpString += "s";
    return tmpString;
}

string affichageGrandNombres(const bool& is_francs_restants, const bool& is_centaine_only, const bool& is_multiple, const string& nomGrandNombre){
    string outputString;
    outputString = (is_centaine_only || is_francs_restants ? "-" : " ");
    outputString += nomGrandNombre;
    outputString += (is_multiple ? "s" : "");
    outputString += (!is_francs_restants ? " de" : "");
    return outputString;
}






