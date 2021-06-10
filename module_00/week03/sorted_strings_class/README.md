# Тренировочное задание по программированию: Отсортированные строки


Реализуйте класс, поддерживающий набор строк в отсортированном порядке. Класс должен содержать два публичных метода: 

```
private:
  // приватные поля
};
```

Пример

Код 

```
void PrintSortedStrings(SortedStrings& strings) {
  for (const string& s : strings.GetSortedStrings()) {
    cout << s << " ";
  }
  cout << endl;
}

int main() {
  SortedStrings strings;
  
  strings.AddString("first");
  strings.AddString("third");
  strings.AddString("second");
  PrintSortedStrings(strings);
  
  strings.AddString("second");
  PrintSortedStrings(strings);
  
  return 0;
}

```

output

```
first second third
first second second third


```