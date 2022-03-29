#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

enum Spec { CS, IT, ME, PhIT, TR };

string strSpec[] = { "Комп'ютернi науки", "Iнформатика", "Математика та економiка", "Фiзика та iнформатика", "Трудове навчання" };

struct Student {
    string prizv;
    int kurs;
    Spec spec;
    int physics;
    int math;
    int informatik;
};

void create(Student* s, int N) 
{
    int sp;
    for (int i = 0; i < N; i++) 
    {
        cout << "Прiзвище: ";
        cin >> s[i].prizv;
        cout << "Курс: ";
        cin >> s[i].kurs;
        cout << "Спецiальнiсть (0 - Комп'ютернi науки, 1 - Iнформатика, 2 - Математика та економiка, 3 - Фiзика та iнформатика, Трудове навчання) ";
        cin >> sp;
        s[i].spec = (Spec)sp;
        cout << "Оцiнка з фiзики: ";
        cin >> s[i].physics;
        cout << "Оцiнка з математики: ";
        cin >> s[i].math;
        cout << "Оцiнка з iнформатики: ";
        cin >> s[i].informatik;
        
    }
}
void print(Student* s, int amSt)
{
    cout << "=========================================================================================================================="
        << endl;
    cout << "| № |    Прiзвище   | Курс |      Спецiальнiсть     | Фiзика |  Математика |  Iнформатика |"
        << endl;
    cout << "--------------------------------------------------------------------------------------------------------------------------"
        << endl;
    for (int i = 0; i < amSt; i++) {

        cout << "| " << setw(2) << right << i + 1 << "";
        cout << "| " << setw(14) << left << s[i].prizv
            << "| " << setw(5) << right << s[i].kurs
            << "| " << setw(23) << left << strSpec[s[i].spec]
            << "| " << setw(7) << s[i].physics
            << "| " << setw(11) << right << s[i].math
            << "| " << setw(11) << right << s[i].informatik
            << "| ";
        cout << endl;
    }
    cout << "--------------------------------------------------------------------------------------------------------------------------"
        << endl;
}
double ProsPhysik(Student* s, int N)
{
    int k = 0;
    for (int i = 0; i < N; i++)
    {
        if (s[i].physics == 5)
        {
            k++;
        }
    }
    return 100.0 * k / N * 1.;

}
int AllFive(Student* s, int N) {
    int count = 0;
    for (int i = 0; i < N; i++) {
        if (s[i].physics == 5 && s[i].math == 5 && s[i].informatik)
        {
            count += 1;
        }
    }
    return count;
}


int main() {
    setlocale(LC_ALL, "Ukrainian");
    int N;
    cout << "Кiлькiсть студентiв: ";
    cin >> N;
    Student* s = new Student[N];
    create(s, N);
    print(s, N);

    cout << "Kiлькiсть студентiв, якi вчаться на <5>: " << AllFive(s, N) << endl;
    cout << "Вiдсоток студентiв , в яких з фiзики  <5>: " << ProsPhysik(s, N) << endl;

    return 0;

}
