#include <stdio.h>
#include <stdlib.h>
int main() {
    void** blocks = malloc(100000 * sizeof(void*));
    if (blocks == NULL) {
        perror("Не вдалося виділити пам’ять для масиву вказівників\n");
        return 1;
    }
    
    for (int i = 0; i < 100000; ++i) {
        blocks[i] = malloc(8);
        if (blocks[i] == NULL) {
            printf("Помилка виділення пам'яті для елементів масива\n");
            break;
        }
    }

for (int i = 0; i < 100000; i += 2) {
        free(blocks[i]);
        blocks[i] = NULL;
    }

    void* large_block = malloc(802048);
    if (large_block == NULL) {
        printf("Не вдалося виділити великий блок пам’яті\n");
    } else {
        printf("Великий блок пам’яті виділено\n");
        free(large_block);
    }
   
    for (int i = 0; i < 100000; ++i) {
        if (blocks[i] != NULL) {
            free(blocks[i]);
        }
    }
    free(blocks);
    return 0;
}
