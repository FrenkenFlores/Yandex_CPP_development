Указание
Один из способов проверки того, являются ли слова анаграммами друг друга, заключается в следующем. Для каждого слова с помощью словаря подсчитаем, сколько раз в нём встречается каждая буква. Если для обоих слов эти словари равны (а это проверяется с помощью обычного оператора ==), то слова являются анаграммами друг друга, в противном случае не являются.

При этом построение такого словаря по слову удобно вынести в отдельную функцию BuildCharCounters.

Формат ввода
Сначала дано число пар слов N, затем в N строках содержатся пары слов, которые необходимо проверить. Гарантируется, что все слова состоят лишь из строчных латинских букв.

Формат вывода
Выведите N строк: для каждой введённой пары слов YES, если эти слова являются анаграммами, и NO в противном случае.

Ввод
3
eat tea
find search
master stream

Вывод
YES
NO
YES


