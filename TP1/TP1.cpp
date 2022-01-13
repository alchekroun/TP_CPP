#include <iostream>

/**
 * Ex 1
 */
double square_root(double const number) {
    if (number < 0) {
        throw std::invalid_argument("received negative value");
    }

    return sqrt(number);
}

/**
 * Ex 2
 */
double harmonic_serie(double const number) {
    double output = 0;

    for(auto i = 1; i <= number; i++) {
        output += 1.0 / i;
    }

    return output;
}

/**
 * Ex 3
 */
void print_xmas_tree(int const number) {
    for(auto i = 1; i <= number; i++) {
        for(auto j = 1; j <=number - i; j++) {
            std::cout << "=";
        }
        for(auto j = 1; j <= 2 * i - 1; j++) {
            std::cout << "*";
        }
        for (auto j = 1; j <= number - i; j++) {
            std::cout << "=";
        }
        std::cout << std::endl;
    }
}

/**
 * Ex 4
 */
int tribonacci(int number) {
    auto output = 0;
    auto t0 = 0, t1 = 1, t2 = 1;

    if (number == 1) return t1;
    if (number == 2) return t2;

    while (number > 2) {
        output = t0 + t1 + t2;
        t0 = t1;
        t1 = t2;
        t2 = output;
        number -= 1;
    }

    return output;
}

/**
 * Ex 5
 */
double calculator(double const n1, double const n2, char const ope) {
    switch (ope) {
    case '+':
        return n1 + n2;
    case '-':
        return n1 - n2;
    case '*':
        return n1 * n2;
    case '/':
        if(std::fabs(n2) == 0) {
            throw std::invalid_argument("Division by 0");
        }
        return n1 / n2;
    default:
        throw std::invalid_argument("Unsupported operation");
    }
}

/**
 * Ex 6
 */
int COUNT_CALL;
int count_called() {
    COUNT_CALL += 1;
    return COUNT_CALL;
}

/**
 * Ex 7
 */
int pgcd(int const p, int const q) {
    if (p == 0) return q;
    return pgcd(q % p, p);
}

/**
 * Ex 8
 */
void increment_to_variable(double* base, double const incr) {
    *base += 2 * incr + 1;
}

int main()
{
    enum choice {
        ex1 = 1,
        ex2 = 2,
        ex3 = 3,
        ex4 = 4,
        ex5 = 5,
        ex6 = 6,
        ex7 = 7,
        ex8 = 8
    };
    auto user_choice = 0;
    std::cout << "Welcome at TD1!" << std::endl;
    while (user_choice >= 0) {
        std::cout << "Pick an exercice number : " << std::endl;
        std::cin >> user_choice;
        int number;
        switch (user_choice) {
        case ex1:
            std::cout << "Choose a number : ";
            std::cin >> number;
            try {
                std::cout << "The square root is : " << square_root(number) << std::endl;
            } catch (const std::invalid_argument& e) {
                std::cerr << "Exception: " << e.what() << std::endl;
            }
            break;
        case ex2:
            std::cout << "Choose a number : ";
            std::cin >> number;
            std::cout << "The harmonic series result is : " << harmonic_serie(number) << std::endl;
            break;
        case ex3:
            std::cout << "Choose a number : ";
            std::cin >> number;
            print_xmas_tree(number);
            break;
        case ex4:
            std::cout << "Choose a number : ";
            std::cin >> number;
            std::cout << "Tribonacci result : " << tribonacci(number);
            break;
        case ex5:
            double n1, n2;
            char ope;
            std::cout << "Calculator." << std::endl << "1st number : ";
            std::cin >> n1;
            std::cout << "2nd number : ";
            std::cin >> n2;
            std::cout << "Operator : ";
            std::cin >> ope;
            try {
                std::cout << n1 << ope << n2 << "=" << calculator(n1, n2, ope) << std::endl;
            } catch (const std::invalid_argument& e) {
                std::cerr << "Exception: " << e.what() << std::endl;
            }
            break;
        case ex6:
            count_called();
            std::cout << "The count is : " << COUNT_CALL << std::endl;
            break;
        case ex7:
            int p, q;
            std::cout << "PGCD." << std::endl << "1st number : ";
            std::cin >> p;
            std::cout << "2nd number : ";
            std::cin >> q;
            std::cout << "PGCD=" << pgcd(p, q) << std::endl;
            break;
        case ex8:
            double i, j;
            std::cout << "Incremental." << std::endl << "1st number : ";
            std::cin >> i;
            std::cout << "2nd number : ";
            std::cin >> j;
            increment_to_variable(&i, j);
            std::cout << "i incremented : " << i << std::endl;
            break;
        default: break;
        }
    }
}
