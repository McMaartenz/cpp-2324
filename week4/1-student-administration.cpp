#include <cstdlib>
#include <iostream>

/*! \brief Available fields of study */
enum class FieldsOfStudy {
    ESA,
    SE,
    BIM,
    IDS
};

/*! \brief A student */
struct student {
    unsigned int student_number;
    std::string name;
    FieldsOfStudy fieldOfStudy;
};

/*! \brief Print a student
 *  \param s Student to print
 */
void print_student(const student& s);

int main(int argc, char** argv) {
    student john {
        1234,
        "john",
        FieldsOfStudy::SE
    };

    student smith {
        1337,
        "smith",
        FieldsOfStudy::ESA
    };

    student steve {
        69420,
        "steve",
        FieldsOfStudy::IDS
    };

    print_student(john);
    print_student(smith);
    print_student(steve);
    return EXIT_SUCCESS;
}

void print_student(const student& s) {
    std::cout << s.student_number << ": " << s.name << ", studying: " << (int)s.fieldOfStudy << std::endl;
}
