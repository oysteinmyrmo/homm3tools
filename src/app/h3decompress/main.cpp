#include <h3/savefile.h>

#include <cstdio>

int main(int argc, char *argv[])
{
    if (argc < 3)
    {
        fprintf(stderr, "Too few arguments. First argument must be input file and second argument output file.");
        return 1;
    }

    // Let's be content with just passing the arguments forward for now.
    h3::savefile::read_write_decompressed(argv[1], argv[2]);
    return 0;
}
