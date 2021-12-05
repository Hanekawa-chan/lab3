#include <iostream>
#include <string>
#include "Quittance.h"

using namespace std;

int main() {
    system("chcp 65001");//для русского языка в Clion
    auto *quit1 = new Quittance();
    quit1->set_number(0);
    quit1->set_date(13112021);
    quit1->set_summary(12.15f);
    auto *quit = new Quittance(1, 13112021, 100.00f);
    auto *quit2 = new Quittance(*quit1);
    cout << "Вывод квитанций:\n\n";
    cout << quit->get_log();
    string log = "number=" + to_string(quit1->get_number()) +
                 "\ndate=" + to_string(quit1->get_date()) +
                 "\nsummary=" + to_string(quit1->get_summary());
    cout << "\n\n" << log << "\n\n";
    cout << quit2->get_log() << "\n\n";

    auto *quits = new Quittance[3];
    quits[0] = *quit;
    quits[1] = *quit1;
    quits[2] = *quit2;
    cout << Quittance::get_most(reinterpret_cast<Quittance *>(quits), 3) << "\n\n";
    delete quit;
    delete quit1;
    delete quit2;
}