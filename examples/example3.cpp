#include <iostream>
#include "bstree.cpp"

using namespace std;
using namespace BSTree;

void menu(Tree *&tree) {
  int ch;
  char ch_2;
  string s;
  do {
    cout << " " << endl;
    cout << "1. Вывести дерево на экран" << endl;
    cout << "2. Вывести список узлов дерева" << endl;
    cout << "3. Добавить узел в дерево" << endl;
    cout << "4. Удалить узел из дерева" << endl;
    cout << "5. Сохранить дерево в файл" << endl;
    cout << "6. Загрузить дерево из файла" << endl;
    cout << "7. Проверить наличие узла" << endl;
    cout << "8. Завершить работу программы" << endl;

    cin >> ch;
    switch (ch) {
      case 1: {
        tree->show();
        break;
      }
      case 2:
        if (!(tree->zero())) {
          cout << "a.Прямой обход" << endl;
          cout << "b.Поперечный обход" << endl;
          cout << "c.Обратный обход" << endl;
          cin >> ch_2;
          switch (ch_2) {
            case 'b':
              tree->InOrder();
              cout << endl;
              break;
            case 'a':
              tree->PreOrder();
              cout << endl;
              break;
            case 'c':
              tree->PostOrder();
              cout << endl;
              break;
          }
          break;
        } else
          cout << "nothing to show" << endl;
        break;

      case 8: {
        cout << "Вы хотите выйти из программы ? (Да|Нет):" << endl;
        cin >> s;
        if (s == "yes" || s == "YES" || s == "Yes" || s == "Y" || s == "y")
          cout << "Всего доброго!" << endl;
        break;
      }
    }
  } while (s != "yes" && s != "YES" && s != "Да" && s != "Yes" && s != "Y" &&
           s != "y");
}
int main(int argc, char *argv[]) {
  Tree *tree = new Tree;
  for (int i = 1; i < argc; i++) {
    tree->insert(atoi(argv[i]));
  };
  menu(tree);
  delete tree;
}
