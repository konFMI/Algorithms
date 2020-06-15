﻿// ShoesEasy.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include <algorithm>
int main()
{
    int numberOfRatings = 0, kThValue = 0;
    std::cin >> numberOfRatings >> kThValue;

    int* values = new int[numberOfRatings];

    int value = 0;
    for (size_t i = 0; i < numberOfRatings; i++)
    {
        std::cin >> value;
        values[i] = value;
    }

    std::sort(values, values + numberOfRatings);

    for (size_t i = 0; i < numberOfRatings; i++)
    {
        std::cout << std::setw(3) << values[i];
    }

    std::cout << values[kThValue];
    delete[] values;
}

// Много цивилизации са се сблъсквали с така наречения “обувчен проблем”* .
// И докато хората на планетата Земя още не са проклели нозете си и не са започнала да летят, обувките си остават сериозен проблем(поне в средите на Елеонора).
// Както всеки от вас сигурно знае, крайно недопустимо e две(или повече) момичета в училище да ходят с еднакви дрехи, прически или обувки.
// За това намирането на съответните аксесоари изобщо не е толкова лесна задача – ако Ели определи някакъв коефициент
// колко й харесва даден чифт обувки(висок ток, по възможност дънките да могат да влязат вътре и т.н.), то не винаги е изгодно 
// за нея да вземе тези с най - високата стойност(например ако някое момиче в училището й вече си е взела същия модел).
// За това тя би желала да знае при разходката си по
// моловете не задължително стойността на най - хубавите обувки, а стойността на k - тия по оценка чифт.
// 
// Вход: На първия ред на стандартния вход ще бъде зададен броят обиколки по магазините на Ели – цялото число Т.
// Следващите Т теста ще се състоят от по два реда.Първият от тях ще съдържа числата N и K – колко чифта обувки е оценила Ели
// и коя по ред стойност иска да знае тя(1 ≤ K ≤ N ≤ 1000).На следващия ред ще има N цели числа Ai, задаващи оценките на харесаните от нея ботушки(0 ≤ Ai ≤ 1, 000).
// 
// Изход : За всеки тест на стандартния изход изведете на отделен ред по едно число – стойността на k - тите по хубост обувки.

