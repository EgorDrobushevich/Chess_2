# Шахматы - приложение (мини игра)

## Об игре
Игровое издание классических шахмат. В данной приложении вам будет представлена возможность открыть небольшое поле и сразиться со своими друзьями в честном поединке черных и белых фигур. Данный продукт представляется исключительно в тестовом варианте и не несет в себе конечную коммерческую продукцию для выхода на рынок.

## Игровой процесс
При запуске приложения вам будет отображено шахматное поле. По умолчанию игровой ход начинается за белые фигуры. Для того чтобы осуществить ход, необходимо:
1) выбрать фигуру своего цвета (путем нажатия на нее правой левой мыши)
2) выбрать клетку для хода (путем нажатия на нее левой кнопкой мыши)
3) завершить ход (путем нажатия на кнопку "подтвердить ход" внизу интерфейса левой кнопкой мыши);
После обработки данных ввода пользователя, система подтвердит ход путем смены цвета играющих фигур или сброса вводимых данных в случае ошибочного ввода.

## Структура программа
Данное приложение использовало библиотеку "ultralight" - https://github.com/ultralight-ux/ultralight. Структура данного приложения соответствует модульному программированию. 
![Структура проекта](https://github.com/EgorDrobushevich/Chess_2/blob/main/media/structure.png)
При проектировании игрового интерфейса были применены HTML CSS JS, что является ключевой особенностью библиотеки ultralight. Для связи двух языков сред, был спроектирован мост. Все данные при транспортировки конвертируются в массив для исключения возможных неполадок преобразований типов js в типы с++. После поступления данных в игровую логическую среду, их дальнейшую обработку осуществляет проверочный модуль, с предварительной конвертацией массива в другие типы. После обработки данные поступают и перерисовываются на интерфейсе.

## Другие сведения
Данный проект был написан группой студентов Белорусского Государственного Технологического Университета - https://www.belstu.by .
Общее затраченное время (примерного вычисления) полтора дня.
Дальнейшие подробности изложены в документации нашего проекта на сайте - https://github.com/EgorDrobushevich/Chess_2/tree/main/game-introduction-site .
