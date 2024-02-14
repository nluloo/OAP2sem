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
    int rec = 0;
    int ret = 0;

    for (int i = 0; i < numStrings; i++) {
        ret = 0;
        char* str = va_arg(args, char*);
        for (int j = 0; str[j] != '\0'; j++) {
            rec++;
            if (str[j] == ' ') {
                rec--;
                if(rec > ret)
                ret = rec;
                rec = 0;
            }
        }
        rec = 0;
        cout << ret << endl;
    }

    va_end(args);
}
