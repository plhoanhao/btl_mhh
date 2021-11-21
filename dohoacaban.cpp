#include <iostream>
#include <string>
#include <vector>
#include "mylib.h"
using namespace std;

class Transition;
class Place
{
public:
    string name;
    int token;
    vector<int> input;
    vector<int> output;
    int x;
    int y;
    Place()
    {
        name = "";
        token = 0;
        x = 0;
        y = 0;
    }
    Place(string name, int token, int x, int y)
    {
        this->name = name;
        this->token = token;
        this->x = x;
        this->y = y;
    }
};

class Transition
{
public:
    string name = "";
    vector<int> input;
    vector<int> output;
    vector<int> e;
    int x;
    int y;
    Transition()
    {
        name = "";
        x = 0;
        y = 0;
    }
    Transition(string name, int x, int y)
    {
        this->name = name;
        this->x = x;
        this->y = y;
    }
};

class PetriNet
{
public:
    vector<Transition> trans;
    vector<Place> place;
    // in mo hinh
    void PrintModel1(bool edge[4])
    {
        clrscr();
        gotoXY(10, 5);
        cout << "(" << (place[0]).name << ": " << (place[0]).token << ")";
        if (edge[0])
        {
            SetColor(12);
            PrintEdgeX(20, 40, 5);
            SetColor(7);
        }
        else
            PrintEdgeX(20, 40, 5);
        box(40, 4, 10, 2, 2, (trans[0]).name);
        if (edge[1])
        {
            SetColor(12);
            PrintEdgeX(51, 70, 5);
            SetColor(7);
        }
        else
            PrintEdgeX(51, 70, 5);
        gotoXY(70, 5);
        cout << "(" << (place[1]).name << ": " << (place[1]).token << ")";
        if (edge[2])
        {
            SetColor(12);
            PrintEdgeX(82, 102, 5);
            SetColor(7);
        }
        else
            PrintEdgeX(82, 102, 5);
        box(102, 4, 10, 2, 2, (trans[1]).name);
        if (edge[3])
        {
            SetColor(12);
            PrintEdgeX(113, 132, 5);
            SetColor(7);
        }
        else
            PrintEdgeX(113, 132, 5);
        gotoXY(132, 5);
        cout << "(" << (place[2]).name << ": " << (place[2]).token << ")";
        gotoXY(15, 8);
        cout << "Wait: " << (place[0]).token << ", Inside: " << (place[1]).token << ", Done: " << (place[2]).token;
        Sleep(1000);
    }

    void PrintModel2(bool edge[6])
    {
        clrscr();
        cout << "Press E to exit.";
        gotoXY(place[0].x, place[0].y);
        cout << "(" << (place[0]).name << ": " << (place[0]).token << ")";
        if (edge[0])
        {
            SetColor(12);
            PrintEdgeY(6, 10, place[0].x + 5);
            SetColor(7);
        }
        else
            PrintEdgeY(6, 10, place[0].x + 5);
        box(trans[0].x, trans[0].y, 10, 2, 2, (trans[0]).name);
        if (edge[1])
        {
            SetColor(12);
            PrintEdgeX(21, 40, 11);
            SetColor(7);
        }
        else
            PrintEdgeX(21, 40, 11);
        gotoXY(place[1].x, place[1].y);
        cout << "(" << (place[1]).name << ": " << (place[1]).token << ")";
        if (edge[2])
        {
            SetColor(12);
            PrintEdgeX(51, 70, 11);
            SetColor(7);
        }
        else
            PrintEdgeX(51, 70, 11);
        box(trans[1].x, trans[1].y, 10, 2, 2, (trans[1]).name);
        if (edge[3])
        {
            SetColor(12);
            PrintEdgeY(10, 6, place[2].x + 5);
            SetColor(7);
        }
        else
            PrintEdgeY(10, 6, place[2].x + 5);
        gotoXY(place[2].x, place[2].y);
        cout << "(" << (place[2]).name << ": " << (place[2]).token << ")";
        if (edge[4])
        {
            SetColor(12);
            PrintEdgeX(70, 51, 5);
            SetColor(7);
        }
        else
            PrintEdgeX(70, 51, 5);
        box(trans[2].x, trans[2].y, 10, 2, 2, (trans[2]).name);
        if (edge[5])
        {
            SetColor(12);
            PrintEdgeX(40, 21, 5);
            SetColor(7);
        }
        else
            PrintEdgeX(40, 21, 5);
        // In canh
        gotoXY(15, 15);
        cout << "Wait: " << (place[0]).token << ", Inside: " << (place[1]).token << ", Done: " << (place[2]).token;
        Sleep(1000);
    }

    void PrintModel3(bool edge[10])
    {
        clrscr();
        cout << "Press E to exit.";
        gotoXY(place[0].x, place[0].y);
        cout << "(" << (place[0]).name << ": " << (place[0]).token << ")";
        if (edge[0])
        {
            SetColor(12);
            PrintEdgeX(21, 40, 11);
            SetColor(7);
        }
        else
            PrintEdgeX(21, 40, 11);
        box(trans[0].x, trans[0].y, 10, 2, 2, (trans[0]).name);
        if (edge[1])
        {
            SetColor(12);
            PrintEdgeX(51, 70, 11);
            SetColor(7);
        }
        else
            PrintEdgeX(51, 70, 11);
        if (edge[2])
        {
            SetColor(12);
            PrintCornerL();
            SetColor(7);
        }
        else
            PrintCornerL();
        gotoXY(place[1].x, place[1].y);
        cout << "(" << place[1].name << ": " << place[1].token << ")";
        gotoXY(place[2].x, place[2].y);
        cout << "(" << place[2].name << ": " << place[2].token << ")";
        if (edge[3])
        {
            SetColor(12);
            PrintEdgeX(81, 100, 11);
            SetColor(7);
        }
        else
            PrintEdgeX(81, 100, 11);
        if (edge[4])
        {
            SetColor(12);
            PrintCornerR();
            SetColor(7);
        }
        else
            PrintCornerR();
        box(trans[1].x, trans[1].y, 10, 2, 2, trans[1].name);
        if (edge[5])
        {
            SetColor(12);
            PrintEdgeX(111, 130, 11);
            SetColor(7);
        }
        else
            PrintEdgeX(111, 130, 11);
        gotoXY(130, 11);
        cout << "(" << (place[3]).name << ": " << (place[3]).token << ")";
        if (edge[6])
        {
            SetColor(12);
            PrintEdgeY(10, 6, place[4].x + 5);
            SetColor(7);
        }
        else
            PrintEdgeY(10, 6, place[4].x + 5);
        gotoXY(place[4].x, place[4].y);
        cout << "(" << (place[4]).name << ": " << (place[4]).token << ")";
        if (edge[7])
        {
            SetColor(12);
            PrintEdgeX(100, 81, 5);
            SetColor(7);
        }
        else
            PrintEdgeX(100, 81, 5);
        box(trans[2].x, trans[2].y, 10, 2, 2, (trans[2]).name);
        if (edge[8])
        {
            SetColor(12);
            PrintEdgeX(70, 51, 5);
            SetColor(7);
        }
        else
            PrintEdgeX(70, 51, 5);
        gotoXY(40, 5);
        cout << "(" << (place[5]).name << ": " << (place[5]).token << ")";
        if (edge[9])
        {
            SetColor(12);
            PrintEdgeY(6, 10, place[5].x + 5);
            SetColor(7);
        }
        else
            PrintEdgeY(6, 10, place[5].x + 5);
        // In so lieu
        gotoXY(15, 20);
        cout << "Wait: " << (place[0]).token << ", Inside: " << (place[1]).token << ", Done: " << (place[3]).token;
        gotoXY(15, 21);
        cout << "Free: " << (place[5]).token << ", Busy: " << (place[2]).token << ", Docu: " << (place[4]).token;
        Sleep(2000);
    }

    // ham in phu
    void box(int x, int y, int w, int h, int t_color, string nd)
    {
        SetColor(7);
        gotoXY(x + 1, y + 1);
        cout << nd;
        //============= ve vien =============
        textcolor(1);
        SetColor(t_color); //update
        if (h <= 1 || w <= 1)
            return;
        for (int ix = x; ix <= x + w; ix++)
        {
            gotoXY(ix, y);
            cout << char(196);
            gotoXY(ix, y + h);
            cout << char(196);
        }
        for (int iy = y; iy <= y + h; iy++)
        {
            gotoXY(x, iy);
            cout << char(179);
            gotoXY(x + w, iy);
            cout << char(179);
        }
        gotoXY(x, y);
        cout << char(218);
        gotoXY(x + w, y);
        cout << char(191);
        gotoXY(x, y + h);
        cout << char(192);
        gotoXY(x + w, y + h);
        cout << char(217);
        SetColor(7);
    }

    void PrintEdgeX(int ox, int x, int y)
    {
        if (ox > x)
        {
            gotoXY(x, y);
            cout << char(60);
            x++;
        }
        else
        {
            gotoXY(x - 1, y);
            x--;
            cout << char(62);
            gotoXY(ox, y);
        }
        int i = 0;
        while (i < abs(x - ox))
        {
            cout << char(196);
            i++;
        }
    }

    void PrintEdgeY(int oy, int y, int x)
    {
        if (oy > y)
        {
            gotoXY(x, y);
            cout << '^';
            y++;
        }
        else
        {
            gotoXY(x, y - 1);
            y--;
            cout << 'v';
        }
        int i = 0;
        while (i < abs(y - oy))
        {
            if (oy < y)
            {
                gotoXY(x, oy + i);
                cout << char(179);
            }
            else
            {
                gotoXY(x, y + i);
                cout << char(179);
            }
            i++;
        }
    }

    void PrintCornerL()
    {
        gotoXY(45, 17);
        cout << char(192);
        for (int i = 45; i < 68; i++)
        {
            cout << char(196);
        }
        for (int i = 13; i <= 16; i++)
        {
            gotoXY(45, i);
            cout << char(179);
        }    
        gotoXY(68, 17);
        cout << '>';
    }
    
    void PrintCornerR()
    {
        gotoXY(105, 17);
        cout << char(217);
        gotoXY(82, 17);
        for (int i = 82; i < 105; i++)
        {
            cout << char(196);
        }
        for (int i = 13; i <= 16; i++)
        {
            gotoXY(105, i);
            cout << char(179);
        }    
        gotoXY(105,13);
        cout << '^';
    }
    // ham chinhh
    void Exercise1()
    {
        // nhap so lieu
        int waitT = 0;
        int insideT = 0;
        int doneT = 0;
        cout << "Wait = ", cin >> waitT, cout << endl;
        cout << "Inside = ", cin >> insideT, cout << endl;
        cout << "Done = ", cin >> doneT, cout << endl;
        // khoi tao place
        place.resize(3);
        place[0] = Place("Wait", waitT, 10, 5);
        place[1] = Place("Inside", insideT, 70, 5);
        place[2] = Place("Done", doneT, 132, 5);
        // khoi tao transition
        trans.resize(3);
        trans[0] = Transition("  Start", 40, 5);
        trans[1] = Transition(" Change", 102, 5);
        // xu ly
        bool edge[4];
        for (int i = 0; i < 4; i++)
            edge[i] = false;
        for (int i = 0; i < trans.size(); i++)
        {
            while (place[i].token > 0)
            {
                edge[i * 2] = edge[i * 2 + 1] = true;
                PrintModel1(edge);
                place[i].token--;
                PrintModel1(edge);
                place[i + 1].token++;
                edge[i * 2] = edge[i * 2 + 1] = false;
            }
            PrintModel1(edge);
        }
    }

    void Exercise2()
    {
        // nhap du lieu
        int freeT = 0;
        int busyT = 0;
        int docuT = 0;
        cout << "free = ", cin >> freeT, cout << endl;
        cout << "busy = ", cin >> busyT, cout << endl;
        cout << "docu = ", cin >> docuT, cout << endl;
        // khoi tao place
        place.resize(3);
        place[0] = Place(" Free", freeT, 10, 5);
        place[1] = Place(" Busy", busyT, 40, 11);
        place[2] = Place(" Docu", docuT, 70, 5);
        // khoi tao transition
        trans.resize(3);
        trans[0] = Transition("  Start", 10, 10);
        trans[1] = Transition(" Change", 70, 10);
        trans[2] = Transition("  End", 40, 4);
        bool edge[6];
        for (int i = 0; i < 6; i++)
            edge[i] = false;
        int i = 0;
        int key;
        while (1)
        {
            if (place[0].token == 0 && place[1].token == 0 && place[2].token == 0)
                break;
            if (i == 3)
                i = 0;
            while (place[i].token > 0)
            {
                key = inputKey();
                if (key == 'E' || key == 'e')
                {
                    PrintModel2(edge);
                    break;
                }
                edge[i * 2] = edge[i * 2 + 1] = true;
                PrintModel2(edge);
                place[i].token--;
                PrintModel2(edge);
                place[(i + 1) % 3].token++;
                edge[i * 2] = edge[i * 2 + 1] = false;
            }
            if (key == 'E' || key == 'e')
                break;
            PrintModel2(edge);
            i++;
        }
    }

    void Exercise3()
    {
        // nhap so lieu
        int waitT = 0;
        int insideT = 0;
        int doneT = 0;
        int freeT = 0;
        int busyT = 0;
        int docuT = 0;
        Reset:
        cout << "wait = ", cin >> waitT, cout << endl;
        cout << "free = ", cin >> freeT, cout << endl;
        cout << "inside = ", cin >> insideT, cout << endl;
        cout << "busy = ", cin >> busyT, cout << endl;
        cout << "done = ", cin >> doneT, cout << endl;
        cout << "docu = ", cin >> docuT, cout << endl;
        // khoi tao place
        place.resize(7);
        place[0] = Place("Wait", waitT, 10, 11);
        place[1] = Place("Inside", insideT, 70, 17);
        place[3] = Place("Done", doneT, 130, 11);

        place[5] = Place(" Free", freeT, 40, 5);
        place[2] = Place(" Busy", busyT, 70, 11);
        place[4] = Place(" Docu", docuT, 100, 5);

        place[6] = Place(" Temp", 100, 0, 0);
        // khoi tao trans
        trans.resize(3);
        trans[0] = Transition("  Start", 40, 10);
        trans[1] = Transition(" Change", 100, 10);
        trans[2] = Transition("  End", 70, 4);
        trans[0].input = vector<int> {0,5};
        trans[0].output = vector<int> {1,2};
        trans[0].e = vector<int> {0,9,1,2};
        trans[1].input = vector<int> {1,2};
        trans[1].output = vector<int> {3,4};
        trans[1].e = vector<int> {3,4,5,6};
        trans[2].input = vector<int> {4, 6};
        trans[2].output = vector<int> {5, 6};
        trans[2].e = vector<int> {7,8};
        bool edge[10];
        for (int i = 0; i < 10; i++)
            edge[i] = false;
        int k = 0;
        int key;
        bool check = true;
        while (check)
        {
            check = false;
            for (int i = 0; i < 3; i++)
            {
                while (place[trans[i].input[0]].token > 0 && place[trans[i].input[1]].token > 0)
                {
                    check = true;
                    key = inputKey();
                    if (key == 'E' || key == 'e')
                    {
                        PrintModel3(edge);
                        goto Exit;
                    }
                    for (int j = 0; j < trans[i].e.size(); j++)
                        edge[trans[i].e[j]] = true;
                    PrintModel3(edge);
                    place[trans[i].input[0]].token--;
                    place[trans[i].input[1]].token--;
                    PrintModel3(edge);
                    place[trans[i].output[0]].token++;
                    place[trans[i].output[1]].token++;
                    for (int j = 0; j < trans[i].e.size(); j++)
                        edge[trans[i].e[j]] = false;
                }
                PrintModel3(edge);
            }
            if (check == false) break;
        }
        Exit:
        gotoXY(0, 24);
        cout << "Press R to reset. Press E to exit";
        while (1)
        {
            key = inputKey();
            if (key == 'R' || key == 'r')
            {
                clrscr();
                goto Reset;
            }
            else 
            {
                break;
            }
        }
    }

    void Exercise4()
    {

    }
};

int main()
{
    resizeConsole(1600, 900);
    int t = 0;
    PetriNet petri;
    cout << "Nhap bai can giai: ";
    do
    {
        cin >> t;
        if (t == 1)
        {
            petri.Exercise1();
        }
        else if (t == 2)
        {
            petri.Exercise2();
        }
        else if (t == 3)
        {
            petri.Exercise3();
        }
        else if (t == 4)
        {
            petri.Exercise4();
        }
        else
        {
            cout << "Ban da nhap nham, vui long nhap lai: ";
        }
    } while (t != 1 && t != 2 && t != 3 && t != 4);
    cout << endl;
    system("pause");
}