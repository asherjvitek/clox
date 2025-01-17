#include "chunk.h"
#include "common.h"
#include "debug.h"
#include "vm.h"
#include <stdio.h>

void testExpressions(Chunk *chunk) {
    int constant = addConstant(chunk, 1.2);
    writeChunk(chunk, OP_CONSTANT, 123);
    writeChunk(chunk, constant, 123);

    constant = addConstant(chunk, 3.4);
    writeChunk(chunk, OP_CONSTANT, 123);
    writeChunk(chunk, constant, 123);

    writeChunk(chunk, OP_ADD, 123);

    constant = addConstant(chunk, 5.6);
    writeChunk(chunk, OP_CONSTANT, 123);
    writeChunk(chunk, constant, 123);

    writeChunk(chunk, OP_DIVIDE, 123);
    writeChunk(chunk, OP_NEGATE, 123);

    writeChunk(chunk, OP_RETURN, 123);
}

void writeConstant(Chunk *chunk, double value) {
    int constant = addConstant(chunk, value);
    writeChunk(chunk, OP_CONSTANT, 123);
    writeChunk(chunk, constant, 123);
}

void testExpressions2(Chunk *chunk) {
    writeConstant(chunk, 2);
    writeConstant(chunk, 3);

    writeChunk(chunk, OP_MULTIPLY, 123);

    writeConstant(chunk, 1);

    writeChunk(chunk, OP_ADD, 123);

    writeConstant(chunk, 4);
    writeConstant(chunk, 5);

    writeChunk(chunk, OP_NEGATE, 123);
    writeChunk(chunk, OP_DIVIDE, 123);
    writeChunk(chunk, OP_SUBTRACT, 123);

    writeChunk(chunk, OP_RETURN, 123);
}

void testExpressions3(Chunk *chunk) {
    writeConstant(chunk, 4);
    writeConstant(chunk, 3);

    writeChunk(chunk, OP_SUBTRACT, 123);
    writeChunk(chunk, OP_MULTIPLY, 123);

    writeConstant(chunk, 0);
    writeConstant(chunk, 2);
    writeChunk(chunk, OP_SUBTRACT, 123);

    writeChunk(chunk, OP_RETURN, 123);
}

int main(int argc, const char *argv[]) {
#ifdef PERFORMANCE_TEST
    for (int i = 1; i < 10000000; i++) {
#endif
        initVM();
        Chunk chunk;
        initChunk(&chunk);

        testExpressions2(&chunk);

        /* writeConstant(&chunk, 1); */
        /* writeConstant(&chunk, 1); */
        /**/
        /* writeChunk(&chunk, OP_ADD, 123); */
        /* writeChunk(&chunk, OP_RETURN, 123); */

        /* disassembleChunk(&chunk, "test chunk"); */
        interpret(&chunk);
        freeVM();
        freeChunk(&chunk);
#ifdef PERFORMANCE_TEST
    }
#endif

    return 0;
}
