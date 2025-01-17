#include <bal/abi.h>
#include <bal/hw/io.h>
#include <brutal/mem.h>

BalIo bal_io_mem(uintptr_t base, size_t size)
{
    return (BalIo){BAL_IO_MEMORY, base, size};
}

BalIo bal_io_port(uintptr_t base, size_t size)
{
    return (BalIo){BAL_IO_PORTS, base, size};
}

BalIo bal_io_slice(BalIo io, uintptr_t offset, size_t size)
{
    return (BalIo){io.type, io.base + offset, size};
}

uint8_t bal_io_in8(BalIo io, size_t offset)
{
    if (io.type == BAL_IO_PORTS)
    {
        BrIoArgs args = {
            .port = io.base + offset,
            .size = 1,
        };

        br_in(&args);

        return args.data;
    }
    else
    {
        return volatile_read8(io.base + offset);
    }
}

uint16_t bal_io_in16(BalIo io, size_t offset)
{
    if (io.type == BAL_IO_PORTS)
    {
        BrIoArgs args = {
            .port = io.base + offset,
            .size = 2,
        };

        br_in(&args);

        return args.data;
    }
    else
    {
        return volatile_read16(io.base + offset);
    }
}

uint32_t bal_io_in32(BalIo io, size_t offset)
{
    if (io.type == BAL_IO_PORTS)
    {
        BrIoArgs args = {
            .port = io.base + offset,
            .size = 4,
        };

        br_in(&args);

        return args.data;
    }
    else
    {
        return volatile_read32(io.base + offset);
    }
}

uint64_t bal_io_in64(BalIo io, size_t offset)
{
    if (io.type == BAL_IO_PORTS)
    {
        BrIoArgs args = {
            .port = io.base + offset,
            .size = 8,
        };

        br_in(&args);

        return args.data;
    }
    else
    {
        return volatile_read64(io.base + offset);
    }
}

void bal_io_out8(BalIo io, size_t offset, uint8_t data)
{
    if (io.type == BAL_IO_PORTS)
    {
        BrIoArgs args = {
            .port = io.base + offset,
            .size = 1,
            .data = data,
        };

        br_out(&args);
    }
    else
    {
        volatile_write8(io.base + offset, data);
    }
}

void bal_io_out16(BalIo io, size_t offset, uint16_t data)
{
    if (io.type == BAL_IO_PORTS)
    {
        BrIoArgs args = {
            .port = io.base + offset,
            .size = 2,
            .data = data,
        };

        br_out(&args);
    }
    else
    {
        volatile_write16(io.base + offset, data);
    }
}

void bal_io_out32(BalIo io, size_t offset, uint32_t data)
{
    if (io.type == BAL_IO_PORTS)
    {
        BrIoArgs args = {
            .port = io.base + offset,
            .size = 4,
            .data = data,
        };

        br_out(&args);
    }
    else
    {
        volatile_write32(io.base + offset, data);
    }
}

void bal_io_out64(BalIo io, size_t offset, uint64_t data)
{
    if (io.type == BAL_IO_PORTS)
    {
        BrIoArgs args = {
            .port = io.base + offset,
            .size = 8,
            .data = data,
        };

        br_out(&args);
    }
    else
    {
        volatile_write64(io.base + offset, data);
    }
}
