#include <iostream>
#include <cstdarg>

using namespace std;

void deleteSpace(int numStrings, ...);

int main() {
    setlocale(LC_ALL, "ru");

    char arr1[] = "jfghsdhf dof ighdoifg df oijfg idjf oigjdfo igj";
    char arr2[] = "lksaekfsdkmfk sdlk fskdf slkdf ;ks;dlf ksl;d kf";
    char arr3[] = "sdgsd flkjsd lkjfslkdj flkjsd kjlsdlk jflkjsd f";

    deleteSpace(3, arr1, arr2, arr3);
    deleteSpace(1, arr2);
    deleteSpace(2, arr1, arr3);

    return 0;
}

void deleteSpace(int numStrings, ...) {
    va_list args;
    va_start(args, numStrings);

    for (int i = 0; i < numStrings; i++) {
        char* str = va_arg(args, char*);
        for (int j = 0; str[j] != '\0'; j++) {
            if (str[j] != ' ') {
                cout << str[j];
            }
        }
        cout << endl;
    }

    va_end(args);
}
