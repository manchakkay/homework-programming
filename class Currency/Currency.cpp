#include "Currency.h"


double Currency::to_lower(double high_currency){
    return high_currency * 100;
}

double Currency::to_higher(double low_currency){
    return low_currency / 100;
}


double Currency::to_rubles(double cur_amount){
    return cur_amount * ((1 / CUR_EUR) * RUB_EUR);
}

double Currency::get_rubles(){
    return to_rubles(amount);
}

double Currency::get_kopek(){
    return to_lower(to_rubles(amount));
}


Dollar::Dollar(double EUR_USD){
    CUR_EUR = EUR_USD;
}

double Dollar::get_cent(){
    return to_lower(amount);
}

double Dollar::get_dollar(){
    return amount;
}


Euro::Euro(double EUR_EUR){
    CUR_EUR = EUR_EUR;
}

double Euro::get_eurocent(){
    return to_lower(amount);
}

double Euro::get_euro(){
    return amount;
}


Pound::Pound(double EUR_GBP){
    CUR_EUR = EUR_GBP;
}

double Pound::get_penny(){
    return to_lower(amount);
}

double Pound::get_pound(){
    return amount;
}