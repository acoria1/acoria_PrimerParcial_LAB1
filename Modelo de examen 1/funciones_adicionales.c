#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "ac_getFunciones.h"
#include "funciones_adicionales.h"

void normalizeString (char a[]){
strlwr(a);
        a[0] = toupper(a[0]);
        for (int j=0;a[j]!= '\0';j++){
            if (a[j]== ' '){
                a[j+1] = toupper(a[j + 1]);
            }
        }

}
