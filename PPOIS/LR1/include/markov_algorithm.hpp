#pragma once

#include <string>
#include <vector>
#include <iostream>

/**
 * @brief Одно правило подстановки для нормального алгорифма Маркова.
 * 
 * Хранит левую часть (что искать), правую часть (на что менять)
 * и флаг финальности (стоп-правило или нет).
 */
class Rule {
private:
    std::string left;
    std::string right;
    bool isFinal;

public:
    /**
     * @brief Конструктор правила.
     * @param left Левая часть (что искать).
     * @param right Правая часть (на что менять).
     * @param isFinal Является ли правило финальным.
     */
    Rule(const std::string& left, const std::string& right, bool isFinal);

    /**
     * @brief Возвращает левую часть правила.
     * @return Левая часть.
     */
    std::string getLeft() const;

    /**
     * @brief Возвращает правую часть правила.
     * @return Правая часть.
     */
    std::string getRight() const;

    /**
     * @brief Проверяет, является ли правило финальным.
     * @return true, если правило финальное.
     */
    bool isFinalRule() const;

    /**
     * @brief Возвращает строковое представление правила.
     * @return Строка вида "ab -> c" или "bc -> .".
     */
    std::string toString() const;
};

/**
 * @brief Класс, реализующий нормальный алгорифм Маркова.
 * 
 * Хранит список правил подстановки и умеет применять их к строке.
 */
class MarkovAlgorithm {
private:
    std::vector<Rule> rules;

public:
    /**
     * @brief Конструктор по умолчанию.
     * 
     * Создаёт алгоритм без правил.
     */
    MarkovAlgorithm();

    /**
     * @brief Добавляет правило из строки.
     * @param ruleStr Строка вида "ab -> c" или "bc -> .".
     */
    void addRule(const std::string& ruleStr);

    /**
     * @brief Удаляет все правила.
     */
    void clear();

    /**
     * @brief Применяет алгоритм к строке.
     * @param input Входная строка.
     * @return Результат применения алгоритма.
     */
    std::string apply(const std::string& input) const;

    /**
     * @brief Возвращает количество правил.
     * @return Число правил.
     */
    int ruleCount() const;

    /**
     * @brief Оператор вывода в поток.
     * @param os Поток вывода.
     * @param ma Алгоритм для вывода.
     * @return Ссылка на поток.
     */
    friend std::ostream& operator<<(std::ostream& os, const MarkovAlgorithm& ma);
};