#pragma once

#include <brutal/io/read.h>
#include <brutal/io/write.h>

typedef Result(Error, size_t) IoCopyResult;

static inline IoCopyResult io_copy(IoReader *from, IoWriter *to)
{
    size_t total = 0;

    do
    {
        char buffer[512];
        auto read = TRY(IoCopyResult, io_read(from, buffer, 512));

        if (read == 0)
        {
            return OK(IoCopyResult, total);
        }

        auto written = TRY(IoCopyResult, io_write(to, buffer, read));

        if (written == 0)
        {
            return OK(IoCopyResult, total);
        }

        total += written;
    } while (1);
}