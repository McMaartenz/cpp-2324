#include <cstdlib>
#include <iostream>

/*! \brief Count occurrences of char \a c
 *  \param array C-style string to check
 *  \param c Character to count
 *  \return Count of character \a c
 */
size_t count_char(const char* array, char c);

int main(int argc, char** argv) {
    const char* string = "DEADBEEFCO";
    
    const size_t n = count_char(string, 'E');
    std::cout << "Amount of 'E': " << n << std::endl;

    constexpr size_t ARRAY_LENGTH = 4;
    const char* strings[ARRAY_LENGTH] = {
        "Neem de file uit de vorige opdracht.",
        "Definieer een string in een character array met ongeveer 10 characters waarvan enkele dubbele.",
        "Maak de functie waaraan je een character array meegeeft en een character. De functie gaat tellen hoe vaak het character voorkomt in de string en retourneert dit.",
        "Test de functie met meerdere strings in character arrays en meerdere characters."
    };

    for (size_t i = 0; i < ARRAY_LENGTH; i++) {
        std::cout << "Amount of E's in '" << strings[i] << "': " << count_char(strings[i], 'e') << std::endl;
    }

    return EXIT_SUCCESS;
}

size_t count_char(const char* array, char c) {
    size_t count = 0;

    for (; *array; array++) {
        if (*array == c) {
            count++;
        }
    }

    return count;
}
