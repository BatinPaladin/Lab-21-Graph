#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

vector<vector<int>> matrix = { {-1, 12, 18, 5, 0, 34},
                               {12, -1, 16, 0, 53, 45},
                               {18, 16, -1, 3, 21, 0},
                               {5, 0, 3, -1, 0, 0},
                               {0, 53, 21, 0, -1, 0},
                               {34, 45, 0, 0, 0, -1} };

struct Edge {
    int from;
    int to;
};

void change_map() {

}

void show_map() {
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            if (matrix[i][j] == -1) {
                cout << "   ";
            }
            else if (matrix[i][j] < 10) {
                cout << "  " << matrix[i][j];
            }
            else {
                cout << " " << matrix[i][j];
            }
        }
        cout << endl;
    }
}

int main()
{
    system("chcp 1251");
    int markup[6] = { 1000, 1000, 1000, 1000, 1000, 1000 };
    bool flag[6] = { 0, 0, 0, 0, 0, 0 };
    int from, to, min_index = 1000;
    cout << "\nТаблица графа:\n";
    show_map();
    cout << "\nНайти оптимальный путь:\n\nОт города ";
    do {
        cin >> from;
        if (from > 6 || from < 1) {
            cout << "\n1 <= Номер города <=6\n";
        }
    } while (from > 6 || from < 1);
    cout << "\nДо города ";
    do {
        cin >> to;
        if (to > 6 || to < 1) {
            cout << "\n1 <= Номер города <=6\n";
        }
    } while (to > 6 || to < 1);
    markup[from - 1] = 0;
    do
    {
        min_index = 1000;
        int min = 1000;
        for (int i = 0; i < 6; i++)
        {
            if (flag[i] == 0 && markup[i] < min)
            {
                min = markup[i];
                min_index = i;
            }
        }
        if (min_index != 1000)
        {
            for (int i = 0; i < 6; i++)
            {
                if (matrix[min_index][i] > 0)
                {
                    int temp = min + matrix[min_index][i];
                    if (temp < markup[i])
                    {
                        markup[i] = temp;
                    }
                }
            }
            flag[min_index] = 1;
        }
    } while (min_index < 1000);
    queue<int> Queue;
    stack<Edge> Edges;
    Edge edge;
    int visit[6] = { 0, 0, 0, 0, 0, 0 };
    Queue.push(from);
    while (!Queue.empty()) {
        int node = Queue.front();
        Queue.pop();
        flag[node - 1] = 2;
        for (int i = 0; i < 6; i++) {
            if (matrix[node - 1][i] > 0 && visit[i] == 0) {
                Queue.push(i + 1);
                visit[i] = 1;
                edge.from = node;
                edge.to = i + 1;
                Edges.push(edge);
                if (node == to)
                {
                    break;
                }
            }
        }
    }
    if (Edges.empty() == 0 && (markup[to - 1] < 1 || markup[to - 1] == 1000)) {
        cout << "\nНеудалось найти оптимальный путь для заданного маршрута!\n";
    }
    else {
        cout << "\nРазмер оптимального пути = " << markup[to - 1] << endl;
        cout << "\nОптимальный путь: \n";
        cout << to;
        while (!Edges.empty()) {
            edge = Edges.top();
            Edges.pop();
            if (edge.to == to) {
                to = edge.from;
                cout << " <- " << to;
            }
        }
        cout << endl;
    }
    system("pause");
}