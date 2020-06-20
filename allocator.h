#ifndef ALLOCATOR_H
#define ALLOCATOR_H

#include <stdint.h>
#include <stdio.h>

typedef struct _CG_Allocator {
    uint8_t     *_memory;
    uint32_t    _offset;
    uint32_t    _capacity;
} CG_Allocator;

CG_Allocator *CG_AllocatorAllocate(const uint32_t size);

void CG_AllocatorInfo(const CG_Allocator *alloc);

void *CG_AllocatorGetBlock(CG_Allocator *alloc, const uint32_t size);

void CG_AllocatorGiveBlock(const uint32_t size);

void CG_AllocatorExtend(CG_Allocator *alloc, const uint32_t size);

#endif // ALLOCATOR_H
