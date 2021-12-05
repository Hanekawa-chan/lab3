//
// Created by Tobias on 14.11.2021.
//
#pragma once
#include <string>

#ifndef LAB3_QUITTANCE_H
#define LAB3_QUITTANCE_H

#endif //LAB3_QUITTANCE_H

using namespace std;

class Quittance {
private:
    int number;
    int date;
    float summary;
public:
    Quittance() {
        number = 0;
        date = 0;
        summary = 0;
        cout << "Квитанция №" << number << ": Стандартный конструктор был вызван\n\n";
    }
    Quittance(int num, int dat, float sum) {
        number = num;
        date = dat;
        summary = sum;
        cout << "Квитанция №" << number << ": Конструктор с параметрами был вызван\n\n";
    }
    Quittance(Quittance const &quit) {
        number = quit.number;
        date = quit.date;
        summary = quit.summary;
        cout << "Квитанция №" << number << ": Конструктор копирования был вызван\n\n";
    }
    void set_number(int num) {
        number = num;
    }
    int get_number() const {
        return number;
    }
    void set_date(int dat) {
        date = dat;
    }
    int get_date() const {
        return date;
    }
    void set_summary(float sum) {
        summary = sum;
    }
    float get_summary() const {
        return summary;
    }
    string get_log() const {
        string log = "number=" + to_string(number) +
                     "\ndate=" + to_string(date) +
                     "\nsummary=" + to_string(summary);
        return log;
    }
    ~Quittance()
    {
        cout << "Квитанция №" << number << ": Деструктор был вызван. Прощайте.\n\n";
    }
    static string get_most(Quittance quits[], int size) {
        float max = quits[0].summary;
        for (int i = 0; i < size; i++) {
            if (quits[i].summary > max) {
                max = quits[i].summary;
            }
        }
        return "Наибольшая сумма квитанции равна: " + to_string(max);
    }
};