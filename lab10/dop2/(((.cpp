#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_COUNTRIES = 100;

bool canAddToGroup(int country, int group, int adjacencyMatrix[MAX_COUNTRIES][MAX_COUNTRIES], int groups[MAX_COUNTRIES]) {
    for (int i = 0; i < MAX_COUNTRIES; ++i) {
        if (adjacencyMatrix[country][i] && groups[i] == group) {
            return false;
        }
    }
    return true;
}

void divideIntoTwoGroupsRecursive(int adjacencyMatrix[MAX_COUNTRIES][MAX_COUNTRIES], int groups[MAX_COUNTRIES], int country, int group, int& minCrossGroupPairs, int countries) {
    if (country == countries) {
        int crossGroupPairs = 0;
        for (int i = 0; i < countries; ++i) {
            for (int j = i + 1; j < countries; ++j) {
                if (adjacencyMatrix[i][j] && groups[i] != groups[j]) {
                    ++crossGroupPairs;
                }
            }
        }
        minCrossGroupPairs = min(minCrossGroupPairs, crossGroupPairs);
        return;
    }

    if (canAddToGroup(country, 1, adjacencyMatrix, groups)) {
        groups[country] = group;
        divideIntoTwoGroupsRecursive(adjacencyMatrix, groups, country + 1, 1, minCrossGroupPairs, countries);
        groups[country] = 0;
    }

    if (canAddToGroup(country, 2, adjacencyMatrix, groups)) {
        groups[country] = group;
        divideIntoTwoGroupsRecursive(adjacencyMatrix, groups, country + 1, 2, minCrossGroupPairs, countries);
        groups[country] = 0;
    }
}
// это написано не мной, смотрите сами(не вижу смысла разбирать матрицы смежности не зна€ дискретной математики)
int main() {
    setlocale(LC_ALL, "ru");

    int adjacencyMatrix[MAX_COUNTRIES][MAX_COUNTRIES] = {};
    int groups[MAX_COUNTRIES] = {};

    int countries;
    cout << "¬ведите количество стран: ";
    cin >> countries;

    if (countries <= 0 || countries > MAX_COUNTRIES) {
        cout << "Ќекорректное количество стран." << endl;
        return 1;
    }

    cout << "¬ведите матрицу смежности дл€ стран:" << endl;
    for (int i = 0; i < countries; ++i) {
        for (int j = 0; j < countries; ++j) {
            cin >> adjacencyMatrix[i][j];
        }
    }

    int minCrossGroupPairs = countries * (countries - 1) / 2;

    divideIntoTwoGroupsRecursive(adjacencyMatrix, groups, 0, 0, minCrossGroupPairs, countries);

    cout << "ћинимальное количество пар смежных стран из разных групп: " << minCrossGroupPairs << endl;

    return 0;
}
