#include <iostream>
#include <string>
#include <Windows.h>
#include <conio.h>
#include "Bus_Depot.h"

using namespace std;

void menu(Bus_Depot Brest)
{
    int vib = 0;
    bool ind = true;
    while (ind)
    {
        system("cls");
        cout << "1- Список автобусов на станции" << endl;
        cout << "2- Список автобусов на маршрутах" << endl;
        cout << "3- Добавить автобус" << endl;
        cout << "4- Добавить автобус перед каким-то" << endl;
        cout << "5- Отправить автобус на маршрут" << endl;
        cout << "6- Принять автобус с маршрута" << endl;
        cout << "0- Выход";
            vib = _getch() - 48;
        switch (vib)
        {
        case 1:
        {
            Brest.show_all_depot();
            _getch();
            break;
        }
        case 2:
        {
            Brest.show_all_route();
            _getch();
            break;
        }
        case 3:
        {
            string second_name;
            string inic;
            int number_bus;
            int number_route;
            cout << "Введите фамилию водителя: " << endl;
            cin >> second_name;
            cout << "Введите инициалы водителя: " << endl;
            cin >> inic;
            cout << "Введите номер автобуса: " << endl;
            cin >> number_bus;
            cout << "Введите номер маршрута: " << endl;
            cin >> number_route;
            Brest.add_bus(second_name, inic, number_bus, number_route);
            _getch();
            break;
        }
        case 4:
        {
            string second_name;
            string inic;
            int number_bus;
            int number_route;
            int befor;
            cout << "Перед каким автобусом добавить новый?" << endl;
            cin >> befor;
            cout << "Введите фамилию водителя: " << endl;
            cin >> second_name;
            cout << "Введите инициалы водителя: " << endl;
            cin >> inic;
            cout << "Введите номер автобуса: " << endl;
            cin >> number_bus;
            cout << "Введите номер маршрута: " << endl;
            cin >> number_route;
            Brest.add_bus(second_name, inic, number_bus, number_route);
            _getch();
            break;
        }
        case 5:
        {
            int num;
            Brest.show_all_depot();
            cout << "Номер автобуса, который отправить на маршрут" << endl;
            cin >> num;
            try
            {
                Brest.bus_add_route(num);
            }
            catch (const std::exception& e)
            {
                cout << e.what() << endl;
            }
            break;
        }
        case 6:
        {
            int num;
            Brest.show_all_route();
            cout << "Номер автобуса, который принять на станцию" << endl;
            cin >> num;
            try
            {
                Brest.bus_add_depot(num);
            }
            catch (const std::exception& e)
            {
                cout << e.what() << endl;
            }
        }
        case 0:
        {
            ind = 0;
            break;
        }
        default:
            break;
        }
    }
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Bus_Depot Brest;
    Brest.add_bus("Gusko", "MN", 1, 2);
    Brest.add_bus("Husko", "NB", 2, 1);
    Brest.add_bus("Milko", "WV", 3, 4);
    menu(Brest);
}
