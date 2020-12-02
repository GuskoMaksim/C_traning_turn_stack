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
        cout << "1- ������ ��������� �� �������" << endl;
        cout << "2- ������ ��������� �� ���������" << endl;
        cout << "3- �������� �������" << endl;
        cout << "4- �������� ������� ����� �����-��" << endl;
        cout << "5- ��������� ������� �� �������" << endl;
        cout << "6- ������� ������� � ��������" << endl;
        cout << "0- �����";
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
            cout << "������� ������� ��������: " << endl;
            cin >> second_name;
            cout << "������� �������� ��������: " << endl;
            cin >> inic;
            cout << "������� ����� ��������: " << endl;
            cin >> number_bus;
            cout << "������� ����� ��������: " << endl;
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
            cout << "����� ����� ��������� �������� �����?" << endl;
            cin >> befor;
            cout << "������� ������� ��������: " << endl;
            cin >> second_name;
            cout << "������� �������� ��������: " << endl;
            cin >> inic;
            cout << "������� ����� ��������: " << endl;
            cin >> number_bus;
            cout << "������� ����� ��������: " << endl;
            cin >> number_route;
            Brest.add_bus(second_name, inic, number_bus, number_route);
            _getch();
            break;
        }
        case 5:
        {
            int num;
            Brest.show_all_depot();
            cout << "����� ��������, ������� ��������� �� �������" << endl;
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
            cout << "����� ��������, ������� ������� �� �������" << endl;
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
