#include <iostream>
#include <string>

/*задание 1*/

std::string sortletters(const std::string& str) {
    std::string sortedStr = str;

    // Удаление пробелов
    size_t spacePos = sortedStr.find(' '); /*функция которая ищет пробел*/
    while (spacePos != std::string::npos) { /* цикл проверки вводимых значений на начличие пробелов*/
        sortedStr.erase(spacePos, 1); /*удаляет элемент, на который указывает итератор в скобках.*/
        spacePos = sortedStr.find(' ');
    }

    // Удаление пунктуационных знаков
    std::string punctuations = ".,?!:;\"'-"; /*знаки пунктакционные*/
    for (char punctuation : punctuations) { /*ищет среди чаровских введенных значений те, что были указаны выше*/
        size_t punctuationPos = sortedStr.find(punctuation); /*тут уже непосредственно сама функция find*/
        while (punctuationPos != std::string::npos) { /*прогоняет каждый раз цикл пока не найдет все знаки*/
            sortedStr.erase(punctuationPos, 1); /*убирает их*/
            punctuationPos = sortedStr.find(punctuation); 
        }
    }

    // Сортировка букв в алфавитном порядке
    for (size_t i = 0; i < sortedStr.length(); i++) {
        for (size_t j = i + 1; j < sortedStr.length(); j++) {
            if (std::tolower(sortedStr[i]) > std::tolower(sortedStr[j])) {
                char temp = sortedStr[i];
                sortedStr[i] = sortedStr[j];
                sortedStr[j] = temp;
            }
        }
    }

    return sortedStr;
}

int main() {
    setlocale(LC_ALL, "Rus"); /* чтобы русский язык работал в консоли*/
    std::string input;
    std::cout << "vvedite stroku: ";
    std::getline(std::cin, input);

    std::string sortedString = sortletters(input);

    std::cout << "gotovaya stroka: " << sortedString << std::endl;

    return 0;
}

/*не знаю почему не работает setlocale. вроде бы в онлайн компиляторе работает, поэтому пишу латиницей по-русски*/
