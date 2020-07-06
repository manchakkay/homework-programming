#include "Currency.h"

//Перевод в мелкую валюту
double Currency::to_lower(double high_currency){
    return high_currency * 100;
}
//Перевод в мелкую валюту
double Currency::to_higher(double low_currency){
    return low_currency / 100;
}

//Перевод в рубли
double Currency::to_rubles(double cur_amount){
    return cur_amount * ((1 / CUR_EUR) * RUB_EUR);
}
//Вывод в рубях
double Currency::get_rubles(){
    return to_rubles(amount);
}
//Вывод в копейках
double Currency::get_kopek(){
    return to_lower(to_rubles(amount));
}

//Конструктор доллара
Dollar::Dollar(double EUR_USD){
    CUR_EUR = EUR_USD;
}
//Вывод в центах
double Dollar::get_cent(){
    return to_lower(amount);
}
//Вывод в долларах
double Dollar::get_dollar(){
    return amount;
}

//Конструктор евро
Euro::Euro(double EUR_EUR){
    CUR_EUR = EUR_EUR;
}
//Вывод в евроцентах
double Euro::get_eurocent(){
    return to_lower(amount);
}
//Вывод в евро
double Euro::get_euro(){
    return amount;
}

//Конструктор фунта
Pound::Pound(double EUR_GBP){
    CUR_EUR = EUR_GBP;
}
//Вывод в пенни
double Pound::get_penny(){
    return to_lower(amount);
}
//Вывод в фунтах
double Pound::get_pound(){
    return amount;
}