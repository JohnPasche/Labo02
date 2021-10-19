//
// Created by jonat on 19.10.2021.
//

#include "montantEnToutesLettres.h"
#include <math.h>

using namespace std;

const long double MAX_NUMBER = 999999999999.99;
const long double MIN_NUMBER = 00.00;


string chiffresEnToutesLettres(int chiffres){
    string outputString = "";
    switch(chiffres){
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

string nombreParticuliersEnToutesLettres(int nombreParticuliers){
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

string dizaineEnToutesLettres(int dizaine){
    string tmpString = "";
    int dizaineFirst = dizaine/10;
    int reste = dizaine - (dizaineFirst * 10);
    if(dizaineFirst == 1 && reste && reste < 7){
        tmpString = nombreParticuliersEnToutesLettres(reste);
    }else{
        switch(dizaineFirst){
            case 0:
                break;
            case 1:
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
    }
    return tmpString;
}


string convert(unsigned int numberToConvert, bool isLastPart){
 string tmpString = "";
 int centaine = numberToConvert / 100;
 int dizaine = numberToConvert - (centaine * 100);
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
string francsEnToutesLettres(long long francs){
    string francsEnToutesLettres = "";
    for (unsigned long long i = 1000000000000; i >= 1; i /= 1000) {
        unsigned int tranche = francs / i;
        if (tranche != 0) {
            francsEnToutesLettres += convert(tranche, i == 1);
            francs -= tranche * i;
            switch (i) {
                case 1000000000:
                    francsEnToutesLettres += "-milliard";
                    francsEnToutesLettres += ((tranche > 1) ? "s" : "");
                    francsEnToutesLettres += ((!francs) ? " de " : "");
                    break;
                case 1000000:
                    francsEnToutesLettres += "-million";
                    francsEnToutesLettres += (tranche > 1) ? "s" : "";
                    francsEnToutesLettres += ((!francs) ? " de" : "");
                    break;
                case 1000:
                    francsEnToutesLettres += "-mille";
            }
        }

        if (francsEnToutesLettres != "" && francs)
            francsEnToutesLettres += "-";
    }
    return francsEnToutesLettres;
}


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
    const unsigned long long FRANCS = montant;
    const unsigned long long CENTIMES = round((montant - FRANCS) * 100);

    if(FRANCS) {
        outputString += francsEnToutesLettres(FRANCS);
        outputString += (FRANCS > 1) ? " francs" : " franc";
        if(CENTIMES) {
            outputString += " et ";
        }
    }

    if(CENTIMES) {
        outputString += dizaineEnToutesLettres(CENTIMES);
        outputString += (CENTIMES > 1) ? " centimes" : " centime";
    }

    return outputString;
}


