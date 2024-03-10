#include <stdio.h>
#include <stdlib.h>

extern char **environ;

int main() {
    // Afficher toutes les variables d'environnement
    for (char **env = environ; *env != NULL; env++) {
        printf("%s\n", *env);
    }

    // Accéder à une variable d'environnement spécifique
    char *path_value = getenv("PATH");
    if (path_value != NULL) {
        printf("La valeur de la variable PATH est : %s\n", path_value);
    } else {
        printf("La variable PATH n'est pas définie.\n");
    }

    return 0;
}
