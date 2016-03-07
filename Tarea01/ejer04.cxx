#include <stdio.h>

int strlen(const char * string)
{
  int idx = 0;
  while (*(string + idx) != '\0') {
    idx++;
  }
  return idx;
}

int main(int argc, char const *argv[]) {
  const char * string = "Esta es mi fabulosa cadena";
  printf("%s\n", string);

  int size = strlen(string);
  printf("El tamanio de la cadena es: %d\n", size);

  return 0;
}
