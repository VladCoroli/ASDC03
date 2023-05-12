#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;


class HOSPITAL
{
public:
    int id; // айди больницы
    char name[70]; // название больницы
    int price; // стоимость первчиного обследования больницы
    int number_of_floor; // количесво этажей больницы
    int capacity; // вместимость больницы
    void display() {
            cout << id << "/" << name << "/" << price << "/" << number_of_floor << "/" << capacity << endl;
        }
};

void getHospitalFromFile(ifstream& in, HOSPITAL& n) {
    char delimiter;
    in >> n.id;
    in >> delimiter;
    in >> n.name;
    in >> delimiter;
    in >> n.price;
    in >> delimiter;
    in >> n.number_of_floor;
    in >> delimiter;
    in >> n.capacity;
    in >> delimiter;
}

struct BinTree {
    int value; //содержит значение
    BinTree* left;//адрес левого поддерева
    BinTree* right;//адрес правого поддерева
};

void newBinTree(int val, BinTree** Tree) {
    if ((*Tree) == NULL)
    {
        (*Tree) = new BinTree; //Выделить память
        (*Tree)->value = val;  //Поместить в выделенное место аргумент
        (*Tree)->left = (*Tree)->right = NULL;
    }
    if (val > (*Tree)->value) newBinTree(val, &(*Tree)->right);//Если аргумент больше чем текущий элемент, поместить его вправо
    else if (val < (*Tree)->value) newBinTree(val, &(*Tree)->left);//Иначе поместить его влево
}

int Search(BinTree* Tree, int key) {
    if (Tree == NULL) return NULL;
    if (Tree->value == key) return Tree->value;
    if (key < Tree->value) return Search(Tree->left, key);
    else
        return Search(Tree->right, key);
}







int main() {
    setlocale(LC_ALL, "rus");
    const int NM = 50;
    HOSPITAL* hospitals = new HOSPITAL[50];

    const string fileName = "D:\\vova1.txt";
    ifstream inputFile(fileName);

    if (!inputFile.fail()) {
        int i = 0;
        while (!inputFile.eof())
            getHospitalFromFile(inputFile, hospitals[i++]);
        inputFile.close();
    }
    else
        cout << "File not found" << endl;

    for (int i = 0; i < NM; i++) {
        cout << hospitals[i].id << "/" << hospitals[i].name << "/" << hospitals[i].price << "/" << hospitals[i].number_of_floor << "/" << hospitals[i].capacity << endl;
    }

    /*int result_3;
    cout << "\n\nTreeSearch" << endl;
    cout << "Enter element search -> ";

    BinTree* Tree = NULL;

    for (int i = 0; i < 50; i++) {
        newBinTree(hospitals[i].capacity, &Tree);
    }

    
    int key;

    cout << "Enter value for search -> ";
    cin >> key;
    int result_4 = Search(Tree, key);
    if (result_4 == NULL)
        cout << "Element is not found";
    else
        cout << "Your element is->" << endl;
    for (int i = 0; i < 50; i++) {
        if (result_4 == hospitals[i].capacity) {
            hospitals[i].display();
        }
    }*/

     /*cout << "-------------------------POSLEDOVATELINII POISK--------------------------" << endl;
   bool flag = false;
   int var1;
   int capacity_value;

   cout << "Enter the capacity value " << endl;
   cin >> capacity_value;

   for (int i = 0; i < NM; i++) {
       if (hospitals[i].capacity == capacity_value) {
           flag = true;
           var1 = hospitals[i].id;
       }
   }

   if (flag) {
       cout << "Hospital number " << var1 << " has the capacity " << capacity_value << endl;
   }
   else {
       cout << "There are no hospitals with this capacity" << endl;
   }*/
    
}