#include "allocator.h"
#include <stdlib.h>
#include <assert.h>
#include <string.h>

CG_Allocator *CG_AllocatorAllocate(const uint32_t size)
{
    CG_Allocator *alloc = (CG_Allocator *)malloc(sizeof(CG_Allocator) + size);
    alloc->_offset = sizeof (CG_Allocator);
    alloc->_capacity = alloc->_offset + size;
    alloc->_memory = (uint8_t *)alloc;

    for (uint32_t i = alloc->_offset; i < alloc->_capacity; ++i) {
        alloc->_memory[i] = 0u;
    }
    return alloc;
}


void CG_AllocatorInfo(const CG_Allocator *alloc)
{
    printf("Size: %u\nOffset: %u\n", alloc->_capacity, alloc->_offset);
    for (uint32_t i = 0; i < alloc->_capacity; ++i) {
        if (i % 4 == 0) printf("\t");
        if (i % 8 == 0) printf("\n");
        if (alloc->_memory[i] < 16) printf("0");
        printf("%x ", alloc->_memory[i]);
    }
    printf("\n\n");
}

void *CG_AllocatorGetBlock(CG_Allocator *alloc, const uint32_t size)
{
    uint32_t newOffset = alloc->_offset + size;
    assert(newOffset <= alloc->_capacity);
    void *block = alloc->_memory + alloc->_offset;
    alloc->_offset = newOffset;
    return block;
}

void CG_AllocatorExtend(CG_Allocator *alloc, const uint32_t newCapacity)
{
    CG_Allocator *newAllocator = (CG_Allocator *)malloc(alloc->_capacity + newCapacity);
    memcpy(newAllocator, alloc->_memory, alloc->_capacity);
    newAllocator->_capacity = alloc->_capacity + newCapacity;
    free(alloc);
    alloc = newAllocator;
}
