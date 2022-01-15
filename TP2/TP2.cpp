#include <iostream>
#include <algorithm>
#include <vector>


/**
 * Ex 1
 */
float get_min(std::vector<float> const& t) {
    auto minimum = std::numeric_limits<float>::max();
    std::for_each(begin(t), end(t),
        [&minimum](float const i) {
            if (i < minimum) {
                minimum = i;
            }
        });
    return minimum;
}

float get_max(std::vector<float> const& t) {
    auto maximum = std::numeric_limits<float>::min();
    std::for_each(begin(t), end(t),
        [&maximum](float const i) {
            if (i > maximum) {
                maximum = i;
            }
        });
    return maximum;
}

void fill_positives_values(std::vector<float>& t1, std::vector<float> const& t2) {
    auto count = 0;
    std::for_each(begin(t2), end(t2),
        [&t1, &count](float const i) {
            (i > 0) ? t1[count] = i : t1[count] = 0;
            count += 1;
        });
}


void ex1_main_function(std::vector<float>& t1, std::vector<float> const& t2) {
    std::cout << "Max of t1 : " << get_max(t1) << "\tMin of t1 : " << get_min(t1) << std::endl;
    fill_positives_values(t1, t2);
    std::cout << "t1 becomes : " << std::endl;
    std::for_each(begin(t1), end(t1),
        [](float const i) {
            std::cout << i << "\t";
        });
    std::cout << std::endl;
}

/**
 * Ex 2
 */
void ex2_main_function(float const t[], int const size_of_t, float* result) {
    float sum = 0;
    for (auto i = 0; i < size_of_t; i++) {
        sum += t[i];
    }
    *result = sum;
}

/**
 * Ex 3
 */
void ex3_main_function() {
    int size_of_t;
    std::cout << "Size of the array : ";
    std::cin >> size_of_t;

    auto const t = new int[size_of_t];
    for (auto i = 0; i < size_of_t; i++) {
        std::cout << "Enter value of element " << i << " : ";
        std::cin >> t[i];
    }

    auto const t2 = new int[size_of_t];
    for (auto i = 0; i < size_of_t; i++) {
        t2[i] = std::pow(t[i], 2);
    }

    std::cout << "The array of square is : " << std::endl;
    for (auto i = 0; i < size_of_t; i++) {
        std::cout << t2[i] << "\t";
    }
    std::cout << std::endl;

}

/**
 * Ex 4
 */
int ex4_main_function(std::string const& s, char const& c_find) {
    auto count = 0;
    for (auto const& c: s) {
        if (toupper(c) == toupper(c_find)) count += 1;
    }
    return count;
}

int main()
{
    enum choice {
        ex1 = 1,
        ex2 = 2,
        ex3 = 3,
        ex4 = 4
    };
    auto user_choice = 0, count_call = 0;
    std::cout << "Welcome at TD2!" << std::endl;
    while (user_choice >= 0) {
        std::cout << "Pick an exercice number : " << std::endl;
        std::cin >> user_choice;
        switch (user_choice) {
        case ex1: {
            std::vector<float> t_ex1_1{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
            std::vector<float> t_ex1_2{ -1, 5, 1, 2, 3, -10, 1, -2, -5, 8 };
            ex1_main_function(t_ex1_1, t_ex1_2);            
        }
            break;
        case ex2: {
            auto const size_of_t = 10;
            float result;
            float t_ex2[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
            ex2_main_function(t_ex2, size_of_t, &result);
            std::cout << "Sum of t : " << result << std::endl;
        }
            break;
        case ex3:
            ex3_main_function();
            break;
        case ex4: {
            std::string const s =  "Hello, World!";
            char c;
            std::cout << "Char to find : ";
            std::cin >> c;
            std::cout << "There is " << ex4_main_function(s, c) << " " << c << " in it." << std::endl;
        }
            break;
        default: break;
        }
    }
}
