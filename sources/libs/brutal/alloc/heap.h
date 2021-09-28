#pragma once

#include <brutal/alloc/base.h>

typedef struct heap_major HeapMajor;
typedef struct heap_minor HeapMinor;

struct heap_major
{
    size_t pages;

    size_t size;
    size_t usage;

    HeapMajor *prev;
    HeapMajor *next;

    HeapMinor *first;
};

struct heap_minor
{
    size_t magic;

    size_t size;
    size_t req_size;

    HeapMinor *prev;
    HeapMinor *next;

    HeapMajor *block;
};

#define MAJOR_BLOCK_HEADER_SIZE (ALIGN_UP(sizeof(HeapMajor), ALLOC_HEAP_ALIGN))
#define MINOR_BLOCK_HEADER_SIZE (ALIGN_UP(sizeof(HeapMinor), ALLOC_HEAP_ALIGN))

typedef struct
{
    Alloc base;

    NodeSize size;
    HeapMajor *root; // The root memory block acquired from the system.
    HeapMajor *best; // The major with the most free memory.
} HeapAlloc;

void heap_alloc_init(HeapAlloc *alloc, NodeSize size);

void heap_alloc_deinit(HeapAlloc *alloc);
