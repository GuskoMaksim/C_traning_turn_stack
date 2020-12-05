#pragma once
#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;

class Bus_Depot
{
protected:
    struct bus_depot_struct
    {
        int num_bus;
        int num_route;
        string second_name;
        string initial;
        bus_depot_struct* next;
    };
    struct bus_route_struct
    {
        int num_bus;
        int num_route;
        string second_name;
        string initial;
        bus_route_struct* next;
    };
    bus_depot_struct* First;
    bus_depot_struct* Now;
    bus_route_struct* First_route;
    bus_route_struct* Now_route;
public:
    void show_all_depot()
    {
        if (First != NULL)
        {
            cout << "Список автобусов на автостанции: " << endl << endl;
            Now = First;
            while (Now != NULL)
            {
                cout << "Номер автобуса " << Now->num_bus << endl;
                cout << "Номер маршрута " << Now->num_route << endl;
                cout << "Фамилия инициалы " << Now->second_name << " " << Now->initial << endl << endl;
                Now = Now->next;
            }
        }
        else {
            cout << "Список пуст!" << endl;
        }
    }

    void show_all_route()
    {
        if (First_route != NULL)
        {
            cout << "Список автобусов на маршруте: " << endl << endl;
            Now_route = First_route;
            while (Now_route != NULL)
            {
                cout << "Номер автобуса " << Now_route->num_bus << endl;
                cout << "Номер маршрута " << Now_route->num_route << endl;
                cout << "Фамилия инициалы " << Now_route->second_name << " " << Now_route->initial << endl << endl;
                Now_route = Now_route->next;
            }
        }
        else {
            cout << "Список пуст!" << endl;
        }
    }

    void add_bus(string new_second_name, string new_initial, int new_num_bus, int new_num_route) {
        if (First == NULL)
        {
            First = new bus_depot_struct;
            First->num_bus = new_num_bus;
            First->num_route = new_num_route;
            First->second_name = new_second_name;
            First->initial = new_initial;
            First->next = NULL;
        }
        else
        {
            Now = First;
            while (Now->next != NULL)
            {
                Now = Now->next;
            }
            bus_depot_struct* NEW;
            NEW = new bus_depot_struct;
            NEW->num_bus = new_num_bus;
            NEW->num_route = new_num_route;
            NEW->second_name = new_second_name;
            NEW->initial = new_initial;
            NEW->next = NULL;
            Now->next = NEW;
        }
    }
    
    void add_bus_before(int before_bus, string new_second_name, string new_initial, int new_num_bus, int new_num_route)
    {
        if (First == NULL)
        {
            add_bus(new_second_name, new_initial, new_num_bus, new_num_route);
        }
        else
        {
            if (before_bus == 1)
            {
                bus_depot_struct* NEW;
                NEW = new bus_depot_struct;
                NEW->num_bus = new_num_bus;
                NEW->num_route = new_num_route;
                NEW->second_name = new_second_name;
                NEW->initial = new_initial;
                NEW->next = First;
                First = NEW;
            }
            else
            {
                Now = First;
                for (int i = 1; i < before_bus - 1; i++)
                {
                    if (Now == NULL)
                    {
                        throw exception("Введено число больше, чем количесво автобусов");
                    }
                    Now = Now->next;
                }
                if (Now == NULL)
                {
                    throw exception("Введено число больше, чем количесво автобусов");
                }
                bus_depot_struct* NEW;
                NEW = new bus_depot_struct;
                NEW->num_bus = new_num_bus;
                NEW->num_route = new_num_route;
                NEW->second_name = new_second_name;
                NEW->initial = new_initial;
                NEW->next = Now->next;
                Now->next = NEW;
            }
        }

    }
    
    void add_bus_route(string new_second_name, string new_initial, int new_num_bus, int new_num_route) {
        if (First_route == NULL)
        {
            First_route = new bus_route_struct;
            First_route->num_bus = new_num_bus;
            First_route->num_route = new_num_route;
            First_route->second_name = new_second_name;
            First_route->initial = new_initial;
            First_route->next = NULL;
        }
        else
        {
            Now_route = First_route;
            while (Now_route->next != NULL)
            {
                Now_route = Now_route->next;
            }
            bus_route_struct* NEW;
            NEW = new bus_route_struct;
            NEW->num_bus = new_num_bus;
            NEW->num_route = new_num_route;
            NEW->second_name = new_second_name;
            NEW->initial = new_initial;
            NEW->next = NULL;
            Now_route->next = NEW;
        }
    }

    void bus_add_depot(int _num_bus)
    {
        if (First_route == NULL)
        {
            throw exception("Список автобусов на маршруте пуст");
        }
        bus_route_struct* Last;
        Last = First_route;
        Now_route = First_route;
        while (Now_route != NULL)
        {
            if (this->Now_route->num_bus == _num_bus)
            {
                if (this->Now_route == First_route)
                {
                    First_route = this->Now_route->next;
                }
                else
                    Last->next = Now_route->next;
                add_bus(Now_route->second_name, Now_route->initial, Now_route->num_bus, Now_route->num_route);
                delete Now_route;
                break;
            }
            if (Now_route == Last)
            {
                Now = Now->next;
            }
            else
            {
                Last = Now_route;
                Now_route = Now_route->next;
            }
        }
    }

    void bus_add_route(int _num_bus)
    {
        if (First == NULL)
        {
            throw exception("Список автобусов на станции пуст");
        }
        bus_depot_struct* Last;
        Last = First;
        Now = First;
        while (Now != NULL)
        {
            if (this->Now->num_bus == _num_bus)
            {
                if (Now == First)
                {
                    First = this->Now->next;
                }
                else
                    Last->next = Now->next;
                add_bus_route(Now->second_name, Now->initial, Now->num_bus, Now->num_route);
                delete Now;
                break;
            }
            if (Now== Last)
            {
                Now = Now->next;
            }
            else
            {
                Last = Now;
                Now = Now->next;
            }
        }
    }

    Bus_Depot()
    {
        First = NULL;
        Now = NULL;
        First_route = NULL;
        Now_route = NULL;
    }
    ~Bus_Depot()
    {
        if (First != NULL)
        {
            Now = First;
            while (Now != NULL)
            {
                bus_depot_struct* Next;
                Next = Now->next;
                delete Now;
                Now = Next;
            }
            First = NULL;
            Now = NULL;
            cout << "Список очищен!" << endl;
        }
        else {
            cout << "Список пуст!" << endl;
        }
    }
};