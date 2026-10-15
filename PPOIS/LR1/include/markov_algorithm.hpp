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
 * @brief Лента абстрактной машины.
 *
 * Хранит текущую строку (состояние ленты) и умеет её менять,
 * загружать из потока и выводить.
 */
class Tape {
private:
    std::string content;

public:
    Tape();
    explicit Tape(const std::string& initial);

    void setContent(const std::string& str);
    const std::string& getContent() const;

    // Загрузка состояния ленты из потока (одна строка)
    void loadFromStream(std::istream& is);

    friend std::ostream& operator<<(std::ostream& os, const Tape& t);
};

/**
 * @brief Класс, реализующий нормальный алгорифм Маркова.
 * 
 * Хранит список правил подстановки и умеет применять их к строке.
 */
class MarkovAlgorithm {
private:
    std::vector<Rule> rules;
    Tape tape;
    bool logMode = false;

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
     * @brief Устанавливает начальное состояние ленты.
     * @param input Строка, которой будет инициализирована лента.
     */
    void setInput(const std::string& input);

    /**
     * @brief Возвращает текущее содержимое ленты.
     */
    const std::string& getTape() const;

    /**
     * @brief Включает/выключает логирование шагов.
     */
    void setLogMode(bool enabled);

    /**
     * @brief Проверяет, включён ли режим логирования.
     */
    bool isLogMode() const;

    /**
     * @brief Загружает программу и начальное состояние ленты из потока.
     *
     * Ожидаемый формат:
     *   input: <начальная строка>
     *   <правило 1>
     *   <правило 2>
     *   ...
     */
    void loadFromStream(std::istream& is);

    /**
     * @brief Выполняет один шаг алгоритма.
     * @return true, если правило применилось и работа может продолжаться;
     *         false, если достигнут конец работы.
     */
    bool step();

    /**
     * @brief Выполняет интерпретацию всей программы, используя внутреннюю ленту.
     * @return Итоговое содержимое ленты.
     */
    std::string apply();

    /**
     * @brief Оператор вывода в поток.
     * @param os Поток вывода.
     * @param ma Алгоритм для вывода.
     * @return Ссылка на поток.
     */
    friend std::ostream& operator<<(std::ostream& os, const MarkovAlgorithm& ma);
};