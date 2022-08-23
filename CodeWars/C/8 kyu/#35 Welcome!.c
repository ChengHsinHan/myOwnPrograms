// Your start-up's BA has told marketing that your website has a large audience
// in Scandinavia and surrounding countries. Marketing thinks it would be great
// to welcome visitors to the site in their own language. Luckily you already
// use an API that detects the user's location, so this is an easy win.
//
// The Task
// Think of a way to store the languages as a database (eg an object). The
// languages are listed below so you can copy and paste!
// Write a 'welcome' function that takes a parameter 'language' (always a
// string), and returns a greeting - if you have it in your database. It should
// default to English if the language is not in the database, or in the event of
// an invalid input.
// The Database
// english: 'Welcome',
// czech: 'Vitejte',
// danish: 'Velkomst',
// dutch: 'Welkom',
// estonian: 'Tere tulemast',
// finnish: 'Tervetuloa',
// flemish: 'Welgekomen',
// french: 'Bienvenue',
// german: 'Willkommen',
// irish: 'Failte',
// italian: 'Benvenuto',
// latvian: 'Gaidits',
// lithuanian: 'Laukiamas',
// polish: 'Witamy',
// spanish: 'Bienvenido',
// swedish: 'Valkommen',
// welsh: 'Croeso'
// Possible invalid inputs include:
//
// IP_ADDRESS_INVALID - not a valid ipv4 or ipv6 ip address
// IP_ADDRESS_NOT_FOUND - ip address not in the database
// IP_ADDRESS_REQUIRED - no ip address was supplied

#include <string.h>

const char* greet(const char* language)
{
    if (language == NULL)
        return "Welcome";

    if (strcmp(language, "czech") == 0)
        return "Vitejte";
    else if (strcmp(language, "danish") == 0)
        return "Velkomst";
    else if (strcmp(language, "dutch") == 0)
        return "Welkom";
    else if (strcmp(language, "estonian") == 0)
        return "Tere tulemast";
    else if (strcmp(language, "finnish") == 0)
        return "Tervetuloa";
    else if (strcmp(language, "flemish") == 0)
        return "Welgekomen";
    else if (strcmp(language, "french") == 0)
        return "Bienvenue";
    else if (strcmp(language, "german") == 0)
        return "Willkommen";
    else if (strcmp(language, "irish") == 0)
        return "Failte";
    else if (strcmp(language, "italian") == 0)
        return "Benvenuto";
    else if (strcmp(language, "latvian") == 0)
        return "Gaidits";
    else if (strcmp(language, "lithuanian") == 0)
        return "Laukiamas";
    else if (strcmp(language, "polish") == 0)
        return "Witamy";
    else if (strcmp(language, "spanish") == 0)
        return "Bienvenido";
    else if (strcmp(language, "swedish") == 0)
        return "Valkommen";
    else if (strcmp(language, "welsh") == 0)
        return "Croeso";
    else
        return "Welcome";
}
