/**

Задача:


Необходимо написать программу на C++
с использованием Qt, которая в окне
показывает симуляцию движения N шариков.
Шарики притягиваются друг к другу с силой:
F(r) = 1/r - 1/r^2
(http://www.wolframalpha.com/input/?i=1%2Fr+-+1%2Fr%5E2),
где r – расстояние между шариками.
Начальное положение шариков – случайное.
В процессе работы шары можно перетаскивать мышкой,
лопать (если попал по шарику) и
добавлять (если попал в пустое место)
второй кнопкой мыши.

Все вычисления нужно производить
в отдельном потоке,
основной поток Qt должен заниматься
только отрисовкой и взаимодействием
с пользователем.
Взаимодействие между потоками должно быть
сделано аккуратно и корректно.
Анимация должна быть плавной.
В потоке, производящем вычисления,
Qt не использовать.
Вместе с программой должны быть
сделаны юнит-тесты, подтверждающие
корректность работы программы.
Для юнит-тестов желательно использовать
Google Test
(https://github.com/google/googletest).
*/

#include "mainwindow.h"
#include <QApplication>
#include <QTime>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}