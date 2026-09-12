#pragma once

#include <map>
#include <string>
#include <iostream>
#include <variant>
#include <vector>

class Multiset;

using Element = std::variant<std::string, Multiset>;

/**
 * @brief Класс «Неориентированное мультимножество».
 * 
 * Хранит элементы с повторениями. Элементы могут быть строками
 * или вложенными мультимножествами.
 */
class Multiset {
private:
    std::map<Element, int> data;

public:
    /**
     * @brief Конструктор по умолчанию.
     * 
     * Создаёт пустое мультимножество.
     */
    Multiset();

    /**
     * @brief Конструктор от строки.
     * @param str Строка вида {a, a, b, {c, d}}.
     */
    Multiset(const std::string& str);

    /**
     * @brief Конструктор копирования.
     * @param other Другое мультимножество для копирования.
     */
    Multiset(const Multiset& other);

    /**
     * @brief Оператор присваивания копированием.
     * @param other Другое мультимножество.
     * @return Ссылка на текущий объект.
     */
    Multiset& operator=(const Multiset& other);

    /**
     * @brief Деструктор.
     */
    ~Multiset();

    /**
     * @brief Парсит строку и заполняет мультимножество.
     * @param str Строка вида {a, a, b}.
     */
    void fromString(const std::string& str);

    /**
     * @brief Оператор сравнения на равенство.
     * @param other Другое мультимножество.
     * @return true, если мультимножества равны.
     */
    bool operator==(const Multiset& other) const;

    /**
     * @brief Оператор сравнения на неравенство.
     * @param other Другое мультимножество.
     * @return true, если мультимножества не равны.
     */
    bool operator!=(const Multiset& other) const;

    /**
     * @brief Оператор «меньше».
     * @param other Другое мультимножество.
     * @return true, если текущее меньше.
     */
    bool operator<(const Multiset& other) const;

    /**
     * @brief Оператор «больше».
     * @param other Другое мультимножество.
     * @return true, если текущее больше.
     */
    bool operator>(const Multiset& other) const;

    /**
     * @brief Оператор «меньше или равно».
     * @param other Другое мультимножество.
     * @return true, если текущее меньше или равно.
     */
    bool operator<=(const Multiset& other) const;

    /**
     * @brief Оператор «больше или равно».
     * @param other Другое мультимножество.
     * @return true, если текущее больше или равно.
     */
    bool operator>=(const Multiset& other) const;

    /**
     * @brief Оператор чтения из потока.
     * @param is Поток ввода.
     * @param m Мультимножество для чтения.
     * @return Ссылка на поток.
     */
    friend std::istream& operator>>(std::istream& is, Multiset& m);

    /**
     * @brief Оператор записи в поток.
     * @param os Поток вывода.
     * @param m Мультимножество для записи.
     * @return Ссылка на поток.
     */
    friend std::ostream& operator<<(std::ostream& os, const Multiset& m);

    /**
     * @brief Добавляет элемент в мультимножество.
     * @param element Элемент (строка или вложенное мультимножество).
     */
    void add(const Element& element);

    /**
     * @brief Удаляет один экземпляр строки.
     * @param element Строка для удаления.
     */
    void remove(const std::string& element);

    /**
     * @brief Удаляет count экземпляров строки.
     * @param element Строка для удаления.
     * @param count Сколько экземпляров удалить.
     */
    void remove(const std::string& element, int count);

    /**
     * @brief Удаляет один экземпляр вложенного мультимножества.
     * @param element Вложенное мультимножество для удаления.
     */
    void remove(const Multiset& element);

    /**
     * @brief Количество уникальных элементов.
     * @return Число уникальных элементов.
     */
    int uniqueElementsCount() const;

    /**
     * @brief Общее количество элементов (с повторениями).
     * @return Общее количество.
     */
    int size() const;

    /**
     * @brief Количество вхождений строки.
     * @param element Строка.
     * @return Сколько раз встречается.
     */
    int count(const std::string& element) const;

    /**
     * @brief Количество вхождений вложенного мультимножества.
     * @param element Вложенное мультимножество.
     * @return Сколько раз встречается.
     */
    int count(const Multiset& element) const;

    /**
     * @brief Проверяет наличие строки.
     * @param element Строка.
     * @return true, если есть.
     */
    bool contains(const std::string& element) const;

    /**
     * @brief Проверяет наличие вложенного мультимножества.
     * @param element Вложенное мультимножество.
     * @return true, если есть.
     */
    bool contains(const Multiset& element) const;

    /**
     * @brief Строковое представление мультимножества.
     * @return Строка вида {a:2, b:1}.
     */
    std::string check() const;
};