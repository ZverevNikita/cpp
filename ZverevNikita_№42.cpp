#include <iostream>
#include <string>
#include <locale.h>
#include <windows.h>

using namespace std;

const int dotDuration = 100;
const int dashDuration = 3 * dotDuration;
const int pauseDuration = dotDuration;

void playDot()
{
    Beep(800, dotDuration);
    Sleep(pauseDuration);
}

void playDash()
{
    Beep(800, dashDuration);
    Sleep(pauseDuration);
}

string morseCode(char symbol)
{
    switch (tolower(symbol)) {
    case 'a': return ".-";
    case 'b': return "-...";
    case 'c': return "-.-.";
    case 'd': return "-..";
    case 'e': return ".";
    case 'f': return "..-.";
    case 'g': return "--.";
    case 'h': return "....";
    case 'i': return "..";
    case 'j': return ".---";
    case 'k': return "-.-";
    case 'l': return ".-..";
    case 'm': return "--";
    case 'n': return "-.";
    case 'o': return "---";
    case 'p': return ".--.";
    case 'q': return "--.-";
    case 'r': return ".-.";
    case 's': return "...";
    case 't': return "-";
    case 'u': return "..-";
    case 'v': return "...-";
    case 'w': return ".--";
    case 'x': return "-..-";
    case 'y': return "-.--";
    case 'z': return "--..";
    case 'а': return ".-";
    case 'б': return "-...";
    case 'в': return ".--";
    case 'г': return "--.";
    case 'д': return "-..";
    case 'е': return ".";
    case 'ж': return "...-";
    case 'з': return "--..";
    case 'и': return "..";
    case 'й': return ".---";
    case 'к': return "-.-";
    case 'л': return ".-..";
    case 'м': return "--";
    case 'н': return "-.";
    case 'о': return "---";
    case 'п': return ".--.";
    case 'р': return ".-.";
    case 'с': return "...";
    case 'т': return "-";
    case 'у': return "..-";
    case 'ф': return "..-.";
    case 'х': return "....";
    case 'ц': return "-.-.";
    case 'ч': return "---.";
    case 'ш': return "----";
    case 'щ': return "--.-";
    case 'ъ': return ".--.-.";
    case 'ы': return "-.--";
    case 'ь': return "-..-";
    case 'э': return "..-..";
    case 'ю': return "..--";
    case 'я': return ".-.-";
    case '0': return "-----";
    case '1': return ".----";
    case '2': return "..---";
    case '3': return "...--";
    case '4': return "....-";
    case '5': return ".....";
    case '6': return "-....";
    case '7': return "--...";
    case '8': return "---..";
    case '9': return "----.";
    case ' ': return "/";
    default: return "";
    }
}

void playMorse(const string& code)
{
    for (int i = 0; i < code.length(); i++) {
        switch (code[i]) {
        case '.':
            playDot();
            break;
        case '-':
            playDash();
            break;
        case '/':
            Sleep(2 * pauseDuration);  
            break;
        }
    }
}

string encrypt(string text)
{
    string morse = "";
    for (int i = 0; i < text.length(); i++) {
        morse += morseCode(tolower(text[i])) + " ";
    }
    return morse;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    string text;
    cout << "Введите текст: ";
    getline(cin, text);
    string morse = encrypt(text);
    cout << "Введённый текст, зашифрованный в азбуку Морзе: " << morse << endl;
    playMorse(morse);
}
