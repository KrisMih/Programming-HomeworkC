#include <stdio.h>
#define COMMAND(name,type) type##_##name##_command
#define DEFINE_COMMAND(name, type)  \
void COMMAND(name,type)(void) { \
        printf(#type " command: " #name "\n"); \
        }
DEFINE_COMMAND(quit, internal)
DEFINE_COMMAND(start, external)
void main(){
 COMMAND(quit, internal)();
 COMMAND(start, external)();
}