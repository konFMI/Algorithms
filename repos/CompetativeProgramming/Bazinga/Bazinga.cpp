// Bazinga.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <unordered_map>
#include <string>

int main()
{
    std::string banner;

    std::getline(std::cin,banner);
    std::unordered_map<char, int> letters = {
        std::pair<char,int>('b',0),
        std::pair<char,int>('a',0),
        std::pair<char,int>('z',0),
        std::pair<char,int>('i',0),
        std::pair<char,int>('n',0),
        std::pair<char,int>('g',0),
        std::pair<char,int>('a',0)
    };
    
    char letter = ' ';
    for (size_t i = 0; i < banner.length(); i++)
    {
        letter = tolower(banner[i]);
        if (letter == 'b' || letter == 'a' || letter == 'z' || letter == 'i' || letter == 'n' || letter == 'g' || letter == 'a')
        {
            letters[letter]++;
        }
    }

    letters['a'] = letters['a'] / 2;

    int minRepeatedLetter = INT_MAX;
    for (auto letter : letters)
    {
        if (letter.second < minRepeatedLetter)
        {
            minRepeatedLetter = letter.second;
        }
    }

    std::cout << minRepeatedLetter;

    return 0;
}

// Ели започна работа като стажант в Българската Академия за Изследване на Генната Архитектура(накратко БАЗИНГА).
// Първата работа, която й възложиха, беше да популяризира академията като разлепи рекламни банери, изписващи "BAZINGA" из целия град.
// За целта са ѝ предоставили голям стар банер, от които тя може да вземе някои(потенциално всички) букви.
// По даден изписания текст на стария банер, помогнете на Ели да определи колко най - много нови такива с думата "BAZINGA" могат да бъдат направени.
// Всяка от буквите може да бъде изписана както главна, така и малка, тоест някои от валидните начини за изписване са например "BAZINGA", "bazinga", "BaZiNGa" и т.н.
// 
// Вход
// На единствен ред на стандартния вход ще бъде зададен текстът T на стария банер, който Ели може да преизползва.Той ще е с дължина до 1000 символа и може да съдържа главни и малки латински букви, цифри, шпации и препинателните знаци ‘.’, ‘, ’, ‘ ? ’, ‘!’.
// 
// Изход
// На стандартния изход изведете едно цяло число – броя банери, които може да направи Ели от наличните букви.
