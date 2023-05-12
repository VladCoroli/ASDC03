#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

#define min(a,b) a<b?a:b

struct HOSPITAL
{
    int id; // айди больницы
    char name[70]; // название больницы
    int price; // стоимость первичного обследования
    int number_of_floor; // количество этажей
    int capacity; // вместимость 
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


int main() {
    const int NM = 50;
    HOSPITAL*hospitals = new HOSPITAL[50];

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

    /*cout << "-------------------------POSLEDOVATELINII POISK--------------------------" << endl;
    bool flag = false;
    int var1;
    int price_value;

    cout << "Enter the price value " << endl;
    cin >> price_value;

    for (int i = 0; i < NM; i++) {
        if (hospitals[i].price == price_value) {
            flag = true;
            var1 = i;
        }
    }

    if (flag) {
        cout << "Hospital number " << var1 << " has the price " << price_value << endl;
    }
    else {
        cout << "There are no hospitals with this price" << endl;
    }*/

    //cout << "---------------------------BINARNII POISK----------------------------------------" << endl;
    //int price_value;
    //int search = -1; // (элемент не найден)

    //int left = 0; // задаем левую и правую границы
    //int right = 50;


    //cout << "Enter the price value " << endl;
    //cin >> price_value;

    //while (left <= right) { // пока левая граница не "перескочит" правую
    //    int mid = (left + right) / 2; // ищем середину отрезка
    //    if (price_value == hospitals[mid].price) { // если ключевое поле равно искомому
    //        search = mid; // мы нашли требуемый элемент
    //        break; // выходим из цикла
    //    }
    //    if (price_value < hospitals[mid].price) // если искомое ключевое поле меньше найденной середины
    //        right = mid - 1; // смещаем правую границу, продолжим поиск в левой части
    //    else // иначе
    //        left = mid + 1; // смещаем левую границу, продолжим поиск в правой части
    //}

    //if (search == -1) {
    //    cout << "There are no hospitals with this price" << endl;
    //}
    //else
    //   cout << "Hospital number " << search << " has the price " << price_value << endl;

    //cout << "---------------------POISK INTERPOLEATIEII-----------------------" << endl;

    //int x = 0; // текущая позиция массива, с которым сравнивается искомое
    //int a = 0; // левая граница области, где ведется поиск
    //int b = 50; // правая граница области, где ведется поиск
    //bool flag; // флаг, если переменная найдена

    //int price_value; // искомое значение
    //cout << "Enter the price value " << endl;
    //cin >> price_value;


    //// цикл поиска по массиву, пока искомое не найдено
    //// или пределы поиска еще не существуют
    //for (flag = false; (hospitals[a].price < price_value) && (hospitals[b].price > price_value) && !flag; ) {
    //// вычисление интерполяцией след элемента, который будет сравниваться с искомым
    //    x = a + ((price_value - hospitals[a].price) * (b - a)) / (hospitals[b].price - hospitals[a].price);
    //    // получение новых границ области, если искомое не найдено
    //    if (hospitals[x].price < price_value)
    //        a = x + 1;
    //    else if (hospitals[x].price > price_value)
    //        b = x - 1;
    //    else
    //        flag = true;
    //}


    //if (hospitals[a].price == price_value)
    //    cout << price_value << " founded in hospital " << a << endl;
    //else if (hospitals[b].price == price_value)
    //    cout << price_value << " founded in hospital " << b << endl;
    //else
    //    cout << "No hospitals with this price" << endl;


    //cout << "---------------FIBONACI---------------------" << endl;
    //int i;
    //// инициализация чисел Фибаначи
    //int a = 0;
    //int b = 1;
    //int c = a + b;
    //int n = 49;
    //int price_value;

    //cout << "Enter the price value " << endl;
    //cin >> price_value;

    //while (c < n) {
    //    a = b;
    //    b = c;
    //    c = a + b;
    //}
    //// отмечаем исключенный диапазон спереди
    //int offset = -1;
    //while (c > 1) {
    //    i = min(offset + a, n - 1);
    //    if (hospitals[i].price < price_value) {
    //        c = b;
    //        b = a;
    //        a = c - b;
    //        offset = i;
    //    }
    //    else if (hospitals[i].price > price_value) {
    //        c = a;
    //        b = b - a;
    //        a = c - b;
    //    }
    //    else {
    //        cout << "price " << price_value << " is found at index " << i;
    //        break;
    //    }
    //}
    
}



