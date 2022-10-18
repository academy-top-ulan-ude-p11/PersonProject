#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

class Person
{
    string firstname;
    string lastname;
    string phone;
public:
    string& operator[](string prop)
    {
        if (prop == "firstname")
            return firstname;
        if (prop == "lastname")
            return lastname;
        if (prop == "phone")
            return phone;

        string snull = "";
        return snull;
    }
};

class Accumulator
{
    int value;
public:
    Accumulator(int sum = 0) : value{ sum } {}
    int Add(int sum)
    {
        this->value += sum;
        return this->value;
    }

    int operator()(int sum)
    {
        this->value += sum;
        return this->value;
    }
};

class Matrix
{
    int matrix[3][4];
public:
    int& operator()(int i, int j)
    {
        return matrix[i][j];
    }


};

class Gauss
{
public:
    int operator()(int n)
    {
        int result = 0;
        for (int i = 1; i <= n; i++)
            result += i;
        return result;
    }
};

class Employe
{
public:
    char name[50];
    int age;
    float salary;

    Employe()
    {
        strcpy(name, "");
        age = 0;
        salary = 0;
    }
    Employe(char* name, int age, float salary)
                        : age{ age }, salary{ salary }
    {
        strcpy(this->name, name);
    }

    friend bool operator<(Employe e1, Employe e2)
    {
        return e1.age < e2.age;
    }

    friend ostream& operator<<(ostream& out, const Employe e)
    {
        out << e.name << " [" << e.age << "] - " << e.salary;
        return out;
    }
};

class UserComparer
{
public:
    bool operator()(char* c1, char* c2)
    {
        return strcmp(c1, c2) < 0;
    }
    bool operator()(int n1, int n2)
    {
        return n1 < n2;
    }
    bool operator()(float n1, float n2)
    {
        return n1 < n2;
    }
};

void EmployeSort(Employe*& array, int size, UserComparer comparer)
{
    for (int i = 0; i < size; i++)
    {
        int min = i;
        for (int j = i; j < size; j++)
            if (comparer(array[j].salary, array[min].salary))
                min = j;
        Employe temp = array[i];
        array[i] = array[min];
        array[min] = temp;
    }
}

int Sum(int a, int b)
{
    return a + b;
}

int Mult(int a, int b)
{
    return a * b;
}

int Calc(int a, int b, int (*fptr)(int, int))
{
    return fptr(a, b);
}


int main()
{
    /*Person person;
    person["firstname"] = "Bob";
    person["lastname"] = "Smith";
    person["phone"] = "8-920-123-45-67";

    cout << person["firstname"] << " "
        << person["lastname"] << " "
        << person["phone"] << "\n";


    Accumulator acc(10);

    cout << acc(20);

    Matrix matrix;
    matrix(2, 3) = 100;

    Gauss gauss;
    cout << gauss(1000);*/


    Employe* employes = new Employe[5];
    strcpy(employes[0].name, "Sam");
    employes[0].age = 42;
    employes[0].salary = 45000;

    strcpy(employes[1].name, "Bob");
    employes[1].age = 21;
    employes[1].salary = 52000;

    strcpy(employes[2].name, "Joe");
    employes[2].age = 35;
    employes[2].salary = 61000;

    strcpy(employes[3].name, "Tim");
    employes[3].age = 29;
    employes[3].salary = 49000;

    strcpy(employes[4].name, "Leo");
    employes[4].age = 19;
    employes[4].salary = 47000;

    for (int i = 0; i < 5; i++)
        cout << employes[i] << "\n";
    cout << "\n";

    UserComparer comparer;
    EmployeSort(employes, 5, comparer);

    for (int i = 0; i < 5; i++)
        cout << employes[i] << "\n";
    cout << "\n";

    int (*fptr)(int, int);

    cout << Calc(10, 20, Mult) << "\n";
    cout << Calc(10, 20, Sum) << "\n";

    return 0;
}
